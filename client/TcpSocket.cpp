//
// TcpSocket.cpp for  in /home/souman_a//Desktop/my_project/zappy_delamort/client
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
// Started on  Wed Jun  1 18:33:59 2011 abd-el-moxine soumanou

//

#include	<iostream>
#include	"TcpSocket.hh"
#include        "bucketsingleton.hpp"

TCP::Socket::Socket(QObject *parent) : QTcpSocket(parent), Observable()
{
  this->co = false;
  this->connect(this, SIGNAL(connected()), this, SLOT(xconnected()));
  this->connect(this, SIGNAL(disconnected()), this, SLOT(xdisconnected()));
  this->connect(this, SIGNAL(readyRead()), this, SLOT(readPendingData()));
  // this->connect(&this->timer, SIGNAL(timeout()), this, SLOT(hasDataToSend()));
  this->connect(&this->timer, SIGNAL(timeout()), this, SLOT(xtimeout()));
  this->timer.setInterval(20);
  this->timer.start();
}

TCP::Socket::~Socket()
{
  if (!this->ba.isEmpty())
    this->ba.clear();
  this->qvector.clear();
}

void        TCP::Socket::readPendingData()
{
  QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
  QByteArray ba;
  QVector<QByteArray >::ConstIterator it;

  if (!socket)
    return;
  this->qvector.append(ba = socket->readAll());
  if (ba.endsWith('\n'))
    {
      for (it = this->qvector.begin(); it != this->qvector.end(); ++it)
	this->ba.append(*it);
      this->notify(this->ba.data(), true);
      this->qvector.clear();
      if (!this->ba.isEmpty())
	this->ba.clear();
    }
}

void        TCP::Socket::xdisconnected()
{
  std::cout << "Disconnected" << std::endl;
  exit(EXIT_FAILURE);
}

void        TCP::Socket::xconnected()
{
  std::cout << "Connection successfull" << std::endl;
  this->co = true;
}

void        TCP::Socket::xtimeout()
{
  SingletonBucket *sgleBck = SingletonBucket::getInstance();
  std::string	&ip = sgleBck->getAddress();
  int		&port = sgleBck->getPort();

  if (!ip.empty())
    {
      this->connectToHost(ip.c_str(), static_cast<quint16> (port));
      if (!this->waitForConnected(5000))
	{
	  std::cout << "Timeout socket, connection to peer refused. Progam stops." << std::endl;
	}
      ip.clear();
    }
}

void        TCP::Socket::hasDataToSend()
{
    SingletonBucket *sgleBck = SingletonBucket::getInstance();
    char	*data;

  data = sgleBck->getSend();
  if (data && this->state() == QAbstractSocket::ConnectedState)
    {
      std::string s(data);
      
      this->write(s.c_str());
      data = NULL;
    }
}

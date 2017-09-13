//
// TcpSocket.cpp for  in /home/souman_a//Desktop/my_project/zappy_delamort/client
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
// Started on  Wed Jun  1 18:33:59 2011 abd-el-moxine soumanou
// Last update Thu Jun 23 17:03:46 2011 damien benloukil
//

#include	<iostream>
#include	"TcpSocket.hh"
#include        "bucketsingleton.hpp"

TCP::Socket::Socket(QObject *parent, QString const &ip, quint16 port) : QTcpSocket(parent), Observable(), ip(ip), port(port)
{
  this->timer.setInterval(100);
  this->connect(this, SIGNAL(disconnected()), this, SLOT(xdisconnected()));
  this->connect(this, SIGNAL(readyRead()), this, SLOT(readPendingData()));
  this->connect(&this->timer, SIGNAL(timeout()), this, SLOT(hasDataToSend()));
  QTimer::singleShot(1000, this, SLOT(xconnected()));
}

TCP::Socket::~Socket()
{}

void        TCP::Socket::readPendingData()
{
  QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
  QByteArray ba;
  QList<QByteArray> list_ba;
  QVector<QByteArray >::ConstIterator it;

  if (!socket)
    return;
  this->qvector.append(ba = socket->readAll());
  if (ba.endsWith('\n'))
    {
      for (it = this->qvector.begin(); it != this->qvector.end(); ++it)
	this->ba.append(*it);
      list_ba = this->ba.split('\n');
      while (!list_ba.isEmpty())
	{
	  this->notify(list_ba.front().data());
	  list_ba.removeFirst();
	}
      this->notify("bct end");
      this->qvector.clear();
      this->ba.clear();
    }
}

void	TCP::Socket::sendData(char const *data)
{
  this->write(data);
}

void        TCP::Socket::xdisconnected()
{
  this->notify("koC");
}

void        TCP::Socket::xconnected()
{
  this->connectToHost(this->ip, this->port);
  if (this->waitForConnected())
    {
      this->notify("okC");
      this->timer.start();
    }
  else
    this->notify("koC");
}

void	TCP::Socket::hasDataToSend()
{
  SingletonBucket *sgleBck = SingletonBucket::getInstance();
  const char	*data = sgleBck->getSend();
  if (data)
    {
      if (sgleBck->getSendingState())
	{
	  this->sendData(data);
	  sgleBck->setSendingState(false);
	}
    }
}

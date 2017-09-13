//
// TcpSocket.hh for  in /home/souman_a//Desktop/my_project/zappy_delamort/client
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
// Started on  Wed Jun  1 18:21:28 2011 abd-el-moxine soumanou
// Last update Sun Jul 10 20:23:26 2011 anthony louis-regis
//

#ifndef		TCPSOCKET_HH
#define		TCPSOCKET_HH

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpServer>
#include <QString>
#include <QTimer>
#include "Observable.hh"

namespace	TCP
{
  class	Socket : public QTcpSocket, public Observable
  {
    Q_OBJECT
  public:
    Socket(QObject *parent);
    ~Socket();
    void	hasDataToSend();
    bool co;

  private slots:

    void        readPendingData();
    void        xconnected();
    void        xdisconnected();
    void	xtimeout();
  private:
    QVector<QByteArray > qvector;
    QByteArray	ba;
    QTimer	timer;
  };
}


#endif

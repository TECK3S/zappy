//
// TcpSocket.hh for  in /home/souman_a//Desktop/my_project/zappy_delamort/client
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
// Started on  Wed Jun  1 18:21:28 2011 abd-el-moxine soumanou
// Last update Wed Jun 22 21:13:26 2011 damien benloukil
//

#ifndef		TCPSOCKET_HH
#define		TCPSOCKET_HH

#include <qtextstream.h>
#include <QtGui>
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
    Socket(QObject *parent, QString const &ip, quint16 port);
    virtual ~Socket();

    void	      sendData(char const *data);
  private slots:
    void        readPendingData();
    void        xconnected();
    void        xdisconnected();
    void	hasDataToSend();
  private:
    QVector<QByteArray > qvector;
    QByteArray	ba;
    QString	ip;
    quint16	port;
    QTimer	timer;
  };
}

#endif

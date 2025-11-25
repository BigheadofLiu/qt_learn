#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
//应对子线程无法创建tcpsocket的情况
class myTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit myTcpServer(QObject *parent = nullptr);

protected:
   virtual void incomingConnection (qintptr socketDescriptor) override;
signals:
   void newDesDescriptor(qintptr sock);
private:

};

#endif // MYTCPSERVER_H

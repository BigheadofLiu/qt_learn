#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
//应对子线程无法创建tcpsocket的情况 其实qt6看起来运行并没有问题。。。
class myTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit myTcpServer(QObject *parent = nullptr);

protected:
   virtual void incomingConnection (qintptr socketDescriptor) override;  //重写方法 会自动调用
signals:
   void newDesDescriptor(qintptr sock);
private:

};

#endif // MYTCPSERVER_H

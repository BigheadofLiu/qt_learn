#ifndef RECVFILE_H
#define RECVFILE_H

#include <QObject>
#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include "mytcpserver.h"

class recvFile : public QThread
{
    Q_OBJECT
public:
    explicit recvFile(qintptr sock,QObject *parent = nullptr);
public slots:
    void setTcpSocket(/*QTcpSocket* client*/);
signals:
    void sendOver();
protected:
    void run() override;
private:
    QTcpSocket* mClient;
    // myTcpServer* mClient;
    qintptr mSocket=0;
};

#endif // RECVFILE_H

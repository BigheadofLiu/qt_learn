#include "sendfile.h"

sendFile::sendFile(QObject *parent)
    : QObject{parent}
{}

void sendFile::connectServer(QString ip,unsigned short port)
{
    // mClient=new QTcpSocket;
    mClient->connectToHost(ip,port);
    connect(mClient,&QTcpSocket::connected,this,&sendFile::isConnected);
    connect(mClient,&QTcpSocket::disconnected,this,[=]{
        mClient->close();
        mClient->deleteLater();
        emit disConnected();
    });
}

void sendFile::fileSend(QString filePath)
{
    QFile file(filePath);
    QFileInfo fileInfo(filePath);
    int fileSize=fileInfo.size();
    file.open(QFile::ReadOnly);
    while(!file.atEnd()){
        static int count=0;
        if(count==0){
            mClient->write((char*)&fileSize,4); //这里为啥设置为4个字节？
        }
        QByteArray buffer=file.readLine();
        count+=buffer.size();
        int percent=(count*100)/fileSize;
        mClient->write(buffer);
        emit curPercent(percent);
    }

}

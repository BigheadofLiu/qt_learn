#include "recvfile.h"

recvFile::recvFile(QObject *parent)
    : QThread{parent}
{

}

void recvFile::setTcpSocket(QTcpSocket *client)
{
    this->mClient=client;
}

void recvFile::run()
{
    // auto file=std::make_shared<QFile>();
    QFile* file=new QFile("recv.txt");
    file->open(QFile::WriteOnly);

    connect(mClient,&QTcpSocket::readyRead,this,[=](){
        static int count=0;
        static int total=0;
        if(count==0){
            mClient->read((char*) &total,4);
        }
        QByteArray arry=mClient->readAll();
        count+=arry.size();
        file->write(arry);

        if(count==total){
            mClient->close();
            mClient->deleteLater();
            file->close();
            file->deleteLater();
            emit sendOver();
        }

    });
    //进入时间循环 防止子线程提前退出 这里跟用while(true)有啥区别吗
    exec();

}

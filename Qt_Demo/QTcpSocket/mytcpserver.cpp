#include "mytcpserver.h"
#include "ui_mytcpserver.h"

myTcpServer::myTcpServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myTcpServer)
    , mTcpServer(new QTcpServer(this))
{
    ui->setupUi(this);
    this->setWindowTitle("服务器");
    connect(ui->startLisBtn,&QPushButton::clicked,[this](){
        //开启监听
        mTcpServer->listen(QHostAddress::Any,8899);

        //监听到新连接
        connect(mTcpServer,&QTcpServer::newConnection,[=](){
            QTcpSocket* rec=mTcpServer->nextPendingConnection();
            QMessageBox::information(this,"提示","检测到新连接的客户端");

            ui->ip->setText(rec->peerAddress().toString());
            ui->port->setText(QString::number(rec->peerPort()));

            connect(rec,&QTcpSocket::disconnected,[=](){
                QMessageBox::information(this,"提示","客户端已断开连接");
            });
        });


    });

    connect(ui->endLisBtn,&QPushButton::clicked,[this](){
    mTcpServer->close();
        QMessageBox::information(this,"提示","已停止监听");
    });
}

myTcpServer::~myTcpServer()
{
    delete ui;
}

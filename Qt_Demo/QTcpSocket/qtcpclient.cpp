#include "qtcpclient.h"
#include "./ui_qtcpclient.h"
#include <QMessageBox>

QTcpClient::QTcpClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QTcpClient)
    , mClient(new QTcpSocket(this))
{
    ui->setupUi(this);
    this->setWindowTitle("客户端");

    // QTcpSocket* client=new QTcpSocket(this); //定义为成员变量以免捕获不到
    connect(ui->startBtn,&QPushButton::clicked,[this](){
        QString mIp(ui->ip->text());
        QString mPort(ui->port->text());
        mClient->connectToHost(QHostAddress(mIp),mPort.toUShort());
        connect(mClient,&QTcpSocket::connected,[this](){
            QMessageBox::information(this,"提示","连接成功！");
        });
        connect(mClient,&QTcpSocket::disconnected,[this](){
            QMessageBox::information(this,"提示","断开连接!");
        });
     });
    connect(ui->overBtn,&QPushButton::clicked,[this](){
        mClient->close();
    });
}

QTcpClient::~QTcpClient()
{
    delete ui;
}

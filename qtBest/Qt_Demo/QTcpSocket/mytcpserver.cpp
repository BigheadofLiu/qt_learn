#include "mytcpserver.h"
#include "ui_mytcpserver.h"
#include <QDateTime>

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
            mClient=mTcpServer->nextPendingConnection();
            QMessageBox::information(this,"提示","检测到新连接的客户端");

            ui->ip->setText(mClient->peerAddress().toString());
            ui->port->setText(QString::number(mClient->peerPort()));

            connect(mClient,&QTcpSocket::readyRead,[=](){
                QByteArray arry=mClient->readAll();
                // ui->msgLineEdit->text().append(arry);
                ui->hisTextEdit->append(arry);
            });

            connect(mClient,&QTcpSocket::disconnected,[=](){
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

void myTcpServer::on_sendMsgBtn_clicked()
{
    QString msg=ui->msgLineEdit->text();
    QString timeStr = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString finalStr=QString("服务器[%1]说:%2\n")
                           .arg(timeStr)
                           .arg(msg);
    mClient->write(finalStr.toUtf8());
    ui->hisTextEdit->append(finalStr);
    ui->msgLineEdit->clear();
}

void myTcpServer::on_clearBtn_clicked()
{
    ui->msgLineEdit->clear();
}


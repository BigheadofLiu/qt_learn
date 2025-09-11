#include "clientwindow.h"
#include "./ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    ui->port->setText("8899");
    ui->ip->setText("127.0.0.1");
    setWindowTitle("客户端");
    ui->disconnect->setEnabled(false);
    ui->sendBtn->setEnabled(false);
    // mServer=new QTcpServer(this);
    mClient=new QTcpSocket(this); //对象树管理

    connect(mClient,&QTcpSocket::connected,[=](){ //已连接信号
        ui->histroyMsg->append("成功连接到服务器...");
        mStatusLab->setPixmap(QPixmap(":/已连接.png").scaled(20,20));
        ui->disconnect->setEnabled(true);
        ui->connect->setEnabled(false);
        ui->sendBtn->setEnabled(true);
    });

    connect(mClient,&QTcpSocket::readyRead,this,[=](){  //读准备信号
        QByteArray data=mClient->readAll();
        ui->histroyMsg->append("服务器说:"+data);
    });

    connect(mClient,&QTcpSocket::disconnected,this,[=](){   //断开连接信号
        mClient->close();
        //释放QTcpsocket对象的方式
        // mClient->deleteLater();
        ui->histroyMsg->append("服务器已断开连接...");
        mStatusLab->setPixmap(QPixmap(":/未连接.png").scaled(20,20));
        ui->disconnect->setEnabled(false);
        ui->connect->setEnabled(true);
        ui->sendBtn->setEnabled(false);
    });

    // connect(mServer,&QTcpServer::newConnection,this,[=](){
    //     mStatusLab->setPixmap(QPixmap(":/已连接.png").scaled(20,20));
    //     mClient=mServer->nextPendingConnection();
        // connect(mClient,&QTcpSocket::readyRead,this,[=](){
        //     QByteArray data=mClient->readAll();
        //     ui->histroyMsg->append("客户端说:"+data);
        // });

        // connect(mClient,&QTcpSocket::disconnected,this,[=](){
        //     // mClient->close();
        //     //释放QTcpsocket对象的方式
        //     mClient->deleteLater();
        //     mStatusLab->setPixmap(QPixmap(":/未连接.png").scaled(20,20));
        // });
    // });

    mStatusLab=new QLabel;
    mStatusLab->setPixmap(QPixmap(":/未连接.png").scaled(20,20));

    ui->statusbar->addWidget(new QLabel("连接状态:"));
    ui->statusbar->addWidget(mStatusLab);
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::on_connect_clicked()
{
    QString ip=ui->ip->text();
    unsigned short port=ui->port->text().toUShort();
    mClient->connectToHost(ip,port);
}


void ClientWindow::on_disconnect_clicked()
{
    mClient->close();
    ui->connect->setEnabled(true);
    ui->disconnect->setEnabled(false);
}


void ClientWindow::on_sendBtn_clicked()
{
    QString msg=ui->sendMsg->toPlainText();
    mClient->write(msg.toUtf8());
    ui->histroyMsg->append("客户端说："+msg);
}


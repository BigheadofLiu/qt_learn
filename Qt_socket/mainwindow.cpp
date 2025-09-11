#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->port->setText("8899"); //设置默认端口号
    ui->sendBtn->setEnabled(false);
    setWindowTitle("服务器");

    mServer=new QTcpServer(this);  //使用对象树管理的服务端
    //QTcpServer的使用
    connect(mServer,&QTcpServer::newConnection,this,[=](){  //newConnection信号发出：有新的客户端连接
        mStatusLab->setPixmap(QPixmap(":/已连接.png").scaled(20,20));
        mClient=mServer->nextPendingConnection(); //nextPendingConnection()用于返回监听到的客户端（本质为套接字）指针
        ui->sendBtn->setEnabled(true);
        connect(mClient,&QTcpSocket::readyRead,this,[=](){  //readyRead信号发出后 可以发送（write）/接收数据（readAll）
            QByteArray data=mClient->readAll();
            ui->histroyMsg->append("客户端说:"+data);
        });

        connect(mClient,&QTcpSocket::disconnected,this,[=](){ //断开连接
            //释放QTcpsocket对象的方式
            mClient->close();  //适用于对象树来管理
            // mClient->deleteLater();
            mStatusLab->setPixmap(QPixmap(":/未连接.png").scaled(20,20));
            ui->sendBtn->setEnabled(false);
        });
    });

    mStatusLab=new QLabel;
    mStatusLab->setPixmap(QPixmap(":/未连接.png").scaled(20,20));

    ui->statusbar->addWidget(new QLabel("连接状态:"));
    ui->statusbar->addWidget(mStatusLab);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startListen_clicked()
{
    unsigned short port=ui->port->text().toUShort();  //获取端口号 并转为无符号short
    mServer->listen(QHostAddress::Any,port);  //1.监听
    ui->startListen->setEnabled(false); //按钮禁用
}


void MainWindow::on_sendBtn_clicked()
{
    QString msg=ui->sendMsg->toPlainText();
    mClient->write(msg.toUtf8());
    ui->histroyMsg->append("服务器说："+msg);
}


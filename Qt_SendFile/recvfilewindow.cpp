#include "recvfilewindow.h"
#include "ui_recvfilewindow.h"
#include "recvfile.h"
#include "mytcpserver.h"

recvFileWindow::recvFileWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::recvFileWindow)
{
    //服务器界面
    ui->setupUi(this);
    setWindowTitle("服务器");
    ui->portLineEdit->setText("8899");
    ui->startListenBtn->setEnabled(true);
    ui->endListenBtn->setEnabled(false);
    // mServer=new QTcpServer();
    mServer=new myTcpServer(this);

    // connect(mServer,&QTcpServer::newConnection,this,[=](){
    connect(mServer,&myTcpServer::newDesDescriptor,this,[=](qintptr sock){
        // QTcpSocket* client=mServer->nextPendingConnection();
        // QTcpServer* client=mServer->incomingConnection(); 这里不用写 会自动调用
        recvFile* recv=new recvFile(sock);
        // connect(this,&recvFileWindow::sendTcpsocket,recv,&recvFile::setTcpSocket);
        // emit sendTcpsocket(client);

        recv->start();
        connect(recv,&recvFile::sendOver,this,[=](){
            recv->exit();
            recv->wait();
            recv->deleteLater();
            QMessageBox::information(this,"Tips","文件传输完毕！");
        });
    });
}

recvFileWindow::~recvFileWindow()
{
    delete ui;
}

void recvFileWindow::on_startListenBtn_clicked()
{
    mServer->listen(QHostAddress::Any,ui->portLineEdit->text().toUShort());
    ui->startListenBtn->setEnabled(false);
    ui->endListenBtn->setEnabled(true);
}


void recvFileWindow::on_endListenBtn_clicked()
{
    mServer->close();
    ui->startListenBtn->setEnabled(true);
    ui->endListenBtn->setEnabled(false);
}


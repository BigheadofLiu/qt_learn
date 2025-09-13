#include "recvfilewindow.h"
#include "ui_recvfilewindow.h"
#include "recvfile.h"

recvFileWindow::recvFileWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::recvFileWindow)
{
    ui->setupUi(this);
    ui->portLineEdit->setText("8899");
    mServer=new QTcpServer(this);
    recvFile* recv=new recvFile(this);
    recv->start();
    connect(this,&recvFileWindow::sendTcpsocket,recv,&recvFile::setTcpSocket);
    connect(mServer,&QTcpServer::newConnection,this,[=](){
        QTcpSocket* client=mServer->nextPendingConnection();
        emit sendTcpsocket(client);
    });
}

recvFileWindow::~recvFileWindow()
{
    delete ui;
}

void recvFileWindow::on_startListenBtn_clicked()
{
    mServer->listen(QHostAddress::Any,ui->portLineEdit->text().toUShort());
}


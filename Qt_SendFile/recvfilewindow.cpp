#include "recvfilewindow.h"
#include "ui_recvfilewindow.h"
#include "recvfile.h"

recvFileWindow::recvFileWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::recvFileWindow)
{
    //服务器界面
    ui->setupUi(this);
    ui->portLineEdit->setText("8899");
    mServer=new QTcpServer(this);
    recvFile* recv=new recvFile(this);

    connect(this,&recvFileWindow::sendTcpsocket,recv,&recvFile::setTcpSocket);
    connect(mServer,&QTcpServer::newConnection,this,[=](){
        QTcpSocket* client=mServer->nextPendingConnection();
        emit sendTcpsocket(client);
        recv->start();
        connect(recv,&recvFile::sendOver,this,[=](){
            recv->exit();
            recv->wait();
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
}


#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>

namespace Ui {
class myTcpServer;
}

class myTcpServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit myTcpServer(QWidget *parent = nullptr);
    ~myTcpServer();

private slots:
    void on_sendMsgBtn_clicked();

    void on_clearBtn_clicked();

private:
    Ui::myTcpServer *ui;
    QTcpServer* mTcpServer;  //服务器
    QTcpSocket* mClient; //客户端
};

#endif // MYTCPSERVER_H

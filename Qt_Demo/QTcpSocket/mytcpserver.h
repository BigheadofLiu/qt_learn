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

private:
    Ui::myTcpServer *ui;
    QTcpServer* mTcpServer;
};

#endif // MYTCPSERVER_H

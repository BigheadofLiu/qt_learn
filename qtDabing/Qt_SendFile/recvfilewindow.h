#ifndef RECVFILEWINDOW_H
#define RECVFILEWINDOW_H

#include <QMainWindow>
#include "recvfile.h"
#include <QMessageBox>

namespace Ui {
class recvFileWindow;
}

class recvFileWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit recvFileWindow(QWidget *parent = nullptr);
    ~recvFileWindow();
signals:
    void sendTcpsocket(QTcpSocket* client);
private slots:
    void on_startListenBtn_clicked();

    void on_endListenBtn_clicked();

private:
    Ui::recvFileWindow *ui;
    // QTcpServer* mServer;
    myTcpServer* mServer;
};

#endif // RECVFILEWINDOW_H

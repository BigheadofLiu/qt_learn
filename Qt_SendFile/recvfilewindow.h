#ifndef RECVFILEWINDOW_H
#define RECVFILEWINDOW_H

#include <QMainWindow>
#include "recvfile.h"

namespace Ui {
class recvFileWindow;
}

class recvFileWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit recvFileWindow(QWidget *parent = nullptr);
    ~recvFileWindow();

private slots:
    void on_startListenBtn_clicked();

private:
    Ui::recvFileWindow *ui;
    QTcpServer* mServer;
};

#endif // RECVFILEWINDOW_H

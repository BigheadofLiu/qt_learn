#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QWidget>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startListen_clicked();

    void on_sendBtn_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer* mServer; //服务端对象
    QTcpSocket* mClient; //客户端对象
    QLabel* mStatusLab; //状态栏
};
#endif // MAINWINDOW_H

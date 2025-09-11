#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
// #include <QTcpServer>
#include <QTcpSocket>
#include <QWidget>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui {
class ClientWindow;
}
QT_END_NAMESPACE

class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();

private slots:
    void on_connect_clicked();

    void on_disconnect_clicked();

    void on_sendBtn_clicked();

private:
    Ui::ClientWindow *ui;
    // QTcpServer* mServer;
    QTcpSocket* mClient;
    QLabel* mStatusLab;
};

#endif // CLIENTWINDOW_H

#ifndef QTCPCLIENT_H
#define QTCPCLIENT_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class QTcpClient;
}
QT_END_NAMESPACE

class QTcpClient : public QMainWindow
{
    Q_OBJECT

public:
    QTcpClient(QWidget *parent = nullptr);
    ~QTcpClient();

private:
    Ui::QTcpClient *ui;
    QTcpSocket* mClient;
};
#endif // QTCPCLIENT_H

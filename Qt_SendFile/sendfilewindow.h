#ifndef SENDFILEWINDOW_H
#define SENDFILEWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QFileDialog>
#include <QErrorMessage>

QT_BEGIN_NAMESPACE
namespace Ui {
class sendFileWindow;
}
QT_END_NAMESPACE

class sendFileWindow : public QMainWindow
{
    Q_OBJECT

public:
    sendFileWindow(QWidget *parent = nullptr);
    ~sendFileWindow();
protected:

private slots:
    void on_choseFileBtn_clicked();

    void on_connectBtn_clicked();

    void on_disconnectBtn_clicked();

    void on_sendFileBtn_clicked();

    void startconnect(QString ip,unsigned short port);
signals:
    void sendFilePath(QString filePath);
private:
    Ui::sendFileWindow *ui;
};
#endif // SENDFILEWINDOW_H

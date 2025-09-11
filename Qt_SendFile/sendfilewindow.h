#ifndef SENDFILEWINDOW_H
#define SENDFILEWINDOW_H

#include <QMainWindow>

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

private:
    Ui::sendFileWindow *ui;
};
#endif // SENDFILEWINDOW_H

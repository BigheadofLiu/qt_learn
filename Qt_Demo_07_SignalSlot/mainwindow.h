#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "girlfriend.h"
#include "me.h"

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

public slots:
    void hungrySlot()
    {
        //emit 可加可不加 代表发射信号 更好阅读
        emit this->m_Girl->hungry();
        emit this->m_Girl->hungry("带你吃意大利面");
    }
    void eatSlot();

private:
    Ui::MainWindow *ui;
    GirlFriend* m_Girl;
    Me* m_Me;
};
#endif // MAINWINDOW_H

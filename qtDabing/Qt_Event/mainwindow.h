#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QResizeEvent>
#include <QMessageBox>
#include "mybutton.h"
#include "butterfly.h"
#include <QRandomGenerator>

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
protected:
    void closeEvent(QCloseEvent* e) override;  //重写父类QWidget的方法
    void resizeEvent(QResizeEvent* e) override; //重写父类QWidget的方法
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

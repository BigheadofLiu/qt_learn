#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include "createRandNum.h"
#include "bubblesort.h"
#include "quicksort.h"
#include "heapsort.h"
#include <QDebug>
#include <QThread>
#include <QRunnable>
#include <QThreadPool>
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

signals:
    void setNum(int num);

private slots:
    void on_startBtn_clicked();
    // void setNum(int num);  这里是槽函数大哥 定义在这里干嘛
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

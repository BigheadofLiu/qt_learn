#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QQueue>
#include <QMainWindow>
#include <QPair>

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
    void on_pushButton_clicked();

    void on_addBtn_clicked();

private:
    Ui::MainWindow *ui;
    //重新添加tabwidget时 需要用到原widget、text、icon 使用两个QQueue存储
    QQueue<std::pair<QWidget*,QString>> tabWidgetAndTextQueue;
    QQueue<QPair<QIcon,int>> tabIconAndIndexQueue;
};
#endif // MAINWINDOW_H

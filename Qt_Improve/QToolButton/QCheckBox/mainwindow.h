#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_checkBox_4_checkStateChanged(const Qt::CheckState &arg1);

    void on_checkBox_5_checkStateChanged(const Qt::CheckState &arg1);

    void on_checkBox_6_checkStateChanged(const Qt::CheckState &arg1);

    void on_checkBox_7_checkStateChanged(const Qt::CheckState &arg1);

    void on_checkBox_4_stateChanged(int arg1);

    void on_checkBox_5_stateChanged(int arg1);

    void on_checkBox_6_stateChanged(int arg1);

    void on_checkBox_7_stateChanged(int arg1);

    void stateChanged(int state);

    void on_checkBox_10_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    int checkNum=0;
};
#endif // MAINWINDOW_H

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
    void on_zeroBtn_clicked();

    void on_oneBtn_clicked();

    void on_twoBtn_clicked();

    void on_threeBtn_clicked();

    void on_fourBtn_clicked();

    void on_fiveBtn_clicked();

    void on_sixBtn_clicked();

    void on_sevenBtn_clicked();

    void on_eightBtn_clicked();

    void on_nineBtn_clicked();

    void on_pointBtn_clicked();

    void on_deviBtn_clicked();

    void on_multiBtn_clicked();

    void on_subBtn_clicked();

    void on_addBtn_clicked();

    void on_leftBtn_clicked();

    void on_rightBtn_clicked();

    void on_clearBtn_clicked();

private:
    Ui::MainWindow *ui;
    QString expression;
};
#endif // MAINWINDOW_H

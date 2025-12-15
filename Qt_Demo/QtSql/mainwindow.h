#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

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

    void on_searchBtn_clicked();

    void on_addBtn_clicked();

private:
    Ui::MainWindow *ui;
   /* QSqlDatabase* mDatabase;*/ //error
    QSqlDatabase mDatabase;   //这里不要使用指针 Qt中只有继承QObject的对象才需要用指针实例化
};
#endif // MAINWINDOW_H

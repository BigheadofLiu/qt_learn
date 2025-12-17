#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "testqwidget.h"
#include "testdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
#if 1
    TestForm* f = new TestForm;
    f->show();
#else
    TestForm* f = new TestForm(this);
#endif
    TestDialog* d=new TestDialog(this);
    //1.常规窗口展示 非阻塞
    // d->show();
    //2.exec:模态运行 程序会阻塞在此处(其他窗口会被阻塞)
    d->exec();
}


MainWindow::~MainWindow()
{
    delete ui;
}

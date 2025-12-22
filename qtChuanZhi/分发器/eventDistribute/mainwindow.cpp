#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //事件分发器

    //事件过滤器
}

MainWindow::~MainWindow()
{
    delete ui;
}

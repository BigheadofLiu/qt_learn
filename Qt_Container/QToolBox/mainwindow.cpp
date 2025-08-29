#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ui->toolBox->setCurrentIndex(1);
    ui->toolBox->setCurrentWidget(ui->page_2);
    //两种方式都可以来设置默认展开的工具抽屉
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolBox_currentChanged(int index)
{
    //用来响应 发出的工具抽屉变更信号的槽函数
    QString str=QString(ui->toolBox->itemText(index));
    QMessageBox::information(this,"提示",str);
}


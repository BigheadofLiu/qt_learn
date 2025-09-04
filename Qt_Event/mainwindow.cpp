#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    int ret=QMessageBox::question(this,"提示","确定要关闭窗口吗？");
    if(ret==QMessageBox::Yes){
        e->accept();
    }else{
        e->ignore();
    }
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
    qDebug()<<"旧窗口大小:"<<e->oldSize()<<"新窗口大小"<<e->size();
}

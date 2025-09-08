#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // connect(ui->myBtn,&myButton::click,[=](){
    //     QMessageBox::information(this,"tips","你不要碰我！");
    // });
    setWindowFlags(windowFlags()|Qt::FramelessWindowHint); //设置无边框
    setAttribute(Qt::WA_TranslucentBackground); //设置透明背景
    showMaximized(); //窗口最大化


    //生成多只蝴蝶
    for(int i=0;i<100;++i){
        butterFly* butter=new butterFly(this);
        // butter->move((width()-butter->width())/2,(height()-butter->height())/2);
        //位置随机生成
        butter->move(QRandomGenerator::global()->bounded(this->width()),QRandomGenerator::global()->bounded(this->height()));
        butter->show();
    }
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

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRect>
#include <QPoint>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // //窗口最大尺寸
    // setMaximumSize(600,600);
    // //窗口最小尺寸
    // setMinimumSize(300,300);
    //设置固定窗口大小
    // setFixedSize(500,500);
    //设置窗口标题
    setWindowTitle("你好，QT！");
    //设置窗口图标
    setWindowIcon(QIcon("C:\\Users\\ZYB\\Pictures\\icon\\像素-马里奥.png"));
    //窗口标题改变 signal
    connect(this,&MainWindow::windowTitleChanged,this,[=](const QString& title){
        qDebug()<<"窗口标题已变更为："<<title;
    });
    connect(this,&MainWindow::windowIconChanged,this,[=](const QIcon& icon){
        qDebug()<<"窗口图标已发生变更";
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //窗口移动按钮
    QRect rect=this->frameGeometry(); //获取当前位置信息
    this->move(rect.topLeft()+QPoint(10,20)); //对窗体进行移动
}


void MainWindow::on_pushButton_2_clicked()
{
    //获取当前窗口信息按钮
    QRect rect=this->frameGeometry();
    qDebug()
    <<"左上:"<<rect.topLeft()
    <<"右上:"<<rect.topRight()
    <<"左下:"<<rect.bottomLeft()
    <<"右下:"<<rect.bottomRight()
    <<"宽："<<rect.width()
    <<"高："<<rect.height();
}


void MainWindow::on_pushButton_3_clicked()
{
    //修改窗体位置和尺寸按钮
    srand(time(0));
    int x=rand()%500;
    int y=rand()%500;
    int height=this->height()+10;
    int width=this->height()+10;
    this->setGeometry(x,y,height,width);
}


void MainWindow::on_pushButton_4_clicked()
{
    setWindowIcon(QIcon("C:\\Users\\ZYB\\Pictures\\icon\\像素-红蘑菇.png"));
    setWindowTitle("QT,我来了！");
}


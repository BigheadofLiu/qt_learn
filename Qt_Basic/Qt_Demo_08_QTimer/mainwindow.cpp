#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *qt1=new QTimer(this);
    //设置定时器的精度
    qt1->setTimerType(Qt::PreciseTimer);

    //使用匿名函数
    connect(ui->startBtn,&QPushButton::clicked,this,[=](){
    if(qt1->isActive()){
        qt1->stop();
        ui->startBtn->setText("开始");
    }else{
        ui->startBtn->setText("结束");
        qt1->start();
    }
    });
    connect(qt1,&QTimer::timeout,this,[=](){
        QTime curTime=QTime::currentTime();
        QString nowTime=curTime.toString("hh:mm:ss:zzz");
        ui->timeLab->setText(nowTime);
    });

    //onceBtn
    connect(ui->startBtn_2,&QPushButton::clicked,this,[=](){
        qt1->singleShot(0,this,[=](){
            QTime curTime=QTime::currentTime();
            QString nowTime=curTime.toString("hh:mm:ss:zzz");
            ui->timeLab_2->setText(nowTime);
        });
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

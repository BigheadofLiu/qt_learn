#include "widget.h"
#include "./ui_widget.h"
/*
 关于QObjectTimer和QTimer的区别
 QObjectTimer继承于QObject 可以直接调用this.startTimer 重写父类虚方法timerEvent完成监听来触发相关事件 不通过槽函数来连接 更加底层
 QTimer 需要手动创建对象调用start方法 使用槽函数触发和处理相关事件
*/

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // ui->picLabel->setAutoFillBackground(true);
    ui->picLabel->setScaledContents(true);

    QImage pic;
    pic.load(":/1.jpg");
    ui->picLabel->setPixmap(QPixmap::fromImage(pic));

    mPicNum=2;
    mTimer=new QTimer(this);

    connect(mTimer,&QTimer::timeout,[this](){
        QString partPath=":/%1.jpg";
        QString filePath=partPath.arg(mPicNum);
        QImage pic;
        pic.load(filePath);
        ui->picLabel->setPixmap(QPixmap::fromImage(pic));
        mPicNum++;
        // qDebug()<<filePath<<" "<<mPicNum;
        if(mPicNum>5){
            mPicNum=1;
        }
    });

    connect(ui->startBtn,&QPushButton::clicked,[this](){
        if(!mTimer->isActive()){
            emit mTimer->start(1000);
        }
    });

    connect(ui->stopBtn,&QPushButton::clicked,[this](){
        if(mTimer->isActive()){
            emit mTimer->stop();
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

// void Widget::timerEvent()
// {

// }

#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap pic(":/img/1.jpg");
    ui->picLab->setScaledContents(true);  //设置图片大小自适应
    ui->picLab->setPixmap(pic);
    mPicNum=2;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()!=mTimerId){
        return;
    }
    QString partPath=":/img/%1.jpg";
    QString picPath=partPath.arg(this->mPicNum);
    QPixmap pic(picPath);
    ui->picLab->setPixmap(pic);
    mPicNum++;
    if(mPicNum>=5){
        mPicNum=1;
    }
}

void Widget::on_pushButton_clicked()
{
    // using namespace std::chrono_literals;
    mTimerId= this->startTimer(1000);
}


void Widget::on_pushButton_2_clicked()
{
    this->killTimer(mTimerId);
}


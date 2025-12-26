#include "mycoin.h"
#include "ui_mycoin.h"

MyCoin::MyCoin(QWidget *parent)
    : QPushButton(parent)
    , ui(new Ui::MyCoin)
{
    ui->setupUi(this);
}

MyCoin::~MyCoin()
{
    delete ui;
}

MyCoin::MyCoin(QString btnImg)
{
    //初始化金币
    mBtnImg=btnImg;
    QPixmap pix;
    if(!pix.load(mBtnImg)){
        qDebug()<<"图片加载失败！";
    }
    this->setFixedSize(pix.size());
    this->setStyleSheet(
        "QPushButton"
        "{"
        "border:0px;"
        "background:transparent;"
        "}"
        );
    this->setIcon(pix);
    this->setIconSize(pix.size());

    this->mTimer1=new QTimer(this);
    this->mTimer2=new QTimer(this);

    connect(mTimer1,&QTimer::timeout,[=](){
        //翻转动画1
        QPixmap pix;
        QString img=QString(":/res/Coin000%1.png").arg(this->mMin++);
        pix.load(img);
        this->setFixedSize(pix.size());
        this->setStyleSheet(
            "QPushButton"
            "{"
            "border:0px;"
            "background:transparent;"
            "}"
            );
        this->setIcon(pix);
        this->setIconSize(pix.size());
        if(this->mMin>mMax){
            this->mMin=1;
            mTimer1->stop();
        }
    });
    connect(mTimer2,&QTimer::timeout,[=](){
        //翻转动画2
        QPixmap pix;
        QString img=QString(":/res/Coin000%1.png").arg(this->mMax--);
        pix.load(img);
        this->setFixedSize(pix.size());
        this->setStyleSheet(
            "QPushButton"
            "{"
            "border:0px;"
            "background:transparent;"
            "}"
            );
        this->setIcon(pix);
        this->setIconSize(pix.size());
        if(this->mMin>mMax){
            this->mMax=8;
            mTimer2->stop();
        }
    });

}

void MyCoin::cionChange()
{   //金币翻转
    if(this->mFlag){
        this->mTimer1->start(30);
        this->mFlag=false;
    }
    this->mTimer2->start(30);
    this->mFlag=true;
}

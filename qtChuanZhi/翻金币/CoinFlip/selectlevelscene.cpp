#include "selectlevelscene.h"
#include "ui_selectlevelscene.h"

SelectLevelScene::SelectLevelScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SelectLevelScene)
{
    ui->setupUi(this);
    this->setFixedSize(490,860);
    this->setWindowTitle("选择关卡");
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    MyPushBtn* backBtn=new MyPushBtn(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()*0.5-backBtn->width()*0.5,this->height()*0.90);

    connect(backBtn,&MyPushBtn::clicked,this,[=](){
        QTimer* timer=new QTimer(this);
        timer->setSingleShot(true);
        timer->start(500);

        connect(timer,&QTimer::timeout,[=](){
            // backBtn->myZoom1();
            // backBtn->myZoom2();    写了鼠标事件就不写这个了
            this->hide();
            emit this->selectSceneBack();   //  发射返回信号
        });

    });
}

SelectLevelScene::~SelectLevelScene()
{
    delete ui;
}

void SelectLevelScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    if(!pix.load(":/res/OtherSceneBg.png")){
        qDebug()<<"图片加载失败";
    }
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5); //缩放图片
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}

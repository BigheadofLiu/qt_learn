#include "mainscene.h"
#include "./ui_mainscene.h"


MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    this->setFixedSize(490,860);
    this->setWindowTitle("牢大带你翻金币");
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));  //为什么设置了不生效(linux环境）
    // setMouseTracking(false);

    connect(ui->quitAct,&QAction::triggered,[this](){
        this->close();
    });

    //创建start按钮
    MyPushBtn* startBtn=new MyPushBtn(QString(":/res/MenuSceneStartButton.png"));
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.80);

    SelectLevelScene* levelScene=new SelectLevelScene(this);
    // SelectLevelScene
    connect(startBtn,&MyPushBtn::clicked,[=](){
        startBtn->myZoom1();
        startBtn->myZoom2();
        //这样写是不是更容易理解一点
        QTimer* timer=new QTimer(this);
        timer->setSingleShot(true);
        timer->start(500);
        connect(timer,&QTimer::timeout,[=](){
            this->hide();
            levelScene->show();
        });

        //使用匿名函数实现
        // QTimer::singleShot(500,[=](){
        //     this->hide();
        //     levelScene->show();
        // });
    });

    //接受返回信号
    connect(levelScene,&SelectLevelScene::selectSceneBack,this,[=](){
            this->show();
    });
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent *event)
{
    //绘制游戏背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5); //缩放图片
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);


}

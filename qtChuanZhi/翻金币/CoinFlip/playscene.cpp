#include "playscene.h"
#include "ui_playscene.h"

PlayScene::PlayScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PlayScene)
{
    ui->setupUi(this);
}

PlayScene::~PlayScene()
{
    delete ui;
}

PlayScene::PlayScene(int level):ui(new Ui::PlayScene)
{
    //要写在创建对象是使用的构造函数中
    //感觉这里应该写在一个函数里面不该写在带参数构造函数里面。。。
    ui->setupUi(this);
    mLevel=level;
    setFixedSize(490,860);
    setWindowTitle(QString("关卡%1").arg(mLevel));
    setWindowIcon(QPixmap(":/res/Coin0001.png"));

    connect(ui->exitAct,&QAction::triggered,[=](){
        this->close();
        //要不要发射一个信号 让上级页面也关闭还是显示出来？
    });
    //返回按钮
    MyPushBtn* backBtn=new MyPushBtn(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()*0.5-backBtn->width()*0.5,this->height()*0.90);

    //返回按钮点击事件
    connect(backBtn,&MyPushBtn::clicked,this,[=](){
        //不推荐会出现一堆野指针(自作聪明了。。）
        // QTimer* timer=new QTimer(this);
        // timer->setSingleShot(true);
        // timer->start(500);
        // connect(timer,&QTimer::timeout,this,[=](){
        //     // backBtn->myZoom1();
        //     // backBtn->myZoom2();    写了鼠标事件就不写这个了
        //     this->hide();
        //     emit this->playSceneBack();   //  发射返回信号
        // });
        QTimer::singleShot(500,this,[=]{
            this->hide();
            emit this->playSceneBack();
        });
    });

    //创建金币背景
    //创建金币的背景图片
    for(int i = 0 ; i < 4;i++)
    {
        for(int j = 0 ; j < 4; j++)
        {
            //绘制背景图片
            QLabel* label = new QLabel;
            label->setGeometry(0,0,50,50);
            QPixmap pix;
            pix.load(":/res/BoardNode.png");

            // label->setPixmap(QPixmap(":/res/BoardNode.png"));
            label->setPixmap(pix);
            label->setFixedSize(pix.size());
            // label->setScaledContents(true);
            label->setParent(this);
            label->move(140 + i*50,300+j*50);
            // 120 + (i%4)*70 , 260+ (i/4)*70

            //金币对象创建
            MyCoin * coin = new MyCoin(":/res/Coin0001.png");
            coin->setParent(this);
            coin->move(140 + i*50,300+j*50);
        }
    }
}

void PlayScene::paintEvent(QPaintEvent *event)
{
    //加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //加载标题
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap( 10,30,pix.width(),pix.height(),pix);
}

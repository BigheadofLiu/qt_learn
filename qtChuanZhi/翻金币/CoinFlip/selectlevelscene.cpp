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

    //返回按钮
    MyPushBtn* backBtn=new MyPushBtn(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()*0.5-backBtn->width()*0.5,this->height()*0.90);

    //返回按钮点击事件
    connect(backBtn,&MyPushBtn::clicked,this,[=](){
        // QTimer* timer=new QTimer(this);
        // timer->setSingleShot(true);
        // timer->start(500);

        // connect(timer,&QTimer::timeout,[=](){
        //     // backBtn->myZoom1();
        //     // backBtn->myZoom2();    写了鼠标事件就不写这个了
        //     this->hide();
        //     emit this->selectSceneBack();   //  发射返回信号
        // });

        QTimer::singleShot(500,this,[=](){
            this->hide();
            emit this->selectSceneBack();
        });
    });

    connect(ui->exitAct,&QAction::triggered,this,[=](){
        this->close();
    });

    //创建关卡
    for(auto i=0;i<20;i++){
        //创建按钮
        MyPushBtn* levelBtn=new MyPushBtn(":/res/LevelIcon.png");
        levelBtn->setParent(this);
        //移动到合适的位置
        // levelBtn->resize(QSize(80,80));
        levelBtn->move(120 + (i%4)*70 , 260+ (i/4)*70);

        //按钮添加文字
        QLabel* levelLab=new QLabel(this);
        levelLab->setFixedSize(levelBtn->size());
        levelLab->setText(QString::number(i+1));
        levelLab->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        levelLab->move(120 + (i%4)*70 , 260+ (i/4)*70);
        levelLab->setAttribute(Qt::WA_TransparentForMouseEvents,true);  //设置鼠标穿透 嘛意思

        //关联鼠标点击
        connect(levelBtn,&MyPushBtn::clicked,this,[=](){
            qDebug()<<QString("玩家选择了第%1关").arg(i+1);

            if(mPlayScene==nullptr){
                //能不能给加个按下动画
                levelBtn->myZoom1();
                levelBtn->myZoom2();

                // QTimer* timer=new QTimer(this);
                // timer->setSingleShot(true);
                // timer->start(500);

                // connect(timer,&QTimer::timeout,this,[=](){
                //     // mPlayScene=new PlayScene(this);
                //     mPlayScene=new PlayScene(i+1);
                //     // mPlayScene->setParent(this);  //这里不能设置 否则会一起隐藏
                //     this->hide();
                //     mPlayScene->show();
                // });
                QTimer::singleShot(500,this,[=](){
                        this->mPlayScene=new PlayScene(i+1);
                        this->hide();
                        this->mPlayScene->show();

                        connect(mPlayScene,&PlayScene::playSceneBack,this,[=](){
                            // mPlayScene->deleteLater();
                            mPlayScene=NULL;
                            this->show();
                        });
                });
            }
        });
     }
}


SelectLevelScene::~SelectLevelScene()
{
    delete ui;
}

void SelectLevelScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    //绘制背景1
    if(!pix.load(":/res/OtherSceneBg.png")){
        qDebug()<<"图片加载失败";
    }
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //绘制背景2
    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5); //缩放图片
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}

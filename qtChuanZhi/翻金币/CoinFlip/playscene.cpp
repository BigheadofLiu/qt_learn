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



    //返回按钮
    MyPushBtn* backBtn=new MyPushBtn(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()*0.5-backBtn->width()*0.5,this->height()*0.90);

    QSoundEffect* backSound=new QSoundEffect(this);
    backSound->setSource(QUrl::fromLocalFile(":/res/BackButtonSound.wav"));

    QSoundEffect* coinSound=new QSoundEffect(this);
    coinSound->setSource(QUrl::fromLocalFile(":/res/ConFlipSound.wav"));

    QSoundEffect* successSound=new QSoundEffect(this);
    successSound->setSource(QUrl::fromLocalFile(":/res/LevelWinSound.wav"));

    connect(ui->exitAct,&QAction::triggered,[=](){
        backSound->play();
        this->close();
        //要不要发射一个信号 让上级页面也关闭还是显示出来？
    });

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
        backSound->play();
        QTimer::singleShot(500,this,[=]{
            this->hide();
            emit this->playSceneBack();
        });
    });

    //初始化关卡数据
    dataConfig config;
    for(auto i=0;i<4;i++){
        for(auto j=0;j<4;j++){
            this->mGameArry[i][j]=config.mData[this->mLevel][i][j];
        }
    }

    //创建胜利图片
    QLabel* winLab=new QLabel(this);
    QPixmap winPix;
    winPix.load(":/res/LevelCompletedDialogBg.png");
    winLab->setGeometry(0,0,winPix.width(),winPix.height());
    winLab->setPixmap(winPix);
    // winlab.set
    winLab->move((this->width() - winPix.width())*0.5 , - winPix.height());

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
            QString img;
            if(mGameArry[i][j] == 1)
            {
                img = ":/res/Coin0001.png";
            }
            else
            {
                img = ":/res/Coin0008.png";
            }
            MyCoin * coin = new MyCoin(img);
            coin->setParent(this);
            coin->move(140 + i*50,300+j*50);
            coin->mPosX=i;
            coin->mPosY=j;
            coin->mFlag=mGameArry[i][j];

            mIconBtnArry[i][j]=coin;
            //监听鼠标按下
            connect(coin,&MyCoin::clicked,this,[=](){
                coinSound->play();
                coin->cionChange();
                mGameArry[i][j]=mGameArry[i][j]==0?1:0; //0变1 1变0

                //翻动周围其他按钮   逆天我是写不出来
                QTimer::singleShot(300, this,[=](){
                    if(coin->mPosX+1 <=3)
                    {
                        mIconBtnArry[coin->mPosX+1][coin->mPosY]->cionChange();
                        mGameArry[coin->mPosX+1][coin->mPosY] = mGameArry[coin->mPosX+1][coin->mPosY]== 0 ? 1 : 0;
                    }
                    if(coin->mPosX-1>=0)
                    {
                        mIconBtnArry[coin->mPosX-1][coin->mPosY]->cionChange();
                        mGameArry[coin->mPosX-1][coin->mPosY] = mGameArry[coin->mPosX-1][coin->mPosY]== 0 ? 1 : 0;
                    }

                    if(coin->mPosY+1<=3)
                    {
                        mIconBtnArry[coin->mPosX][coin->mPosY+1]->cionChange();
                        mGameArry[coin->mPosX][coin->mPosY+1] = mGameArry[coin->mPosX+1][coin->mPosY]== 0 ? 1 : 0;
                    }

                    if(coin->mPosY-1>=0)
                    {
                        mIconBtnArry[coin->mPosX][coin->mPosY-1]->cionChange();
                        mGameArry[coin->mPosX][coin->mPosY-1] = mGameArry[coin->mPosX+1][coin->mPosY]== 0 ? 1 : 0;

                    }

                    //判断胜利
                    this->mIsWin=true;  //默认游戏胜利
                    for(auto i=0;i<4;i++){
                        for(auto j=0;j<4;j++){
                            // mIconBtnArry[i][j]->mIsWin=true;  //设置为胜利 禁止点击
                            if(mIconBtnArry[i][j]->mFlag == false){
                                //如果存在任意一个银色金币
                                //就判断游戏还没胜利
                                // mIconBtnArry[i][j]->mIsWin=true;  //禁用按钮
                                this->mIsWin=false;
                                break;
                            }
                        }
                        if(!this->mIsWin){
                            break;
                        }
                    }

                    if(this->mIsWin){
                        // 禁用所有按钮
                        for (auto i = 0; i < 4; i++) {
                            for (auto j = 0; j < 4; j++) {
                                mIconBtnArry[i][j]->mIsWin = true;  // 设置按钮不可点击
                                // mIconBtnArry[i][j]->setEnabled(false);  // 禁用按钮
                            }
                        }
                        qDebug()<<"游戏胜利";
                        successSound->play();
                        //设置游戏胜利过场动画
                        QPropertyAnimation* animation1 =  new QPropertyAnimation(winLab,"geometry");
                        animation1->setDuration(1000);
                        animation1->setStartValue(QRect(winLab->x(),winLab->y(),winLab->width(),winLab->height())); //初始位置
                        animation1->setEndValue(QRect(winLab->x(),winLab->y()+260,winLab->width(),winLab->height()));  //目标位置
                        animation1->setEasingCurve(QEasingCurve::OutBounce);  //动画效果
                        animation1->start();

                    }
                });
            });
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

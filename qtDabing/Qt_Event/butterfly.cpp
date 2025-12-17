#include "butterfly.h"

butterFly::butterFly(QWidget *parent)
    : QWidget{parent}
{
    mIndex=1;
    mPixmap.load(":/1");
    // update();
    setFixedSize(mPixmap.size());
    startTimer(100); //每100ms发出一次timerEvent
}

void butterFly::fly()
{
    fly(10,30);  //往右下移动
}

void butterFly::fly(int min, int max)
{
    mIndex++;
    if(mIndex>2){
        mIndex=1;
    }
    QString picturePath=QString(":/%1").arg(mIndex);
    mPixmap.load(picturePath);
    update();
    int stepX=QRandomGenerator::global()->bounded(min,max);
    int stepY=QRandomGenerator::global()->bounded(min,max);
    int objX=this->geometry().topLeft().x()+stepX;
    int objY=this->geometry().topLeft().y()+stepY;

    //边界检查
    // QDesktopWidget *desk=QApplication::desktop(); Qt6已弃用
    QRect screenRect=QGuiApplication::primaryScreen()->geometry();
    if(objX>screenRect.right()){
        objX=screenRect.left();
    }
    if(objY>screenRect.bottom()){
        objY=screenRect.top();
    }
    this->move(objX,objY);
    update();
}

void butterFly::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(rect(),mPixmap);
}

void butterFly::timerEvent(QTimerEvent *e)
{
    fly();
    // mIndex++;
    // if(mIndex>2){
    //     mIndex=1;
    // }
    // QString picturePath=QString(":/%1").arg(mIndex);
    // mPixmap.load(picturePath);
    // update();
    // int stepX=QRandomGenerator::global()->bounded(10,30);
    // int stepY=QRandomGenerator::global()->bounded(10,30);
    // int objX=this->geometry().topLeft().x()+stepX;
    // int objY=this->geometry().topLeft().y()+stepY;

    // //边界检查
    // // QDesktopWidget *desk=QApplication::desktop(); Qt6已弃用
    // QRect screenRect=QGuiApplication::primaryScreen()->geometry();
    // if(objX>screenRect.right()){
    //     objX=screenRect.left();
    // }
    // if(objY>screenRect.bottom()){
    //     objY=screenRect.top();
    // }
    // this->move(objX,objY);
    // update();
}

void butterFly::mouseMoveEvent(QMouseEvent* e)
{
    //监测鼠标移动
    if(e->buttons()&Qt::LeftButton){
        this->move(e->globalPos()-mPoint);
        e->accept();
    }
}
void butterFly::mousePressEvent(QMouseEvent *e)
{
    //监测鼠标按下
    if(e->button()==Qt::LeftButton){
        mPoint=e->globalPos()-this->geometry().topLeft();
        e->accept();
    }

}

void butterFly::enterEvent(QEnterEvent *e)
{
    fly(-200,200); //防止抓到（但是还是可以抓到）
}

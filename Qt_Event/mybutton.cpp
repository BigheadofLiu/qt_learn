#include "mybutton.h"

myButton::myButton(QWidget *parent)
    : QWidget{parent}
{
    mPixmap.load(":/像素-红蘑菇.png");
    setFixedSize(mPixmap.size());
}

void myButton::mousePressEvent(QMouseEvent *e)
{
    mPixmap.load(":/像素-绿蘑菇.png");
     update(); //刷新窗口
}

void myButton::mouseReleaseEvent(QMouseEvent *e)
{
    mPixmap.load(":/像素_红蘑菇.png");
     update(); //刷新窗口
}

void myButton::enterEvent(QEnterEvent *e)
{

    mPixmap.load(":/像素_旗帜.png");
     update(); //刷新窗口
}

void myButton::leaveEvent(QEvent *e)
{
    mPixmap.load(":/像素-红蘑菇.png");
     update(); //刷新窗口
}

void myButton::paintEvent(QPaintEvent *e)
{
    // qDebug() << "pixmap isNull:" << mPixmap.isNull();
    // qDebug() << "myButton size:" << size() << "pixmap size:" << mPixmap.size();
    QPainter p(this);  //添加绘图对象（画家）
    p.drawPixmap(rect(),mPixmap); //指定画图区域（画板）
}


#include "mybutton.h"

myButton::myButton(QWidget *parent)
    : QWidget{parent}
{
    mPixmap.load(":/像素-红蘑菇.png");
    setFixedSize(mPixmap.size());


}

void myButton::mousePressEvent(QMouseEvent *e)
{
    Q_UNUSED(e); //避免未使用告警
    emit click();  //发射自定义信号
    mPixmap.load(":/像素-绿蘑菇.png");
    update(); //刷新窗口

    //如果子类还想使用父类的方法(根据实际情况添加)
    // QWidget::mousePressEvent(e);

}

void myButton::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e); //避免未使用告警
    mPixmap.load(":/像素_红蘑菇.png");
     update(); //刷新窗口
}

void myButton::enterEvent(QEnterEvent *e)
{
    Q_UNUSED(e); //避免未使用告警
    mPixmap.load(":/像素_旗帜.png");
     update(); //刷新窗口
}

void myButton::leaveEvent(QEvent *e)
{
    Q_UNUSED(e); //避免未使用告警
    mPixmap.load(":/像素-红蘑菇.png");
     update(); //刷新窗口
}

void myButton::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e); //避免未使用告警
    // qDebug() << "pixmap isNull:" << mPixmap.isNull();
    // qDebug() << "myButton size:" << size() << "pixmap size:" << mPixmap.size();
    QPainter p(this);  //添加绘图对象（画家）
    p.drawPixmap(rect(),mPixmap); //指定画图区域（画板）
}


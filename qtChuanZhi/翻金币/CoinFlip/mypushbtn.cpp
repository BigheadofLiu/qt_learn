#include "mypushbtn.h"

MyPushBtn::MyPushBtn(QWidget *parent)
    : QPushButton{parent}
{

}

MyPushBtn::MyPushBtn(QString normalImgPath, QString pressedImgPath)
{
    mNormalImgPath=normalImgPath;
    mPressedImgPath=pressedImgPath;

    QPixmap pix;
    if(!pix.load(normalImgPath)){
        qDebug()<<"图片加载失败";
    }
    this->setFixedSize(pix.size());  //使图片完全覆盖
    this->setStyleSheet(
        //linux下按钮不透明
        "QPushButton{"
        "border: 0px; "
        "background:transparent;"   //Linux加上之后还是不透明?
        "}"

        //替代方案
        // QString("QPushButton{"
        //         "border:0px; "
        //         "background-image: url(%1);"
        //         "}"
        //         ).arg(mNormalImgPath)
        );
    this->setIcon(pix);
    this->setIconSize(pix.size());
    //这么设置之后 按钮点击动效消失 需要自定义动画效果
}

void MyPushBtn::myZoom1()
{   //让按钮往下弹一下

    //创建动画对象
    QPropertyAnimation* animation=new QPropertyAnimation(this,"geometry",this);
    //设置延时
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //动画效果
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void MyPushBtn::myZoom2()
{
    //再弹回来
    //创建动画对象
    QPropertyAnimation* animation=new QPropertyAnimation(this,"geometry",this);
    //设置延时
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //动画效果
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void MyPushBtn::mousePressEvent(QMouseEvent *e)
{
    //重写鼠标按下事件
    //这样设置之后整个按钮的点击都没反应了 是不是应该设置分发器啊？
    if(this->mPressedImgPath !=""){
        QPixmap pix;
        if(!pix.load(mPressedImgPath)){
            qDebug()<<"press图片加载失败！";
        }
        this->setFixedSize(pix.size());
        this->setStyleSheet(
            "QPushButton{"
            "border: 0px; "
            "background:transparent;"
            "}"
            );
        this->setIcon(pix);
        this->setIconSize(pix.size());
    }
   /* return*/ QPushButton::mousePressEvent(e);   //确定这里要加return？
}

void MyPushBtn::mouseReleaseEvent(QMouseEvent *e)
{
    //重写鼠标释放事件
    if(this->mNormalImgPath !=""){
        QPixmap pix;
        if(!pix.load(mNormalImgPath)){
            qDebug()<<"release图片加载失败！";
        }
        this->setFixedSize(pix.size());
        this->setStyleSheet(
            "QPushButton{"
            "border: 0px; "
            "background:transparent;"
            "}"
            );
        this->setIcon(pix);
        this->setIconSize(pix.size());
    }
    /*return */QPushButton::mouseReleaseEvent(e);
}

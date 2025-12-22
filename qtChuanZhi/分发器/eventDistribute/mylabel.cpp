#include "mylabel.h"
#include "ui_mylabel.h"

MyLabel::MyLabel(QWidget *parent)
    : QLabel(parent)
    , ui(new Ui::MyLabel)
{
    ui->setupUi(this);
    setMouseTracking(true); //设置鼠标追踪
}

MyLabel::~MyLabel()
{
    delete ui;
}

void  MyLabel::enterEvent(QEnterEvent *event)
{
    qDebug()<<"鼠标进入";
}

void MyLabel::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"鼠标移动到:"<<event->x()<<event->y();
}

void MyLabel::mousePressEvent(QMouseEvent *event){
    qDebug()<<"鼠标按下";
}

void MyLabel::leaveEvent(QEvent *event)
{
     qDebug()<<"鼠标离开";
}

bool MyLabel::event(QEvent *e)   //自定义事件分发
{
    if(e->type()==QEvent::Enter){
        qDebug()<<"分发器："<<"鼠标进入";
        return true;   //自己处理的事件 不向下分发
        //分发器可以用来拦截事件使用 但是一般不推荐
    }else if(e->type()==QEvent::Leave){
        qDebug()<<"分发器："<<"鼠标离开";
        //如果不加return true 分发器和父类都会处理
        return true;
    }else if(e->type()==QEvent::MouseButtonPress){
        QMouseEvent* ev=static_cast<QMouseEvent*>(e);  //类型转换
        if(ev->button()==Qt::LeftButton){
            qDebug()<<"分发器："<<"鼠标左键按下";
            return true;
        }else{
            return QLabel::event(ev);  //鼠标右键向下分发
        }
    }


    return QLabel::event(e); //交给父类处理 向下分发
}


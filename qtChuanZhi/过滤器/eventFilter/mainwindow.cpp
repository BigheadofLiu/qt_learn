#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //在事件进入分发器进行分发之前 可以通过过滤器进行拦截
    //1.控件安装过滤器
    //2.设置拦截规则(重写eventFilter(obj,event))
    setMouseTracking(true);
    ui->label1->installEventFilter(this); //给控件安装过滤器  需要重写eventFilter函数
    ui->label2->installEventFilter(this);
    //过滤器的优先级高于分发器

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->label1 && event->type()== QEvent::MouseButtonPress){
        QMouseEvent* ev=static_cast<QMouseEvent*>(event);
        if(ev->button()==Qt::LeftButton){
            qDebug()<<"拦截器:"<<"label1鼠标左键按下";
             return true;
        }
        return false;
    }

    if(watched==ui->label2 && event->type()== QEvent::MouseButtonPress){
        QMouseEvent* ev=static_cast<QMouseEvent*>(event);
        if(ev->button()==Qt::RightButton){
            qDebug()<<"拦截器:"<<"label2鼠标右键按下";
            return true;
        }
        return false;
    }
    return false;
}

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
    ui->label1->installEventFilter(this); //给控件安装过滤器
    //过滤器的优先级高于分发器
}

MainWindow::~MainWindow()
{
    delete ui;
}

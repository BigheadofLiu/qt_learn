#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //普通按钮
    ui->normalBtn->setIcon(QIcon("://像素-红蘑菇.png"));
    ui->normalBtn->setText("我是一个屌丝");
    ui->normalBtn->setIconSize(QSize(30,30));
    ui->normalBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    connect(ui->normalBtn,&QToolButton::clicked,this,[=](){
        QMessageBox::information(this,"提示","我就是一个屌丝");
    });

    //带有check属性的按钮（相当于一个开关）
    ui->checkBtn->setIcon((QIcon(":/像素-马里奥.png")));
    ui->checkBtn->setText("我是一个开关按钮");
    ui->checkBtn->setIconSize(QSize(30,30));
    ui->checkBtn->setCheckable(true); //打开开关属性
    ui->checkBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    connect(ui->checkBtn,&QToolButton::toggled,this,[=](bool tag){
        QString message=QString("当前按钮状态为:%1").arg(tag?"选中":"未选中");  //使用字符串拼接 不要用+了
        QMessageBox::information(this,"提示",message);
    });

    //设置带有菜单的按钮
    ui->menuBtn->setText("选择你喜欢的小姐姐类型");
    ui->menuBtn->setIcon(QIcon(":/选择.png"));
    ui->menuBtn->setIconSize(QSize(30,30));
    ui->menuBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    QMenu *btnMenu =new QMenu(this);
    QAction* act1= btnMenu->addAction(QIcon(":/像素_药水.png"),"温柔的");
    QAction* act2=btnMenu->addAction(QIcon(":/像素-火焰.png"),"狂野的");
    QAction* act3=btnMenu->addAction(QIcon(":/像素-红鹦鹉.png"),"内敛的");
    QAction* act4=btnMenu->addAction(QIcon(":/像素-咖啡.png"),"奔放的");
    btnMenu->setFixedWidth(ui->menuBtn->width());
    // btnMenu->setMinimumWidth(ui->menuBtn->width());
    ui->menuBtn->setMenu(btnMenu);
    ui->menuBtn->setDefaultAction(act2);

    //难不成要绑定四次

    // 在菜单显示前调整宽度
    // connect(ui->menuBtn, &QPushButton::clicked, this, [=]() {
    //     btnMenu->setMinimumWidth(ui->menuBtn->width());
    // });

    connect(btnMenu,&QMenu::triggered,this,[=](QAction* act){
        QString message=QString("当前选择为:%1").arg(act->text());
        QMessageBox::information(this,"提示",message);
    });

    //setArrowType
    ui->arrowBtn->setArrowType(Qt::UpArrow);
    ui->arrowBtn->setText("向上");
    ui->arrowBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    //setPopupMode
    ui->popBtn->setPopupMode(QToolButton::MenuButtonPopup); //默认为delay
    ui->popBtn->setMenu(btnMenu);
    connect(ui->popBtn,&QToolButton::clicked,this,[=](){
        QString modeStr;
        switch(ui->popBtn->popupMode()) {
        case QToolButton::DelayedPopup:
            modeStr = "DelayedPopup";
            break;
        case QToolButton::MenuButtonPopup:
            modeStr = "MenuButtonPopup";
            break;
        case QToolButton::InstantPopup:
            modeStr = "InstantPopup";
            break;
        default:
            modeStr = "Unknown";
        }
        QMessageBox::information(this,"提醒","click信号发出,当前按钮模式为:"+modeStr);
    });
}




MainWindow::~MainWindow()
{
    delete ui;
}

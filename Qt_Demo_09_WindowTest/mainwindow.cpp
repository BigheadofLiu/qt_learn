#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRect>
#include <QPoint>
#include <QDebug>
#include <QMessageBox>
#include "mydialog.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // //窗口最大尺寸
    // setMaximumSize(600,600);
    // //窗口最小尺寸
    // setMinimumSize(300,300);
    //设置固定窗口大小
    // setFixedSize(500,500);
    //设置窗口标题
    setWindowTitle("你好，QT！");
    //设置窗口图标
    setWindowIcon(QIcon("C:\\Users\\ZYB\\Pictures\\icon\\像素-马里奥.png"));
    //窗口标题改变 signal
    connect(this,&MainWindow::windowTitleChanged,this,[=](const QString& title){
        qDebug()<<"窗口标题已变更为："<<title;
    });
    connect(this,&MainWindow::windowIconChanged,this,[=](const QIcon& icon){
        qDebug()<<"窗口图标已发生变更";
    });

    //设置鼠标右键点击事件
    setContextMenuPolicy(Qt::CustomContextMenu);
    //鼠标右键点击后绑定对应的槽函数
    connect(this,&MainWindow::customContextMenuRequested,this,[=](const QPoint& pos){
        QMenu qMenu;
        //添加菜单选项
        qMenu.addMenu("丁真珍珠");
        qMenu.addMenu("芙蓉王源");
        qMenu.addMenu("一给我Giao");
        //菜单显示(在鼠标点击坐标处显示)
        // qMenu.exec(QPoint(pos));
        qMenu.exec(QCursor::pos());
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //窗口移动按钮
    QRect rect=this->frameGeometry(); //获取当前位置信息
    this->move(rect.topLeft()+QPoint(10,20)); //对窗体进行移动
}


void MainWindow::on_pushButton_2_clicked()
{
    //获取当前窗口信息按钮
    QRect rect=this->frameGeometry();
    qDebug()
    <<"左上:"<<rect.topLeft()
    <<"右上:"<<rect.topRight()
    <<"左下:"<<rect.bottomLeft()
    <<"右下:"<<rect.bottomRight()
    <<"宽："<<rect.width()
    <<"高："<<rect.height();
}


void MainWindow::on_pushButton_3_clicked()
{
    //修改窗体位置和尺寸按钮
    srand(time(0));
    int x=rand()%500;
    int y=rand()%500;
    int height=this->height()+10;
    int width=this->height()+10;
    this->setGeometry(x,y,height,width);
}


void MainWindow::on_pushButton_4_clicked()
{
    //修改窗口图标和窗口标题 会触发对应的signal
    setWindowIcon(QIcon("C:\\Users\\ZYB\\Pictures\\icon\\像素-红蘑菇.png"));
    setWindowTitle("QT,我来了！");
}


void MainWindow::on_showDia_clicked()
{   //Dialog类内信号槽的使用

    myDialog* myDia=new myDialog(this);
    //输出返回值
    connect(myDia,&QDialog::accepted,this,[=](/*int ret*/){
        qDebug()<<"accept信号被发射";
    });
    connect(myDia,&QDialog::rejected,this,[=](/*int ret*/){
        qDebug()<<"reject信号被发射";
    });
    connect(myDia,&QDialog::finished,this,[=](int ret){
        qDebug()<<ret;
    });

    int ret=myDia->exec();
    //通过返回值判断按钮点击类型
    if(ret==QDialog::Accepted){  //枚举值 相当于1
        qDebug()<<"accept button clicked"<<ret;
    }else if(ret==QDialog::Rejected){ //枚举值 相当于0
        qDebug()<<"reject button clicked"<<ret;
    }else{
        qDebug()<<"done button clicked"<<ret;
    }
}

void MainWindow::on_showmsgBtn_clicked()
{
    //QMessageBox对话框的使用
    QMessageBox* qmsg=new QMessageBox(this);
    qmsg->about(this,"about","这是一条about消息框");
    qmsg->critical(this,"critical","这是一条错误critical提示框");
    int ret=qmsg->question(this,"question","确定要保存吗?",qmsg->Save|qmsg->Cancel,qmsg->Save);
    if(ret==qmsg->Save){
        qmsg->information(this,"infimation","保存成功");
    }else{
        qmsg->warning(this,"warning","取消保存");
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    //fileDialog常用方法的使用
 QFileDialog* qfd=new QFileDialog(this);
#define OPENFILE
#ifdef OPENDIR
    //获取目录
    QString dirName=qfd->getExistingDirectory(this,"打开目录","C:\\Users\\ZYB\\Pictures\\icon");
    QMessageBox::information(this,"打开目录","当前选择的目录为："+dirName);
#endif

#ifdef OPENFILE
    //获取单个文件
    QString arg("Text files (.txt)");
    QString fileName=qfd->getOpenFileName(this,tr("Open File"),"C:\\Users\\ZYB\\Pictures\\icon",tr("Image(*.png *.jpg);;Text files (*.txt)"),&arg);
    QMessageBox::information(this,"Open File","选择的文件为:"+fileName);
#endif

}


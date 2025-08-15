#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRect>
#include <QPoint>
#include <QDebug>
#include <QMessageBox>
#include "mydialog.h"
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QInputDialog>
#include <QProgressDialog>
#include <QTimer>

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
#define SAVEFILE
#ifdef OPENDIR
    //获取目录
    QString dirName=qfd->getExistingDirectory(this,"打开目录","C:\\Users\\ZYB\\Pictures\\icon");
    QMessageBox::information(this,"打开目录","当前选择的目录为："+dirName);
#endif

#ifdef OPENFILE
    //获取单个文件 tr为翻译时使用 可不加
    QString arg("Text files (*.txt)");  //过滤器 指代默认情况
    //多种格式用;;进行分隔
    QString fileName=qfd->getOpenFileName(this,tr("Open File"),"C:\\Users\\ZYB\\Pictures\\icon",tr("Image(*.png *.jpg);;Text files (*.txt)"),&arg);
    QMessageBox::information(this,"Open File","选择的文件为:"+fileName);
#endif

#ifdef OPENFILES
    QStringList qsl=qfd->getOpenFileNames(this,tr("Open Files"),"C:\\Users\\ZYB\\Pictures\\icon",tr("Image(*.png *.jpg);;Text files (*.txt)"));
    QString names;
    for(int i=0;i<qsl.size();i++){
        names+=qsl[i]+" ";
    }
    QMessageBox::information(this,tr("Open Files"),"选择的文件为："+names);
#endif

#ifdef SAVEFILE
    QString save=qfd->getSaveFileName(this,tr("Save File"),"C:\\Users\\ZYB\\Pictures\\icon");
    QMessageBox::information(this,"Save File","已保存文件:"+save);
#endif
}


void MainWindow::on_setFontBtn_clicked()
{
    QFontDialog* qfl=new QFontDialog(this);
#if 1
    bool ok;
    //字体选择窗体
    QFont ft=qfl->getFont(&ok,QFont("微软雅黑",16,QFont::Bold),this);
    // ui->myLabel->setFont(ft);  //设置某个控件字体
    QApplication::setFont(ft); //设置整个窗体字体
#endif

}


void MainWindow::on_pushButton_6_clicked()
{
    QColorDialog* qcd=new QColorDialog(this);
    QColor color=qcd->getColor(QColor(Qt::black),this);
    //绘制颜色需要用到绘图类 还没看到 下面直接打印颜色
    QString colors=QString("r:%1, g:%2, b:%3, a:%4").arg(color.red()).arg(color.green()).arg(color.black()).arg(color.alpha());
    ui->colorLabel->setText(colors);
}


void MainWindow::on_pushButton_7_clicked()
{
#define MULTITEXT
#ifdef INPUT_INT
    int age=QInputDialog::getInt(this,"设置年龄","选择你的年龄：",20,1,100,2);
    QMessageBox::information(this,"提示","你的年龄为："+QString::number(age));
#endif
#ifdef INPUT_DOUBLE
    int salary=QInputDialog::getDouble(this,"设置薪资","设置工资：",8000,3500,5000,2);
    QMessageBox::information(this,"提示","你的工资为："+QString::number(salary));
#endif
#ifdef INPUT_ITEM
    QStringList items;
    items<<"苹果"<<"香蕉"<<"橘子"<<"西瓜"<<"火龙果";
    QString choice=QInputDialog::getItem(this,"选择水果","选择你想吃的水果:",items,true);
    QMessageBox::information(this,"提示","你的水果为："+choice);
#endif
#ifdef INPUT_TEXT
    QString password=QInputDialog::getText(this,"设置密码","密码:",QLineEdit::Password,"123");
    QMessageBox::information(this,"提示","你的密码为："+password);
#endif
#ifdef MULTITEXT
    QString words=QInputDialog::getMultiLineText(this,"表白","你想对小姐姐说什么","I Love You");
    QMessageBox::information(this,"知心姐姐","我说了"+words);
#endif

}


void MainWindow::on_showQProDiaBtn_clicked()
{
    QProgressDialog* qpd =new QProgressDialog("正在保存文件","取消保存",0,100,this);
    // qpd->setWindowIcon(this->windowIcon());
    qpd->setWindowTitle("保存中");
    qpd->setWindowModality(Qt::WindowModal); //设置窗口模式为模态
    qpd->show();
    QTimer* timer=new QTimer();
    static int value=0;
    timer->start(50);
    connect(timer,&QTimer::timeout,this,[=](){
        qpd->setValue(value);
        value++;
        if(value>qpd->maximum()){
            timer->stop();
            value=0;
        }
        connect(qpd,&QProgressDialog::canceled,this,[=](){
            timer->stop();
            value=0;
            qpd->close();
        });
    });
}


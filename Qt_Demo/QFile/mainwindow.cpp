#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("文本编辑器");
    // ui->textEdit->viewport()->installEventFilter(this);    //设置事件过滤器
    // this->menuBar()->setMouseTracking(true);
    connect(ui->openFileAct,&QAction::triggered,this,&MainWindow::openFileSlot);
    connect(ui->saveAsAct,&QAction::triggered,this,&MainWindow::saveAsFileSlot);
    connect(ui->savaFileAct,&QAction::triggered,this,&MainWindow::saveFileSlot);
    connect(ui->newFileAct,&QAction::triggered,this,&MainWindow::newFileSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers()==Qt::ControlModifier && event->key()==Qt::Key_S){
        saveFileSlot();
    }
}

// bool MainWindow::eventFilter(QObject *obj, QEvent *event)
// {
//     //判断发出对象
//     if(obj==ui->textEdit){
//         //判断事件类型
//         if(event->type()== QEvent::MouseButtonPress){
//             // auto* e=(QMouseEvent*) event;  //强制类型转换 可能会出错
//             auto* e=static_cast<QMouseEvent*> (event); //使用静态类型转换
//             //判断哪个按键
//             if(e->button()==Qt::LeftButton){
//                 qDebug()<<"左键被按下";
//             }
//             if(e->button()== Qt::RightButton){
//                 qDebug()<<"右键被按下";
//             }
//             return false;  //避免被拦截
//         }
//     }
//     return QMainWindow::eventFilter(obj,event);
// }



void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint p1=event->pos();
    qDebug()<<p1;
    if(event->button()==Qt::LeftButton){
        qDebug()<<"左键被按下";
    }else if(event->button()== Qt::RightButton){
        qDebug()<<"右键被按下";
    }
}

void MainWindow::newFileSlot()
{
    ui->textEdit->clear();
    this->setWindowTitle("new txtEditor");
}

void MainWindow::openFileSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this, "打开文件","/home","文本文档(*.txt)");
    this->mCurrentFilePath=fileName;
    if(fileName.isEmpty()){
        QMessageBox::warning(this,"警告","未选择文件路径或非法路径！");
    }
    // QFile file;  需要构造时传参数...
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QByteArray ba=file.readAll();
    ui->textEdit->setText(QString(ba));
    file.close();
}

void MainWindow::saveFileSlot()
{
    // QString fileName = QFileDialog::getOpenFileName(this, "打开文件","/home","文本文档(*.txt)");
    // if(fileName.isEmpty()){
    //     QMessageBox::warning(this,"警告","未选择文件路径或非法路径！");
    // }
    // QFile file;  需要构造时传参数...
    if(mCurrentFilePath.isEmpty()){
        QMessageBox::warning(this,"警告","请先打开一个文本");
        return;
    }
    QFile file(mCurrentFilePath);
    file.open(QIODevice::WriteOnly);
    QByteArray ba;
    ba.append(ui->textEdit->toPlainText().toUtf8());
    file.write(ba);
    QMessageBox::information(this,"提示","内容已保存");
    file.close();
}

void MainWindow::saveAsFileSlot()
{
    QString fileName=QFileDialog::getSaveFileName(this,"保存文件","/home","文本文档(*.txt)");
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QByteArray ba;
    ba.append(ui->textEdit->toPlainText().toUtf8());
    file.write(ba);
    file.close();
}

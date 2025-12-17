#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QQueue>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->addBtn->setEnabled(false);
    connect(ui->tabWidget,&QTabWidget::tabCloseRequested,this,[=](int index){
        //移除之前先保存 方便后续重新添加
        //暂存 widget、icon、index
        QWidget* currentWidget=ui->tabWidget->widget(index);
        QString currentTitle=ui->tabWidget->tabText(index);
        QIcon currentIcon=ui->tabWidget->tabIcon(index);
        tabWidgetAndTextQueue.enqueue(std::make_pair(currentWidget,currentTitle));
        tabIconAndIndexQueue.enqueue(qMakePair(currentIcon,index));
        ui->tabWidget->removeTab(index);
        ui->addBtn->setEnabled(true);
    });

    connect(ui->tabWidget,&QTabWidget::tabBarClicked,this,[=](int index){
        QString currentText=ui->tabWidget->tabText(index);
        QMessageBox::information(this,"tips",currentText+"单击");
    });
    connect(ui->tabWidget,&QTabWidget::tabBarDoubleClicked,this,[=](int index){
        //单击信号不取消 双击信号永远不会被触发
        QString currentText=ui->tabWidget->tabText(index);
        QMessageBox::information(this,"tips",currentText+"双击");
    });
    connect(ui->tabWidget,&QTabWidget::currentChanged,this,[=](int index){
        if(index>0){
        QString currentText=ui->tabWidget->tabText(index);
        QMessageBox::information(this,"tips","菜单变更为"+currentText);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


// void MainWindow::on_pushButton_clicked()
// {
//     //重新添加tabwidget
//     ui->tabWidget->addTab(tabWidgetAndTextQueue.dequeue().first,tabIconAndIndexQueue.dequeue().first,tabWidgetAndTextQueue.dequeue().second);
//     if(tabWidgetAndTextQueue.empty()){
//         ui->addBtn->setEnabled(false);
//     }
// }


void MainWindow::on_addBtn_clicked()
{
    //重新添加tabwidget
    //下面这种写法会出现两次出队的情况
    //先存储一次出队的元素
    auto widgetAndText=tabWidgetAndTextQueue.dequeue();
    auto iconAndIndex=tabIconAndIndexQueue.dequeue();
    // ui->tabWidget->addTab(tabWidgetAndTextQueue.dequeue().first,tabIconAndIndexQueue.dequeue().first,tabWidgetAndTextQueue.dequeue().second);
    ui->tabWidget->addTab(widgetAndText.first,iconAndIndex.first,widgetAndText.second);
    if(tabWidgetAndTextQueue.empty()){
        ui->addBtn->setEnabled(false);
    }
}


#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->checkBox_10->setTristate(true);
    connect(ui->checkBox,&QCheckBox::stateChanged,this,&MainWindow::stateChanged);
    connect(ui->checkBox_2,&QCheckBox::stateChanged,this,&MainWindow::stateChanged);
    connect(ui->checkBox_3,&QCheckBox::stateChanged,this,&MainWindow::stateChanged);
    connect(ui->checkBox_8,&QCheckBox::stateChanged,this,&MainWindow::stateChanged);
    connect(ui->checkBox_9,&QCheckBox::stateChanged,this,&MainWindow::stateChanged);
    connect(ui->checkBox_11,&QCheckBox::stateChanged,this,&MainWindow::stateChanged);
    connect(ui->checkBox_10,&QCheckBox::clicked,this,[=](bool bl){
        if(bl){
        ui->checkBox->setCheckState(Qt::Checked);
        ui->checkBox_2->setCheckState(Qt::Checked);
        ui->checkBox_3->setCheckState(Qt::Checked);
        ui->checkBox_8->setCheckState(Qt::Checked);
        ui->checkBox_9->setCheckState(Qt::Checked);
        ui->checkBox_11->setCheckState(Qt::Checked);
        checkNum=6;
        }else{
            ui->checkBox->setCheckState(Qt::Unchecked);
            ui->checkBox_2->setCheckState(Qt::Unchecked);
            ui->checkBox_3->setCheckState(Qt::Unchecked);
            ui->checkBox_8->setCheckState(Qt::Unchecked);
            ui->checkBox_9->setCheckState(Qt::Unchecked);
            ui->checkBox_11->setCheckState(Qt::Unchecked);
            checkNum=0;
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkBox_4_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        qDebug()<<ui->checkBox_4->text()+"被选中";
    }else{
        qDebug()<<ui->checkBox_4->text()+"取消选中";
    }
}


void MainWindow::on_checkBox_5_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        qDebug()<<ui->checkBox_5->text()+"被选中";
    }else{
        qDebug()<<ui->checkBox_5->text()+"取消选中";
    }
}


void MainWindow::on_checkBox_6_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        qDebug()<<ui->checkBox_6->text()+"被选中";
    }else{
        qDebug()<<ui->checkBox_6->text()+"取消选中";
    }
}

void MainWindow::on_checkBox_7_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        qDebug()<<ui->checkBox_7->text()+"被选中";
    }else{
        qDebug()<<ui->checkBox_7->text()+"取消选中";
    }
}

void MainWindow::stateChanged(int state)
{
    if(state==Qt::Checked){
        checkNum++;
    }else {
        checkNum--;
    }
    if(checkNum==6){
        ui->checkBox_10->setCheckState(Qt::Checked);
    }else if(checkNum==0){
        ui->checkBox_10->setCheckState(Qt::Unchecked);
    }
    else{
        ui->checkBox_10->setCheckState(Qt::PartiallyChecked);
    }
}



//这里不能使用转到槽的方式来创建 会形成递归调用 还得是connect
// void MainWindow::on_checkBox_10_stateChanged(int arg1)
// {
//     if(arg1==Qt::Checked){
//         ui->checkBox->setCheckState(Qt::Checked);
//         ui->checkBox_2->setCheckState(Qt::Checked);
//         ui->checkBox_3->setCheckState(Qt::Checked);
//         ui->checkBox_8->setCheckState(Qt::Checked);
//         ui->checkBox_9->setCheckState(Qt::Checked);
//         ui->checkBox_11->setCheckState(Qt::Checked);
//         checkNum=6;
//     }else{
//         ui->checkBox->setCheckState(Qt::Unchecked);
//         ui->checkBox_2->setCheckState(Qt::Unchecked);
//         ui->checkBox_3->setCheckState(Qt::Unchecked);
//         ui->checkBox_8->setCheckState(Qt::Unchecked);
//         ui->checkBox_9->setCheckState(Qt::Unchecked);
//         ui->checkBox_11->setCheckState(Qt::Unchecked);
//         checkNum=0;
//     }
// }


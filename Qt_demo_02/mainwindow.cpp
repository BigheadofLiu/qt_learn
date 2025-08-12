#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //父窗体为this（MainWindow）
    QPushButton* but_1 =new QPushButton(this);
    but_1->setFixedSize(600,600);
    //针对父窗体（mainwindow）坐标原点的偏移
    but_1->move(10,10);

    //父对象为but_1
    QPushButton* but_2 =new QPushButton(but_1);
    but_2->setFixedSize(400,400);
    //针对父窗体（but_1）坐标原点的偏移
    but_2->move(10,10);

    QPushButton* but_3 =new QPushButton(but_2);
    but_3->setFixedSize(200,200);
    but_3->move(10,10);


}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void CreateRandomNumber()
{
    srand(time(0));
    for(auto i=0;i<50;i++){
        auto num=rand()%10000;
        qDebug()<<num;
    }

}

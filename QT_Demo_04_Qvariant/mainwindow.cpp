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

QVariant MainWindow::DataPlus(QVariant a, QVariant b)
{
    QVariant ret;
    if(a.typeId() == QVariant::Int&&b.typeId()==QVariant::Int){
        // ret=QVariant(a+b);
        ret=a.toInt()+b.toInt();
        ret= QVariant(a.toInt()+b.toInt());
    }else if(a.typeId() == QVariant::String&&b.typeId()==QVariant::String){
        ret.setValue(a.toString()+b.toString());
}
    return ret;
}

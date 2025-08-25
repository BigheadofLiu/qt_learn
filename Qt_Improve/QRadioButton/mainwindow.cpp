#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton_5->setChecked(true); //设置默认选项
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_4_clicked()
{
    QMessageBox::information(this,"提示",ui->radioButton_4->text());
}


void MainWindow::on_radioButton_5_clicked()
{
    QMessageBox::information(this,"提示",ui->radioButton_5->text());
}


void MainWindow::on_radioButton_6_clicked()
{
    QMessageBox::information(this,"提示",ui->radioButton_6->text());
}


void MainWindow::on_radioButton_7_clicked()
{
    QMessageBox::information(this,"提示",ui->radioButton_7->text());
}


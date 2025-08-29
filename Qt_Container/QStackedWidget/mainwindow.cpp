#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel* imageLab1=new QLabel(ui->page);
    QLabel* imageLab2=new QLabel(ui->page_2);
    QPixmap image1(":/images/海贼王.jpg");
    QPixmap image2(":/images/下载_索隆.jpg");
    imageLab1->setPixmap(image1);
    imageLab2->setPixmap(image2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}


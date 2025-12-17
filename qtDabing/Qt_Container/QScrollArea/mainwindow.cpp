#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // QLabel* lable=new QLabel(this);
    // lable->setPixmap(QPixmap(":/下载_索隆.jpg"));
    // lable->setFixedWidth(30);
    // ui->scrollArea->setWidget(lable);  //会把原来的scrollArea覆盖掉
    // ui->scrollArea->setAlignment(Qt::AlignCenter);

    QVBoxLayout* vboxlay =new QVBoxLayout(this);
    for (int i = 0; i < 11; ++i) {
        QLabel* lable=new QLabel(this);
        lable->setPixmap(QPixmap(QString(":/%1").arg(i+1)));
        lable->setAlignment(Qt::AlignCenter); //这里设置才会生效
        vboxlay->addWidget(lable);
    }
    QWidget* widget =new QWidget(this);
    widget->setLayout(vboxlay);
    ui->scrollArea->setWidget(widget);
    ui->scrollArea->setAlignment(Qt::AlignCenter); //没有生效
}

MainWindow::~MainWindow()
{
    delete ui;
}


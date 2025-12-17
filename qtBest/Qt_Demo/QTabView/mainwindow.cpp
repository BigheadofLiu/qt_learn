#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mDb=QSqlDatabase::addDatabase("QMYSQL");
    this->mDb.setHostName("127.0.0.1");
    this->mDb.setPort(3306);
    this->mDb.setUserName("db1");
    this->mDb.setPassword("123456");
    this->mDb.setDatabaseName("mytest");

    if(!mDb.open()){
        QMessageBox::information(this,"error","数据库连接失败，请检查数据库连接状态！");
        return;
    }
     QMessageBox::information(this,"success","数据库连接成功！") ;
    this->mTab=new QSqlTableModel;
    this->mTab->setTable("mytest_stu");   //指定数据表
    // this->mTab->setTable(ui->tableView);
    ui->tableView->setModel(mTab);   //tabview指定 QSqlTableModel
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectBtn_clicked()
{
    this->mTab->select();
}


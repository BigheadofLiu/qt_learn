#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("查询");
    // mDatabase->addDatabase("QMYSQL"); //error
    mDatabase=QSqlDatabase::addDatabase("QMYSQL");  //指定数据库类型
    mDatabase.setHostName("127.0.0.1");  //ip
    mDatabase.setPort(3306);        //端口
    mDatabase.setUserName("db1");    //指定登录名
    mDatabase.setPassword("123456");  //密码
    mDatabase.setDatabaseName("mytest");  //数据库名

    if(!mDatabase.open()){
        QMessageBox::information(this,"error","数据库连接失败，请检查数据库连接状态！");
        return;
    }
    QMessageBox::information(this,"success","数据库连接成功！") ;

    // create table mytest_stu(
    //       id int primary key auto_increment,
    //       name varchar(10),
    //       age tinyint,
    //       gender varchar(2)
    // );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_searchBtn_clicked()
{
    QString id = ui->idLineEdit->text();
    QString name = ui->nameLineEdit->text();
    QString age = ui->ageLineEdit->text();
    QString gender=ui->genderLineEdit->text();

    QSqlQuery query;
    QString sql="select * from mytest_stu";

    if(!id.isEmpty() || !name.isEmpty() || !age.isEmpty()){
        //根据条件拼接sql
        sql += " WHERE ";

        bool firstCondition = true;

        if (!id.isEmpty()) {
            sql += QString("id = %1").arg(id);
            firstCondition = false;
        }

        if (!name.isEmpty()) {
            if (!firstCondition) sql += " AND ";
            sql += QString("name = '%1'").arg(name);
            firstCondition = false;
        }

        if (!age.isEmpty()) {
            if (!firstCondition) sql += " AND ";
            sql += QString("age = %1").arg(age);
        }

        if (!gender.isEmpty()) {
            if (!firstCondition) sql += " AND ";
            sql += QString("gender = '%1' ").arg(gender);
        }
    }

    qDebug() << "执行的SQL:" << sql;  // 调试输出

    if(query.exec(sql)){
        while(query.next()){
            // qDebug() << "找到记录:"
            //          << "ID:" << query.value(0).toString()
            //          << "姓名:" << query.value(1).toString()
            //          << "年龄:" << query.value(2).toString();
            QString result=QString("找到记录:\n"
                            "ID:  %1\n"
                            "姓名: %2\n"
                            "年龄: %3\n"
                            "性别：%4\n")
                                 .arg(query.value(0).toInt())
                                 .arg(query.value(1).toString())
                                 .arg(query.value(2).toInt())
                                 .arg(query.value(3).toString());
            qDebug()<<result;
            QMessageBox::information(this,"查询结果",result);
        }
    }
}


void MainWindow::on_addBtn_clicked()
{
    QString id = ui->idLineEdit->text();
    QString name = ui->nameLineEdit->text();
    QString age = ui->ageLineEdit->text();
    QString gender = ui->genderLineEdit->text();
    QSqlQuery query;
    QString sql=QString("insert into mytest_stu values (%1,'%2',%3,'%4')")
                      .arg(id)
                      .arg(name)
                      .arg(age)
                      .arg(gender);
     qDebug() << "执行的SQL:" << sql;
    if(query.exec(sql)){
        QMessageBox::information(this, "成功", "数据插入成功！");
    }else{
         QMessageBox::critical(this, "失败", "数据插入失败: " + query.lastError().text());
    }
}


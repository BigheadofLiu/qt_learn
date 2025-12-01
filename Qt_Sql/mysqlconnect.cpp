#include "mysqlconnect.h"

mysqlConnect::mysqlConnect(QObject *parent)
    : QObject{parent}
{

}

bool mysqlConnect::connectToMysql()
{
    this->db1=QSqlDatabase::addDatabase("QMYSQL");
    db1.setHostName("127.0.0.1");
    db1.setPort(3306);
    db1.setUserName("db1");
    db1.setPassword("123456");

    if(!db1.open()){
        qDebug()<<"数据库连接失败！\n";
        return false;
    }
    qDebug()<<"数据库连接成功！\n";
    return true;
}

void mysqlConnect::testQuery()
{
    if(!db1.open()){
        qDebug()<<"数据库未连接\n";
        return;
    }
    QString sql="show databases";
    QSqlQuery query;
    query.exec(sql);
    while(query.next()){
         qDebug()<<query.value(0).toString();
    }
}


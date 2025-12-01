#ifndef MYSQLCONNECT_H
#define MYSQLCONNECT_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

class mysqlConnect : public QObject
{
    Q_OBJECT
public:
    explicit mysqlConnect(QObject *parent = nullptr);
    bool connectToMysql(); //检查连接状态
    void testQuery();   //测试sql语句
signals:
private:
    QSqlDatabase db1; //数据库实例
};

#endif // MYSQLCONNECT_H

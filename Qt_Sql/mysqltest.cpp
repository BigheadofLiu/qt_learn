#include "mysqltest.h"

//测试驱动安装情况
mysqlTest::mysqlTest() {
    qDebug() << "SQL Drivers:" << QSqlDatabase::drivers();
}

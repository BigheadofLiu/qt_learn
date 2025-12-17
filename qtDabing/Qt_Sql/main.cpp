#include "mainwindow.h"

#include <QApplication>
#include "mysqltest.h"
#include "mysqlconnect.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    mysqlTest* t1=new mysqlTest();
    // mysqlConnect* connect;


    mysqlConnect* con=new mysqlConnect();
    if(con->connectToMysql()){
        con->testQuery();
    }
    delete con;
    delete t1;
    return a.exec();
}

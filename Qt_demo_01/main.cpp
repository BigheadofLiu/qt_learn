#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    //应用程序类，在一个QT程序中，该对象只有一个
    QApplication a(argc, argv);
    //窗体对象
    MainWindow w;
    //窗体显示
    w.show();
    //阻塞函数，程序进入事件循环
    return a.exec();
}

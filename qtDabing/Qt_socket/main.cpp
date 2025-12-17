#include "mainwindow.h"
#include "clientwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ClientWindow cw;
    w.show();
    cw.show();
    return a.exec();
}

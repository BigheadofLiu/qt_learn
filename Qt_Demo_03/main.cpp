#include "mainwindow.h"

#include <QApplication>

#ifdef _WIN32
#include <windows.h>
#include <iostream>

void attachConsole() {
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
}
#endif


int main(int argc, char *argv[])
{
    #ifdef _WIN32
        attachConsole();
    #endif

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


}

#include "sendfilewindow.h"
#include "recvfilewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sendFileWindow w;
    recvFileWindow efw;
    w.show();
    efw.show();
    return a.exec();
}

#include "sendfilewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sendFileWindow w;
    w.show();
    return a.exec();
}

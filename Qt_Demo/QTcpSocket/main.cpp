#include "qtcpclient.h"
#include "mytcpserver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTcpClient client;
    myTcpServer server;
    client.show();
    server.show();
    return a.exec();
}

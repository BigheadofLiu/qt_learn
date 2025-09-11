#include "sendfilewindow.h"
#include "./ui_sendfilewindow.h"

sendFileWindow::sendFileWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sendFileWindow)
{
    ui->setupUi(this);
}

sendFileWindow::~sendFileWindow()
{
    delete ui;
}

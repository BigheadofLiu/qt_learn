#include "myicon.h"
#include "ui_myicon.h"

MyIcon::MyIcon(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyIcon)
{
    ui->setupUi(this);
}

MyIcon::~MyIcon()
{
    delete ui;
}

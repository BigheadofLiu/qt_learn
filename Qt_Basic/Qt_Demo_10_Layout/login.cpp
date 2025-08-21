#include "login.h"
#include "ui_login.h"
#include <QDialog.h>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    setFixedSize(286,219);
}

Login::~Login()
{
    delete ui;
}

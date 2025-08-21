#include "subdialog.h"
#include "ui_subdialog.h"

#include <qdebug.h>
SubDialog::SubDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SubDialog)
{
    ui->setupUi(this);

}

SubDialog::~SubDialog()
{
    qDebug()<<"sub窗口资源被析构";
    delete ui;
}

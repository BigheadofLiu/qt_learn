#include "mycoin.h"
#include "ui_mycoin.h"

MyCoin::MyCoin(QWidget *parent)
    : QPushButton(parent)
    , ui(new Ui::MyCoin)
{
    ui->setupUi(this);
}

MyCoin::~MyCoin()
{
    delete ui;
}

MyCoin::MyCoin(QString btnImg)
{
    mBtnImg=btnImg;
    QPixmap pix;
    if(!pix.load(mBtnImg)){
        qDebug()<<"图片加载失败！";
    }
    this->setFixedSize(pix.size());
    this->setStyleSheet(
        "QPushButton"
        "{"
        "border:0px;"
        "background:transparent;"
        "}"
        );
    this->setIcon(pix);
    this->setIconSize(pix.size());
}

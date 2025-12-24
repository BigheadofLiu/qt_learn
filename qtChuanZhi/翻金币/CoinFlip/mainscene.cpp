#include "mainscene.h"
#include "./ui_mainscene.h"
#include <QPixmap>
#include <QIcon>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    this->setFixedSize(480,780);
    this->setWindowTitle("牢大带你翻金币");
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));  //为什么设置了不显示
    this->setIconSize(QSize(14,14));

    // qDebug() << "测试资源加载...";
    // QPixmap pixmap(":/res/Coin0001.png");
    // qDebug() << "QPixmap加载结果:" << !pixmap.isNull();
    // qDebug() << "尺寸:" << pixmap.size();
}

MainScene::~MainScene()
{
    delete ui;
}

#include "mywidget.h"
#include "./ui_mywidget.h"
#include <QPixmap>
#include <QPainter>
#include <QPaintDevice>
#include <QImage>
#include <QPicture>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //////绘制QPixmap设备//////
    // QPixmap pix(300,300);  //设定绘图区域大小
    // QPainter painter(&pix); //创建画家 指定绘图设备QPixmap
    // pix.fill(Qt::white);  //设置pix颜色填充
    // painter.setPen(QPen(Qt::darkRed));  //设置画笔
    // painter.setBrush(Qt::yellow);
    // painter.drawEllipse(QPoint(100,100),50,50);
    // pix.save("/home/wdnmd/demo/git/qt_learn/qtChuanZhi/绘图/QPaintDevice/pix.png");

    //////绘制QImage设备 可以对像素点进行操作//////
    // QImage img(300,300,QImage::Format_RGB32);
    // img.fill(Qt::white);
    // QPainter painter(&img);
    // painter.setPen(QPen(Qt::darkRed));  //设置画笔
    // painter.setBrush(Qt::yellow);
    // painter.drawEllipse(QPoint(100,100),50,50);
    // img.save("/home/wdnmd/demo/git/qt_learn/qtChuanZhi/绘图/QPaintDevice/img.png");

    //绘制QPicture设备  可以记录和重现绘图指令（写入二进制文件）
    QPicture pic;
    QPainter painter(this);
    // painter.drawPicture(pic);
    painter.begin(&pic);
    painter.setPen(QPen(Qt::yellow));
    painter.setBrush(Qt::red);
    painter.drawEllipse(100,100,50,50);
    painter.end();
    pic.save("/home/wdnmd/demo/git/qt_learn/qtChuanZhi/绘图/QPaintDevice/pic.pic");  //使用二进制的当时进行存储

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::paintEvent(QPaintEvent *event)
{
    QImage img/*(":/e8903ae61a094a23b8dfa517c82e9f2e.png")*/;
    img.load(":/e8903ae61a094a23b8dfa517c82e9f2e.png");

    QPainter painter(this);
    for(int i=50;i<100;i++){
        for(int j=50;j<100;j++){
            QRgb rgb=qRgb(255,0,0);
            img.setPixel(i,j,rgb);
        }
    }
    painter.drawImage(0,0,img);

    //绘图重现（读取二进制文件）
    QPicture pic1;
    QPainter painter1(this);
    pic1.load("/home/wdnmd/demo/git/qt_learn/qtChuanZhi/绘图/QPaintDevice/pic.pic");
    painter1.begin(&pic1);
    painter1.drawPicture(50,50,pic1);
    painter1.end();
}

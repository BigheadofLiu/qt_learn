#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mXpos(100)
{
    ui->setupUi(this);
    // update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
            //////基础使用/////
    // QPen pen(this); error 不需要指定父对象
    //画笔
    // QPen pen;
    // pen.setColor(QColor(0,0,255));  //设置线条颜色
    // pen.setWidth(2); //设置线条宽度

    // //画刷
    // QBrush brush(Qt::yellow);  //设置画刷填充颜色
    // brush.setStyle(Qt::Dense4Pattern);  //设置画刷填充风格
    // // brush.setColor(Qt::yellow);  //为神马不生效？

    QPainter painter(this);

    // painter.setPen(pen);
    // painter.setBrush(brush);

    // painter.drawLine(QPoint(0,0),QPoint(100,100));

    // painter.drawEllipse(QPoint(100,100),50,50);   //画圆

    // painter.drawRect(150,150,50,100);

    // painter.drawText(QRect(300,200,100,100),"Hello World!");


            /////绘图高级事件/////
    // painter.setRenderHint(QPainter::Antialiasing);  //抗锯齿
    // painter.drawEllipse(QPoint(100,100),50,50);

    // painter.drawRect(150,150,100,50);
    // painter.translate(0,150); //移动绘图起点 防止重叠
    // painter.save(); //保存画家状态
    // painter.drawRect(150,150,100,50);
    // painter.translate(0,150);
    // painter.restore();//还原画家状态
    // painter.drawRect(150,150,100,50);

                //////手动调用绘图事件//////
    QPixmap pic(":/e8903ae61a094a23b8dfa517c82e9f2e.png");
    // pic.fromImage(QImage("qrc:/img/29218a6ac8ea4a2ab3ab2cec50b2ea24.jpg"));
    // qDebug()<<pic.
    if(pic.isNull()){
        qDebug()<<"图片加载失败！";
        // qDebug() << "尝试的路径：:/793548396878132080.jpeg";

        // QFile file(":/793548396878132080.jpeg");
        // qDebug() << "文件是否存在：" << file.exists();

        // QFile file2(":/29218a6ac8ea4a2ab3ab2cec50b2ea24.jpg");
        // qDebug() << "JPG文件是否存在：" << file2.exists();

        // qDebug() << "支持的图片格式：" << QImageReader::supportedImageFormats();
        return;
    }
    // qDebug() << "图片加载成功，尺寸：" << pic.size();

    painter.drawPixmap(QPoint(mXpos,100),pic);
    // painter.drawLine(QPoint(100,100),QPoint(100,200));

}

void MainWindow::on_moveBtn_clicked()
{
    this->mXpos+=20;
    update();
    if(this->mXpos>this->width()){
        this->mXpos=0;
    }
}


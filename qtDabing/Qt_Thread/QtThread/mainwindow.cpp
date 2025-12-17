#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //继承QThread的方式
    //创建子线程（创建随机数）
    createRandNum* createRandom=new createRandNum(this);  //这里带参数与不带参数有啥区别
    connect(this,&MainWindow::setNum,createRandom,&createRandNum::recvNum);  //（先绑定）绑定用于接收主线程设置的随机数生成个数
    //启动子线程
    connect(ui->startBtn,&QPushButton::clicked,this,[=](){
        //子线程启动之前需要指定生成随机数的个数（由主线程发出）
        emit this->setNum(10000);  //设置生成随机数个数为10000
        createRandom->start();
    });

    connect(createRandom,&createRandNum::sendVector,this,[=](QVector<int> list){
        for(auto i:list){
            ui->randList->addItem(QString::number(i));
        }
    });

    //冒泡排序
    bubbleSort* bubble=new bubbleSort(this);
    connect(createRandom,&createRandNum::sendVector,bubble,&bubbleSort::recvVector);
    connect(ui->startBubbBtn,&QPushButton::clicked,this,[=](){

        //bubble 开始之前 需要设置mList
        bubble->start();
    });
    connect(bubble,&bubbleSort::sendVector,this,[=](QVector<int> list){
        for(auto i:list){
            ui->bubbList->addItem(QString::number(i));
        }
    });

    //快速排序
    quickSort* quick =new quickSort(this);
    connect(createRandom,&createRandNum::sendVector,quick,&quickSort::recvVector);
    connect(ui->startQuickBtn,&QPushButton::clicked,[=](){
        quick->start();
    });
    connect(quick,&quickSort::sendVector,this,[=](QVector<int> list){
        for(auto i:list){
            ui->quickList->addItem(QString::number(i));
        }
    });

    //堆排序
    heapSort* heap =new heapSort(this);
    connect(createRandom,&createRandNum::sendVector,heap,&heapSort::recvVector);
    connect(ui->startHeapBtn,&QPushButton::clicked,[=](){
        heap->start();
    });
    connect(heap,&heapSort::sendVector,this,[=](QVector<int> list){
        for(auto i:list){
            ui->heapList->addItem(QString::number(i));
        }
    });

    //线程销毁
    connect(this,&MainWindow::destroyed,this,[=](){
        createRandom->quit();
        createRandom->wait();

        bubble->quit();
        bubble->wait();

        quick->quit();
        quick->wait();

        heap->quit();
        heap->wait();

        createRandom->deleteLater();
        bubble->deleteLater();
        quick->deleteLater();
        heap->deleteLater();

    });
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_startBtn_clicked(){

}
#if 0
void MainWindow::on_startBtn_clicked()
{
    // 单线程模式 执行以下循环时 窗口拖动无响应（窗口主线程被阻塞）
    //不允许使用子线程直接操作主线程
    for(int i=0;i<10000000;++i){
        ui->numLab->setNum(i);
    }
}
#endif



#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QThread* t1=new QThread;
    QThread* t2=new QThread;
    QThread* t3=new QThread;
    QThread* t4=new QThread;

    //创建任务对象
    createRandNum* createRandom=new createRandNum(this);
    bubbleSort* bubble=new bubbleSort(this);
    quickSort* quick =new quickSort(this);
    heapSort* heap =new heapSort(this);
    //这样改三个排序按钮直接退役了。。。
    createRandom->moveToThread(t1);
    bubble->moveToThread(t2);
    quick->moveToThread(t3);
    heap->moveToThread(t4);

    connect(this,&MainWindow::setNum,createRandom,&createRandNum::working);  //（先绑定）绑定用于接收主线程设置的随机数生成个数

    connect(ui->startBtn,&QPushButton::clicked,this,[=](){
        emit this->setNum(10000);  //设置生成随机数个数为10000

        t1->start();
    });
    connect(createRandom,&createRandNum::sendVector,this,[=](QVector<int> list){
        ui->randList->clear();
        for(auto i:list){
            ui->randList->addItem(QString::number(i));
        }
    });

    //冒泡排序
    connect(createRandom,&createRandNum::sendVector,bubble,&bubbleSort::working);
    connect(ui->startBubbBtn,&QPushButton::clicked,this,[=](){

        //bubble 开始之前 需要设置mList
        t2->start();
    });
    connect(bubble,&bubbleSort::sendVector,this,[=](QVector<int> list){
        ui->bubbList->clear();
        for(auto i:list){
            ui->bubbList->addItem(QString::number(i));
        }
    });

    //快速排序
    connect(createRandom,&createRandNum::sendVector,quick,&quickSort::working);
    connect(ui->startQuickBtn,&QPushButton::clicked,[=](){
        t3->start();
    });
    connect(quick,&quickSort::sendVector,this,[=](QVector<int> list){
        ui->quickList->clear();
        for(auto i:list){
            ui->quickList->addItem(QString::number(i));
        }
    });

    //堆排序
    connect(createRandom,&createRandNum::sendVector,heap,&heapSort::working);
    connect(ui->startHeapBtn,&QPushButton::clicked,[=](){
        t4->start();
    });
    connect(heap,&heapSort::sendVector,this,[=](QVector<int> list){
        ui->heapList->clear();
        for(auto i:list){
            ui->heapList->addItem(QString::number(i));
        }
    });

    //线程的销毁
    connect(this,&MainWindow::destroy,this,[=](){
        t1->quit();
        t1->wait();
        t1->deleteLater();

        t2->quit();
        t2->wait();
        t2->deleteLater();

        t3->quit();
        t3->wait();
        t3->deleteLater();

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



void MainWindow::on_startBtn_clicked()
{

}


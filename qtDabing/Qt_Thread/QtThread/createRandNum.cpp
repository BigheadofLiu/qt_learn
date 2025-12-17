#include "createRandNum.h"

createRandNum::createRandNum(QObject *parent)
    : QThread{parent}
{}

void createRandNum::recvNum(int num)
{
    this->mNum=num;
}

//用于生成随机数
void createRandNum::run()
{
    qDebug()<<"生成随机数的线程地址为"<<QThread::currentThread();
    QVector<int> randList;
    QElapsedTimer time;
    time.start();
    for(int i=0;i<mNum;++i){
        // srand(time(0));
        randList.push_back(rand()%10000+1);
    }
   int millsec=time.elapsed();
    qDebug()<<"生成"<<mNum<<"个随机数耗时"<<millsec<<"毫秒";
   emit sendVector(randList);
}



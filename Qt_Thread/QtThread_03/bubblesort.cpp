#include "bubblesort.h"


bubbleSort::bubbleSort(QObject *parent)
    : QObject{parent},QRunnable()
{
    setAutoDelete(true);
}

void bubbleSort::recvVector(QVector<int> list)
{
    this->mList=list;
}


void bubbleSort::run()
{
    qDebug()<<"冒泡排序线程的地址为"<<QThread::currentThread();
    QElapsedTimer time;
    time.start();
    this->sort(mList);
    int millsec =time.elapsed();
    qDebug()<<"冒泡排序用时"<<millsec<<"毫秒";
    emit sendVector(mList); //把排序后的vector发出
}

void bubbleSort::sort(QVector<int>& list)
{
    int n=list.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                std::swap(list[j], list[j + 1]);
            }
        }
    }
}

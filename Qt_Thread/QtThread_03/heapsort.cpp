#include "heapsort.h"

heapSort::heapSort(QObject *parent)
    : QObject{parent},QRunnable()
{
    setAutoDelete(true);
}

void heapSort::recvVector(QVector<int> list)
{
    this->mList=list;
}

void heapSort::run()
{
    qDebug()<<"堆排序线程的地址为"<<QThread::currentThread();
    QElapsedTimer time;
    time.start();
    this->sort(mList);
    int millsec =time.elapsed();
    qDebug()<<"堆排序用时"<<millsec<<"毫秒";
    emit sendVector(mList); //把排序后的vector发出
}

void heapSort::sort(QVector<int> &list)
{
    int n = list.size();

    // 建立最大堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(list, n, i);
    }

    // 逐个取出堆顶元素
    for (int i = n - 1; i > 0; i--) {
        qSwap(list[0], list[i]);  // 把最大值放到数组末尾
        heapify(list, i, 0);      // 重新调整堆
    }
}

void heapSort::heapify(QVector<int> &list, int n, int i)
{
    int largest = i;       // 当前最大元素下标
    int l = 2 * i + 1;     // 左子节点
    int r = 2 * i + 2;     // 右子节点

    if (l < n && list[l] > list[largest]) {
        largest = l;
    }
    if (r < n && list[r] > list[largest]) {
        largest = r;
    }

    if (largest != i) {
        qSwap(list[i], list[largest]);
        heapify(list, n, largest); // 递归调整
    }
}

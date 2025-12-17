#include "quicksort.h"

quickSort::quickSort(QObject *parent)
    : QObject{parent}
{}

// void quickSort::recvVector(QVector<int> list)
// {
//     this->mList=list;
// }

void quickSort::working(QVector<int> list)
{
    qDebug()<<"快速排序线程的地址为"<<QThread::currentThread();
    QElapsedTimer time;
    time.start();
    this->sort(list);
    int millsec =time.elapsed();
    qDebug()<<"快速排序用时"<<millsec<<"毫秒";
    emit sendVector(list); //把排序后的vector发出
}
void quickSort::sort(QVector<int> &list)
{
    quickSortHelper(list, 0, list.size() - 1);
}

void quickSort::quickSortHelper(QVector<int> &list, int left, int right)
{
    if (left >= right) return;

    int i = left, j = right;
    int pivot = list[left]; // 选取第一个元素为基准

    while (i < j) {
        // 从右往左找小于 pivot 的数
        while (i < j && list[j] >= pivot) j--;
        if (i < j) list[i++] = list[j];

        // 从左往右找大于等于 pivot 的数
        while (i < j && list[i] < pivot) i++;
        if (i < j) list[j--] = list[i];
    }

    list[i] = pivot; // 基准归位

    quickSortHelper(list, left, i - 1);
    quickSortHelper(list, i + 1, right);
}


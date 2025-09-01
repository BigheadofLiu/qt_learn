#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <QObject>
#include <QThread>
#include <QVector>
#include <QElapsedTimer>
#include <QDebug>


class  quickSort  : public QObject
{
    Q_OBJECT
public:
    explicit  quickSort (QObject *parent = nullptr);
    // void recvVector(QVector<int> list);
// protected:
    void working(QVector<int> list) ;
    void sort(QVector<int>& list);
    void quickSortHelper(QVector<int> &list, int left, int right);
signals:
    void sendVector(QVector<int> list);
private:
    // QVector<int> mList;
};
#endif // QUICKSORT_H

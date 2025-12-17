#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <QObject>
#include <QThread>
#include <QVector>
#include <QElapsedTimer>
#include <QDebug>
#include <QRunnable>

class heapSort  : public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit heapSort (QObject *parent = nullptr);
    void recvVector(QVector<int> list);
// protected:
    // void working(QVector<int> list) ;
    void run() override;
    void sort(QVector<int>& list);
    void heapify(QVector<int> &list, int n, int i);
signals:
    void sendVector(QVector<int> list);
private:
    QVector<int> mList;
};

#endif // HEAPSORT_H

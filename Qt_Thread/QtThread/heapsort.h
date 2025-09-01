#ifndef HEAPSORT_H
#define HEAPSORT_H


#include <QThread>
#include <QVector>
#include <QElapsedTimer>
#include <QDebug>


class heapSort  : public QThread
{
    Q_OBJECT
public:
    explicit heapSort (QObject *parent = nullptr);
    void recvVector(QVector<int> list);
protected:
    void run() override;
    void sort(QVector<int>& list);
    void heapify(QVector<int> &list, int n, int i);
signals:
    void sendVector(QVector<int> list);
private:
    QVector<int> mList;
};

#endif // HEAPSORT_H

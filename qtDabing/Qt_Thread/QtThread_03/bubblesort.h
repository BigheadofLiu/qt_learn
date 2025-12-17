#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <QObject>
#include <QThread>
#include <QVector>
#include <QElapsedTimer>
#include <QDebug>
#include <QRunnable>

class bubbleSort  : public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit bubbleSort (QObject *parent = nullptr);
    void recvVector(QVector<int> list);
// protected:
// public slots:
// void working(QVector<int> List) ;
    void run() override;
signals:
    void sendVector(QVector<int> list);
private:
    QVector<int> mList;
void sort(QVector<int>& list);
};

#endif // BUBBLESORT_H

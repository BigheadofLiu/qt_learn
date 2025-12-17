#ifndef BUBBLESORT_H
#define BUBBLESORT_H


#include <QThread>
#include <QVector>
#include <QElapsedTimer>
#include <QDebug>


class bubbleSort  : public QThread
{
    Q_OBJECT
public:
    explicit bubbleSort (QObject *parent = nullptr);
    void recvVector(QVector<int> list);
protected:
    void run() override;
    void sort(QVector<int>& list);
signals:
    void sendVector(QVector<int> list);
private:
    QVector<int> mList;
};

#endif // BUBBLESORT_H

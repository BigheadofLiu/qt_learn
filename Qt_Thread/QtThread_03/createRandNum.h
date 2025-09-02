#ifndef CREATERANDNUM_H
#define CREATERANDNUM_H

#include <QObject>
#include <QThread>
#include <QVector>
#include <QElapsedTimer>
#include <QDebug>
#include <QRunnable>
//用于生成随机数
class createRandNum : public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit createRandNum(QObject *parent = nullptr);
    void recvNum(int num);
// protected:
    // void working(int num) ;
    void run() override;
signals:
    void sendVector(QVector<int> list);
private:
    int mNum;
};

#endif // CREATERANDNUM_H

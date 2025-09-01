#ifndef CREATERANDNUM_H
#define CREATERANDNUM_H

#include <QThread>
#include <QVector>
#include <QElapsedTimer>
#include <QDebug>

//用于生成随机数
class createRandNum : public QThread
{
    Q_OBJECT
public:
    explicit createRandNum(QObject *parent = nullptr);
    void recvNum(int num);
protected:
    void run() override;

signals:
    void sendVector(QVector<int>);
private:
    int mNum;
};

#endif // CREATERANDNUM_H

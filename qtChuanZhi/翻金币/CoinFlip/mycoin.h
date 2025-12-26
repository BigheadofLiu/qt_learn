#ifndef MYCOIN_H
#define MYCOIN_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>
#include <QPixmap>

namespace Ui {
class MyCoin;
}

class MyCoin : public QPushButton
{
    Q_OBJECT

public:
    explicit MyCoin(QWidget *parent = nullptr);
    ~MyCoin();
    MyCoin(QString btnImg);
    void cionChange();
    QTimer* mTimer1;
    QTimer* mTimer2;

private:
    Ui::MyCoin *ui;
    QString mBtnImg;

public:
    int mPosX;   //金币坐标
    int mPosY;
    bool mFlag;  //金币正反面
    int mMin=1;  //金币图1
    int mMax=8;  //金币图2
};

#endif // MYCOIN_H

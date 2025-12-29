#ifndef MYCOIN_H
#define MYCOIN_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>
#include <QPixmap>
#include <QMouseEvent>

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

    void mousePressEvent(QMouseEvent *even) override;
protected:
    // void mousePressEvent(QMouseEvent *even) override;

private:
    Ui::MyCoin *ui;
    QString mBtnImg;
    QTimer* mTimer1;
    QTimer* mTimer2;
    bool isDomain=false;  //禁止连击
    int mMin=1;  //金币图1
    int mMax=8;  //金币图2


public:   //设置为private类外访问不到
    int mPosX;    //金币x数组下标
    int mPosY;    //金币y数组坐标
    bool mFlag;  //金币正反面    1金币 0银币
    bool mIsWin=false; //判断游戏是否胜利（用于禁用金币是否可翻动）
};

#endif // MYCOIN_H

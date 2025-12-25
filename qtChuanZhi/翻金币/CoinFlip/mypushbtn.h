#ifndef MYPUSHBTN_H
#define MYPUSHBTN_H

// #include <QWidget>
#include <QPushButton>
#include <QString>
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>  //神马头文件
#include <QEasingCurve>

class MyPushBtn : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushBtn(QWidget *parent = nullptr);
    MyPushBtn(QString NormalImgPath,QString PressedImgPath=""/*,QWidget *parent = nullptr*/);
    void myZoom1();
    void myZoom2();
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
signals:

private:
    QString mNormalImgPath;  //默认图片
    QString mPressedImgPath; //按下之后的图片
};

#endif // MYPUSHBTN_H

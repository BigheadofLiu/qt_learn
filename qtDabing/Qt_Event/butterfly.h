#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QRandomGenerator>
#include <QApplication>
#include <QGuiApplication>

class butterFly : public QWidget
{
    Q_OBJECT
public:
    explicit butterFly(QWidget *parent = nullptr);
    void fly();
    void fly(int min,int max);  //用于蝴蝶移动
protected:
    void paintEvent(QPaintEvent* e) override;  //重写事件函数
    void timerEvent(QTimerEvent* e) override;
    void mouseMoveEvent(QMouseEvent* e) override;
    void mousePressEvent(QMouseEvent* e) override;
    void enterEvent(QEnterEvent* e) override;  //Qt6中被QEnterEven替代
signals:
private:
    QPixmap mPixmap;  //用于绘制图片
    int mIndex;  //用于控制图片
    QPoint mPoint; //用于记录鼠标移动后图片的坐标
};

#endif // BUTTERFLY_H

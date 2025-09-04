#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPainter>
#include <QEvent>
#include <QEnterEvent>
#include <QMouseEvent>

class myButton : public QWidget
{
    Q_OBJECT
public:
    explicit myButton(QWidget *parent = nullptr);

signals:
protected:
    void mousePressEvent(QMouseEvent* e) override;  //重写父类QWidget的方法
    void mouseReleaseEvent(QMouseEvent* e) override;
    void enterEvent(QEnterEvent* e) override;   //qt6的坑 这里参数类型由：QEvent->QEnterEvent
    void leaveEvent(QEvent* e) override ;
    void paintEvent(QPaintEvent* e) override;
private:
    QPixmap mPixmap;  //用于显示图片
    /*QImage mImage; */  //用于像素级别的修改
};

#endif // MYBUTTON_H

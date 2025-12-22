#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QEnterEvent>
#include <QDebug>
#include <QMoveEvent>
#include <QLabel>

namespace Ui {
class MyLabel;
}

class MyLabel : public QLabel
{
    Q_OBJECT

public:
    explicit MyLabel(QWidget *parent = nullptr);
    ~MyLabel();

protected:
    void enterEvent(QEnterEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void leaveEvent(QEvent *event) override;

    bool event(QEvent *e) override;
    bool eventFilter(QObject *obj, QEvent *event) override;
private:
    Ui::MyLabel *ui;
};

#endif // MYLABEL_H

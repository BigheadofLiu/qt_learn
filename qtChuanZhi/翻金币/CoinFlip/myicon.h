#ifndef MYICON_H
#define MYICON_H

#include <QWidget>

namespace Ui {
class MyIcon;
}

class MyIcon : public QWidget
{
    Q_OBJECT

public:
    explicit MyIcon(QWidget *parent = nullptr);
    ~MyIcon();

private:
    Ui::MyIcon *ui;
};

#endif // MYICON_H

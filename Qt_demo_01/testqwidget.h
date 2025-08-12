#ifndef TESTQWIDGET_H
#define TESTQWIDGET_H

#include <QWidget>

namespace Ui {
class TestForm;
}

class TestForm : public QWidget
{
    Q_OBJECT

public:
    explicit TestForm(QWidget *parent = nullptr);
    ~TestForm();

private:
    Ui::TestForm *ui;
};

#endif // TESTQWIDGET_H

#ifndef MYCOIN_H
#define MYCOIN_H

#include <QWidget>
#include <QPushButton>

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
private:
    Ui::MyCoin *ui;
    QString mBtnImg;
};

#endif // MYCOIN_H

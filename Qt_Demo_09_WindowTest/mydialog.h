#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class myDialog;
}

class myDialog : public QDialog
{
    Q_OBJECT

public:
    explicit myDialog(QWidget *parent = nullptr);
    ~myDialog();

private slots:
    void on_acceptBtn_clicked();

    void on_rejectBtn_clicked();

    void on_doneBtn_clicked();

private:
    Ui::myDialog *ui;
};

#endif // MYDIALOG_H

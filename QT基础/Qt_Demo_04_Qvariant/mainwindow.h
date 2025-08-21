#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qvariant.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct person
{
    int age;
    QString name;
};
Q_DECLARE_METATYPE(person);

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static QVariant DataPlus(QVariant,QVariant);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

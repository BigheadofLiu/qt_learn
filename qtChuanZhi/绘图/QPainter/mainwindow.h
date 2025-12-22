#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintDevice>
#include <QPaintEvent>
#include <QPixmap>
#include <QFile>
#include <QImage>
#include <QImageReader>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void on_moveBtn_clicked();

private:
    Ui::MainWindow *ui;
    int mXpos;
};
#endif // MAINWINDOW_H

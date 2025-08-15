#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "subdialog.h"
/**
 * Qt 的内存回收机制（基于 QObject 对象树）
 *
 * 1. Qt 的大多数类（如 QWidget、QPushButton 等）都继承自 QObject。
 * 2. Qt 通过“父子对象机制”实现对象的自动回收：
 *    - 每个 QObject 可以有一个父对象（parent）；
 *    - 当父对象被析构时，它会自动 delete 所有子对象，避免内存泄漏。
 *    - 注意：这里的“父子关系”是对象之间的关系，不一定是类的继承关系。
 *
 * 3. 指定父对象的方式有两种：
 *    a. 通过构造函数传入父对象指针（常见写法）：
 *         QPushButton* btn = new QPushButton("确定", this);
 *
 *    b. 创建对象后通过 setParent() 方法设置父对象：
 *         QPushButton* btn = new QPushButton("确定");
 *         btn->setParent(this);
 *
 * 4. 建议优先使用构造函数方式设置父对象，更安全、简洁。
 *
 * 5. 如果对象未设置父对象，Qt 不会自动回收它，必须手动 delete。
 */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"QT 你真帅";
#if 0
    //指定sub_1的副窗体为MainWindow
    //观察MainWindow关闭后 sub_1的析构函数输出(sub窗口资源被析构)
    SubDialog* sub_1 =new SubDialog(this);
    sub_1->show();
#endif

}

MainWindow::~MainWindow()
{
    delete ui;
}

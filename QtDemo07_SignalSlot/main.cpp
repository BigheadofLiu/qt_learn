#include "mainwindow.h"

#include <QApplication>

/**
 *  信号槽机制（Signals and Slots）
 *
 *  - 信号（Signal）本质是一种事件通知机制。Qt 中，信号由 QObject 的子类实例发出，
 *    通常用于通知其他对象某个状态已经发生改变或某个操作已经完成。
 *
 *  - 槽（Slot）是一个普通的成员函数，用于接收和处理信号。它可以执行任何操作，
 *    包括修改 UI、处理数据等。
 *
 *  - connect() 函数用于将信号与槽连接起来，使得当一个信号被发出时，自动调用对应的槽函数。
 *    Qt5/6 推荐的现代写法：
 *      connect(sender, &SenderClass::signalName, receiver, &ReceiverClass::slotName);
 *    Qt4/5 的旧写法（字符串）也可用，但不推荐：
 *      connect(sender, SIGNAL(signalName()), receiver, SLOT(slotName()));
 *
 *  - 注意：
 *    1. 信号和槽函数的参数数量和类型必须一致。
 *    2. 使用信号槽机制的类必须继承自 QObject，并且包含 Q_OBJECT 宏（启用元对象系统）。
 */

int main(int argc, char *argv[])
{
    #if 1
    #endif
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

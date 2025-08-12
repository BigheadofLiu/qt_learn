#include "mainwindow.h"
#include <QApplication>
#include <qvariant.h>
#include <QDebug>

#ifdef _WIN32
#include <windows.h>
void attachConsole() {
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
}
#endif
/**
 * QVariant 是 Qt 中的通用数据容器，可以在运行时存储和传递任意类型的变量，
 * 包括 Qt 内建类型（int、QString、double 等）以及用户自定义类型。
 *
 * 使用场景：
 * - 通用接口参数（如 model/view、信号槽等）
 * - 动态类型存储
 *
 * 主要接口：
 * - QVariant::fromValue<T>()：存储任意类型（需要 Q_DECLARE_METATYPE 支持）
 * - QVariant::value<T>()：提取数据（需要类型匹配）
 * - QVariant::canConvert<T>()：判断能否安全转换为指定类型
 *
 * 使用自定义类型注意：
 * - 必须用 Q_DECLARE_METATYPE(type) 宏注册类型
 * - 在运行时使用 qRegisterMetaType<type>() 注册到元对象系统
 */
int main(int argc, char *argv[])
{
    #ifdef _WIN32
        attachConsole();
    #endif

    #if 0
        // QVariant q1=MainWindow::DataPlus(10,20);
        //需要匿名对象接收数据
        int Ret1=MainWindow::DataPlus(10,20).toInt();
        QString Ret2=MainWindow::DataPlus("hello","world!").toString();
        qDebug()<<Ret1<<" "<<Ret2;

    #endif

         person p{18,"丁真珍珠"};
    #if 0
        //方法1 通过setvalue方法
         QVariant v;
         v.setValue(p);
    #else
         //方法2 通过fromvalue方法
         QVariant v=QVariant::fromValue(p);
    #endif
         if(v.canConvert<person>()){
             auto temp=v.value<person>();
             qDebug()<<temp.age<<" "<<temp.name;
         }
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
}

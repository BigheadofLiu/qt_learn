#include "mainwindow.h"

#include <QApplication>
/**
 * 1. QPoint：表示二维空间中的一个“点”，由 x 和 y 坐标组成。
 *    - 构造函数：
 *        QPoint()                // 创建默认点 (0, 0)
 *        QPoint(int x, int y)    // 创建点 (x, y)
 *    - 常用方法：
 *        x(), y()                // 获取坐标
 *        setX(int), setY(int)    // 设置坐标
 *        isNull()                // 是否为 (0, 0)
 *        manhattanLength()       // 返回从原点到该点的曼哈顿距离（|x| + |y|）
 *        +=, -=, +, -            // 点之间加减支持运算符重载

 * 2. QSize：表示一个“尺寸”，由宽度（width）和高度（height）构成。
 *    - 构造函数：
 *        QSize()                     // 创建默认尺寸 (0, 0)
 *        QSize(int width, int height)
 *    - 常用方法：
 *        width(), height()           // 获取宽高
 *        setWidth(int), setHeight(int)
 *        isEmpty()                   // 是否为0尺寸
 *        expandedTo(QSize)           // 取两者最大尺寸
 *        boundedTo(QSize)            // 取两者最小尺寸

 * 3. QLine：表示一条“线段”，由起点和终点（两个 QPoint）定义。
 *    - 构造函数：
 *        QLine()                              // 默认空线段
 *        QLine(QPoint p1, QPoint p2)          // 用两点构造
 *        QLine(int x1, y1, x2, y2)            // 用坐标构造
 *    - 常用方法：
 *        p1(), p2()                           // 获取起点、终点
 *        setP1(QPoint), setP2(QPoint)
 *        dx(), dy()                           // 获取水平/垂直距离
 *        length()                             // 获取线段长度（浮点型在 QLineF）
 *        translate(dx, dy)                    // 平移线段

 * 4. QRect：表示一个“矩形区域”，由左上角坐标和尺寸确定。
 *    - 构造函数：
 *        QRect()                              // 默认空矩形
 *        QRect(int x, int y, int w, int h)     // 指定左上角和尺寸
 *        QRect(QPoint topLeft, QSize size)
 *    - 常用方法：
 *        x(), y(), width(), height()          // 获取位置与尺寸
 *        topLeft(), bottomRight()             // 获取四个角的位置
 *        contains(QPoint), intersects(QRect)  // 判断包含与相交
 *        moveTo(), moveCenter(), translate()  // 移动矩形
 *        adjusted(), normalized()             // 返回调整后的矩形
 *
 * 这些类广泛应用于 Qt 的绘图、事件处理、控件布局、碰撞检测等模块，
 * 是图形界面开发中的基础工具类。它们支持运算符重载，使用灵活且直观。
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

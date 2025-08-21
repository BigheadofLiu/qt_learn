#include "mainwindow.h"

#include <QApplication>

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QElapsedTimer>

#include <QDebug>
/*
 * Qt 时间相关类：QDate、QTime、QDateTime 概述
 *
 * 一、QDate —— 表示“日期”（年/月/日）
 * ----------------------------------------
 * 常用构造函数：
 *   QDate()                             // 创建无效日期
 *   QDate(int year, int month, int day) // 创建指定年月日的日期
 *
 * 常用方法：
 *   isValid()、year()、month()、day()
 *   toString("yyyy-MM-dd")             // 按格式转为字符串
 *   addDays(int)、addMonths(int)、addYears(int)
 *   daysTo(QDate)                      // 当前日期到另一个日期的间隔天数
 *   QDate::currentDate()               // 获取当前系统日期
 *   QDate::fromString(str, format)     // 从字符串解析日期
 *
 * 示例：
 *   QDate date = QDate::currentDate();
 *   QString s = date.toString("yyyy年MM月dd日");

 *
 * 二、QTime —— 表示“时间”（时:分:秒:毫秒）
 * ----------------------------------------
 * 常用构造函数：
 *   QTime()                             // 创建无效时间
 *   QTime(int h, int m, int s = 0, int ms = 0) // 指定时分秒毫秒
 *
 * 常用方法：
 *   isValid()、hour()、minute()、second()、msec()
 *   toString("HH:mm:ss.zzz")           // 格式化为字符串
 *   addSecs(int)、addMSecs(int)
 *   secsTo(QTime)、msecsTo(QTime)
 *   QTime::currentTime()               // 获取当前系统时间
 *
 * 示例：
 *   QTime time = QTime::currentTime();
 *   QString s = time.toString("hh:mm:ss");

 *
 * 三、QDateTime —— 表示“日期+时间”的组合
 * ----------------------------------------
 * 常用构造函数：
 *   QDateTime()                         // 无效时间戳
 *   QDateTime(QDate date, QTime time)  // 由日期+时间构造
 *
 * 常用方法：
 *   date()、time()、isValid()
 *   toString("yyyy-MM-dd HH:mm:ss")
 *   addDays(int)、addSecs(int)
 *   QDateTime::currentDateTime()       // 获取当前日期+时间
 *   QDateTime::fromString(str, format)
 *   toSecsSinceEpoch()                 // 获取自1970以来的时间戳（秒）
 *
 * 示例：
 *   QDateTime dt = QDateTime::currentDateTime();
 *   QString s = dt.toString("yyyy-MM-dd hh:mm:ss");

 *
 * 四、三者之间的转换与应用
 * ----------------------------------------
 *   QDateTime dt(date, time);          // 合成 QDateTime
 *   dt.date();                         // 拆分出 QDate
 *   dt.time();                         // 拆分出 QTime
 *
 * 典型应用场景：
 *   - 日志记录、时间戳比较、定时任务
 *   - UI 控件：QDateEdit、QTimeEdit、QDateTimeEdit
 *   - 文件的创建时间/修改时间处理
 */

int main(int argc, char *argv[])
{
#if 0
    QDate time1=QDate::currentDate();
    qDebug()<<time1.year()<<" "<<time1.month()<<" "<<time1.day();
#elif 0
    QDate time2=QDate::currentDate();
    QString str1=time2.toString("yyyy-MM-dd");
    qDebug()<<str1;
#elif 0
    QTime qt1=QTime::currentTime();
    qDebug()<<qt1.hour()<<":"<<qt1.minute()<<":"<<qt1.second();
#elif 0
    QTime qt2=QTime::currentTime();
    QString str2=qt2.toString("hh:mm:ss.zzz");  //设置输出格式
    qDebug()<<str2;
#elif 0
    // QT6已废弃方法
    // QTime tt;
    // tt.start();
    // CreateRandomNumber();
    // int ms=tt.elapsed();

    //新
    QElapsedTimer tt;
    tt.start();
    CreateRandomNumber();
    int ms=tt.elapsed();
    qDebug()<<ms<<"ms";
#elif 1
    QDateTime qdt=QDateTime::currentDateTime();
    QString qs=qdt.toString("yyyy-MM-dd hh:mm:ss ap");
    qDebug()<<qs;

    QDate qd=qdt.date();
    QTime qt=qdt.time();
    QString qd1=qd.toString("yyyy-MM-dd");
    QString qt1=qt.toString("hh:mm:ss:ms");
    qDebug()<<qd1;
    qDebug()<<qt1;

#endif

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QProgressBar *progressBar;
    QLCDNumber *lcdNumber;
    QWidget *page_3;
    QWidget *page_4;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_2);

        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName("toolBox");
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 778, 210));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName("verticalLayout");
        calendarWidget = new QCalendarWidget(page);
        calendarWidget->setObjectName("calendarWidget");

        verticalLayout->addWidget(calendarWidget);

        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/\345\203\217\347\264\240_\347\214\253.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page, icon, QString::fromUtf8("\345\267\245\345\205\267\346\240\2171"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 778, 83));
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        progressBar = new QProgressBar(page_2);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        verticalLayout_2->addWidget(progressBar);

        lcdNumber = new QLCDNumber(page_2);
        lcdNumber->setObjectName("lcdNumber");

        verticalLayout_2->addWidget(lcdNumber);

        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/\345\203\217\347\264\240_\350\215\257\346\260\264.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_2, icon1, QString::fromUtf8("\345\267\245\345\205\267\346\240\2172"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/\345\203\217\347\264\240_\346\240\221.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_3, icon2, QString::fromUtf8("\345\267\245\345\205\267\346\240\2173"));
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/\345\203\217\347\264\240-\351\273\204\351\271\246\351\271\211.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_4, icon3, QString::fromUtf8("\345\267\245\345\205\267\346\240\2174"));

        verticalLayout_3->addWidget(toolBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\2171", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\2172", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\2173", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_4), QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\2174", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *CloseBtn;
    QPushButton *hungryBtn;
    QPushButton *hungryBtn2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        CloseBtn = new QPushButton(centralwidget);
        CloseBtn->setObjectName("CloseBtn");
        CloseBtn->setGeometry(QRect(180, 100, 80, 18));
        hungryBtn = new QPushButton(centralwidget);
        hungryBtn->setObjectName("hungryBtn");
        hungryBtn->setGeometry(QRect(180, 140, 80, 18));
        hungryBtn2 = new QPushButton(centralwidget);
        hungryBtn2->setObjectName("hungryBtn2");
        hungryBtn2->setGeometry(QRect(180, 180, 92, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        CloseBtn->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\347\252\227\345\217\243", nullptr));
        hungryBtn->setText(QCoreApplication::translate("MainWindow", "\346\210\221\351\245\277\344\272\206", nullptr));
        hungryBtn2->setText(QCoreApplication::translate("MainWindow", "\346\210\221\344\271\237\351\245\277\344\272\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

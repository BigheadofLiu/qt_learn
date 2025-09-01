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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QListWidget *randList;
    QPushButton *startBtn;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QListWidget *quickList;
    QPushButton *startQuickBtn;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QListWidget *bubbList;
    QPushButton *startBubbBtn;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QListWidget *heapList;
    QPushButton *startHeapBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(11, 11, 778, 551));
        horizontalLayout = new QHBoxLayout(groupBox_5);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(groupBox_5);
        groupBox->setObjectName("groupBox");
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        randList = new QListWidget(groupBox);
        randList->setObjectName("randList");

        verticalLayout_2->addWidget(randList);

        startBtn = new QPushButton(groupBox);
        startBtn->setObjectName("startBtn");

        verticalLayout_2->addWidget(startBtn);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(groupBox_5);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        quickList = new QListWidget(groupBox_2);
        quickList->setObjectName("quickList");

        verticalLayout_3->addWidget(quickList);

        startQuickBtn = new QPushButton(groupBox_2);
        startQuickBtn->setObjectName("startQuickBtn");

        verticalLayout_3->addWidget(startQuickBtn);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox_5);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        bubbList = new QListWidget(groupBox_3);
        bubbList->setObjectName("bubbList");

        verticalLayout_4->addWidget(bubbList);

        startBubbBtn = new QPushButton(groupBox_3);
        startBubbBtn->setObjectName("startBubbBtn");

        verticalLayout_4->addWidget(startBubbBtn);


        horizontalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(groupBox_5);
        groupBox_4->setObjectName("groupBox_4");
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setObjectName("verticalLayout_5");
        heapList = new QListWidget(groupBox_4);
        heapList->setObjectName("heapList");

        verticalLayout_5->addWidget(heapList);

        startHeapBtn = new QPushButton(groupBox_4);
        startHeapBtn->setObjectName("startHeapBtn");

        verticalLayout_5->addWidget(startHeapBtn);


        horizontalLayout->addWidget(groupBox_4);

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
        groupBox_5->setTitle(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\351\232\217\346\234\272\346\225\260", nullptr));
        startBtn->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\345\277\253\351\200\237\346\216\222\345\272\217", nullptr));
        startQuickBtn->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\345\206\222\346\263\241\346\216\222\345\272\217", nullptr));
        startBubbBtn->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\345\240\206\346\216\222\345\272\217", nullptr));
        startHeapBtn->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

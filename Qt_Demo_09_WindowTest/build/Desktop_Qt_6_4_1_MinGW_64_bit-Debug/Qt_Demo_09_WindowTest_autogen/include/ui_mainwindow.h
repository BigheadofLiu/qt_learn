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
#include <QtWidgets/QLabel>
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
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *showDia;
    QPushButton *showmsgBtn;
    QPushButton *pushButton_5;
    QLabel *myLabel;
    QPushButton *setFontBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(310, 160, 92, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(310, 200, 101, 28));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(270, 250, 191, 28));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(270, 290, 191, 28));
        showDia = new QPushButton(centralwidget);
        showDia->setObjectName("showDia");
        showDia->setGeometry(QRect(310, 330, 92, 28));
        showmsgBtn = new QPushButton(centralwidget);
        showmsgBtn->setObjectName("showmsgBtn");
        showmsgBtn->setGeometry(QRect(290, 370, 141, 28));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(310, 410, 92, 28));
        myLabel = new QLabel(centralwidget);
        myLabel->setObjectName("myLabel");
        myLabel->setGeometry(QRect(540, 310, 171, 131));
        setFontBtn = new QPushButton(centralwidget);
        setFontBtn->setObjectName("setFontBtn");
        setFontBtn->setGeometry(QRect(310, 460, 92, 28));
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
        pushButton->setText(QCoreApplication::translate("MainWindow", "\347\247\273\345\212\250\347\252\227\345\217\243", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\350\216\267\345\217\226\347\252\227\345\217\243\344\275\215\347\275\256", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\347\252\227\345\217\243\347\232\204\344\275\215\347\275\256\345\222\214\345\260\272\345\257\270\344\277\241\346\201\257", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\347\252\227\345\217\243\345\233\276\346\240\207\345\222\214\346\240\207\351\242\230", nullptr));
        showDia->setText(QCoreApplication::translate("MainWindow", "showDialog", nullptr));
        showmsgBtn->setText(QCoreApplication::translate("MainWindow", "showMessageBox", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "fileDialog", nullptr));
        myLabel->setText(QCoreApplication::translate("MainWindow", "\344\270\200giao\346\210\221\351\207\214giao", nullptr));
        setFontBtn->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\345\255\227\344\275\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_8;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 80, 181, 181));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName("radioButton");

        verticalLayout->addWidget(radioButton);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName("radioButton_3");

        verticalLayout->addWidget(radioButton_3);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName("radioButton_2");

        verticalLayout->addWidget(radioButton_2);

        radioButton_8 = new QRadioButton(groupBox);
        radioButton_8->setObjectName("radioButton_8");

        verticalLayout->addWidget(radioButton_8);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(290, 80, 181, 181));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName("radioButton_4");

        verticalLayout_2->addWidget(radioButton_4);

        radioButton_5 = new QRadioButton(groupBox_2);
        radioButton_5->setObjectName("radioButton_5");

        verticalLayout_2->addWidget(radioButton_5);

        radioButton_6 = new QRadioButton(groupBox_2);
        radioButton_6->setObjectName("radioButton_6");

        verticalLayout_2->addWidget(radioButton_6);

        radioButton_7 = new QRadioButton(groupBox_2);
        radioButton_7->setObjectName("radioButton_7");

        verticalLayout_2->addWidget(radioButton_7);

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
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\344\275\240\345\226\234\346\254\242\347\232\204\347\274\226\347\250\213\350\257\255\350\250\200\357\274\237", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "C++", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "JAVA", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "GO", nullptr));
        radioButton_8->setText(QCoreApplication::translate("MainWindow", "Python", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\344\275\240\347\246\273\350\201\214\347\232\204\345\216\237\345\233\240\357\274\237", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "996", nullptr));
        radioButton_5->setText(QCoreApplication::translate("MainWindow", "pua", nullptr));
        radioButton_6->setText(QCoreApplication::translate("MainWindow", "3.25", nullptr));
        radioButton_7->setText(QCoreApplication::translate("MainWindow", "\345\267\245\350\265\204\344\275\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox_10;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_11;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 30, 181, 181));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName("checkBox_4");

        verticalLayout_2->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName("checkBox_5");

        verticalLayout_2->addWidget(checkBox_5);

        checkBox_6 = new QCheckBox(groupBox_2);
        checkBox_6->setObjectName("checkBox_6");

        verticalLayout_2->addWidget(checkBox_6);

        checkBox_7 = new QCheckBox(groupBox_2);
        checkBox_7->setObjectName("checkBox_7");

        verticalLayout_2->addWidget(checkBox_7);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 260, 191, 298));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        checkBox_10 = new QCheckBox(groupBox);
        checkBox_10->setObjectName("checkBox_10");

        verticalLayout_3->addWidget(checkBox_10);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName("groupBox_3");
        QFont font;
        font.setBold(false);
        font.setUnderline(false);
        groupBox_3->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(30, -1, -1, -1);
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName("checkBox");

        verticalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName("checkBox_2");

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName("checkBox_3");

        verticalLayout->addWidget(checkBox_3);

        checkBox_8 = new QCheckBox(groupBox_3);
        checkBox_8->setObjectName("checkBox_8");

        verticalLayout->addWidget(checkBox_8);

        checkBox_9 = new QCheckBox(groupBox_3);
        checkBox_9->setObjectName("checkBox_9");

        verticalLayout->addWidget(checkBox_9);

        checkBox_11 = new QCheckBox(groupBox_3);
        checkBox_11->setObjectName("checkBox_11");

        verticalLayout->addWidget(checkBox_11);


        verticalLayout_3->addWidget(groupBox_3);

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
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\344\275\240\347\246\273\350\201\214\347\232\204\345\216\237\345\233\240\357\274\237", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "996", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "pua", nullptr));
        checkBox_6->setText(QCoreApplication::translate("MainWindow", "3.25", nullptr));
        checkBox_7->setText(QCoreApplication::translate("MainWindow", "\345\267\245\350\265\204\344\275\216", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\344\275\240\345\226\234\346\254\242\347\232\204\347\276\216\351\243\237\357\274\210\345\244\232\351\200\211\357\274\211", nullptr));
        checkBox_10->setText(QCoreApplication::translate("MainWindow", "\347\276\216\351\243\237", nullptr));
        groupBox_3->setTitle(QString());
        checkBox->setText(QCoreApplication::translate("MainWindow", "\350\236\272\350\233\263\347\262\211", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "\347\203\251\351\235\242", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "\347\203\255\345\271\262\351\235\242", nullptr));
        checkBox_8->setText(QCoreApplication::translate("MainWindow", "\350\202\211\345\244\271\351\246\215", nullptr));
        checkBox_9->setText(QCoreApplication::translate("MainWindow", "\347\214\252\350\204\232\351\245\255", nullptr));
        checkBox_11->setText(QCoreApplication::translate("MainWindow", "\347\203\244\351\270\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

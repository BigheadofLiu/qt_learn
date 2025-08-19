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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *save_action;
    QAction *delete_action;
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
    QPushButton *pushButton_6;
    QLabel *colorLabel;
    QPushButton *pushButton_7;
    QPushButton *showQProDiaBtn;
    QMenuBar *menubar;
    QMenu *menuSave;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        save_action = new QAction(MainWindow);
        save_action->setObjectName("save_action");
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/ZYB/Pictures/icon/\344\277\235\345\255\230.png"), QSize(), QIcon::Normal, QIcon::Off);
        save_action->setIcon(icon);
        save_action->setMenuRole(QAction::MenuRole::NoRole);
        delete_action = new QAction(MainWindow);
        delete_action->setObjectName("delete_action");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("C:/Users/ZYB/Pictures/icon/\345\210\240\351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        delete_action->setIcon(icon1);
        delete_action->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(180, 50, 92, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(180, 90, 101, 28));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(180, 140, 191, 28));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(180, 180, 191, 28));
        showDia = new QPushButton(centralwidget);
        showDia->setObjectName("showDia");
        showDia->setGeometry(QRect(180, 220, 92, 28));
        showmsgBtn = new QPushButton(centralwidget);
        showmsgBtn->setObjectName("showmsgBtn");
        showmsgBtn->setGeometry(QRect(180, 260, 141, 28));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(180, 300, 92, 28));
        myLabel = new QLabel(centralwidget);
        myLabel->setObjectName("myLabel");
        myLabel->setGeometry(QRect(440, 50, 171, 131));
        setFontBtn = new QPushButton(centralwidget);
        setFontBtn->setObjectName("setFontBtn");
        setFontBtn->setGeometry(QRect(180, 340, 92, 28));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(180, 380, 92, 28));
        colorLabel = new QLabel(centralwidget);
        colorLabel->setObjectName("colorLabel");
        colorLabel->setGeometry(QRect(440, 160, 221, 71));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(180, 420, 111, 28));
        showQProDiaBtn = new QPushButton(centralwidget);
        showQProDiaBtn->setObjectName("showQProDiaBtn");
        showQProDiaBtn->setGeometry(QRect(180, 460, 171, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuSave = new QMenu(menubar);
        menuSave->setObjectName("menuSave");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSave->menuAction());
        menuSave->addAction(save_action);
        menuSave->addAction(delete_action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        save_action->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        save_action->setToolTip(QCoreApplication::translate("MainWindow", "\347\202\271\345\207\273\345\215\263\345\217\257\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        delete_action->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
#if QT_CONFIG(tooltip)
        delete_action->setToolTip(QCoreApplication::translate("MainWindow", "\347\202\271\345\207\273\345\215\263\345\217\257\345\210\240\351\231\244\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QCoreApplication::translate("MainWindow", "\347\247\273\345\212\250\347\252\227\345\217\243", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\350\216\267\345\217\226\347\252\227\345\217\243\344\275\215\347\275\256", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\347\252\227\345\217\243\347\232\204\344\275\215\347\275\256\345\222\214\345\260\272\345\257\270\344\277\241\346\201\257", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\347\252\227\345\217\243\345\233\276\346\240\207\345\222\214\346\240\207\351\242\230", nullptr));
        showDia->setText(QCoreApplication::translate("MainWindow", "showDialog", nullptr));
        showmsgBtn->setText(QCoreApplication::translate("MainWindow", "showMessageBox", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "fileDialog", nullptr));
        myLabel->setText(QCoreApplication::translate("MainWindow", "\344\270\200giao\346\210\221\351\207\214giao", nullptr));
        setFontBtn->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\345\255\227\344\275\223", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\351\242\234\350\211\262", nullptr));
        colorLabel->setText(QString());
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "QInputDialog", nullptr));
        showQProDiaBtn->setText(QCoreApplication::translate("MainWindow", "showQProessDialog", nullptr));
        menuSave->setTitle(QCoreApplication::translate("MainWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

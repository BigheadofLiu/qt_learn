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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QPushButton *addBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabShape(QTabWidget::TabShape::Rounded);
        tabWidget->setElideMode(Qt::TextElideMode::ElideLeft);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        tabWidget->setTabBarAutoHide(false);
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/\345\203\217\347\264\240-\347\273\277\350\230\221\350\217\207.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_4, icon, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/\345\203\217\347\264\240-\351\273\204\351\271\246\351\271\211.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_5, icon1, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/\345\203\217\347\264\240-\345\226\234\346\254\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon2, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/\345\203\217\347\264\240-\347\201\253\350\213\227.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_2, icon3, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/\345\203\217\347\264\240-\347\272\242\350\230\221\350\217\207.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_3, icon4, QString());

        verticalLayout->addWidget(tabWidget);

        addBtn = new QPushButton(centralwidget);
        addBtn->setObjectName("addBtn");

        verticalLayout->addWidget(addBtn);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\345\224\261", nullptr));
#if QT_CONFIG(whatsthis)
        tabWidget->setTabWhatsThis(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\350\277\231\346\230\257\346\210\221\347\232\204\347\256\200\344\273\213", nullptr));
#endif // QT_CONFIG(whatsthis)
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\351\270\241\347\210\252", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\350\267\263", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Rap", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\347\257\256\347\220\203", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

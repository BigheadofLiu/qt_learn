/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_myDialog
{
public:
    QPushButton *acceptBtn;
    QPushButton *rejectBtn;
    QPushButton *doneBtn;

    void setupUi(QDialog *myDialog)
    {
        if (myDialog->objectName().isEmpty())
            myDialog->setObjectName("myDialog");
        myDialog->resize(400, 300);
        acceptBtn = new QPushButton(myDialog);
        acceptBtn->setObjectName("acceptBtn");
        acceptBtn->setGeometry(QRect(140, 80, 92, 28));
        rejectBtn = new QPushButton(myDialog);
        rejectBtn->setObjectName("rejectBtn");
        rejectBtn->setGeometry(QRect(140, 120, 92, 28));
        doneBtn = new QPushButton(myDialog);
        doneBtn->setObjectName("doneBtn");
        doneBtn->setGeometry(QRect(140, 160, 92, 28));

        retranslateUi(myDialog);

        QMetaObject::connectSlotsByName(myDialog);
    } // setupUi

    void retranslateUi(QDialog *myDialog)
    {
        myDialog->setWindowTitle(QCoreApplication::translate("myDialog", "Dialog", nullptr));
        acceptBtn->setText(QCoreApplication::translate("myDialog", "accetp", nullptr));
        rejectBtn->setText(QCoreApplication::translate("myDialog", "reject", nullptr));
        doneBtn->setText(QCoreApplication::translate("myDialog", "done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myDialog: public Ui_myDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H

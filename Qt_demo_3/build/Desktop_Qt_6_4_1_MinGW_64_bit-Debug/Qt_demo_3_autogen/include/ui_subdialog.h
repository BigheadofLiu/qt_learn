/********************************************************************************
** Form generated from reading UI file 'subdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBDIALOG_H
#define UI_SUBDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SubDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *SubDialog)
    {
        if (SubDialog->objectName().isEmpty())
            SubDialog->setObjectName("SubDialog");
        SubDialog->resize(400, 300);
        label = new QLabel(SubDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 130, 61, 31));

        retranslateUi(SubDialog);

        QMetaObject::connectSlotsByName(SubDialog);
    } // setupUi

    void retranslateUi(QDialog *SubDialog)
    {
        SubDialog->setWindowTitle(QCoreApplication::translate("SubDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SubDialog", "subdialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubDialog: public Ui_SubDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBDIALOG_H

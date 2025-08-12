/********************************************************************************
** Form generated from reading UI file 'testdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTDIALOG_H
#define UI_TESTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TestDialog
{
public:
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TestDialog)
    {
        if (TestDialog->objectName().isEmpty())
            TestDialog->setObjectName("TestDialog");
        TestDialog->resize(400, 300);
        pushButton = new QPushButton(TestDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(90, 150, 80, 18));
        checkBox = new QCheckBox(TestDialog);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(100, 90, 61, 18));
        buttonBox = new QDialogButtonBox(TestDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(180, 100, 164, 18));
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(TestDialog);

        QMetaObject::connectSlotsByName(TestDialog);
    } // setupUi

    void retranslateUi(QDialog *TestDialog)
    {
        TestDialog->setWindowTitle(QCoreApplication::translate("TestDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("TestDialog", "PushButton", nullptr));
        checkBox->setText(QCoreApplication::translate("TestDialog", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestDialog: public Ui_TestDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTDIALOG_H

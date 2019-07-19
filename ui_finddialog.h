/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FindDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_next;
    QPushButton *pushButton_prev;
    QPushButton *pushButton_close;

    void setupUi(QDialog *FindDialog)
    {
        if (FindDialog->objectName().isEmpty())
            FindDialog->setObjectName(QString::fromUtf8("FindDialog"));
        FindDialog->resize(393, 82);
        verticalLayout_2 = new QVBoxLayout(FindDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(FindDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_next = new QPushButton(FindDialog);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));

        horizontalLayout->addWidget(pushButton_next);

        pushButton_prev = new QPushButton(FindDialog);
        pushButton_prev->setObjectName(QString::fromUtf8("pushButton_prev"));

        horizontalLayout->addWidget(pushButton_prev);

        pushButton_close = new QPushButton(FindDialog);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));

        horizontalLayout->addWidget(pushButton_close);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(FindDialog);
        QObject::connect(pushButton_close, SIGNAL(clicked()), FindDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QDialog *FindDialog)
    {
        FindDialog->setWindowTitle(QCoreApplication::translate("FindDialog", "Dialog", nullptr));
        pushButton_next->setText(QCoreApplication::translate("FindDialog", "Find Next", nullptr));
        pushButton_prev->setText(QCoreApplication::translate("FindDialog", "Find Previous", nullptr));
        pushButton_close->setText(QCoreApplication::translate("FindDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H

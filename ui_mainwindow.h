/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout_QNotePad;
    QAction *actionselect_all_Ctrl_A;
    QAction *actionCut_Ctrl_X;
    QAction *actionCopy_Ctrl_C;
    QAction *actionPaste_Ctrl_V;
    QAction *actionUndo_Ctrl_Z;
    QAction *actionRedo_Shift_Ctrl_Z;
    QAction *actionNew_Ctrl_N;
    QAction *actionOpen_Shift_Ctrl_N;
    QAction *actionSave_Ctrl_S;
    QAction *actionSave_as_Shift_Ctrl_S;
    QAction *actionFind_Ctrl_F;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1120, 667);
        MainWindow->setFocusPolicy(Qt::NoFocus);
        actionAbout_QNotePad = new QAction(MainWindow);
        actionAbout_QNotePad->setObjectName(QString::fromUtf8("actionAbout_QNotePad"));
        actionselect_all_Ctrl_A = new QAction(MainWindow);
        actionselect_all_Ctrl_A->setObjectName(QString::fromUtf8("actionselect_all_Ctrl_A"));
        actionCut_Ctrl_X = new QAction(MainWindow);
        actionCut_Ctrl_X->setObjectName(QString::fromUtf8("actionCut_Ctrl_X"));
        actionCopy_Ctrl_C = new QAction(MainWindow);
        actionCopy_Ctrl_C->setObjectName(QString::fromUtf8("actionCopy_Ctrl_C"));
        actionPaste_Ctrl_V = new QAction(MainWindow);
        actionPaste_Ctrl_V->setObjectName(QString::fromUtf8("actionPaste_Ctrl_V"));
        actionUndo_Ctrl_Z = new QAction(MainWindow);
        actionUndo_Ctrl_Z->setObjectName(QString::fromUtf8("actionUndo_Ctrl_Z"));
        actionRedo_Shift_Ctrl_Z = new QAction(MainWindow);
        actionRedo_Shift_Ctrl_Z->setObjectName(QString::fromUtf8("actionRedo_Shift_Ctrl_Z"));
        actionNew_Ctrl_N = new QAction(MainWindow);
        actionNew_Ctrl_N->setObjectName(QString::fromUtf8("actionNew_Ctrl_N"));
        actionOpen_Shift_Ctrl_N = new QAction(MainWindow);
        actionOpen_Shift_Ctrl_N->setObjectName(QString::fromUtf8("actionOpen_Shift_Ctrl_N"));
        actionSave_Ctrl_S = new QAction(MainWindow);
        actionSave_Ctrl_S->setObjectName(QString::fromUtf8("actionSave_Ctrl_S"));
        actionSave_as_Shift_Ctrl_S = new QAction(MainWindow);
        actionSave_as_Shift_Ctrl_S->setObjectName(QString::fromUtf8("actionSave_as_Shift_Ctrl_S"));
        actionFind_Ctrl_F = new QAction(MainWindow);
        actionFind_Ctrl_F->setObjectName(QString::fromUtf8("actionFind_Ctrl_F"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1120, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew_Ctrl_N);
        menuFile->addAction(actionOpen_Shift_Ctrl_N);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_Ctrl_S);
        menuFile->addAction(actionSave_as_Shift_Ctrl_S);
        menuEdit->addAction(actionselect_all_Ctrl_A);
        menuEdit->addAction(actionCut_Ctrl_X);
        menuEdit->addAction(actionCopy_Ctrl_C);
        menuEdit->addAction(actionPaste_Ctrl_V);
        menuEdit->addAction(actionFind_Ctrl_F);
        menuEdit->addSeparator();
        menuEdit->addAction(actionUndo_Ctrl_Z);
        menuEdit->addAction(actionRedo_Shift_Ctrl_Z);
        menuAbout->addAction(actionAbout_QNotePad);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbout_QNotePad->setText(QCoreApplication::translate("MainWindow", "About QNotePad", nullptr));
        actionselect_all_Ctrl_A->setText(QCoreApplication::translate("MainWindow", "select all (Ctrl + A)", nullptr));
#if QT_CONFIG(shortcut)
        actionselect_all_Ctrl_A->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut_Ctrl_X->setText(QCoreApplication::translate("MainWindow", "Cut (Ctrl + X)", nullptr));
#if QT_CONFIG(shortcut)
        actionCut_Ctrl_X->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy_Ctrl_C->setText(QCoreApplication::translate("MainWindow", "Copy (Ctrl + C)", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy_Ctrl_C->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste_Ctrl_V->setText(QCoreApplication::translate("MainWindow", "Paste (Ctrl + V)", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste_Ctrl_V->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUndo_Ctrl_Z->setText(QCoreApplication::translate("MainWindow", "Undo (Ctrl + Z)", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo_Ctrl_Z->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRedo_Shift_Ctrl_Z->setText(QCoreApplication::translate("MainWindow", "Redo (Shift + Ctrl + Z)", nullptr));
#if QT_CONFIG(shortcut)
        actionRedo_Shift_Ctrl_Z->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew_Ctrl_N->setText(QCoreApplication::translate("MainWindow", "New (Ctrl + N)", nullptr));
#if QT_CONFIG(shortcut)
        actionNew_Ctrl_N->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen_Shift_Ctrl_N->setText(QCoreApplication::translate("MainWindow", "Open (Shift + Ctrl +N)", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen_Shift_Ctrl_N->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_Ctrl_S->setText(QCoreApplication::translate("MainWindow", "Save (Ctrl + S)", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_Ctrl_S->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_as_Shift_Ctrl_S->setText(QCoreApplication::translate("MainWindow", "Save as...(Shift + Ctrl + S)", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_as_Shift_Ctrl_S->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFind_Ctrl_F->setText(QCoreApplication::translate("MainWindow", "Find (Ctrl + F)", nullptr));
#if QT_CONFIG(shortcut)
        actionFind_Ctrl_F->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        label->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'signalprocesswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNALPROCESSWINDOW_H
#define UI_SIGNALPROCESSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignalProcessWindow
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SignalProcessWindow)
    {
        if (SignalProcessWindow->objectName().isEmpty())
            SignalProcessWindow->setObjectName(QStringLiteral("SignalProcessWindow"));
        SignalProcessWindow->resize(1116, 708);
        actionOpen = new QAction(SignalProcessWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        centralwidget = new QWidget(SignalProcessWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        SignalProcessWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SignalProcessWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1116, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        SignalProcessWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SignalProcessWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SignalProcessWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);

        retranslateUi(SignalProcessWindow);

        QMetaObject::connectSlotsByName(SignalProcessWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SignalProcessWindow)
    {
        SignalProcessWindow->setWindowTitle(QApplication::translate("SignalProcessWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("SignalProcessWindow", "\346\211\223\345\274\200", 0));
        menuFile->setTitle(QApplication::translate("SignalProcessWindow", "\346\226\207\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class SignalProcessWindow: public Ui_SignalProcessWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNALPROCESSWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'rbf.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RBF_H
#define UI_RBF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RBF
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RBF)
    {
        if (RBF->objectName().isEmpty())
            RBF->setObjectName(QStringLiteral("RBF"));
        RBF->resize(792, 803);
        centralwidget = new QWidget(RBF);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        RBF->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RBF);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 792, 23));
        RBF->setMenuBar(menubar);
        statusbar = new QStatusBar(RBF);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        RBF->setStatusBar(statusbar);

        retranslateUi(RBF);

        QMetaObject::connectSlotsByName(RBF);
    } // setupUi

    void retranslateUi(QMainWindow *RBF)
    {
        RBF->setWindowTitle(QApplication::translate("RBF", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class RBF: public Ui_RBF {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RBF_H

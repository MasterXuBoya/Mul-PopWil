/********************************************************************************
** Form generated from reading UI file 'testwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWINDOW_H
#define UI_TESTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *mainLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QGridLayout *gridLayout_2;
    QListView *listView;
    QTreeView *treeView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestWindow)
    {
        if (TestWindow->objectName().isEmpty())
            TestWindow->setObjectName(QStringLiteral("TestWindow"));
        TestWindow->resize(800, 600);
        centralwidget = new QWidget(TestWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 521, 291));
        mainLayout = new QHBoxLayout(layoutWidget);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        mainLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 2, 0, 1, 1);

        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        gridLayout->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_3 = new QRadioButton(layoutWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        gridLayout->addWidget(radioButton_3, 3, 0, 1, 1);

        radioButton_4 = new QRadioButton(layoutWidget);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        gridLayout->addWidget(radioButton_4, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        listView = new QListView(layoutWidget);
        listView->setObjectName(QStringLiteral("listView"));

        gridLayout_2->addWidget(listView, 0, 1, 1, 1);

        treeView = new QTreeView(layoutWidget);
        treeView->setObjectName(QStringLiteral("treeView"));

        gridLayout_2->addWidget(treeView, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);

        mainLayout->addLayout(verticalLayout_2);

        mainLayout->setStretch(0, 1);
        mainLayout->setStretch(1, 1);
        TestWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        TestWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TestWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestWindow->setStatusBar(statusbar);

        retranslateUi(TestWindow);

        QMetaObject::connectSlotsByName(TestWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TestWindow)
    {
        TestWindow->setWindowTitle(QApplication::translate("TestWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("TestWindow", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("TestWindow", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("TestWindow", "PushButton", 0));
        radioButton_2->setText(QApplication::translate("TestWindow", "RadioButton", 0));
        radioButton->setText(QApplication::translate("TestWindow", "RadioButton", 0));
        radioButton_3->setText(QApplication::translate("TestWindow", "RadioButton", 0));
        radioButton_4->setText(QApplication::translate("TestWindow", "RadioButton", 0));
    } // retranslateUi

};

namespace Ui {
    class TestWindow: public Ui_TestWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWINDOW_H

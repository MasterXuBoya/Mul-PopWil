/********************************************************************************
** Form generated from reading UI file 'sinesweepmodule.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINESWEEPMODULE_H
#define UI_SINESWEEPMODULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SineSweepModule
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *Edit_end;
    QLineEdit *Edit_start;
    QLabel *label_2;
    QLineEdit *Edit_sweepTime;
    QLabel *label;
    QLabel *label_3;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLineEdit *Edit_sample;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QLineEdit *Edit_peak;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QRadioButton *radio_linear;
    QRadioButton *radio_log;
    QPushButton *btn_close;
    QPushButton *btn_clear;
    QPushButton *btn_generate;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SineSweepModule)
    {
        if (SineSweepModule->objectName().isEmpty())
            SineSweepModule->setObjectName(QStringLiteral("SineSweepModule"));
        SineSweepModule->resize(455, 493);
        actionOpen = new QAction(SineSweepModule);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(SineSweepModule);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralwidget = new QWidget(SineSweepModule);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 411, 221));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 321, 81));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        Edit_end = new QLineEdit(layoutWidget);
        Edit_end->setObjectName(QStringLiteral("Edit_end"));

        gridLayout->addWidget(Edit_end, 1, 2, 1, 1);

        Edit_start = new QLineEdit(layoutWidget);
        Edit_start->setObjectName(QStringLiteral("Edit_start"));

        gridLayout->addWidget(Edit_start, 0, 2, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        Edit_sweepTime = new QLineEdit(layoutWidget);
        Edit_sweepTime->setObjectName(QStringLiteral("Edit_sweepTime"));

        gridLayout->addWidget(Edit_sweepTime, 2, 2, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        gridLayout->setColumnStretch(0, 4);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 3);
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 150, 321, 51));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        Edit_sample = new QLineEdit(layoutWidget1);
        Edit_sample->setObjectName(QStringLiteral("Edit_sample"));

        gridLayout_2->addWidget(Edit_sample, 1, 2, 1, 1);

        checkBox_2 = new QCheckBox(layoutWidget1);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout_2->addWidget(checkBox_2, 0, 0, 1, 1);

        checkBox = new QCheckBox(layoutWidget1);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout_2->addWidget(checkBox, 1, 0, 1, 1);

        Edit_peak = new QLineEdit(layoutWidget1);
        Edit_peak->setObjectName(QStringLiteral("Edit_peak"));

        gridLayout_2->addWidget(Edit_peak, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 240, 411, 91));
        radio_linear = new QRadioButton(groupBox_2);
        radio_linear->setObjectName(QStringLiteral("radio_linear"));
        radio_linear->setGeometry(QRect(40, 40, 81, 21));
        radio_log = new QRadioButton(groupBox_2);
        radio_log->setObjectName(QStringLiteral("radio_log"));
        radio_log->setGeometry(QRect(220, 40, 91, 21));
        btn_close = new QPushButton(centralwidget);
        btn_close->setObjectName(QStringLiteral("btn_close"));
        btn_close->setGeometry(QRect(40, 370, 61, 41));
        btn_clear = new QPushButton(centralwidget);
        btn_clear->setObjectName(QStringLiteral("btn_clear"));
        btn_clear->setGeometry(QRect(210, 370, 81, 41));
        btn_generate = new QPushButton(centralwidget);
        btn_generate->setObjectName(QStringLiteral("btn_generate"));
        btn_generate->setGeometry(QRect(320, 370, 91, 41));
        SineSweepModule->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SineSweepModule);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 455, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        SineSweepModule->setMenuBar(menubar);
        statusbar = new QStatusBar(SineSweepModule);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SineSweepModule->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);

        retranslateUi(SineSweepModule);

        QMetaObject::connectSlotsByName(SineSweepModule);
    } // setupUi

    void retranslateUi(QMainWindow *SineSweepModule)
    {
        SineSweepModule->setWindowTitle(QApplication::translate("SineSweepModule", "\346\211\253\351\242\221\345\217\221\347\224\237\345\231\250", 0));
        actionOpen->setText(QApplication::translate("SineSweepModule", "\346\211\223\345\274\200", 0));
        actionSave->setText(QApplication::translate("SineSweepModule", "\344\277\235\345\255\230", 0));
        groupBox->setTitle(QApplication::translate("SineSweepModule", "\345\237\272\346\234\254\350\256\276\347\275\256", 0));
        label_2->setText(QApplication::translate("SineSweepModule", "\347\273\223\346\235\237\351\242\221\347\216\207 [Hz]", 0));
        label->setText(QApplication::translate("SineSweepModule", "\345\274\200\345\247\213\351\242\221\347\216\207 [Hz]", 0));
        label_3->setText(QApplication::translate("SineSweepModule", "\346\211\253\351\242\221\346\227\266\351\227\264 [s]", 0));
        Edit_sample->setText(QApplication::translate("SineSweepModule", "100", 0));
        checkBox_2->setText(QApplication::translate("SineSweepModule", "\350\246\206\347\233\226\351\273\230\350\256\244\345\271\205\345\200\274", 0));
        checkBox->setText(QApplication::translate("SineSweepModule", "\350\246\206\347\233\226\351\273\230\350\256\244\351\207\207\346\240\267\351\242\221\347\216\207 [Hz]", 0));
        Edit_peak->setText(QApplication::translate("SineSweepModule", "1", 0));
        groupBox_2->setTitle(QApplication::translate("SineSweepModule", "\346\211\253\351\242\221\346\226\271\345\274\217", 0));
        radio_linear->setText(QApplication::translate("SineSweepModule", "\347\272\277\346\200\247\346\211\253\351\242\221", 0));
        radio_log->setText(QApplication::translate("SineSweepModule", "\345\257\271\346\225\260\346\211\253\351\242\221", 0));
        btn_close->setText(QApplication::translate("SineSweepModule", "\345\205\263\351\227\255", 0));
        btn_clear->setText(QApplication::translate("SineSweepModule", "\345\205\250\351\203\250\346\270\205\347\251\272", 0));
        btn_generate->setText(QApplication::translate("SineSweepModule", "\347\224\237\346\210\220\346\211\253\351\242\221\344\277\241\345\217\267", 0));
        menuFile->setTitle(QApplication::translate("SineSweepModule", "\346\226\207\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class SineSweepModule: public Ui_SineSweepModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINESWEEPMODULE_H

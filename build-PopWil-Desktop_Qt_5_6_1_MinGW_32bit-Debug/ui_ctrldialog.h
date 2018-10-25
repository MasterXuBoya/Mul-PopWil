/********************************************************************************
** Form generated from reading UI file 'ctrldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTRLDIALOG_H
#define UI_CTRLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CtrlDialog
{
public:
    QLabel *label_4;
    QComboBox *cmbCtrlMode;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_P;
    QLineEdit *lineEdit_D;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit_I;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tab_2;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLineEdit *le_sine_P;
    QLineEdit *le_sine_D;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *le_sine_I;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btnOk;
    QPushButton *btnQuit;

    void setupUi(QDialog *CtrlDialog)
    {
        if (CtrlDialog->objectName().isEmpty())
            CtrlDialog->setObjectName(QStringLiteral("CtrlDialog"));
        CtrlDialog->resize(502, 401);
        label_4 = new QLabel(CtrlDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 20, 91, 21));
        cmbCtrlMode = new QComboBox(CtrlDialog);
        cmbCtrlMode->setObjectName(QStringLiteral("cmbCtrlMode"));
        cmbCtrlMode->setGeometry(QRect(140, 20, 221, 21));
        tabWidget = new QTabWidget(CtrlDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 70, 431, 261));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 40, 211, 151));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_P = new QLineEdit(layoutWidget);
        lineEdit_P->setObjectName(QStringLiteral("lineEdit_P"));

        gridLayout->addWidget(lineEdit_P, 0, 2, 1, 1);

        lineEdit_D = new QLineEdit(layoutWidget);
        lineEdit_D->setObjectName(QStringLiteral("lineEdit_D"));

        gridLayout->addWidget(lineEdit_D, 2, 2, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_I = new QLineEdit(layoutWidget);
        lineEdit_I->setObjectName(QStringLiteral("lineEdit_I"));

        gridLayout->addWidget(lineEdit_I, 1, 2, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(100, 40, 211, 151));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        le_sine_P = new QLineEdit(layoutWidget1);
        le_sine_P->setObjectName(QStringLiteral("le_sine_P"));

        gridLayout_2->addWidget(le_sine_P, 0, 2, 1, 1);

        le_sine_D = new QLineEdit(layoutWidget1);
        le_sine_D->setObjectName(QStringLiteral("le_sine_D"));

        gridLayout_2->addWidget(le_sine_D, 2, 2, 1, 1);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        le_sine_I = new QLineEdit(layoutWidget1);
        le_sine_I->setObjectName(QStringLiteral("le_sine_I"));

        gridLayout_2->addWidget(le_sine_I, 1, 2, 1, 1);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 2, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        btnOk = new QPushButton(CtrlDialog);
        btnOk->setObjectName(QStringLiteral("btnOk"));
        btnOk->setGeometry(QRect(70, 350, 75, 23));
        btnQuit = new QPushButton(CtrlDialog);
        btnQuit->setObjectName(QStringLiteral("btnQuit"));
        btnQuit->setGeometry(QRect(280, 350, 75, 23));

        retranslateUi(CtrlDialog);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CtrlDialog);
    } // setupUi

    void retranslateUi(QDialog *CtrlDialog)
    {
        CtrlDialog->setWindowTitle(QApplication::translate("CtrlDialog", "Dialog", 0));
        label_4->setText(QApplication::translate("CtrlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\346\216\247\345\210\266\346\226\271\345\274\217\357\274\232</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("CtrlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">D:</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("CtrlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">I:</span></p></body></html>", 0));
        label->setText(QApplication::translate("CtrlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">P:</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CtrlDialog", "Tab 1", 0));
        label_5->setText(QApplication::translate("CtrlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">D:</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("CtrlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">I:</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("CtrlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">P:</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("CtrlDialog", "Tab 2", 0));
        btnOk->setText(QApplication::translate("CtrlDialog", "\347\241\256\345\256\232", 0));
        btnQuit->setText(QApplication::translate("CtrlDialog", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class CtrlDialog: public Ui_CtrlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTRLDIALOG_H

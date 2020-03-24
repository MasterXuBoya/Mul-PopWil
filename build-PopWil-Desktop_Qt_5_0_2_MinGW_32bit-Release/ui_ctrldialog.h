/********************************************************************************
** Form generated from reading UI file 'ctrldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
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
#include <QtWidgets/QHBoxLayout>
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
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QLineEdit *lineEdit_P;
    QLineEdit *lineEdit_I;
    QLineEdit *lineEdit_D;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_5;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QLineEdit *le_sine_P;
    QLineEdit *le_sine_I;
    QLineEdit *le_sine_D;
    QWidget *tab_2;
    QLabel *label_3;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *le_fs;
    QLineEdit *le_fv;
    QLineEdit *le_fa;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLineEdit *le_bs;
    QLineEdit *le_bv;
    QLineEdit *le_ba;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *tab_3;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_16;
    QLineEdit *le_pid3_vp;
    QLineEdit *le_pid3_vi;
    QLineEdit *le_pid3_vd;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_15;
    QLineEdit *le_pid3_ap;
    QLineEdit *le_pid3_ai;
    QLineEdit *le_pid3_ad;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QLineEdit *le_pid3_sp;
    QLineEdit *le_pid3_si;
    QLineEdit *le_pid3_sd;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_17;
    QLabel *label_12;
    QLabel *label_18;
    QLabel *label_4;
    QComboBox *cmbCtrlMode;
    QPushButton *btnOk;
    QPushButton *btnQuit;

    void setupUi(QDialog *CtrlDialog)
    {
        if (CtrlDialog->objectName().isEmpty())
            CtrlDialog->setObjectName(QStringLiteral("CtrlDialog"));
        CtrlDialog->resize(583, 490);
        tabWidget = new QTabWidget(CtrlDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(15, 80, 1351, 331));
        tabWidget->setStyleSheet(QLatin1String("QTabBar::tab{background:transparent;font:bold;color:#000000;min-width:30ex;min-height:10ex;}\n"
"QTabBar::tab:hover{background:#CCFFFF;}\n"
"QTabBar::tab:selected{background:#99CCFF;border-color: green;}"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 96, 491, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setStyleSheet(QStringLiteral("font: 75 12pt \"Agency FB\";"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_11);

        lineEdit_P = new QLineEdit(layoutWidget);
        lineEdit_P->setObjectName(QStringLiteral("lineEdit_P"));

        horizontalLayout->addWidget(lineEdit_P);

        lineEdit_I = new QLineEdit(layoutWidget);
        lineEdit_I->setObjectName(QStringLiteral("lineEdit_I"));

        horizontalLayout->addWidget(lineEdit_I);

        lineEdit_D = new QLineEdit(layoutWidget);
        lineEdit_D->setObjectName(QStringLiteral("lineEdit_D"));

        horizontalLayout->addWidget(lineEdit_D);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 11, 491, 61));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font;
        font.setPointSize(11);
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_7);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_6);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_5);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);
        horizontalLayout_5->setStretch(3, 1);
        layoutWidget2 = new QWidget(tab);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(11, 181, 491, 71));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QStringLiteral("font: 75 12pt \"Agency FB\";"));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_10);

        le_sine_P = new QLineEdit(layoutWidget2);
        le_sine_P->setObjectName(QStringLiteral("le_sine_P"));

        horizontalLayout_4->addWidget(le_sine_P);

        le_sine_I = new QLineEdit(layoutWidget2);
        le_sine_I->setObjectName(QStringLiteral("le_sine_I"));

        horizontalLayout_4->addWidget(le_sine_I);

        le_sine_D = new QLineEdit(layoutWidget2);
        le_sine_D->setObjectName(QStringLiteral("le_sine_D"));

        horizontalLayout_4->addWidget(le_sine_D);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 1);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 50, 71, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\351\232\266\344\271\246\";"));
        label_3->setAlignment(Qt::AlignCenter);
        layoutWidget3 = new QWidget(tab_2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(30, 100, 481, 51));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("font: 75 12pt \"Agency FB\";"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label);

        le_fs = new QLineEdit(layoutWidget3);
        le_fs->setObjectName(QStringLiteral("le_fs"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(le_fs->sizePolicy().hasHeightForWidth());
        le_fs->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(le_fs);

        le_fv = new QLineEdit(layoutWidget3);
        le_fv->setObjectName(QStringLiteral("le_fv"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(le_fv->sizePolicy().hasHeightForWidth());
        le_fv->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(le_fv);

        le_fa = new QLineEdit(layoutWidget3);
        le_fa->setObjectName(QStringLiteral("le_fa"));
        sizePolicy1.setHeightForWidth(le_fa->sizePolicy().hasHeightForWidth());
        le_fa->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(le_fa);

        layoutWidget4 = new QWidget(tab_2);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(30, 190, 481, 51));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QStringLiteral("font: 75 12pt \"Agency FB\";"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_9);

        le_bs = new QLineEdit(layoutWidget4);
        le_bs->setObjectName(QStringLiteral("le_bs"));
        sizePolicy1.setHeightForWidth(le_bs->sizePolicy().hasHeightForWidth());
        le_bs->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(le_bs);

        le_bv = new QLineEdit(layoutWidget4);
        le_bv->setObjectName(QStringLiteral("le_bv"));
        sizePolicy1.setHeightForWidth(le_bv->sizePolicy().hasHeightForWidth());
        le_bv->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(le_bv);

        le_ba = new QLineEdit(layoutWidget4);
        le_ba->setObjectName(QStringLiteral("le_ba"));
        sizePolicy1.setHeightForWidth(le_ba->sizePolicy().hasHeightForWidth());
        le_ba->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(le_ba);

        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(270, 50, 71, 31));
        label_13->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\351\232\266\344\271\246\";"));
        label_13->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(400, 50, 71, 31));
        label_14->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\351\232\266\344\271\246\";"));
        label_14->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        layoutWidget5 = new QWidget(tab_3);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(41, 149, 427, 22));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\351\232\266\344\271\246\";"));
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_16);

        le_pid3_vp = new QLineEdit(layoutWidget5);
        le_pid3_vp->setObjectName(QStringLiteral("le_pid3_vp"));

        horizontalLayout_8->addWidget(le_pid3_vp);

        le_pid3_vi = new QLineEdit(layoutWidget5);
        le_pid3_vi->setObjectName(QStringLiteral("le_pid3_vi"));

        horizontalLayout_8->addWidget(le_pid3_vi);

        le_pid3_vd = new QLineEdit(layoutWidget5);
        le_pid3_vd->setObjectName(QStringLiteral("le_pid3_vd"));

        horizontalLayout_8->addWidget(le_pid3_vd);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 1);
        horizontalLayout_8->setStretch(2, 1);
        horizontalLayout_8->setStretch(3, 1);
        layoutWidget6 = new QWidget(tab_3);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(41, 217, 427, 22));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(layoutWidget6);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\351\232\266\344\271\246\";"));
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_15);

        le_pid3_ap = new QLineEdit(layoutWidget6);
        le_pid3_ap->setObjectName(QStringLiteral("le_pid3_ap"));

        horizontalLayout_9->addWidget(le_pid3_ap);

        le_pid3_ai = new QLineEdit(layoutWidget6);
        le_pid3_ai->setObjectName(QStringLiteral("le_pid3_ai"));

        horizontalLayout_9->addWidget(le_pid3_ai);

        le_pid3_ad = new QLineEdit(layoutWidget6);
        le_pid3_ad->setObjectName(QStringLiteral("le_pid3_ad"));

        horizontalLayout_9->addWidget(le_pid3_ad);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 1);
        horizontalLayout_9->setStretch(2, 1);
        horizontalLayout_9->setStretch(3, 1);
        layoutWidget7 = new QWidget(tab_3);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(41, 80, 427, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget7);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\351\232\266\344\271\246\";"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_8);

        le_pid3_sp = new QLineEdit(layoutWidget7);
        le_pid3_sp->setObjectName(QStringLiteral("le_pid3_sp"));

        horizontalLayout_3->addWidget(le_pid3_sp);

        le_pid3_si = new QLineEdit(layoutWidget7);
        le_pid3_si->setObjectName(QStringLiteral("le_pid3_si"));

        horizontalLayout_3->addWidget(le_pid3_si);

        le_pid3_sd = new QLineEdit(layoutWidget7);
        le_pid3_sd->setObjectName(QStringLiteral("le_pid3_sd"));

        horizontalLayout_3->addWidget(le_pid3_sd);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 1);
        layoutWidget8 = new QWidget(tab_3);
        layoutWidget8->setObjectName(QStringLiteral("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(42, 12, 421, 41));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);

        label_17 = new QLabel(layoutWidget8);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font);
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_17);

        label_12 = new QLabel(layoutWidget8);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_12);

        label_18 = new QLabel(layoutWidget8);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_18);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 1);
        horizontalLayout_10->setStretch(2, 1);
        horizontalLayout_10->setStretch(3, 1);
        tabWidget->addTab(tab_3, QString());
        label_4 = new QLabel(CtrlDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(21, 21, 85, 18));
        cmbCtrlMode = new QComboBox(CtrlDialog);
        cmbCtrlMode->setObjectName(QStringLiteral("cmbCtrlMode"));
        cmbCtrlMode->setGeometry(QRect(250, 20, 221, 21));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cmbCtrlMode->sizePolicy().hasHeightForWidth());
        cmbCtrlMode->setSizePolicy(sizePolicy2);
        cmbCtrlMode->setAutoFillBackground(false);
        cmbCtrlMode->setStyleSheet(QLatin1String("border:3px;\n"
"background-color: rgb(240, 254, 255);"));
        cmbCtrlMode->setIconSize(QSize(16, 20));
        cmbCtrlMode->setFrame(true);
        btnOk = new QPushButton(CtrlDialog);
        btnOk->setObjectName(QStringLiteral("btnOk"));
        btnOk->setGeometry(QRect(51, 442, 81, 31));
        btnOk->setStyleSheet(QLatin1String("QPushButton{\n"
"    background-color:rgb(230, 240, 250);\n"
"    border-radius: 10px;\n"
"    border: 2px groove gray;\n"
"    border-style: outset;\n"
"\n"
"    font:bold;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color:white;\n"
"    color: black;\n"
"    }\n"
"QPushButton:pressed{\n"
"    background-color:rgb(85, 170, 255);\n"
"    border-style: inset;\n"
"    }"));
        btnQuit = new QPushButton(CtrlDialog);
        btnQuit->setObjectName(QStringLiteral("btnQuit"));
        btnQuit->setGeometry(QRect(430, 442, 81, 31));
        btnQuit->setStyleSheet(QLatin1String("QPushButton{\n"
"    background-color:rgb(230, 240, 250);\n"
"    border-radius: 10px;\n"
"    border: 2px groove gray;\n"
"    border-style: outset;\n"
"\n"
"    font:bold;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color:white;\n"
"    color: black;\n"
"    }\n"
"QPushButton:pressed{\n"
"    background-color:rgb(85, 170, 255);\n"
"    border-style: inset;\n"
"    }"));

        retranslateUi(CtrlDialog);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CtrlDialog);
    } // setupUi

    void retranslateUi(QDialog *CtrlDialog)
    {
        CtrlDialog->setWindowTitle(QApplication::translate("CtrlDialog", "Dialog", 0));
        label_11->setText(QApplication::translate("CtrlDialog", "\351\235\231\346\200\201\346\216\247\345\210\266", 0));
        label_7->setText(QApplication::translate("CtrlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">P</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("CtrlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">I</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("CtrlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">D</span></p></body></html>", 0));
        label_10->setText(QApplication::translate("CtrlDialog", "\345\212\250\346\200\201\346\216\247\345\210\266", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CtrlDialog", "PID\345\217\202\346\225\260", 0));
        label_3->setText(QApplication::translate("CtrlDialog", "S", 0));
        label->setText(QApplication::translate("CtrlDialog", "\345\211\215\351\246\210", 0));
        label_9->setText(QApplication::translate("CtrlDialog", "\345\217\215\351\246\210", 0));
        label_13->setText(QApplication::translate("CtrlDialog", "V", 0));
        label_14->setText(QApplication::translate("CtrlDialog", "A", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("CtrlDialog", "\344\270\211\345\217\202\351\207\217", 0));
        label_16->setText(QApplication::translate("CtrlDialog", "V", 0));
        label_15->setText(QApplication::translate("CtrlDialog", "A", 0));
        label_8->setText(QApplication::translate("CtrlDialog", "S", 0));
        label_17->setText(QApplication::translate("CtrlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">P</span></p></body></html>", 0));
        label_12->setText(QApplication::translate("CtrlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">I</span></p></body></html>", 0));
        label_18->setText(QApplication::translate("CtrlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">D</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("CtrlDialog", "PID3\345\217\202\346\225\260", 0));
        label_4->setText(QApplication::translate("CtrlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\346\216\247\345\210\266\346\226\271\345\274\217\357\274\232</span></p></body></html>", 0));
        btnOk->setText(QApplication::translate("CtrlDialog", "\347\241\256\345\256\232", 0));
        btnQuit->setText(QApplication::translate("CtrlDialog", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class CtrlDialog: public Ui_CtrlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTRLDIALOG_H

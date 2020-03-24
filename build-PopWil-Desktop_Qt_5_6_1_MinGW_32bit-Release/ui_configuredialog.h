/********************************************************************************
** Form generated from reading UI file 'configuredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGUREDIALOG_H
#define UI_CONFIGUREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_ConfigureDialog
{
public:
    QComboBox *cmbDevice;
    QLabel *lblDevice;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QGroupBox *groupBox;
    QComboBox *cmbChannelStart;
    QLabel *lblValueRange;
    QLabel *lblChannelCount;
    QLabel *lblChannelStart;
    QComboBox *cmbValueRange;
    QComboBox *cmbChannelCount;
    QGroupBox *groupBox_3;
    QLabel *lblChannelCount_2;
    QLineEdit *edtClockRatePerChan_AI;
    QComboBox *cmbValueRange_AI;
    QLabel *lblValueRange_2;
    QLabel *lblClockRate;
    QComboBox *cmbChannelStart_AI;
    QLabel *lblChannelStart_2;
    QLabel *lblRateUnit;
    QComboBox *cmbChannelCount_AI;
    QLabel *lblSectionLength;
    QLineEdit *edtSectionLength_AI;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_ENC;
    QRadioButton *radioButton_SSI;

    void setupUi(QDialog *ConfigureDialog)
    {
        if (ConfigureDialog->objectName().isEmpty())
            ConfigureDialog->setObjectName(QStringLiteral("ConfigureDialog"));
        ConfigureDialog->resize(670, 354);
        ConfigureDialog->setMinimumSize(QSize(455, 213));
        cmbDevice = new QComboBox(ConfigureDialog);
        cmbDevice->setObjectName(QStringLiteral("cmbDevice"));
        cmbDevice->setGeometry(QRect(130, 30, 311, 21));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmbDevice->sizePolicy().hasHeightForWidth());
        cmbDevice->setSizePolicy(sizePolicy);
        cmbDevice->setLayoutDirection(Qt::LeftToRight);
        lblDevice = new QLabel(ConfigureDialog);
        lblDevice->setObjectName(QStringLiteral("lblDevice"));
        lblDevice->setGeometry(QRect(70, 30, 51, 21));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblDevice->sizePolicy().hasHeightForWidth());
        lblDevice->setSizePolicy(sizePolicy1);
        btnOK = new QPushButton(ConfigureDialog);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        btnOK->setGeometry(QRect(170, 300, 75, 23));
        btnOK->setStyleSheet(QLatin1String("QPushButton{\n"
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
        btnCancel = new QPushButton(ConfigureDialog);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(390, 300, 75, 23));
        btnCancel->setStyleSheet(QLatin1String("QPushButton{\n"
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
        btnCancel->setAutoDefault(false);
        groupBox = new QGroupBox(ConfigureDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 80, 241, 121));
        cmbChannelStart = new QComboBox(groupBox);
        cmbChannelStart->setObjectName(QStringLiteral("cmbChannelStart"));
        cmbChannelStart->setGeometry(QRect(98, 20, 131, 21));
        sizePolicy.setHeightForWidth(cmbChannelStart->sizePolicy().hasHeightForWidth());
        cmbChannelStart->setSizePolicy(sizePolicy);
        lblValueRange = new QLabel(groupBox);
        lblValueRange->setObjectName(QStringLiteral("lblValueRange"));
        lblValueRange->setGeometry(QRect(8, 84, 91, 22));
        sizePolicy1.setHeightForWidth(lblValueRange->sizePolicy().hasHeightForWidth());
        lblValueRange->setSizePolicy(sizePolicy1);
        lblValueRange->setMinimumSize(QSize(91, 22));
        lblValueRange->setMaximumSize(QSize(91, 22));
        lblChannelCount = new QLabel(groupBox);
        lblChannelCount->setObjectName(QStringLiteral("lblChannelCount"));
        lblChannelCount->setGeometry(QRect(8, 52, 91, 22));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblChannelCount->sizePolicy().hasHeightForWidth());
        lblChannelCount->setSizePolicy(sizePolicy2);
        lblChannelCount->setMinimumSize(QSize(91, 22));
        lblChannelCount->setMaximumSize(QSize(91, 22));
        lblChannelStart = new QLabel(groupBox);
        lblChannelStart->setObjectName(QStringLiteral("lblChannelStart"));
        lblChannelStart->setGeometry(QRect(8, 20, 91, 22));
        lblChannelStart->setMinimumSize(QSize(91, 22));
        lblChannelStart->setMaximumSize(QSize(91, 22));
        cmbValueRange = new QComboBox(groupBox);
        cmbValueRange->setObjectName(QStringLiteral("cmbValueRange"));
        cmbValueRange->setGeometry(QRect(99, 84, 131, 21));
        sizePolicy.setHeightForWidth(cmbValueRange->sizePolicy().hasHeightForWidth());
        cmbValueRange->setSizePolicy(sizePolicy);
        cmbChannelCount = new QComboBox(groupBox);
        cmbChannelCount->setObjectName(QStringLiteral("cmbChannelCount"));
        cmbChannelCount->setGeometry(QRect(99, 52, 131, 21));
        sizePolicy.setHeightForWidth(cmbChannelCount->sizePolicy().hasHeightForWidth());
        cmbChannelCount->setSizePolicy(sizePolicy);
        groupBox_3 = new QGroupBox(ConfigureDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(310, 80, 341, 201));
        lblChannelCount_2 = new QLabel(groupBox_3);
        lblChannelCount_2->setObjectName(QStringLiteral("lblChannelCount_2"));
        lblChannelCount_2->setGeometry(QRect(17, 56, 81, 21));
        sizePolicy2.setHeightForWidth(lblChannelCount_2->sizePolicy().hasHeightForWidth());
        lblChannelCount_2->setSizePolicy(sizePolicy2);
        edtClockRatePerChan_AI = new QLineEdit(groupBox_3);
        edtClockRatePerChan_AI->setObjectName(QStringLiteral("edtClockRatePerChan_AI"));
        edtClockRatePerChan_AI->setGeometry(QRect(110, 120, 161, 20));
        edtClockRatePerChan_AI->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        cmbValueRange_AI = new QComboBox(groupBox_3);
        cmbValueRange_AI->setObjectName(QStringLiteral("cmbValueRange_AI"));
        cmbValueRange_AI->setGeometry(QRect(110, 90, 161, 20));
        sizePolicy.setHeightForWidth(cmbValueRange_AI->sizePolicy().hasHeightForWidth());
        cmbValueRange_AI->setSizePolicy(sizePolicy);
        lblValueRange_2 = new QLabel(groupBox_3);
        lblValueRange_2->setObjectName(QStringLiteral("lblValueRange_2"));
        lblValueRange_2->setGeometry(QRect(17, 88, 71, 21));
        sizePolicy1.setHeightForWidth(lblValueRange_2->sizePolicy().hasHeightForWidth());
        lblValueRange_2->setSizePolicy(sizePolicy1);
        lblClockRate = new QLabel(groupBox_3);
        lblClockRate->setObjectName(QStringLiteral("lblClockRate"));
        lblClockRate->setGeometry(QRect(17, 120, 61, 21));
        sizePolicy1.setHeightForWidth(lblClockRate->sizePolicy().hasHeightForWidth());
        lblClockRate->setSizePolicy(sizePolicy1);
        cmbChannelStart_AI = new QComboBox(groupBox_3);
        cmbChannelStart_AI->setObjectName(QStringLiteral("cmbChannelStart_AI"));
        cmbChannelStart_AI->setGeometry(QRect(110, 30, 161, 20));
        sizePolicy.setHeightForWidth(cmbChannelStart_AI->sizePolicy().hasHeightForWidth());
        cmbChannelStart_AI->setSizePolicy(sizePolicy);
        lblChannelStart_2 = new QLabel(groupBox_3);
        lblChannelStart_2->setObjectName(QStringLiteral("lblChannelStart_2"));
        lblChannelStart_2->setGeometry(QRect(17, 26, 71, 21));
        lblRateUnit = new QLabel(groupBox_3);
        lblRateUnit->setObjectName(QStringLiteral("lblRateUnit"));
        lblRateUnit->setGeometry(QRect(280, 121, 21, 20));
        sizePolicy1.setHeightForWidth(lblRateUnit->sizePolicy().hasHeightForWidth());
        lblRateUnit->setSizePolicy(sizePolicy1);
        cmbChannelCount_AI = new QComboBox(groupBox_3);
        cmbChannelCount_AI->setObjectName(QStringLiteral("cmbChannelCount_AI"));
        cmbChannelCount_AI->setGeometry(QRect(110, 60, 161, 20));
        sizePolicy.setHeightForWidth(cmbChannelCount_AI->sizePolicy().hasHeightForWidth());
        cmbChannelCount_AI->setSizePolicy(sizePolicy);
        lblSectionLength = new QLabel(groupBox_3);
        lblSectionLength->setObjectName(QStringLiteral("lblSectionLength"));
        lblSectionLength->setGeometry(QRect(10, 150, 91, 21));
        sizePolicy1.setHeightForWidth(lblSectionLength->sizePolicy().hasHeightForWidth());
        lblSectionLength->setSizePolicy(sizePolicy1);
        edtSectionLength_AI = new QLineEdit(groupBox_3);
        edtSectionLength_AI->setObjectName(QStringLiteral("edtSectionLength_AI"));
        edtSectionLength_AI->setGeometry(QRect(110, 150, 161, 21));
        groupBox_2 = new QGroupBox(ConfigureDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 210, 241, 61));
        radioButton_ENC = new QRadioButton(groupBox_2);
        radioButton_ENC->setObjectName(QStringLiteral("radioButton_ENC"));
        radioButton_ENC->setGeometry(QRect(10, 20, 89, 16));
        radioButton_SSI = new QRadioButton(groupBox_2);
        radioButton_SSI->setObjectName(QStringLiteral("radioButton_SSI"));
        radioButton_SSI->setGeometry(QRect(140, 20, 89, 16));
#ifndef QT_NO_SHORTCUT
        lblDevice->setBuddy(cmbDevice);
        lblValueRange->setBuddy(cmbValueRange);
        lblChannelCount->setBuddy(cmbChannelCount);
        lblChannelStart->setBuddy(cmbChannelStart);
        lblChannelCount_2->setBuddy(cmbChannelCount);
        lblValueRange_2->setBuddy(cmbValueRange);
        lblClockRate->setBuddy(cmbValueRange);
        lblChannelStart_2->setBuddy(cmbChannelStart);
        lblRateUnit->setBuddy(cmbValueRange);
        lblSectionLength->setBuddy(cmbValueRange);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(cmbDevice, cmbChannelStart);
        QWidget::setTabOrder(cmbChannelStart, cmbChannelCount);
        QWidget::setTabOrder(cmbChannelCount, cmbValueRange);
        QWidget::setTabOrder(cmbValueRange, btnOK);
        QWidget::setTabOrder(btnOK, btnCancel);

        retranslateUi(ConfigureDialog);

        QMetaObject::connectSlotsByName(ConfigureDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigureDialog)
    {
        ConfigureDialog->setWindowTitle(QApplication::translate("ConfigureDialog", "PCI\351\200\232\351\201\223\350\256\276\347\275\256", 0));
        lblDevice->setText(QApplication::translate("ConfigureDialog", "\350\256\276\345\244\207\357\274\232", 0));
        btnOK->setText(QApplication::translate("ConfigureDialog", "\347\241\256\345\256\232", 0));
        btnCancel->setText(QApplication::translate("ConfigureDialog", "\351\200\200\345\207\272", 0));
        groupBox->setTitle(QApplication::translate("ConfigureDialog", "AO\350\256\276\347\275\256", 0));
        lblValueRange->setText(QApplication::translate("ConfigureDialog", "\350\276\223\345\207\272\346\234\200\345\244\247\345\200\274\357\274\232", 0));
        lblChannelCount->setText(QApplication::translate("ConfigureDialog", "\351\200\232\351\201\223\346\225\260\351\207\217", 0));
        lblChannelStart->setText(QApplication::translate("ConfigureDialog", "\350\265\267\345\247\213\351\200\232\351\201\223\357\274\232", 0));
        groupBox_3->setTitle(QApplication::translate("ConfigureDialog", "\351\253\230\351\200\237AI\351\207\207\351\233\206\351\205\215\347\275\256", 0));
        lblChannelCount_2->setText(QApplication::translate("ConfigureDialog", "\351\200\232\351\201\223\346\225\260\351\207\217\357\274\232", 0));
        edtClockRatePerChan_AI->setText(QString());
        lblValueRange_2->setText(QApplication::translate("ConfigureDialog", "\350\276\223\345\205\245\346\234\200\345\244\247\347\224\265\345\216\213\357\274\232", 0));
        lblClockRate->setText(QApplication::translate("ConfigureDialog", "\351\207\207\346\240\267\351\242\221\347\216\207", 0));
        lblChannelStart_2->setText(QApplication::translate("ConfigureDialog", "\350\265\267\345\247\213\351\200\232\351\201\223\357\274\232", 0));
        lblRateUnit->setText(QApplication::translate("ConfigureDialog", "Hz", 0));
        lblSectionLength->setText(QApplication::translate("ConfigureDialog", "\347\274\223\345\206\262\345\214\272\351\225\277\345\272\246\357\274\232", 0));
        edtSectionLength_AI->setText(QString());
        groupBox_2->setTitle(QApplication::translate("ConfigureDialog", "\344\275\215\347\247\273\351\207\207\351\233\206", 0));
        radioButton_ENC->setText(QApplication::translate("ConfigureDialog", "ENC_7480", 0));
        radioButton_SSI->setText(QApplication::translate("ConfigureDialog", "SSI\351\207\207\351\233\206\345\215\241", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigureDialog: public Ui_ConfigureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGUREDIALOG_H

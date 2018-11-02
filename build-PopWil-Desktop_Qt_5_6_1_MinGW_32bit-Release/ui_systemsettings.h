/********************************************************************************
** Form generated from reading UI file 'systemsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMSETTINGS_H
#define UI_SYSTEMSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemSettings
{
public:
    QPushButton *btnSaveOnce;
    QPushButton *btnClose;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *lab_ctrl_interval_2;
    QLineEdit *lineEdit_MaxAbsolutePosition;
    QLabel *label_3;
    QLabel *lab_draw_interval_2;
    QLineEdit *lineEdit_MaxOutU;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QSlider *horizontalSlider_control;
    QSlider *horizontalSlider_draw;
    QLabel *lab_ctrl_interval;
    QLabel *label;
    QSpinBox *spinBoxCtrlInterval;
    QLabel *lab_draw_interval;
    QSpinBox *spinBoxDrawInterval;
    QLabel *label_2;

    void setupUi(QDialog *SystemSettings)
    {
        if (SystemSettings->objectName().isEmpty())
            SystemSettings->setObjectName(QStringLiteral("SystemSettings"));
        SystemSettings->resize(716, 499);
        btnSaveOnce = new QPushButton(SystemSettings);
        btnSaveOnce->setObjectName(QStringLiteral("btnSaveOnce"));
        btnSaveOnce->setGeometry(QRect(130, 420, 121, 41));
        btnSaveOnce->setStyleSheet(QLatin1String("QPushButton{\n"
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
        btnClose = new QPushButton(SystemSettings);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setGeometry(QRect(390, 420, 141, 41));
        btnClose->setStyleSheet(QLatin1String("QPushButton{\n"
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
        groupBox = new QGroupBox(SystemSettings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(370, 0, 331, 241));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 311, 211));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lab_ctrl_interval_2 = new QLabel(layoutWidget);
        lab_ctrl_interval_2->setObjectName(QStringLiteral("lab_ctrl_interval_2"));
        QFont font;
        font.setPointSize(15);
        lab_ctrl_interval_2->setFont(font);

        gridLayout_2->addWidget(lab_ctrl_interval_2, 0, 0, 1, 1);

        lineEdit_MaxAbsolutePosition = new QLineEdit(layoutWidget);
        lineEdit_MaxAbsolutePosition->setObjectName(QStringLiteral("lineEdit_MaxAbsolutePosition"));

        gridLayout_2->addWidget(lineEdit_MaxAbsolutePosition, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setWeight(50);
        label_3->setFont(font1);

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);

        lab_draw_interval_2 = new QLabel(layoutWidget);
        lab_draw_interval_2->setObjectName(QStringLiteral("lab_draw_interval_2"));
        lab_draw_interval_2->setFont(font);

        gridLayout_2->addWidget(lab_draw_interval_2, 1, 0, 1, 1);

        lineEdit_MaxOutU = new QLineEdit(layoutWidget);
        lineEdit_MaxOutU->setObjectName(QStringLiteral("lineEdit_MaxOutU"));

        gridLayout_2->addWidget(lineEdit_MaxOutU, 1, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout_2->addWidget(label_4, 1, 2, 1, 1);

        gridLayout_2->setColumnStretch(0, 2);
        gridLayout_2->setColumnStretch(1, 2);
        gridLayout_2->setColumnStretch(2, 1);
        groupBox_2 = new QGroupBox(SystemSettings);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 0, 351, 241));
        horizontalSlider_control = new QSlider(groupBox_2);
        horizontalSlider_control->setObjectName(QStringLiteral("horizontalSlider_control"));
        horizontalSlider_control->setGeometry(QRect(50, 70, 160, 22));
        horizontalSlider_control->setOrientation(Qt::Horizontal);
        horizontalSlider_draw = new QSlider(groupBox_2);
        horizontalSlider_draw->setObjectName(QStringLiteral("horizontalSlider_draw"));
        horizontalSlider_draw->setGeometry(QRect(50, 170, 160, 22));
        horizontalSlider_draw->setOrientation(Qt::Horizontal);
        lab_ctrl_interval = new QLabel(groupBox_2);
        lab_ctrl_interval->setObjectName(QStringLiteral("lab_ctrl_interval"));
        lab_ctrl_interval->setGeometry(QRect(20, 30, 100, 20));
        lab_ctrl_interval->setFont(font);
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 70, 20, 20));
        label->setFont(font1);
        spinBoxCtrlInterval = new QSpinBox(groupBox_2);
        spinBoxCtrlInterval->setObjectName(QStringLiteral("spinBoxCtrlInterval"));
        spinBoxCtrlInterval->setGeometry(QRect(230, 70, 61, 20));
        lab_draw_interval = new QLabel(groupBox_2);
        lab_draw_interval->setObjectName(QStringLiteral("lab_draw_interval"));
        lab_draw_interval->setGeometry(QRect(20, 120, 100, 23));
        lab_draw_interval->setFont(font);
        spinBoxDrawInterval = new QSpinBox(groupBox_2);
        spinBoxDrawInterval->setObjectName(QStringLiteral("spinBoxDrawInterval"));
        spinBoxDrawInterval->setGeometry(QRect(230, 170, 61, 20));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 170, 20, 20));
        label_2->setFont(font1);

        retranslateUi(SystemSettings);

        QMetaObject::connectSlotsByName(SystemSettings);
    } // setupUi

    void retranslateUi(QDialog *SystemSettings)
    {
        SystemSettings->setWindowTitle(QApplication::translate("SystemSettings", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
        btnSaveOnce->setText(QApplication::translate("SystemSettings", "\347\241\256\345\256\232", 0));
        btnClose->setText(QApplication::translate("SystemSettings", "\351\200\200\345\207\272", 0));
        groupBox->setTitle(QApplication::translate("SystemSettings", "\344\277\235\346\212\244\345\217\202\346\225\260", 0));
        lab_ctrl_interval_2->setText(QApplication::translate("SystemSettings", "\346\234\200\345\244\247\347\273\235\345\257\271\344\275\215\347\247\273\357\274\232", 0));
        label_3->setText(QApplication::translate("SystemSettings", "MM", 0));
        lab_draw_interval_2->setText(QApplication::translate("SystemSettings", "<html><head/><body><p>\350\276\223\345\207\272\347\273\235\345\257\271\351\231\220\345\271\205\357\274\232</p></body></html>", 0));
        label_4->setText(QApplication::translate("SystemSettings", "V", 0));
        groupBox_2->setTitle(QApplication::translate("SystemSettings", "\345\221\250\346\234\237\345\217\202\346\225\260", 0));
        lab_ctrl_interval->setText(QApplication::translate("SystemSettings", "\346\216\247\345\210\266\345\221\250\346\234\237\357\274\232", 0));
        label->setText(QApplication::translate("SystemSettings", "MS", 0));
        lab_draw_interval->setText(QApplication::translate("SystemSettings", "<html><head/><body><p>\347\273\230\345\233\276\345\221\250\346\234\237\357\274\232</p></body></html>", 0));
        label_2->setText(QApplication::translate("SystemSettings", "MS", 0));
    } // retranslateUi

};

namespace Ui {
    class SystemSettings: public Ui_SystemSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMSETTINGS_H

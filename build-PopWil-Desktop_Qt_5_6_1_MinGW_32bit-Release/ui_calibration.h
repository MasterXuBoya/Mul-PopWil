/********************************************************************************
** Form generated from reading UI file 'calibration.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATION_H
#define UI_CALIBRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_calibration
{
public:
    QGroupBox *groupBox;
    QLabel *label_2;
    QLineEdit *led_k;
    QLabel *label;
    QLineEdit *led_bias;
    QPushButton *btn_ok;
    QGroupBox *groupBox_3;
    QLabel *label_5;
    QLineEdit *led_k_dis;
    QLabel *label_6;
    QLineEdit *led_bias_dis;
    QPushButton *btn_ok_2;

    void setupUi(QDialog *calibration)
    {
        if (calibration->objectName().isEmpty())
            calibration->setObjectName(QStringLiteral("calibration"));
        calibration->resize(545, 268);
        groupBox = new QGroupBox(calibration);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 241, 131));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 80, 54, 12));
        led_k = new QLineEdit(groupBox);
        led_k->setObjectName(QStringLiteral("led_k"));
        led_k->setGeometry(QRect(100, 40, 113, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 54, 12));
        led_bias = new QLineEdit(groupBox);
        led_bias->setObjectName(QStringLiteral("led_bias"));
        led_bias->setGeometry(QRect(100, 70, 113, 20));
        btn_ok = new QPushButton(calibration);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));
        btn_ok->setGeometry(QRect(100, 180, 81, 31));
        groupBox_3 = new QGroupBox(calibration);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(290, 20, 241, 131));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 80, 54, 12));
        led_k_dis = new QLineEdit(groupBox_3);
        led_k_dis->setObjectName(QStringLiteral("led_k_dis"));
        led_k_dis->setGeometry(QRect(100, 40, 113, 20));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 40, 54, 12));
        led_bias_dis = new QLineEdit(groupBox_3);
        led_bias_dis->setObjectName(QStringLiteral("led_bias_dis"));
        led_bias_dis->setGeometry(QRect(100, 70, 113, 20));
        btn_ok_2 = new QPushButton(calibration);
        btn_ok_2->setObjectName(QStringLiteral("btn_ok_2"));
        btn_ok_2->setGeometry(QRect(320, 180, 81, 31));

        retranslateUi(calibration);

        QMetaObject::connectSlotsByName(calibration);
    } // setupUi

    void retranslateUi(QDialog *calibration)
    {
        calibration->setWindowTitle(QApplication::translate("calibration", "\344\274\240\346\204\237\345\231\250\346\240\241\345\207\206", 0));
        groupBox->setTitle(QApplication::translate("calibration", "\345\212\240\351\200\237\345\272\246\344\274\240\346\204\237\345\231\250", 0));
        label_2->setText(QApplication::translate("calibration", "bias\357\274\232", 0));
        label->setText(QApplication::translate("calibration", "\347\263\273\346\225\260K\357\274\232", 0));
        btn_ok->setText(QApplication::translate("calibration", "\347\241\256\345\256\232", 0));
        groupBox_3->setTitle(QApplication::translate("calibration", "\344\275\215\347\247\273\344\274\240\346\204\237\345\231\250", 0));
        label_5->setText(QApplication::translate("calibration", "bias\357\274\232", 0));
        label_6->setText(QApplication::translate("calibration", "\347\263\273\346\225\260K\357\274\232", 0));
        btn_ok_2->setText(QApplication::translate("calibration", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class calibration: public Ui_calibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATION_H

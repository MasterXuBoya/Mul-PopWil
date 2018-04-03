/********************************************************************************
** Form generated from reading UI file 'aboutform.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTFORM_H
#define UI_ABOUTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutForm
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_12;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_11;
    QLabel *label_2;
    QLabel *label_13;

    void setupUi(QWidget *AboutForm)
    {
        if (AboutForm->objectName().isEmpty())
            AboutForm->setObjectName(QStringLiteral("AboutForm"));
        AboutForm->setEnabled(true);
        AboutForm->resize(519, 378);
        groupBox = new QGroupBox(AboutForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 471, 331));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 421, 261));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout->addWidget(label_12);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout->addWidget(label_9);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout->addWidget(label_10);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_2->addWidget(label_11);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 290, 411, 31));

        retranslateUi(AboutForm);

        QMetaObject::connectSlotsByName(AboutForm);
    } // setupUi

    void retranslateUi(QWidget *AboutForm)
    {
        AboutForm->setWindowTitle(QApplication::translate("AboutForm", "\347\211\210\346\234\254\344\277\241\346\201\257", 0));
        groupBox->setTitle(QString());
        label_3->setText(QApplication::translate("AboutForm", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\211\210       \346\234\254\357\274\232</span></p></body></html>", 0));
        label_12->setText(QApplication::translate("AboutForm", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\274\226    \345\217\267\357\274\232</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("AboutForm", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\215\225\344\275\215\357\274\232</span></p></body></html>", 0));
        label_9->setText(QApplication::translate("AboutForm", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\216\247\345\210\266\345\231\250\357\274\232</span></p></body></html>", 0));
        label_10->setText(QApplication::translate("AboutForm", "<html><head/><body><p><span style=\" font-size:12pt;\">\350\201\224\347\263\273\347\224\265\350\257\235\357\274\232</span></p></body></html>", 0));
        label->setText(QApplication::translate("AboutForm", "<html><head/><body><p><span style=\" font-size:12pt;\">\344\272\247\345\223\201\345\220\215\347\247\260\357\274\232</span></p></body></html>", 0));
        label_8->setText(QApplication::translate("AboutForm", "<html><head/><body><p><span style=\" font-size:12pt;\">0571-85024352</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("AboutForm", "<html><head/><body><p><span style=\" font-size:12pt;\">SSI or PCI1716</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("AboutForm", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\200\232\347\224\250\347\211\210V1.0</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("AboutForm", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\235\255\345\267\236\351\202\246\345\250\201\344\273\252\345\231\250(POPWIL)</span></p></body></html>", 0));
        label_11->setText(QApplication::translate("AboutForm", "<html><head/><body><p><span style=\" font-size:12pt;\">POPWARE_DZ_20180326</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("AboutForm", "<html><head/><body><p><span style=\" font-size:11pt;\">\345\215\225\350\207\252\347\224\261\345\272\246\346\250\241\346\213\237\346\214\257\345\212\250\345\217\260\346\216\247\345\210\266\347\263\273\347\273\237</span></p></body></html>", 0));
        label_13->setText(QApplication::translate("AboutForm", "Copyright 2017-2030 The POPWIL Company Ltd. All rights reserved.", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutForm: public Ui_AboutForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTFORM_H

/********************************************************************************
** Form generated from reading UI file 'drawdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWDIALOG_H
#define UI_DRAWDIALOG_H

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
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_DrawDialog
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *DrawDialog)
    {
        if (DrawDialog->objectName().isEmpty())
            DrawDialog->setObjectName(QStringLiteral("DrawDialog"));
        DrawDialog->resize(482, 353);
        pushButton = new QPushButton(DrawDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 290, 75, 23));
        pushButton_2 = new QPushButton(DrawDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 290, 75, 23));
        groupBox = new QGroupBox(DrawDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 80, 391, 181));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 80, 113, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 71, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 81, 31));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 30, 113, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(240, 40, 21, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(240, 80, 21, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 120, 81, 16));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 120, 113, 20));
        lineEdit_3->setReadOnly(true);
        textBrowser = new QTextBrowser(DrawDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(40, 10, 391, 61));

        retranslateUi(DrawDialog);

        QMetaObject::connectSlotsByName(DrawDialog);
    } // setupUi

    void retranslateUi(QDialog *DrawDialog)
    {
        DrawDialog->setWindowTitle(QApplication::translate("DrawDialog", "\347\273\230\345\233\276\350\256\276\347\275\256", 0));
        pushButton->setText(QApplication::translate("DrawDialog", "\347\241\256\345\256\232", 0));
        pushButton_2->setText(QApplication::translate("DrawDialog", "\351\200\200\345\207\272", 0));
        groupBox->setTitle(QApplication::translate("DrawDialog", "\347\273\230\345\233\276\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("DrawDialog", "\347\273\230\345\233\276\351\227\264\351\232\224\357\274\232", 0));
        label_2->setText(QApplication::translate("DrawDialog", "\350\247\206\351\207\216\346\227\266\351\225\277\357\274\232", 0));
        label_3->setText(QApplication::translate("DrawDialog", "ms", 0));
        label_4->setText(QApplication::translate("DrawDialog", "ms", 0));
        label_5->setText(QApplication::translate("DrawDialog", "\347\274\223\345\206\262\345\214\272\345\244\247\345\260\217\357\274\232", 0));
        lineEdit_3->setText(QApplication::translate("DrawDialog", "10000", 0));
        textBrowser->setHtml(QApplication::translate("DrawDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">    \345\215\225\350\207\252\347\224\261\345\272\246\346\214\257\345\212\250\345\217\260\346\216\247\345\210\266\347\263\273\347\273\237\347\273\230\345\233\276\351\203\250\345\210\206\351\207\207\347\224\250ChartDirector\346\216\247\344\273\266\345\274\200\345\217\221\357\274\214\345\271\266\345\210\251\347\224\250\345\217\214\347\274\223\345\206\262\346\212\200\346\234\257\345\256\236\347\216\260</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class DrawDialog: public Ui_DrawDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWDIALOG_H

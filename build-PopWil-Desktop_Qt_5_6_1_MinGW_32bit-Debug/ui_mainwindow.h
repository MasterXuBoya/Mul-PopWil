/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Open;
    QAction *action_Save;
    QAction *action_Quit;
    QAction *action_SineWaveTest;
    QAction *action_EarthWaveTest;
    QAction *action_ToolFlag;
    QAction *action_StatusFlag;
    QAction *action_HelpF1;
    QAction *action_About;
    QAction *action_Start;
    QAction *action_Pause;
    QAction *action_Continue;
    QAction *action_Stop;
    QAction *action_StorageSettings;
    QAction *action_SaveAsPicture;
    QAction *action_ChannelParameters;
    QAction *action_ControlParameters;
    QAction *action_LimitedParameters;
    QAction *action_ZoomIn;
    QAction *action_ZoomOut;
    QAction *action_Pointer;
    QWidget *centralWidget;
    QFrame *rightFrame;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QLabel *labeStatusl;
    QLabel *label_S;
    QLabel *label_V;
    QLabel *label_A;
    QLineEdit *lineEdit_S;
    QLineEdit *lineEdit_V;
    QLineEdit *lineEdit_A;
    QLabel *label_S_2;
    QLabel *label_S_3;
    QLabel *label_S_4;
    QLineEdit *lineEdit;
    QLabel *label_S_5;
    QFrame *lastFrame;
    QLabel *labeStatusl_2;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu;
    QMenu *menu_View;
    QMenu *menu_Settings;
    QMenu *menu_Command;
    QMenu *menu_Data;
    QMenu *menu_Help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(912, 537);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icon/Icon/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon);
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icon/Icon/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon1);
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName(QStringLiteral("action_Quit"));
        action_SineWaveTest = new QAction(MainWindow);
        action_SineWaveTest->setObjectName(QStringLiteral("action_SineWaveTest"));
        action_EarthWaveTest = new QAction(MainWindow);
        action_EarthWaveTest->setObjectName(QStringLiteral("action_EarthWaveTest"));
        action_ToolFlag = new QAction(MainWindow);
        action_ToolFlag->setObjectName(QStringLiteral("action_ToolFlag"));
        action_ToolFlag->setCheckable(true);
        action_StatusFlag = new QAction(MainWindow);
        action_StatusFlag->setObjectName(QStringLiteral("action_StatusFlag"));
        action_StatusFlag->setCheckable(true);
        action_HelpF1 = new QAction(MainWindow);
        action_HelpF1->setObjectName(QStringLiteral("action_HelpF1"));
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QStringLiteral("action_About"));
        action_Start = new QAction(MainWindow);
        action_Start->setObjectName(QStringLiteral("action_Start"));
        action_Pause = new QAction(MainWindow);
        action_Pause->setObjectName(QStringLiteral("action_Pause"));
        action_Continue = new QAction(MainWindow);
        action_Continue->setObjectName(QStringLiteral("action_Continue"));
        action_Stop = new QAction(MainWindow);
        action_Stop->setObjectName(QStringLiteral("action_Stop"));
        action_StorageSettings = new QAction(MainWindow);
        action_StorageSettings->setObjectName(QStringLiteral("action_StorageSettings"));
        action_SaveAsPicture = new QAction(MainWindow);
        action_SaveAsPicture->setObjectName(QStringLiteral("action_SaveAsPicture"));
        action_ChannelParameters = new QAction(MainWindow);
        action_ChannelParameters->setObjectName(QStringLiteral("action_ChannelParameters"));
        action_ControlParameters = new QAction(MainWindow);
        action_ControlParameters->setObjectName(QStringLiteral("action_ControlParameters"));
        action_LimitedParameters = new QAction(MainWindow);
        action_LimitedParameters->setObjectName(QStringLiteral("action_LimitedParameters"));
        action_ZoomIn = new QAction(MainWindow);
        action_ZoomIn->setObjectName(QStringLiteral("action_ZoomIn"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icon/Icon/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_ZoomIn->setIcon(icon2);
        action_ZoomOut = new QAction(MainWindow);
        action_ZoomOut->setObjectName(QStringLiteral("action_ZoomOut"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icon/Icon/zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_ZoomOut->setIcon(icon3);
        action_Pointer = new QAction(MainWindow);
        action_Pointer->setObjectName(QStringLiteral("action_Pointer"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Icon/Icon/pointer.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Pointer->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        rightFrame = new QFrame(centralWidget);
        rightFrame->setObjectName(QStringLiteral("rightFrame"));
        rightFrame->setGeometry(QRect(665, 0, 235, 271));
        rightFrame->setFrameShape(QFrame::StyledPanel);
        rightFrame->setFrameShadow(QFrame::Plain);
        btnStart = new QPushButton(rightFrame);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setGeometry(QRect(30, 40, 61, 41));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Icon/Icon/startIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStart->setIcon(icon5);
        btnStart->setIconSize(QSize(40, 40));
        btnStart->setFlat(true);
        btnStop = new QPushButton(rightFrame);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setGeometry(QRect(140, 40, 61, 41));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Icon/Icon/stopIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop->setIcon(icon6);
        btnStop->setIconSize(QSize(40, 40));
        btnStop->setFlat(true);
        labeStatusl = new QLabel(rightFrame);
        labeStatusl->setObjectName(QStringLiteral("labeStatusl"));
        labeStatusl->setGeometry(QRect(2, 0, 231, 31));
        labeStatusl->setTextFormat(Qt::PlainText);
        label_S = new QLabel(rightFrame);
        label_S->setObjectName(QStringLiteral("label_S"));
        label_S->setGeometry(QRect(30, 90, 41, 16));
        label_V = new QLabel(rightFrame);
        label_V->setObjectName(QStringLiteral("label_V"));
        label_V->setGeometry(QRect(30, 120, 54, 12));
        label_A = new QLabel(rightFrame);
        label_A->setObjectName(QStringLiteral("label_A"));
        label_A->setGeometry(QRect(20, 150, 54, 12));
        lineEdit_S = new QLineEdit(rightFrame);
        lineEdit_S->setObjectName(QStringLiteral("lineEdit_S"));
        lineEdit_S->setGeometry(QRect(70, 90, 113, 20));
        lineEdit_V = new QLineEdit(rightFrame);
        lineEdit_V->setObjectName(QStringLiteral("lineEdit_V"));
        lineEdit_V->setGeometry(QRect(70, 120, 113, 20));
        lineEdit_A = new QLineEdit(rightFrame);
        lineEdit_A->setObjectName(QStringLiteral("lineEdit_A"));
        lineEdit_A->setGeometry(QRect(70, 150, 113, 20));
        label_S_2 = new QLabel(rightFrame);
        label_S_2->setObjectName(QStringLiteral("label_S_2"));
        label_S_2->setGeometry(QRect(190, 90, 41, 16));
        label_S_3 = new QLabel(rightFrame);
        label_S_3->setObjectName(QStringLiteral("label_S_3"));
        label_S_3->setGeometry(QRect(190, 120, 41, 16));
        label_S_4 = new QLabel(rightFrame);
        label_S_4->setObjectName(QStringLiteral("label_S_4"));
        label_S_4->setGeometry(QRect(190, 150, 41, 16));
        lineEdit = new QLineEdit(rightFrame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 200, 113, 20));
        label_S_5 = new QLabel(rightFrame);
        label_S_5->setObjectName(QStringLiteral("label_S_5"));
        label_S_5->setGeometry(QRect(10, 200, 71, 21));
        lastFrame = new QFrame(centralWidget);
        lastFrame->setObjectName(QStringLiteral("lastFrame"));
        lastFrame->setGeometry(QRect(665, 270, 235, 252));
        lastFrame->setFrameShape(QFrame::StyledPanel);
        lastFrame->setFrameShadow(QFrame::Plain);
        labeStatusl_2 = new QLabel(lastFrame);
        labeStatusl_2->setObjectName(QStringLiteral("labeStatusl_2"));
        labeStatusl_2->setGeometry(QRect(2, 0, 231, 31));
        labeStatusl_2->setTextFormat(Qt::PlainText);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 912, 23));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu = new QMenu(menu_File);
        menu->setObjectName(QStringLiteral("menu"));
        menu_View = new QMenu(menuBar);
        menu_View->setObjectName(QStringLiteral("menu_View"));
        menu_Settings = new QMenu(menuBar);
        menu_Settings->setObjectName(QStringLiteral("menu_Settings"));
        menu_Command = new QMenu(menuBar);
        menu_Command->setObjectName(QStringLiteral("menu_Command"));
        menu_Data = new QMenu(menuBar);
        menu_Data->setObjectName(QStringLiteral("menu_Data"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_View->menuAction());
        menuBar->addAction(menu_Settings->menuAction());
        menuBar->addAction(menu_Command->menuAction());
        menuBar->addAction(menu_Data->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_File->addAction(menu->menuAction());
        menu_File->addAction(action_Open);
        menu_File->addAction(action_Save);
        menu_File->addSeparator();
        menu_File->addAction(action_Quit);
        menu->addAction(action_SineWaveTest);
        menu->addAction(action_EarthWaveTest);
        menu_View->addAction(action_ToolFlag);
        menu_View->addAction(action_StatusFlag);
        menu_Settings->addAction(action_ChannelParameters);
        menu_Settings->addAction(action_ControlParameters);
        menu_Settings->addAction(action_LimitedParameters);
        menu_Command->addAction(action_Start);
        menu_Command->addAction(action_Pause);
        menu_Command->addAction(action_Continue);
        menu_Command->addAction(action_Stop);
        menu_Data->addAction(action_Pointer);
        menu_Data->addAction(action_ZoomIn);
        menu_Data->addAction(action_ZoomOut);
        menu_Data->addSeparator();
        menu_Data->addAction(action_StorageSettings);
        menu_Data->addAction(action_SaveAsPicture);
        menu_Help->addAction(action_HelpF1);
        menu_Help->addAction(action_About);
        toolBar->addAction(action_Open);
        toolBar->addAction(action_Save);
        toolBar->addSeparator();
        toolBar->addAction(action_Pointer);
        toolBar->addAction(action_ZoomIn);
        toolBar->addAction(action_ZoomOut);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\215\225\350\207\252\347\224\261\345\272\246\346\250\241\346\213\237\346\214\257\345\212\250\345\217\260\346\216\247\345\210\266\347\263\273\347\273\237", 0));
        action_Open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\350\257\225\351\252\214", 0));
        action_Open->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        action_Save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\350\257\225\351\252\214", 0));
        action_Save->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        action_Quit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\263\273\347\273\237", 0));
        action_Quit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        action_SineWaveTest->setText(QApplication::translate("MainWindow", "\346\255\243\345\274\246\346\263\242\350\257\225\351\252\214", 0));
        action_EarthWaveTest->setText(QApplication::translate("MainWindow", "\345\234\260\351\234\207\346\263\242\350\257\225\351\252\214", 0));
        action_ToolFlag->setText(QApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217(&T)", 0));
        action_StatusFlag->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217", 0));
        action_HelpF1->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0));
        action_HelpF1->setShortcut(QApplication::translate("MainWindow", "F1", 0));
        action_About->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0));
        action_Start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", 0));
        action_Pause->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234", 0));
        action_Continue->setText(QApplication::translate("MainWindow", "\347\273\247\347\273\255", 0));
        action_Stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0));
        action_StorageSettings->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\350\256\276\347\275\256", 0));
        action_SaveAsPicture->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\344\270\272\345\233\276\347\211\207", 0));
        action_ChannelParameters->setText(QApplication::translate("MainWindow", "\351\200\232\351\201\223\345\217\202\346\225\260", 0));
        action_ControlParameters->setText(QApplication::translate("MainWindow", "\346\216\247\345\210\266\345\217\202\346\225\260", 0));
        action_LimitedParameters->setText(QApplication::translate("MainWindow", "\351\231\220\345\210\266\345\217\202\346\225\260", 0));
        action_ZoomIn->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247", 0));
        action_ZoomOut->setText(QApplication::translate("MainWindow", "\347\274\251\345\260\217", 0));
        action_Pointer->setText(QApplication::translate("MainWindow", "\346\214\207\351\222\210", 0));
        btnStart->setText(QString());
        btnStop->setText(QString());
        labeStatusl->setText(QApplication::translate("MainWindow", "\350\257\225\351\252\214\347\212\266\346\200\201", 0));
        label_S->setText(QApplication::translate("MainWindow", "\344\275\215\347\247\273\357\274\232", 0));
        label_V->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246\357\274\232", 0));
        label_A->setText(QApplication::translate("MainWindow", "\345\212\240\351\200\237\345\272\246\357\274\232", 0));
        label_S_2->setText(QApplication::translate("MainWindow", "mm", 0));
        label_S_3->setText(QApplication::translate("MainWindow", "mm/s", 0));
        label_S_4->setText(QApplication::translate("MainWindow", "mm/ss", 0));
        label_S_5->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\347\224\265\345\216\213:V", 0));
        labeStatusl_2->setText(QApplication::translate("MainWindow", "\350\257\225\351\252\214\344\277\241\346\201\257", 0));
        menu_File->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\257\225\351\252\214", 0));
        menu_View->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276(&V)", 0));
        menu_Settings->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256(&S)", 0));
        menu_Command->setTitle(QApplication::translate("MainWindow", "\345\221\275\344\273\244(&C)", 0));
        menu_Data->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256(&D)", 0));
        menu_Help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

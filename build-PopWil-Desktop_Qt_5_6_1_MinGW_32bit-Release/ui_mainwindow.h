/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
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
    QAction *action_SaveAsDefalut;
    QAction *action_Identity;
    QAction *actionAction_SystemSettings;
    QWidget *centralWidget;
    QFrame *displayFrame;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QLabel *labeStatusl;
    QPushButton *btn_clearZero;
    QPushButton *btn_DO;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_S;
    QLCDNumber *lcd_S;
    QLabel *label_S_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_V;
    QLCDNumber *lcd_V;
    QLabel *label_S_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_A;
    QLCDNumber *lcd_A;
    QLabel *label_S_4;
    QFrame *infoFrame;
    QLabel *labeStatusl_2;
    QListView *listView_eventInformation;
    QFrame *controlFrame;
    QTabWidget *tabWidget_controller;
    QWidget *tab;
    QFrame *line;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_S_6;
    QLineEdit *le_uk;
    QLabel *label_4;
    QPushButton *btn_out_uk;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_desPosition;
    QLineEdit *lineEdit_desPosition;
    QLabel *label_3;
    QPushButton *btn_static_comfirm;
    QWidget *tab_2;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *le_fre;
    QLineEdit *le_mag;
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QLineEdit *le_cnt;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *le_mid;
    QLabel *label_9;
    QPushButton *btn_sine_load;
    QWidget *tab_3;
    QGroupBox *groupBox;
    QComboBox *cmb_earth;
    QPushButton *btn_preview_earth;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *rbt_S;
    QRadioButton *rbt_V;
    QRadioButton *rbt_A;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *lab_earth_sample_T;
    QLabel *label_14;
    QLabel *lab_earth_sample_Cnt;
    QFrame *picFrame;
    QTabWidget *tabWidget_pic;
    QWidget *tab_draw;
    QFrame *drawFrame;
    QWidget *tab_preview;
    QFrame *frame;
    QLabel *labeStatusl_3;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *rbt_S_plot;
    QRadioButton *rbt_V_plot;
    QRadioButton *rbt_A_plot;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu;
    QMenu *menu_View;
    QMenu *menu_Settings;
    QMenu *menu_Command;
    QMenu *menu_Data;
    QMenu *menu_Help;
    QMenu *menu_Control;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(960, 900);
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
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icon/Icon/channel.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_ChannelParameters->setIcon(icon2);
        action_ControlParameters = new QAction(MainWindow);
        action_ControlParameters->setObjectName(QStringLiteral("action_ControlParameters"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icon/Icon/ctrlSetting.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_ControlParameters->setIcon(icon3);
        action_LimitedParameters = new QAction(MainWindow);
        action_LimitedParameters->setObjectName(QStringLiteral("action_LimitedParameters"));
        action_ZoomIn = new QAction(MainWindow);
        action_ZoomIn->setObjectName(QStringLiteral("action_ZoomIn"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Icon/Icon/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_ZoomIn->setIcon(icon4);
        action_ZoomOut = new QAction(MainWindow);
        action_ZoomOut->setObjectName(QStringLiteral("action_ZoomOut"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Icon/Icon/zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_ZoomOut->setIcon(icon5);
        action_Pointer = new QAction(MainWindow);
        action_Pointer->setObjectName(QStringLiteral("action_Pointer"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Icon/Icon/pointer.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Pointer->setIcon(icon6);
        action_SaveAsDefalut = new QAction(MainWindow);
        action_SaveAsDefalut->setObjectName(QStringLiteral("action_SaveAsDefalut"));
        action_Identity = new QAction(MainWindow);
        action_Identity->setObjectName(QStringLiteral("action_Identity"));
        actionAction_SystemSettings = new QAction(MainWindow);
        actionAction_SystemSettings->setObjectName(QStringLiteral("actionAction_SystemSettings"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Icon/Icon/settings2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAction_SystemSettings->setIcon(icon7);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        displayFrame = new QFrame(centralWidget);
        displayFrame->setObjectName(QStringLiteral("displayFrame"));
        displayFrame->setGeometry(QRect(660, 0, 300, 380));
        displayFrame->setFrameShape(QFrame::StyledPanel);
        displayFrame->setFrameShadow(QFrame::Plain);
        btnStart = new QPushButton(displayFrame);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setGeometry(QRect(60, 40, 50, 50));
        btnStart->setIconSize(QSize(40, 40));
        btnStart->setFlat(false);
        btnStop = new QPushButton(displayFrame);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setGeometry(QRect(150, 40, 50, 50));
        btnStop->setIconSize(QSize(40, 40));
        btnStop->setFlat(false);
        labeStatusl = new QLabel(displayFrame);
        labeStatusl->setObjectName(QStringLiteral("labeStatusl"));
        labeStatusl->setGeometry(QRect(2, 0, 300, 30));
        labeStatusl->setStyleSheet(QLatin1String("font: 75 12pt \"Agency FB\";\n"
"background-color: rgb(153, 204, 255);"));
        labeStatusl->setTextFormat(Qt::PlainText);
        btn_clearZero = new QPushButton(displayFrame);
        btn_clearZero->setObjectName(QStringLiteral("btn_clearZero"));
        btn_clearZero->setGeometry(QRect(210, 90, 16, 16));
        btn_DO = new QPushButton(displayFrame);
        btn_DO->setObjectName(QStringLiteral("btn_DO"));
        btn_DO->setGeometry(QRect(230, 40, 50, 50));
        layoutWidget = new QWidget(displayFrame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 100, 240, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_S = new QLabel(layoutWidget);
        label_S->setObjectName(QStringLiteral("label_S"));

        horizontalLayout->addWidget(label_S);

        lcd_S = new QLCDNumber(layoutWidget);
        lcd_S->setObjectName(QStringLiteral("lcd_S"));
        lcd_S->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 9pt \"Agency FB\";\n"
"background-color: rgb(238, 255, 246);"));
        lcd_S->setDigitCount(8);
        lcd_S->setSegmentStyle(QLCDNumber::Flat);
        lcd_S->setProperty("value", QVariant(0));
        lcd_S->setProperty("intValue", QVariant(0));

        horizontalLayout->addWidget(lcd_S);

        label_S_2 = new QLabel(layoutWidget);
        label_S_2->setObjectName(QStringLiteral("label_S_2"));
        label_S_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\232\266\344\271\246\";"));

        horizontalLayout->addWidget(label_S_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_V = new QLabel(layoutWidget);
        label_V->setObjectName(QStringLiteral("label_V"));

        horizontalLayout_2->addWidget(label_V);

        lcd_V = new QLCDNumber(layoutWidget);
        lcd_V->setObjectName(QStringLiteral("lcd_V"));
        lcd_V->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 9pt \"Agency FB\";\n"
"background-color: rgb(238, 255, 246);"));
        lcd_V->setDigitCount(8);
        lcd_V->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_2->addWidget(lcd_V);

        label_S_3 = new QLabel(layoutWidget);
        label_S_3->setObjectName(QStringLiteral("label_S_3"));
        label_S_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\232\266\344\271\246\";"));

        horizontalLayout_2->addWidget(label_S_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_A = new QLabel(layoutWidget);
        label_A->setObjectName(QStringLiteral("label_A"));

        horizontalLayout_3->addWidget(label_A);

        lcd_A = new QLCDNumber(layoutWidget);
        lcd_A->setObjectName(QStringLiteral("lcd_A"));
        lcd_A->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 9pt \"Agency FB\";\n"
"background-color: rgb(238, 255, 246);"));
        lcd_A->setDigitCount(8);
        lcd_A->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_3->addWidget(lcd_A);

        label_S_4 = new QLabel(layoutWidget);
        label_S_4->setObjectName(QStringLiteral("label_S_4"));
        label_S_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\232\266\344\271\246\";\n"
""));

        horizontalLayout_3->addWidget(label_S_4);


        verticalLayout->addLayout(horizontalLayout_3);

        infoFrame = new QFrame(centralWidget);
        infoFrame->setObjectName(QStringLiteral("infoFrame"));
        infoFrame->setGeometry(QRect(0, 600, 660, 220));
        infoFrame->setFrameShape(QFrame::StyledPanel);
        infoFrame->setFrameShadow(QFrame::Plain);
        labeStatusl_2 = new QLabel(infoFrame);
        labeStatusl_2->setObjectName(QStringLiteral("labeStatusl_2"));
        labeStatusl_2->setGeometry(QRect(0, 0, 660, 30));
        labeStatusl_2->setStyleSheet(QLatin1String("font: 75 12pt \"Agency FB\";\n"
"background-color: rgb(153, 204, 255);"));
        labeStatusl_2->setTextFormat(Qt::PlainText);
        listView_eventInformation = new QListView(infoFrame);
        listView_eventInformation->setObjectName(QStringLiteral("listView_eventInformation"));
        listView_eventInformation->setGeometry(QRect(0, 30, 660, 190));
        controlFrame = new QFrame(centralWidget);
        controlFrame->setObjectName(QStringLiteral("controlFrame"));
        controlFrame->setGeometry(QRect(660, 380, 300, 331));
        controlFrame->setFrameShape(QFrame::StyledPanel);
        controlFrame->setFrameShadow(QFrame::Plain);
        tabWidget_controller = new QTabWidget(controlFrame);
        tabWidget_controller->setObjectName(QStringLiteral("tabWidget_controller"));
        tabWidget_controller->setGeometry(QRect(1, 0, 300, 331));
        tabWidget_controller->setStyleSheet(QLatin1String("QTabBar::tab{background:transparent;font:bold;color:#000000;min-width:30ex;min-height:10ex;}\n"
"QTabBar::tab:hover{background:#CCFFFF;}\n"
"QTabBar::tab:selected{background:#99CCFF;border-color: green;}"));
        tabWidget_controller->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setStyleSheet(QStringLiteral(""));
        line = new QFrame(tab);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 110, 291, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 281, 80));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 261, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_S_6 = new QLabel(layoutWidget1);
        label_S_6->setObjectName(QStringLiteral("label_S_6"));

        horizontalLayout_4->addWidget(label_S_6);

        le_uk = new QLineEdit(layoutWidget1);
        le_uk->setObjectName(QStringLiteral("le_uk"));
        le_uk->setEchoMode(QLineEdit::Normal);
        le_uk->setClearButtonEnabled(true);

        horizontalLayout_4->addWidget(le_uk);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        btn_out_uk = new QPushButton(layoutWidget1);
        btn_out_uk->setObjectName(QStringLiteral("btn_out_uk"));

        horizontalLayout_4->addWidget(btn_out_uk);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 4);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 1);
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 140, 281, 71));
        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 30, 261, 25));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_desPosition = new QLabel(layoutWidget2);
        label_desPosition->setObjectName(QStringLiteral("label_desPosition"));

        horizontalLayout_5->addWidget(label_desPosition);

        lineEdit_desPosition = new QLineEdit(layoutWidget2);
        lineEdit_desPosition->setObjectName(QStringLiteral("lineEdit_desPosition"));
        lineEdit_desPosition->setClearButtonEnabled(true);

        horizontalLayout_5->addWidget(lineEdit_desPosition);

        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        btn_static_comfirm = new QPushButton(layoutWidget2);
        btn_static_comfirm->setObjectName(QStringLiteral("btn_static_comfirm"));

        horizontalLayout_5->addWidget(btn_static_comfirm);

        horizontalLayout_5->setStretch(0, 2);
        horizontalLayout_5->setStretch(1, 4);
        horizontalLayout_5->setStretch(2, 1);
        horizontalLayout_5->setStretch(3, 1);
        tabWidget_controller->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget3 = new QWidget(tab_2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 30, 271, 101));
        gridLayout = new QGridLayout(layoutWidget3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        le_fre = new QLineEdit(layoutWidget3);
        le_fre->setObjectName(QStringLiteral("le_fre"));

        gridLayout->addWidget(le_fre, 2, 1, 1, 1);

        le_mag = new QLineEdit(layoutWidget3);
        le_mag->setObjectName(QStringLiteral("le_mag"));

        gridLayout->addWidget(le_mag, 1, 1, 1, 1);

        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label_6 = new QLabel(layoutWidget3);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 2, 1, 1);

        le_cnt = new QLineEdit(layoutWidget3);
        le_cnt->setObjectName(QStringLiteral("le_cnt"));

        gridLayout->addWidget(le_cnt, 3, 1, 1, 1);

        label_7 = new QLabel(layoutWidget3);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 2, 2, 1, 1);

        label_8 = new QLabel(layoutWidget3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        le_mid = new QLineEdit(layoutWidget3);
        le_mid->setObjectName(QStringLiteral("le_mid"));

        gridLayout->addWidget(le_mid, 0, 1, 1, 1);

        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 0, 2, 1, 1);

        btn_sine_load = new QPushButton(tab_2);
        btn_sine_load->setObjectName(QStringLiteral("btn_sine_load"));
        btn_sine_load->setGeometry(QRect(90, 160, 75, 23));
        tabWidget_controller->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 281, 221));
        cmb_earth = new QComboBox(groupBox);
        cmb_earth->setObjectName(QStringLiteral("cmb_earth"));
        cmb_earth->setGeometry(QRect(31, 35, 181, 20));
        btn_preview_earth = new QPushButton(groupBox);
        btn_preview_earth->setObjectName(QStringLiteral("btn_preview_earth"));
        btn_preview_earth->setGeometry(QRect(100, 190, 75, 23));
        layoutWidget4 = new QWidget(groupBox);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(30, 80, 221, 21));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        rbt_S = new QRadioButton(layoutWidget4);
        rbt_S->setObjectName(QStringLiteral("rbt_S"));

        horizontalLayout_6->addWidget(rbt_S);

        rbt_V = new QRadioButton(layoutWidget4);
        rbt_V->setObjectName(QStringLiteral("rbt_V"));

        horizontalLayout_6->addWidget(rbt_V);

        rbt_A = new QRadioButton(layoutWidget4);
        rbt_A->setObjectName(QStringLiteral("rbt_A"));

        horizontalLayout_6->addWidget(rbt_A);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 120, 61, 16));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 150, 61, 21));
        lab_earth_sample_T = new QLabel(groupBox);
        lab_earth_sample_T->setObjectName(QStringLiteral("lab_earth_sample_T"));
        lab_earth_sample_T->setGeometry(QRect(110, 120, 61, 21));
        lab_earth_sample_T->setStyleSheet(QStringLiteral("background-color: rgb(147, 127, 137);"));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(190, 120, 54, 12));
        lab_earth_sample_Cnt = new QLabel(groupBox);
        lab_earth_sample_Cnt->setObjectName(QStringLiteral("lab_earth_sample_Cnt"));
        lab_earth_sample_Cnt->setGeometry(QRect(110, 150, 61, 21));
        lab_earth_sample_Cnt->setStyleSheet(QStringLiteral("background-color: rgb(243, 255, 225);"));
        tabWidget_controller->addTab(tab_3, QString());
        picFrame = new QFrame(centralWidget);
        picFrame->setObjectName(QStringLiteral("picFrame"));
        picFrame->setGeometry(QRect(0, 0, 660, 600));
        picFrame->setFrameShape(QFrame::StyledPanel);
        picFrame->setFrameShadow(QFrame::Plain);
        tabWidget_pic = new QTabWidget(picFrame);
        tabWidget_pic->setObjectName(QStringLiteral("tabWidget_pic"));
        tabWidget_pic->setGeometry(QRect(0, 0, 660, 600));
        tabWidget_pic->setStyleSheet(QLatin1String("QTabBar::tab{background:transparent;font:bold;color:#000000;min-width:30ex;min-height:10ex;}QTabBar::tab:hover{background:#CCFFFF;}\n"
"QTabBar::tab:selected{background:#99CCFF;border-color: green;}"));
        tab_draw = new QWidget();
        tab_draw->setObjectName(QStringLiteral("tab_draw"));
        drawFrame = new QFrame(tab_draw);
        drawFrame->setObjectName(QStringLiteral("drawFrame"));
        drawFrame->setGeometry(QRect(0, 0, 660, 600));
        drawFrame->setFrameShape(QFrame::StyledPanel);
        drawFrame->setFrameShadow(QFrame::Raised);
        tabWidget_pic->addTab(tab_draw, QString());
        tab_preview = new QWidget();
        tab_preview->setObjectName(QStringLiteral("tab_preview"));
        tabWidget_pic->addTab(tab_preview, QString());
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(660, 710, 311, 111));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        labeStatusl_3 = new QLabel(frame);
        labeStatusl_3->setObjectName(QStringLiteral("labeStatusl_3"));
        labeStatusl_3->setGeometry(QRect(0, 0, 301, 30));
        labeStatusl_3->setStyleSheet(QLatin1String("font: 75 12pt \"Agency FB\";\n"
"background-color: rgb(153, 204, 255);"));
        labeStatusl_3->setTextFormat(Qt::PlainText);
        layoutWidget5 = new QWidget(frame);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(40, 50, 211, 41));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        rbt_S_plot = new QRadioButton(layoutWidget5);
        rbt_S_plot->setObjectName(QStringLiteral("rbt_S_plot"));

        horizontalLayout_7->addWidget(rbt_S_plot);

        rbt_V_plot = new QRadioButton(layoutWidget5);
        rbt_V_plot->setObjectName(QStringLiteral("rbt_V_plot"));

        horizontalLayout_7->addWidget(rbt_V_plot);

        rbt_A_plot = new QRadioButton(layoutWidget5);
        rbt_A_plot->setObjectName(QStringLiteral("rbt_A_plot"));

        horizontalLayout_7->addWidget(rbt_A_plot);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 960, 23));
        menuBar->setStyleSheet(QStringLiteral("background-color:#EEE9E9"));
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
        menu_Control = new QMenu(menuBar);
        menu_Control->setObjectName(QStringLiteral("menu_Control"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setStyleSheet(QStringLiteral("background-color:#CCFFFF"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setStyleSheet(QStringLiteral("background-color:#C0C0C0"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_View->menuAction());
        menuBar->addAction(menu_Settings->menuAction());
        menuBar->addAction(menu_Command->menuAction());
        menuBar->addAction(menu_Data->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menuBar->addAction(menu_Control->menuAction());
        menu_File->addAction(menu->menuAction());
        menu_File->addAction(action_Open);
        menu_File->addAction(action_Save);
        menu_File->addAction(action_SaveAsDefalut);
        menu_File->addSeparator();
        menu_File->addAction(action_Quit);
        menu->addAction(action_SineWaveTest);
        menu->addAction(action_EarthWaveTest);
        menu_View->addAction(action_ToolFlag);
        menu_View->addAction(action_StatusFlag);
        menu_Settings->addAction(action_ChannelParameters);
        menu_Settings->addAction(action_ControlParameters);
        menu_Settings->addAction(action_LimitedParameters);
        menu_Settings->addAction(actionAction_SystemSettings);
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
        menu_Control->addAction(action_Identity);
        toolBar->addAction(action_Open);
        toolBar->addAction(action_Save);
        toolBar->addSeparator();
        toolBar->addAction(action_Pointer);
        toolBar->addAction(action_ZoomIn);
        toolBar->addAction(action_ZoomOut);
        toolBar->addSeparator();
        toolBar->addAction(action_ChannelParameters);
        toolBar->addAction(action_ControlParameters);
        toolBar->addAction(actionAction_SystemSettings);

        retranslateUi(MainWindow);

        tabWidget_controller->setCurrentIndex(0);
        tabWidget_pic->setCurrentIndex(0);


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
        action_SaveAsDefalut->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\344\270\272\351\273\230\350\256\244\350\256\276\347\275\256", 0));
        action_Identity->setText(QApplication::translate("MainWindow", "RBF\350\276\250\350\257\206", 0));
        actionAction_SystemSettings->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
        btnStart->setText(QString());
        btnStop->setText(QString());
        labeStatusl->setText(QApplication::translate("MainWindow", "\350\257\225\351\252\214\347\212\266\346\200\201", 0));
        btn_clearZero->setText(QApplication::translate("MainWindow", "0", 0));
        btn_DO->setText(QString());
        label_S->setText(QApplication::translate("MainWindow", "\344\275\215\347\247\273\357\274\232", 0));
        label_S_2->setText(QApplication::translate("MainWindow", "mm", 0));
        label_V->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246\357\274\232", 0));
        label_S_3->setText(QApplication::translate("MainWindow", "mm/s", 0));
        label_A->setText(QApplication::translate("MainWindow", "\345\212\240\351\200\237\345\272\246\357\274\232", 0));
        label_S_4->setText(QApplication::translate("MainWindow", "mm/ss", 0));
        labeStatusl_2->setText(QApplication::translate("MainWindow", "\350\257\225\351\252\214\344\277\241\346\201\257", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Debug", 0));
        label_S_6->setText(QApplication::translate("MainWindow", "\347\224\265\345\216\213:", 0));
        label_4->setText(QApplication::translate("MainWindow", "V", 0));
        btn_out_uk->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\351\235\231\346\200\201\346\216\247\345\210\266", 0));
        label_desPosition->setText(QApplication::translate("MainWindow", "\347\233\256\346\240\207\344\275\215\347\275\256\357\274\232", 0));
        label_3->setText(QApplication::translate("MainWindow", "mm", 0));
        btn_static_comfirm->setText(QApplication::translate("MainWindow", "\347\241\256\345\256\232", 0));
        tabWidget_controller->setTabText(tabWidget_controller->indexOf(tab), QApplication::translate("MainWindow", "\350\260\203\350\257\225", 0));
        label->setText(QApplication::translate("MainWindow", "\345\271\205\345\200\274\357\274\232", 0));
        label_2->setText(QApplication::translate("MainWindow", "\351\242\221\347\216\207\357\274\232", 0));
        label_5->setText(QApplication::translate("MainWindow", "\351\207\215\345\244\215\346\254\241\346\225\260\357\274\232", 0));
        label_6->setText(QApplication::translate("MainWindow", "mm", 0));
        label_7->setText(QApplication::translate("MainWindow", "Hz", 0));
        label_8->setText(QApplication::translate("MainWindow", "\344\270\255\345\277\203\357\274\232", 0));
        label_9->setText(QApplication::translate("MainWindow", "mm", 0));
        btn_sine_load->setText(QApplication::translate("MainWindow", "\350\275\275\345\205\245\345\217\202\346\225\260", 0));
        tabWidget_controller->setTabText(tabWidget_controller->indexOf(tab_2), QApplication::translate("MainWindow", "\346\255\243\345\274\246\346\263\242", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\234\260\351\234\207\346\263\242", 0));
        btn_preview_earth->setText(QApplication::translate("MainWindow", "\351\242\204\350\247\210", 0));
        rbt_S->setText(QApplication::translate("MainWindow", "\344\275\215\347\247\273", 0));
        rbt_V->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246", 0));
        rbt_A->setText(QApplication::translate("MainWindow", "\345\212\240\351\200\237\345\272\246", 0));
        label_10->setText(QApplication::translate("MainWindow", "\351\207\207\346\240\267\345\221\250\346\234\237\357\274\232", 0));
        label_11->setText(QApplication::translate("MainWindow", "\351\207\207\346\240\267\347\202\271\346\225\260\357\274\232", 0));
        lab_earth_sample_T->setText(QString());
        label_14->setText(QApplication::translate("MainWindow", "ms", 0));
        lab_earth_sample_Cnt->setText(QString());
        tabWidget_controller->setTabText(tabWidget_controller->indexOf(tab_3), QApplication::translate("MainWindow", "\345\234\260\351\234\207\346\263\242", 0));
        tabWidget_pic->setTabText(tabWidget_pic->indexOf(tab_draw), QApplication::translate("MainWindow", "\345\212\250\346\200\201\346\233\262\347\272\277", 0));
        tabWidget_pic->setTabText(tabWidget_pic->indexOf(tab_preview), QApplication::translate("MainWindow", "\351\242\204\350\247\210", 0));
        labeStatusl_3->setText(QApplication::translate("MainWindow", "\345\256\236\346\227\266\346\233\262\347\272\277\345\217\202\346\225\260", 0));
        rbt_S_plot->setText(QApplication::translate("MainWindow", "\344\275\215\347\247\273", 0));
        rbt_V_plot->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246", 0));
        rbt_A_plot->setText(QApplication::translate("MainWindow", "\345\212\240\351\200\237\345\272\246", 0));
        menu_File->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\257\225\351\252\214", 0));
        menu_View->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276(&V)", 0));
        menu_Settings->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256(&S)", 0));
        menu_Command->setTitle(QApplication::translate("MainWindow", "\345\221\275\344\273\244(&C)", 0));
        menu_Data->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256(&D)", 0));
        menu_Help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", 0));
        menu_Control->setTitle(QApplication::translate("MainWindow", "\346\216\247\345\210\266(&C)", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

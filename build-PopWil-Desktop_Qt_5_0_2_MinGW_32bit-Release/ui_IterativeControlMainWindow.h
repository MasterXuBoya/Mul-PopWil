/********************************************************************************
** Form generated from reading UI file 'IterativeControlMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITERATIVECONTROLMAINWINDOW_H
#define UI_ITERATIVECONTROLMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IterativeControlMainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit;
    QPushButton *btn_open;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_save;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView_Acc;
    QFrame *frame_Acc;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView_Vel;
    QFrame *frame_Vel;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QTableView *tableView_Dis;
    QFrame *frame_Dis;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_2;
    QPushButton *btn_open_2;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_4;
    QLabel *lab_origin_cnt;
    QLabel *label_15;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *lab_origin_sampleT;
    QGroupBox *groupBox_5;
    QLabel *label_14;
    QLabel *lab_new_cnt;
    QLabel *label_17;
    QLabel *label_16;
    QPushButton *btn_resample;
    QPushButton *btn_resample_save;
    QLineEdit *le_new_sample;
    QFrame *frame_Acc_2;
    QHBoxLayout *horizontalLayout_13;
    QWidget *tab_3;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *btn_model_save;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLineEdit *le_nfft;
    QLabel *label;
    QWidget *tab_5;
    QGraphicsView *graphicsView_3;
    QPushButton *btn_load_yd;
    QPushButton *pushButton_25;
    QPushButton *pushButton_22;
    QPushButton *pushButton_24;
    QPushButton *btn_cal_drive;
    QPushButton *btn_load_model;
    QPushButton *pushButton_27;
    QPushButton *btn_integral1;
    QPushButton *pushButton_32;
    QWidget *tab_4;
    QGraphicsView *graphicsView_2;
    QPushButton *btn_fresh;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_18;
    QLabel *label_10;
    QLineEdit *le_iterattion_cnt;
    QPushButton *pushButton_28;
    QPushButton *pushButton_29;
    QPushButton *pushButton_30;
    QPushButton *btn_integral2;
    QPushButton *pushButton_11;
    QPushButton *btn_load_model_2;
    QPushButton *pushButton_33;
    QLineEdit *le_learning_rate;
    QLabel *label_11;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *IterativeControlMainWindow)
    {
        if (IterativeControlMainWindow->objectName().isEmpty())
            IterativeControlMainWindow->setObjectName(QStringLiteral("IterativeControlMainWindow"));
        IterativeControlMainWindow->resize(1355, 876);
        centralwidget = new QWidget(IterativeControlMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_9 = new QHBoxLayout(tab);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_7->addWidget(lineEdit);

        btn_open = new QPushButton(tab);
        btn_open->setObjectName(QStringLiteral("btn_open"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_open->sizePolicy().hasHeightForWidth());
        btn_open->setSizePolicy(sizePolicy);
        btn_open->setMinimumSize(QSize(75, 25));
        btn_open->setMaximumSize(QSize(75, 25));
        btn_open->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout_7->addWidget(btn_open);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        btn_save = new QPushButton(tab);
        btn_save->setObjectName(QStringLiteral("btn_save"));
        sizePolicy.setHeightForWidth(btn_save->sizePolicy().hasHeightForWidth());
        btn_save->setSizePolicy(sizePolicy);
        btn_save->setMinimumSize(QSize(75, 25));
        btn_save->setMaximumSize(QSize(75, 25));
        btn_save->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout_7->addWidget(btn_save);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(240, 0));
        groupBox->setMaximumSize(QSize(240, 16777215));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableView_Acc = new QTableView(groupBox);
        tableView_Acc->setObjectName(QStringLiteral("tableView_Acc"));
        tableView_Acc->setMinimumSize(QSize(0, 0));
        tableView_Acc->setMaximumSize(QSize(300, 16777215));
        tableView_Acc->setStyleSheet(QStringLiteral(""));
        tableView_Acc->horizontalHeader()->setVisible(false);
        tableView_Acc->verticalHeader()->setVisible(false);

        horizontalLayout->addWidget(tableView_Acc);


        horizontalLayout_4->addWidget(groupBox);

        frame_Acc = new QFrame(tab);
        frame_Acc->setObjectName(QStringLiteral("frame_Acc"));
        frame_Acc->setFrameShape(QFrame::StyledPanel);
        frame_Acc->setFrameShadow(QFrame::Plain);

        horizontalLayout_4->addWidget(frame_Acc);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableView_Vel = new QTableView(groupBox_2);
        tableView_Vel->setObjectName(QStringLiteral("tableView_Vel"));
        tableView_Vel->setMaximumSize(QSize(220, 16777215));
        tableView_Vel->verticalHeader()->setVisible(false);

        horizontalLayout_2->addWidget(tableView_Vel);


        horizontalLayout_5->addWidget(groupBox_2);

        frame_Vel = new QFrame(tab);
        frame_Vel->setObjectName(QStringLiteral("frame_Vel"));
        frame_Vel->setFrameShape(QFrame::StyledPanel);
        frame_Vel->setFrameShadow(QFrame::Plain);

        horizontalLayout_5->addWidget(frame_Vel);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        tableView_Dis = new QTableView(groupBox_3);
        tableView_Dis->setObjectName(QStringLiteral("tableView_Dis"));
        tableView_Dis->setMaximumSize(QSize(220, 16777215));
        tableView_Dis->verticalHeader()->setVisible(false);

        horizontalLayout_3->addWidget(tableView_Dis);


        horizontalLayout_6->addWidget(groupBox_3);

        frame_Dis = new QFrame(tab);
        frame_Dis->setObjectName(QStringLiteral("frame_Dis"));
        frame_Dis->setFrameShape(QFrame::StyledPanel);
        frame_Dis->setFrameShadow(QFrame::Plain);

        horizontalLayout_6->addWidget(frame_Dis);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_3->addLayout(verticalLayout);


        horizontalLayout_9->addLayout(verticalLayout_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_12 = new QHBoxLayout(tab_2);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);

        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_10->addWidget(lineEdit_2);

        btn_open_2 = new QPushButton(tab_2);
        btn_open_2->setObjectName(QStringLiteral("btn_open_2"));
        sizePolicy.setHeightForWidth(btn_open_2->sizePolicy().hasHeightForWidth());
        btn_open_2->setSizePolicy(sizePolicy);
        btn_open_2->setMinimumSize(QSize(75, 25));
        btn_open_2->setMaximumSize(QSize(75, 25));
        btn_open_2->setStyleSheet(QLatin1String("QPushButton{\n"
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

        horizontalLayout_10->addWidget(btn_open_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        lab_origin_cnt = new QLabel(groupBox_4);
        lab_origin_cnt->setObjectName(QStringLiteral("lab_origin_cnt"));
        lab_origin_cnt->setGeometry(QRect(90, 90, 71, 21));
        lab_origin_cnt->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 9pt \"Agency FB\";\n"
"background-color: rgb(238, 255, 246);"));
        lab_origin_cnt->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(180, 60, 41, 21));
        label_15->setStyleSheet(QLatin1String("font: 10pt \"Agency FB\";\n"
"font: 14pt \"Agency FB\";"));
        label_15->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 90, 61, 21));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 60, 61, 16));
        lab_origin_sampleT = new QLabel(groupBox_4);
        lab_origin_sampleT->setObjectName(QStringLiteral("lab_origin_sampleT"));
        lab_origin_sampleT->setGeometry(QRect(90, 60, 71, 21));
        lab_origin_sampleT->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 9pt \"Agency FB\";\n"
"background-color: rgb(238, 255, 246);"));
        lab_origin_sampleT->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 100, 61, 21));
        lab_new_cnt = new QLabel(groupBox_5);
        lab_new_cnt->setObjectName(QStringLiteral("lab_new_cnt"));
        lab_new_cnt->setGeometry(QRect(100, 100, 71, 21));
        lab_new_cnt->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 9pt \"Agency FB\";\n"
"background-color: rgb(238, 255, 246);"));
        lab_new_cnt->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(20, 50, 61, 16));
        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(190, 50, 41, 21));
        label_16->setStyleSheet(QLatin1String("font: 10pt \"Agency FB\";\n"
"font: 14pt \"Agency FB\";"));
        label_16->setAlignment(Qt::AlignCenter);
        btn_resample = new QPushButton(groupBox_5);
        btn_resample->setObjectName(QStringLiteral("btn_resample"));
        btn_resample->setGeometry(QRect(30, 180, 75, 25));
        sizePolicy.setHeightForWidth(btn_resample->sizePolicy().hasHeightForWidth());
        btn_resample->setSizePolicy(sizePolicy);
        btn_resample->setMinimumSize(QSize(75, 25));
        btn_resample->setMaximumSize(QSize(75, 25));
        btn_resample->setStyleSheet(QLatin1String("QPushButton{\n"
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
        btn_resample_save = new QPushButton(groupBox_5);
        btn_resample_save->setObjectName(QStringLiteral("btn_resample_save"));
        btn_resample_save->setGeometry(QRect(170, 180, 75, 25));
        sizePolicy.setHeightForWidth(btn_resample_save->sizePolicy().hasHeightForWidth());
        btn_resample_save->setSizePolicy(sizePolicy);
        btn_resample_save->setMinimumSize(QSize(75, 25));
        btn_resample_save->setMaximumSize(QSize(75, 25));
        btn_resample_save->setStyleSheet(QLatin1String("QPushButton{\n"
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
        le_new_sample = new QLineEdit(groupBox_5);
        le_new_sample->setObjectName(QStringLiteral("le_new_sample"));
        le_new_sample->setGeometry(QRect(100, 50, 81, 20));

        verticalLayout_2->addWidget(groupBox_5);


        horizontalLayout_11->addLayout(verticalLayout_2);

        frame_Acc_2 = new QFrame(tab_2);
        frame_Acc_2->setObjectName(QStringLiteral("frame_Acc_2"));
        frame_Acc_2->setFrameShape(QFrame::StyledPanel);
        frame_Acc_2->setFrameShadow(QFrame::Plain);
        horizontalLayout_13 = new QHBoxLayout(frame_Acc_2);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));

        horizontalLayout_11->addWidget(frame_Acc_2);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 4);

        verticalLayout_4->addLayout(horizontalLayout_11);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 9);

        horizontalLayout_12->addLayout(verticalLayout_4);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        graphicsView = new QGraphicsView(tab_3);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 701, 461));
        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 120, 81, 61));
        pushButton->setStyleSheet(QLatin1String("QPushButton{\n"
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
        pushButton_2 = new QPushButton(tab_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(570, 120, 81, 61));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{\n"
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
        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 310, 81, 61));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton{\n"
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
        btn_model_save = new QPushButton(tab_3);
        btn_model_save->setObjectName(QStringLiteral("btn_model_save"));
        btn_model_save->setGeometry(QRect(560, 300, 81, 61));
        btn_model_save->setStyleSheet(QLatin1String("QPushButton{\n"
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
        pushButton_5 = new QPushButton(tab_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(300, 90, 111, 111));
        pushButton_5->setStyleSheet(QStringLiteral("border-image:url(:Icon/Icon/controlpanel.png);"));
        pushButton_6 = new QPushButton(tab_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(160, 130, 121, 31));
        pushButton_6->setStyleSheet(QStringLiteral("border-image:url(:Icon/Icon/borderrightarrow.png);"));
        pushButton_7 = new QPushButton(tab_3);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(430, 130, 121, 31));
        pushButton_7->setStyleSheet(QStringLiteral("border-image:url(:Icon/Icon/borderleftarrow.png);"));
        pushButton_8 = new QPushButton(tab_3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(410, 320, 121, 31));
        pushButton_8->setStyleSheet(QStringLiteral("border-image:url(:Icon/Icon/borderrightarrow.png);"));
        pushButton_9 = new QPushButton(tab_3);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(340, 210, 41, 91));
        pushButton_9->setStyleSheet(QStringLiteral("border-image:url(:Icon/Icon/borderdownarrow.png);"));
        le_nfft = new QLineEdit(tab_3);
        le_nfft->setObjectName(QStringLiteral("le_nfft"));
        le_nfft->setGeometry(QRect(110, 20, 113, 20));
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 54, 12));
        tabWidget->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        graphicsView_3 = new QGraphicsView(tab_5);
        graphicsView_3->setObjectName(QStringLiteral("graphicsView_3"));
        graphicsView_3->setGeometry(QRect(0, 0, 691, 471));
        graphicsView_3->setStyleSheet(QStringLiteral(""));
        btn_load_yd = new QPushButton(tab_5);
        btn_load_yd->setObjectName(QStringLiteral("btn_load_yd"));
        btn_load_yd->setGeometry(QRect(30, 110, 81, 61));
        btn_load_yd->setStyleSheet(QLatin1String("QPushButton{\n"
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
        pushButton_25 = new QPushButton(tab_5);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        pushButton_25->setGeometry(QRect(140, 120, 121, 31));
        pushButton_25->setStyleSheet(QStringLiteral("border-image:url(:Icon/Icon/borderrightarrow.png);"));
        pushButton_22 = new QPushButton(tab_5);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setGeometry(QRect(280, 80, 111, 111));
        pushButton_22->setStyleSheet(QStringLiteral("border-image:url(:Icon/Icon/controlpanel.png);"));
        pushButton_24 = new QPushButton(tab_5);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        pushButton_24->setGeometry(QRect(320, 200, 41, 91));
        pushButton_24->setStyleSheet(QStringLiteral("border-image:url(:Icon/Icon/borderdownarrow.png);"));
        btn_cal_drive = new QPushButton(tab_5);
        btn_cal_drive->setObjectName(QStringLiteral("btn_cal_drive"));
        btn_cal_drive->setGeometry(QRect(290, 300, 81, 61));
        btn_cal_drive->setStyleSheet(QLatin1String("QPushButton{\n"
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
        btn_load_model = new QPushButton(tab_5);
        btn_load_model->setObjectName(QStringLiteral("btn_load_model"));
        btn_load_model->setGeometry(QRect(570, 110, 81, 61));
        btn_load_model->setStyleSheet(QLatin1String("QPushButton{\n"
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
        pushButton_27 = new QPushButton(tab_5);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        pushButton_27->setGeometry(QRect(430, 120, 121, 31));
        pushButton_27->setStyleSheet(QStringLiteral("border-image:url(:Icon/Icon/borderleftarrow.png);"));
        btn_integral1 = new QPushButton(tab_5);
        btn_integral1->setObjectName(QStringLiteral("btn_integral1"));
        btn_integral1->setGeometry(QRect(580, 290, 81, 61));
        btn_integral1->setStyleSheet(QLatin1String("QPushButton{\n"
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
        pushButton_32 = new QPushButton(tab_5);
        pushButton_32->setObjectName(QStringLiteral("pushButton_32"));
        pushButton_32->setGeometry(QRect(430, 310, 121, 31));
        pushButton_32->setStyleSheet(QStringLiteral("border-image:url(:Icon/Icon/borderrightarrow.png);"));
        tabWidget->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        graphicsView_2 = new QGraphicsView(tab_4);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(0, 0, 701, 471));
        graphicsView_2->setStyleSheet(QStringLiteral(""));
        btn_fresh = new QPushButton(tab_4);
        btn_fresh->setObjectName(QStringLiteral("btn_fresh"));
        btn_fresh->setGeometry(QRect(590, 40, 61, 31));
        btn_fresh->setStyleSheet(QLatin1String("QPushButton{\n"
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
        pushButton_12 = new QPushButton(tab_4);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(310, 290, 41, 91));
        pushButton_12->setStyleSheet(QStringLiteral("border-image:url(:Icon/Icon/borderdownarrow.png);"));
        pushButton_13 = new QPushButton(tab_4);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(270, 170, 111, 111));
        pushButton_13->setStyleSheet(QStringLiteral("border-image:url(:Icon/Icon/controlpanel.png);"));
        pushButton_14 = new QPushButton(tab_4);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(250, 10, 81, 61));
        pushButton_14->setStyleSheet(QLatin1String("QPushButton{\n"
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
        pushButton_15 = new QPushButton(tab_4);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(280, 380, 81, 61));
        pushButton_15->setStyleSheet(QLatin1String("QPushButton{\n"
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
        pushButton_16 = new QPushButton(tab_4);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(550, 190, 91, 51));
        pushButton_16->setStyleSheet(QLatin1String("QPushButton{\n"
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
        pushButton_18 = new QPushButton(tab_4);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(140, 200, 121, 31));
        pushButton_18->setStyleSheet(QStringLiteral("border-image:url(:Icon/Icon/borderrightarrow.png);"));
        label_10 = new QLabel(tab_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 20, 121, 31));
        label_10->setStyleSheet(QStringLiteral("font: 12pt \"Agency FB\";"));
        le_iterattion_cnt = new QLineEdit(tab_4);
        le_iterattion_cnt->setObjectName(QStringLiteral("le_iterattion_cnt"));
        le_iterattion_cnt->setGeometry(QRect(110, 25, 113, 20));
        le_iterattion_cnt->setAlignment(Qt::AlignCenter);
        pushButton_28 = new QPushButton(tab_4);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        pushButton_28->setGeometry(QRect(40, 190, 101, 51));
        pushButton_28->setStyleSheet(QLatin1String("QPushButton{\n"
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
        pushButton_29 = new QPushButton(tab_4);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));
        pushButton_29->setGeometry(QRect(290, 80, 41, 91));
        pushButton_29->setStyleSheet(QStringLiteral("border-image:url(:Icon/Icon/borderdownarrow.png);"));
        pushButton_30 = new QPushButton(tab_4);
        pushButton_30->setObjectName(QStringLiteral("pushButton_30"));
        pushButton_30->setGeometry(QRect(400, 390, 121, 31));
        pushButton_30->setStyleSheet(QStringLiteral("border-image:url(:Icon/Icon/borderrightarrow.png);"));
        btn_integral2 = new QPushButton(tab_4);
        btn_integral2->setObjectName(QStringLiteral("btn_integral2"));
        btn_integral2->setGeometry(QRect(550, 370, 81, 61));
        btn_integral2->setStyleSheet(QLatin1String("QPushButton{\n"
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
        pushButton_11 = new QPushButton(tab_4);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(410, 200, 121, 31));
        pushButton_11->setStyleSheet(QStringLiteral("border-image:url(:Icon/Icon/borderleftarrow.png);"));
        btn_load_model_2 = new QPushButton(tab_4);
        btn_load_model_2->setObjectName(QStringLiteral("btn_load_model_2"));
        btn_load_model_2->setGeometry(QRect(340, 10, 81, 61));
        btn_load_model_2->setStyleSheet(QLatin1String("QPushButton{\n"
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
        pushButton_33 = new QPushButton(tab_4);
        pushButton_33->setObjectName(QStringLiteral("pushButton_33"));
        pushButton_33->setGeometry(QRect(350, 80, 41, 91));
        pushButton_33->setStyleSheet(QStringLiteral("border-image:url(:Icon/Icon/borderdownarrow.png);"));
        le_learning_rate = new QLineEdit(tab_4);
        le_learning_rate->setObjectName(QStringLiteral("le_learning_rate"));
        le_learning_rate->setGeometry(QRect(110, 70, 113, 20));
        le_learning_rate->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(tab_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 60, 71, 31));
        label_11->setStyleSheet(QStringLiteral("font: 12pt \"Agency FB\";"));
        tabWidget->addTab(tab_4, QString());

        verticalLayout_5->addWidget(tabWidget);

        IterativeControlMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(IterativeControlMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1355, 23));
        IterativeControlMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(IterativeControlMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        IterativeControlMainWindow->setStatusBar(statusbar);

        retranslateUi(IterativeControlMainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(IterativeControlMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *IterativeControlMainWindow)
    {
        IterativeControlMainWindow->setWindowTitle(QApplication::translate("IterativeControlMainWindow", "\350\277\255\344\273\243\346\216\247\345\210\266\345\217\260", 0));
        btn_open->setText(QApplication::translate("IterativeControlMainWindow", "\346\265\217\350\247\210", 0));
        btn_save->setText(QApplication::translate("IterativeControlMainWindow", "\344\277\235\345\255\230", 0));
        groupBox->setTitle(QApplication::translate("IterativeControlMainWindow", "\345\212\240\351\200\237\345\272\246", 0));
        groupBox_2->setTitle(QApplication::translate("IterativeControlMainWindow", "\351\200\237\345\272\246", 0));
        groupBox_3->setTitle(QApplication::translate("IterativeControlMainWindow", "\344\275\215\347\247\273", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("IterativeControlMainWindow", "\345\234\260\351\234\207\346\263\242\347\247\257\345\210\206", 0));
        btn_open_2->setText(QApplication::translate("IterativeControlMainWindow", "\346\265\217\350\247\210", 0));
        groupBox_4->setTitle(QApplication::translate("IterativeControlMainWindow", "\345\216\237\345\247\213\345\234\260\351\234\207\346\263\242", 0));
        lab_origin_cnt->setText(QString());
        label_15->setText(QApplication::translate("IterativeControlMainWindow", "ms", 0));
        label_13->setText(QApplication::translate("IterativeControlMainWindow", "\351\207\207\346\240\267\347\202\271\346\225\260\357\274\232", 0));
        label_12->setText(QApplication::translate("IterativeControlMainWindow", "\351\207\207\346\240\267\345\221\250\346\234\237\357\274\232", 0));
        lab_origin_sampleT->setText(QString());
        groupBox_5->setTitle(QApplication::translate("IterativeControlMainWindow", "\346\217\222\345\200\274\345\220\216", 0));
        label_14->setText(QApplication::translate("IterativeControlMainWindow", "\351\207\207\346\240\267\347\202\271\346\225\260\357\274\232", 0));
        lab_new_cnt->setText(QString());
        label_17->setText(QApplication::translate("IterativeControlMainWindow", "\351\207\207\346\240\267\345\221\250\346\234\237\357\274\232", 0));
        label_16->setText(QApplication::translate("IterativeControlMainWindow", "ms", 0));
        btn_resample->setText(QApplication::translate("IterativeControlMainWindow", "\346\217\222\345\200\274", 0));
        btn_resample_save->setText(QApplication::translate("IterativeControlMainWindow", "\344\277\235\345\255\230", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("IterativeControlMainWindow", "\346\217\222\345\200\274\351\242\204\345\244\204\347\220\206", 0));
        pushButton->setText(QApplication::translate("IterativeControlMainWindow", "\350\275\275\345\205\245\346\277\200\345\212\261\344\277\241\345\217\267", 0));
        pushButton_2->setText(QApplication::translate("IterativeControlMainWindow", "\350\257\273\345\217\226\345\223\215\345\272\224\344\277\241\345\217\267", 0));
        pushButton_3->setText(QApplication::translate("IterativeControlMainWindow", "\350\256\241\347\256\227\351\242\221\345\223\215\345\207\275\346\225\260", 0));
        btn_model_save->setText(QApplication::translate("IterativeControlMainWindow", "\344\277\235\345\255\230\347\263\273\347\273\237\346\250\241\345\236\213", 0));
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        le_nfft->setText(QApplication::translate("IterativeControlMainWindow", "1024", 0));
        label->setText(QApplication::translate("IterativeControlMainWindow", "\350\260\261\347\272\277\346\225\260\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("IterativeControlMainWindow", "\347\263\273\347\273\237\350\276\250\350\257\206", 0));
        btn_load_yd->setText(QApplication::translate("IterativeControlMainWindow", "\350\275\275\345\205\245\346\234\237\346\234\233\346\263\242\345\275\242", 0));
        pushButton_25->setText(QString());
        pushButton_22->setText(QString());
        pushButton_24->setText(QString());
        btn_cal_drive->setText(QApplication::translate("IterativeControlMainWindow", "\350\256\241\347\256\227\351\251\261\345\212\250\344\277\241\345\217\267", 0));
        btn_load_model->setText(QApplication::translate("IterativeControlMainWindow", "\350\257\273\345\217\226\351\242\221\345\237\237\345\223\215\345\272\224", 0));
        pushButton_27->setText(QString());
        btn_integral1->setText(QApplication::translate("IterativeControlMainWindow", "\351\242\221\345\237\237\347\247\257\345\210\206", 0));
        pushButton_32->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("IterativeControlMainWindow", "\347\233\264\351\200\232\346\250\241\345\274\217", 0));
        btn_fresh->setText(QApplication::translate("IterativeControlMainWindow", "\345\210\267\346\226\260", 0));
        pushButton_12->setText(QString());
        pushButton_13->setText(QString());
        pushButton_14->setText(QApplication::translate("IterativeControlMainWindow", "\350\275\275\345\205\245\346\234\237\346\234\233\346\263\242\345\275\242", 0));
        pushButton_15->setText(QApplication::translate("IterativeControlMainWindow", "\350\256\241\347\256\227\351\251\261\345\212\250\344\277\241\345\217\267", 0));
        pushButton_16->setText(QApplication::translate("IterativeControlMainWindow", "\345\223\215\345\272\224\344\277\241\345\217\267", 0));
        pushButton_18->setText(QString());
        label_10->setText(QApplication::translate("IterativeControlMainWindow", "\345\275\223\345\211\215\350\277\255\344\273\243\346\254\241\346\225\260", 0));
        le_iterattion_cnt->setText(QApplication::translate("IterativeControlMainWindow", "0", 0));
        pushButton_28->setText(QApplication::translate("IterativeControlMainWindow", "\345\211\215\344\270\200\346\254\241\351\251\261\345\212\250\344\277\241\345\217\267", 0));
        pushButton_29->setText(QString());
        pushButton_30->setText(QString());
        btn_integral2->setText(QApplication::translate("IterativeControlMainWindow", "\351\242\221\345\237\237\347\247\257\345\210\206", 0));
        pushButton_11->setText(QString());
        btn_load_model_2->setText(QApplication::translate("IterativeControlMainWindow", "\350\257\273\345\217\226\351\242\221\345\237\237\345\223\215\345\272\224", 0));
        pushButton_33->setText(QString());
        le_learning_rate->setText(QApplication::translate("IterativeControlMainWindow", "0.1", 0));
        label_11->setText(QApplication::translate("IterativeControlMainWindow", "Alpha", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("IterativeControlMainWindow", "\350\277\255\344\273\243\346\250\241\345\274\217", 0));
    } // retranslateUi

};

namespace Ui {
    class IterativeControlMainWindow: public Ui_IterativeControlMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITERATIVECONTROLMAINWINDOW_H

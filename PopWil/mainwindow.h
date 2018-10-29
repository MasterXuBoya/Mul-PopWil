#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stdio.h"
#include <QObject>
#include <string>
#include <QMainWindow>
#include <QDialog>
#include <QDateTime>
#include <QTimer>
#include <QLabel>
#include <QScrollbar>
#include "qchartviewer.h"
#include "qdoublebufferedqueue.h"
#include "bdaqctrl.h"
#include "configuredialog.h"
#include "performancetimer.h"
#include "QStandardItemModel"
#include "qstring.h"
#include "logger.h"
#include "aiinstant.h"
#include "aoinstant.h"
#include <QCloseEvent>
#include <QApplication>
#include <QButtonGroup>
#include <QIcon>
#include <QPushButton>
#include <QComboBox>
#include <QFileDialog>
#include "chartdir.h"
#include <math.h>
#include <vector>
#include <sstream>
#include "qdebug.h"
#include "QTime"
#include "qmessagebox.h"
#include "aboutform.h"
#include "qdesktopservices.h"
#include <QProcess>
#include "Enc7480.h"
#include "qmath.h"
#include "inihelper.h"
#include "ctrldialog.h"
#include "rbf.h"
#include "systemsettings.h"
#include "QStandardItem"
#include "mathtool.h"
//#include "QtXlsx"
#include "signalprocess.h"
#include "constvar.h"
#include <QTextCodec>
#include <QTextStream>
#include "doinstant.h"
#include "aistreaming.h"
#include "mychartviewer.h"
#include "staticpositioncontroller.h"
#include <vector>
#include "AVGFilter.h"
#include "ButtorFilter.h"
#include "PIDController.h"

using namespace Automation::BDaq;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow//当前窗体继承自系统自带QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //------------------------PCI1716---------------------------------
    void SetConfigureParameterAI(ConfigureParameterAI value){this->configureAI = value;}
    void SetConfigureParameterAO(ConfigureParameterAO value){this->configureAO = value;}
    //------------------------文件操作------------------------------
    void addItemToListView(QString str);
    void dataSaveToTxt();
    void closeEvent(QCloseEvent *event);
    double getPosition(int direct);

private:
    Ui::MainWindow *ui;
    bool startFlag;//开始按钮点击标志

    QString dataSaveBasePath;//试验数据保存位置
    QString log;//临时变量，需要保存的日志信息，在此处定义，主要是不需要再每个函数中分别定义
    Logger *logger;//日志
    //------------------------PCI1716------------------------------------
    DoInstant *doInstant;
    AoInstant *aoInstant;//输出电压控制柄
    AiInstant *aiInstant;
    ConfigureParameterAO configureAO;//AO,InstantAi,InstantDo输出配置

    AiStreaming *aiStreaming;
    ConfigureParameterAI configureAI;//AI输入配置    
    //-------------------------滤波器-------------------------------------
    AvgFilter *sAvgFilter,*vAvgFilter,*aAvgFilter;
    ButtorFilter *sButtorFilter,*vButtorFilter,*aButtorFilter;
    //---------------------控制器---------------------------------------------
    long msCount;//从打开程序开启的总时间   ms
    long msStartCount;//点击开始后的时间   ms
    int refIndex;//Reference中的索引

    StaticPositionController *sController;
    PIDController *sinePIDController;//正弦波PID控制器
    PIDController *earthquakePIDController;//地震波PID控制器

    PerformanceTimer *timer;
    int PERFORMANCEINTERVAL;
    //------------------------动态绘图---------------------------------------------
    MyChartViewer *dPlot;
    QChartViewer *m_ChartViewer;
    //------------------------UI---------------------------------------------
    QLabel *currentLabel;
    QStandardItemModel *model;

    void outUToPCI(double value);
    void outDataToExcel();
    void testFunction();
private slots:
    void slotFuction();     //1ms多媒体定时器
    void on_action_Quit_triggered();
    void on_action_ToolFlag_triggered();
    void on_action_StatusFlag_triggered();
    void on_action_About_triggered();
    void on_action_HelpF1_triggered();
    void on_btnStart_clicked();
    void on_action_ChannelParameters_triggered();
    void on_btnStop_clicked();
    void on_action_ControlParameters_triggered();
    void on_action_SaveAsDefalut_triggered();
    void on_action_Identity_triggered();
    void on_actionAction_SystemSettings_triggered();
    void on_btn_clearZero_clicked();
    void on_btn_static_comfirm_clicked();
    void on_btn_DO_clicked();
    void on_action_Pointer_triggered();//pointer,zoomIn,zoomOut按钮
    void on_action_ZoomIn_triggered();
    void on_action_ZoomOut_triggered();
    void on_btn_out_uk_clicked();
    void on_btn_sine_load_clicked();
    void on_btn_preview_earth_clicked();
};
#endif // MAINWINDOW_H


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "popwilheader.h"

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
    void changeEvent(QEvent *event);
    double getPosition(int direct);
    void wavePreview(QString title);
    void drawTmp(QString title,int n,double xlabel[],double data[]);

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
    //---------------------信号发生器---------------------------
    Oscilator oscilator;
    SineSweepModule sineSweepForm;
    //-------------------------滤波器-------------------------------------
    int m_filter_length;
    AvgFilter *sAvgFilter,*vAvgFilter,*aAvgFilter;
    AvgFilter *sAvgFilterThreeFreedom;
    HMAFilter *sHMAFilter,*vHMAFilter,*aHMAFilter;

    ButtorFilter *sButtorFilter,*vButtorFilter,*aButtorFilter;
    AvgFilter v2AvgFilter,a2AvgFilter;
    ButtorFilter v2ButtorFilter,a2ButtorFilter;
    SignalProcess signalHandler;//fft,频域积分
    double sCurrentThreeFreedom[DISSENSORCOUNT];
    //---------------------控制器---------------------------------------------
    long msCount;//从打开程序开启的总时间   ms
    //-------试验开始之后变量----------------
    long msStartCount,msStartCount_Ref;//点击开始后的时间   ms
    double elapseStartTime;
    int refIndex;//Reference中的索引

    StaticPositionController *sController;
    PIDController *sinePIDController;//位移PID控制器
    PIDController *sinePIDControllerThreeFreedom;
    PIDController *accPIDController;//加速度PID控制器
    //PIDController *earthquakePIDController;//地震波PID控制器
    TVController *tvcController;
    PID3Controller *pid3Controller;

    PerformanceTimer *timer;
    int PERFORMANCEINTERVAL;
    //------------------------动态绘图---------------------------------------------
    MyChartViewer *dPlot;
    QChartViewer *m_ChartViewer;

    DisplayBuffer sDisplayBuffer,vDisplayBuffer,aDisplayBuffer;
    //------------------------UI---------------------------------------------
    QLabel *currentLabel;
    QStandardItemModel *model;
    IterativeControlMainWindow *iterativeControlUI;
    calibration *calibrationDialog;

    QTranslator *englishTranslator;

    void outUToPCI(double value);
    void outUToPCI(double value[DISSENSORCOUNT]);
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
    void on_action_SystemSettings_triggered();
    void on_btn_clearZero_clicked();
    void on_btn_static_comfirm_clicked();
    void on_btn_DO_clicked();
    void on_action_Pointer_triggered();//pointer,zoomIn,zoomOut按钮
    void on_action_ZoomIn_triggered();
    void on_action_ZoomOut_triggered();
    void on_btn_out_uk_clicked();
    void on_btn_sine_load_clicked();
    void on_cmb_contr_method_currentIndexChanged(int index);
    void on_tabWidget_controller_currentChanged(int index);
    void on_btn_load_clicked();
    void on_listWidget_waveMode_currentRowChanged(int currentRow);
    void on_btn_preview_clicked();
    void on_btn_sineswep_config_clicked();
    void on_btn_sineSweep_open_clicked();
    void on_action_DrawDelay_triggered();
    void on_rbt_S_plot_clicked();
    void on_rbt_V_plot_clicked();
    void on_rbt_A_plot_clicked();
    void on_action_IterativeControl_triggered();
    void on_action_Calibration_triggered();
    void on_action_SaveAsPicture_triggered();
    void on_action_Chinese_triggered();
    void on_action_English_triggered();
    void refreshUI();
    void on_btn_out_uk_2_clicked();
    void on_btn_out_uk_3_clicked();
};
#endif // MAINWINDOW_H


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QDateTime>
#include <QTimer>
#include <QLabel>
#include <QScrollbar>
#include "qchartviewer.h"
#include "qdoublebufferedqueue.h"
#include "randomwalk.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // The random data source
    RandomWalk *dataSource;

    // Handles callback from the RandomWalk
    static void OnData(void *self, double elapsedTime, double series0, double series1);

    // A thread-safe queue with minimal read/write contention
    struct DataPacket
    {
        double elapsedTime;
        double series0;
        double series1;
    };
    QDoubleBufferedQueue<DataPacket> buffer;//每组数据有三个

    // The number of samples per data series used in this demo
    //显示缓冲区的图像大小
    static const int sampleSize = 10000;

    // The full range is initialized to 180 seconds. It will extend when more data are available.
    static const int initialFullRange = 180;

    // The visible range is initialized to 30 seconds.
    //视野中可视化的秒数，非常重要的一个量
    static const int initialVisibleRange = 5;

    // The maximum zoom in is 5 seconds.
    static const int zoomInLimit = 5;
    long msCount;
    QFrame *leftFrame;
    QLabel *currentLabel;


    // If the track cursor is at the end of the data series, we will automatic move the track
    // line when new data arrives.
    double trackLineEndPos;
    bool trackLineIsAtEnd;

    double m_timeStamps[sampleSize];        // The timestamps for the data series
    double m_dataSeriesA[sampleSize];       // The values for the data series A
    double m_dataSeriesB[sampleSize];       // The values for the data series B

    int m_currentIndex;                     // Index of the array position to which new values are added.

    QChartViewer *m_ChartViewer;            // QChartViewer control
    //QViewPortControl *m_ViewPortControl;    // QViewPortControl
    QTimer *m_ChartUpdateTimer;             // The chart update timer

    void drawChart(QChartViewer *viewer);           // Draw chart
    void drawFullChart(QViewPortControl *vpc);      // Draw full chart
    double trackLineLabel(XYChart *c, int mouseX);  // Draw track cursor


private slots:
    void onMouseUsageChanged(int mouseUsage);       // Pointer/zoom in/zoom out button clicked
    void onSave(bool);                              // Save button clicked
    void onMouseMovePlotArea(QMouseEvent *event);   // Mouse move on plot area
    void onChartUpdateTimer();                      // Update the chart.
    void onViewPortChanged();                       // Viewport has changed
    void slotFuction();     //100ms多媒体定时器
    void on_action_Quit_triggered();
    void on_action_ToolFlag_triggered();
    void on_action_StatusFlag_triggered();
    void on_action_About_triggered();
    void on_action_HelpF1_triggered();
    void on_btnStart_clicked();
};
#endif // MAINWINDOW_H


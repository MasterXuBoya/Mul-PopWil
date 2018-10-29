#ifndef MYCHARTVIEWER_H
#define MYCHARTVIEWER_H

#include <QObject>
#include <qchartviewer.h>
#include <QTimer>
#include <QDebug>
#include <QString>
#include "constvar.h"
#include <sstream>
#include <QFileDialog>

class MyChartViewer : public QObject
{
    Q_OBJECT
public:
    explicit MyChartViewer(QObject *parent = 0);
    virtual ~MyChartViewer();
    void start();
    void stop();
private:
    // The number of samples per data series used in this demo
   //显示缓冲区的图像大小
   static const int sampleSize = 500;
   // The full range is initialized to 180 seconds. It will extend when more data are available.
   static const int initialFullRange = 30;
   // The visible range is initialized to 30 seconds.
   //视野中可视化的秒数，非常重要的一个量
   static const int initialVisibleRange = 10;
   // The maximum zoom in is 5 seconds.
   static const int zoomInLimit = 1;

   // If the track cursor is at the end of the data series, we will automatic move the track
   // line when new data arrives.
   double trackLineEndPos;
   bool trackLineIsAtEnd;

   double m_timeStamps[sampleSize];        // The timestamps for the data series
   double m_dataSeriesA[sampleSize];       // The values for the data series A
   double m_dataSeriesB[sampleSize];       // The values for the data series B

   int m_currentIndex;                     // Index of the array position to which new values are added.

   QChartViewer *m_ChartViewer;            // QChartViewer control
   QViewPortControl *m_ViewPortControl;    // QViewPortControl
   QTimer *m_ChartUpdateTimer;             // The chart update timer

   void drawChart(QChartViewer *viewer);           // Draw chart
   void drawFullChart(QViewPortControl *vpc);      // Draw full chart
   double trackLineLabel(XYChart *c, int mouseX);  // Draw track cursor
signals:

public slots:
   void onMouseUsageChanged(int mouseUsage);       // Pointer/zoom in/zoom out button clicked
   void onSave(bool);                              // Save button clicked
   void onMouseMovePlotArea(QMouseEvent *event);   // Mouse move on plot area
   void onChartUpdateTimer();                      // Update the chart.
   void onViewPortChanged();                       // Viewport has changed
};

#endif // MYCHARTVIEWER_H

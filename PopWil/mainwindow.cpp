#include "mainwindow.h"
#include "ui_mainwindow.h"

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
#include "performancetimer.h"
#include "qdebug.h"
#include "QTime"
#include "qdatetime.h"
#include "qmessagebox.h"
#include "aboutform.h"
#include "qdesktopservices.h"
#include <QProcess>
#include "Enc7480.h"
#include "qmath.h"
#include "bdaqctrl.h"
#include "configuredialog.h"

using namespace std;
using namespace Automation::BDaq;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//******************************总体布局***************************************************************
    /*
    QWidget *widget = new QWidget();
    this->setCentralWidget(widget);
    widget->setLayout(ui->mainGridLayout);
    */
    setFixedSize(900, 600);
//*********************************************************************************************

    // Pointer push button
    QPushButton *pointerPB = new QPushButton();
    // Zoom In push button
    QPushButton *zoomInPB = new QPushButton();
    // Zoom Out push button
    QPushButton *zoomOutPB = new QPushButton();
    //Save as Picture
    connect(ui->action_SaveAsPicture, SIGNAL(triggered(bool)), SLOT(onSave(bool)));

    pointerPB->setVisible(false);
    zoomInPB->setVisible(false);
    zoomOutPB->setVisible(false);

    // The Pointer/Zoom In/Zoom Out buttons form a button group
    QButtonGroup *mouseUsage = new QButtonGroup();

    mouseUsage->addButton(pointerPB, Chart::MouseUsageScroll);
    mouseUsage->addButton(zoomInPB, Chart::MouseUsageZoomIn);
    mouseUsage->addButton(zoomOutPB, Chart::MouseUsageZoomOut);


    connect(mouseUsage, SIGNAL(buttonPressed(int)), SLOT(onMouseUsageChanged(int)));

    connect(ui->action_Pointer,SIGNAL(triggered()),pointerPB,SLOT(click()));
    connect(ui->action_ZoomIn,SIGNAL(triggered()),zoomInPB,SLOT(click()));
    connect(ui->action_ZoomOut,SIGNAL(triggered()),zoomOutPB,SLOT(click()));

    //这是右边一整块，包括上下两部分
//******************************实时曲线绘制UI----LeftFrame***************************************************************
    leftFrame = new QFrame(this);
    leftFrame->setGeometry(4, 62, 660, 500);

    leftFrame->setStyleSheet("background-color:white");

    // Chart Viewer
    m_ChartViewer = new QChartViewer(leftFrame);
    m_ChartViewer->setGeometry(10, 25, 640, 480);
    connect(m_ChartViewer, SIGNAL(viewPortChanged()), SLOT(onViewPortChanged()));
    connect(m_ChartViewer, SIGNAL(mouseMovePlotArea(QMouseEvent*)),
        SLOT(onMouseMovePlotArea(QMouseEvent*)));
//***************************控制---RightFrame******************************************************************************
    ui->labeStatusl->setStyleSheet("font:bold;font-size:12px;background-color:#7FFFD4");
    ui->labeStatusl_2->setStyleSheet("font:bold;font-size:12px;background-color:#7FFFD4");

//*********************************状态栏************************************************************
    currentLabel=new QLabel;
    currentLabel->setMinimumSize(200,25);
    //currentLabel->setFrameShadow(QFrame::Sunken);
    currentLabel->setFrameShape(QFrame::WinPanel);


    ui->statusBar->addWidget(currentLabel);
//********************************颜色样式************************************************************
    setWindowIcon(QPixmap(":/Icon/Icon/dashboard.png"));

    ui->menuBar->setStyleSheet("background-color:#EEE9E9");
    ui->toolBar->setStyleSheet("background-color:#C0C0C0");
    ui->statusBar->setStyleSheet("background-color:#CCFFFF");
    //leftFrame->setStyleSheet(QString::fromUtf8("border:1px solid red"));

//********************************ENC7480****************************************************************
    int d7480rtn= Enc7480_Init();
    qDebug()<<"leisai number:"<<d7480rtn;
    if(d7480rtn < 1)
    {
        qDebug()<<"初始化ENC7480计数卡失败!";
        QMessageBox::information(NULL,"提示","初始化ENC7480计数卡失败",QMessageBox::Ok|QMessageBox::Cancel);
        this->close();
    }
    Enc7480_Set_Encoder(0,0);
//**********************************PCI1716初始化************************************************************
    instantAoCtrl = InstantAoCtrl::Create();

    startFlag=false;
    dataScaled[0]=0;
    dataScaled[1]=0;

//*********************************参数初始化************************************************************

    //
    // Initialize member variables
    //
    m_currentIndex = 0;

    // Initially, auto-move the track line to make it follow the data series
    trackLineEndPos = 0;
    trackLineIsAtEnd = true;

    // Initially set the mouse to drag to scroll mode.
    pointerPB->click();

    // Enable mouse wheel zooming by setting the zoom ratio to 1.1 per wheel event
    m_ChartViewer->setMouseWheelZoomRatio(1.1);

    // Configure the initial viewport
    m_ChartViewer->setViewPortWidth(initialVisibleRange / (double)initialFullRange);

    // Start the random data generator
    //dataSource = new RandomWalk(OnData, this);
    //dataSource->start();

    // Set up the chart update timer
    m_ChartUpdateTimer = new QTimer(this);
    connect(m_ChartUpdateTimer, SIGNAL(timeout()), SLOT(onChartUpdateTimer()));

    // The chart update rate is set to 100ms
    m_ChartUpdateTimer->start(100);

    PerformanceTimer *timer=new PerformanceTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(slotFuction()));
    timer->start(10);  //20为毫秒
    msCount=0;

}

MainWindow::~MainWindow()
{
    Enc7480_Close();
    delete m_ChartViewer->getChart();
    //delete m_ViewPortControl->getChart();
    delete dataSource;
    delete ui;
}

void MainWindow::Initialize() {
    ErrorCode errorCode = Success;
    std::wstring description = configureAO.deviceName.toStdWString();
    DeviceInformation selected(description.c_str());
    this->setWindowTitle(tr("Static AO - Run(") + configureAO.deviceName + tr(")"));
    errorCode = instantAoCtrl->setSelectedDevice(selected);
    CheckError(errorCode);
    for (int i = 0; i < instantAoCtrl->getChannels()->getCount(); i++) {
        errorCode = instantAoCtrl->getChannels()->getItem(i).setValueRange(configureAO.valueRange);
        CheckError(errorCode);
    }

}

void MainWindow::CheckError(ErrorCode errorCode)
{
    if (BioFailed(errorCode)) {
        QString message = tr("Sorry, there are some errors occurred, Error Code: 0x") +
            QString::number(errorCode, 16).right(8).toUpper();
        QMessageBox::information(this, "Warning Information", message);
    }
}

//
// The Pointer, Zoom In or Zoom out button is pressed
//
void MainWindow::onMouseUsageChanged(int mouseUsage)
{
    m_ChartViewer->setMouseUsage(mouseUsage);
}

//
// The Save button is pressed
//
void MainWindow::onSave(bool)
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save", "chartdirector_demo",
        "PNG (*.png);;JPG (*.jpg);;GIF (*.gif);;BMP (*.bmp);;SVG (*.svg);;PDF (*.pdf)");

    if (!fileName.isEmpty())
    {
        // Save the chart
        BaseChart *c = m_ChartViewer->getChart();
        if (0 != c)
            c->makeChart(fileName.toUtf8().constData());
    }
}

//
// Handles realtime data from RandomWalk. The RandomWalk will call this method from its own thread.
// This is a static method.
//
void MainWindow::OnData(void *self, double elapsedTime, double series0, double series1)
{
    /*
    // Copy the data into a structure and store it in the queue.
    DataPacket packet;
    packet.elapsedTime = elapsedTime;
    packet.series0 = series0;
    packet.series1 = series1;

    //buffer.put(packet);
    ((MainWindow *)self)->buffer.put(packet);*/
}

//
// Get data from the queue, update the viewport and update the chart display if necessary.
//
void MainWindow::onChartUpdateTimer()
{
    QChartViewer *viewer = m_ChartViewer;

    // Enables auto scroll if the viewport is showing the latest data before the update
    bool autoScroll = (m_currentIndex > 0) && (0.001 + viewer->getValueAtViewPort("x",
        viewer->getViewPortLeft() + viewer->getViewPortWidth()) >= m_timeStamps[m_currentIndex - 1]);

    //
    // Get new data from the queue and append them to the data arrays
    //
    int count;
    DataPacket *packets;
    if ((count = buffer.get(&packets)) <= 0)
        return;
    //qDebug()<<"双缓冲队列中数据个数:"<<count;
    //上边这步非常有意思，利用二级指针作为函数的参数
    //经过上边这个操作之后，buffer里面的数据就转到了packets指针中，长度为count


    // if data arrays have insufficient space, we need to remove some old data.
    if (m_currentIndex + count >= sampleSize)
    {
        // For safety, we check if the queue contains too much data than the entire data arrays. If
        // this is the case, we only use the latest data to completely fill the data arrays.
        if (count > sampleSize)
        {
            packets += count - sampleSize;
            count = sampleSize;
        }

        // Remove oldest data to leave space for new data. To avoid frequent removal, we ensure at
        // least 5% empty space available after removal.
        int originalIndex = m_currentIndex;
        m_currentIndex = sampleSize * 95 / 100 - 1;
        if (m_currentIndex > sampleSize - count)
            m_currentIndex = sampleSize - count;
        //将所有数据往前移动一段距离，大概是5%
        for (int i = 0; i < m_currentIndex; ++i)
        {
            int srcIndex = i + originalIndex - m_currentIndex;
            m_timeStamps[i] = m_timeStamps[srcIndex];
            m_dataSeriesA[i] = m_dataSeriesA[srcIndex];
            m_dataSeriesB[i] = m_dataSeriesB[srcIndex];
        }
    }
    //qDebug()<<"显示缓冲区的数据个数："<<m_currentIndex;
    // Append the data from the queue to the data arrays
    //将packet类型数组中数据取出来，放到显示数组中去
    for (int n = 0; n < count; ++n)
    {
        m_timeStamps[m_currentIndex] = packets[n].elapsedTime;
        m_dataSeriesA[m_currentIndex] = packets[n].series0;
        m_dataSeriesB[m_currentIndex] = packets[n].series1;
        //qDebug()<<m_timeStamps[m_currentIndex]<<m_dataSeriesA[m_currentIndex]<<m_dataSeriesB[m_currentIndex];
        ++m_currentIndex;
    }
    //此时要显示的数据全部存储在那三个数组中
    //qDebug()<<"显示缓冲区的数据个数："<<m_currentIndex;

    //这个是下面进度条全局图
    // As we added more data, we may need to update the full range of the viewport.
    //

    double startDate = m_timeStamps[0];
    double endDate = m_timeStamps[m_currentIndex - 1];

    // Use the initialFullRange (which is 60 seconds in this demo) if this is sufficient.
    double duration = endDate - startDate;
    if (duration < initialFullRange)
        endDate = startDate + initialFullRange;

    // Update the new full data range to include the latest data
    bool axisScaleHasChanged = viewer->updateFullRangeH("x", startDate, endDate,
        Chart::KeepVisibleRange);

    if (autoScroll)
    {
        // Scroll the viewport if necessary to display the latest data
        double viewPortEndPos = viewer->getViewPortAtValue("x", m_timeStamps[m_currentIndex - 1]);
        if (viewPortEndPos > viewer->getViewPortLeft() + viewer->getViewPortWidth())
        {
            viewer->setViewPortLeft(viewPortEndPos - viewer->getViewPortWidth());
            axisScaleHasChanged = true;
        }
    }

    // Set the zoom in limit as a ratio to the full range
    viewer->setZoomInWidthLimit(zoomInLimit / (viewer->getValueAtViewPort("x", 1) -
        viewer->getValueAtViewPort("x", 0)));

    // Trigger the viewPortChanged event. Updates the chart if the axis scale has changed
    // (scrolling or zooming) or if new data are added to the existing axis scale.
    viewer->updateViewPort(axisScaleHasChanged || (duration < initialFullRange), false);
}

//
// View port changed event
//
void MainWindow::onViewPortChanged()
{
    // Update the chart if necessary
    if (m_ChartViewer->needUpdateChart())
        drawChart(m_ChartViewer);

    // Update the full chart
    //drawFullChart(m_ViewPortControl);
}

//
// Draw chart
//
void MainWindow::drawChart(QChartViewer *viewer)
{
    // Get the start date and end date that are visible on the chart.
    double viewPortStartDate = viewer->getValueAtViewPort("x", viewer->getViewPortLeft());
    double viewPortEndDate = viewer->getValueAtViewPort("x", viewer->getViewPortLeft() +
        viewer->getViewPortWidth());

    // Extract the part of the data arrays that are visible.
    DoubleArray viewPortTimeStamps;
    DoubleArray viewPortDataSeriesA;
    DoubleArray viewPortDataSeriesB;
    /*
     * m_timeStamps,m_dataSeriesA,m_dataSeriesB:从双缓冲区中读取的所有数据
    */
    //qDebug()<<m_currentIndex;

    if (m_currentIndex > 0)
    {
        // Get the array indexes that corresponds to the visible start and end dates
        int startIndex = (int)floor(Chart::bSearch(DoubleArray(m_timeStamps, m_currentIndex), viewPortStartDate));
        int endIndex = (int)ceil(Chart::bSearch(DoubleArray(m_timeStamps, m_currentIndex), viewPortEndDate));
        int noOfPoints = endIndex - startIndex + 1;

        // Extract the visible data
        if (m_timeStamps[endIndex] >= viewPortStartDate)
        {
            viewPortTimeStamps = DoubleArray(m_timeStamps+ startIndex, noOfPoints);
            viewPortDataSeriesA = DoubleArray(m_dataSeriesA + startIndex, noOfPoints);
            viewPortDataSeriesB = DoubleArray(m_dataSeriesB + startIndex, noOfPoints);
        }

        // Keep track of the latest available data at chart plotting time
        trackLineEndPos = m_timeStamps[m_currentIndex - 1];
    }

    //
    // At this stage, we have extracted the visible data. We can use those data to plot the chart.
    //

    //================================================================================
    // Configure overall chart appearance.
    //================================================================================

    // Create an XYChart object of size 640 x 350 pixels
    XYChart *c = new XYChart(640, 450);

    // Set the plotarea at (20, 30) with width 41 pixels less than chart width, and height 50 pixels
    // less than chart height. Use a vertical gradient from light blue (f0f6ff) to sky blue (a0c0ff)
    // as background. Set border to transparent and grid lines to white (ffffff).
    c->setPlotArea(20, 30, c->getWidth() - 41, c->getHeight() - 50, c->linearGradientColor(0, 30, 0,
        c->getHeight() - 50, 0xf0f6ff, 0xa0c0ff), -1, Chart::Transparent, 0xffffff, 0xffffff);

     // As the data can lie outside the plotarea in a zoomed chart, we need enable clipping.
    c->setClipping();

    // Add a title to the chart using 18pt Arial font
    //c->addTitle("   Multithreading Real-Time Chart", "arial.ttf", 18);
    c->addTitle("实时曲线", "simsun.ttc", 18);

    // Add a legend box at (55, 25) using horizontal layout. Use 10pt Arial Bold as font. Set the
    // background and border color to transparent and use line style legend key.
    LegendBox *b = c->addLegend(55, 25, false, "arialbd.ttf", 10);
    b->setBackground(Chart::Transparent);
    b->setLineStyleKey();

    // Set the x and y axis stems to transparent and the label font to 10pt Arial
    c->xAxis()->setColors(Chart::Transparent);
    c->yAxis()->setColors(Chart::Transparent);
    c->xAxis()->setLabelStyle("arial.ttf", 10);
    c->yAxis()->setLabelStyle("arial.ttf", 10, 0x336699);

    // Set the y-axis tick length to 0 to disable the tick and put the labels closer to the axis.
    c->yAxis()->setTickLength(0);

    // Add axis title using 10pt Arial Bold Italic font
    c->yAxis()->setTitle("velocity", "arialbd.ttf", 10);

    // Configure the y-axis label to be inside the plot area and above the horizontal grid lines
    c->yAxis()->setLabelGap(-1);
    c->yAxis()->setLabelAlignment(1);
    c->yAxis()->setMargin(20);

    // Configure the x-axis labels to be to the left of the vertical grid lines
    //设置X轴标签与竖直网格线的位置关系，0表示正下方，1表示向右偏
    c->xAxis()->setLabelAlignment(0);

    //================================================================================
    // Add data to chart
    //================================================================================

    //
    // In this example, we represent the data by lines. You may modify the code below to use other
    // representations (areas, scatter plot, etc).
    //

    // Add a line layer for the lines, using a line width of 2 pixels
    LineLayer *layer = c->addLineLayer();
    layer->setLineWidth(1);
    layer->setFastLineMode();

    // Now we add the 2 data series to the line layer with red (ff0000) and green (00cc00) colors
    layer->setXData(viewPortTimeStamps);
    layer->addDataSet(viewPortDataSeriesA, 0xff0000, "line1");
    layer->addDataSet(viewPortDataSeriesB, 0x00cc00, "line2");

    //================================================================================
    // Configure axis scale and labelling
    //================================================================================

    // Set the x-axis as a date/time axis with the scale according to the view port x range.
    if (m_currentIndex > 0)
        c->xAxis()->setDateScale(viewPortStartDate, viewPortEndDate);

    // For the automatic axis labels, set the minimum spacing to 75/30 pixels for the x/y axis.
    c->xAxis()->setTickDensity(75);
    c->yAxis()->setTickDensity(30);

    // We use "hh:nn:ss" as the axis label format.
    c->xAxis()->setLabelFormat("{value|hh:nn:ss}");

    // We make sure the tick increment must be at least 1 second.
    //c->xAxis()->setMinTickInc(1);

    // Set the auto-scale margin to 0.05, and the zero affinity to 0.6
    c->yAxis()->setAutoScale(0.05, 0.05, 0.6);

    //================================================================================
    // Output the chart
    //================================================================================

    // We need to update the track line too. If the mouse is moving on the chart (eg. if
    // the user drags the mouse on the chart to scroll it), the track line will be updated
    // in the MouseMovePlotArea event. Otherwise, we need to update the track line here.
    if (!viewer->isInMouseMoveEvent())
        trackLineLabel(c, trackLineIsAtEnd ? c->getWidth() : viewer->getPlotAreaMouseX());

    // Set the chart image to the QChartViewer
    delete viewer->getChart();
    viewer->setChart(c);
}

//
// Draw track cursor when mouse is moving over plotarea
//
void MainWindow::onMouseMovePlotArea(QMouseEvent *)
{
    double trackLinePos = trackLineLabel((XYChart *)m_ChartViewer->getChart(),
        m_ChartViewer->getPlotAreaMouseX());
    trackLineIsAtEnd = (m_currentIndex <= 0) || (trackLinePos == trackLineEndPos);

    m_ChartViewer->updateDisplay();
}

//
// Draw the track line with data point labels
//
double MainWindow::trackLineLabel(XYChart *c, int mouseX)
{
    // Clear the current dynamic layer and get the DrawArea object to draw on it.
    DrawArea *d = c->initDynamicLayer();

    // The plot area object
    PlotArea *plotArea = c->getPlotArea();

    // Get the data x-value that is nearest to the mouse, and find its pixel coordinate.
    double xValue = c->getNearestXValue(mouseX);
    int xCoor = c->getXCoor(xValue);
    if (xCoor < plotArea->getLeftX())
        return xValue;

    // Draw a vertical track line at the x-position
    d->vline(plotArea->getTopY(), plotArea->getBottomY(), xCoor, 0x888888);

    // Draw a label on the x-axis to show the track line position.
    ostringstream xlabel;
    xlabel << "<*font,bgColor=000000*> " << c->xAxis()->getFormattedLabel(xValue + 0.00499,
        "hh:nn:ss.ff") << " <*/font*>";
    TTFText *t = d->text(xlabel.str().c_str(), "arialbd.ttf", 10);

    // Restrict the x-pixel position of the label to make sure it stays inside the chart image.
    int xLabelPos = max(0, min(xCoor - t->getWidth() / 2, c->getWidth() - t->getWidth()));
    t->draw(xLabelPos, plotArea->getBottomY() + 2, 0xffffff);
    t->destroy();

    // Iterate through all layers to draw the data labels
    for (int i = 0; i < c->getLayerCount(); ++i) {
        Layer *layer = c->getLayerByZ(i);

        // The data array index of the x-value
        int xIndex = layer->getXIndexOf(xValue);

        // Iterate through all the data sets in the layer
        for (int j = 0; j < layer->getDataSetCount(); ++j)
        {
            DataSet *dataSet = layer->getDataSetByZ(j);
            const char *dataSetName = dataSet->getDataName();

            // Get the color, name and position of the data label
            int color = dataSet->getDataColor();
            int yCoor = c->getYCoor(dataSet->getPosition(xIndex), dataSet->getUseYAxis());

            // Draw a track dot with a label next to it for visible data points in the plot area
            if ((yCoor >= plotArea->getTopY()) && (yCoor <= plotArea->getBottomY()) && (color !=
                Chart::Transparent) && dataSetName && *dataSetName)
            {
                d->circle(xCoor, yCoor, 4, 4, color, color);

                ostringstream label;
                label << "<*font,bgColor=" << hex << color << "*> "
                    << c->formatValue(dataSet->getValue(xIndex), "{value|P4}") << " <*font*>";
                t = d->text(label.str().c_str(), "arialbd.ttf", 10);

                // Draw the label on the right side of the dot if the mouse is on the left side the
                // chart, and vice versa. This ensures the label will not go outside the chart image.
                if (xCoor <= (plotArea->getLeftX() + plotArea->getRightX()) / 2)
                    t->draw(xCoor + 6, yCoor, 0xffffff, Chart::Left);
                else
                    t->draw(xCoor - 6, yCoor, 0xffffff, Chart::Right);

                t->destroy();
            }
        }
    }

    return xValue;
}

//
// Draw the full thumbnail chart and display it in the given QViewPortControl
//
void MainWindow::drawFullChart(QViewPortControl *vpc)
{
    // Create an XYChart object of size 640 x 60 pixels
    XYChart *c = new XYChart(640, 60);

    // Set the plotarea with the same horizontal position as that in the main chart for alignment.
    c->setPlotArea(20, 0, c->getWidth() - 41, c->getHeight() - 1, 0xc0d8ff, -1, 0xcccccc,
        Chart::Transparent, 0xffffff);

    // Set the x axis stem to transparent and the label font to 10pt Arial
    c->xAxis()->setColors(Chart::Transparent);
    c->xAxis()->setLabelStyle("Arial", 10);

    // Put the x-axis labels inside the plot area by setting a negative label gap. Use
    // setLabelAlignment to put the label at the right side of the tick.
    c->xAxis()->setLabelGap(-1);
    c->xAxis()->setLabelAlignment(1);

    // Set the y axis stem and labels to transparent (that is, hide the labels)
    c->yAxis()->setColors(Chart::Transparent, Chart::Transparent);

    // Add a line layer for the lines with fast line mode enabled
    LineLayer *layer = c->addLineLayer();
    layer->setFastLineMode();

    // Now we add the 3 data series to a line layer, using the color red (0xff3333), green
    // (0x008800) and blue (0x3333cc)
    layer->setXData(DoubleArray(m_timeStamps, m_currentIndex));
    layer->addDataSet(DoubleArray(m_dataSeriesA, m_currentIndex), 0xff3333);
    layer->addDataSet(DoubleArray(m_dataSeriesB, m_currentIndex), 0x008800);

    // The x axis scales should reflect the full range of the view port
    c->xAxis()->setDateScale(vpc->getViewer()->getValueAtViewPort("x", 0),
        vpc->getViewer()->getValueAtViewPort("x", 1));
    c->xAxis()->setLabelFormat("{value|nn:ss}");

    // For the automatic x-axis labels, set the minimum spacing to 75 pixels.
    c->xAxis()->setTickDensity(75);

    // For the auto-scaled y-axis, as we hide the labels, we can disable axis rounding. This can
    // make the axis scale fit the data tighter.
    c->yAxis()->setRounding(false, false);

    // Output the chart
    delete vpc->getChart();
    vpc->setChart(c);
}

//******************************************************************************************************************
//10ms多媒体定时器
//100ms绘图
void MainWindow::slotFuction()
{
    /*msCount:真是的时间，毫秒为单位
     * currentTime:真实的时间，以s为单位
    */
    //*************************************状态栏*********************************************
    if (msCount%1000==0)
    {
        QDateTime time = QDateTime::currentDateTime();
        QString str = "系统时间："+time.toString("yyyy-MM-dd hh:mm:ss");
        currentLabel->setText(str);
    }
    //*********************************读取位移数据*******************************************************
    int x_position = Enc7480_Get_Encoder(0);//
    ui->lineEdit_S->setText(QString::number(x_position*(-0.0024)));
    //qDebug()<<"水平位置："<<x_position;
    //*********************************将数据放入缓冲区*****************************************************
    msCount+=10;
    double series0;
    double series1;
    double currentTime =msCount*0.01;
    double elapsedTime;

    series0=x_position*(-0.0024);
    series1=x_position*(-0.0024);

    /*
    //Test1
    //series0=30*sin(0.001*currentTime)+30*sin(0.002*currentTime)+30*sin(0.004*currentTime);
    //series1=30*sin(0.0005*currentTime);
    //Test2
    series0=1/100.0*qSin(currentTime)*currentTime;
    series1=1/100.0*currentTime;
    //Test3
    series0=qExp(-currentTime/10.0);
    series1=qSin(currentTime)*qExp(-currentTime/10.0);

    if (currentTime<100)
    {
        series0=1/100.0*qSin(currentTime)*currentTime;
        series1=1/100.0*currentTime;
    }else
    {
        series0=qSin(currentTime);
        series1=1;
    }

    //series0=qSqrt(currentTime);
    //series1=qSin(currentTime)*qSqrt(currentTime);
*/
    elapsedTime=msCount / 1000.0;

    DataPacket packet;
    packet.elapsedTime = elapsedTime;
    packet.series0 = series0;
    packet.series1 = series1;

    buffer.put(packet);
    //((RealTimeViewPort *)self)->buffer.put(packet);

    //*****************************AO输出*********************************************************
    if (startFlag)
    {
        ErrorCode errorCode = Success;
        errorCode = instantAoCtrl->Write(configureAO.channelStart,configureAO.channelCount, dataScaled);
        CheckError(errorCode);
    }

}

void MainWindow::on_action_Quit_triggered()
{
    int ret=QMessageBox::information(NULL,"提示信息","请确实是否退出操作界面？",
                                     QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
    switch (ret) {
      case QMessageBox::Ok:
          qDebug()<<"OkButton is clicked!";
          this->close();
          break;
      case QMessageBox::Cancel:
          qDebug()<<"CancelButton is clicked!";
          break;
      default:
          // should never be reached
          break;
    }
}

void MainWindow::on_action_ToolFlag_triggered()
{
    if (ui->action_ToolFlag->isChecked())
        ui->toolBar->setVisible(false);
    else
        ui->toolBar->setVisible(true);
}

void MainWindow::on_action_StatusFlag_triggered()
{
    if (ui->action_StatusFlag->isChecked())
        ui->statusBar->setVisible(false);
    else
        ui->statusBar->setVisible(true);
}

void MainWindow::on_action_About_triggered()
{
    AboutForm *aboutForm=new AboutForm;
    aboutForm->show();
}

void MainWindow::on_action_HelpF1_triggered()
{/*
    QDesktopServices desktopServices;
    QString strUrl=QCoreApplication::applicationDirPath () ;
    strUrl=QString("D:/Popwil/PopWil/Help/VCSHelp.chm").arg (strUrl);
    QUrl qqq(strUrl);
    desktopServices.openUrl(qqq);
    */
}

void MainWindow::on_action_ChannelParameters_triggered()
{
    ConfigureDialog dialog;
    int resultDialog = dialog.exec();
    if (resultDialog == QDialog::Rejected)
    {
        //exit(0);
    }
    else if(resultDialog == QDialog::Accepted)
    {
        SetConfigureParameter(dialog.GetConfigureParameter());
        qDebug()<<configureAO.deviceName;
        qDebug()<<configureAO.channelStart<<configureAO.channelCount<<configureAO.valueRange;
        Initialize();
    }
}

void MainWindow::on_btnStart_clicked()
{
    double AoValue;

    if (ui->btnStart->isFlat())
    {
        ui->btnStart->setFlat(false);
        ui->btnStart->setStyleSheet("background-color:green");
    }
    else
        ui->btnStart->setFlat(true);

    AoValue=ui->lineEdit->text().toDouble();
    qDebug()<<"输出电压"<<AoValue;
    if(AoValue<=-10||AoValue>=10)
    {
        QMessageBox::information(NULL,"提示","Too large Voltage!",QMessageBox::Ok|QMessageBox::Cancel);
        exit;
    }
    for (int i = 0; i < 2; i++)
        dataScaled[i]=AoValue;
    startFlag=true;
}



void MainWindow::on_btnStop_clicked()
{
    if (ui->btnStop->isFlat())//没按
    {
        ui->btnStop->setFlat(false);
        ui->btnStop->setStyleSheet("background-color:green");
    }
    else
    {
        ui->btnStop->setFlat(true);
    }

    dataScaled[0]=0;
    dataScaled[1]=0;
    ui->lineEdit->setText("0");
}

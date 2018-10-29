#include "rbf.h"
#include "ui_rbf.h"
#include "chartdir.h"
#include "qchartviewer.h"
#include "constvar.h"
#include "qdebug.h"
#include "time.h"
#include "math.h"

#define LEN 3000
#define pi 3.1415926535897932

RBF::RBF(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RBF)
{
    ui->setupUi(this);
    this->setWindowTitle("RBF系统辨识");
    work();
    drawData();
    drawJacobian();
    drawYm();

}

RBF::~RBF()
{
    delete ui;
}

void RBF::drawData()
{
    // Chart Viewer
    QChartViewer *m_ChartViewer = new QChartViewer(this);
    m_ChartViewer->setGeometry(10, 25, 640, 480);
   // Create an XYChart object of size 600 x 300 pixels, with a light blue (EEEEFF) background,
   // black border, 1 pxiel 3D border effect and rounded corners
   XYChart *c = new XYChart(600, 300, 0xeeeeff, 0x000000, 1);
   c->setRoundedFrame();

   // Set the plotarea at (55, 58) and of size 520 x 195 pixels, with white background. Turn on
   // both horizontal and vertical grid lines with light grey color (0xcccccc)
   c->setPlotArea(55, 58, 520, 195, 0xffffff, -1, -1, 0xcccccc, 0xcccccc);

   // Add a legend box at (50, 30) (top of the chart) with horizontal layout. Use 9pt Arial Bold
   // font. Set the background and border color to Transparent.
   c->addLegend(50, 30, false, "arialbd.ttf", 9)->setBackground(Chart::Transparent);

   // Add a title box to the chart using 15pt Times Bold Italic font, on a light blue (CCCCFF)
   // background with glass effect. white (0xffffff) on a dark red (0x800000) background, with a 1
   // pixel 3D border.
   c->addTitle("位移曲线", "simsun.ttc", 18)->setBackground(0xccccff,0x000000, Chart::glassEffect());

   // Add a title to the y axis
   c->yAxis()->setTitle("s","simsun.ttc",15);

   // Set the labels on the x axis.
   //c->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));
   c->xAxis()->setLabels(DoubleArray(time,LEN));

   // Display 1 out of 3 labels on the x-axis.
   c->xAxis()->setLabelStep(300);

   // Add a title to the x axis
   c->xAxis()->setTitle("Time t");

   // Add a line layer to the chart
   LineLayer *layer = c->addLineLayer();

   // Set the default line width to 2 pixels
   layer->setLineWidth(2);

   // Add the three data sets to the line layer. For demo purpose, we use a dash line color for the
   // last line
   //layer->addDataSet(DoubleArray(data0, (int)(sizeof(data0) / sizeof(data0[0]))), 0xff0000,"Server #1");
   //layer->addDataSet(DoubleArray(data2, (int)(sizeof(data2) / sizeof(data2[0]))), c->dashLineColor(0x3333ff, Chart::DashLine), "Server #3");
   //layer->setXData(DoubleArray(time,LEN));
   layer->addDataSet(DoubleArray(y,LEN),0xff0000,"True Values");
   layer->addDataSet(DoubleArray(ym,LEN),0x3333ff,"Pred Values");


   // Output the chart
   c->makeChart("multiline.png");
   m_ChartViewer->setChart(c);

   //free up resources
   delete c;
   m_ChartViewer->show();
}

void RBF::drawJacobian()
{
    // Chart Viewer
    QChartViewer *m_ChartViewer = new QChartViewer(this);
    m_ChartViewer->setGeometry(10, 350, 640, 480);
    XYChart *c = new XYChart(600, 300, 0xeeeeff, 0x000000, 1);
    c->setRoundedFrame();
    c->setPlotArea(55, 58, 520, 195, 0xffffff, -1, -1, 0xcccccc, 0xcccccc);
    c->addLegend(50, 30, false, "arialbd.ttf", 9)->setBackground(Chart::Transparent);
    c->addTitle("Jacobian", "simsun.ttc", 18)->setBackground(0xccccff,0x000000, Chart::glassEffect());
    c->yAxis()->setTitle("dyu","simsun.ttc",15);

    // Set the labels on the x axis.
    //c->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));
    c->xAxis()->setLabels(DoubleArray(time,LEN));

    // Display 1 out of 3 labels on the x-axis.
    c->xAxis()->setLabelStep(300);
    c->xAxis()->setTitle("Time t");
    LineLayer *layer = c->addLineLayer();
    layer->setLineWidth(2);
    layer->addDataSet(DoubleArray(dyu,LEN),0x3333ff,"Jacobian");
    m_ChartViewer->setChart(c);
    delete c;
    m_ChartViewer->show();
}

void RBF::drawYm()
{
    // Chart Viewer
    QChartViewer *m_ChartViewer = new QChartViewer(this);
    m_ChartViewer->setGeometry(700, 25, 640, 480);
    XYChart *c = new XYChart(600, 300, 0xeeeeff, 0x000000, 1);
    c->setRoundedFrame();
    c->setPlotArea(55, 58, 520, 195, 0xffffff, -1, -1, 0xcccccc, 0xcccccc);
    c->addLegend(50, 30, false, "arialbd.ttf", 9)->setBackground(Chart::Transparent);
    c->addTitle("误差曲线", "simsun.ttc", 18)->setBackground(0xccccff,0x000000, Chart::glassEffect());
    c->yAxis()->setTitle("e","simsun.ttc",15);

    // Set the labels on the x axis.
    //c->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));
    c->xAxis()->setLabels(DoubleArray(time,LEN));

    // Display 1 out of 3 labels on the x-axis.
    c->xAxis()->setLabelStep(300);
    c->xAxis()->setTitle("Time t");
    LineLayer *layer = c->addLineLayer();
    layer->setLineWidth(2);
    layer->addDataSet(DoubleArray(em,LEN),0x3333ff,"Error");
    m_ChartViewer->setChart(c);
    delete c;
    m_ChartViewer->show();
}

void RBF::work()
{
    int i,j,k;
    //RBF网络辨识
    double alfa=0.05;//阻尼
    double xite=0.5; //学习率
    double x[2];

    double b_1[4],b_2[4],b[4]={1.5,1.5,1.5,1.5};
    for(i=0;i<4;i++)
    {
        b_1[i]=b[i];
        b_2[i]=b[i];
    }
    double c_1[2][4],c_2[2][4],c[2][4]={{0.5,0.5,0.5,0.5},
                                        {0.5,0.5,0.5,0.5}};
    for(i=0;i<2;i++)
        for (j=0;j<4;j++)
        {
            c_1[i][j]=c[i][j];
            c_2[i][j]=c[i][j];
        }
    double w_1[4],w_2[4],w[4]={0.914333896485891,-0.029248702554318,0.600560937777600,-0.716227322745569};
    for (i=0;i<4;i++)
    {
        w_1[i]=w[i];
        w_2[i]=w[i];
    }

    double d_w[4]={0};
    double d_b[4]={0};
    double d_c[2][4]={0};

    double y_1=0;
    double ts=0.001;
    double h[4];
    double tmp;

    for (k=1;k<=LEN-2;k++)
    {
        time[k]=k*ts;//时间
        //u[k]=0.50*sin(1*2*pi*k*ts);//系统输入
        //y[k]=pow(u[k],3)+y_1/(1+y_1*y_1);  //k时刻系统输出，可以理解成采集到的值

        u[k]=0.5*sin(1.0/50*pi*k*ts);
        double a0=1+0.15*sin(1/25*pi*k*ts);
        y[k]=(a0*y_1+u[k-1])/(1+y_1*y_1);
        //---------------------------前向传播------------------------------------**
        x[0]=u[k];
        x[1]=y_1;

        for (i=0;i<4;i++)
        {
            tmp=(x[0]-c[0][i])*(x[0]-c[0][i])+(x[1]-c[1][i])*(x[1]-c[1][i]);
            h[i]=exp(-tmp/(2*b[i]*b[i]));
        }
        for (i=0;i<4;i++)
            ym[k]+=h[i]*w[i];
        em[k]=y[k]-ym[k];
        qDebug()<<k<<":"<<y[k]<<ym[k];
        //---------------------------**Back 传播---------------------------------
        for (j=0;j<4;j++)
        {
            d_w[j]=xite*em[k]*h[j];
            d_b[j]=xite*em[k]*w[j]*h[j]*pow(b[j],-3)*tmp;
            for (i=0;i<2;i++)
                d_c[i][j]=xite*em[k]*w[j]*h[j]*(x[i]-c[i][j])*pow(b[j],-1);

        }
        for(i=0;i<4;i++)
        {
            w[i]=w_1[i]+d_w[i]+alfa*(w_1[i]-w_2[i]);
            b[i]=b_1[i]+d_b[i]+alfa*(b_1[i]-b_2[i]);
        }
        for(i=0;i<2;i++)
            for(j=0;j<4;j++)
                c[i][j]=c_1[i][j]+alfa*(c_1[i][j]-c_2[i][j]);
        //------------------------**Jacobian------------------------------------
        for(j=0;j<4;j++)
            dyu[k]+=w[j]*h[j]*(c[0][j]-x[0])*pow(b[j],-2);
        //------------------------------------------------------------**
        for(i=0;i<4;i++)
        {
            w_2[i]=w_1[i];w_1[i]=w[i];
            b_2[i]=b_1[i];b_1[i]=b[i];
            for(j=0;j<2;j++)
            {
                c_2[j][i]=c_1[j][i];
                c_1[j][i]=c[j][i];
            }
        }

        y_1=y[k];
    }

}

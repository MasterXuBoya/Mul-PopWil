#include "mainwindow.h"
#include <QApplication>
#include "qdebug.h"
#include "qlibrary.h"
#include "fftForMatlab.h"
#include "qmessagebox.h"
#include "tfeFun.h"
#include "dotMul.h"
#include "addMul.h"
#include "plotTest.h"
#include "stdlib.h"
#include "QSplashScreen"
#include "QTextCodec"
#include "QPixmap"
#include "ToolFromMatlab.h"
#include "QTranslator"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    double data[5]={1,2,3,4,5};
//    dotMulInitialize();
//    QLibrary myLib("dotMul.dll");
//    if(myLib.load())
//        qDebug()<<"-------------success load---------------";
//    typedef void MW_CALL_CONV (*Fun)(int nargout, mwArray& b, const mwArray& a);
//    Fun dotMul = (Fun) myLib.resolve("?dotMul@@YAXHAAVmwArray@@ABV1@@Z");
//    if(dotMul)
//        qDebug()<<"-------------function loaded success-------------------";
//    qDebug()<<"开始计算";

//    mwArray mwA(1,5,mxDOUBLE_CLASS);
//    mwArray ans(1,5,mxDOUBLE_CLASS);
//    mwA.SetData(data,5);

//    dotMul(1,ans,mwA);
//    qDebug()<<mwA.ToString();
//    qDebug()<<ans.ToString();
//    double t=ans(1,1);
//    qDebug()<<"the first data is"<<t;
//    dotMulTerminate();


//    fftForMatlabInitialize();
//    QLibrary myLib("fftForMatlab.dll");
//    if(myLib.load())
//        qDebug()<<"haha";
//    typedef void MW_CALL_CONV (*Fun)(int nargout, mwArray& y, const mwArray& x);
//    Fun fftForMatlab = (Fun) myLib.resolve("?fftForMatlab@@YAXHAAVmwArray@@ABV1@@Z");
//    if(fftForMatlab)
//        qDebug()<<"success loasd";
//    mwArray data(1,10,mxDOUBLE_CLASS);
//    double tmp[]={1,2,3,4,5,6,7,8,9,10};
//    data.SetData(tmp,10);
//    mwArray s(1,10,mxDOUBLE_CLASS);
//    fftForMatlab(1,s,data);
//    QString mess=QString(s.ToString());
//    QMessageBox::information(NULL,"test",mess,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);

//    for(int i=1;i<=10;i++)
//        qDebug()<<s(1,i).ToString();

//    fftForMatlabTerminate();


//    addMulInitialize();
//    QLibrary myLib("addMul.dll");
//    if(myLib.load())
//        qDebug()<<"-----------addMul.dll load success-----------------";
//    typedef void MW_CALL_CONV (*Fun)(int nargout, mwArray& y, mwArray& z, const mwArray& x);
//    Fun addMul=(Fun)myLib.resolve("?addMul@@YAXHAAVmwArray@@ABV1@@Z");
//    if(addMul)
//        qDebug()<<"-----------function addMul load success---------------";
//    mwArray mwA(1,5,mxDOUBLE_CLASS);
//    mwArray ansY(1,5,mxDOUBLE_CLASS);
//    mwArray ansZ(1,5,mxDOUBLE_CLASS);
//    double data[]={1,2,3,4,5};
//    mwA.SetData(data,5);

//    //addMul(2,ansY,ansZ,mwA);
//    qDebug()<<mwA.ToString();
//    qDebug()<<ansY.ToString();
//    qDebug()<<ansZ.ToString();

//    addMulTerminate();



//    QLibrary myLib("tfeFun.dll");
//    if(myLib.load())
//           qDebug()<<"-----------tfeFun.dll load success-----------------";
//    tfeFunInitialize();

//    typedef void MW_CALL_CONV (*Fun)(int nargout, mwArray& y, mwArray& f);
//    Fun tfeFun = (Fun) myLib.resolve("?tfeFun@@YAXHAAVmwArray@@0@Z");
//    if(tfeFun)
//        qDebug()<<"-----------function tfeFun load success---------------";
//    mwArray y(129,1,mxDOUBLE_CLASS);
//    mwArray f(129,1,mxDOUBLE_CLASS);
//    tfeFun(2,y,f);
//    for(int i=1;i<=129;i++)
//        qDebug()<<y(i,1).ToString();
//    for(int i=1;i<=129;i++)
//        qDebug()<<f(i,1).ToString();
//    tfeFunTerminate();
    //-----------------------开机动画--------------------------------
    //QTextCodec :: setCodecForTr( QTextCodec :: codecForName( "GB18030" ));
    QPixmap pixmap(":/Icon/Icon/start.png");      //绑定一个图片
    QSplashScreen splash(pixmap);
    splash.show();                            //显示启动画面
    splash.showMessage(QObject::tr("MATLAB接口模块.正在启动中...."),Qt::AlignLeft|Qt::AlignBottom,Qt::green);
    a.processEvents();                //加载其他的模块

    //-------------------------------------------------------------
//    QLibrary myLib("plotTest.dll");
//    if(myLib.load())
//           qDebug()<<"-----------plotTest.dll load success-----------------";
//    plotTestInitialize();

//    typedef void MW_CALL_CONV (*Fun)(const mwArray& x);
//    Fun plotTest = (Fun) myLib.resolve("?plotTest@@YAXABVmwArray@@@Z");
//    if(plotTest)
//        qDebug()<<"-----------function plotTest load success---------------";
//    mwArray x(1,10,mxDOUBLE_CLASS);
//    double data[]={1,3,4,2,5,6,2,3,6,8};
//    x.SetData(data,10);
//    plotTest(x);
//    system("pause");
//    plotTestTerminate();

    matlabHandler.init();
    //-------------------启动主窗体---------------------------
    MainWindow w;
    splash.showMessage(QObject::tr("加载模块数据...."),Qt::AlignLeft|Qt::AlignBottom,Qt::green);
    w.show();

    splash.finish(&w);     //当主窗口启动后，启动画面隐藏

    return a.exec();
}

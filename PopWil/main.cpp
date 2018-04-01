#include "mainwindow.h"
#include <QApplication>
#include "qchartviewer.h"
#include "testwindow.h"
#include "Enc7480.h"
#include "qdebug.h"
#include "aboutform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    int d7480rtn= Enc7480_Init();
    qDebug()<<"leisai number:"<<d7480rtn;
    if(d7480rtn < 1)
    {
        qDebug()<<"初始化ENC7480计数卡失败!";
        Enc7480_Close();
    }
    MainWindow w;
    w.show();
    //AboutForm w;
    //w.show();

    return a.exec();
}

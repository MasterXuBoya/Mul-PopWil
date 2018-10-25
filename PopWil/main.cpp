#include "mainwindow.h"
#include <QApplication>
#include "qchartviewer.h"
#include "testwindow.h"
#include "Enc7480.h"
#include "qdebug.h"
#include "sinesweepmodule.h"
#include "fftw3.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //SineSweepModule w;
    w.show();
    return a.exec();
}

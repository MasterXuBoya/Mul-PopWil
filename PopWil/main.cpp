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
    MainWindow w;
    w.show();
    //AboutForm w;
    //w.show();

    return a.exec();
}

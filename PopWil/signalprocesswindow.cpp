#include "signalprocesswindow.h"
#include "ui_signalprocesswindow.h"

SignalProcessWindow::SignalProcessWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignalProcessWindow)
{
    ui->setupUi(this);
}

SignalProcessWindow::~SignalProcessWindow()
{
    delete ui;
}

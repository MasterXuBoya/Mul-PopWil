#include "testwindow.h"
#include "ui_testwindow.h"

TestWindow::TestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestWindow)
{
    ui->setupUi(this);

    QWidget *widget = new QWidget();
    this->setCentralWidget(widget);
    widget->setLayout(ui->mainLayout);
}

TestWindow::~TestWindow()
{
    delete ui;
}

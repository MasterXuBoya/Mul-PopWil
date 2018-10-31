#include "DisplayBufferForm.h"
#include "ui_DisplayBufferForm.h"
#include "constvar.h"
DisplayBufferForm::DisplayBufferForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayBufferForm)
{
    ui->setupUi(this);
    ui->spinBox_S->setRange(2,20);
    ui->spinBox_S->setSingleStep(1);
    ui->spinBox_V->setRange(2,30);
    ui->spinBox_V->setSingleStep(1);
    ui->spinBox_A->setRange(2,20);
    ui->spinBox_A->setSingleStep(1);

    ui->spinBox_S->setValue(displayDelay.sDelay);
    ui->spinBox_V->setValue(displayDelay.vDelay);
    ui->spinBox_A->setValue(displayDelay.aDelay);
}

DisplayBufferForm::~DisplayBufferForm()
{
    delete ui;
}

void DisplayBufferForm::on_pushButton_clicked()
{
    displayDelay.sDelay=ui->spinBox_S->value();
    displayDelay.vDelay=ui->spinBox_V->value();
    displayDelay.aDelay=ui->spinBox_A->value();
    this->accept();
}

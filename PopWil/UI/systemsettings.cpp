#include "systemsettings.h"
#include "ui_systemsettings.h"
#include "qdebug.h"

SystemSettings::SystemSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SystemSettings)
{
    ui->setupUi(this);
    ui->spinBoxCtrlInterval->setRange(1,20);
    ui->spinBoxCtrlInterval->setSingleStep(1);
    ui->spinBoxDrawInterval->setRange(100,1000);
    ui->spinBoxDrawInterval->setSingleStep(100);

    setTabOrder(ui->spinBoxCtrlInterval,ui->spinBoxDrawInterval);
    setTabOrder(ui->spinBoxDrawInterval,ui->lineEdit_MaxAbsolutePosition);
    setTabOrder(ui->lineEdit_MaxAbsolutePosition,ui->lineEdit_MaxOutU);
}

SystemSettings::~SystemSettings()
{
    delete ui;
}

void SystemSettings::setSystemInfo()
{
    ui->spinBoxCtrlInterval->setValue(systemInfo.contrlInterval);
    ui->spinBoxDrawInterval->setValue(systemInfo.drawInterval);
    ui->lineEdit_MaxAbsolutePosition->setText(QString::number(systemInfo.maxAbsolutePosition));
    ui->lineEdit_MaxOutU->setText(QString::number(systemInfo.maxOutU));
}

void SystemSettings::on_btnSaveOnce_clicked()
{
    systemInfo.contrlInterval=ui->spinBoxCtrlInterval->value();
    systemInfo.drawInterval=ui->spinBoxDrawInterval->value();
    systemInfo.maxAbsolutePosition=ui->lineEdit_MaxAbsolutePosition->text().toDouble();
    systemInfo.maxOutU=ui->lineEdit_MaxOutU->text().toDouble();
    this->accept();
}

void SystemSettings::on_btnClose_clicked()
{
    this->close();
}

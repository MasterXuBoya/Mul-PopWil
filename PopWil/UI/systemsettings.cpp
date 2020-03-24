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
    ui->horizontalSlider_control->setRange(1,20);
    ui->horizontalSlider_control->setSingleStep(1);
    connect(ui->spinBoxCtrlInterval,SIGNAL(valueChanged(int)),ui->horizontalSlider_control,SLOT(setValue(int)));
    connect(ui->horizontalSlider_control,SIGNAL(valueChanged(int)),ui->spinBoxCtrlInterval,SLOT(setValue(int)));

    ui->spinBoxDrawInterval->setRange(100,1000);
    ui->spinBoxDrawInterval->setSingleStep(100);
    ui->horizontalSlider_draw->setRange(100,1000);
    ui->horizontalSlider_draw->setSingleStep(100);
    connect(ui->spinBoxDrawInterval,SIGNAL(valueChanged(int)),ui->horizontalSlider_draw,SLOT(setValue(int)));
    connect(ui->horizontalSlider_draw,SIGNAL(valueChanged(int)),ui->spinBoxDrawInterval,SLOT(setValue(int)));

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
    ui->lineEdit_MaxOutU_Debug->setText(QString::number(systemInfo.maxOutUDebug));
    ui->lineEdit_MaxOutU->setText(QString::number(systemInfo.maxOutU));
    ui->led_Max_force->setText(QString::number(systemInfo.maxAbsoluteForce));
    ui->lineEdit_MaxAbsolutePosition->setText(QString::number(systemInfo.maxAbsolutePosition));
    ui->led_Max_Vel->setText(QString::number(systemInfo.maxAbsoluteVel));
    ui->led_Max_Acc->setText(QString::number(systemInfo.maxAbsoluteAcc));
    ui->led_Max_Weight->setText(QString::number(systemInfo.maxLoadWeight));
}

void SystemSettings::on_btnSaveOnce_clicked()
{
    systemInfo.contrlInterval=ui->spinBoxCtrlInterval->value();
    systemInfo.drawInterval=ui->spinBoxDrawInterval->value();
    systemInfo.maxOutUDebug=ui->lineEdit_MaxOutU_Debug->text().toDouble();
    systemInfo.maxOutU=ui->lineEdit_MaxOutU->text().toDouble();
    systemInfo.maxAbsoluteForce=ui->led_Max_force->text().toDouble();
    systemInfo.maxAbsolutePosition=ui->lineEdit_MaxAbsolutePosition->text().toDouble();
    systemInfo.maxAbsoluteVel=ui->led_Max_Vel->text().toDouble();
    systemInfo.maxAbsoluteAcc=ui->led_Max_Acc->text().toDouble();
    systemInfo.maxLoadWeight=ui->led_Max_Weight->text().toDouble();
    this->accept();
}

void SystemSettings::on_btnClose_clicked()
{
    this->close();
}

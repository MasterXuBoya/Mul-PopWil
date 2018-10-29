#include "ctrldialog.h"
#include "ui_ctrldialog.h"

CtrlDialog::CtrlDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CtrlDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("控制参数");
    ctrlModeSet.append("Static Displacement Contrller");
    ctrlModeSet.append("SineWave Controller");
    ui->cmbCtrlMode->addItems(ctrlModeSet);
    for (int i=0;i<2;i++)
        ui->tabWidget->setTabText(i,ctrlModeSet[i]);

    setTabOrder(ui->le_sine_P,ui->le_sine_I);
    setTabOrder(ui->le_sine_I,ui->le_sine_D);
    setTabOrder(ui->lineEdit_P,ui->lineEdit_I);
    setTabOrder(ui->lineEdit_I,ui->lineEdit_D);

    connect(ui->cmbCtrlMode, SIGNAL(currentIndexChanged(int)), this, SLOT(DeviceChanged(int)));
    connect(ui->tabWidget,SIGNAL(currentChanged(int)),ui->cmbCtrlMode,SLOT(setCurrentIndex(int)));
}

CtrlDialog::~CtrlDialog()
{
    delete ui;
}

void CtrlDialog::setPIDParameter()
{
    ui->lineEdit_P->setText(QString::number(sPIDInfo.SP));
    ui->lineEdit_I->setText(QString::number(sPIDInfo.SI));
    ui->lineEdit_D->setText(QString::number(sPIDInfo.SD));

    ui->le_sine_P->setText(QString::number(sinePIDInfo.SP));
    ui->le_sine_I->setText(QString::number(sinePIDInfo.SI));
    ui->le_sine_D->setText(QString::number(sinePIDInfo.SD));
}

void CtrlDialog::on_btnOk_clicked()
{
    sPIDInfo.SP=ui->lineEdit_P->text().toDouble();
    sPIDInfo.SI=ui->lineEdit_I->text().toDouble();
    sPIDInfo.SD=ui->lineEdit_D->text().toDouble();

    sinePIDInfo.SP=ui->le_sine_P->text().toDouble();
    sinePIDInfo.SI=ui->le_sine_I->text().toDouble();
    sinePIDInfo.SD=ui->le_sine_D->text().toDouble();
    this->accept();
}


void CtrlDialog::on_btnQuit_clicked()
{
    this->reject();
}

void CtrlDialog::DeviceChanged(int index)
{
    ui->tabWidget->setCurrentIndex(index);
}

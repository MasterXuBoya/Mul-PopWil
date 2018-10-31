#include "ctrldialog.h"
#include "ui_ctrldialog.h"

#include "qdebug.h"
CtrlDialog::CtrlDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CtrlDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("控制参数");
    ctrlModeSet.append(QString("PID控制"));
    ctrlModeSet.append(QString("三参量控制"));
    ctrlModeSet.append(QString("PID3控制"));
    ui->cmbCtrlMode->addItems(ctrlModeSet);

    setTabOrder(ui->le_sine_P,ui->le_sine_I);
    setTabOrder(ui->le_sine_I,ui->le_sine_D);
    setTabOrder(ui->lineEdit_P,ui->lineEdit_I);
    setTabOrder(ui->lineEdit_I,ui->lineEdit_D);

    ui->cmbCtrlMode->setCurrentIndex(0);
    ui->tabWidget->setCurrentWidget(0);

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

    ui->le_fs->setText(QString::number(tvcInfo.fs));
    ui->le_fv->setText(QString::number(tvcInfo.fv));
    ui->le_fa->setText(QString::number(tvcInfo.fa));
    ui->le_bs->setText(QString::number(tvcInfo.bs));
    ui->le_bv->setText(QString::number(tvcInfo.bv));
    ui->le_ba->setText(QString::number(tvcInfo.ba));

    ui->le_pid3_sp->setText(QString::number(pid3Info.dis.SP));
    ui->le_pid3_si->setText(QString::number(pid3Info.dis.SI));
    ui->le_pid3_sd->setText(QString::number(pid3Info.dis.SD));
    ui->le_pid3_vp->setText(QString::number(pid3Info.vel.SP));
    ui->le_pid3_vi->setText(QString::number(pid3Info.vel.SI));
    ui->le_pid3_vd->setText(QString::number(pid3Info.vel.SD));
    ui->le_pid3_ap->setText(QString::number(pid3Info.acc.SP));
    ui->le_pid3_ai->setText(QString::number(pid3Info.acc.SI));
    ui->le_pid3_ad->setText(QString::number(pid3Info.acc.SD));
}

void CtrlDialog::on_btnOk_clicked()
{
    sPIDInfo.SP=ui->lineEdit_P->text().toDouble();
    sPIDInfo.SI=ui->lineEdit_I->text().toDouble();
    sPIDInfo.SD=ui->lineEdit_D->text().toDouble();

    sinePIDInfo.SP=ui->le_sine_P->text().toDouble();
    sinePIDInfo.SI=ui->le_sine_I->text().toDouble();
    sinePIDInfo.SD=ui->le_sine_D->text().toDouble();

    tvcInfo.fs=ui->le_fs->text().toDouble();
    tvcInfo.fv=ui->le_fv->text().toDouble();
    tvcInfo.fa=ui->le_fa->text().toDouble();
    tvcInfo.bs=ui->le_bs->text().toDouble();
    tvcInfo.bv=ui->le_bv->text().toDouble();
    tvcInfo.ba=ui->le_ba->text().toDouble();

    pid3Info.dis.SP=ui->le_pid3_sp->text().toDouble();
    pid3Info.dis.SI=ui->le_pid3_si->text().toDouble();
    pid3Info.dis.SD=ui->le_pid3_sd->text().toDouble();

    pid3Info.vel.SP=ui->le_pid3_vp->text().toDouble();
    pid3Info.vel.SI=ui->le_pid3_vi->text().toDouble();
    pid3Info.vel.SD=ui->le_pid3_vd->text().toDouble();

    pid3Info.acc.SP=ui->le_pid3_ap->text().toDouble();
    pid3Info.acc.SI=ui->le_pid3_ai->text().toDouble();
    pid3Info.acc.SD=ui->le_pid3_ad->text().toDouble();


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

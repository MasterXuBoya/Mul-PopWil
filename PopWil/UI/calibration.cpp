#include "calibration.h"
#include "ui_calibration.h"
#include "qstring.h"
#include "constvar.h"
#include "qmessagebox.h"

calibration::calibration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calibration)
{
    ui->setupUi(this);
    ui->led_k->setText(QString::number(g_acc_k));
    ui->led_bias->setText(QString::number(g_acc_bias));
    ui->led_k_dis->setText(QString::number(g_dis_k));
    ui->led_bias_dis->setText(QString::number(g_dis_bias));
}

calibration::~calibration()
{
    delete ui;
}

void calibration::on_btn_ok_clicked(){
    g_acc_k=ui->led_k->text().toDouble();
    g_acc_bias=ui->led_bias->text().toDouble();
    g_dis_k=ui->led_k_dis->text().toDouble();
    g_dis_bias=ui->led_bias_dis->text().toDouble();
    QMessageBox::information(NULL,"提示","参数设置成功",QMessageBox::Ok|QMessageBox::Cancel);
    this->close();
}

void calibration::on_btn_ok_2_clicked()
{
    this->close();
}

#include "sinesweepmodule.h"
#include "ui_sinesweepmodule.h"
#include "common.h"
#include "qstring.h"
#include "qdebug.h"
#include "qmessagebox.h"
#include <vector>
#include <math.h>

SineSweepModule::SineSweepModule(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SineSweepModule)
{
    ui->setupUi(this);

    this->ui->Edit_start->setFocus();
    this->ui->Edit_peak->setText("1");
    this->ui->Edit_peak->setEnabled(false);
    this->ui->Edit_sample->setText("100");
    this->ui->Edit_sample->setEnabled(false);
    this->ui->radio_linear->setChecked(true);
}

SineSweepModule::~SineSweepModule()
{
    delete ui;
}

void SineSweepModule::on_btn_close_clicked()
{
    this->close ();
}

void SineSweepModule::on_btn_generate_clicked()
{
    QString editStart=this->ui->Edit_start->text();
    QString editEnd=this->ui->Edit_end->text();
    QString editSweepTime=this->ui->Edit_sweepTime->text();
    QString editPeak=this->ui->Edit_peak->text();
    QString editSample=this->ui->Edit_sample->text();

    COMMON commonStringCheck;
    if (!commonStringCheck.isIntStr(editStart))
    {
        QString errorMessage="开始频率输入格式错误，请重新输入";
        qDebug()<<errorMessage;
        QMessageBox::information(NULL, "提示",errorMessage, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }
    if (!commonStringCheck.isIntStr(editEnd))
    {
        QString errorMessage="结束频率输入格式错误，请重新输入";
        qDebug()<<errorMessage;
        QMessageBox::information(NULL, "提示",errorMessage, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }

    if (!commonStringCheck.isIntStr(editSweepTime))
    {
        QString errorMessage="扫频时间输入格式错误，请重新输入";
        qDebug()<<errorMessage;
        QMessageBox::information(NULL, "提示",errorMessage, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }

    if (!commonStringCheck.isDigitStr(editPeak))
    {
        QString errorMessage="幅值数组输入格式错误，请重新输入";
        qDebug()<<errorMessage;
        QMessageBox::information(NULL, "提示",errorMessage, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }

    if (!commonStringCheck.isIntStr(editSample))
    {
        QString errorMessage="采样频率输入格式错误，请重新输入";
        qDebug()<<errorMessage;
        QMessageBox::information(NULL, "提示",errorMessage, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }
    int f0=editStart.toInt();
    int f1=editEnd.toInt();
    int sample=editSample.toInt();
    int sweepTime=editSweepTime.toInt();
    double peak=editPeak.toDouble();
    sweep_generator(2,f0,f1,sample,peak,sweepTime);


}

void SineSweepModule::sweep_generator(int type, int f0, int f1, int sample, double peak, int sweepTime)
{
    int i;
    const double PI = acos(-1.0);
    FILE *f;
    //vector<int> q;
    //vector<sineSweepNode> data;

    f=fopen("E://SingalGenerator//SineSweepData.txt","wt");
    if(f==NULL)
    {
       qDebug()<<"文件打开失败";
       return;
    }
    else
    {
       qDebug()<<"文件打开成功";
       fprintf(f,"时间[s]      幅值       频率[Hz]\n");
    }
    if(type==1)//线性扫频
    {
        double k=(f1-f0)*1.0/sweepTime;
        int total_point=sample*sweepTime;
        for(i=0;i<=total_point;i++)
        {
            double time=i*1.0/sample;
            double theta=PI*k*time*time+2*PI*f0*time;
            double value=peak*sin(theta);
            double fre=f0+k*time;
            //data.push_back(sineSweepNode(time,value,fre));
            fprintf(f,"%.6lf  %.6lf  %.6lf\n",time,value,fre);
            if(i==1)
                qDebug()<<time<<" "<<theta<<" "<<value<<" "<<fre;
        }
    }
    else//对数扫频
    {
        double k=exp(log(f1*1.0/f0)/sweepTime);
        int total_point=sample*sweepTime;
        for(i=0;i<=total_point;i++)
        {
            double time=i*1.0/sample;
            double theta=2*PI*f0/log(k)*(pow(k,time)-1);
            double value=peak*sin(theta);
            double fre=f0*pow(k,time);
            //data.push_back(sineSweepNode(time,value,fre));
            fprintf(f,"%.6lf  %.6lf  %.6lf\n",time,value,fre);
        }

    }
    QString successMessage="扫频数据保存成功，位置在E:/SingalGenerator/SineSweepData.txt";
    qDebug()<<successMessage;
    QMessageBox::information(NULL, "提示",successMessage, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    fclose(f);
}

void SineSweepModule::on_btn_clear_clicked()
{
    this->ui->Edit_start->setText("");
    this->ui->Edit_end->setText("");
    this->ui->Edit_sweepTime->setText("");
}

void SineSweepModule::on_checkBox_2_clicked()
{
    if(this->ui->checkBox_2->isChecked()==true)
        ui->Edit_peak->setEnabled(true);
    else
        ui->Edit_peak->setEnabled(false);
}

void SineSweepModule::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked()==true)
        ui->Edit_sample->setEnabled(true);
    else
        ui->Edit_sample->setEnabled(false);
}

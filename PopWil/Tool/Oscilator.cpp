#include "Oscilator.h"
#include "QDebug"
Oscilator::Oscilator()
{
    srand((int)time(0));
}
Oscilator::~Oscilator(){}

void Oscilator::caculateSine(TSineWaveInfo para){
    double mid    =para.mid;//中心坐标
    double mag    =para.mag;//幅值
    double fs     =para.fs;//频率
    double sineCnt=para.sineCnt;//重复次数
    //生成参考波形
    refData.refCnt=0;refData.dataRefSampleT=systemInfo.contrlInterval;
    double elapseStartTime=0,sRef,sRef_=0,vRef=0,vRef_=0;
    while(true){
        if(elapseStartTime>3+sineCnt/fs) break;
        if(elapseStartTime<=3){//3s启动时间
            sRef=mag/(3+1/fs/4)*elapseStartTime*sin(2*PI*fs*elapseStartTime)+mid;
            refData.SRef[++refData.refCnt]=sRef;
            vRef=(sRef-sRef_)/(systemInfo.contrlInterval*1.0/1000);
            refData.VRef[refData.refCnt]=vRef;
            refData.ARef[refData.refCnt]=(vRef-vRef_)/(systemInfo.contrlInterval*1.0/1000)/10000;
            sRef_=sRef;vRef_=vRef;
        }
        else {
            refData.SRef[++refData.refCnt]=mag*sin(2*PI*fs*elapseStartTime)+mid;
            refData.VRef[refData.refCnt]=mag*2*PI*fs*cos(2*PI*fs*elapseStartTime);
            refData.ARef[refData.refCnt]=-mag*4*PI*PI*fs*fs*sin(2*PI*fs*elapseStartTime)/10000;
        }
        elapseStartTime += refData.dataRefSampleT*1.0/1000;
    }
}

void Oscilator::caculateSineSweep(QString path){
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"正弦扫频信号文件"+path+"文件打开失败";
        return;
    }
    qDebug()<<"正弦扫频信号"+path+"打开成功！";
    int cnt=0;
    double SRef_=0,VRef_=0;
    QTextStream in(&file);
    while (!in.atEnd()) {
        cnt++;
        QString line = in.readLine();
        line=line.trimmed();//去掉两端空格
        line=line.simplified();//将连续的空格转化成一个
        QStringList lines=line.split(" ");//分割
        if(cnt==1){
            refData.dataRefSampleT=lines[1].toInt();
            continue;
        }
        if(cnt==2) continue;
        int i=cnt-2;
        refData.SRef[i]=lines[1].toDouble();
        refData.VRef[i]=(refData.SRef[i]-SRef_)/(refData.dataRefSampleT/1000.0);
        refData.ARef[i]=(refData.VRef[i]-VRef_)/(refData.dataRefSampleT/1000.0);
        SRef_=refData.SRef[i];
        VRef_=refData.VRef[i];
    }
    refData.refCnt=cnt-2;
}

void Oscilator::caculateRandom(double mag){
    refData.refCnt=10000;refData.dataRefSampleT=5;
    for(int i=1;i<10000;i++)
        refData.SRef[i]=mag*(random(1000)*1.0/500-1);
}

void Oscilator::caculateTriangle(TSineWaveInfo para){
    double mid    =para.mid;//中心坐标
    double mag    =para.mag;//幅值
    double fs     =para.fs;//频率
    double sineCnt=para.sineCnt;//重复次数
    refData.refCnt=0;refData.dataRefSampleT=systemInfo.contrlInterval;
    double elapseStartTime=0,sRef,sRef_=0,vRef=0,vRef_=0;
    double k=mag*4*fs;//斜率
    while(elapseStartTime<=1.0/fs){//计算第一个周期
        if(elapseStartTime<1.0/(4*fs))
            refData.SRef[++refData.refCnt]=k*elapseStartTime+mid;
        else if(elapseStartTime<3.0/(4*fs))
            refData.SRef[++refData.refCnt]=k*(0.5/fs-elapseStartTime)+mid;
        else
           refData.SRef[++refData.refCnt]=k*(elapseStartTime-1/fs)+mid;
        elapseStartTime += refData.dataRefSampleT/1000.0;
    }
    while(elapseStartTime<=sineCnt/fs){//利用周期性计算
        refData.SRef[++refData.refCnt]=refData.SRef[refData.refCnt-(int)(1000/fs/refData.dataRefSampleT)];
        elapseStartTime+=refData.dataRefSampleT/1000.0;
    }
}



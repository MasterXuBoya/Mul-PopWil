#include "constvar.h"
#include "QDebug"
#include <QString>
#include "logger.h"

#define AFILTERNUM 10
double sBuf[11]={0};
double vBuf[11]={0};

TPIDInfo sPIDInfo,sinePIDInfo;//静态控制PID三个参数
TSystemInfo systemInfo;//系统参数
QDoubleBufferedQueue<DataPacket> buffer;//每组数据有三个
TFlag globalFlag=DefaultFlag;//控制模式标志位

int dataCnt=0,dataRefCnt=0;
double SRefArray[MAXDATACOUNT],SArray[MAXDATACOUNT];
double VRefArray[MAXDATACOUNT],VArray[MAXDATACOUNT];
double ARefArray[MAXDATACOUNT],AArray[MAXDATACOUNT];
double OutUPreArray[MAXDATACOUNT],OutUArray[MAXDATACOUNT];
double ErrorPreArray[MAXDATACOUNT],ErrorArray[MAXDATACOUNT];

//int ss=18;
//QString str="Hello";
//const int m=19;
int sum(int a,int b)
{
    int c;
    c=a+b;
    return c;
}

double S_AVFilter(double ADValue)
{
    int i;
    double sumS,minS,maxS,result;
    sBuf[0]++;
    sumS=0;
    for (i=1;i<AFILTERNUM;i++)
        sBuf[i]=sBuf[i+1];
    sBuf[AFILTERNUM]=ADValue;
    minS=sBuf[1];
    maxS=sBuf[1];
    for(i=1;i<=AFILTERNUM;i++)
    {
        sumS+=sBuf[i];
        if (sBuf[i]>maxS)
            maxS=sBuf[i];
        if (sBuf[i]<minS)
            minS=sBuf[i];
    }
    if (sBuf[0]<AFILTERNUM)
        result=sumS/sBuf[0];
    else
        result=(sumS-minS-maxS)/(AFILTERNUM-2);
    return result;
}

double V_AVFilter(double ADValue)
{
    int i;
    double sumS,minS,maxS,result;
    vBuf[0]++;
    sumS=0;
    for (i=1;i<AFILTERNUM;i++)
        vBuf[i]=vBuf[i+1];
    vBuf[AFILTERNUM]=ADValue;
    minS=vBuf[1];
    maxS=vBuf[1];
    for(i=1;i<=AFILTERNUM;i++)
    {
        sumS+=vBuf[i];
        if (vBuf[i]>maxS)
            maxS=vBuf[i];
        if (vBuf[i]<minS)
            minS=vBuf[i];
    }
    if (vBuf[0]<AFILTERNUM)
        result=sumS/vBuf[0];
    else
        result=(sumS-minS-maxS)/(AFILTERNUM-2);
    return result;
}

Matrix matrixMultiply(Matrix a,Matrix b)
{
    int i,j,k;
    double sum;
    Matrix c;
    c.row=a.row;
    c.column=b.column;
    for (i=0;i<c.row;i++)
        for (j=0;j<c.column;j++)
        {
            sum=0;
            for (k=0;k<a.column;k++)
                sum+=a.data[i][k]*b.data[k][j];
            c.data[i][j]=sum;
        }
     return c;
}

QString CheckError(ErrorCode errorCode)
{
    if (BioFailed(errorCode)) {
        QString message = QString("Sorry, there are some errors occurred, Error Code: 0x") +
            QString::number(errorCode, 16).right(8).toUpper();
        qDebug()<<message;
        Logger *logger=Logger::getInstance();
        logger->appendLogger("[error] "+message);
        return QString("success");
    }
    return QString("fail");
}

QStringList getFileNames(const QString &path)
{
    QDir dir(path);
    QStringList nameFilters;
    nameFilters << "*.txt";
    QStringList files = dir.entryList(nameFilters);
//    qDebug()<<files.size();
//    for(int i=0;i<files.size();i++)
//        qDebug()<<files[i];
    return files;
}

void getEarthquakeWave(const QString &path){
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"地震波文件"+path+"文件打开失败";
        return;
    }
    qDebug()<<"地震波文件"+path+"打开成功！";
    int cnt=0,interval;
    QTextStream in(&file);
    while (!in.atEnd()) {
        cnt++;
        QString line = in.readLine();
        line=line.trimmed();//去掉两端空格
        line=line.simplified();//将连续的空格转化成一个
        QStringList lines=line.split(" ");//分割
        if(cnt==1){
            //qDebug()<<lines[1];
            interval=lines[1].toInt();
            continue;
        }
        if(cnt==2) continue;
        int i=lines[0].toInt();
        SRefArray[i]=lines[1].toDouble();
        VRefArray[i]=lines[2].toDouble();
        ARefArray[i]=lines[3].toDouble();
    }
    dataRefCnt=cnt-2;
    //qDebug()<<dataRefCnt<<"       "<<interval;
}





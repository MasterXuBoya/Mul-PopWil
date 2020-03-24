#include "constvar.h"
#include "QDebug"
#include <QString>
#include "logger.h"


double g_acc_k=1,g_acc_bias=0;
double g_dis_k=1,g_dis_bias=0;
bool ssiEnable=true;
ToolFromMatlab matlabHandler;

TPIDInfo sPIDInfo,sinePIDInfo,accPIDInfo;//静态控制、位移PID、加速度PID参数
TPID3Info pid3Info;//位移、速度、加速度PID控制
TPID3Weight pid3Weight;
TTVCInfo tvcInfo;//三参量控制的六个参数，前馈三个，反馈三个
TSystemInfo systemInfo;//系统参数
QDoubleBufferedQueue<DataPacket> buffer;//每组数据有三个

TWaveMode waveMode,waveModeTmp;//要控制的波形
TControlMethod controlMethod;//控制方法，对于一个波形存在多种控制方法

TDisplayDelay displayDelay={2,25,2};
TDrawType drawType=DisType;//判断动态绘图的是位移、速度还是加速度，以便于改变标题和单位

int dataCnt=0,dataRefCnt=0,iterationIndex=0;
double SRefArray[MAXDATACOUNT],SArray[MAXDATACOUNT];
double VRefArray[MAXDATACOUNT],VArray[MAXDATACOUNT];
double ARefArray[MAXDATACOUNT],AArray[MAXDATACOUNT];
double OutUPreArray[MAXDATACOUNT],OutUArray[MAXDATACOUNT];
double ErrorPreArray[MAXDATACOUNT],ErrorArray[MAXDATACOUNT];
TRefData refData,ydData,segData,refSegData;
int segCnt=0;
TRefData segsData[10],refsData[10];
TModel systemModel;

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
    int cnt=0;
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
        int i=lines[0].toInt();
        //refData.SRef[i]=lines[1].toDouble();
        //refData.VRef[i]=lines[2].toDouble();
        refData.ARef[i]=lines[3].toDouble();
    }
    refData.refCnt=cnt-2;
}


////------------------------------------读取加速度-------------------------
//aCurrent=aiStreaming->getAcc();//通过SteamingAi方式获取加速度
//aCurrent=aAvgFilter->filter(aCurrent);//简单滑动滤波
//aCurrent=aButtorFilter->filter(aCurrent);
////--------------------位移、速度、加速度过大保护--------------------
////为了防止程序跑飞，造成很大的噪音，加速度超过3g即立即停止试验
//if(fabs(sCurrent)>systemInfo.maxAbsolutePosition||fabs(vCurrent)>systemInfo.maxAbsoluteVel\
//        ||fabs(aCurrent)>systemInfo.maxAbsoluteAcc){
//    outUToPCI(0.0);
//    return;//查看位移(速度/加速度)发现过大，直接跳出定时器，等待手动输出电压调节
//}


#ifndef CONSTVAR_H
#define CONSTVAR_H

#include "QString"
#include "bdaqctrl.h"
#include "qdoublebufferedqueue.h"
#include "QDir"
#include "qstringlist.h"

#define PI  3.1415926535898

using namespace Automation::BDaq;
#define MAXDATACOUNT 120000//每秒200个数据，100分钟
//------------------------------------------------------------------
//定义结构型变量
struct ConfigureParameterAO
{
    QString deviceName;//设备标识
    int channelCount;//通道个数
    int channelStart;//起始通道
    ValueRange valueRange;//通道输出电压范围：1表示-10V~10V
    const wchar_t* profilePath;
};

struct ConfigureParameterAI
{
    QString deviceName;
    int channelCount;
    int channelStart;
    ValueRange valueRange;
    int32 clockRatePerChan;
    int32 sectionLength;
    const wchar_t* profilePath;
};

struct ConfigureParameterPCI
{
    ConfigureParameterAI iniSettingAI;
    ConfigureParameterAO iniSettingAO;
};

struct TPIDInfo
{
    double SP;
    double SI;
    double SD;
};
extern TPIDInfo sPIDInfo,sinePIDInfo;

struct TSystemInfo
{
    int contrlInterval;
    int drawInterval;
    double maxAbsolutePosition;
    double maxOutU;
};
extern TSystemInfo systemInfo;
struct Matrix
{
    int row;
    int column;
    double data[10][10];
};
// A thread-safe queue with minimal read/write contention
struct DataPacket
{
    double elapsedTime;
    double series0;
    double series1;
    DataPacket(){}
    DataPacket(double elapsedTime_,double series0_,double series1_):elapsedTime(elapsedTime_),series0(series0_),series1(series1_){}
};
extern QDoubleBufferedQueue<DataPacket> buffer;//每组数据有三个
enum TFlag{
    DefaultFlag,//表示没有进入任何一个控制模式
    StaticPosionFlag,//静态位移控制
    SineWaveFlag,//正弦波位移控制
    IterativeFlag
};
extern TFlag globalFlag;
//------------------------------------------------------------------
//全局变量
/*
extern int ss;
extern QString str;
extern TChannelCoef tchannelcoef;
//使用static定义的全局变量是局部全局变量，用extern定义的是真正意义上的全局变量
//------------------------------------------------------------------
//全局常量
extern const int m;
//------------------------------------------------------------------
//全局函数,这种全局函数可以集成到类里面，也可以直接用这样的方式进行全局调用
int sum(int a,int b);

*/

//vector会在运行过程中复制数组，造成运算效率下降，还是使用原生态数组吧
//extern std::vector<double> SRefArray[MAXDATACOUNT];

extern int dataCnt,dataRefCnt;
extern double SRefArray[MAXDATACOUNT],SArray[MAXDATACOUNT];
extern double VRefArray[MAXDATACOUNT],VArray[MAXDATACOUNT];
extern double ARefArray[MAXDATACOUNT],AArray[MAXDATACOUNT];
extern double OutUPreArray[MAXDATACOUNT],OutUArray[MAXDATACOUNT];
extern double ErrorPreArray[MAXDATACOUNT],ErrorArray[MAXDATACOUNT];

QString CheckError(ErrorCode errorCode);

Matrix matrixMultiply(Matrix a,Matrix b);

QStringList getFileNames(const QString &path);
void getEarthquakeWave(const QString &path);
#endif // CONSTVAR_H

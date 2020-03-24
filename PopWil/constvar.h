#ifndef CONSTVAR_H
#define CONSTVAR_H

#include "QString"
#include "bdaqctrl.h"
#include "qdoublebufferedqueue.h"
#include "QDir"
#include "qstringlist.h"
#include "ToolFromMatlab.h"
#include "vector"

#define PI  3.1415926535898
#define ACCSENSORCOUNT 2//加速度传感器数量
#define DISSENSORCOUNT 3//位移传感器数量

using namespace Automation::BDaq;
using namespace std;
#define MAXDATACOUNT 300000//每秒100个数据，50分钟
//------------------------------------------------------------------
//传感器校准
extern double g_acc_k,g_acc_bias;
extern double g_dis_k,g_dis_bias;
extern bool ssiEnable;

extern ToolFromMatlab matlabHandler;
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
    TPIDInfo(){

    }
    TPIDInfo(double p,double i,double d){
        SP=p;SI=i;SD=d;
    }
};
extern TPIDInfo sPIDInfo,sinePIDInfo,accPIDInfo;//全局变量，位移PID控制参数

struct TPID3Info{
    TPIDInfo dis;
    TPIDInfo vel;
    TPIDInfo acc;
};
extern TPID3Info pid3Info;

struct TPID3Weight{
    double ws;
    double wv;
    double wa;
    void setDate(double ws_,double wv_,double wa_){
        ws=ws_;wv=wv_;wa=wa_;
    }
};
extern TPID3Weight pid3Weight;

struct TTVCInfo//三参量参数类型
{
    double fs,fv,fa;//前馈
    double bs,bv,ba;//反馈
};
extern TTVCInfo tvcInfo;

struct TStateInfo{
    double S,V,A;
    TStateInfo(){}
    TStateInfo(double S_,double V_,double A_):S(S_),V(V_),A(A_){}//构造函数
};

struct TSystemInfo
{
    int contrlInterval;//控制周期
    int drawInterval;//绘图周期
    double maxOutUDebug;//Debug输出限幅
    double maxOutU;//最大输出限幅
    double maxAbsoluteForce;//最大推力
    double maxAbsolutePosition;//最大位移
    double maxAbsoluteVel;//最大速度
    double maxAbsoluteAcc;//最大加速度
    double maxLoadWeight;//最大负载质量

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
enum TWaveMode{
    DefaultFlag,//表示没有进入任何一个控制模式
    StaticPosionFlag,//静态位移控制
    SineWaveFlag,//正弦波位移控制
    SineSweepFlag,//正弦扫描
    RandomFlag,//随机波
    TriangleFlag,//三角波
    EarthquakeFlag
};
extern TWaveMode waveMode,waveModeTmp;
enum TControlMethod{
    PIDMethod,
    ACCPIDMethod,
    Para3Method,
    PID3Method,
    IterativeMethod
};
extern TControlMethod controlMethod;

struct TSineWaveInfo{
    double mid ;//中心坐标
    double mag ;//幅值
    double fs  ;//频率
    double sineCnt;//重复次数
    TSineWaveInfo(double mid_,double mag_,double fs_,double sineCnt_):
    mid(mid_),mag(mag_),fs(fs_),sineCnt(sineCnt_){}
};
struct TDisplayDelay{//位移、速度、加速度延迟绘图参数
    int sDelay,vDelay,aDelay;
};
extern TDisplayDelay displayDelay;

enum TDrawType{
    DisType,
    VelType,
    AccType,
};
extern TDrawType drawType;//判断动态绘图的是位移、速度还是加速度，以便于改变标题和单位
struct TModel{//系统辨识模型
    int Nfft;//数据长度为Nfft/2+1
    int Fs;
    double Txy_real[2048];
    double Txy_imag[2048];
    double F[2048];
};
extern TModel systemModel;
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
extern int iterationIndex;
extern double SRefArray[MAXDATACOUNT],SArray[MAXDATACOUNT];
extern double VRefArray[MAXDATACOUNT],VArray[MAXDATACOUNT];
extern double ARefArray[MAXDATACOUNT],AArray[MAXDATACOUNT];
extern double OutUPreArray[MAXDATACOUNT],OutUArray[MAXDATACOUNT];
extern double ErrorPreArray[MAXDATACOUNT],ErrorArray[MAXDATACOUNT];

struct TRefData{
    int refCnt;//采样点数
    int dataRefSampleT;//采样时间 unit ms
    double SRef[MAXDATACOUNT];
    double VRef[MAXDATACOUNT];
    double ARef[MAXDATACOUNT];
};
//内环系统参考信号
extern TRefData ydData;//真正的参考信号yd，一般只有加速度信号
extern TRefData refData;//自己生成，或者载入外部的参考波形
extern TRefData segData;//每一段实际采集到的波形，与refSegData对应
//当ydData采样频率为100Hz时，refData和refSegData一样
//当ydData采样频率为1000Hz时，refData为1000Hz，refSegData为100Hz
extern TRefData refSegData;
extern int segCnt;
extern TRefData segsData[10];
extern TRefData refsData[10];

QString CheckError(ErrorCode errorCode);

Matrix matrixMultiply(Matrix a,Matrix b);

QStringList getFileNames(const QString &path);
void getEarthquakeWave(const QString &path);
#endif // CONSTVAR_H

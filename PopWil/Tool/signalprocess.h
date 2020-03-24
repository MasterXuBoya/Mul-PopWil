#ifndef SIGNALPROCESS_H
#define SIGNALPROCESS_H
#include "constvar.h"
#include "QDebug"
#include "math.h"

class SignalProcess
{
public:
    SignalProcess();
    //calculate the DFT of IN[] using FFT Algrithm,return complex array
    void fft(int N,double input[],double output[][2]);
    //calculate the ifft()
    void ifft(int N,double input[][2],double output[]);
    //given a complex array,calculating the Amp and phase
    void fft_Amp_phase(int N,double output[][2],double Amp[],double phase[]);
    //return the power spectrum
    void power_spectrum(int N,double Amp[],double power[]);
    //Integrate in frequency----通用频域积分函数
    /***
     * N：原始数据采样点数
     * fs:采样频率，Unit Hz
     * X:原始数据
     * Y:积分后数据
     *
     * note：X[0---N-1]---------->Y[0---N-1]
    */
    void inteFD(int &N, int fs,double X[], double Y[]);
    //通过加速度得到速度，位移
    /***
     * N：加速度数据采样点数
     * fs:采样频率，Unit Hz
     * X:加速度数据
     * Y:积分后地震波数据，包含采样频率、点数、位移、速度、加速度
     * note：X[0---N-1]---------->Y[0---N-1]
    */
    void inteFD_All(int N,int fs,double Acc[],TRefData *data);
    //自相关函数---计算一项的值
    double AutoCorrelation(double *data, int m, int N);
    /***自相关函数
     * in:输入数据，长度为lenth
     * out：输出数据，长度为2*lenth-1，且左右对称
    */
    void autoXcorr_func(double *in,double *out,int lenth);
    /***互相关函数
     * x,y:输入数据，长度为N
     * r：输出数据，长度为2*N-1,且不对称
    */
    void crossXcorr_func(double *x,double *y, int N,double *r);
    //方差,此处方差没有除以N，且没有开平方
    double varForArray(double *x, int count);
    //相关系数
    double coeff(double *x, double *y, int count);
    /***
     * 拉格朗日四点插值算法------三次多项式
     * origin:原始地震波数据，采样间隔较大
     * newData：新的地震波数据，采样间隔较小
     * sampleT:新的采样间隔，1——2ms
    */
    void lagrangeInterpolation(int n,int originSampleT,double origin[],TRefData *newData,int sampleT);
    void constTest(const int &n,const double *in,double *out);
};

#endif // SIGNALPROCESS_H


#ifndef SIGNALPROCESS_H
#define SIGNALPROCESS_H
#include "constvar.h"
#include "QDebug"

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
    //Integrate in frequency
    /***
     * N：加速度采样点数
     * fs:采样频率，Unit Hz
     * X:原始数据
     * Y:积分后数据
    */
    void inteFD(int &N, int fs,double X[], double Y[]);
    //通过加速度得到速度，位移
    void inteFD_All(int N,int fs,double Acc[],TRefData *data);
};

#endif // SIGNALPROCESS_H

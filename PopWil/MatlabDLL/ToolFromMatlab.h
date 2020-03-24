#ifndef TOOLFROMMATLAB_H
#define TOOLFROMMATLAB_H

#include "qdebug.h"
#include "qlibrary.h"
#include "EarthPreprocess.h"
#include "WaveResample.h"
#include "transformFunction.h"
#include "generateFirstDrive.h"
#include "IterativeMode.h"
//对加速度进行极限校准、Buttor4阶滤波，积分得到速度和位移
typedef void MW_CALL_CONV (* EARTHPREPROCESS) (int nargout, mwArray& corr_a, mwArray& corr_v, mwArray& corr_s, const mwArray& data, const mwArray& Fs);
//重采样newData=resample(data,q,p)
typedef void MW_CALL_CONV (* WAVERESAMPLE)(int nargout, mwArray& y, const mwArray& x, const mwArray& q, const mwArray& p);
//计算系统频域响应
typedef void MW_CALL_CONV (*TRANSFORMFUNCTION)(int nargout, mwArray& Txy, mwArray& F, const mwArray& x, const mwArray& y, const mwArray& nfft, const mwArray& fs);
//直通模式下计算驱动信号
typedef void MW_CALL_CONV (*GENERATEFIRSTDRIVE)(int nargout, mwArray& newX, const mwArray& Txy, const mwArray& F, const mwArray& yd, const mwArray& nfft, const mwArray& Fs);
//迭代模式计算驱动信号
//Nfft通常为1024,Fs通常为10
typedef void MW_CALL_CONV (*ITERATIVEMODE)(int nargout, mwArray& newX, const mwArray& Txy, const mwArray& F, const mwArray& yd, const mwArray& y, const mwArray& X, const mwArray& nfft, const mwArray& Fs, const mwArray& alpha);

class ToolFromMatlab
{
public :
    ToolFromMatlab();
    ~ToolFromMatlab();
    void init();//所有从MATLAB导入函数的Initialize，可能比较耗时
    EARTHPREPROCESS earthPreprocess;//函数指针
    WAVERESAMPLE waveSample;
    TRANSFORMFUNCTION transformFunction;
    GENERATEFIRSTDRIVE generateFirstDrive;
    ITERATIVEMODE IterativeMode;
};

#endif // TOOLFROMMATLAB_H

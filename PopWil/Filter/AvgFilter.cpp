#include "AvgFilter.h"

AvgFilter::AvgFilter()
{
    buffer=new double[MAXFILTERCNT];
    memset(buffer,0,MAXFILTERCNT);
    avgFilterIndex=dataCnt=sum=0;
}

AvgFilter::~AvgFilter(){
    delete[] buffer;
}
double AvgFilter::filter(double value){
    dataCnt++;
    //开辟环形缓冲区，在O(1)的时间内计算出结果
    avgFilterIndex=(avgFilterIndex+1)%MAXFILTERCNT;
    sum=sum-buffer[avgFilterIndex]+value;
    buffer[avgFilterIndex]=value;
    if (dataCnt<MAXFILTERCNT)//最前面10个数据
        return sum/dataCnt;
    return sum/MAXFILTERCNT;
}


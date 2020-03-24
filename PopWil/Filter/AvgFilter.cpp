#include "AvgFilter.h"

AvgFilter::AvgFilter(){
}

AvgFilter::AvgFilter(int lag){
    MAXFILTERCNT=lag;
    buffer=new double[MAXFILTERCNT];
    for(int i=0;i<MAXFILTERCNT;i++)
        buffer[i]=0;
    avgFilterIndex=-1;
    dataCnt=sum=0;
}

void AvgFilter::setLag(int lag){
    MAXFILTERCNT=lag;
    buffer=new double[MAXFILTERCNT];
    for(int i=0;i<MAXFILTERCNT;i++)
        buffer[i]=0;
    avgFilterIndex=-1;
    dataCnt=sum=0;
}

AvgFilter::~AvgFilter(){
    delete[] buffer;
}
double AvgFilter::filter(double value){
    double result;
    dataCnt++;
    //开辟环形缓冲区，在O(1)的时间内计算出结果
    avgFilterIndex=(avgFilterIndex+1)%MAXFILTERCNT;
    sum=sum-buffer[avgFilterIndex]+value;
    buffer[avgFilterIndex]=value;
    if (dataCnt<MAXFILTERCNT)//最前面10个数据
        result=sum/dataCnt;
    else result=sum/MAXFILTERCNT;
    return result;
}


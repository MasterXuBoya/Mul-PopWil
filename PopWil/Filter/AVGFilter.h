#ifndef AVGFILTER_H
#define AVGFILTER_H

#include<QDebug>
class AvgFilter
{
public:
    AvgFilter();
    virtual ~AvgFilter();
    double filter(double value);//将value滤波后输出的结果
private:
    int avgFilterIndex,dataCnt;
    static const int MAXFILTERCNT=10;
    double *buffer;
    double sum;
};

#endif // AVGFILTER_H

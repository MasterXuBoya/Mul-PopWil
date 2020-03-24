#ifndef AVGFILTER_H
#define AVGFILTER_H

#include<QDebug>
class AvgFilter
{
public:
    AvgFilter();//一定要存在默认构造函数
    AvgFilter(int lag);
    virtual ~AvgFilter();
    void setLag(int lag);
    double filter(double value);//将value滤波后输出的结果
private:
    int avgFilterIndex,dataCnt;
    int MAXFILTERCNT;
    double *buffer;
    double sum;
};

#endif // AVGFILTER_H

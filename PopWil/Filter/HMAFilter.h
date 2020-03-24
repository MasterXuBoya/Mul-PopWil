#ifndef HMAFILTER_H
#define HMAFILTER_H

#include "qdebug.h"
#include "AVGFilter.h"
#include "math.h"

class HMAFilter
{
public:
    HMAFilter();
    HMAFilter(int lag);
    ~HMAFilter();
    double filter(double value);
private:
    int m_T;
    AvgFilter *m_filter_T;//Lag=T;
    AvgFilter *m_filter_half;//Lag=T/2;
    AvgFilter *m_filter_sqrtT;//Lag=Sqrt(T);
};

#endif // HMAFILTER_H

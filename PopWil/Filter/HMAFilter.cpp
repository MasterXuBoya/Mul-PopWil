#include "HMAFilter.h"

HMAFilter::HMAFilter()
{

}
HMAFilter::HMAFilter(int lag):m_T(lag){
    m_filter_T=new AvgFilter(m_T);
    m_filter_half=new AvgFilter((int)m_T/2);
    m_filter_sqrtT=new AvgFilter((int)sqrt(m_T));
}

HMAFilter::~HMAFilter(){
    delete m_filter_T;
    delete m_filter_half;
    delete m_filter_sqrtT;
}

double HMAFilter::filter(double value){
    double value_T=m_filter_T->filter(value);
    double value_half=m_filter_half->filter(value);
    double value_process=value_half*2-value_T;
    return m_filter_sqrtT->filter(value_process);
}

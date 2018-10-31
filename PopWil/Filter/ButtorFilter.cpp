/* Digital filter designed by mkfilter/mkshape/gencode   A.J. Fisher
   Command line: /www/usr/fisher/helpers/mkfilter -Bu -Lp -o 4 -a 3.0000000000e-02 0.0000000000e+00 -l */
#include "ButtorFilter.h"
#include <cstring>
ButtorFilter::ButtorFilter()
{
    for(int i=0;i<=NZEROS;i++)
        xv[i]=yv[i]=0;
}

ButtorFilter::~ButtorFilter(){

}

double ButtorFilter::filter(double value){
    xv[0] = xv[1]; xv[1] = xv[2]; xv[2] = xv[3]; xv[3] = xv[4];
    xv[4] = value/ GAIN;
    yv[0] = yv[1]; yv[1] = yv[2]; yv[2] = yv[3]; yv[3] = yv[4];
    yv[4] =   (xv[0] + xv[4]) + 4 * (xv[1] + xv[3]) + 6 * xv[2]
                 + ( -0.6105348076 * yv[0]) + (  2.7426528211 * yv[1])
                 + ( -4.6409024127 * yv[2]) + (  3.5077862074 * yv[3]);
    return yv[4];
}

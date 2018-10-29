#include "mathtool.h"
#include "math.h"
#include "qdebug.h"

MathTool::MathTool()
{

}

double MathTool::varForArray(double *x, int count)
{
    int i;
    double result=0,xAvg=0;
    for (i=0;i<count;i++)
        xAvg+=*(x+i);
    xAvg/=count;
    for (i=0;i<count;i++)
        result+=(*(x+i)-xAvg)*(*(x+i)-xAvg);
    return result;
}


double MathTool::coeff(double *x, double *y, int count)
{
    int i,j;
    double xAvg=0,yAvg=0,cov=0,result=0;
    for (i=0;i<count;i++)
    {
        xAvg+=*(x+i);
        yAvg+=*(y+i);
    }
    xAvg/=count;
    yAvg/=count;
    for(i=0;i<count;i++)
        cov+=(*(x+i)-xAvg)*(*(y+i)-yAvg);
    if(varForArray(x,count)==0||varForArray(y,count)==0)
        result=-2;
    else
        result=cov/(sqrt(varForArray(x,count))*sqrt(varForArray(y,count)));
    return result;
}

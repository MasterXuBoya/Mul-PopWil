#ifndef CONSTVAR_H
#define CONSTVAR_H

#include "QString"
//********************************************************************
//定义结构型变量
typedef struct
{
    int a;
    int b;
    int c;
    int d;

}TChannelCoef;
//********************************************************************
//全局变量
extern int ss;
extern int min;
extern QString str;
extern TChannelCoef tchannelcoef;
//使用static定义的全局变量是局部全局变量，用extern定义的是真正意义上的全局变量
//********************************************************************
//全局常量
extern const int m;
//********************************************************************
//全局函数,这种全局函数可以集成到类里面，也可以直接用这样的方式进行全局调用
int sum(int a,int b);



#endif // CONSTVAR_H

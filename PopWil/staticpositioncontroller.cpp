#include "staticpositioncontroller.h"
#include "math.h"
#include "constvar.h"

StaticPositionController::StaticPositionController()
{
    uk=uk_1=ek=ek_1=ek_2=0;
    speed=0.05;
}

void StaticPositionController::configure(double x_static_des_, double static_PosVref_){
    x_static_des=x_static_des_;
    static_PosVref=static_PosVref_;
}

double StaticPositionController::getUk(double currentPosition, double &refPosition){
    if(fabs(static_PosVref-x_static_des)<0.2)
        static_PosVref=x_static_des;
    else
    {
        if(static_PosVref<x_static_des)
            static_PosVref+=speed*systemInfo.contrlInterval;
        else
            static_PosVref-=speed*systemInfo.contrlInterval;
    }
    refPosition=static_PosVref;//将参考位移返回到MainWindow函数

    ek=static_PosVref-currentPosition;
    double duk=sPIDInfo.SP*(ek-ek_1)+sPIDInfo.SI*ek+sPIDInfo.SD*(ek-2*ek_1+ek_2);
    duk=duk>0.5?0.5:duk;
    duk=duk<-0.5?-0.5:duk;

    uk=duk+uk_1;

    ek_2=ek_1;
    ek_1=ek;
    uk_1=uk;
    return uk;
}

void StaticPositionController::clear(){
    uk=uk_1=ek=ek_1=ek_2=0;
}

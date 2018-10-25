#include "sinepositioncontroller.h"

SinePositionController::SinePositionController()
{
    uk=uk_1=ek=ek_1=ek_2=0;
}

void SinePositionController::clear(){
    uk=uk_1=ek=ek_1=ek_2=0;
}

double SinePositionController::getUk(double currentPosition, double refPosition){
    ek=refPosition-currentPosition;
    double duk=sinePIDInfo.SP*(ek-ek_1)+sinePIDInfo.SI*ek+sinePIDInfo.SD*(ek-2*ek_1+ek_2);
    duk=duk>0.5?0.5:duk;
    duk=duk<-0.5?-0.5:duk;

    uk=duk+uk_1;

    ek_2=ek_1;
    ek_1=ek;
    uk_1=uk;
    return uk;
}

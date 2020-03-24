#include "PIDController.h"

PIDController::PIDController()
{
    uk=uk_1=ek=ek_1=ek_2=0;
}

PIDController::~PIDController(){

}

void PIDController::clear(){
    uk=uk_1=ek=ek_1=ek_2=0;
}

void PIDController::setPIDPara(TPIDInfo value){
    para_P=value.SP;para_I=value.SI;para_D=value.SD;
}

double PIDController::getUk(double refPosition, double currentPosition){
    ek=refPosition-currentPosition;
    double duk=para_P*(ek-ek_1)+para_I*ek+para_D*(ek-2*ek_1+ek_2);
    double MAXDUK=3;
    duk=duk>MAXDUK?MAXDUK:duk;
    duk=duk<-MAXDUK?-MAXDUK:duk;

    uk=duk+uk_1;

    ek_2=ek_1;
    ek_1=ek;
    uk_1=uk;

    uk=uk>systemInfo.maxOutU?systemInfo.maxOutU:uk;
    uk=uk<-systemInfo.maxOutU?-systemInfo.maxOutU:uk;

    return uk;
}

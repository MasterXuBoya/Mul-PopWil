#include "PID3Controller.h"

PID3Controller::PID3Controller()
{
    sHandler=new PIDController();
    vHandler=new PIDController();
    aHandler=new PIDController();
}

PID3Controller::~PID3Controller(){
    delete sHandler;
    delete vHandler;
    delete aHandler;
}

void PID3Controller::setPara(TPID3Info para_){
    sHandler->setPIDPara(para_.dis);
    vHandler->setPIDPara(para_.vel);
    aHandler->setPIDPara(para_.acc);
}

void PID3Controller::clear(){
    sHandler->clear();
    vHandler->clear();
    aHandler->clear();
}

double PID3Controller::getUk(TStateInfo ref, TStateInfo cur){
    double uk=sHandler->getUk(ref.S,cur.S)+vHandler->getUk(ref.V,cur.V)+aHandler->getUk(ref.A,cur.A);
    uk=uk>systemInfo.maxOutU?systemInfo.maxOutU:uk;
    uk=uk<-systemInfo.maxOutU?-systemInfo.maxOutU:uk;
    return uk;
}

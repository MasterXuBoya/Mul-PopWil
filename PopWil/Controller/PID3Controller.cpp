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
    //此处可以考虑加权，原因如下：位移控制的很好的时候，加速度依然悬差很大，但是加速度数值较小，最大值也只有2g左右
    double uk=sHandler->getUk(ref.S,cur.S)*pid3Weight.ws
             +vHandler->getUk(ref.V,cur.V)*pid3Weight.wv
             +aHandler->getUk(ref.A,cur.A)*pid3Weight.wa;

    uk=uk>systemInfo.maxOutU?systemInfo.maxOutU:uk;
    uk=uk<-systemInfo.maxOutU?-systemInfo.maxOutU:uk;
    return uk;
}





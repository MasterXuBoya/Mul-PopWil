#include "TVController.h"

TVController::TVController(){

}

TVController::~TVController(){

}

void TVController::setTvcPara(TTVCInfo para_){
    para=para_;
}

void TVController::clear(){
    uk=0;
}

double TVController::getUk(TStateInfo ref, TStateInfo cur){
    uk=ref.S*para.fs+ref.V*para.fv+ref.A*para.fa;//前馈
    uk+=(ref.S-cur.A)*para.bs+(ref.V-cur.V)*para.bv+(ref.A-cur.A)*para.ba;//反馈

    uk=uk>systemInfo.maxOutU?systemInfo.maxOutU:uk;
    uk=uk<-systemInfo.maxOutU?-systemInfo.maxOutU:uk;

    return uk;
}



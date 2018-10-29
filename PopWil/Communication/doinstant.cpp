#include "doinstant.h"
#include <QDebug>

DoInstant::DoInstant(){
   instantDoCtrl = InstantDoCtrl::Create();
}

DoInstant::~DoInstant(){
    if(instantDoCtrl!=NULL)
        instantDoCtrl->Dispose();
}

void DoInstant::setInstantDoPara(ConfigureParameterAO para){
    instantDoPara=para;
}

void DoInstant::configure(){
    ErrorCode errorCode = Success;
    std::wstring description = instantDoPara.deviceName.toStdWString();
    DeviceInformation selected(description.c_str());
    errorCode = instantDoCtrl->setSelectedDevice(selected);
    CheckError(errorCode);
}

quint8 DoInstant::getDoState(){
    quint8 portStates=0;
    ErrorCode errorCode = instantDoCtrl->Read(0, portStates);
    CheckError(errorCode);
    return portStates;
}

bool DoInstant::setDoState(quint8 status){
    ErrorCode errorCode = instantDoCtrl->Write(0,status);
    QString ret=CheckError(errorCode);
    if(ret=="success")
        return true;
    else return false;
}

int DoInstant::getDeviceCount(QString &deviceName){
    Array<DeviceTreeNode> *supportedDevice = instantDoCtrl->getSupportedDevices();
    if(supportedDevice->getCount()>0)
        deviceName=QString::fromWCharArray(supportedDevice->getItem(0).Description);
    return supportedDevice->getCount();
}

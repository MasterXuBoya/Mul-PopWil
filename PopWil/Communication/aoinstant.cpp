#include "aoinstant.h"

AoInstant::AoInstant()
{
   instantAoCtrl = InstantAoCtrl::Create();
}
AoInstant::~AoInstant(){
    if(instantAoCtrl!=NULL)
        instantAoCtrl->Dispose();
}

void AoInstant::setInstantAoPara(ConfigureParameterAO para){
    instantAoPara=para;
}

void AoInstant::configure(){
    ErrorCode errorCode = Success;
    std::wstring description = instantAoPara.deviceName.toStdWString();
    DeviceInformation selected(description.c_str());

    errorCode = instantAoCtrl->setSelectedDevice(selected);
    CheckError(errorCode);

    for (int i = 0; i < instantAoCtrl->getChannels()->getCount(); i++) {
        errorCode = instantAoCtrl->getChannels()->getItem(i).setValueRange(instantAoPara.valueRange);
        CheckError(errorCode);
    }
}
//输出电压到0通道
bool AoInstant::outU(double value){
    ErrorCode errorCode = Success;
    scaledData[0]=scaledData[1]=value;
    errorCode = instantAoCtrl->Write(instantAoPara.channelStart,instantAoPara.channelCount, scaledData);
    QString ret=CheckError(errorCode);
    if(ret=="success")//输出电压成功
        return true;
    else return false;//输出电压失败
}

bool AoInstant::outU(double value[DISSENSORCOUNT]){
    ErrorCode errorCode = Success;
    for(int i=0;i<DISSENSORCOUNT;i++)
        scaledData[i]=value[i];
    errorCode = instantAoCtrl->Write(instantAoPara.channelStart,instantAoPara.channelCount, scaledData);
    QString ret=CheckError(errorCode);
    if(ret=="success")//输出电压成功
        return true;
    else return false;//输出电压失败
}

#include "aiinstant.h"

AiInstant::AiInstant()
{
    instantAiCtrl = InstantAiCtrl::Create();
}

AiInstant::~AiInstant(){
    if (instantAiCtrl != NULL)
    {
        instantAiCtrl->Dispose();
    }
}

void AiInstant::setInstantAiPara(ConfigureParameterAO t){
    instantAiPara=t;
}

void AiInstant::configure(){
    std::wstring description = instantAiPara.deviceName.toStdWString();
    DeviceInformation selected(description.c_str());

    //this->setWindowTitle(tr("Static AO - Run(") + configureAO.deviceName + tr(")"));
    ErrorCode errorCode = instantAiCtrl->setSelectedDevice(selected);
    CheckError(errorCode);

    for (int i = 0; i < instantAiCtrl->getChannels()->getCount(); i++) {
        errorCode = instantAiCtrl->getChannels()->getItem(i).setValueRange(instantAiPara.valueRange);
        CheckError(errorCode);
    }
}

double AiInstant::getAcc(){
    double currentAcc;
    ErrorCode errorCode = Success;
    errorCode = instantAiCtrl->Read(instantAiPara.channelStart, instantAiPara.channelCount, scaledData);
    CheckError(errorCode);
    if (errorCode != Success)
        return 100;
    currentAcc=(scaledData[0]-2.5)/0.4;//灵敏度0.4V/g  基准电压2.5V
    return currentAcc;
}

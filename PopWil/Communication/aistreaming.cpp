#include "aistreaming.h"
#include <QDebug>
#include <QMessageBox>
#include <logger.h>

AiStreaming::AiStreaming(){
    waveformAiCtrl=WaveformAiCtrl::Create();
    waveformAiCtrl->addDataReadyHandler(OnDataReadyEvent, this);
    waveformAiCtrl->addOverrunHandler(OnOverRunEvent, this);
    waveformAiCtrl->addCacheOverflowHandler(OnCacheOverflowEvent, this);
    waveformAiCtrl->addStoppedHandler(OnStoppedEvent, this);

    bufferAiCount=0;
    preAcc=0;
}

AiStreaming::~AiStreaming(){
    waveformAiCtrl->Dispose();
}

void AiStreaming::setStreamingAiPara(ConfigureParameterAI t){
    para=t;
}

void AiStreaming::clearBufferAiCount(){
    bufferAiCount=0;
}
void AiStreaming::start(){
    waveformAiCtrl->Start();
}

void AiStreaming::stop(){
    waveformAiCtrl->Stop();
}

void AiStreaming::configure(){

    std::wstring description = para.deviceName.toStdWString();
    qDebug()<<para.deviceName;
    DeviceInformation selected(description.c_str());

    ErrorCode errorCode = waveformAiCtrl->setSelectedDevice(selected);
    CheckError(errorCode);

    //Set the streaming mode.
    errorCode = waveformAiCtrl->getConversion()->setChannelCount(para.channelCount);
    CheckError(errorCode);
    //qDebug()<<"error occur!";
    errorCode = waveformAiCtrl->getConversion()->setChannelStart(para.channelStart);
    CheckError(errorCode);
    errorCode = waveformAiCtrl->getConversion()->setClockRate(para.clockRatePerChan);
    CheckError(errorCode);
    errorCode = waveformAiCtrl->getRecord()->setSectionLength(para.sectionLength);
    CheckError(errorCode);
    errorCode = waveformAiCtrl->getRecord()->setSectionCount(0);
    CheckError(errorCode);

    for (int i = 0; i < waveformAiCtrl->getChannels()->getCount(); i++)
    {
        errorCode = waveformAiCtrl->getChannels()->getItem(i).setValueRange(para.valueRange);
        CheckError(errorCode);
    }

    errorCode = waveformAiCtrl->Prepare();
    CheckError(errorCode);
}

//获取加速度,缓冲区满即进入这个函数
void AiStreaming::OnDataReadyEvent(void * sender, BfdAiEventArgs * args, void * userParam)
{
    AiStreaming * uParam = (AiStreaming *)userParam;
    int32 getDataCount =uParam->para.sectionLength * uParam->para.channelCount;
    ErrorCode ret = ((WaveformAiCtrl*)sender)->GetData(getDataCount, uParam->scaledData, 0, NULL, NULL, NULL, NULL);
    if (ret != Success && ret != WarningRecordEnd)
    {
        QString message = QString("[error] get steaming ai failed, Error Code: 0x") +QString::number(ret, 16).right(8);
        Logger *logger=Logger::getInstance();
        logger->appendLogger(message);
        return;
    }
    qDebug()<<"available data count is:"<<args->Count<<"getDataCout is:"<<getDataCount;
    double s=0;
    for(int i=0;i<getDataCount;i++)
        s+=uParam->scaledData[i];
    double avgAcc=s/getDataCount;

    uParam->bufferAi[uParam->bufferAiCount++]=avgAcc;
}

void AiStreaming::OnOverRunEvent(void * sender, BfdAiEventArgs * args, void * userParam){
   /*
   AI_StreamingBufferedAi * uParam = (AI_StreamingBufferedAi *)userParam;
   QString message = tr("The event over run has happened!");
   QMessageBox::information(uParam, "Warning Information", message);
   */
}
void AiStreaming::OnCacheOverflowEvent(void * sender, BfdAiEventArgs * args, void * userParam){
   /*
   AI_StreamingBufferedAi * uParam = (AI_StreamingBufferedAi *)userParam;
   QString message = tr("The event cache over flow has happened!");
   QMessageBox::information(uParam, "Warning Information", message);
   */
}
void AiStreaming::OnStoppedEvent(void * sender, BfdAiEventArgs * args, void * userParam){
   /*
   AI_StreamingBufferedAi * uParam = (AI_StreamingBufferedAi *)userParam;
   QString message = tr("The event stopped has happened!");
   QMessageBox::information(uParam, "Warning Information", message);
   */
}

double AiStreaming::getAcc(){
    double currentAcc;
    if(bufferAiCount==0){
        currentAcc=preAcc;
    }else{
        double s=0;
        for(int i=0;i<bufferAiCount;i++)
            s+=scaledData[i];
        currentAcc=s/bufferAiCount;
        preAcc=currentAcc;
    }
    return currentAcc;
}


#ifndef AISTREAMING_H
#define AISTREAMING_H

#include <QObject>
#include "constvar.h"
#include "bdaqctrl.h"

class AiStreaming
{
public:
    AiStreaming();
    ~AiStreaming();
    void setStreamingAiPara(ConfigureParameterAI t);
    void configure();
    void start();
    void stop();
    void clearBufferAiCount();
    double getAcc();

    static void BDAQCALL OnDataReadyEvent(void * sender, BfdAiEventArgs * args, void * userParam);
    static void BDAQCALL OnOverRunEvent(void * sender, BfdAiEventArgs * args, void * userParam);
    static void BDAQCALL OnCacheOverflowEvent(void * sender, BfdAiEventArgs * args, void * userParam);
    static void BDAQCALL OnStoppedEvent(void * sender, BfdAiEventArgs * args, void * userParam);
private:
    double scaledData[100];
    double bufferAi[100];//将每次OnDataReadyEvent中采集的数据计算平均值，放入buffer数组
    int bufferAiCount;
    double preAcc;

    WaveformAiCtrl *waveformAiCtrl;
    ConfigureParameterAI para;
};

#endif // AISTREAMING_H


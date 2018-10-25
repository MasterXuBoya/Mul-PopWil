#ifndef AIINSTANT_H
#define AIINSTANT_H

#include <QObject>
#include "constvar.h"
#include "bdaqctrl.h"

class AiInstant
{
public:
    AiInstant();
    ~AiInstant();
    void setInstantAiPara(ConfigureParameterAO t);
    void configure();
    double getAcc();//起始通道0，通道数目1
private:
    double scaledData[16];
    InstantAiCtrl *instantAiCtrl;
    ConfigureParameterAO instantAiPara;
};

#endif // AIINSTANT_H

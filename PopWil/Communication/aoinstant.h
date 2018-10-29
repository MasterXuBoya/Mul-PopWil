#ifndef AOINSTANT_H
#define AOINSTANT_H
#include <QObject>
#include "bdaqctrl.h"
#include "constvar.h"

class AoInstant
{
public:
    AoInstant();
    ~AoInstant();
    void setInstantAoPara(ConfigureParameterAO para);
    void configure();
    bool outU(double value);
private:
    double scaledData[16];
    InstantAoCtrl * instantAoCtrl;
    ConfigureParameterAO instantAoPara;
};

#endif // AOINSTANT_H

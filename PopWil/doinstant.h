#ifndef DOINSTANT_H
#define DOINSTANT_H

#include <QObject>
#include "bdaqctrl.h"
#include "constvar.h"

class DoInstant
{
public:
    DoInstant();
    ~DoInstant();
    void setInstantDoPara(ConfigureParameterAO para);
    void configure();
    quint8 getDoState();
    bool setDoState(quint8 status);
    int getDeviceCount(QString &deviceName);
private:
    InstantDoCtrl *instantDoCtrl;
    ConfigureParameterAO instantDoPara;
};

#endif // DOINSTANT_H


#ifndef IOHELPER_H
#define IOHELPER_H

#include "constvar.h"
#include "qsettings.h"
#include "qstring.h"

class IOHelper
{
public:
    IOHelper();
    IOHelper(QString fileName);
    //void writeToIni();
    //void readFromIni();
    bool writeToTestIni(TChannelCoef tmp);
    bool writeToPCIIni(ConfigureParameterAI tmpAI,ConfigureParameterAO tmpAO);
private:
    QSettings *configIniWrite;
    //QString fileName;
};

#endif // IOHELPER_H

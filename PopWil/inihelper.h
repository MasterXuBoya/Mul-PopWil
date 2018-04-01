#ifndef INIHELPER_H
#define INIHELPER_H
#include "qsettings.h"
#include "qstring.h"
#include "constvar.h"

class IniHelper
{
public:
    IniHelper();
    IniHelper(QString fileName);
    bool writeToTestIni(TChannelCoef tmp);
private:
    QSettings *configIniWrite;
};

#endif // INIHELPER_H

#ifndef INIHELPER_H
#define INIHELPER_H
#include "qsettings.h"
#include "qstring.h"
#include "constvar.h"

class IniHelper
{
public:
    IniHelper();
    ConfigureParameterPCI readFromPciIni(QString fileName);
    void readFromCtrlIni(QString fileName,TPIDInfo &sInfo,TPIDInfo &sineInfo);
    TSystemInfo readFromSystemInfoIni(QString fileName);

    bool writeToPCIIni(QString fileName,ConfigureParameterPCI tmp);
    bool writeToCtrlIni(QString fileName,TPIDInfo sInfo,TPIDInfo sineInfo);
    bool writeToSystemInfoIni(QString fileName,TSystemInfo tmp);

private:
    QSettings *configIniWrite;
    QSettings *configIniRead;
};

#endif // INIHELPER_H

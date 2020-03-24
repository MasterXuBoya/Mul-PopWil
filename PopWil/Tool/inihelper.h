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
    void readFromCtrlIni(QString fileName);
    TSystemInfo readFromSystemInfoIni(QString fileName);
    void readFromTVCIno(QString fileName);

    bool writeToPCIIni(QString fileName,ConfigureParameterPCI tmp);
    bool writeToCtrlIni(QString fileName);
    bool writeToSystemInfoIni(QString fileName,TSystemInfo tmp);
    bool writeToTvcInfo(QString fileName);

private:
    QSettings *configIniWrite;
    QSettings *configIniRead;
};

#endif // INIHELPER_H

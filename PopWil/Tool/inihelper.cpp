#include "inihelper.h"
#include "qsettings.h"
#include "qdebug.h"
#include "qstring.h"
#include "constvar.h"
#include "qmessagebox.h"
#include <QDateTime>


/*读写Ini配置文件
 * @time 2018-03-19
 * @Author：MasterXu
 * 完成最基本的Ini文件的写入和读取，还存在以下几个方面的问题：
 * 1.如何判断读取或者写入是否成功；
 * 2.如果文件已经存在，是否进行覆盖；如果文件没有，是否创建一个
 * 3.对内容进行封装
*/

IniHelper::IniHelper()
{

}


ConfigureParameterPCI IniHelper::readFromPciIni(QString fileName)
{
    ConfigureParameterPCI tmp;
    ConfigureParameterAI tmpAI;
    ConfigureParameterAO tmpAO;
    if (fileName==NULL||fileName==""){
        QMessageBox::information(NULL,"提示","文件名为空，请重新输入",QMessageBox::Ok|QMessageBox::Cancel);
        qDebug()<<"Warning：Ini文件名为空！";
        //return false;
    }
   configIniRead = new QSettings(fileName, QSettings::IniFormat);

   //将读取到的ini文件保存在QString中，先取值，然后通过toString()函数转换成QString类型
   tmpAO.deviceName = configIniRead->value("/ConfigureParameterAO/deviceName").toString();
   tmpAO.channelStart= configIniRead->value("/ConfigureParameterAO/channelStart").toString().toInt();
   tmpAO.channelCount= configIniRead->value("/ConfigureParameterAO/channelCount").toString().toInt();
   tmpAO.valueRange=ValueRange(configIniRead->value("/ConfigureParameterAO/valueRange").toString().toInt());

   tmpAI.deviceName = configIniRead->value("/ConfigureParameterAI/deviceName").toString();
   tmpAI.channelStart= configIniRead->value("/ConfigureParameterAI/channelStart").toString().toInt();
   tmpAI.channelCount= configIniRead->value("/ConfigureParameterAI/channelCount").toString().toInt();
   tmpAI.valueRange=ValueRange(configIniRead->value("/ConfigureParameterAI/valueRange").toString().toInt());
   tmpAI.clockRatePerChan= configIniRead->value("/ConfigureParameterAI/clockRatePerChan").toString().toInt();
   tmpAI.sectionLength= configIniRead->value("/ConfigureParameterAI/sectionLength").toString().toInt();

   tmp.iniSettingAO=tmpAO;
   tmp.iniSettingAI=tmpAI;
   //打印得到的结果
   //qDebug()<<tmp.iniSettingAO.deviceName<<tmp.iniSettingAO.valueRange;
   //qDebug() << tmp.iniSettingAI.channelStart<<tmp.iniSettingAI.channelCount<<tmp.iniSettingAI.sectionLength;

   //读入入完成后删除指针
   delete configIniRead;
   return tmp;
}

void IniHelper::readFromCtrlIni(QString fileName,TPIDInfo &sInfo,TPIDInfo &sineInfo)
{
    if (fileName==NULL||fileName==""){
        QMessageBox::information(NULL,"提示","文件名为空，请重新输入",QMessageBox::Ok|QMessageBox::Cancel);
        qDebug()<<"Warning：Ini文件名为空！";
    }
    configIniRead = new QSettings(fileName, QSettings::IniFormat);

    sInfo.SP = configIniRead->value("/SPID/P").toString().toDouble();
    sInfo.SI = configIniRead->value("/SPID/I").toString().toDouble();
    sInfo.SD = configIniRead->value("/SPID/D").toString().toDouble();

    sineInfo.SP = configIniRead->value("/SinePID/P").toString().toDouble();
    sineInfo.SI = configIniRead->value("/SinePID/I").toString().toDouble();
    sineInfo.SD = configIniRead->value("/SinePID/D").toString().toDouble();

    delete configIniRead;
}

TSystemInfo IniHelper::readFromSystemInfoIni(QString fileName)
{
    TSystemInfo tmp;
    if (fileName==NULL||fileName=="")
    {
        QMessageBox::information(NULL,"提示","文件名为空，请重新输入",QMessageBox::Ok|QMessageBox::Cancel);
        qDebug()<<"Warning：Ini文件名为空！";
    }
    configIniRead = new QSettings(fileName, QSettings::IniFormat);

    tmp.contrlInterval = configIniRead->value("/SystemInfo/ContrlInterval").toString().toInt();
    tmp.drawInterval = configIniRead->value("/SystemInfo/DrawInterval").toString().toInt();
    tmp.maxAbsolutePosition = configIniRead->value("/SystemInfo/MaxAbsolutePosition").toString().toDouble();
    tmp.maxOutU = configIniRead->value("/SystemInfo/MaxOutU").toString().toDouble();

    delete configIniRead;
    return tmp;
}

bool IniHelper::writeToPCIIni(QString fileName,ConfigureParameterPCI tmp)
{
    if (fileName==NULL||fileName=="")
    {
        QMessageBox::information(NULL,"提示","文件名为空，请重新输入",QMessageBox::Ok|QMessageBox::Cancel);
        qDebug()<<"Warning：Ini文件名为空！";
        return false;
    }
    configIniWrite = new QSettings(fileName, QSettings::IniFormat);//此处支持绝对路径

    ConfigureParameterAO tmpAO=tmp.iniSettingAO;
    configIniWrite->beginGroup("ConfigureParameterAO");
    configIniWrite->setValue("deviceName", tmpAO.deviceName);
    configIniWrite->setValue("channelStart",tmpAO.channelStart);
    configIniWrite->setValue("channelCount",tmpAO.channelCount);
    configIniWrite->setValue("valueRange", tmpAO.valueRange);
    configIniWrite->endGroup();

    ConfigureParameterAI tmpAI=tmp.iniSettingAI;
    configIniWrite->beginGroup("ConfigureParameterAI");
    configIniWrite->setValue("deviceName", tmpAI.deviceName);
    configIniWrite->setValue("channelStart",tmpAI.channelStart);
    configIniWrite->setValue("channelCount",tmpAI.channelCount);
    configIniWrite->setValue("valueRange", tmpAI.valueRange);
    configIniWrite->setValue("clockRatePerChan", tmpAI.clockRatePerChan);
    configIniWrite->setValue("sectionLength", tmpAI.sectionLength);
    configIniWrite->endGroup();

    delete configIniWrite;
    return true;
}

bool IniHelper::writeToCtrlIni(QString fileName,TPIDInfo sInfo,TPIDInfo sineInfo)
{
    if (fileName==NULL||fileName=="")
    {
        QMessageBox::information(NULL,"提示","文件名为空，请重新输入",QMessageBox::Ok|QMessageBox::Cancel);
        qDebug()<<"Warning：Ini文件名为空！";
        return false;
    }
    configIniWrite = new QSettings(fileName, QSettings::IniFormat);//此处支持绝对路径
    configIniWrite->beginGroup("SPID");
    configIniWrite->setValue("P", sInfo.SP);
    configIniWrite->setValue("I", sInfo.SI);
    configIniWrite->setValue("D", sInfo.SD);
    configIniWrite->endGroup();

    configIniWrite->beginGroup("SinePID");
    configIniWrite->setValue("P", sineInfo.SP);
    configIniWrite->setValue("I", sineInfo.SI);
    configIniWrite->setValue("D", sineInfo.SD);
    configIniWrite->endGroup();

    delete configIniWrite;
    return true;

}

bool IniHelper::writeToSystemInfoIni(QString fileName,TSystemInfo tmp)
{
    if (fileName==NULL||fileName=="")
    {
        QMessageBox::information(NULL,"提示","文件名为空，请重新输入",QMessageBox::Ok|QMessageBox::Cancel);
        qDebug()<<"Warning：Ini文件名为空！";
        return false;
    }

    configIniWrite = new QSettings(fileName, QSettings::IniFormat);//此处支持绝对路径
    configIniWrite->beginGroup(QString("SystemInfo"));
    configIniWrite->setValue("ContrlInterval", tmp.contrlInterval);
    configIniWrite->setValue("DrawInterval", tmp.drawInterval);
    configIniWrite->setValue("MaxAbsolutePosition", tmp.maxAbsolutePosition);
    configIniWrite->setValue("MaxOutU", tmp.maxOutU);
    configIniWrite->endGroup();

    delete configIniWrite;
    return true;
}


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

void IniHelper::readFromCtrlIni(QString fileName)
{
    if (fileName==NULL||fileName==""){
        QMessageBox::information(NULL,"提示","文件名为空，请重新输入",QMessageBox::Ok|QMessageBox::Cancel);
        qDebug()<<"Warning：Ini文件名为空！";
    }
    configIniRead = new QSettings(fileName, QSettings::IniFormat);

    sPIDInfo.SP = configIniRead->value("/SPID/P").toString().toDouble();
    sPIDInfo.SI = configIniRead->value("/SPID/I").toString().toDouble();
    sPIDInfo.SD = configIniRead->value("/SPID/D").toString().toDouble();

    sinePIDInfo.SP = configIniRead->value("/SinePID/P").toString().toDouble();
    sinePIDInfo.SI = configIniRead->value("/SinePID/I").toString().toDouble();
    sinePIDInfo.SD = configIniRead->value("/SinePID/D").toString().toDouble();

    accPIDInfo.SP = configIniRead->value("/AccPID/P").toString().toDouble();
    accPIDInfo.SI = configIniRead->value("/AccPID/I").toString().toDouble();
    accPIDInfo.SD = configIniRead->value("/AccPID/D").toString().toDouble();

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
    tmp.maxOutUDebug = configIniRead->value("/SystemInfo/maxOutUDebug").toString().toDouble();
    tmp.maxOutU = configIniRead->value("/SystemInfo/MaxOutU").toString().toDouble();
    tmp.maxAbsoluteForce = configIniRead->value("/SystemInfo/maxAbsoluteForce").toString().toDouble();
    tmp.maxAbsolutePosition = configIniRead->value("/SystemInfo/MaxAbsolutePosition").toString().toDouble();
    tmp.maxAbsoluteVel = configIniRead->value("/SystemInfo/maxAbsoluteVel").toString().toDouble();
    tmp.maxAbsoluteAcc = configIniRead->value("/SystemInfo/maxAbsoluteAcc").toString().toDouble();
    tmp.maxLoadWeight = configIniRead->value("/SystemInfo/maxLoadWeight").toString().toDouble();

    delete configIniRead;
    return tmp;
}

void IniHelper::readFromTVCIno(QString fileName){
    if (fileName==NULL||fileName==""){
        QMessageBox::information(NULL,"提示","文件名为空，请重新输入",QMessageBox::Ok|QMessageBox::Cancel);
        qDebug()<<"Warning：Ini文件名为空！";
    }
    configIniRead = new QSettings(fileName, QSettings::IniFormat);
    //全局变量tvcInfo,记录系统三参量的六个参数
    tvcInfo.fs=configIniRead->value("/TvcInfo/fs").toString().toDouble();
    tvcInfo.fv=configIniRead->value("/TvcInfo/fv").toString().toDouble();
    tvcInfo.fa=configIniRead->value("/TvcInfo/fa").toString().toDouble();
    tvcInfo.bs=configIniRead->value("/TvcInfo/bs").toString().toDouble();
    tvcInfo.bv=configIniRead->value("/TvcInfo/bv").toString().toDouble();
    tvcInfo.ba=configIniRead->value("/TvcInfo/ba").toString().toDouble();

    pid3Info.dis.SP=configIniRead->value("/PID3Info/dis/SP").toString().toDouble();
    pid3Info.dis.SI=configIniRead->value("/PID3Info/dis/SI").toString().toDouble();
    pid3Info.dis.SD=configIniRead->value("/PID3Info/dis/SD").toString().toDouble();

    pid3Info.vel.SP=configIniRead->value("/PID3Info/vel/SP").toString().toDouble();
    pid3Info.vel.SI=configIniRead->value("/PID3Info/vel/SI").toString().toDouble();
    pid3Info.vel.SD=configIniRead->value("/PID3Info/vel/SD").toString().toDouble();

    pid3Info.acc.SP=configIniRead->value("/PID3Info/acc/SP").toString().toDouble();
    pid3Info.acc.SI=configIniRead->value("/PID3Info/acc/SI").toString().toDouble();
    pid3Info.acc.SD=configIniRead->value("/PID3Info/acc/SD").toString().toDouble();

//    qDebug()<<pid3Info.dis.SP;
//    qDebug()<<pid3Info.dis.SI;
//    qDebug()<<pid3Info.dis.SD;
//    qDebug()<<pid3Info.vel.SP;
//    qDebug()<<pid3Info.vel.SI;
//    qDebug()<<pid3Info.vel.SD;
//    qDebug()<<pid3Info.acc.SP;
//    qDebug()<<pid3Info.acc.SI;
//    qDebug()<<pid3Info.acc.SD;

    delete configIniRead;
}
//--------------------------------------------------------------------------------------------------------
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

bool IniHelper::writeToCtrlIni(QString fileName)
{
    if (fileName==NULL||fileName=="")
    {
        QMessageBox::information(NULL,"提示","文件名为空，请重新输入",QMessageBox::Ok|QMessageBox::Cancel);
        qDebug()<<"Warning：Ini文件名为空！";
        return false;
    }
    configIniWrite = new QSettings(fileName, QSettings::IniFormat);//此处支持绝对路径
    configIniWrite->beginGroup("SPID");
    configIniWrite->setValue("P", sPIDInfo.SP);
    configIniWrite->setValue("I", sPIDInfo.SI);
    configIniWrite->setValue("D", sPIDInfo.SD);
    configIniWrite->endGroup();

    configIniWrite->beginGroup("SinePID");
    configIniWrite->setValue("P", sinePIDInfo.SP);
    configIniWrite->setValue("I", sinePIDInfo.SI);
    configIniWrite->setValue("D", sinePIDInfo.SD);
    configIniWrite->endGroup();

    configIniWrite->beginGroup("AccPID");
    configIniWrite->setValue("P", accPIDInfo.SP);
    configIniWrite->setValue("I", accPIDInfo.SI);
    configIniWrite->setValue("D", accPIDInfo.SD);
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
    configIniWrite->setValue("maxOutUDebug", tmp.maxOutUDebug);
    configIniWrite->setValue("MaxOutU", tmp.maxOutU);
    configIniWrite->setValue("maxAbsoluteForce", tmp.maxAbsoluteForce);
    configIniWrite->setValue("MaxAbsolutePosition", tmp.maxAbsolutePosition);
    configIniWrite->setValue("maxAbsoluteVel", tmp.maxAbsoluteVel);
    configIniWrite->setValue("maxAbsoluteAcc", tmp.maxAbsoluteAcc);
    configIniWrite->setValue("maxLoadWeight", tmp.maxLoadWeight);
    configIniWrite->endGroup();

    delete configIniWrite;
    return true;
}

bool IniHelper::writeToTvcInfo(QString fileName){
    if (fileName==NULL||fileName=="")
    {
        QMessageBox::information(NULL,"提示","文件名为空，请重新输入",QMessageBox::Ok|QMessageBox::Cancel);
        qDebug()<<"Warning：Ini文件名为空！";
        return false;
    }
    configIniWrite = new QSettings(fileName, QSettings::IniFormat);//此处支持绝对路径

    configIniWrite->beginGroup(QString("TvcInfo"));
    configIniWrite->setValue("fs", tvcInfo.fs);
    configIniWrite->setValue("fv", tvcInfo.fv);
    configIniWrite->setValue("fa", tvcInfo.fa);
    configIniWrite->setValue("bs", tvcInfo.bs);
    configIniWrite->setValue("bv", tvcInfo.bv);
    configIniWrite->setValue("ba", tvcInfo.ba);
    configIniWrite->endGroup();

    configIniWrite->beginGroup(QString("PID3Info"));
    configIniWrite->setValue("dis/SP",pid3Info.dis.SP);
    configIniWrite->setValue("dis/SI",pid3Info.dis.SI);
    configIniWrite->setValue("dis/SD",pid3Info.dis.SD);

    configIniWrite->setValue("vel/SP",pid3Info.vel.SP);
    configIniWrite->setValue("vel/SI",pid3Info.vel.SI);
    configIniWrite->setValue("vel/SD",pid3Info.vel.SD);

    configIniWrite->setValue("acc/SP",pid3Info.acc.SP);
    configIniWrite->setValue("acc/SI",pid3Info.acc.SI);
    configIniWrite->setValue("acc/SD",pid3Info.acc.SD);

    configIniWrite->endGroup();

    delete configIniWrite;
    return true;
}


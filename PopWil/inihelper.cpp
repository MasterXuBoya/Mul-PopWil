#include "inihelper.h"
#include "qsettings.h"
#include "qdebug.h"
#include "qstring.h"
#include "constvar.h"
#include "qmessagebox.h"


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

IniHelper::IniHelper(QString fileName)
{
    if (fileName==NULL||fileName=="")
    {
        QMessageBox::information(NULL,"提示","文件名为空，请重新输入",QMessageBox::Ok|QMessageBox::Cancel);
        qDebug()<<"Warning：Ini文件名为空！";
    }
    configIniWrite = new QSettings(fileName, QSettings::IniFormat);//此处支持绝对路径
}

bool IniHelper::writeToTestIni(TChannelCoef tmp)
{
    //QSettings *configIniWrite = new QSettings("TchannelCoef.ini", QSettings::IniFormat);//此处支持绝对路径

    configIniWrite->beginGroup("TchannelCoef");
    configIniWrite->setValue("a", tmp.a);
    configIniWrite->setValue("b", tmp.b);
    configIniWrite->setValue("c", tmp.c);
    configIniWrite->setValue("d", tmp.d);
    configIniWrite->endGroup();

    //delete configIniWrite;
    return true;
}


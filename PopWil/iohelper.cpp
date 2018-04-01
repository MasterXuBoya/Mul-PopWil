#include "iohelper.h"
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
IOHelper::IOHelper()
{

}

IOHelper::IOHelper(QString fileName)

{
    if (fileName==NULL||fileName=="")
    {
        QMessageBox::information(NULL,"提示","文件名为空，请重新输入",QMessageBox::Ok|QMessageBox::Cancel);
        qDebug()<<"Warning：Ini文件名为空！";
    }
    configIniWrite = new QSettings(fileName, QSettings::IniFormat);//此处支持绝对路径
}

/*
void IOHelper::writeToIni()
{
   //Qt中使用QSettings类读写ini文件
   //QSettings构造函数的第一个参数是ini文件的路径,第二个参数表示针对ini文件,第三个参数可以缺省
   QSettings *configIniWrite = new QSettings("hahaya.ini", QSettings::IniFormat);//此处支持绝对路径


   //向ini文件中写入内容,setValue函数的两个参数是键值对
   //向ini文件的第一个节写入内容,ip节下的第一个参数
   configIniWrite->beginGroup("ip");
   configIniWrite->setValue("first", "192.168.0.1");
   //向ini文件的第一个节写入内容,ip节下的第二个参数
   configIniWrite->setValue("second", "127.0.0.1");
   configIniWrite->endGroup();


   //向ini文件的第二个节写入内容,port节下的第一个参数
   configIniWrite->setValue("port/open", "2222");
   //写入完成后删除指针
   delete configIniWrite;
}

void IOHelper::readFromIni()
{
   QSettings *configIniRead = new QSettings("D:/hahaya.ini", QSettings::IniFormat);
   //将读取到的ini文件保存在QString中，先取值，然后通过toString()函数转换成QString类型
   QString ipResult = configIniRead->value("/ip/second").toString();
   QString portResult = configIniRead->value("/port/open").toString();
   //打印得到的结果
   qDebug() << ipResult;
   qDebug() << portResult;
   //读入入完成后删除指针
   delete configIniRead;
}
*/
bool IOHelper::writeToTestIni(TChannelCoef tmp)
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


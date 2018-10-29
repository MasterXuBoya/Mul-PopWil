#include "logger.h"
#include <QStringList>
#include <QDateTime>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>

Logger::Logger()
{
    loggerList.clear();
/*定义四种级别
 * debug
 * info
 * warning
 * error
*/
}
Logger * Logger::instance=NULL;//静态成员变量必须在类外边进行初始化

Logger *Logger::getInstance(){
    if(instance==NULL)
        instance=new Logger;
    return instance;
}

void Logger::appendLogger(QString str){
    QDateTime currentTime = QDateTime::currentDateTime();
    QString current = currentTime.toString("yyyy-MM-dd hh:mm:ss ");
    QString content=current+str;
    loggerList.append(content);
}

void Logger::writeAll(){
    QDateTime currentTime = QDateTime::currentDateTime();
    QString current = currentTime.toString("yyyyMMdd_hhmm");
    QString path="E:/PopWilCacher/logger/"+current+".txt";
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }

    QTextStream out(&file);
    out.setCodec(QTextCodec::codecForName("UTF-8"));
    for (int i = 0; i < loggerList.size(); ++i){
        out<<loggerList.at(i)<<endl;
    }
}

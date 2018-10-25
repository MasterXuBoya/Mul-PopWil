#ifndef LOGGER_H
#define LOGGER_H
#include <QString>
#include <QStringList>

class Logger//单例模式Singleton
{
public:
    static Logger *getInstance();
    void writeAll();
    void appendLogger(QString str);
private:
    QStringList loggerList;
    Logger();//构造函数私有化
    static Logger *instance;//
};

#endif // LOGGER_H

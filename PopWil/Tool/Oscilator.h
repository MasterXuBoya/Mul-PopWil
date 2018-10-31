#ifndef OSCILATOR_H
#define OSCILATOR_H

#include "QDebug"
#include "constvar.h"
#include "math.h"
#include <stdlib.h>
#include <time.h>
#include <QFile>
#include <QTextStream>
#include <QString>

#define random(x) (rand()%x)

class Oscilator
{
public:
    Oscilator();
    virtual ~Oscilator();
    void caculateSine(TSineWaveInfo para);//正弦波
    void caculateSineSweep(QString path);//正弦扫频，打开生成的文件
    void caculateRandom(double mag);//随机波
    void caculateTriangle(TSineWaveInfo para);//三角波
private:

};

#endif // OSCILATOR_H

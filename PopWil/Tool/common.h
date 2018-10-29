#ifndef COMMON_H
#define COMMON_H
#include <qstring.h>


class COMMON
{
public:
    COMMON();
    //判断QString是否是数字，包括整数和小数
    bool isDigitStr(QString src);
    //判断QString是否是整数
    bool isIntStr(QString src);
};

#endif // COMMON_H

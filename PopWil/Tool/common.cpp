#include "common.h"
#include<cstring>
#include "qstring.h"

COMMON::COMMON()
{

}

bool COMMON::isDigitStr(QString src)
{
    int i;
    QByteArray ba = src.toLatin1();//QString 转换为 char*
    const char *s = ba.data();
    int len=strlen(s);
    for(i=0;i<len;i++)
    {
        char ch=*(s+i);
        if(!((ch>='0' && ch<='9')||ch=='.'||ch=='-'))
            return false;
    }
    return true;
}

bool COMMON::isIntStr (QString src)
{
    int i;
    QByteArray ba = src.toLatin1();//QString 转换为 char*
    const char *s = ba.data();
    int len=strlen(s);
    for(i=0;i<len;i++)
    {
        char ch=*(s+i);
        if(!((ch>='0' && ch<='9')||ch=='-'))
            return false;
    }
    return true;
}

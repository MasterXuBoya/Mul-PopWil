#ifndef TVCONTROLLER_H
#define TVCONTROLLER_H

#include "constvar.h"
class TVController
{
public:
    TVController();
    virtual ~TVController();
    void setTvcPara(TTVCInfo para_);
    double getUk(TStateInfo ref,TStateInfo cur);//参考状态和当前状态
    void clear();
private:
    TTVCInfo para;
    double uk;
};

#endif // TVCONTROLLER_H




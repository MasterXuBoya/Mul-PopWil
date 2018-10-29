#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#include "constvar.h"
class PIDController
{
public:
    PIDController();
    virtual ~PIDController();
    void setPIDPara(TPIDInfo value);
    double getUk(double refPosition,double currentPosition);
    void clear();
private:
    double uk,uk_1,ek,ek_1,ek_2;
    double para_P,para_I,para_D;
};

#endif // PIDCONTROLLER_H


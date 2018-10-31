#ifndef PID3CONTROLLER_H
#define PID3CONTROLLER_H

#include "constvar.h"
#include "PIDController.h"

class PID3Controller
{
public:
    PID3Controller();
    virtual ~PID3Controller();
    void setPara(TPID3Info para_);
    double getUk(TStateInfo ref,TStateInfo cur);
    void clear();
private:
    PIDController *sHandler,*vHandler,*aHandler;
    TStateInfo para;
};

#endif // PID3CONTROLLER_H


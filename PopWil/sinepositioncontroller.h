#ifndef SINEPOSITIONCONTROLLER_H
#define SINEPOSITIONCONTROLLER_H

#include "constvar.h"

class SinePositionController
{
public:
    SinePositionController();
    double getUk(double currentPosition,double refPosition);
    void clear();
private:
    double uk,uk_1,ek,ek_1,ek_2;
};

#endif // SINEPOSITIONCONTROLLER_H

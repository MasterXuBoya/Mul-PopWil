#ifndef BUTTORFILTER_H
#define BUTTORFILTER_H

#define NZEROS 4
#define NPOLES 4
#define GAIN   1.602898462e+04

class ButtorFilter
{
public:
    ButtorFilter();
    virtual ~ButtorFilter();
    double filter(double value);
private:
    double xv[NZEROS+1], yv[NPOLES+1];
};

#endif // BUTTORFILTER_H

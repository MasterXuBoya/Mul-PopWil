#ifndef STATICPOSITIONCONTROLLER_H
#define STATICPOSITIONCONTROLLER_H


class StaticPositionController
{
public:
    StaticPositionController();
    void configure(double x_static_des_,double static_PosVref_);
    double getUk(double currentPosition,double &refPosition);
    void clear();
private:
    double uk,uk_1,ek,ek_1,ek_2;
    double x_static_des,static_PosVref;
    double speed;
};

#endif // STATICPOSITIONCONTROLLER_H

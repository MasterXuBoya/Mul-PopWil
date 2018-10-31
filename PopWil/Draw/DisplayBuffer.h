#ifndef DISPLAYBUFFER_H
#define DISPLAYBUFFER_H


class DisplayBuffer
{
public:
    DisplayBuffer();
    virtual ~DisplayBuffer();
    double delay(double value);
    void setDelayCnt(int value);
private:
    static const int bufferSize=50;//最大的空间
    double *buffer;
    int bufferIndex,delayCnt;//绘图延迟的点数,不是秒数
};

#endif // DISPLAYBUFFER_H

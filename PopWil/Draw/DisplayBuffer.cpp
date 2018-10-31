#include "DisplayBuffer.h"

DisplayBuffer::DisplayBuffer()
{
    buffer=new double[bufferSize];
    for(int i=0;i<bufferSize;i++)
        buffer[i]=0;
    bufferIndex=0;delayCnt=2;//默认两次
}

DisplayBuffer::~DisplayBuffer(){
    delete[] buffer;
}

void DisplayBuffer::setDelayCnt(int value){
    delayCnt=value;//设置延迟的点数
}

double DisplayBuffer::delay(double value){
    bufferIndex=(bufferIndex+1)%delayCnt;
    double result=buffer[bufferIndex];
    buffer[bufferIndex]=value;
    return result;
}

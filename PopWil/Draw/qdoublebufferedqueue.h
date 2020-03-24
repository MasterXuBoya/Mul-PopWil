///////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2016 Advanced Software Engineering Limited
//
// You may use and modify the code in this file in your application, provided the code and
// its modifications are used only in conjunction with ChartDirector. Usage of this software
// is subjected to the terms and condition of the ChartDirector license.
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef QDOUBLEBUFFEREDQUEUE_HDR
#define QDOUBLEBUFFEREDQUEUE_HDR

#include <QMutex>
#include "windows.h"

template <class T>
class QDoubleBufferedQueue
{
public:
    //
    // Constructor - construct a queue with the given buffer size
    //
    QDoubleBufferedQueue(int bufferSize = 100) :
        bufferLen(0), bufferSize(bufferSize)
	{ 
		buffer0 = buffer = new T[bufferSize]; 
		buffer1 = new T[bufferSize];
	}

    //
    // Destructor
    //
    ~QDoubleBufferedQueue()
	{
		 delete[] buffer0;
		 delete[] buffer1;
	}

    //
    // Add an item to the queue. Returns true if successful, false if the buffer is full.
    //
	bool put(const T& datum)
	{
        mutex.lock();//mutex是互斥量，把buffer已经指针锁起来，不允许其他现成进行操作
		bool canWrite = bufferLen < bufferSize;
		if (canWrite) buffer[bufferLen++] = datum;
        mutex.unlock();
		return canWrite;
	}
//    bool putData(const TDataType& data){
//        bool isFull=true;
//        WaitForSingleObject(g_hMutex,INFINITE);
//        if(bufferCnt<BUFFERSIZE){
//            isFull=false;
//            buffer[bufferCnt++]=data;
//        }
//        ReleaseMutex(g_hMutex);
//        return isFull;
//    }
//    void getData(TDataType *&p,int dataLen){
//        WaitForSingleObject(g_hMutex,INFINITE);
//        p=buffer;dataLen=bufferCnt;
//        if(buffer==buffer0)
//            buffer=buffer1;
//        else buffer=buffer0;
//        ReleaseMutex(g_hMutex);
//    }
    //
    // Get all the items in the queue. The T** argument should be the address of a variable to
    // receive the pointer to the item array. The return value is the size of the array.
    //
	int get(T** data)
	{
        mutex.lock();
        *data = buffer;
		int ret = bufferLen;
        buffer = (buffer == buffer0) ? buffer1 : buffer0;//交换
		bufferLen = 0;
        mutex.unlock();
		return ret;
	}

private:

    // Disable copying and assignment
    QDoubleBufferedQueue & operator=(const QDoubleBufferedQueue&);
    QDoubleBufferedQueue(const QDoubleBufferedQueue&);

	T* buffer0;
	T* buffer1;
	T* buffer;
    int bufferLen;//当前指针
    int bufferSize;//缓冲区总的长度
    QMutex mutex;
};


#endif

#ifndef SSITOOL_H
#define SSITOOL_H
#include <stdio.h>
#include <windef.h>


class ssitool
{
public:
    ssitool();
};

//please use stdcall when use new pcidll lib
typedef int(_stdcall *lpReadFun)(const HANDLE, unsigned char ); //宏定义函数指针类型
typedef int(_stdcall *lpWriteFun)(const HANDLE, unsigned char,unsigned char );
typedef HANDLE (_stdcall *lpConnectToDev)(DWORD instance);
typedef int (_stdcall *lpDisConnectToDev)(const HANDLE);

extern HANDLE   hPDC1;
extern lpReadFun readFun; //函数指针
extern lpWriteFun writeFun; //函数指针
extern lpConnectToDev conToDevFun;
extern lpDisConnectToDev disConToDevFun;

bool ImportDLL_ConnectToDev();
bool DisConnectToDev_FreeDll();

//读第几路SSI数据，返回值为最终的数值，不论是格雷码二进制还是自然二进制，都当做自然二进制数算出一个总数，
//如果SSI源是格雷码，则再调用grayToDecimal来获得格雷码对应的数值
unsigned int readSSIData(unsigned int SSI,HANDLE hPDC);
unsigned int grayToDecimal(unsigned int graydata);
int writeData(unsigned char address, unsigned char data);


#endif // SSITOOL_H

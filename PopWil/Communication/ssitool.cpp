#include "ssitool.h"
#include <qlibrary.h>
#include "qdebug.h"
#include "qmessagebox.h"

ssitool::ssitool()
{

}
HANDLE      hPDC1; //第一块单板

lpReadFun readFun; //函数指针
lpWriteFun writeFun; //函数指针
lpConnectToDev conToDevFun;
lpDisConnectToDev disConToDevFun;

bool ImportDLL_ConnectToDev()
{
    BOOL	bConnectSuccess;
    bConnectSuccess = TRUE;
    QLibrary hDll("pcidll.dll");
    if(hDll.load())
    {
        qDebug()<<"-----------pcidll.dll load success-----------------";
        readFun = (lpReadFun)hDll.resolve("ReadDataFromDev");
        if(readFun)
            qDebug()<<"-----------function readFun load success---------------";

        writeFun = (lpWriteFun)hDll.resolve("WriteDataToDev");
        if(writeFun)
            qDebug()<<"-----------function writeFun load success---------------";
        conToDevFun = (lpConnectToDev)hDll.resolve("ConnectToDev");
        if(conToDevFun)
            qDebug()<<"-----------function conToDevFun load success---------------";
        disConToDevFun = (lpDisConnectToDev)hDll.resolve("DisConnectToDev");
        if(disConToDevFun)
            qDebug()<<"-----------function disConToDevFun load success---------------";
        //QMessageBox::information(NULL,"提示","function disConToDevFun load success",QMessageBox::Ok|QMessageBox::Cancel);

    }else{
        bConnectSuccess = FALSE;
        return FALSE;
    }
    hPDC1 = NULL;
    hPDC1 = conToDevFun(0);
    if (hPDC1 == NULL)
    {
        qDebug()<<"No SSI-PCI Card found";
        QMessageBox::information(NULL,"提示","No SSI-PCI Card found",QMessageBox::Ok|QMessageBox::Cancel);
        bConnectSuccess = FALSE;
    }else{
        QMessageBox::information(NULL,"提示","SSI-PCI Card found",QMessageBox::Ok|QMessageBox::Cancel);
        qDebug()<<"Card1 opened";
        bConnectSuccess=true;
    }
    return bConnectSuccess;
}
////////////////////////////////////////////////////////////////////////////////////
//	Function Name	:	DisconnectToPDC1000
//	Description		:
////////////////////////////////////////////////////////////////////////////////////
bool DisConnectToDev_FreeDll()
{												//DisconnectToPDC1000
    if (hPDC1)
    {
        disConToDevFun(hPDC1);
    }
    return TRUE;
}												//DisconnectToPDC1000

//读第几路SSI数据，注意输入值为0，1，2，3对应说明电气连接图上的0，1，2，3路。返回值为最终的数值，不论是格雷码二进制还是自然二进制，都先当做自然二进制数算出一个总数，
unsigned int readSSIData(unsigned int SSI, HANDLE hPDC)
{
    unsigned int SSIdata = 0;

    unsigned int buf0_data,buf1_data,buf2_data,buf3_data;

    unsigned char Buf0_addr = 0x80 + SSI*4;
    unsigned char Buf1_addr = 0x81 + SSI*4;
    unsigned char Buf2_addr = 0x82 + SSI*4;
    unsigned char Buf3_addr = 0x83 + SSI*4;

    buf0_data = readFun(hPDC,Buf0_addr);//最低0-7位数据，buf0_addr为地址，数据返回给buf0_data,下同
    buf1_data = readFun(hPDC,Buf1_addr);//第8-15位数据
    buf2_data = readFun(hPDC,Buf2_addr);//第16-23位数据
    buf3_data = readFun(hPDC,Buf3_addr);//第24-31位数据

    //将4个寄存器中数据组合为最终数值
    SSIdata = buf0_data + (buf1_data<< 8) +  (buf2_data<<16) + (buf3_data<<24);

    return SSIdata;
}
//若SSI源为格雷码，仍然是一种二进制码，因此PCI板卡读入无区别，读进来时候，可先当做普通二进制码算出总数，再将总数转换成格雷码真正应该对应的数值
//此函数只能做最多32位的格雷码转换
unsigned int grayToDecimal(unsigned int graydata)
{
    unsigned int decimal = graydata;
    graydata=graydata>>1;
    while (graydata!=0)
    {
        decimal ^= graydata;
        graydata=graydata>>1;
    }

    return decimal;
}

//示例程序，如何用write函数写数据，注意，一个寄存器只有8位，所以写数据的时候，高低位也是分开写
int writeData(unsigned char address, unsigned char data)
{
    //返回值表示是否写入成功
    return 	writeFun(hPDC1,address,data);
}


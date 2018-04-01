#include "windef.h"
#ifdef __cplusplus
extern "C" {
#endif

int __stdcall Enc7480_Init(void);
void __stdcall Enc7480_Close();

long __stdcall Enc7480_Get_Encoder(WORD axis); 
void __stdcall Enc7480_Set_Encoder(WORD axis,long value);
long __stdcall Enc7480_Get_LatchValue(WORD axis);

void __stdcall Enc7480_Count_Config(WORD axis,WORD mode);

void __stdcall Enc7480_Write_OutBit(WORD bitno,WORD Off_On);
void __stdcall Enc7480_Write_OutPort(WORD cardno,DWORD value);
long __stdcall Enc7480_Read_OutPort(WORD cardno);
long __stdcall Enc7480_Read_InPort(WORD cardno);

void __stdcall Enc7480_Set_Triger_Logic(WORD logic);

void __stdcall Enc7480_Set_EZ_Logic(WORD axis,WORD enable,WORD logic);

long __stdcall Enc7480_Read_Latch_Status(WORD cardno);
void __stdcall Enc7480_Reset_Latch_Flag(WORD cardno);
void __stdcall Enc7480_Reset_Cls_Flag(WORD cardno);
void __stdcall Enc7480_Led_Logic(WORD cardno,WORD Logic);



#ifdef __cplusplus
}
#endif



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Jul 30 19:05:25 2015
 */
/* Compiler settings for win32\mwcomutil.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IMWUtil,0xC47EA90E,0x56D1,0x11d5,0xB1,0x59,0x00,0xD0,0xB7,0xBA,0x75,0x44);


MIDL_DEFINE_GUID(IID, LIBID_MWComUtil,0x6A52E8DA,0x9F92,0x4D1E,0xB0,0xF4,0xEC,0x4F,0xA3,0xCB,0x18,0xD0);


MIDL_DEFINE_GUID(CLSID, CLSID_MWField,0x02DE498F,0x5A84,0x4E33,0x91,0x44,0xF8,0xA1,0x08,0xAC,0x97,0xB7);


MIDL_DEFINE_GUID(CLSID, CLSID_MWStruct,0xD5D20C69,0x131A,0x4074,0xB5,0xF5,0xCA,0xA1,0xF0,0x12,0x01,0x06);


MIDL_DEFINE_GUID(CLSID, CLSID_MWComplex,0xE2E27469,0xEBBA,0x4800,0x93,0xDC,0x59,0x81,0xEC,0x8E,0x8C,0x7A);


MIDL_DEFINE_GUID(CLSID, CLSID_MWSparse,0x0DBD7D4A,0x294D,0x4F3D,0x9B,0xA0,0xA5,0xD5,0xE4,0xE1,0xCC,0x93);


MIDL_DEFINE_GUID(CLSID, CLSID_MWArg,0x6A80E334,0xDD50,0x4C03,0x96,0x6F,0x03,0x6A,0xC6,0x43,0xD2,0xEC);


MIDL_DEFINE_GUID(CLSID, CLSID_MWArrayFormatFlags,0x647C1716,0xFD7E,0x46E0,0xBE,0x73,0x7F,0x83,0x39,0x64,0x3C,0xA3);


MIDL_DEFINE_GUID(CLSID, CLSID_MWDataConversionFlags,0x3E5D957F,0x0941,0x4E2B,0xB5,0x97,0xC7,0x66,0x99,0x02,0x4D,0x0F);


MIDL_DEFINE_GUID(CLSID, CLSID_MWUtil,0xD959FD63,0x4D75,0x41DE,0x8B,0x38,0x12,0x6B,0xB4,0x38,0x0A,0x2D);


MIDL_DEFINE_GUID(CLSID, CLSID_MWFlags,0xB58F4316,0x8BB3,0x4500,0x92,0xB2,0xC8,0xC4,0x65,0x36,0x46,0x4F);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif




/* Copyright 2013 The MathWorks, Inc. */

#ifndef xilservice_CInterface_h
#define xilservice_CInterface_h

#include "coder/connectivity/xilservice/xilservice.h"

XILSERVICE_API_EXTERN_C uint8_T xilServiceTgtCreate();

XILSERVICE_API_EXTERN_C void xilServiceTgtDestroy();

XILSERVICE_API_EXTERN_C void xilServiceTgtDestroyBuf();

XILSERVICE_API_EXTERN_C uint8_T* xilServiceTgtGetData(uint16_T* size);

#endif

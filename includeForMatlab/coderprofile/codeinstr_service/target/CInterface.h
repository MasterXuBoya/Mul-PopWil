/* Copyright 2013 The MathWorks, Inc. */

#ifndef codeInstrService_CInterface_h
#define codeInstrService_CInterface_h

#include "coderprofile/codeinstr_service/codeinstrservice.h"

/* Create code instrumentation service */
CODEINSTRSERVICE_API_EXTERN_C uint8_T codeInstrServiceTgtCreate(void* pCSVoid);

/* Destroy code instrumentation service */
CODEINSTRSERVICE_API_EXTERN_C void codeInstrServiceTgtDestroy(void);


#endif


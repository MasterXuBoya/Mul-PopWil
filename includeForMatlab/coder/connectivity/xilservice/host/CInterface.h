/* Copyright 2013 The MathWorks, Inc. */

#ifndef __CInterface_h__
#define __CInterface_h__

#include "coder/connectivity/xilservice/xilservice.h"

typedef struct {
    void* data;
    mwSize size;
} XIL_IOBuffer_T;

XILSERVICE_API_EXTERN_C boolean_T xilServiceCreate(
        void** const ppXILService,                                      
        void* const pCommService,                                       
        void* const pXILUtils,                                          
        XIL_IOBuffer_T* const pIOBuffer,                                
        const uint8_T memUnitSize,                                      
        const uint8_T ioDataTypeSize,
        const boolean_T isUsingCommService);
       
XILSERVICE_API_EXTERN_C const uint8_T xilServiceGetIsResponseComplete(
        void* const pXILService);

XILSERVICE_API_EXTERN_C void xilServiceSetIsResponseComplete(
        void* const pXILService,                                                  
        const uint8_T val);

XILSERVICE_API_EXTERN_C const mwSize xilServiceGetPayloadSizeForOneStep(
        void* const pXILServiceVoid);

XILSERVICE_API_EXTERN_C boolean_T xilServiceGrowIOBuffer(
        void* const pXILService,                                        
        XIL_IOBuffer_T* const IOBuffer,                                       
        const mwSize requiredSize,                                            
        const uint8_T isVerbose);

XILSERVICE_API_EXTERN_C boolean_T xilServiceSend(
        void* const pXILService,                                      
        void* const src,                                              
        const mwSize size);

XILSERVICE_API_EXTERN_C boolean_T xilServiceWaitForDataFromTarget(
        void* const pXILServiceVoid);
       
XILSERVICE_API_EXTERN_C void xilServiceDestroy(
        void* const pXILServiceVoid);

#endif

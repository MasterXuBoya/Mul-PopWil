/* Copyright 2013-2015 The MathWorks, Inc. */

#ifndef __comms_interface_h__
#define __comms_interface_h__

#ifdef BUILDING_LIBMWXILSERVICE
    #include "coder/connectivity/xilservice/xilservice.h"
#else
   
    #include "xilservice.h"
#endif
#include <stddef.h>

#if defined (USING_CS_API) || defined(BUILDING_LIBMWXILSERVICE)
       
    typedef uint8_T IOUnit_T;   
#else
    #ifdef HOST_WORD_ADDRESSABLE_TESTING
       
        typedef unsigned char IOUnit_T;
    #else
       
        typedef MemUnit_T IOUnit_T;
    #endif
#endif

static const uint8_T COMMS_ERROR = 0;
static const uint8_T COMMS_SUCCESS = 1;

XILSERVICE_API_EXTERN_C uint8_T commsCreate(
        const int argc,
        void * argv[]);

XILSERVICE_API_EXTERN_C uint8_T commsDestroy(void);

XILSERVICE_API_EXTERN_C void* getCommsInstance(void);

XILSERVICE_API_EXTERN_C uint8_T commsRun(void);

XILSERVICE_API_EXTERN_C uint8_T commsAllocXILBuffer(       
        void** ppBuf,
        const uint16_T size);

XILSERVICE_API_EXTERN_C uint8_T commsAllocCodeInstrBuffer(       
        void** ppBuf,
        const uint16_T size);

XILSERVICE_API_EXTERN_C uint8_T commsAllocCoderAssumptionsBuffer(
        void** ppBuf,
        const uint16_T size);

XILSERVICE_API_EXTERN_C IOUnit_T* commsGetXILBufferDataPtr(void* const pBufVoid);

XILSERVICE_API_EXTERN_C IOUnit_T* commsGetCodeInstrBufferDataPtr(void* const pBufVoid);

XILSERVICE_API_EXTERN_C IOUnit_T * commsGetCoderAssumptionsBufferDataPtr(void* const pBufVoid);

XILSERVICE_API_EXTERN_C uint8_T commsEnqueueBuffer(
        void* const pBufVoid,
        const uint8_T appId,
        const uint16_T payloadSize);

XILSERVICE_API_EXTERN_C void commsWaitUntilConnected(void);

XILSERVICE_API_EXTERN_C uint16_T commsGetMaxPayloadSize(void);

#endif

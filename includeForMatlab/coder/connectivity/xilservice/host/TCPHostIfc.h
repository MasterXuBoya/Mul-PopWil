/* Copyright 2013 The MathWorks, Inc. */

#ifndef __TCPHostIfc_h__
#define __TCPHostIfc_h__

#include "coder/connectivity/xilservice/host/CInterface.h"

XILSERVICE_API_EXTERN_C boolean_T createTCPHost(
        void** const ppCS,
        void* const pXILUtilsVoid,
        const char *hostName,
        uint16_T port);

XILSERVICE_API_EXTERN_C void destroyTCPHost(void* const pCSVoid);

#endif

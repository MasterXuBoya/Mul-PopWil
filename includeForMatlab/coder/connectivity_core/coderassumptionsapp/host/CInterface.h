/* Copyright 2015 The MathWorks, Inc. */

#ifndef CODERASSUMPTIONSAPP_CINTERFACE_H
#define CODERASSUMPTIONSAPP_CINTERFACE_H

#include "coder/connectivity_core/coderassumptionsapp/coderassumptionsapp.h"

CODERASSUMPTIONSAPP_API_EXTERN_C boolean_T coderAssumptionsAppCreate(
        void** const ppCoderAssumptionsApp,                                      
        void* const pXILUtilsVoid,
        const boolean_T isVerbose,
        const boolean_T prodEqTarget,
        const mxArray * codeGenComponent,
        const boolean_T isSimulinkConfig);
       
CODERASSUMPTIONSAPP_API_EXTERN_C void coderAssumptionsAppDestroy(
        void* const pCoderAssumptionsApp);

#endif

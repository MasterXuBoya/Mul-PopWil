/* Copyright 2013 The MathWorks, Inc. */

#ifndef coderprofile_CInterface_h
#define coderprofile_CInterface_h

#include "coderprofile/codeinstr_service/codeinstrservice.h"

typedef struct CodeInstrServiceData {
    const char* infoPath;
    const char* blockPath;
    const char* rootModel;
    size_t memUnitSize;
    bool isProfilingEnabled;
    size_t inTheLoopType;
    const char* silPilInterfaceFcn;
} CodeInstrServiceData_T;


/* C interface */
CODEINSTRSERVICE_API_EXTERN_C int codeInstrServiceCreate(
        void** const ppCodeInstrService,   
        const CodeInstrServiceData_T* const pData,
        void* const pCSVoid,                         
        const void* const pMemUnitXformer,                                 
        const int idTypeSize,                                              
        void* const pXILUtils,                                             
        const int memUnitSize,
        const boolean_T isUsingCommService);
                
CODEINSTRSERVICE_API_EXTERN_C void codeInstrServiceSetTime( 
        void* const pCodeInstrService,                       
        const time_T simTime);
        
CODEINSTRSERVICE_API_EXTERN_C void codeInstrServiceDestroy( 
        void* const pCodeInstrService,
        const CodeInstrServiceData_T* const pData);

        
#endif


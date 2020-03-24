/* Copyright 2015 The MathWorks, Inc. */

#ifndef CODERASSUMPTIONSAPP_SPEC_H
#define CODERASSUMPTIONSAPP_SPEC_H

#ifdef BUILDING_LIBMWCODERASSUMPTIONSAPP

#define CODERASSUMPTIONSAPP_API                 DLL_EXPORT_SYM
#define CODERASSUMPTIONSAPP_API_EXTERN_C        extern "C" DLL_EXPORT_SYM

#elif defined(DLL_IMPORT_SYM)

#define CODERASSUMPTIONSAPP_API                 DLL_IMPORT_SYM
#define CODERASSUMPTIONSAPP_API_EXTERN_C        extern "C" DLL_IMPORT_SYM

#else

#define CODERASSUMPTIONSAPP_API                  extern
#ifdef __cplusplus
    #define CODERASSUMPTIONSAPP_API_EXTERN_C     extern "C"
#else
    #define CODERASSUMPTIONSAPP_API_EXTERN_C     extern
#endif
#endif

#endif

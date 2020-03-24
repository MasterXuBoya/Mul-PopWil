/* Copyright 2013 MathWorks, Inc. */

#ifndef XILSERVICE_SPEC_H
#define XILSERVICE_SPEC_H

#ifdef BUILDING_LIBMWXILSERVICE

#define XILSERVICE_API                 DLL_EXPORT_SYM
#define XILSERVICE_API_EXTERN_C        extern "C" DLL_EXPORT_SYM

#elif defined(DLL_IMPORT_SYM)

#define XILSERVICE_API                 DLL_IMPORT_SYM
#define XILSERVICE_API_EXTERN_C        extern "C" DLL_IMPORT_SYM

#else

#define XILSERVICE_API                  extern
#ifdef __cplusplus
    #define XILSERVICE_API_EXTERN_C     extern "C"
#else
    #define XILSERVICE_API_EXTERN_C     extern
#endif
#endif

#endif

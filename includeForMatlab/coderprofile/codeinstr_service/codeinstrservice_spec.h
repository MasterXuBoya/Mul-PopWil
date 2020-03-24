/* Copyright 2013 MathWorks, Inc. */
#ifndef CODEINSTRSERVICE_SPEC_H
#define CODEINSTRSERVICE_SPEC_H


#ifdef BUILDING_LIBMWCODERPROFILE
/* This file is being included by files inside this module */
#define CODEINSTRSERVICE_API                 DLL_EXPORT_SYM
#define CODEINSTRSERVICE_API_EXTERN_C        extern "C" DLL_EXPORT_SYM

#ifndef MATLAB_MEX_FILE
    #define MATLAB_MEX_FILE
#endif

#elif defined(DLL_IMPORT_SYM)
/* This file is being included by other TMW internal modules */
#define CODEINSTRSERVICE_API                 DLL_IMPORT_SYM
#define CODEINSTRSERVICE_API_EXTERN_C        extern "C" DLL_IMPORT_SYM

#else
/* This file is being included by external users */
#define CODEINSTRSERVICE_API                  extern
#ifdef __cplusplus
    #define CODEINSTRSERVICE_API_EXTERN_C     extern "C"
#else
    #define CODEINSTRSERVICE_API_EXTERN_C     extern
#endif
#endif

#endif


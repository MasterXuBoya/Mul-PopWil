//
// MATLAB Compiler: 6.1 (R2015b)
// Date: Fri Nov 16 21:29:31 2018
// Arguments: "-B" "macro_default" "-W" "cpplib:tfeFun" "-T" "link:lib" "-d"
// "C:\Users\Administrator\Documents\MATLAB\MATLABForCPlus\tfeFun\for_testing"
// "-v" "C:\Users\Administrator\Documents\MATLAB\MATLABForCPlus\tfeFun.m" 
//

#ifndef __tfeFun_h
#define __tfeFun_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_tfeFun
#define PUBLIC_tfeFun_C_API __global
#else
#define PUBLIC_tfeFun_C_API /* No import statement needed. */
#endif

#define LIB_tfeFun_C_API PUBLIC_tfeFun_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_tfeFun
#define PUBLIC_tfeFun_C_API __declspec(dllexport)
#else
#define PUBLIC_tfeFun_C_API __declspec(dllimport)
#endif

#define LIB_tfeFun_C_API PUBLIC_tfeFun_C_API


#else

#define LIB_tfeFun_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_tfeFun_C_API 
#define LIB_tfeFun_C_API /* No special import/export declaration */
#endif

extern LIB_tfeFun_C_API 
bool MW_CALL_CONV tfeFunInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_tfeFun_C_API 
bool MW_CALL_CONV tfeFunInitialize(void);

extern LIB_tfeFun_C_API 
void MW_CALL_CONV tfeFunTerminate(void);



extern LIB_tfeFun_C_API 
void MW_CALL_CONV tfeFunPrintStackTrace(void);

extern LIB_tfeFun_C_API 
bool MW_CALL_CONV mlxTfeFun(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_tfeFun
#define PUBLIC_tfeFun_CPP_API __declspec(dllexport)
#else
#define PUBLIC_tfeFun_CPP_API __declspec(dllimport)
#endif

#define LIB_tfeFun_CPP_API PUBLIC_tfeFun_CPP_API

#else

#if !defined(LIB_tfeFun_CPP_API)
#if defined(LIB_tfeFun_C_API)
#define LIB_tfeFun_CPP_API LIB_tfeFun_C_API
#else
#define LIB_tfeFun_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_tfeFun_CPP_API void MW_CALL_CONV tfeFun(int nargout, mwArray& y, mwArray& f);

#endif
#endif

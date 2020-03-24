//
// MATLAB Compiler: 6.1 (R2015b)
// Date: Sun Apr 21 16:06:37 2019
// Arguments: "-B" "macro_default" "-W" "cpplib:transformFunction" "-T"
// "link:lib" "-d" "C:\Users\Administrator\Documents\MATLAB\Off-line Iterative
// Control\transformFunction\for_testing" "-v"
// "C:\Users\Administrator\Documents\MATLAB\Off-line Iterative
// Control\transformFunction.m" 
//

#ifndef __transformFunction_h
#define __transformFunction_h 1

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

#ifdef EXPORTING_transformFunction
#define PUBLIC_transformFunction_C_API __global
#else
#define PUBLIC_transformFunction_C_API /* No import statement needed. */
#endif

#define LIB_transformFunction_C_API PUBLIC_transformFunction_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_transformFunction
#define PUBLIC_transformFunction_C_API __declspec(dllexport)
#else
#define PUBLIC_transformFunction_C_API __declspec(dllimport)
#endif

#define LIB_transformFunction_C_API PUBLIC_transformFunction_C_API


#else

#define LIB_transformFunction_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_transformFunction_C_API 
#define LIB_transformFunction_C_API /* No special import/export declaration */
#endif

extern LIB_transformFunction_C_API 
bool MW_CALL_CONV transformFunctionInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_transformFunction_C_API 
bool MW_CALL_CONV transformFunctionInitialize(void);

extern LIB_transformFunction_C_API 
void MW_CALL_CONV transformFunctionTerminate(void);



extern LIB_transformFunction_C_API 
void MW_CALL_CONV transformFunctionPrintStackTrace(void);

extern LIB_transformFunction_C_API 
bool MW_CALL_CONV mlxTransformFunction(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                       *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_transformFunction
#define PUBLIC_transformFunction_CPP_API __declspec(dllexport)
#else
#define PUBLIC_transformFunction_CPP_API __declspec(dllimport)
#endif

#define LIB_transformFunction_CPP_API PUBLIC_transformFunction_CPP_API

#else

#if !defined(LIB_transformFunction_CPP_API)
#if defined(LIB_transformFunction_C_API)
#define LIB_transformFunction_CPP_API LIB_transformFunction_C_API
#else
#define LIB_transformFunction_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_transformFunction_CPP_API void MW_CALL_CONV transformFunction(int nargout, mwArray& Txy, mwArray& F, const mwArray& x, const mwArray& y, const mwArray& nfft, const mwArray& fs);

#endif
#endif

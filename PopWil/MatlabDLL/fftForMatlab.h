//
// MATLAB Compiler: 6.1 (R2015b)
// Date: Thu Nov 15 16:11:27 2018
// Arguments: "-B" "macro_default" "-W" "cpplib:fftForMatlab" "-T" "link:lib"
// "-d"
// "C:\Users\Administrator\Documents\MATLAB\MATLABForCPlus\fftForMatlab\for_test
// ing" "-v"
// "C:\Users\Administrator\Documents\MATLAB\MATLABForCPlus\fftForMatlab.m" 
//

#ifndef __fftForMatlab_h
#define __fftForMatlab_h 1

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

#ifdef EXPORTING_fftForMatlab
#define PUBLIC_fftForMatlab_C_API __global
#else
#define PUBLIC_fftForMatlab_C_API /* No import statement needed. */
#endif

#define LIB_fftForMatlab_C_API PUBLIC_fftForMatlab_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_fftForMatlab
#define PUBLIC_fftForMatlab_C_API __declspec(dllexport)
#else
#define PUBLIC_fftForMatlab_C_API __declspec(dllimport)
#endif

#define LIB_fftForMatlab_C_API PUBLIC_fftForMatlab_C_API


#else

#define LIB_fftForMatlab_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_fftForMatlab_C_API 
#define LIB_fftForMatlab_C_API /* No special import/export declaration */
#endif

extern LIB_fftForMatlab_C_API 
bool MW_CALL_CONV fftForMatlabInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_fftForMatlab_C_API 
bool MW_CALL_CONV fftForMatlabInitialize(void);

extern LIB_fftForMatlab_C_API 
void MW_CALL_CONV fftForMatlabTerminate(void);



extern LIB_fftForMatlab_C_API 
void MW_CALL_CONV fftForMatlabPrintStackTrace(void);

extern LIB_fftForMatlab_C_API 
bool MW_CALL_CONV mlxFftForMatlab(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_fftForMatlab
#define PUBLIC_fftForMatlab_CPP_API __declspec(dllexport)
#else
#define PUBLIC_fftForMatlab_CPP_API __declspec(dllimport)
#endif

#define LIB_fftForMatlab_CPP_API PUBLIC_fftForMatlab_CPP_API

#else

#if !defined(LIB_fftForMatlab_CPP_API)
#if defined(LIB_fftForMatlab_C_API)
#define LIB_fftForMatlab_CPP_API LIB_fftForMatlab_C_API
#else
#define LIB_fftForMatlab_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_fftForMatlab_CPP_API void MW_CALL_CONV fftForMatlab(int nargout, mwArray& y, const mwArray& x);

#endif
#endif

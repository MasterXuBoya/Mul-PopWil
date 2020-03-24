//
// MATLAB Compiler: 6.1 (R2015b)
// Date: Fri Apr 26 17:38:26 2019
// Arguments: "-B" "macro_default" "-W" "cpplib:generateFirstDrive" "-T"
// "link:lib" "-d" "C:\Users\Administrator\Documents\MATLAB\Off-line Iterative
// Control\generateFirstDrive\for_testing" "-v"
// "C:\Users\Administrator\Documents\MATLAB\Off-line Iterative
// Control\generateFirstDrive.m" 
//

#ifndef __generateFirstDrive_h
#define __generateFirstDrive_h 1

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

#ifdef EXPORTING_generateFirstDrive
#define PUBLIC_generateFirstDrive_C_API __global
#else
#define PUBLIC_generateFirstDrive_C_API /* No import statement needed. */
#endif

#define LIB_generateFirstDrive_C_API PUBLIC_generateFirstDrive_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_generateFirstDrive
#define PUBLIC_generateFirstDrive_C_API __declspec(dllexport)
#else
#define PUBLIC_generateFirstDrive_C_API __declspec(dllimport)
#endif

#define LIB_generateFirstDrive_C_API PUBLIC_generateFirstDrive_C_API


#else

#define LIB_generateFirstDrive_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_generateFirstDrive_C_API 
#define LIB_generateFirstDrive_C_API /* No special import/export declaration */
#endif

extern LIB_generateFirstDrive_C_API 
bool MW_CALL_CONV generateFirstDriveInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_generateFirstDrive_C_API 
bool MW_CALL_CONV generateFirstDriveInitialize(void);

extern LIB_generateFirstDrive_C_API 
void MW_CALL_CONV generateFirstDriveTerminate(void);



extern LIB_generateFirstDrive_C_API 
void MW_CALL_CONV generateFirstDrivePrintStackTrace(void);

extern LIB_generateFirstDrive_C_API 
bool MW_CALL_CONV mlxGenerateFirstDrive(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                        *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_generateFirstDrive
#define PUBLIC_generateFirstDrive_CPP_API __declspec(dllexport)
#else
#define PUBLIC_generateFirstDrive_CPP_API __declspec(dllimport)
#endif

#define LIB_generateFirstDrive_CPP_API PUBLIC_generateFirstDrive_CPP_API

#else

#if !defined(LIB_generateFirstDrive_CPP_API)
#if defined(LIB_generateFirstDrive_C_API)
#define LIB_generateFirstDrive_CPP_API LIB_generateFirstDrive_C_API
#else
#define LIB_generateFirstDrive_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_generateFirstDrive_CPP_API void MW_CALL_CONV generateFirstDrive(int nargout, mwArray& newX, const mwArray& Txy, const mwArray& F, const mwArray& yd, const mwArray& nfft, const mwArray& Fs);

#endif
#endif

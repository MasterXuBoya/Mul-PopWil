/* Copyright 2012 The MathWorks, Inc. */

#ifndef _OPTICALFLOWHSCORE_
#define _OPTICALFLOWHSCORE_

#ifndef LIBMWOPTICALFLOWHSCORE_API
#    define LIBMWOPTICALFLOWHSCORE_API
#endif

#ifndef EXTERN_C
#  ifdef __cplusplus
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

EXTERN_C LIBMWOPTICALFLOWHSCORE_API void MWCV_OpticalFlow_HS_double( const real_T  *inImgA, 
                                        const real_T  *inImgB,
                                        real_T  *outVelC, 
                                        real_T  *outVelR, 
                                        real_T  *buffCprev, 
                                        real_T  *buffCnext, 
                                        real_T  *buffRprev, 
                                        real_T  *buffRnext, 
                                        real_T  *gradCC, 
                                        real_T  *gradRC, 
                                        real_T  *gradRR, 
                                        real_T  *gradCT, 
                                        real_T  *gradRT, 
                                        real_T  *alpha,  
                                        real_T  *velBufCcurr, 
                                        real_T  *velBufCprev, 
                                        real_T  *velBufRcurr, 
                                        real_T  *velBufRprev, 
                                        const real_T  *lambda,
                                        boolean_T useMaxIter, 
                                        boolean_T useAbsVelDiff,
                                        const int32_T *maxIter, 
                                        const real_T  *maxAllowableAbsDiffVel,
                                        int_T  inRows,
                                        int_T  inCols);

EXTERN_C LIBMWOPTICALFLOWHSCORE_API void MWCV_OpticalFlow_HS_single( const real32_T  *inImgA,
                                        const real32_T  *inImgB,
                                        real32_T  *outVelC, 
                                        real32_T  *outVelR, 
                                        real32_T  *buffCprev, 
                                        real32_T  *buffCnext, 
                                        real32_T  *buffRprev, 
                                        real32_T  *buffRnext, 
                                        real32_T  *gradCC, 
                                        real32_T  *gradRC, 
                                        real32_T  *gradRR, 
                                        real32_T  *gradCT, 
                                        real32_T  *gradRT, 
                                        real32_T  *alpha,  
                                        real32_T  *velBufCcurr, 
                                        real32_T  *velBufCprev, 
                                        real32_T  *velBufRcurr, 
                                        real32_T  *velBufRprev, 
                                        const real32_T  *lambda,
                                        boolean_T useMaxIter, 
                                        boolean_T useAbsVelDiff,
                                        const int32_T *maxIter, 
                                        const real32_T  *maxAllowableAbsDiffVel,
                                        int_T  inRows, 
                                        int_T  inCols); 

EXTERN_C LIBMWOPTICALFLOWHSCORE_API void MWCV_OpticalFlow_HS_uint8( const uint8_T  *inImgA, 
                                        const uint8_T  *inImgB,
                                        real32_T  *outVelC, 
                                        real32_T  *outVelR, 
                                        real32_T  *buffCprev,
                                        real32_T  *buffCnext,
                                        real32_T  *buffRprev,
                                        real32_T  *buffRnext,
                                        real32_T  *gradCC,
                                        real32_T  *gradRC,
                                        real32_T  *gradRR,
                                        real32_T  *gradCT,
                                        real32_T  *gradRT,
                                        real32_T  *alpha, 
                                        real32_T  *velBufCcurr, 
                                        real32_T  *velBufCprev, 
                                        real32_T  *velBufRcurr, 
                                        real32_T  *velBufRprev, 
                                        const real32_T  *lambda,
                                        boolean_T useMaxIter, 
                                        boolean_T useAbsVelDiff,
                                        const int32_T *maxIter, 
                                        const real32_T  *maxAllowableAbsDiffVel, 
                                        int_T  inRows, 
                                        int_T  inCols);
#endif

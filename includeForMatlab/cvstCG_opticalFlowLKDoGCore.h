/* Copyright 2012 The MathWorks, Inc. */

#ifndef _OPTICALFLOWLKDOGCORE_
#define _OPTICALFLOWLKDOGCORE_

#ifndef LIBMWOPTICALFLOWLKDOGCORE_API
#    define LIBMWOPTICALFLOWLKDOGCORE_API
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

EXTERN_C LIBMWOPTICALFLOWLKDOGCORE_API void MWCV_OpticalFlow_LKDoG_double( const real_T  *inImgA, 
                                    const real_T  *delayBuffer, 
                                    const uint32_T *allIdx,
                                    const int_T  numFramesInBuffer, 
                                            real_T  *outVelC, /* output velocity - component along column */
                                            real_T  *outVelR, /* output velocity - component along row */
                                            real_T  *dx, /* xx => gradCC */
                                            real_T  *dy, /* yy => gradRC */
                                            real_T  *dt, /* xy => gradRR */
                                            real_T  *xt, /* gradCT */
                                            real_T  *yt, /* gradRT */
                                            const real_T *eigTh,
                                            const real_T *tGradKernel,
                                            const real_T *sGradKernel,
                                            const real_T *tKernel,
                                            const real_T *sKernel,
                                            const real_T *wKernel,
                                            int_T   inRows,
                                            int_T   inCols,
                                            int_T tGradKernelLen,
                                            int_T sGradKernelLen,
                                            int_T tKernelLen,
                                            int_T sKernelLen,
                                            int_T wKernelLen,
                                            boolean_T includeNormalFlow);

EXTERN_C LIBMWOPTICALFLOWLKDOGCORE_API void MWCV_OpticalFlow_LKDoG_single( const real32_T  *inImgA, 
                                    const real32_T  *delayBuffer, 
                                    const uint32_T *allIdx,
                                    const int_T  numFramesInBuffer, 
                                            real32_T  *outVelC, /* output velocity - component along column */
                                            real32_T  *outVelR, /* output velocity - component along row */
                                            real32_T  *dx, /* xx => gradCC */
                                            real32_T  *dy, /* yy => gradRC */
                                            real32_T  *dt, /* xy => gradRR */
                                            real32_T  *xt, /* gradCT */
                                            real32_T  *yt, /* gradRT */
                                            const real32_T *eigTh,
                                            const real32_T *tGradKernel,
                                            const real32_T *sGradKernel,
                                            const real32_T *tKernel,
                                            const real32_T *sKernel,
                                            const real32_T *wKernel,
                                            int_T   inRows,
                                            int_T   inCols,
                                            int_T tGradKernelLen,
                                            int_T sGradKernelLen,
                                            int_T tKernelLen,
                                            int_T sKernelLen,
                                            int_T wKernelLen,
                                            boolean_T includeNormalFlow);

EXTERN_C LIBMWOPTICALFLOWLKDOGCORE_API void MWCV_OpticalFlow_LKDoG_uint8( const uint8_T  *inImgA, 
                                    const uint8_T  *delayBuffer, 
                                    const uint32_T *allIdx,
                                    const int_T  numFramesInBuffer,   
                                            real32_T  *outVelC, /* output velocity - component along column */
                                            real32_T  *outVelR, /* output velocity - component along row */
                                            real32_T  *dx, /* xx => gradCC */
                                            real32_T  *dy, /* yy => gradRC */
                                            real32_T  *dt, /* xy => gradRR */
                                            real32_T  *xt, /* gradCT */
                                            real32_T  *yt, /* gradRT */
                                            const real32_T *eigTh,
                                            const real32_T *tGradKernel,
                                            const real32_T *sGradKernel,
                                            const real32_T *tKernel,
                                            const real32_T *sKernel,
                                            const real32_T *wKernel,
                                            int_T   inRows,
                                            int_T   inCols,
                                            int_T tGradKernelLen,
                                            int_T sGradKernelLen,
                                            int_T tKernelLen,
                                            int_T sKernelLen,
                                            int_T wKernelLen,
                                            boolean_T includeNormalFlow);
#endif

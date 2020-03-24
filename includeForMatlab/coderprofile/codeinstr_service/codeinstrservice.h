/* Copyright 2013 The MathWorks, Inc. */

#ifndef _codeinstrservice_h_
#define _codeinstrservice_h_

#include "codeinstrservice_spec.h"

#if defined (MATLAB_MEX_FILE) || defined(BUILDING_LIBMWCODERPROFILE)
/* This file is being compiled as a mex file or when building this module */
#include "tmwtypes.h"
#else
/* This file is being compiled on the target */
#include "rtwtypes.h"
#endif

#define CODEINSTR_SERVICE_ID 2
static const boolean_T CODEINSTR_SERVICE_ERROR = 0;
static const boolean_T CODEINSTR_SERVICE_SUCCESS = 1;

#endif


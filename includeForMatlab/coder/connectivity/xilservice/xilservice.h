/* Copyright 2013 The MathWorks, Inc. */

#ifndef _xilservice_h_
#define _xilservice_h_

#include "xilservice_spec.h"

#if defined (MATLAB_MEX_FILE) || defined(BUILDING_LIBMWXILSERVICE)

#include "tmwtypes.h"
#else

#include "rtwtypes.h"
#endif

#define XIL_SERVICE_ID 1

static const boolean_T XILSERVICE_ERROR = 0;
static const boolean_T XILSERVICE_SUCCESS = 1;

typedef enum {XIL_COMMAND_NOT_COMPLETE=0,
              XIL_COMMAND_COMPLETE,
              XIL_STEP_COMPLETE} XILCommandResponseType;
             
#endif

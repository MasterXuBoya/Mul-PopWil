/* Copyright 2015 The MathWorks, Inc. */

#ifndef PTPLIB_H
#define PTPLIB_H

#include "ptp_types.h"

#ifdef  __cplusplus
extern "C" {
#endif

PTP_ReturnType PTP_Init(PTP_ConfigParams const * const params,
						boolean_T first);

PTP_ReturnType PTP_StateProtocol(PTP_ConfigParams const * const cfgParams);

void PTP_UpdateMessageTxTriggerTimers(boolean_T * const announceTrigger,
								      boolean_T * const syncTrigger,
								      boolean_T * const delayReqTrigger);

uint8_T PTP_GetDelayMeasurementMechanism(void);

PTP_ReturnType PTP_IssueMessage(void * const buf,
	                            uint8_T msgType);

PTP_ReturnType PTP_ProcessMessage(void * const msgBuf,
	                              uint16_T bufLength,
								  boolean_T* isValidMsg);

PTP_ReturnType PTP_AdjustTime(void);

PTP_ReturnType PTP_ReadTime(SYSTEMTIME * const sysTime,
						    ULARGE_INTEGER * const systTimeNano,
						    ULARGE_INTEGER * const tickCountValue);

PTP_ReturnType PTP_ReadParameters(PTP_PortState * const state, 
							      LARGE_INTEGER * const offset,
							      LARGE_INTEGER * const pathDelay,
							      real_T * const driftRate);

boolean_T PTP_IsSynchronized(real_T threshold);

#ifdef  __cplusplus
}
#endif

#endif

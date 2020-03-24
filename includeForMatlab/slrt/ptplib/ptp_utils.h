/* Copyright 2015 The MathWorks, Inc. */

#ifndef PTP_UTILS_H
#define PTP_UTILS_H

#include "ptp_types.h"
#include "slrt_ptplib_spec.h"

#ifdef  __cplusplus
extern "C" {
#endif

uint16_T SLRT_PTPLIB_EXPORT_FCN PTP_GetMessageLength(uint8_T message_type);

uint8_T SLRT_PTPLIB_EXPORT_FCN PTP_NormalizeMessageType(uint8_T type_from_block);

uint16_T SLRT_PTPLIB_EXPORT_FCN  PTP_GetManagementMessageLength(PTP_ManagementId managementId);

boolean_T PTP_ValidateMessageLength(uint16_T messageLength,
	                                uint8_T msgType);

boolean_T PTP_ValidateManagementAction(PTP_ManagementId managementId,
	                                   PTP_ManagementActionField action);

boolean_T PTP_ValidateManagementMessageLength(PTP_ManagementId managementId,
	                                          uint16_T msg_length);

int8_T roundToInt8(real_T val);

#ifdef  __cplusplus
}
#endif

#endif
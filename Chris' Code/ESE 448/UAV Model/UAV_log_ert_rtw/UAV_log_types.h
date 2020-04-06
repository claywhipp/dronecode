/*
 * UAV_log_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "UAV_log".
 *
 * Model version              : 1.170
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri Mar 13 17:53:49 2020
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_UAV_log_types_h_
#define RTW_HEADER_UAV_log_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "HAL.h"
#ifndef DEFINED_TYPEDEF_FOR_CommandBus_
#define DEFINED_TYPEDEF_FOR_CommandBus_

typedef struct {
  boolean_T controlModePosVSOrient;
  real32_T pos_ref[3];
  boolean_T takeoff_flag;
  real32_T orient_ref[3];
  uint32_T live_time_ticks;
} CommandBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_extraSensorData_t_
#define DEFINED_TYPEDEF_FOR_extraSensorData_t_

typedef struct {
  real32_T opticalFlow_data[3];
  real32_T posVIS_data[4];
  real32_T usePosVIS_flag;
} extraSensorData_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SensorsBus_
#define DEFINED_TYPEDEF_FOR_SensorsBus_

typedef struct {
  extraSensorData_t VisionSensors;
  HAL_acquisition_t HALSensors;
  real32_T SensorCalibration[8];
} SensorsBus;

#endif

/* Parameters for system: '<S30>/MeasurementUpdate' */
typedef struct P_MeasurementUpdate_UAV_log_T_ P_MeasurementUpdate_UAV_log_T;

/* Parameters for system: '<S37>/Enabled Subsystem' */
typedef struct P_EnabledSubsystem_UAV_log_T_ P_EnabledSubsystem_UAV_log_T;

/* Parameters (default storage) */
typedef struct P_UAV_log_T_ P_UAV_log_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_UAV_log_T RT_MODEL_UAV_log_T;

#endif                                 /* RTW_HEADER_UAV_log_types_h_ */

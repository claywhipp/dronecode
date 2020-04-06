/*
 * HW6_v1_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "HW6_v1".
 *
 * Model version              : 1.134
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Sun Apr  5 22:41:58 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_HW6_v1_types_h_
#define RTW_HEADER_HW6_v1_types_h_
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

/* Parameters for system: '<S32>/MeasurementUpdate' */
typedef struct P_MeasurementUpdate_HW6_v1_T_ P_MeasurementUpdate_HW6_v1_T;

/* Parameters for system: '<S39>/Enabled Subsystem' */
typedef struct P_EnabledSubsystem_HW6_v1_T_ P_EnabledSubsystem_HW6_v1_T;

/* Parameters (default storage) */
typedef struct P_HW6_v1_T_ P_HW6_v1_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_HW6_v1_T RT_MODEL_HW6_v1_T;

#endif                                 /* RTW_HEADER_HW6_v1_types_h_ */

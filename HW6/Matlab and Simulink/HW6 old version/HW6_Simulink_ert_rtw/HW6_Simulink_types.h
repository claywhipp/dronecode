/*
 * HW6_Simulink_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "HW6_Simulink".
 *
 * Model version              : 1.81
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Mon Mar 30 12:31:25 2020
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_HW6_Simulink_types_h_
#define RTW_HEADER_HW6_Simulink_types_h_
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

/* Parameters for system: '<S28>/MeasurementUpdate' */
typedef struct P_MeasurementUpdate_HW6_Simul_T_ P_MeasurementUpdate_HW6_Simul_T;

/* Parameters for system: '<S35>/Enabled Subsystem' */
typedef struct P_EnabledSubsystem_HW6_Simuli_T_ P_EnabledSubsystem_HW6_Simuli_T;

/* Parameters (default storage) */
typedef struct P_HW6_Simulink_T_ P_HW6_Simulink_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_HW6_Simulink_T RT_MODEL_HW6_Simulink_T;

#endif                                 /* RTW_HEADER_HW6_Simulink_types_h_ */

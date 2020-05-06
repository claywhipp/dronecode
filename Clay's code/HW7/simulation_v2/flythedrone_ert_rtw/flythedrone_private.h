/*
 * flythedrone_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flythedrone".
 *
 * Model version              : 1.196
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed May  6 16:36:38 2020
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_flythedrone_private_h_
#define RTW_HEADER_flythedrone_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "flythedrone.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

extern void flythedr_MeasurementUpdate_Init(B_MeasurementUpdate_flythedro_T
  *localB, P_MeasurementUpdate_flythedro_T *localP);
extern void flythed_MeasurementUpdate_Start(DW_MeasurementUpdate_flythedr_T
  *localDW);
extern void flyth_MeasurementUpdate_Disable(B_MeasurementUpdate_flythedro_T
  *localB, DW_MeasurementUpdate_flythedr_T *localDW,
  P_MeasurementUpdate_flythedro_T *localP);
extern void flythedrone_MeasurementUpdate(boolean_T rtu_Enable, real_T rtu_Lk,
  real_T rtu_yk, real_T rtu_Ck, real_T rtu_xhatkk1, real_T rtu_Dk, real_T rtu_uk,
  B_MeasurementUpdate_flythedro_T *localB, DW_MeasurementUpdate_flythedr_T
  *localDW, P_MeasurementUpdate_flythedro_T *localP);
extern void flythedro_EnabledSubsystem_Init(B_EnabledSubsystem_flythedron_T
  *localB, P_EnabledSubsystem_flythedron_T *localP);
extern void flythedr_EnabledSubsystem_Start(DW_EnabledSubsystem_flythedro_T
  *localDW);
extern void flythe_EnabledSubsystem_Disable(B_EnabledSubsystem_flythedron_T
  *localB, DW_EnabledSubsystem_flythedro_T *localDW,
  P_EnabledSubsystem_flythedron_T *localP);
extern void flythedrone_EnabledSubsystem(boolean_T rtu_Enable, real_T rtu_Mk,
  real_T rtu_Ck, real_T rtu_yk, real_T rtu_xhatkk1,
  B_EnabledSubsystem_flythedron_T *localB, DW_EnabledSubsystem_flythedro_T
  *localDW, P_EnabledSubsystem_flythedron_T *localP);

#endif                                 /* RTW_HEADER_flythedrone_private_h_ */

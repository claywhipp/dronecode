/*
 * HW6_Simulink_private.h
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

#ifndef RTW_HEADER_HW6_Simulink_private_h_
#define RTW_HEADER_HW6_Simulink_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "HW6_Simulink.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern void HW6_Simu_MeasurementUpdate_Init(B_MeasurementUpdate_HW6_Simul_T
  *localB, P_MeasurementUpdate_HW6_Simul_T *localP);
extern void HW6_Sim_MeasurementUpdate_Start(DW_MeasurementUpdate_HW6_Simu_T
  *localDW);
extern void HW6_S_MeasurementUpdate_Disable(B_MeasurementUpdate_HW6_Simul_T
  *localB, DW_MeasurementUpdate_HW6_Simu_T *localDW,
  P_MeasurementUpdate_HW6_Simul_T *localP);
extern void HW6_Simulink_MeasurementUpdate(RT_MODEL_HW6_Simulink_T * const
  HW6_Simulink_M, boolean_T rtu_Enable, real_T rtu_Lk, real_T rtu_yk, real_T
  rtu_Ck, real_T rtu_xhatkk1, real_T rtu_Dk, real_T rtu_uk,
  B_MeasurementUpdate_HW6_Simul_T *localB, DW_MeasurementUpdate_HW6_Simu_T
  *localDW, P_MeasurementUpdate_HW6_Simul_T *localP);
extern void HW6_Simul_EnabledSubsystem_Init(B_EnabledSubsystem_HW6_Simuli_T
  *localB, P_EnabledSubsystem_HW6_Simuli_T *localP);
extern void HW6_Simu_EnabledSubsystem_Start(DW_EnabledSubsystem_HW6_Simul_T
  *localDW);
extern void HW6_Si_EnabledSubsystem_Disable(B_EnabledSubsystem_HW6_Simuli_T
  *localB, DW_EnabledSubsystem_HW6_Simul_T *localDW,
  P_EnabledSubsystem_HW6_Simuli_T *localP);
extern void HW6_Simulink_EnabledSubsystem(RT_MODEL_HW6_Simulink_T * const
  HW6_Simulink_M, boolean_T rtu_Enable, real_T rtu_Mk, real_T rtu_Ck, real_T
  rtu_yk, real_T rtu_xhatkk1, B_EnabledSubsystem_HW6_Simuli_T *localB,
  DW_EnabledSubsystem_HW6_Simul_T *localDW, P_EnabledSubsystem_HW6_Simuli_T
  *localP);

/* private model entry point functions */
extern void HW6_Simulink_derivatives(void);

#endif                                 /* RTW_HEADER_HW6_Simulink_private_h_ */

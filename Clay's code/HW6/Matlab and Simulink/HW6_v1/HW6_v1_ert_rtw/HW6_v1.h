/*
 * HW6_v1.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "HW6_v1".
 *
 * Model version              : 1.140
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed May  6 14:58:41 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_HW6_v1_h_
#define RTW_HEADER_HW6_v1_h_
#include <stddef.h>
#include <string.h>
#include <float.h>
#ifndef HW6_v1_COMMON_INCLUDES_
# define HW6_v1_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* HW6_v1_COMMON_INCLUDES_ */

#include "HW6_v1_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals for system '<S29>/MeasurementUpdate' */
typedef struct {
  real_T Product3;                     /* '<S58>/Product3' */
} B_MeasurementUpdate_HW6_v1_T;

/* Block states (default storage) for system '<S29>/MeasurementUpdate' */
typedef struct {
  boolean_T MeasurementUpdate_MODE;    /* '<S29>/MeasurementUpdate' */
} DW_MeasurementUpdate_HW6_v1_T;

/* Block signals for system '<S36>/Enabled Subsystem' */
typedef struct {
  real_T Product2;                     /* '<S60>/Product2' */
} B_EnabledSubsystem_HW6_v1_T;

/* Block states (default storage) for system '<S36>/Enabled Subsystem' */
typedef struct {
  boolean_T EnabledSubsystem_MODE;     /* '<S36>/Enabled Subsystem' */
} DW_EnabledSubsystem_HW6_v1_T;

/* Block signals (default storage) */
typedef struct {
  real_T TmpSignalConversionAtToWork[17];
  real_T Akxhatkk1[2];                 /* '<S237>/A[k]*xhat[k|k-1]' */
  real_T Add[2];                       /* '<S237>/Add' */
  real_T DataTypeConversion1;          /* '<S1>/Data Type Conversion1' */
  real_T DataTypeConversion2;          /* '<S1>/Data Type Conversion2' */
  real_T Sum1;                         /* '<S1>/Sum1' */
  real_T DataTypeConversion3;          /* '<S1>/Data Type Conversion3' */
  real_T DataTypeConversion4;          /* '<S1>/Data Type Conversion4' */
  real_T DataTypeConversion5;          /* '<S1>/Data Type Conversion5' */
  real_T Integrator;                   /* '<S1>/Integrator' */
  real_T Integrator2;                  /* '<S1>/Integrator2' */
  real_T Integrator4;                  /* '<S1>/Integrator4' */
  real_T Product2[2];                  /* '<S268>/Product2' */
  real_T Product3[2];                  /* '<S266>/Product3' */
  real_T Reshapey;                     /* '<S8>/Reshapey' */
  real_T Gain1;
  real_T Sum1_m;
  real_T rtb_MemoryX_idx_0;
  real_T rtb_MemoryX_idx_1;
  real_T Reshapey_e;                   /* '<S6>/Reshapey' */
  real_T MemoryX_o;                    /* '<S6>/MemoryX' */
  real_T Bkuk_e;                       /* '<S185>/B[k]*u[k]' */
  real_T Reshapey_o;                   /* '<S7>/Reshapey' */
  real_T MemoryX_j;                    /* '<S7>/MemoryX' */
  B_EnabledSubsystem_HW6_v1_T EnabledSubsystem_f;/* '<S192>/Enabled Subsystem' */
  B_MeasurementUpdate_HW6_v1_T MeasurementUpdate_f;/* '<S185>/MeasurementUpdate' */
  B_EnabledSubsystem_HW6_v1_T EnabledSubsystem_d;/* '<S140>/Enabled Subsystem' */
  B_MeasurementUpdate_HW6_v1_T MeasurementUpdate_h;/* '<S133>/MeasurementUpdate' */
  B_EnabledSubsystem_HW6_v1_T EnabledSubsystem_e;/* '<S88>/Enabled Subsystem' */
  B_MeasurementUpdate_HW6_v1_T MeasurementUpdate_o;/* '<S81>/MeasurementUpdate' */
  B_EnabledSubsystem_HW6_v1_T EnabledSubsystem;/* '<S36>/Enabled Subsystem' */
  B_MeasurementUpdate_HW6_v1_T MeasurementUpdate;/* '<S29>/MeasurementUpdate' */
} B_HW6_v1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T MemoryX_DSTATE[2];            /* '<S8>/MemoryX' */
  real_T MemoryX_DSTATE_l;             /* '<S6>/MemoryX' */
  real_T MemoryX_DSTATE_f;             /* '<S7>/MemoryX' */
  real_T MemoryX_DSTATE_j;             /* '<S4>/MemoryX' */
  real_T MemoryX_DSTATE_m;             /* '<S5>/MemoryX' */
  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<S1>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<S1>/To Workspace2' */

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK;                /* '<S1>/To Workspace3' */

  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK;                /* '<S1>/To Workspace4' */

  struct {
    void *LoggedData;
  } ToWorkspace5_PWORK;                /* '<S1>/To Workspace5' */

  struct {
    void *LoggedData;
  } ToWorkspace6_PWORK;                /* '<S1>/To Workspace6' */

  struct {
    void *LoggedData;
  } ToWorkspace7_PWORK;                /* '<S1>/To Workspace7' */

  uint8_T icLoad;                      /* '<S8>/MemoryX' */
  uint8_T icLoad_m;                    /* '<S6>/MemoryX' */
  uint8_T icLoad_l;                    /* '<S7>/MemoryX' */
  uint8_T icLoad_h;                    /* '<S4>/MemoryX' */
  uint8_T icLoad_l4;                   /* '<S5>/MemoryX' */
  boolean_T EnabledSubsystem_MODE;     /* '<S244>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S237>/MeasurementUpdate' */
  DW_EnabledSubsystem_HW6_v1_T EnabledSubsystem_f;/* '<S192>/Enabled Subsystem' */
  DW_MeasurementUpdate_HW6_v1_T MeasurementUpdate_f;/* '<S185>/MeasurementUpdate' */
  DW_EnabledSubsystem_HW6_v1_T EnabledSubsystem_d;/* '<S140>/Enabled Subsystem' */
  DW_MeasurementUpdate_HW6_v1_T MeasurementUpdate_h;/* '<S133>/MeasurementUpdate' */
  DW_EnabledSubsystem_HW6_v1_T EnabledSubsystem_e;/* '<S88>/Enabled Subsystem' */
  DW_MeasurementUpdate_HW6_v1_T MeasurementUpdate_o;/* '<S81>/MeasurementUpdate' */
  DW_EnabledSubsystem_HW6_v1_T EnabledSubsystem;/* '<S36>/Enabled Subsystem' */
  DW_MeasurementUpdate_HW6_v1_T MeasurementUpdate;/* '<S29>/MeasurementUpdate' */
} DW_HW6_v1_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator11_CSTATE;          /* '<S1>/Integrator11' */
  real_T Integrator5_CSTATE;           /* '<S1>/Integrator5' */
  real_T Integrator6_CSTATE;           /* '<S1>/Integrator6' */
  real_T Integrator7_CSTATE;           /* '<S1>/Integrator7' */
  real_T Integrator8_CSTATE;           /* '<S1>/Integrator8' */
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator3_CSTATE;           /* '<S1>/Integrator3' */
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<S1>/Integrator2' */
  real_T Integrator4_CSTATE;           /* '<S1>/Integrator4' */
} X_HW6_v1_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator11_CSTATE;          /* '<S1>/Integrator11' */
  real_T Integrator5_CSTATE;           /* '<S1>/Integrator5' */
  real_T Integrator6_CSTATE;           /* '<S1>/Integrator6' */
  real_T Integrator7_CSTATE;           /* '<S1>/Integrator7' */
  real_T Integrator8_CSTATE;           /* '<S1>/Integrator8' */
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator3_CSTATE;           /* '<S1>/Integrator3' */
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<S1>/Integrator2' */
  real_T Integrator4_CSTATE;           /* '<S1>/Integrator4' */
} XDot_HW6_v1_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator11_CSTATE;       /* '<S1>/Integrator11' */
  boolean_T Integrator5_CSTATE;        /* '<S1>/Integrator5' */
  boolean_T Integrator6_CSTATE;        /* '<S1>/Integrator6' */
  boolean_T Integrator7_CSTATE;        /* '<S1>/Integrator7' */
  boolean_T Integrator8_CSTATE;        /* '<S1>/Integrator8' */
  boolean_T Integrator1_CSTATE;        /* '<S1>/Integrator1' */
  boolean_T Integrator3_CSTATE;        /* '<S1>/Integrator3' */
  boolean_T Integrator_CSTATE;         /* '<S1>/Integrator' */
  boolean_T Integrator2_CSTATE;        /* '<S1>/Integrator2' */
  boolean_T Integrator4_CSTATE;        /* '<S1>/Integrator4' */
} XDis_HW6_v1_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Motors[4];                  /* '<Root>/Motors' */
  uint8_T Flag;                        /* '<Root>/Flag' */
} ExtY_HW6_v1_T;

/* Parameters for system: '<S29>/MeasurementUpdate' */
struct P_MeasurementUpdate_HW6_v1_T_ {
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S58>/L*(y[k]-yhat[k|k-1])'
                                        */
};

/* Parameters for system: '<S36>/Enabled Subsystem' */
struct P_EnabledSubsystem_HW6_v1_T_ {
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S60>/deltax'
                                        */
};

/* Parameters (default storage) */
struct P_HW6_v1_T_ {
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S266>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S268>/deltax'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Integrator11_IC;              /* Expression: 0
                                        * Referenced by: '<S1>/Integrator11'
                                        */
  real_T Integrator5_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator5'
                                        */
  real_T Integrator6_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator6'
                                        */
  real_T Integrator7_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator7'
                                        */
  real_T Constant6_Value;              /* Expression: -9.4351
                                        * Referenced by: '<S1>/Constant6'
                                        */
  real_T Integrator8_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator8'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator3'
                                        */
  real_T KalmanGainM_Value[2];         /* Expression: pInitialization.M
                                        * Referenced by: '<S217>/KalmanGainM'
                                        */
  real_T C_Value[2];                   /* Expression: pInitialization.C
                                        * Referenced by: '<S8>/C'
                                        */
  real_T X0_Value[2];                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S8>/X0'
                                        */
  real_T KalmanGainM_Value_c;          /* Expression: pInitialization.M
                                        * Referenced by: '<S113>/KalmanGainM'
                                        */
  real_T C_Value_a;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S6>/C'
                                        */
  real_T X0_Value_h;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S6>/X0'
                                        */
  real_T KalmanGainM_Value_i;          /* Expression: pInitialization.M
                                        * Referenced by: '<S165>/KalmanGainM'
                                        */
  real_T C_Value_d;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S7>/C'
                                        */
  real_T X0_Value_l;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S7>/X0'
                                        */
  real_T KalmanGainM_Value_a;          /* Expression: pInitialization.M
                                        * Referenced by: '<S9>/KalmanGainM'
                                        */
  real_T C_Value_ag;                   /* Expression: pInitialization.C
                                        * Referenced by: '<S4>/C'
                                        */
  real_T Constant1_Value;              /* Expression: -9.81
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T X0_Value_g;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S4>/X0'
                                        */
  real_T KalmanGainM_Value_j;          /* Expression: pInitialization.M
                                        * Referenced by: '<S61>/KalmanGainM'
                                        */
  real_T C_Value_h;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S5>/C'
                                        */
  real_T Constant_Value_n;             /* Expression: 9.81
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T X0_Value_p;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S5>/X0'
                                        */
  real_T Constant6_Value_e;            /* Expression: -9.4351
                                        * Referenced by: '<S2>/Constant6'
                                        */
  real_T A_Value[4];                   /* Expression: pInitialization.A
                                        * Referenced by: '<S8>/A'
                                        */
  real_T B_Value[2];                   /* Expression: pInitialization.B
                                        * Referenced by: '<S8>/B'
                                        */
  real_T KalmanGainL_Value[2];         /* Expression: pInitialization.L
                                        * Referenced by: '<S217>/KalmanGainL'
                                        */
  real_T D_Value;                      /* Expression: pInitialization.D
                                        * Referenced by: '<S8>/D'
                                        */
  real_T A_Value_k;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S5>/A'
                                        */
  real_T B_Value_h;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S5>/B'
                                        */
  real_T KalmanGainL_Value_b;          /* Expression: pInitialization.L
                                        * Referenced by: '<S61>/KalmanGainL'
                                        */
  real_T D_Value_i;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S5>/D'
                                        */
  real_T A_Value_m;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S6>/A'
                                        */
  real_T B_Value_g;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S6>/B'
                                        */
  real_T KalmanGainL_Value_j;          /* Expression: pInitialization.L
                                        * Referenced by: '<S113>/KalmanGainL'
                                        */
  real_T D_Value_h;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S6>/D'
                                        */
  real_T A_Value_e;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S4>/A'
                                        */
  real_T B_Value_o;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S4>/B'
                                        */
  real_T KalmanGainL_Value_m;          /* Expression: pInitialization.L
                                        * Referenced by: '<S9>/KalmanGainL'
                                        */
  real_T D_Value_a;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S4>/D'
                                        */
  real_T A_Value_mn;                   /* Expression: pInitialization.A
                                        * Referenced by: '<S7>/A'
                                        */
  real_T B_Value_p;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S7>/B'
                                        */
  real_T KalmanGainL_Value_g;          /* Expression: pInitialization.L
                                        * Referenced by: '<S165>/KalmanGainL'
                                        */
  real_T D_Value_e;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S7>/D'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator2'
                                        */
  real_T Integrator4_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator4'
                                        */
  real32_T Saturation1_UpperSat;     /* Computed Parameter: Saturation1_UpperSat
                                      * Referenced by: '<S1>/Saturation1'
                                      */
  real32_T Saturation1_LowerSat;     /* Computed Parameter: Saturation1_LowerSat
                                      * Referenced by: '<S1>/Saturation1'
                                      */
  boolean_T Enable_Value;              /* Expression: true()
                                        * Referenced by: '<S8>/Enable'
                                        */
  boolean_T Enable_Value_g;            /* Expression: true()
                                        * Referenced by: '<S6>/Enable'
                                        */
  boolean_T Enable_Value_m;            /* Expression: true()
                                        * Referenced by: '<S7>/Enable'
                                        */
  boolean_T Enable_Value_i;            /* Expression: true()
                                        * Referenced by: '<S4>/Enable'
                                        */
  boolean_T Enable_Value_ir;           /* Expression: true()
                                        * Referenced by: '<S5>/Enable'
                                        */
  uint8_T Constant1_Value_d;           /* Computed Parameter: Constant1_Value_d
                                        * Referenced by: '<S1>/Constant1'
                                        */
  uint8_T Constant2_Value;             /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S1>/Constant2'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S1>/Manual Switch'
                               */
  P_EnabledSubsystem_HW6_v1_T EnabledSubsystem_f;/* '<S192>/Enabled Subsystem' */
  P_MeasurementUpdate_HW6_v1_T MeasurementUpdate_f;/* '<S185>/MeasurementUpdate' */
  P_EnabledSubsystem_HW6_v1_T EnabledSubsystem_d;/* '<S140>/Enabled Subsystem' */
  P_MeasurementUpdate_HW6_v1_T MeasurementUpdate_h;/* '<S133>/MeasurementUpdate' */
  P_EnabledSubsystem_HW6_v1_T EnabledSubsystem_e;/* '<S88>/Enabled Subsystem' */
  P_MeasurementUpdate_HW6_v1_T MeasurementUpdate_o;/* '<S81>/MeasurementUpdate' */
  P_EnabledSubsystem_HW6_v1_T EnabledSubsystem;/* '<S36>/Enabled Subsystem' */
  P_MeasurementUpdate_HW6_v1_T MeasurementUpdate;/* '<S29>/MeasurementUpdate' */
};

/* Real-time Model Data Structure */
struct tag_RTM_HW6_v1_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_HW6_v1_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[10];
  real_T odeF[3][10];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_HW6_v1_T HW6_v1_P;

/* Block signals (default storage) */
extern B_HW6_v1_T HW6_v1_B;

/* Continuous states (default storage) */
extern X_HW6_v1_T HW6_v1_X;

/* Block states (default storage) */
extern DW_HW6_v1_T HW6_v1_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_HW6_v1_T HW6_v1_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern CommandBus cmd_inport;          /* '<Root>/AC cmd' */
extern SensorsBus sensor_inport;       /* '<Root>/Sensors' */
extern real32_T motors_outport[4];     /* '<S1>/Saturation1' */
extern uint8_T flag_outport;           /* '<S1>/Manual Switch' */

/* Model entry point functions */
extern void HW6_v1_initialize(void);
extern void HW6_v1_step(void);
extern void HW6_v1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_HW6_v1_T *const HW6_v1_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S9>/CovarianceZ' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Conversion' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Conversion' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Conversion' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/G' : Unused code path elimination
 * Block '<S4>/H' : Unused code path elimination
 * Block '<S4>/N' : Unused code path elimination
 * Block '<S4>/P0' : Unused code path elimination
 * Block '<S4>/Q' : Unused code path elimination
 * Block '<S4>/R' : Unused code path elimination
 * Block '<S50>/CheckSignalProperties' : Unused code path elimination
 * Block '<S51>/CheckSignalProperties' : Unused code path elimination
 * Block '<S61>/CovarianceZ' : Unused code path elimination
 * Block '<S104>/Data Type Duplicate' : Unused code path elimination
 * Block '<S105>/Data Type Duplicate' : Unused code path elimination
 * Block '<S106>/Conversion' : Unused code path elimination
 * Block '<S106>/Data Type Duplicate' : Unused code path elimination
 * Block '<S107>/Conversion' : Unused code path elimination
 * Block '<S107>/Data Type Duplicate' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate' : Unused code path elimination
 * Block '<S67>/Data Type Duplicate' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Conversion' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate' : Unused code path elimination
 * Block '<S77>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/G' : Unused code path elimination
 * Block '<S5>/H' : Unused code path elimination
 * Block '<S5>/N' : Unused code path elimination
 * Block '<S5>/P0' : Unused code path elimination
 * Block '<S5>/Q' : Unused code path elimination
 * Block '<S5>/R' : Unused code path elimination
 * Block '<S102>/CheckSignalProperties' : Unused code path elimination
 * Block '<S103>/CheckSignalProperties' : Unused code path elimination
 * Block '<S113>/CovarianceZ' : Unused code path elimination
 * Block '<S156>/Data Type Duplicate' : Unused code path elimination
 * Block '<S157>/Data Type Duplicate' : Unused code path elimination
 * Block '<S158>/Conversion' : Unused code path elimination
 * Block '<S158>/Data Type Duplicate' : Unused code path elimination
 * Block '<S159>/Conversion' : Unused code path elimination
 * Block '<S159>/Data Type Duplicate' : Unused code path elimination
 * Block '<S116>/Data Type Duplicate' : Unused code path elimination
 * Block '<S117>/Data Type Duplicate' : Unused code path elimination
 * Block '<S118>/Data Type Duplicate' : Unused code path elimination
 * Block '<S119>/Data Type Duplicate' : Unused code path elimination
 * Block '<S121>/Data Type Duplicate' : Unused code path elimination
 * Block '<S122>/Data Type Duplicate' : Unused code path elimination
 * Block '<S123>/Data Type Duplicate' : Unused code path elimination
 * Block '<S124>/Conversion' : Unused code path elimination
 * Block '<S124>/Data Type Duplicate' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate' : Unused code path elimination
 * Block '<S127>/Data Type Duplicate' : Unused code path elimination
 * Block '<S129>/Data Type Duplicate' : Unused code path elimination
 * Block '<S130>/Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/G' : Unused code path elimination
 * Block '<S6>/H' : Unused code path elimination
 * Block '<S6>/N' : Unused code path elimination
 * Block '<S6>/P0' : Unused code path elimination
 * Block '<S6>/Q' : Unused code path elimination
 * Block '<S6>/R' : Unused code path elimination
 * Block '<S154>/CheckSignalProperties' : Unused code path elimination
 * Block '<S155>/CheckSignalProperties' : Unused code path elimination
 * Block '<S165>/CovarianceZ' : Unused code path elimination
 * Block '<S208>/Data Type Duplicate' : Unused code path elimination
 * Block '<S209>/Data Type Duplicate' : Unused code path elimination
 * Block '<S210>/Conversion' : Unused code path elimination
 * Block '<S210>/Data Type Duplicate' : Unused code path elimination
 * Block '<S211>/Conversion' : Unused code path elimination
 * Block '<S211>/Data Type Duplicate' : Unused code path elimination
 * Block '<S168>/Data Type Duplicate' : Unused code path elimination
 * Block '<S169>/Data Type Duplicate' : Unused code path elimination
 * Block '<S170>/Data Type Duplicate' : Unused code path elimination
 * Block '<S171>/Data Type Duplicate' : Unused code path elimination
 * Block '<S173>/Data Type Duplicate' : Unused code path elimination
 * Block '<S174>/Data Type Duplicate' : Unused code path elimination
 * Block '<S175>/Data Type Duplicate' : Unused code path elimination
 * Block '<S176>/Conversion' : Unused code path elimination
 * Block '<S176>/Data Type Duplicate' : Unused code path elimination
 * Block '<S177>/Data Type Duplicate' : Unused code path elimination
 * Block '<S178>/Data Type Duplicate' : Unused code path elimination
 * Block '<S179>/Data Type Duplicate' : Unused code path elimination
 * Block '<S181>/Data Type Duplicate' : Unused code path elimination
 * Block '<S182>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/G' : Unused code path elimination
 * Block '<S7>/H' : Unused code path elimination
 * Block '<S7>/N' : Unused code path elimination
 * Block '<S7>/P0' : Unused code path elimination
 * Block '<S7>/Q' : Unused code path elimination
 * Block '<S7>/R' : Unused code path elimination
 * Block '<S206>/CheckSignalProperties' : Unused code path elimination
 * Block '<S207>/CheckSignalProperties' : Unused code path elimination
 * Block '<S217>/CovarianceZ' : Unused code path elimination
 * Block '<S260>/Data Type Duplicate' : Unused code path elimination
 * Block '<S261>/Data Type Duplicate' : Unused code path elimination
 * Block '<S262>/Conversion' : Unused code path elimination
 * Block '<S262>/Data Type Duplicate' : Unused code path elimination
 * Block '<S263>/Conversion' : Unused code path elimination
 * Block '<S263>/Data Type Duplicate' : Unused code path elimination
 * Block '<S220>/Data Type Duplicate' : Unused code path elimination
 * Block '<S221>/Data Type Duplicate' : Unused code path elimination
 * Block '<S222>/Data Type Duplicate' : Unused code path elimination
 * Block '<S223>/Data Type Duplicate' : Unused code path elimination
 * Block '<S225>/Data Type Duplicate' : Unused code path elimination
 * Block '<S226>/Data Type Duplicate' : Unused code path elimination
 * Block '<S227>/Data Type Duplicate' : Unused code path elimination
 * Block '<S228>/Conversion' : Unused code path elimination
 * Block '<S228>/Data Type Duplicate' : Unused code path elimination
 * Block '<S229>/Data Type Duplicate' : Unused code path elimination
 * Block '<S230>/Data Type Duplicate' : Unused code path elimination
 * Block '<S231>/Data Type Duplicate' : Unused code path elimination
 * Block '<S233>/Data Type Duplicate' : Unused code path elimination
 * Block '<S234>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/G' : Unused code path elimination
 * Block '<S8>/H' : Unused code path elimination
 * Block '<S8>/N' : Unused code path elimination
 * Block '<S8>/P0' : Unused code path elimination
 * Block '<S8>/Q' : Unused code path elimination
 * Block '<S8>/R' : Unused code path elimination
 * Block '<S258>/CheckSignalProperties' : Unused code path elimination
 * Block '<S259>/CheckSignalProperties' : Unused code path elimination
 * Block '<S2>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition10' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition11' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition12' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition13' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition5' : Eliminated since input and output rates are identical
 * Block '<S52>/Conversion' : Eliminate redundant data type conversion
 * Block '<S53>/Conversion' : Eliminate redundant data type conversion
 * Block '<S25>/Conversion' : Eliminate redundant data type conversion
 * Block '<S29>/Reshape' : Reshape block reduction
 * Block '<S4>/ReshapeX0' : Reshape block reduction
 * Block '<S4>/Reshapexhat' : Reshape block reduction
 * Block '<S104>/Conversion' : Eliminate redundant data type conversion
 * Block '<S105>/Conversion' : Eliminate redundant data type conversion
 * Block '<S77>/Conversion' : Eliminate redundant data type conversion
 * Block '<S81>/Reshape' : Reshape block reduction
 * Block '<S5>/ReshapeX0' : Reshape block reduction
 * Block '<S5>/Reshapexhat' : Reshape block reduction
 * Block '<S156>/Conversion' : Eliminate redundant data type conversion
 * Block '<S157>/Conversion' : Eliminate redundant data type conversion
 * Block '<S129>/Conversion' : Eliminate redundant data type conversion
 * Block '<S133>/Reshape' : Reshape block reduction
 * Block '<S6>/ReshapeX0' : Reshape block reduction
 * Block '<S6>/Reshapexhat' : Reshape block reduction
 * Block '<S208>/Conversion' : Eliminate redundant data type conversion
 * Block '<S209>/Conversion' : Eliminate redundant data type conversion
 * Block '<S181>/Conversion' : Eliminate redundant data type conversion
 * Block '<S185>/Reshape' : Reshape block reduction
 * Block '<S7>/ReshapeX0' : Reshape block reduction
 * Block '<S7>/Reshapexhat' : Reshape block reduction
 * Block '<S260>/Conversion' : Eliminate redundant data type conversion
 * Block '<S261>/Conversion' : Eliminate redundant data type conversion
 * Block '<S233>/Conversion' : Eliminate redundant data type conversion
 * Block '<S237>/Reshape' : Reshape block reduction
 * Block '<S8>/ReshapeX0' : Reshape block reduction
 * Block '<S8>/Reshapexhat' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'HW6_v1'
 * '<S1>'   : 'HW6_v1/Flight_Control_System'
 * '<S2>'   : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters'
 * '<S3>'   : 'HW6_v1/Flight_Control_System/Subsystem'
 * '<S4>'   : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1'
 * '<S5>'   : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1'
 * '<S6>'   : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter'
 * '<S7>'   : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter'
 * '<S8>'   : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter'
 * '<S9>'   : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/CalculatePL'
 * '<S10>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/CalculateYhat'
 * '<S11>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/CovarianceOutputConfigurator'
 * '<S12>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionA'
 * '<S13>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionB'
 * '<S14>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionC'
 * '<S15>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionD'
 * '<S16>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionEnable'
 * '<S17>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionG'
 * '<S18>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionH'
 * '<S19>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionN'
 * '<S20>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionP'
 * '<S21>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionP0'
 * '<S22>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionQ'
 * '<S23>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionR'
 * '<S24>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionReset'
 * '<S25>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionX'
 * '<S26>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionX0'
 * '<S27>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionu'
 * '<S28>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/MemoryP'
 * '<S29>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/Observer'
 * '<S30>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/ReducedQRN'
 * '<S31>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/Reset'
 * '<S32>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/Reshapeyhat'
 * '<S33>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/ScalarExpansionP0'
 * '<S34>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/ScalarExpansionQ'
 * '<S35>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/ScalarExpansionR'
 * '<S36>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/UseCurrentEstimator'
 * '<S37>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/checkA'
 * '<S38>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/checkB'
 * '<S39>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/checkC'
 * '<S40>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/checkD'
 * '<S41>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/checkEnable'
 * '<S42>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/checkG'
 * '<S43>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/checkH'
 * '<S44>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/checkN'
 * '<S45>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/checkP0'
 * '<S46>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/checkQ'
 * '<S47>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/checkR'
 * '<S48>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/checkReset'
 * '<S49>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/checkX0'
 * '<S50>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/checku'
 * '<S51>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/checky'
 * '<S52>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/CalculatePL/DataTypeConversionL'
 * '<S53>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/CalculatePL/DataTypeConversionM'
 * '<S54>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/CalculatePL/DataTypeConversionP'
 * '<S55>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/CalculatePL/DataTypeConversionZ'
 * '<S56>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/CalculatePL/Ground'
 * '<S57>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/CalculateYhat/Ground'
 * '<S58>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/Observer/MeasurementUpdate'
 * '<S59>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/ReducedQRN/Ground'
 * '<S60>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/phi Kalman filter1/UseCurrentEstimator/Enabled Subsystem'
 * '<S61>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/CalculatePL'
 * '<S62>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/CalculateYhat'
 * '<S63>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/CovarianceOutputConfigurator'
 * '<S64>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionA'
 * '<S65>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionB'
 * '<S66>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionC'
 * '<S67>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionD'
 * '<S68>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionEnable'
 * '<S69>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionG'
 * '<S70>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionH'
 * '<S71>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionN'
 * '<S72>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionP'
 * '<S73>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionP0'
 * '<S74>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionQ'
 * '<S75>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionR'
 * '<S76>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionReset'
 * '<S77>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionX'
 * '<S78>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionX0'
 * '<S79>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionu'
 * '<S80>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/MemoryP'
 * '<S81>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/Observer'
 * '<S82>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/ReducedQRN'
 * '<S83>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/Reset'
 * '<S84>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/Reshapeyhat'
 * '<S85>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/ScalarExpansionP0'
 * '<S86>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/ScalarExpansionQ'
 * '<S87>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/ScalarExpansionR'
 * '<S88>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/UseCurrentEstimator'
 * '<S89>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/checkA'
 * '<S90>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/checkB'
 * '<S91>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/checkC'
 * '<S92>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/checkD'
 * '<S93>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/checkEnable'
 * '<S94>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/checkG'
 * '<S95>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/checkH'
 * '<S96>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/checkN'
 * '<S97>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/checkP0'
 * '<S98>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/checkQ'
 * '<S99>'  : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/checkR'
 * '<S100>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/checkReset'
 * '<S101>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/checkX0'
 * '<S102>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/checku'
 * '<S103>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/checky'
 * '<S104>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/CalculatePL/DataTypeConversionL'
 * '<S105>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/CalculatePL/DataTypeConversionM'
 * '<S106>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/CalculatePL/DataTypeConversionP'
 * '<S107>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/CalculatePL/DataTypeConversionZ'
 * '<S108>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/CalculatePL/Ground'
 * '<S109>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/CalculateYhat/Ground'
 * '<S110>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/Observer/MeasurementUpdate'
 * '<S111>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/ReducedQRN/Ground'
 * '<S112>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/theta Kalman filter1/UseCurrentEstimator/Enabled Subsystem'
 * '<S113>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/CalculatePL'
 * '<S114>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/CalculateYhat'
 * '<S115>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/CovarianceOutputConfigurator'
 * '<S116>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionA'
 * '<S117>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionB'
 * '<S118>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionC'
 * '<S119>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionD'
 * '<S120>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionEnable'
 * '<S121>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionG'
 * '<S122>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionH'
 * '<S123>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionN'
 * '<S124>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionP'
 * '<S125>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionP0'
 * '<S126>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionQ'
 * '<S127>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionR'
 * '<S128>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionReset'
 * '<S129>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionX'
 * '<S130>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionX0'
 * '<S131>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionu'
 * '<S132>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/MemoryP'
 * '<S133>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/Observer'
 * '<S134>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/ReducedQRN'
 * '<S135>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/Reset'
 * '<S136>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/Reshapeyhat'
 * '<S137>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/ScalarExpansionP0'
 * '<S138>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/ScalarExpansionQ'
 * '<S139>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/ScalarExpansionR'
 * '<S140>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/UseCurrentEstimator'
 * '<S141>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/checkA'
 * '<S142>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/checkB'
 * '<S143>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/checkC'
 * '<S144>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/checkD'
 * '<S145>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/checkEnable'
 * '<S146>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/checkG'
 * '<S147>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/checkH'
 * '<S148>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/checkN'
 * '<S149>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/checkP0'
 * '<S150>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/checkQ'
 * '<S151>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/checkR'
 * '<S152>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/checkReset'
 * '<S153>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/checkX0'
 * '<S154>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/checku'
 * '<S155>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/checky'
 * '<S156>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S157>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S158>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S159>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S160>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/CalculatePL/Ground'
 * '<S161>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/CalculateYhat/Ground'
 * '<S162>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/Observer/MeasurementUpdate'
 * '<S163>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/ReducedQRN/Ground'
 * '<S164>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/u Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S165>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/CalculatePL'
 * '<S166>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/CalculateYhat'
 * '<S167>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/CovarianceOutputConfigurator'
 * '<S168>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionA'
 * '<S169>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionB'
 * '<S170>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionC'
 * '<S171>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionD'
 * '<S172>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionEnable'
 * '<S173>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionG'
 * '<S174>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionH'
 * '<S175>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionN'
 * '<S176>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionP'
 * '<S177>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionP0'
 * '<S178>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionQ'
 * '<S179>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionR'
 * '<S180>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionReset'
 * '<S181>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionX'
 * '<S182>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionX0'
 * '<S183>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionu'
 * '<S184>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/MemoryP'
 * '<S185>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/Observer'
 * '<S186>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/ReducedQRN'
 * '<S187>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/Reset'
 * '<S188>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/Reshapeyhat'
 * '<S189>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/ScalarExpansionP0'
 * '<S190>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/ScalarExpansionQ'
 * '<S191>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/ScalarExpansionR'
 * '<S192>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/UseCurrentEstimator'
 * '<S193>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/checkA'
 * '<S194>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/checkB'
 * '<S195>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/checkC'
 * '<S196>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/checkD'
 * '<S197>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/checkEnable'
 * '<S198>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/checkG'
 * '<S199>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/checkH'
 * '<S200>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/checkN'
 * '<S201>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/checkP0'
 * '<S202>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/checkQ'
 * '<S203>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/checkR'
 * '<S204>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/checkReset'
 * '<S205>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/checkX0'
 * '<S206>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/checku'
 * '<S207>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/checky'
 * '<S208>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/CalculatePL/DataTypeConversionL'
 * '<S209>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/CalculatePL/DataTypeConversionM'
 * '<S210>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/CalculatePL/DataTypeConversionP'
 * '<S211>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/CalculatePL/DataTypeConversionZ'
 * '<S212>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/CalculatePL/Ground'
 * '<S213>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/CalculateYhat/Ground'
 * '<S214>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/Observer/MeasurementUpdate'
 * '<S215>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/ReducedQRN/Ground'
 * '<S216>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/v Kalman filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S217>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/CalculatePL'
 * '<S218>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/CalculateYhat'
 * '<S219>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/CovarianceOutputConfigurator'
 * '<S220>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionA'
 * '<S221>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionB'
 * '<S222>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionC'
 * '<S223>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionD'
 * '<S224>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionEnable'
 * '<S225>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionG'
 * '<S226>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionH'
 * '<S227>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionN'
 * '<S228>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionP'
 * '<S229>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionP0'
 * '<S230>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionQ'
 * '<S231>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionR'
 * '<S232>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionReset'
 * '<S233>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionX'
 * '<S234>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionX0'
 * '<S235>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionu'
 * '<S236>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/MemoryP'
 * '<S237>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/Observer'
 * '<S238>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/ReducedQRN'
 * '<S239>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/Reset'
 * '<S240>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/Reshapeyhat'
 * '<S241>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/ScalarExpansionP0'
 * '<S242>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/ScalarExpansionQ'
 * '<S243>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/ScalarExpansionR'
 * '<S244>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/UseCurrentEstimator'
 * '<S245>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/checkA'
 * '<S246>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/checkB'
 * '<S247>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/checkC'
 * '<S248>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/checkD'
 * '<S249>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/checkEnable'
 * '<S250>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/checkG'
 * '<S251>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/checkH'
 * '<S252>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/checkN'
 * '<S253>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/checkP0'
 * '<S254>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/checkQ'
 * '<S255>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/checkR'
 * '<S256>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/checkReset'
 * '<S257>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/checkX0'
 * '<S258>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/checku'
 * '<S259>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/checky'
 * '<S260>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S261>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S262>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S263>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S264>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/CalculatePL/Ground'
 * '<S265>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/CalculateYhat/Ground'
 * '<S266>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/Observer/MeasurementUpdate'
 * '<S267>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/ReducedQRN/Ground'
 * '<S268>' : 'HW6_v1/Flight_Control_System/Clay's Kalman Filters/zw Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 */
#endif                                 /* RTW_HEADER_HW6_v1_h_ */

/*
 * HW6_Simulink.h
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

#ifndef RTW_HEADER_HW6_Simulink_h_
#define RTW_HEADER_HW6_Simulink_h_
#include <stddef.h>
#include <string.h>
#include <float.h>
#include <math.h>
#ifndef HW6_Simulink_COMMON_INCLUDES_
# define HW6_Simulink_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* HW6_Simulink_COMMON_INCLUDES_ */

#include "HW6_Simulink_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "rt_matrixlib.h"

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

#ifndef rtmGetOdeDELTA
# define rtmGetOdeDELTA(rtm)           ((rtm)->odeDELTA)
#endif

#ifndef rtmSetOdeDELTA
# define rtmSetOdeDELTA(rtm, val)      ((rtm)->odeDELTA = (val))
#endif

#ifndef rtmGetOdeDFDX
# define rtmGetOdeDFDX(rtm)            ((rtm)->odeDFDX)
#endif

#ifndef rtmSetOdeDFDX
# define rtmSetOdeDFDX(rtm, val)       ((rtm)->odeDFDX = (val))
#endif

#ifndef rtmGetOdeE
# define rtmGetOdeE(rtm)               ((rtm)->odeE)
#endif

#ifndef rtmSetOdeE
# define rtmSetOdeE(rtm, val)          ((rtm)->odeE = (val))
#endif

#ifndef rtmGetOdeF0
# define rtmGetOdeF0(rtm)              ((rtm)->odeF0)
#endif

#ifndef rtmSetOdeF0
# define rtmSetOdeF0(rtm, val)         ((rtm)->odeF0 = (val))
#endif

#ifndef rtmGetOdeF1
# define rtmGetOdeF1(rtm)              ((rtm)->odeF1)
#endif

#ifndef rtmSetOdeF1
# define rtmSetOdeF1(rtm, val)         ((rtm)->odeF1 = (val))
#endif

#ifndef rtmGetOdeFAC
# define rtmGetOdeFAC(rtm)             ((rtm)->odeFAC)
#endif

#ifndef rtmSetOdeFAC
# define rtmSetOdeFAC(rtm, val)        ((rtm)->odeFAC = (val))
#endif

#ifndef rtmGetOdePIVOTS
# define rtmGetOdePIVOTS(rtm)          ((rtm)->odePIVOTS)
#endif

#ifndef rtmSetOdePIVOTS
# define rtmSetOdePIVOTS(rtm, val)     ((rtm)->odePIVOTS = (val))
#endif

#ifndef rtmGetOdeW
# define rtmGetOdeW(rtm)               ((rtm)->odeW)
#endif

#ifndef rtmSetOdeW
# define rtmSetOdeW(rtm, val)          ((rtm)->odeW = (val))
#endif

#ifndef rtmGetOdeX0
# define rtmGetOdeX0(rtm)              ((rtm)->odeX0)
#endif

#ifndef rtmSetOdeX0
# define rtmSetOdeX0(rtm, val)         ((rtm)->odeX0 = (val))
#endif

#ifndef rtmGetOdeX1START
# define rtmGetOdeX1START(rtm)         ((rtm)->odeX1START)
#endif

#ifndef rtmSetOdeX1START
# define rtmSetOdeX1START(rtm, val)    ((rtm)->odeX1START = (val))
#endif

#ifndef rtmGetOdeXTMP
# define rtmGetOdeXTMP(rtm)            ((rtm)->odeXTMP)
#endif

#ifndef rtmSetOdeXTMP
# define rtmSetOdeXTMP(rtm, val)       ((rtm)->odeXTMP = (val))
#endif

#ifndef rtmGetOdeZTMP
# define rtmGetOdeZTMP(rtm)            ((rtm)->odeZTMP)
#endif

#ifndef rtmSetOdeZTMP
# define rtmSetOdeZTMP(rtm, val)       ((rtm)->odeZTMP = (val))
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

/* Block signals for system '<S28>/MeasurementUpdate' */
typedef struct {
  real_T Product3;                     /* '<S57>/Product3' */
} B_MeasurementUpdate_HW6_Simul_T;

/* Block states (default storage) for system '<S28>/MeasurementUpdate' */
typedef struct {
  boolean_T MeasurementUpdate_MODE;    /* '<S28>/MeasurementUpdate' */
} DW_MeasurementUpdate_HW6_Simu_T;

/* Block signals for system '<S35>/Enabled Subsystem' */
typedef struct {
  real_T Product2;                     /* '<S59>/Product2' */
} B_EnabledSubsystem_HW6_Simuli_T;

/* Block states (default storage) for system '<S35>/Enabled Subsystem' */
typedef struct {
  boolean_T EnabledSubsystem_MODE;     /* '<S35>/Enabled Subsystem' */
} DW_EnabledSubsystem_HW6_Simul_T;

/* Block signals (default storage) */
typedef struct {
  real_T TmpSignalConversionAtToWork[17];
  real_T Akxhatkk1[2];                 /* '<S236>/A[k]*xhat[k|k-1]' */
  real_T Add_f[2];                     /* '<S236>/Add' */
  real_T Xned;                         /* '<S1>/Integrator1' */
  real_T Yned;                         /* '<S1>/Integrator3' */
  real_T RateLimiter;                  /* '<S1>/Rate Limiter' */
  real_T DataTypeConversion3;          /* '<S1>/Data Type Conversion3' */
  real_T DataTypeConversion4;          /* '<S1>/Data Type Conversion4' */
  real_T DataTypeConversion5;          /* '<S1>/Data Type Conversion5' */
  real_T DataTypeConversion;           /* '<S1>/Data Type Conversion' */
  real_T DataTypeConversion1;          /* '<S1>/Data Type Conversion1' */
  real_T DataTypeConversion2;          /* '<S1>/Data Type Conversion2' */
  real_T Sum1;                         /* '<S1>/Sum1' */
  real_T phi;                          /* '<S1>/Integrator6' */
  real_T theta;                        /* '<S1>/Integrator7' */
  real_T psi;                          /* '<S1>/Integrator8' */
  real_T DataTypeConversion6;          /* '<S1>/Data Type Conversion6' */
  real_T DataTypeConversion7;          /* '<S1>/Data Type Conversion7' */
  real_T Integrator11;                 /* '<S1>/Integrator11' */
  real_T Yned_d;                       /* '<S1>/Integrator5' */
  real_T phi_p;                        /* '<S1>/Divide' */
  real_T theta_o;                      /* '<S1>/Divide1' */
  real_T Integrator;                   /* '<S1>/Integrator' */
  real_T Integrator2;                  /* '<S1>/Integrator2' */
  real_T Integrator4;                  /* '<S1>/Integrator4' */
  real_T Product2[2];                  /* '<S267>/Product2' */
  real_T Product3[2];                  /* '<S265>/Product3' */
  real_T deltaT;
  real_T rateLimiterRate;
  real_T riseValLimit;
  real_T Reshapey;                     /* '<S7>/Reshapey' */
  real_T Sum;                          /* '<S265>/Sum' */
  real_T rtb_MemoryX_idx_0;
  real_T rtb_MemoryX_idx_1;
  real_T MemoryX_b;                    /* '<S2>/MemoryX' */
  B_EnabledSubsystem_HW6_Simuli_T EnabledSubsystem_af;/* '<S191>/Enabled Subsystem' */
  B_MeasurementUpdate_HW6_Simul_T MeasurementUpdate_j0;/* '<S184>/MeasurementUpdate' */
  B_EnabledSubsystem_HW6_Simuli_T EnabledSubsystem_a;/* '<S139>/Enabled Subsystem' */
  B_MeasurementUpdate_HW6_Simul_T MeasurementUpdate_p;/* '<S132>/MeasurementUpdate' */
  B_EnabledSubsystem_HW6_Simuli_T EnabledSubsystem_j;/* '<S87>/Enabled Subsystem' */
  B_MeasurementUpdate_HW6_Simul_T MeasurementUpdate_j;/* '<S80>/MeasurementUpdate' */
  B_EnabledSubsystem_HW6_Simuli_T EnabledSubsystem;/* '<S35>/Enabled Subsystem' */
  B_MeasurementUpdate_HW6_Simul_T MeasurementUpdate;/* '<S28>/MeasurementUpdate' */
} B_HW6_Simulink_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T MemoryX_DSTATE[2];            /* '<S7>/MemoryX' */
  real_T MemoryX_DSTATE_l;             /* '<S2>/MemoryX' */
  real_T MemoryX_DSTATE_f;             /* '<S3>/MemoryX' */
  real_T MemoryX_DSTATE_k;             /* '<S4>/MemoryX' */
  real_T MemoryX_DSTATE_j;             /* '<S5>/MemoryX' */
  real_T PrevYA;                       /* '<S1>/Rate Limiter' */
  real_T PrevYB;                       /* '<S1>/Rate Limiter' */
  real_T LastMajorTimeA;               /* '<S1>/Rate Limiter' */
  real_T LastMajorTimeB;               /* '<S1>/Rate Limiter' */
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S1>/To Workspace' */

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

  uint8_T icLoad;                      /* '<S7>/MemoryX' */
  uint8_T icLoad_h;                    /* '<S2>/MemoryX' */
  uint8_T icLoad_p;                    /* '<S3>/MemoryX' */
  uint8_T icLoad_f;                    /* '<S4>/MemoryX' */
  uint8_T icLoad_d;                    /* '<S5>/MemoryX' */
  boolean_T EnabledSubsystem_MODE;     /* '<S243>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S236>/MeasurementUpdate' */
  DW_EnabledSubsystem_HW6_Simul_T EnabledSubsystem_af;/* '<S191>/Enabled Subsystem' */
  DW_MeasurementUpdate_HW6_Simu_T MeasurementUpdate_j0;/* '<S184>/MeasurementUpdate' */
  DW_EnabledSubsystem_HW6_Simul_T EnabledSubsystem_a;/* '<S139>/Enabled Subsystem' */
  DW_MeasurementUpdate_HW6_Simu_T MeasurementUpdate_p;/* '<S132>/MeasurementUpdate' */
  DW_EnabledSubsystem_HW6_Simul_T EnabledSubsystem_j;/* '<S87>/Enabled Subsystem' */
  DW_MeasurementUpdate_HW6_Simu_T MeasurementUpdate_j;/* '<S80>/MeasurementUpdate' */
  DW_EnabledSubsystem_HW6_Simul_T EnabledSubsystem;/* '<S35>/Enabled Subsystem' */
  DW_MeasurementUpdate_HW6_Simu_T MeasurementUpdate;/* '<S28>/MeasurementUpdate' */
} DW_HW6_Simulink_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator3_CSTATE;           /* '<S1>/Integrator3' */
  real_T Integrator6_CSTATE;           /* '<S1>/Integrator6' */
  real_T Integrator7_CSTATE;           /* '<S1>/Integrator7' */
  real_T Integrator8_CSTATE;           /* '<S1>/Integrator8' */
  real_T Integrator11_CSTATE;          /* '<S1>/Integrator11' */
  real_T Integrator5_CSTATE;           /* '<S1>/Integrator5' */
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<S1>/Integrator2' */
  real_T Integrator4_CSTATE;           /* '<S1>/Integrator4' */
} X_HW6_Simulink_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator3_CSTATE;           /* '<S1>/Integrator3' */
  real_T Integrator6_CSTATE;           /* '<S1>/Integrator6' */
  real_T Integrator7_CSTATE;           /* '<S1>/Integrator7' */
  real_T Integrator8_CSTATE;           /* '<S1>/Integrator8' */
  real_T Integrator11_CSTATE;          /* '<S1>/Integrator11' */
  real_T Integrator5_CSTATE;           /* '<S1>/Integrator5' */
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<S1>/Integrator2' */
  real_T Integrator4_CSTATE;           /* '<S1>/Integrator4' */
} XDot_HW6_Simulink_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S1>/Integrator1' */
  boolean_T Integrator3_CSTATE;        /* '<S1>/Integrator3' */
  boolean_T Integrator6_CSTATE;        /* '<S1>/Integrator6' */
  boolean_T Integrator7_CSTATE;        /* '<S1>/Integrator7' */
  boolean_T Integrator8_CSTATE;        /* '<S1>/Integrator8' */
  boolean_T Integrator11_CSTATE;       /* '<S1>/Integrator11' */
  boolean_T Integrator5_CSTATE;        /* '<S1>/Integrator5' */
  boolean_T Integrator_CSTATE;         /* '<S1>/Integrator' */
  boolean_T Integrator2_CSTATE;        /* '<S1>/Integrator2' */
  boolean_T Integrator4_CSTATE;        /* '<S1>/Integrator4' */
} XDis_HW6_Simulink_T;

#ifndef ODE14X_INTG
#define ODE14X_INTG

/* ODE14X Integration Data */
typedef struct {
  real_T *x0;
  real_T *f0;
  real_T *x1start;
  real_T *f1;
  real_T *Delta;
  real_T *E;
  real_T *fac;
  real_T *DFDX;
  real_T *W;
  int_T *pivots;
  real_T *xtmp;
  real_T *ztmp;
  real_T *M;
  real_T *M1;
  real_T *Edot;
  real_T *xdot;
  real_T *fminusMxdot;
  boolean_T isFirstStep;
} ODE14X_IntgData;

#endif

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Motors[4];                  /* '<Root>/Motors' */
  uint8_T Flag;                        /* '<Root>/Flag' */
} ExtY_HW6_Simulink_T;

/* Parameters for system: '<S28>/MeasurementUpdate' */
struct P_MeasurementUpdate_HW6_Simul_T_ {
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S57>/L*(y[k]-yhat[k|k-1])'
                                        */
};

/* Parameters for system: '<S35>/Enabled Subsystem' */
struct P_EnabledSubsystem_HW6_Simuli_T_ {
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S59>/deltax'
                                        */
};

/* Parameters (default storage) */
struct P_HW6_Simulink_T_ {
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S265>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S267>/deltax'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator3'
                                        */
  real_T RateLimiter_RisingLim;        /* Expression: 50
                                        * Referenced by: '<S1>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim;       /* Expression: -50
                                        * Referenced by: '<S1>/Rate Limiter'
                                        */
  real_T Constant6_Value;              /* Expression: -9.4351
                                        * Referenced by: '<S1>/Constant6'
                                        */
  real_T Integrator6_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator6'
                                        */
  real_T Integrator7_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator7'
                                        */
  real_T Integrator8_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator8'
                                        */
  real_T Integrator11_IC;              /* Expression: 0
                                        * Referenced by: '<S1>/Integrator11'
                                        */
  real_T Integrator5_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator5'
                                        */
  real_T KalmanGainM_Value[2];         /* Expression: pInitialization.M
                                        * Referenced by: '<S216>/KalmanGainM'
                                        */
  real_T C_Value[2];                   /* Expression: pInitialization.C
                                        * Referenced by: '<S7>/C'
                                        */
  real_T X0_Value[2];                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S7>/X0'
                                        */
  real_T KalmanGainM_Value_e;          /* Expression: pInitialization.M
                                        * Referenced by: '<S8>/KalmanGainM'
                                        */
  real_T C_Value_k;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S2>/C'
                                        */
  real_T X0_Value_d;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S2>/X0'
                                        */
  real_T KalmanGainM_Value_m;          /* Expression: pInitialization.M
                                        * Referenced by: '<S60>/KalmanGainM'
                                        */
  real_T C_Value_m;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S3>/C'
                                        */
  real_T X0_Value_g;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S3>/X0'
                                        */
  real_T KalmanGainM_Value_n;          /* Expression: pInitialization.M
                                        * Referenced by: '<S112>/KalmanGainM'
                                        */
  real_T C_Value_g;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S4>/C'
                                        */
  real_T Constant7_Value;              /* Expression: 3
                                        * Referenced by: '<S1>/Constant7'
                                        */
  real_T X0_Value_k;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S4>/X0'
                                        */
  real_T KalmanGainM_Value_o;          /* Expression: pInitialization.M
                                        * Referenced by: '<S164>/KalmanGainM'
                                        */
  real_T C_Value_h;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S5>/C'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Constant8_Value;              /* Expression: 3
                                        * Referenced by: '<S1>/Constant8'
                                        */
  real_T X0_Value_j;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S5>/X0'
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
  real_T A_Value;                      /* Expression: pInitialization.A
                                        * Referenced by: '<S2>/A'
                                        */
  real_T B_Value;                      /* Expression: pInitialization.B
                                        * Referenced by: '<S2>/B'
                                        */
  real_T KalmanGainL_Value;            /* Expression: pInitialization.L
                                        * Referenced by: '<S8>/KalmanGainL'
                                        */
  real_T D_Value;                      /* Expression: pInitialization.D
                                        * Referenced by: '<S2>/D'
                                        */
  real_T A_Value_a;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S3>/A'
                                        */
  real_T B_Value_e;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S3>/B'
                                        */
  real_T KalmanGainL_Value_g;          /* Expression: pInitialization.L
                                        * Referenced by: '<S60>/KalmanGainL'
                                        */
  real_T D_Value_h;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S3>/D'
                                        */
  real_T A_Value_g;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S4>/A'
                                        */
  real_T B_Value_g;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S4>/B'
                                        */
  real_T KalmanGainL_Value_o;          /* Expression: pInitialization.L
                                        * Referenced by: '<S112>/KalmanGainL'
                                        */
  real_T D_Value_i;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S4>/D'
                                        */
  real_T A_Value_o;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S5>/A'
                                        */
  real_T B_Value_j;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S5>/B'
                                        */
  real_T KalmanGainL_Value_l;          /* Expression: pInitialization.L
                                        * Referenced by: '<S164>/KalmanGainL'
                                        */
  real_T D_Value_b;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S5>/D'
                                        */
  real_T A_Value_i[4];                 /* Expression: pInitialization.A
                                        * Referenced by: '<S7>/A'
                                        */
  real_T B_Value_m[2];                 /* Expression: pInitialization.B
                                        * Referenced by: '<S7>/B'
                                        */
  real_T KalmanGainL_Value_j[2];       /* Expression: pInitialization.L
                                        * Referenced by: '<S216>/KalmanGainL'
                                        */
  real_T D_Value_a;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S7>/D'
                                        */
  real32_T Saturation1_UpperSat;     /* Computed Parameter: Saturation1_UpperSat
                                      * Referenced by: '<S1>/Saturation1'
                                      */
  real32_T Saturation1_LowerSat;     /* Computed Parameter: Saturation1_LowerSat
                                      * Referenced by: '<S1>/Saturation1'
                                      */
  boolean_T Enable_Value;              /* Expression: true()
                                        * Referenced by: '<S7>/Enable'
                                        */
  boolean_T Enable_Value_l;            /* Expression: true()
                                        * Referenced by: '<S2>/Enable'
                                        */
  boolean_T Enable_Value_o;            /* Expression: true()
                                        * Referenced by: '<S3>/Enable'
                                        */
  boolean_T Enable_Value_ln;           /* Expression: true()
                                        * Referenced by: '<S4>/Enable'
                                        */
  boolean_T Enable_Value_b;            /* Expression: true()
                                        * Referenced by: '<S5>/Enable'
                                        */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S1>/Constant1'
                                        */
  uint8_T Constant2_Value;             /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S1>/Constant2'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S1>/Manual Switch'
                               */
  P_EnabledSubsystem_HW6_Simuli_T EnabledSubsystem_af;/* '<S191>/Enabled Subsystem' */
  P_MeasurementUpdate_HW6_Simul_T MeasurementUpdate_j0;/* '<S184>/MeasurementUpdate' */
  P_EnabledSubsystem_HW6_Simuli_T EnabledSubsystem_a;/* '<S139>/Enabled Subsystem' */
  P_MeasurementUpdate_HW6_Simul_T MeasurementUpdate_p;/* '<S132>/MeasurementUpdate' */
  P_EnabledSubsystem_HW6_Simuli_T EnabledSubsystem_j;/* '<S87>/Enabled Subsystem' */
  P_MeasurementUpdate_HW6_Simul_T MeasurementUpdate_j;/* '<S80>/MeasurementUpdate' */
  P_EnabledSubsystem_HW6_Simuli_T EnabledSubsystem;/* '<S35>/Enabled Subsystem' */
  P_MeasurementUpdate_HW6_Simul_T MeasurementUpdate;/* '<S28>/MeasurementUpdate' */
};

/* Real-time Model Data Structure */
struct tag_RTM_HW6_Simulink_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_HW6_Simulink_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeX0[10];
  real_T odeF0[10];
  real_T odeX1START[10];
  real_T odeF1[10];
  real_T odeDELTA[10];
  real_T odeE[4*10];
  real_T odeFAC[10];
  real_T odeDFDX[10*10];
  real_T odeW[10*10];
  int_T odePIVOTS[10];
  real_T odeXTMP[10];
  real_T odeZTMP[10];
  ODE14X_IntgData intgData;

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
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_HW6_Simulink_T HW6_Simulink_P;

/* Block signals (default storage) */
extern B_HW6_Simulink_T HW6_Simulink_B;

/* Continuous states (default storage) */
extern X_HW6_Simulink_T HW6_Simulink_X;

/* Block states (default storage) */
extern DW_HW6_Simulink_T HW6_Simulink_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_HW6_Simulink_T HW6_Simulink_Y;

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
extern void HW6_Simulink_initialize(void);
extern void HW6_Simulink_step(void);
extern void HW6_Simulink_terminate(void);

/* Real-time Model object */
extern RT_MODEL_HW6_Simulink_T *const HW6_Simulink_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/CovarianceZ' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Conversion' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Conversion' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Conversion' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/G' : Unused code path elimination
 * Block '<S2>/H' : Unused code path elimination
 * Block '<S2>/N' : Unused code path elimination
 * Block '<S2>/P0' : Unused code path elimination
 * Block '<S2>/Q' : Unused code path elimination
 * Block '<S2>/R' : Unused code path elimination
 * Block '<S49>/CheckSignalProperties' : Unused code path elimination
 * Block '<S50>/CheckSignalProperties' : Unused code path elimination
 * Block '<S60>/CovarianceZ' : Unused code path elimination
 * Block '<S103>/Data Type Duplicate' : Unused code path elimination
 * Block '<S104>/Data Type Duplicate' : Unused code path elimination
 * Block '<S105>/Conversion' : Unused code path elimination
 * Block '<S105>/Data Type Duplicate' : Unused code path elimination
 * Block '<S106>/Conversion' : Unused code path elimination
 * Block '<S106>/Data Type Duplicate' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S71>/Conversion' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S76>/Data Type Duplicate' : Unused code path elimination
 * Block '<S77>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/G' : Unused code path elimination
 * Block '<S3>/H' : Unused code path elimination
 * Block '<S3>/N' : Unused code path elimination
 * Block '<S3>/P0' : Unused code path elimination
 * Block '<S3>/Q' : Unused code path elimination
 * Block '<S3>/R' : Unused code path elimination
 * Block '<S101>/CheckSignalProperties' : Unused code path elimination
 * Block '<S102>/CheckSignalProperties' : Unused code path elimination
 * Block '<S112>/CovarianceZ' : Unused code path elimination
 * Block '<S155>/Data Type Duplicate' : Unused code path elimination
 * Block '<S156>/Data Type Duplicate' : Unused code path elimination
 * Block '<S157>/Conversion' : Unused code path elimination
 * Block '<S157>/Data Type Duplicate' : Unused code path elimination
 * Block '<S158>/Conversion' : Unused code path elimination
 * Block '<S158>/Data Type Duplicate' : Unused code path elimination
 * Block '<S115>/Data Type Duplicate' : Unused code path elimination
 * Block '<S116>/Data Type Duplicate' : Unused code path elimination
 * Block '<S117>/Data Type Duplicate' : Unused code path elimination
 * Block '<S118>/Data Type Duplicate' : Unused code path elimination
 * Block '<S120>/Data Type Duplicate' : Unused code path elimination
 * Block '<S121>/Data Type Duplicate' : Unused code path elimination
 * Block '<S122>/Data Type Duplicate' : Unused code path elimination
 * Block '<S123>/Conversion' : Unused code path elimination
 * Block '<S123>/Data Type Duplicate' : Unused code path elimination
 * Block '<S124>/Data Type Duplicate' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate' : Unused code path elimination
 * Block '<S128>/Data Type Duplicate' : Unused code path elimination
 * Block '<S129>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/G' : Unused code path elimination
 * Block '<S4>/H' : Unused code path elimination
 * Block '<S4>/N' : Unused code path elimination
 * Block '<S4>/P0' : Unused code path elimination
 * Block '<S4>/Q' : Unused code path elimination
 * Block '<S4>/R' : Unused code path elimination
 * Block '<S153>/CheckSignalProperties' : Unused code path elimination
 * Block '<S154>/CheckSignalProperties' : Unused code path elimination
 * Block '<S164>/CovarianceZ' : Unused code path elimination
 * Block '<S207>/Data Type Duplicate' : Unused code path elimination
 * Block '<S208>/Data Type Duplicate' : Unused code path elimination
 * Block '<S209>/Conversion' : Unused code path elimination
 * Block '<S209>/Data Type Duplicate' : Unused code path elimination
 * Block '<S210>/Conversion' : Unused code path elimination
 * Block '<S210>/Data Type Duplicate' : Unused code path elimination
 * Block '<S167>/Data Type Duplicate' : Unused code path elimination
 * Block '<S168>/Data Type Duplicate' : Unused code path elimination
 * Block '<S169>/Data Type Duplicate' : Unused code path elimination
 * Block '<S170>/Data Type Duplicate' : Unused code path elimination
 * Block '<S172>/Data Type Duplicate' : Unused code path elimination
 * Block '<S173>/Data Type Duplicate' : Unused code path elimination
 * Block '<S174>/Data Type Duplicate' : Unused code path elimination
 * Block '<S175>/Conversion' : Unused code path elimination
 * Block '<S175>/Data Type Duplicate' : Unused code path elimination
 * Block '<S176>/Data Type Duplicate' : Unused code path elimination
 * Block '<S177>/Data Type Duplicate' : Unused code path elimination
 * Block '<S178>/Data Type Duplicate' : Unused code path elimination
 * Block '<S180>/Data Type Duplicate' : Unused code path elimination
 * Block '<S181>/Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/G' : Unused code path elimination
 * Block '<S5>/H' : Unused code path elimination
 * Block '<S5>/N' : Unused code path elimination
 * Block '<S5>/P0' : Unused code path elimination
 * Block '<S5>/Q' : Unused code path elimination
 * Block '<S5>/R' : Unused code path elimination
 * Block '<S205>/CheckSignalProperties' : Unused code path elimination
 * Block '<S206>/CheckSignalProperties' : Unused code path elimination
 * Block '<S216>/CovarianceZ' : Unused code path elimination
 * Block '<S259>/Data Type Duplicate' : Unused code path elimination
 * Block '<S260>/Data Type Duplicate' : Unused code path elimination
 * Block '<S261>/Conversion' : Unused code path elimination
 * Block '<S261>/Data Type Duplicate' : Unused code path elimination
 * Block '<S262>/Conversion' : Unused code path elimination
 * Block '<S262>/Data Type Duplicate' : Unused code path elimination
 * Block '<S219>/Data Type Duplicate' : Unused code path elimination
 * Block '<S220>/Data Type Duplicate' : Unused code path elimination
 * Block '<S221>/Data Type Duplicate' : Unused code path elimination
 * Block '<S222>/Data Type Duplicate' : Unused code path elimination
 * Block '<S224>/Data Type Duplicate' : Unused code path elimination
 * Block '<S225>/Data Type Duplicate' : Unused code path elimination
 * Block '<S226>/Data Type Duplicate' : Unused code path elimination
 * Block '<S227>/Conversion' : Unused code path elimination
 * Block '<S227>/Data Type Duplicate' : Unused code path elimination
 * Block '<S228>/Data Type Duplicate' : Unused code path elimination
 * Block '<S229>/Data Type Duplicate' : Unused code path elimination
 * Block '<S230>/Data Type Duplicate' : Unused code path elimination
 * Block '<S232>/Data Type Duplicate' : Unused code path elimination
 * Block '<S233>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/G' : Unused code path elimination
 * Block '<S7>/H' : Unused code path elimination
 * Block '<S7>/N' : Unused code path elimination
 * Block '<S7>/P0' : Unused code path elimination
 * Block '<S7>/Q' : Unused code path elimination
 * Block '<S7>/R' : Unused code path elimination
 * Block '<S257>/CheckSignalProperties' : Unused code path elimination
 * Block '<S258>/CheckSignalProperties' : Unused code path elimination
 * Block '<S51>/Conversion' : Eliminate redundant data type conversion
 * Block '<S52>/Conversion' : Eliminate redundant data type conversion
 * Block '<S24>/Conversion' : Eliminate redundant data type conversion
 * Block '<S28>/Reshape' : Reshape block reduction
 * Block '<S2>/ReshapeX0' : Reshape block reduction
 * Block '<S2>/Reshapeu' : Reshape block reduction
 * Block '<S2>/Reshapexhat' : Reshape block reduction
 * Block '<S2>/Reshapey' : Reshape block reduction
 * Block '<S103>/Conversion' : Eliminate redundant data type conversion
 * Block '<S104>/Conversion' : Eliminate redundant data type conversion
 * Block '<S76>/Conversion' : Eliminate redundant data type conversion
 * Block '<S80>/Reshape' : Reshape block reduction
 * Block '<S3>/ReshapeX0' : Reshape block reduction
 * Block '<S3>/Reshapeu' : Reshape block reduction
 * Block '<S3>/Reshapexhat' : Reshape block reduction
 * Block '<S3>/Reshapey' : Reshape block reduction
 * Block '<S155>/Conversion' : Eliminate redundant data type conversion
 * Block '<S156>/Conversion' : Eliminate redundant data type conversion
 * Block '<S128>/Conversion' : Eliminate redundant data type conversion
 * Block '<S132>/Reshape' : Reshape block reduction
 * Block '<S4>/ReshapeX0' : Reshape block reduction
 * Block '<S4>/Reshapeu' : Reshape block reduction
 * Block '<S4>/Reshapexhat' : Reshape block reduction
 * Block '<S4>/Reshapey' : Reshape block reduction
 * Block '<S207>/Conversion' : Eliminate redundant data type conversion
 * Block '<S208>/Conversion' : Eliminate redundant data type conversion
 * Block '<S180>/Conversion' : Eliminate redundant data type conversion
 * Block '<S184>/Reshape' : Reshape block reduction
 * Block '<S5>/ReshapeX0' : Reshape block reduction
 * Block '<S5>/Reshapeu' : Reshape block reduction
 * Block '<S5>/Reshapexhat' : Reshape block reduction
 * Block '<S5>/Reshapey' : Reshape block reduction
 * Block '<S1>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition5' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition6' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition8' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition9' : Eliminated since input and output rates are identical
 * Block '<S259>/Conversion' : Eliminate redundant data type conversion
 * Block '<S260>/Conversion' : Eliminate redundant data type conversion
 * Block '<S232>/Conversion' : Eliminate redundant data type conversion
 * Block '<S236>/Reshape' : Reshape block reduction
 * Block '<S7>/ReshapeX0' : Reshape block reduction
 * Block '<S7>/Reshapexhat' : Reshape block reduction
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
 * '<Root>' : 'HW6_Simulink'
 * '<S1>'   : 'HW6_Simulink/Flight Control System'
 * '<S2>'   : 'HW6_Simulink/Flight Control System/Kalman Filter1'
 * '<S3>'   : 'HW6_Simulink/Flight Control System/Kalman Filter2'
 * '<S4>'   : 'HW6_Simulink/Flight Control System/Kalman Filter3'
 * '<S5>'   : 'HW6_Simulink/Flight Control System/Kalman Filter4'
 * '<S6>'   : 'HW6_Simulink/Flight Control System/Subsystem'
 * '<S7>'   : 'HW6_Simulink/Flight Control System/zw Kalman Filter'
 * '<S8>'   : 'HW6_Simulink/Flight Control System/Kalman Filter1/CalculatePL'
 * '<S9>'   : 'HW6_Simulink/Flight Control System/Kalman Filter1/CalculateYhat'
 * '<S10>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/CovarianceOutputConfigurator'
 * '<S11>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/DataTypeConversionA'
 * '<S12>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/DataTypeConversionB'
 * '<S13>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/DataTypeConversionC'
 * '<S14>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/DataTypeConversionD'
 * '<S15>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/DataTypeConversionEnable'
 * '<S16>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/DataTypeConversionG'
 * '<S17>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/DataTypeConversionH'
 * '<S18>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/DataTypeConversionN'
 * '<S19>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/DataTypeConversionP'
 * '<S20>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/DataTypeConversionP0'
 * '<S21>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/DataTypeConversionQ'
 * '<S22>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/DataTypeConversionR'
 * '<S23>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/DataTypeConversionReset'
 * '<S24>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/DataTypeConversionX'
 * '<S25>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/DataTypeConversionX0'
 * '<S26>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/DataTypeConversionu'
 * '<S27>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/MemoryP'
 * '<S28>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/Observer'
 * '<S29>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/ReducedQRN'
 * '<S30>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/Reset'
 * '<S31>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/Reshapeyhat'
 * '<S32>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/ScalarExpansionP0'
 * '<S33>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/ScalarExpansionQ'
 * '<S34>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/ScalarExpansionR'
 * '<S35>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/UseCurrentEstimator'
 * '<S36>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/checkA'
 * '<S37>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/checkB'
 * '<S38>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/checkC'
 * '<S39>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/checkD'
 * '<S40>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/checkEnable'
 * '<S41>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/checkG'
 * '<S42>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/checkH'
 * '<S43>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/checkN'
 * '<S44>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/checkP0'
 * '<S45>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/checkQ'
 * '<S46>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/checkR'
 * '<S47>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/checkReset'
 * '<S48>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/checkX0'
 * '<S49>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/checku'
 * '<S50>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/checky'
 * '<S51>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/CalculatePL/DataTypeConversionL'
 * '<S52>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/CalculatePL/DataTypeConversionM'
 * '<S53>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/CalculatePL/DataTypeConversionP'
 * '<S54>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/CalculatePL/DataTypeConversionZ'
 * '<S55>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/CalculatePL/Ground'
 * '<S56>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/CalculateYhat/Ground'
 * '<S57>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/Observer/MeasurementUpdate'
 * '<S58>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/ReducedQRN/Ground'
 * '<S59>'  : 'HW6_Simulink/Flight Control System/Kalman Filter1/UseCurrentEstimator/Enabled Subsystem'
 * '<S60>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/CalculatePL'
 * '<S61>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/CalculateYhat'
 * '<S62>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/CovarianceOutputConfigurator'
 * '<S63>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/DataTypeConversionA'
 * '<S64>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/DataTypeConversionB'
 * '<S65>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/DataTypeConversionC'
 * '<S66>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/DataTypeConversionD'
 * '<S67>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/DataTypeConversionEnable'
 * '<S68>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/DataTypeConversionG'
 * '<S69>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/DataTypeConversionH'
 * '<S70>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/DataTypeConversionN'
 * '<S71>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/DataTypeConversionP'
 * '<S72>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/DataTypeConversionP0'
 * '<S73>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/DataTypeConversionQ'
 * '<S74>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/DataTypeConversionR'
 * '<S75>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/DataTypeConversionReset'
 * '<S76>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/DataTypeConversionX'
 * '<S77>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/DataTypeConversionX0'
 * '<S78>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/DataTypeConversionu'
 * '<S79>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/MemoryP'
 * '<S80>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/Observer'
 * '<S81>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/ReducedQRN'
 * '<S82>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/Reset'
 * '<S83>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/Reshapeyhat'
 * '<S84>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/ScalarExpansionP0'
 * '<S85>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/ScalarExpansionQ'
 * '<S86>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/ScalarExpansionR'
 * '<S87>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/UseCurrentEstimator'
 * '<S88>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/checkA'
 * '<S89>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/checkB'
 * '<S90>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/checkC'
 * '<S91>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/checkD'
 * '<S92>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/checkEnable'
 * '<S93>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/checkG'
 * '<S94>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/checkH'
 * '<S95>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/checkN'
 * '<S96>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/checkP0'
 * '<S97>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/checkQ'
 * '<S98>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/checkR'
 * '<S99>'  : 'HW6_Simulink/Flight Control System/Kalman Filter2/checkReset'
 * '<S100>' : 'HW6_Simulink/Flight Control System/Kalman Filter2/checkX0'
 * '<S101>' : 'HW6_Simulink/Flight Control System/Kalman Filter2/checku'
 * '<S102>' : 'HW6_Simulink/Flight Control System/Kalman Filter2/checky'
 * '<S103>' : 'HW6_Simulink/Flight Control System/Kalman Filter2/CalculatePL/DataTypeConversionL'
 * '<S104>' : 'HW6_Simulink/Flight Control System/Kalman Filter2/CalculatePL/DataTypeConversionM'
 * '<S105>' : 'HW6_Simulink/Flight Control System/Kalman Filter2/CalculatePL/DataTypeConversionP'
 * '<S106>' : 'HW6_Simulink/Flight Control System/Kalman Filter2/CalculatePL/DataTypeConversionZ'
 * '<S107>' : 'HW6_Simulink/Flight Control System/Kalman Filter2/CalculatePL/Ground'
 * '<S108>' : 'HW6_Simulink/Flight Control System/Kalman Filter2/CalculateYhat/Ground'
 * '<S109>' : 'HW6_Simulink/Flight Control System/Kalman Filter2/Observer/MeasurementUpdate'
 * '<S110>' : 'HW6_Simulink/Flight Control System/Kalman Filter2/ReducedQRN/Ground'
 * '<S111>' : 'HW6_Simulink/Flight Control System/Kalman Filter2/UseCurrentEstimator/Enabled Subsystem'
 * '<S112>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/CalculatePL'
 * '<S113>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/CalculateYhat'
 * '<S114>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/CovarianceOutputConfigurator'
 * '<S115>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/DataTypeConversionA'
 * '<S116>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/DataTypeConversionB'
 * '<S117>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/DataTypeConversionC'
 * '<S118>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/DataTypeConversionD'
 * '<S119>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/DataTypeConversionEnable'
 * '<S120>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/DataTypeConversionG'
 * '<S121>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/DataTypeConversionH'
 * '<S122>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/DataTypeConversionN'
 * '<S123>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/DataTypeConversionP'
 * '<S124>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/DataTypeConversionP0'
 * '<S125>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/DataTypeConversionQ'
 * '<S126>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/DataTypeConversionR'
 * '<S127>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/DataTypeConversionReset'
 * '<S128>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/DataTypeConversionX'
 * '<S129>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/DataTypeConversionX0'
 * '<S130>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/DataTypeConversionu'
 * '<S131>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/MemoryP'
 * '<S132>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/Observer'
 * '<S133>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/ReducedQRN'
 * '<S134>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/Reset'
 * '<S135>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/Reshapeyhat'
 * '<S136>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/ScalarExpansionP0'
 * '<S137>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/ScalarExpansionQ'
 * '<S138>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/ScalarExpansionR'
 * '<S139>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/UseCurrentEstimator'
 * '<S140>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/checkA'
 * '<S141>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/checkB'
 * '<S142>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/checkC'
 * '<S143>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/checkD'
 * '<S144>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/checkEnable'
 * '<S145>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/checkG'
 * '<S146>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/checkH'
 * '<S147>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/checkN'
 * '<S148>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/checkP0'
 * '<S149>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/checkQ'
 * '<S150>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/checkR'
 * '<S151>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/checkReset'
 * '<S152>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/checkX0'
 * '<S153>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/checku'
 * '<S154>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/checky'
 * '<S155>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/CalculatePL/DataTypeConversionL'
 * '<S156>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/CalculatePL/DataTypeConversionM'
 * '<S157>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/CalculatePL/DataTypeConversionP'
 * '<S158>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/CalculatePL/DataTypeConversionZ'
 * '<S159>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/CalculatePL/Ground'
 * '<S160>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/CalculateYhat/Ground'
 * '<S161>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/Observer/MeasurementUpdate'
 * '<S162>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/ReducedQRN/Ground'
 * '<S163>' : 'HW6_Simulink/Flight Control System/Kalman Filter3/UseCurrentEstimator/Enabled Subsystem'
 * '<S164>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/CalculatePL'
 * '<S165>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/CalculateYhat'
 * '<S166>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/CovarianceOutputConfigurator'
 * '<S167>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/DataTypeConversionA'
 * '<S168>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/DataTypeConversionB'
 * '<S169>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/DataTypeConversionC'
 * '<S170>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/DataTypeConversionD'
 * '<S171>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/DataTypeConversionEnable'
 * '<S172>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/DataTypeConversionG'
 * '<S173>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/DataTypeConversionH'
 * '<S174>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/DataTypeConversionN'
 * '<S175>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/DataTypeConversionP'
 * '<S176>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/DataTypeConversionP0'
 * '<S177>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/DataTypeConversionQ'
 * '<S178>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/DataTypeConversionR'
 * '<S179>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/DataTypeConversionReset'
 * '<S180>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/DataTypeConversionX'
 * '<S181>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/DataTypeConversionX0'
 * '<S182>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/DataTypeConversionu'
 * '<S183>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/MemoryP'
 * '<S184>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/Observer'
 * '<S185>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/ReducedQRN'
 * '<S186>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/Reset'
 * '<S187>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/Reshapeyhat'
 * '<S188>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/ScalarExpansionP0'
 * '<S189>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/ScalarExpansionQ'
 * '<S190>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/ScalarExpansionR'
 * '<S191>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/UseCurrentEstimator'
 * '<S192>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/checkA'
 * '<S193>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/checkB'
 * '<S194>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/checkC'
 * '<S195>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/checkD'
 * '<S196>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/checkEnable'
 * '<S197>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/checkG'
 * '<S198>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/checkH'
 * '<S199>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/checkN'
 * '<S200>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/checkP0'
 * '<S201>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/checkQ'
 * '<S202>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/checkR'
 * '<S203>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/checkReset'
 * '<S204>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/checkX0'
 * '<S205>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/checku'
 * '<S206>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/checky'
 * '<S207>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/CalculatePL/DataTypeConversionL'
 * '<S208>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/CalculatePL/DataTypeConversionM'
 * '<S209>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/CalculatePL/DataTypeConversionP'
 * '<S210>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/CalculatePL/DataTypeConversionZ'
 * '<S211>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/CalculatePL/Ground'
 * '<S212>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/CalculateYhat/Ground'
 * '<S213>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/Observer/MeasurementUpdate'
 * '<S214>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/ReducedQRN/Ground'
 * '<S215>' : 'HW6_Simulink/Flight Control System/Kalman Filter4/UseCurrentEstimator/Enabled Subsystem'
 * '<S216>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/CalculatePL'
 * '<S217>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/CalculateYhat'
 * '<S218>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/CovarianceOutputConfigurator'
 * '<S219>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/DataTypeConversionA'
 * '<S220>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/DataTypeConversionB'
 * '<S221>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/DataTypeConversionC'
 * '<S222>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/DataTypeConversionD'
 * '<S223>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/DataTypeConversionEnable'
 * '<S224>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/DataTypeConversionG'
 * '<S225>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/DataTypeConversionH'
 * '<S226>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/DataTypeConversionN'
 * '<S227>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/DataTypeConversionP'
 * '<S228>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/DataTypeConversionP0'
 * '<S229>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/DataTypeConversionQ'
 * '<S230>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/DataTypeConversionR'
 * '<S231>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/DataTypeConversionReset'
 * '<S232>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/DataTypeConversionX'
 * '<S233>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/DataTypeConversionX0'
 * '<S234>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/DataTypeConversionu'
 * '<S235>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/MemoryP'
 * '<S236>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/Observer'
 * '<S237>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/ReducedQRN'
 * '<S238>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/Reset'
 * '<S239>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/Reshapeyhat'
 * '<S240>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/ScalarExpansionP0'
 * '<S241>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/ScalarExpansionQ'
 * '<S242>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/ScalarExpansionR'
 * '<S243>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/UseCurrentEstimator'
 * '<S244>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/checkA'
 * '<S245>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/checkB'
 * '<S246>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/checkC'
 * '<S247>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/checkD'
 * '<S248>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/checkEnable'
 * '<S249>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/checkG'
 * '<S250>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/checkH'
 * '<S251>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/checkN'
 * '<S252>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/checkP0'
 * '<S253>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/checkQ'
 * '<S254>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/checkR'
 * '<S255>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/checkReset'
 * '<S256>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/checkX0'
 * '<S257>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/checku'
 * '<S258>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/checky'
 * '<S259>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S260>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S261>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S262>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S263>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/CalculatePL/Ground'
 * '<S264>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/CalculateYhat/Ground'
 * '<S265>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/Observer/MeasurementUpdate'
 * '<S266>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/ReducedQRN/Ground'
 * '<S267>' : 'HW6_Simulink/Flight Control System/zw Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 */
#endif                                 /* RTW_HEADER_HW6_Simulink_h_ */

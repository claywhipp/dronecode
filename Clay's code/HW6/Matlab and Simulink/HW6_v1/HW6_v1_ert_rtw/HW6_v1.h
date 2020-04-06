/*
 * HW6_v1.h
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

#ifndef RTW_HEADER_HW6_v1_h_
#define RTW_HEADER_HW6_v1_h_
#include <stddef.h>
#include <math.h>
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

/* Block signals for system '<S32>/MeasurementUpdate' */
typedef struct {
  real_T Product3;                     /* '<S61>/Product3' */
} B_MeasurementUpdate_HW6_v1_T;

/* Block states (default storage) for system '<S32>/MeasurementUpdate' */
typedef struct {
  boolean_T MeasurementUpdate_MODE;    /* '<S32>/MeasurementUpdate' */
} DW_MeasurementUpdate_HW6_v1_T;

/* Block signals for system '<S39>/Enabled Subsystem' */
typedef struct {
  real_T Product2;                     /* '<S63>/Product2' */
} B_EnabledSubsystem_HW6_v1_T;

/* Block states (default storage) for system '<S39>/Enabled Subsystem' */
typedef struct {
  boolean_T EnabledSubsystem_MODE;     /* '<S39>/Enabled Subsystem' */
} DW_EnabledSubsystem_HW6_v1_T;

/* Block signals (default storage) */
typedef struct {
  real_T TmpSignalConversionAtToWork[17];
  real_T Akxhatkk1[2];                 /* '<S240>/A[k]*xhat[k|k-1]' */
  real_T Add_m[2];                     /* '<S240>/Add' */
  real_T DataTypeConversion1;          /* '<S1>/Data Type Conversion1' */
  real_T DataTypeConversion2;          /* '<S1>/Data Type Conversion2' */
  real_T Sum1;                         /* '<S1>/Sum1' */
  real_T DataTypeConversion3;          /* '<S1>/Data Type Conversion3' */
  real_T DataTypeConversion4;          /* '<S1>/Data Type Conversion4' */
  real_T DataTypeConversion5;          /* '<S1>/Data Type Conversion5' */
  real_T Checksignofinput;             /* '<S2>/Check sign of input' */
  real_T a_z;                          /* '<S2>/Decide what to input' */
  real_T a_z_m;                        /* '<S3>/Decide what to input' */
  real_T Integrator;                   /* '<S1>/Integrator' */
  real_T Integrator2;                  /* '<S1>/Integrator2' */
  real_T Integrator4;                  /* '<S1>/Integrator4' */
  real_T Product2[2];                  /* '<S271>/Product2' */
  real_T Product3[2];                  /* '<S269>/Product3' */
  real_T Reshapey;                     /* '<S9>/Reshapey' */
  real_T SquareRoot;                   /* '<S1>/Square Root' */
  real_T Sum;                          /* '<S269>/Sum' */
  real_T rtb_MemoryX_idx_0;
  real_T rtb_MemoryX_idx_1;
  real_T Reshapey_e;                   /* '<S7>/Reshapey' */
  real_T MemoryX_o;                    /* '<S7>/MemoryX' */
  real_T Dkuk;                         /* '<S269>/D[k]*u[k]' */
  boolean_T AND;                       /* '<S10>/AND' */
  B_EnabledSubsystem_HW6_v1_T EnabledSubsystem_f0;/* '<S195>/Enabled Subsystem' */
  B_MeasurementUpdate_HW6_v1_T MeasurementUpdate_f;/* '<S188>/MeasurementUpdate' */
  B_EnabledSubsystem_HW6_v1_T EnabledSubsystem_d;/* '<S143>/Enabled Subsystem' */
  B_MeasurementUpdate_HW6_v1_T MeasurementUpdate_h;/* '<S136>/MeasurementUpdate' */
  B_EnabledSubsystem_HW6_v1_T EnabledSubsystem_f;/* '<S91>/Enabled Subsystem' */
  B_MeasurementUpdate_HW6_v1_T MeasurementUpdate_c;/* '<S84>/MeasurementUpdate' */
  B_EnabledSubsystem_HW6_v1_T EnabledSubsystem;/* '<S39>/Enabled Subsystem' */
  B_MeasurementUpdate_HW6_v1_T MeasurementUpdate;/* '<S32>/MeasurementUpdate' */
} B_HW6_v1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T MemoryX_DSTATE[2];            /* '<S9>/MemoryX' */
  real_T MemoryX_DSTATE_l;             /* '<S7>/MemoryX' */
  real_T MemoryX_DSTATE_f;             /* '<S8>/MemoryX' */
  real_T MemoryX_DSTATE_g;             /* '<S4>/MemoryX' */
  real_T MemoryX_DSTATE_b;             /* '<S5>/MemoryX' */
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

  struct {
    void *LoggedData;
  } ToWorkspace8_PWORK;                /* '<S1>/To Workspace8' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK_j;              /* '<S2>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK_n;              /* '<S2>/To Workspace2' */

  struct {
    void *LoggedData;
  } ToWorkspace8_PWORK_a;              /* '<S2>/To Workspace8' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S3>/To Workspace' */

  uint8_T icLoad;                      /* '<S9>/MemoryX' */
  uint8_T icLoad_m;                    /* '<S7>/MemoryX' */
  uint8_T icLoad_l;                    /* '<S8>/MemoryX' */
  uint8_T icLoad_d;                    /* '<S4>/MemoryX' */
  uint8_T icLoad_e;                    /* '<S5>/MemoryX' */
  boolean_T EnabledSubsystem_MODE;     /* '<S247>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S240>/MeasurementUpdate' */
  DW_EnabledSubsystem_HW6_v1_T EnabledSubsystem_f0;/* '<S195>/Enabled Subsystem' */
  DW_MeasurementUpdate_HW6_v1_T MeasurementUpdate_f;/* '<S188>/MeasurementUpdate' */
  DW_EnabledSubsystem_HW6_v1_T EnabledSubsystem_d;/* '<S143>/Enabled Subsystem' */
  DW_MeasurementUpdate_HW6_v1_T MeasurementUpdate_h;/* '<S136>/MeasurementUpdate' */
  DW_EnabledSubsystem_HW6_v1_T EnabledSubsystem_f;/* '<S91>/Enabled Subsystem' */
  DW_MeasurementUpdate_HW6_v1_T MeasurementUpdate_c;/* '<S84>/MeasurementUpdate' */
  DW_EnabledSubsystem_HW6_v1_T EnabledSubsystem;/* '<S39>/Enabled Subsystem' */
  DW_MeasurementUpdate_HW6_v1_T MeasurementUpdate;/* '<S32>/MeasurementUpdate' */
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

/* Parameters for system: '<S32>/MeasurementUpdate' */
struct P_MeasurementUpdate_HW6_v1_T_ {
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S61>/L*(y[k]-yhat[k|k-1])'
                                        */
};

/* Parameters for system: '<S39>/Enabled Subsystem' */
struct P_EnabledSubsystem_HW6_v1_T_ {
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S63>/deltax'
                                        */
};

/* Parameters (default storage) */
struct P_HW6_v1_T_ {
  real_T IntervalTest_lowlimit;        /* Mask Parameter: IntervalTest_lowlimit
                                        * Referenced by: '<S10>/Lower Limit'
                                        */
  real_T IntervalTest_lowlimit_n;     /* Mask Parameter: IntervalTest_lowlimit_n
                                       * Referenced by: '<S11>/Lower Limit'
                                       */
  real_T IntervalTest_uplimit;         /* Mask Parameter: IntervalTest_uplimit
                                        * Referenced by: '<S10>/Upper Limit'
                                        */
  real_T IntervalTest_uplimit_c;       /* Mask Parameter: IntervalTest_uplimit_c
                                        * Referenced by: '<S11>/Upper Limit'
                                        */
  real_T Checksignofinput_Threshold;   /* Expression: 0
                                        * Referenced by: '<S3>/Check sign of input'
                                        */
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S269>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S271>/deltax'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
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
                                        * Referenced by: '<S220>/KalmanGainM'
                                        */
  real_T C_Value[2];                   /* Expression: pInitialization.C
                                        * Referenced by: '<S9>/C'
                                        */
  real_T X0_Value[2];                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S9>/X0'
                                        */
  real_T KalmanGainM_Value_c;          /* Expression: pInitialization.M
                                        * Referenced by: '<S116>/KalmanGainM'
                                        */
  real_T C_Value_a;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S7>/C'
                                        */
  real_T X0_Value_h;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S7>/X0'
                                        */
  real_T KalmanGainM_Value_i;          /* Expression: pInitialization.M
                                        * Referenced by: '<S168>/KalmanGainM'
                                        */
  real_T C_Value_d;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S8>/C'
                                        */
  real_T X0_Value_l;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S8>/X0'
                                        */
  real_T KalmanGainM_Value_l;          /* Expression: pInitialization.M
                                        * Referenced by: '<S12>/KalmanGainM'
                                        */
  real_T C_Value_h;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S4>/C'
                                        */
  real_T Constant3_Value;              /* Expression: 0.5
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: -0.5
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Checksignofinput_Threshold_b; /* Expression: 0
                                        * Referenced by: '<S2>/Check sign of input'
                                        */
  real_T X0_Value_g;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S4>/X0'
                                        */
  real_T KalmanGainM_Value_n;          /* Expression: pInitialization.M
                                        * Referenced by: '<S64>/KalmanGainM'
                                        */
  real_T C_Value_b;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S5>/C'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Constant3_Value_f;            /* Expression: 0.5
                                        * Referenced by: '<S3>/Constant3'
                                        */
  real_T Constant4_Value_n;            /* Expression: -0.5
                                        * Referenced by: '<S3>/Constant4'
                                        */
  real_T X0_Value_p;                   /* Expression: pInitialization.X0
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
                                        * Referenced by: '<S4>/A'
                                        */
  real_T B_Value;                      /* Expression: pInitialization.B
                                        * Referenced by: '<S4>/B'
                                        */
  real_T KalmanGainL_Value;            /* Expression: pInitialization.L
                                        * Referenced by: '<S12>/KalmanGainL'
                                        */
  real_T D_Value;                      /* Expression: pInitialization.D
                                        * Referenced by: '<S4>/D'
                                        */
  real_T A_Value_c;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S5>/A'
                                        */
  real_T B_Value_l;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S5>/B'
                                        */
  real_T KalmanGainL_Value_o;          /* Expression: pInitialization.L
                                        * Referenced by: '<S64>/KalmanGainL'
                                        */
  real_T D_Value_i;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S5>/D'
                                        */
  real_T A_Value_m;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S7>/A'
                                        */
  real_T B_Value_g;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S7>/B'
                                        */
  real_T KalmanGainL_Value_j;          /* Expression: pInitialization.L
                                        * Referenced by: '<S116>/KalmanGainL'
                                        */
  real_T D_Value_h;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S7>/D'
                                        */
  real_T A_Value_mn;                   /* Expression: pInitialization.A
                                        * Referenced by: '<S8>/A'
                                        */
  real_T B_Value_p;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S8>/B'
                                        */
  real_T KalmanGainL_Value_g;          /* Expression: pInitialization.L
                                        * Referenced by: '<S168>/KalmanGainL'
                                        */
  real_T D_Value_e;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S8>/D'
                                        */
  real_T A_Value_b[4];                 /* Expression: pInitialization.A
                                        * Referenced by: '<S9>/A'
                                        */
  real_T B_Value_n[2];                 /* Expression: pInitialization.B
                                        * Referenced by: '<S9>/B'
                                        */
  real_T KalmanGainL_Value_n[2];       /* Expression: pInitialization.L
                                        * Referenced by: '<S220>/KalmanGainL'
                                        */
  real_T D_Value_d;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S9>/D'
                                        */
  real32_T Saturation1_UpperSat;     /* Computed Parameter: Saturation1_UpperSat
                                      * Referenced by: '<S1>/Saturation1'
                                      */
  real32_T Saturation1_LowerSat;     /* Computed Parameter: Saturation1_LowerSat
                                      * Referenced by: '<S1>/Saturation1'
                                      */
  boolean_T Enable_Value;              /* Expression: true()
                                        * Referenced by: '<S9>/Enable'
                                        */
  boolean_T Enable_Value_g;            /* Expression: true()
                                        * Referenced by: '<S7>/Enable'
                                        */
  boolean_T Enable_Value_m;            /* Expression: true()
                                        * Referenced by: '<S8>/Enable'
                                        */
  boolean_T Enable_Value_i;            /* Expression: true()
                                        * Referenced by: '<S4>/Enable'
                                        */
  boolean_T Enable_Value_gd;           /* Expression: true()
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
  P_EnabledSubsystem_HW6_v1_T EnabledSubsystem_f0;/* '<S195>/Enabled Subsystem' */
  P_MeasurementUpdate_HW6_v1_T MeasurementUpdate_f;/* '<S188>/MeasurementUpdate' */
  P_EnabledSubsystem_HW6_v1_T EnabledSubsystem_d;/* '<S143>/Enabled Subsystem' */
  P_MeasurementUpdate_HW6_v1_T MeasurementUpdate_h;/* '<S136>/MeasurementUpdate' */
  P_EnabledSubsystem_HW6_v1_T EnabledSubsystem_f;/* '<S91>/Enabled Subsystem' */
  P_MeasurementUpdate_HW6_v1_T MeasurementUpdate_c;/* '<S84>/MeasurementUpdate' */
  P_EnabledSubsystem_HW6_v1_T EnabledSubsystem;/* '<S39>/Enabled Subsystem' */
  P_MeasurementUpdate_HW6_v1_T MeasurementUpdate;/* '<S32>/MeasurementUpdate' */
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
 * Block '<S10>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/CovarianceZ' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S57>/Conversion' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Conversion' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Conversion' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/G' : Unused code path elimination
 * Block '<S4>/H' : Unused code path elimination
 * Block '<S4>/N' : Unused code path elimination
 * Block '<S4>/P0' : Unused code path elimination
 * Block '<S4>/Q' : Unused code path elimination
 * Block '<S4>/R' : Unused code path elimination
 * Block '<S53>/CheckSignalProperties' : Unused code path elimination
 * Block '<S54>/CheckSignalProperties' : Unused code path elimination
 * Block '<S64>/CovarianceZ' : Unused code path elimination
 * Block '<S107>/Data Type Duplicate' : Unused code path elimination
 * Block '<S108>/Data Type Duplicate' : Unused code path elimination
 * Block '<S109>/Conversion' : Unused code path elimination
 * Block '<S109>/Data Type Duplicate' : Unused code path elimination
 * Block '<S110>/Conversion' : Unused code path elimination
 * Block '<S110>/Data Type Duplicate' : Unused code path elimination
 * Block '<S67>/Data Type Duplicate' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S75>/Conversion' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate' : Unused code path elimination
 * Block '<S76>/Data Type Duplicate' : Unused code path elimination
 * Block '<S77>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/Data Type Duplicate' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/G' : Unused code path elimination
 * Block '<S5>/H' : Unused code path elimination
 * Block '<S5>/N' : Unused code path elimination
 * Block '<S5>/P0' : Unused code path elimination
 * Block '<S5>/Q' : Unused code path elimination
 * Block '<S5>/R' : Unused code path elimination
 * Block '<S105>/CheckSignalProperties' : Unused code path elimination
 * Block '<S106>/CheckSignalProperties' : Unused code path elimination
 * Block '<S116>/CovarianceZ' : Unused code path elimination
 * Block '<S159>/Data Type Duplicate' : Unused code path elimination
 * Block '<S160>/Data Type Duplicate' : Unused code path elimination
 * Block '<S161>/Conversion' : Unused code path elimination
 * Block '<S161>/Data Type Duplicate' : Unused code path elimination
 * Block '<S162>/Conversion' : Unused code path elimination
 * Block '<S162>/Data Type Duplicate' : Unused code path elimination
 * Block '<S119>/Data Type Duplicate' : Unused code path elimination
 * Block '<S120>/Data Type Duplicate' : Unused code path elimination
 * Block '<S121>/Data Type Duplicate' : Unused code path elimination
 * Block '<S122>/Data Type Duplicate' : Unused code path elimination
 * Block '<S124>/Data Type Duplicate' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate' : Unused code path elimination
 * Block '<S127>/Conversion' : Unused code path elimination
 * Block '<S127>/Data Type Duplicate' : Unused code path elimination
 * Block '<S128>/Data Type Duplicate' : Unused code path elimination
 * Block '<S129>/Data Type Duplicate' : Unused code path elimination
 * Block '<S130>/Data Type Duplicate' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate' : Unused code path elimination
 * Block '<S133>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/G' : Unused code path elimination
 * Block '<S7>/H' : Unused code path elimination
 * Block '<S7>/N' : Unused code path elimination
 * Block '<S7>/P0' : Unused code path elimination
 * Block '<S7>/Q' : Unused code path elimination
 * Block '<S7>/R' : Unused code path elimination
 * Block '<S157>/CheckSignalProperties' : Unused code path elimination
 * Block '<S158>/CheckSignalProperties' : Unused code path elimination
 * Block '<S168>/CovarianceZ' : Unused code path elimination
 * Block '<S211>/Data Type Duplicate' : Unused code path elimination
 * Block '<S212>/Data Type Duplicate' : Unused code path elimination
 * Block '<S213>/Conversion' : Unused code path elimination
 * Block '<S213>/Data Type Duplicate' : Unused code path elimination
 * Block '<S214>/Conversion' : Unused code path elimination
 * Block '<S214>/Data Type Duplicate' : Unused code path elimination
 * Block '<S171>/Data Type Duplicate' : Unused code path elimination
 * Block '<S172>/Data Type Duplicate' : Unused code path elimination
 * Block '<S173>/Data Type Duplicate' : Unused code path elimination
 * Block '<S174>/Data Type Duplicate' : Unused code path elimination
 * Block '<S176>/Data Type Duplicate' : Unused code path elimination
 * Block '<S177>/Data Type Duplicate' : Unused code path elimination
 * Block '<S178>/Data Type Duplicate' : Unused code path elimination
 * Block '<S179>/Conversion' : Unused code path elimination
 * Block '<S179>/Data Type Duplicate' : Unused code path elimination
 * Block '<S180>/Data Type Duplicate' : Unused code path elimination
 * Block '<S181>/Data Type Duplicate' : Unused code path elimination
 * Block '<S182>/Data Type Duplicate' : Unused code path elimination
 * Block '<S184>/Data Type Duplicate' : Unused code path elimination
 * Block '<S185>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/G' : Unused code path elimination
 * Block '<S8>/H' : Unused code path elimination
 * Block '<S8>/N' : Unused code path elimination
 * Block '<S8>/P0' : Unused code path elimination
 * Block '<S8>/Q' : Unused code path elimination
 * Block '<S8>/R' : Unused code path elimination
 * Block '<S209>/CheckSignalProperties' : Unused code path elimination
 * Block '<S210>/CheckSignalProperties' : Unused code path elimination
 * Block '<S220>/CovarianceZ' : Unused code path elimination
 * Block '<S263>/Data Type Duplicate' : Unused code path elimination
 * Block '<S264>/Data Type Duplicate' : Unused code path elimination
 * Block '<S265>/Conversion' : Unused code path elimination
 * Block '<S265>/Data Type Duplicate' : Unused code path elimination
 * Block '<S266>/Conversion' : Unused code path elimination
 * Block '<S266>/Data Type Duplicate' : Unused code path elimination
 * Block '<S223>/Data Type Duplicate' : Unused code path elimination
 * Block '<S224>/Data Type Duplicate' : Unused code path elimination
 * Block '<S225>/Data Type Duplicate' : Unused code path elimination
 * Block '<S226>/Data Type Duplicate' : Unused code path elimination
 * Block '<S228>/Data Type Duplicate' : Unused code path elimination
 * Block '<S229>/Data Type Duplicate' : Unused code path elimination
 * Block '<S230>/Data Type Duplicate' : Unused code path elimination
 * Block '<S231>/Conversion' : Unused code path elimination
 * Block '<S231>/Data Type Duplicate' : Unused code path elimination
 * Block '<S232>/Data Type Duplicate' : Unused code path elimination
 * Block '<S233>/Data Type Duplicate' : Unused code path elimination
 * Block '<S234>/Data Type Duplicate' : Unused code path elimination
 * Block '<S236>/Data Type Duplicate' : Unused code path elimination
 * Block '<S237>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/G' : Unused code path elimination
 * Block '<S9>/H' : Unused code path elimination
 * Block '<S9>/N' : Unused code path elimination
 * Block '<S9>/P0' : Unused code path elimination
 * Block '<S9>/Q' : Unused code path elimination
 * Block '<S9>/R' : Unused code path elimination
 * Block '<S261>/CheckSignalProperties' : Unused code path elimination
 * Block '<S262>/CheckSignalProperties' : Unused code path elimination
 * Block '<S55>/Conversion' : Eliminate redundant data type conversion
 * Block '<S56>/Conversion' : Eliminate redundant data type conversion
 * Block '<S28>/Conversion' : Eliminate redundant data type conversion
 * Block '<S32>/Reshape' : Reshape block reduction
 * Block '<S4>/ReshapeX0' : Reshape block reduction
 * Block '<S4>/Reshapeu' : Reshape block reduction
 * Block '<S4>/Reshapexhat' : Reshape block reduction
 * Block '<S4>/Reshapey' : Reshape block reduction
 * Block '<S107>/Conversion' : Eliminate redundant data type conversion
 * Block '<S108>/Conversion' : Eliminate redundant data type conversion
 * Block '<S80>/Conversion' : Eliminate redundant data type conversion
 * Block '<S84>/Reshape' : Reshape block reduction
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
 * Block '<S159>/Conversion' : Eliminate redundant data type conversion
 * Block '<S160>/Conversion' : Eliminate redundant data type conversion
 * Block '<S132>/Conversion' : Eliminate redundant data type conversion
 * Block '<S136>/Reshape' : Reshape block reduction
 * Block '<S7>/ReshapeX0' : Reshape block reduction
 * Block '<S7>/Reshapexhat' : Reshape block reduction
 * Block '<S211>/Conversion' : Eliminate redundant data type conversion
 * Block '<S212>/Conversion' : Eliminate redundant data type conversion
 * Block '<S184>/Conversion' : Eliminate redundant data type conversion
 * Block '<S188>/Reshape' : Reshape block reduction
 * Block '<S8>/ReshapeX0' : Reshape block reduction
 * Block '<S8>/Reshapexhat' : Reshape block reduction
 * Block '<S263>/Conversion' : Eliminate redundant data type conversion
 * Block '<S264>/Conversion' : Eliminate redundant data type conversion
 * Block '<S236>/Conversion' : Eliminate redundant data type conversion
 * Block '<S240>/Reshape' : Reshape block reduction
 * Block '<S9>/ReshapeX0' : Reshape block reduction
 * Block '<S9>/Reshapexhat' : Reshape block reduction
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
 * '<S2>'   : 'HW6_v1/Flight_Control_System/Check if near zero'
 * '<S3>'   : 'HW6_v1/Flight_Control_System/Check if near zero1'
 * '<S4>'   : 'HW6_v1/Flight_Control_System/Kalman Filter3'
 * '<S5>'   : 'HW6_v1/Flight_Control_System/Kalman Filter4'
 * '<S6>'   : 'HW6_v1/Flight_Control_System/Subsystem'
 * '<S7>'   : 'HW6_v1/Flight_Control_System/u Kalman Filter'
 * '<S8>'   : 'HW6_v1/Flight_Control_System/v Kalman filter'
 * '<S9>'   : 'HW6_v1/Flight_Control_System/zw Kalman Filter'
 * '<S10>'  : 'HW6_v1/Flight_Control_System/Check if near zero/Interval Test'
 * '<S11>'  : 'HW6_v1/Flight_Control_System/Check if near zero1/Interval Test'
 * '<S12>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/CalculatePL'
 * '<S13>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/CalculateYhat'
 * '<S14>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/CovarianceOutputConfigurator'
 * '<S15>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/DataTypeConversionA'
 * '<S16>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/DataTypeConversionB'
 * '<S17>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/DataTypeConversionC'
 * '<S18>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/DataTypeConversionD'
 * '<S19>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/DataTypeConversionEnable'
 * '<S20>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/DataTypeConversionG'
 * '<S21>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/DataTypeConversionH'
 * '<S22>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/DataTypeConversionN'
 * '<S23>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/DataTypeConversionP'
 * '<S24>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/DataTypeConversionP0'
 * '<S25>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/DataTypeConversionQ'
 * '<S26>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/DataTypeConversionR'
 * '<S27>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/DataTypeConversionReset'
 * '<S28>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/DataTypeConversionX'
 * '<S29>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/DataTypeConversionX0'
 * '<S30>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/DataTypeConversionu'
 * '<S31>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/MemoryP'
 * '<S32>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/Observer'
 * '<S33>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/ReducedQRN'
 * '<S34>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/Reset'
 * '<S35>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/Reshapeyhat'
 * '<S36>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/ScalarExpansionP0'
 * '<S37>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/ScalarExpansionQ'
 * '<S38>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/ScalarExpansionR'
 * '<S39>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/UseCurrentEstimator'
 * '<S40>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/checkA'
 * '<S41>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/checkB'
 * '<S42>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/checkC'
 * '<S43>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/checkD'
 * '<S44>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/checkEnable'
 * '<S45>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/checkG'
 * '<S46>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/checkH'
 * '<S47>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/checkN'
 * '<S48>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/checkP0'
 * '<S49>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/checkQ'
 * '<S50>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/checkR'
 * '<S51>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/checkReset'
 * '<S52>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/checkX0'
 * '<S53>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/checku'
 * '<S54>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/checky'
 * '<S55>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/CalculatePL/DataTypeConversionL'
 * '<S56>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/CalculatePL/DataTypeConversionM'
 * '<S57>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/CalculatePL/DataTypeConversionP'
 * '<S58>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/CalculatePL/DataTypeConversionZ'
 * '<S59>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/CalculatePL/Ground'
 * '<S60>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/CalculateYhat/Ground'
 * '<S61>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/Observer/MeasurementUpdate'
 * '<S62>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/ReducedQRN/Ground'
 * '<S63>'  : 'HW6_v1/Flight_Control_System/Kalman Filter3/UseCurrentEstimator/Enabled Subsystem'
 * '<S64>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/CalculatePL'
 * '<S65>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/CalculateYhat'
 * '<S66>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/CovarianceOutputConfigurator'
 * '<S67>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/DataTypeConversionA'
 * '<S68>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/DataTypeConversionB'
 * '<S69>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/DataTypeConversionC'
 * '<S70>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/DataTypeConversionD'
 * '<S71>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/DataTypeConversionEnable'
 * '<S72>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/DataTypeConversionG'
 * '<S73>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/DataTypeConversionH'
 * '<S74>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/DataTypeConversionN'
 * '<S75>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/DataTypeConversionP'
 * '<S76>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/DataTypeConversionP0'
 * '<S77>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/DataTypeConversionQ'
 * '<S78>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/DataTypeConversionR'
 * '<S79>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/DataTypeConversionReset'
 * '<S80>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/DataTypeConversionX'
 * '<S81>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/DataTypeConversionX0'
 * '<S82>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/DataTypeConversionu'
 * '<S83>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/MemoryP'
 * '<S84>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/Observer'
 * '<S85>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/ReducedQRN'
 * '<S86>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/Reset'
 * '<S87>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/Reshapeyhat'
 * '<S88>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/ScalarExpansionP0'
 * '<S89>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/ScalarExpansionQ'
 * '<S90>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/ScalarExpansionR'
 * '<S91>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/UseCurrentEstimator'
 * '<S92>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/checkA'
 * '<S93>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/checkB'
 * '<S94>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/checkC'
 * '<S95>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/checkD'
 * '<S96>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/checkEnable'
 * '<S97>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/checkG'
 * '<S98>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/checkH'
 * '<S99>'  : 'HW6_v1/Flight_Control_System/Kalman Filter4/checkN'
 * '<S100>' : 'HW6_v1/Flight_Control_System/Kalman Filter4/checkP0'
 * '<S101>' : 'HW6_v1/Flight_Control_System/Kalman Filter4/checkQ'
 * '<S102>' : 'HW6_v1/Flight_Control_System/Kalman Filter4/checkR'
 * '<S103>' : 'HW6_v1/Flight_Control_System/Kalman Filter4/checkReset'
 * '<S104>' : 'HW6_v1/Flight_Control_System/Kalman Filter4/checkX0'
 * '<S105>' : 'HW6_v1/Flight_Control_System/Kalman Filter4/checku'
 * '<S106>' : 'HW6_v1/Flight_Control_System/Kalman Filter4/checky'
 * '<S107>' : 'HW6_v1/Flight_Control_System/Kalman Filter4/CalculatePL/DataTypeConversionL'
 * '<S108>' : 'HW6_v1/Flight_Control_System/Kalman Filter4/CalculatePL/DataTypeConversionM'
 * '<S109>' : 'HW6_v1/Flight_Control_System/Kalman Filter4/CalculatePL/DataTypeConversionP'
 * '<S110>' : 'HW6_v1/Flight_Control_System/Kalman Filter4/CalculatePL/DataTypeConversionZ'
 * '<S111>' : 'HW6_v1/Flight_Control_System/Kalman Filter4/CalculatePL/Ground'
 * '<S112>' : 'HW6_v1/Flight_Control_System/Kalman Filter4/CalculateYhat/Ground'
 * '<S113>' : 'HW6_v1/Flight_Control_System/Kalman Filter4/Observer/MeasurementUpdate'
 * '<S114>' : 'HW6_v1/Flight_Control_System/Kalman Filter4/ReducedQRN/Ground'
 * '<S115>' : 'HW6_v1/Flight_Control_System/Kalman Filter4/UseCurrentEstimator/Enabled Subsystem'
 * '<S116>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/CalculatePL'
 * '<S117>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/CalculateYhat'
 * '<S118>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/CovarianceOutputConfigurator'
 * '<S119>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/DataTypeConversionA'
 * '<S120>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/DataTypeConversionB'
 * '<S121>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/DataTypeConversionC'
 * '<S122>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/DataTypeConversionD'
 * '<S123>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/DataTypeConversionEnable'
 * '<S124>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/DataTypeConversionG'
 * '<S125>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/DataTypeConversionH'
 * '<S126>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/DataTypeConversionN'
 * '<S127>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/DataTypeConversionP'
 * '<S128>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/DataTypeConversionP0'
 * '<S129>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/DataTypeConversionQ'
 * '<S130>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/DataTypeConversionR'
 * '<S131>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/DataTypeConversionReset'
 * '<S132>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/DataTypeConversionX'
 * '<S133>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/DataTypeConversionX0'
 * '<S134>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/DataTypeConversionu'
 * '<S135>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/MemoryP'
 * '<S136>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/Observer'
 * '<S137>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/ReducedQRN'
 * '<S138>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/Reset'
 * '<S139>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/Reshapeyhat'
 * '<S140>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/ScalarExpansionP0'
 * '<S141>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/ScalarExpansionQ'
 * '<S142>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/ScalarExpansionR'
 * '<S143>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/UseCurrentEstimator'
 * '<S144>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/checkA'
 * '<S145>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/checkB'
 * '<S146>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/checkC'
 * '<S147>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/checkD'
 * '<S148>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/checkEnable'
 * '<S149>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/checkG'
 * '<S150>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/checkH'
 * '<S151>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/checkN'
 * '<S152>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/checkP0'
 * '<S153>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/checkQ'
 * '<S154>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/checkR'
 * '<S155>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/checkReset'
 * '<S156>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/checkX0'
 * '<S157>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/checku'
 * '<S158>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/checky'
 * '<S159>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S160>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S161>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S162>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S163>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/CalculatePL/Ground'
 * '<S164>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/CalculateYhat/Ground'
 * '<S165>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/Observer/MeasurementUpdate'
 * '<S166>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/ReducedQRN/Ground'
 * '<S167>' : 'HW6_v1/Flight_Control_System/u Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S168>' : 'HW6_v1/Flight_Control_System/v Kalman filter/CalculatePL'
 * '<S169>' : 'HW6_v1/Flight_Control_System/v Kalman filter/CalculateYhat'
 * '<S170>' : 'HW6_v1/Flight_Control_System/v Kalman filter/CovarianceOutputConfigurator'
 * '<S171>' : 'HW6_v1/Flight_Control_System/v Kalman filter/DataTypeConversionA'
 * '<S172>' : 'HW6_v1/Flight_Control_System/v Kalman filter/DataTypeConversionB'
 * '<S173>' : 'HW6_v1/Flight_Control_System/v Kalman filter/DataTypeConversionC'
 * '<S174>' : 'HW6_v1/Flight_Control_System/v Kalman filter/DataTypeConversionD'
 * '<S175>' : 'HW6_v1/Flight_Control_System/v Kalman filter/DataTypeConversionEnable'
 * '<S176>' : 'HW6_v1/Flight_Control_System/v Kalman filter/DataTypeConversionG'
 * '<S177>' : 'HW6_v1/Flight_Control_System/v Kalman filter/DataTypeConversionH'
 * '<S178>' : 'HW6_v1/Flight_Control_System/v Kalman filter/DataTypeConversionN'
 * '<S179>' : 'HW6_v1/Flight_Control_System/v Kalman filter/DataTypeConversionP'
 * '<S180>' : 'HW6_v1/Flight_Control_System/v Kalman filter/DataTypeConversionP0'
 * '<S181>' : 'HW6_v1/Flight_Control_System/v Kalman filter/DataTypeConversionQ'
 * '<S182>' : 'HW6_v1/Flight_Control_System/v Kalman filter/DataTypeConversionR'
 * '<S183>' : 'HW6_v1/Flight_Control_System/v Kalman filter/DataTypeConversionReset'
 * '<S184>' : 'HW6_v1/Flight_Control_System/v Kalman filter/DataTypeConversionX'
 * '<S185>' : 'HW6_v1/Flight_Control_System/v Kalman filter/DataTypeConversionX0'
 * '<S186>' : 'HW6_v1/Flight_Control_System/v Kalman filter/DataTypeConversionu'
 * '<S187>' : 'HW6_v1/Flight_Control_System/v Kalman filter/MemoryP'
 * '<S188>' : 'HW6_v1/Flight_Control_System/v Kalman filter/Observer'
 * '<S189>' : 'HW6_v1/Flight_Control_System/v Kalman filter/ReducedQRN'
 * '<S190>' : 'HW6_v1/Flight_Control_System/v Kalman filter/Reset'
 * '<S191>' : 'HW6_v1/Flight_Control_System/v Kalman filter/Reshapeyhat'
 * '<S192>' : 'HW6_v1/Flight_Control_System/v Kalman filter/ScalarExpansionP0'
 * '<S193>' : 'HW6_v1/Flight_Control_System/v Kalman filter/ScalarExpansionQ'
 * '<S194>' : 'HW6_v1/Flight_Control_System/v Kalman filter/ScalarExpansionR'
 * '<S195>' : 'HW6_v1/Flight_Control_System/v Kalman filter/UseCurrentEstimator'
 * '<S196>' : 'HW6_v1/Flight_Control_System/v Kalman filter/checkA'
 * '<S197>' : 'HW6_v1/Flight_Control_System/v Kalman filter/checkB'
 * '<S198>' : 'HW6_v1/Flight_Control_System/v Kalman filter/checkC'
 * '<S199>' : 'HW6_v1/Flight_Control_System/v Kalman filter/checkD'
 * '<S200>' : 'HW6_v1/Flight_Control_System/v Kalman filter/checkEnable'
 * '<S201>' : 'HW6_v1/Flight_Control_System/v Kalman filter/checkG'
 * '<S202>' : 'HW6_v1/Flight_Control_System/v Kalman filter/checkH'
 * '<S203>' : 'HW6_v1/Flight_Control_System/v Kalman filter/checkN'
 * '<S204>' : 'HW6_v1/Flight_Control_System/v Kalman filter/checkP0'
 * '<S205>' : 'HW6_v1/Flight_Control_System/v Kalman filter/checkQ'
 * '<S206>' : 'HW6_v1/Flight_Control_System/v Kalman filter/checkR'
 * '<S207>' : 'HW6_v1/Flight_Control_System/v Kalman filter/checkReset'
 * '<S208>' : 'HW6_v1/Flight_Control_System/v Kalman filter/checkX0'
 * '<S209>' : 'HW6_v1/Flight_Control_System/v Kalman filter/checku'
 * '<S210>' : 'HW6_v1/Flight_Control_System/v Kalman filter/checky'
 * '<S211>' : 'HW6_v1/Flight_Control_System/v Kalman filter/CalculatePL/DataTypeConversionL'
 * '<S212>' : 'HW6_v1/Flight_Control_System/v Kalman filter/CalculatePL/DataTypeConversionM'
 * '<S213>' : 'HW6_v1/Flight_Control_System/v Kalman filter/CalculatePL/DataTypeConversionP'
 * '<S214>' : 'HW6_v1/Flight_Control_System/v Kalman filter/CalculatePL/DataTypeConversionZ'
 * '<S215>' : 'HW6_v1/Flight_Control_System/v Kalman filter/CalculatePL/Ground'
 * '<S216>' : 'HW6_v1/Flight_Control_System/v Kalman filter/CalculateYhat/Ground'
 * '<S217>' : 'HW6_v1/Flight_Control_System/v Kalman filter/Observer/MeasurementUpdate'
 * '<S218>' : 'HW6_v1/Flight_Control_System/v Kalman filter/ReducedQRN/Ground'
 * '<S219>' : 'HW6_v1/Flight_Control_System/v Kalman filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S220>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/CalculatePL'
 * '<S221>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/CalculateYhat'
 * '<S222>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/CovarianceOutputConfigurator'
 * '<S223>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/DataTypeConversionA'
 * '<S224>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/DataTypeConversionB'
 * '<S225>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/DataTypeConversionC'
 * '<S226>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/DataTypeConversionD'
 * '<S227>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/DataTypeConversionEnable'
 * '<S228>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/DataTypeConversionG'
 * '<S229>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/DataTypeConversionH'
 * '<S230>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/DataTypeConversionN'
 * '<S231>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/DataTypeConversionP'
 * '<S232>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/DataTypeConversionP0'
 * '<S233>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/DataTypeConversionQ'
 * '<S234>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/DataTypeConversionR'
 * '<S235>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/DataTypeConversionReset'
 * '<S236>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/DataTypeConversionX'
 * '<S237>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/DataTypeConversionX0'
 * '<S238>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/DataTypeConversionu'
 * '<S239>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/MemoryP'
 * '<S240>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/Observer'
 * '<S241>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/ReducedQRN'
 * '<S242>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/Reset'
 * '<S243>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/Reshapeyhat'
 * '<S244>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/ScalarExpansionP0'
 * '<S245>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/ScalarExpansionQ'
 * '<S246>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/ScalarExpansionR'
 * '<S247>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/UseCurrentEstimator'
 * '<S248>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/checkA'
 * '<S249>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/checkB'
 * '<S250>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/checkC'
 * '<S251>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/checkD'
 * '<S252>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/checkEnable'
 * '<S253>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/checkG'
 * '<S254>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/checkH'
 * '<S255>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/checkN'
 * '<S256>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/checkP0'
 * '<S257>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/checkQ'
 * '<S258>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/checkR'
 * '<S259>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/checkReset'
 * '<S260>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/checkX0'
 * '<S261>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/checku'
 * '<S262>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/checky'
 * '<S263>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S264>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S265>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S266>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S267>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/CalculatePL/Ground'
 * '<S268>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/CalculateYhat/Ground'
 * '<S269>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/Observer/MeasurementUpdate'
 * '<S270>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/ReducedQRN/Ground'
 * '<S271>' : 'HW6_v1/Flight_Control_System/zw Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 */
#endif                                 /* RTW_HEADER_HW6_v1_h_ */

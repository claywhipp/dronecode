/*
 * TestDataLogging.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "TestDataLogging".
 *
 * Model version              : 1.6
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Feb 26 15:06:48 2020
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TestDataLogging_h_
#define RTW_HEADER_TestDataLogging_h_
#include <stddef.h>
#include <string.h>
#include <float.h>
#ifndef TestDataLogging_COMMON_INCLUDES_
# define TestDataLogging_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* TestDataLogging_COMMON_INCLUDES_ */

#include "TestDataLogging_types.h"

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

/* Block signals (default storage) */
typedef struct {
  real_T TmpSignalConversionAtToWork[15];
  real_T Integrator1;                  /* '<S1>/Integrator1' */
  real_T Integrator3;                  /* '<S1>/Integrator3' */
  real_T DataTypeConversion8;          /* '<S1>/Data Type Conversion8' */
  real_T DataTypeConversion3;          /* '<S1>/Data Type Conversion3' */
  real_T DataTypeConversion4;          /* '<S1>/Data Type Conversion4' */
  real_T DataTypeConversion5;          /* '<S1>/Data Type Conversion5' */
  real_T DataTypeConversion;           /* '<S1>/Data Type Conversion' */
  real_T DataTypeConversion1;          /* '<S1>/Data Type Conversion1' */
  real_T DataTypeConversion2;          /* '<S1>/Data Type Conversion2' */
  real_T Integrator6;                  /* '<S1>/Integrator6' */
  real_T Integrator7;                  /* '<S1>/Integrator7' */
  real_T Integrator8;                  /* '<S1>/Integrator8' */
  real_T DataTypeConversion6;          /* '<S1>/Data Type Conversion6' */
  real_T DataTypeConversion7;          /* '<S1>/Data Type Conversion7' */
  real_T Integrator11;                 /* '<S1>/Integrator11' */
  real_T Integrator;                   /* '<S1>/Integrator' */
  real_T Integrator2;                  /* '<S1>/Integrator2' */
} B_TestDataLogging_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S1>/To Workspace' */

  int32_T clockTickCounter;            /* '<S1>/Pulse Generator1' */
  int32_T clockTickCounter_h;          /* '<S1>/Pulse Generator3' */
  int32_T clockTickCounter_a;          /* '<S1>/Pulse Generator4' */
  int32_T clockTickCounter_n;          /* '<S1>/Pulse Generator2' */
} DW_TestDataLogging_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator3_CSTATE;           /* '<S1>/Integrator3' */
  real_T Integrator6_CSTATE;           /* '<S1>/Integrator6' */
  real_T Integrator7_CSTATE;           /* '<S1>/Integrator7' */
  real_T Integrator8_CSTATE;           /* '<S1>/Integrator8' */
  real_T Integrator11_CSTATE;          /* '<S1>/Integrator11' */
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<S1>/Integrator2' */
} X_TestDataLogging_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator3_CSTATE;           /* '<S1>/Integrator3' */
  real_T Integrator6_CSTATE;           /* '<S1>/Integrator6' */
  real_T Integrator7_CSTATE;           /* '<S1>/Integrator7' */
  real_T Integrator8_CSTATE;           /* '<S1>/Integrator8' */
  real_T Integrator11_CSTATE;          /* '<S1>/Integrator11' */
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<S1>/Integrator2' */
} XDot_TestDataLogging_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S1>/Integrator1' */
  boolean_T Integrator3_CSTATE;        /* '<S1>/Integrator3' */
  boolean_T Integrator6_CSTATE;        /* '<S1>/Integrator6' */
  boolean_T Integrator7_CSTATE;        /* '<S1>/Integrator7' */
  boolean_T Integrator8_CSTATE;        /* '<S1>/Integrator8' */
  boolean_T Integrator11_CSTATE;       /* '<S1>/Integrator11' */
  boolean_T Integrator_CSTATE;         /* '<S1>/Integrator' */
  boolean_T Integrator2_CSTATE;        /* '<S1>/Integrator2' */
} XDis_TestDataLogging_T;

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
} ExtY_TestDataLogging_T;

/* Parameters (default storage) */
struct P_TestDataLogging_T_ {
  real_T PulseGenerator1_Amp;          /* Expression: 400
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;       /* Expression: 1600
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty;         /* Expression: 400
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  real_T PulseGenerator3_Amp;          /* Expression: 400
                                        * Referenced by: '<S1>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_Period;       /* Expression: 1600
                                        * Referenced by: '<S1>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_Duty;         /* Expression: 400
                                        * Referenced by: '<S1>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_PhaseDelay;   /* Expression: 400
                                        * Referenced by: '<S1>/Pulse Generator3'
                                        */
  real_T PulseGenerator4_Amp;          /* Expression: 400
                                        * Referenced by: '<S1>/Pulse Generator4'
                                        */
  real_T PulseGenerator4_Period;       /* Expression: 1600
                                        * Referenced by: '<S1>/Pulse Generator4'
                                        */
  real_T PulseGenerator4_Duty;         /* Expression: 400
                                        * Referenced by: '<S1>/Pulse Generator4'
                                        */
  real_T PulseGenerator4_PhaseDelay;   /* Expression: 800
                                        * Referenced by: '<S1>/Pulse Generator4'
                                        */
  real_T PulseGenerator2_Amp;          /* Expression: 400
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Period;       /* Expression: 1600
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Duty;         /* Expression: 400
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_PhaseDelay;   /* Expression: 1200
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator3'
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
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator2'
                                        */
  real32_T Saturation1_UpperSat;     /* Computed Parameter: Saturation1_UpperSat
                                      * Referenced by: '<S1>/Saturation1'
                                      */
  real32_T Saturation1_LowerSat;     /* Computed Parameter: Saturation1_LowerSat
                                      * Referenced by: '<S1>/Saturation1'
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
};

/* Real-time Model Data Structure */
struct tag_RTM_TestDataLogging_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_TestDataLogging_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[8];
  real_T odeF[3][8];
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
extern P_TestDataLogging_T TestDataLogging_P;

/* Block signals (default storage) */
extern B_TestDataLogging_T TestDataLogging_B;

/* Continuous states (default storage) */
extern X_TestDataLogging_T TestDataLogging_X;

/* Block states (default storage) */
extern DW_TestDataLogging_T TestDataLogging_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_TestDataLogging_T TestDataLogging_Y;

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
extern void TestDataLogging_initialize(void);
extern void TestDataLogging_step(void);
extern void TestDataLogging_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TestDataLogging_T *const TestDataLogging_M;

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
 * '<Root>' : 'TestDataLogging'
 * '<S1>'   : 'TestDataLogging/Flight Control System'
 * '<S2>'   : 'TestDataLogging/Flight Control System/Subsystem'
 */
#endif                                 /* RTW_HEADER_TestDataLogging_h_ */

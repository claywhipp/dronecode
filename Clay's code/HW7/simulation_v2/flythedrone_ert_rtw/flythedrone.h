/*
 * flythedrone.h
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

#ifndef RTW_HEADER_flythedrone_h_
#define RTW_HEADER_flythedrone_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include <float.h>
#ifndef flythedrone_COMMON_INCLUDES_
# define flythedrone_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* flythedrone_COMMON_INCLUDES_ */

#include "flythedrone_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
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
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block signals for system '<S32>/MeasurementUpdate' */
typedef struct {
  real_T Product3;                     /* '<S61>/Product3' */
} B_MeasurementUpdate_flythedro_T;

/* Block states (default storage) for system '<S32>/MeasurementUpdate' */
typedef struct {
  boolean_T MeasurementUpdate_MODE;    /* '<S32>/MeasurementUpdate' */
} DW_MeasurementUpdate_flythedr_T;

/* Block signals for system '<S39>/Enabled Subsystem' */
typedef struct {
  real_T Product2;                     /* '<S63>/Product2' */
} B_EnabledSubsystem_flythedron_T;

/* Block states (default storage) for system '<S39>/Enabled Subsystem' */
typedef struct {
  boolean_T EnabledSubsystem_MODE;     /* '<S39>/Enabled Subsystem' */
} DW_EnabledSubsystem_flythedro_T;

/* Block signals (default storage) */
typedef struct {
  real_T Sum2[3];                      /* '<S2>/Sum2' */
  real_T Sum3[3];                      /* '<S2>/Sum3' */
  real_T Product2[2];                  /* '<S271>/Product2' */
  real_T Product3[2];                  /* '<S269>/Product3' */
  real_T Akxhatkk1[2];                 /* '<S240>/A[k]*xhat[k|k-1]' */
  real_T theta;                        /* '<S3>/Divide2' */
  real_T phi;                          /* '<S3>/Divide3' */
  real_T h_corrected;                  /* '<S1>/Corrects sudden jumps' */
  B_EnabledSubsystem_flythedron_T EnabledSubsystem_k;/* '<S195>/Enabled Subsystem' */
  B_MeasurementUpdate_flythedro_T MeasurementUpdate_ce;/* '<S188>/MeasurementUpdate' */
  B_EnabledSubsystem_flythedron_T EnabledSubsystem_i;/* '<S143>/Enabled Subsystem' */
  B_MeasurementUpdate_flythedro_T MeasurementUpdate_h;/* '<S136>/MeasurementUpdate' */
  B_EnabledSubsystem_flythedron_T EnabledSubsystem_g;/* '<S91>/Enabled Subsystem' */
  B_MeasurementUpdate_flythedro_T MeasurementUpdate_c;/* '<S84>/MeasurementUpdate' */
  B_EnabledSubsystem_flythedron_T EnabledSubsystem;/* '<S39>/Enabled Subsystem' */
  B_MeasurementUpdate_flythedro_T MeasurementUpdate;/* '<S32>/MeasurementUpdate' */
} B_flythedrone_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T MemoryX_DSTATE[2];            /* '<S11>/MemoryX' */
  real_T MemoryX_DSTATE_j;             /* '<S9>/MemoryX' */
  real_T MemoryX_DSTATE_g;             /* '<S8>/MemoryX' */
  real_T MemoryX_DSTATE_c;             /* '<S10>/MemoryX' */
  real_T MemoryX_DSTATE_a;             /* '<S7>/MemoryX' */
  real_T Memory_PreviousInput;         /* '<S1>/Memory' */
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S1>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<S2>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<S2>/To Workspace2' */

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK;                /* '<S2>/To Workspace3' */

  struct {
    void *LoggedData;
  } ToWorkspace6_PWORK;                /* '<S2>/To Workspace6' */

  uint8_T icLoad;                      /* '<S11>/MemoryX' */
  uint8_T icLoad_e;                    /* '<S9>/MemoryX' */
  uint8_T icLoad_i;                    /* '<S8>/MemoryX' */
  uint8_T icLoad_j;                    /* '<S10>/MemoryX' */
  uint8_T icLoad_k;                    /* '<S7>/MemoryX' */
  boolean_T EnabledSubsystem_MODE;     /* '<S247>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S240>/MeasurementUpdate' */
  DW_EnabledSubsystem_flythedro_T EnabledSubsystem_k;/* '<S195>/Enabled Subsystem' */
  DW_MeasurementUpdate_flythedr_T MeasurementUpdate_ce;/* '<S188>/MeasurementUpdate' */
  DW_EnabledSubsystem_flythedro_T EnabledSubsystem_i;/* '<S143>/Enabled Subsystem' */
  DW_MeasurementUpdate_flythedr_T MeasurementUpdate_h;/* '<S136>/MeasurementUpdate' */
  DW_EnabledSubsystem_flythedro_T EnabledSubsystem_g;/* '<S91>/Enabled Subsystem' */
  DW_MeasurementUpdate_flythedr_T MeasurementUpdate_c;/* '<S84>/MeasurementUpdate' */
  DW_EnabledSubsystem_flythedro_T EnabledSubsystem;/* '<S39>/Enabled Subsystem' */
  DW_MeasurementUpdate_flythedr_T MeasurementUpdate;/* '<S32>/MeasurementUpdate' */
} DW_flythedrone_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Motors[4];                  /* '<Root>/Motors' */
  uint8_T Flag;                        /* '<Root>/Flag' */
} ExtY_flythedrone_T;

/* Parameters for system: '<S32>/MeasurementUpdate' */
struct P_MeasurementUpdate_flythedro_T_ {
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S61>/L*(y[k]-yhat[k|k-1])'
                                        */
};

/* Parameters for system: '<S39>/Enabled Subsystem' */
struct P_EnabledSubsystem_flythedron_T_ {
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S63>/deltax'
                                        */
};

/* Parameters (default storage) */
struct P_flythedrone_T_ {
  real_T Kaileron[3];                  /* Variable: Kaileron
                                        * Referenced by: '<S2>/controller gain1'
                                        */
  real_T Kelevator[3];                 /* Variable: Kelevator
                                        * Referenced by: '<S2>/controller gain'
                                        */
  real_T Krudder;                      /* Variable: Krudder
                                        * Referenced by: '<S2>/controller gain2'
                                        */
  real_T Kthrust[2];                   /* Variable: Kthrust
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T M_motor[16];                  /* Variable: M_motor
                                        * Referenced by: '<S5>/Convert fom TEAR to n1,..,n4'
                                        */
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S269>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S271>/deltax'
                                        */
  real_T desiredTstates_Value[2];      /* Expression: [-1.5; 0]
                                        * Referenced by: '<S2>/desired T states'
                                        */
  real_T KalmanGainM_Value[2];         /* Expression: pInitialization.M
                                        * Referenced by: '<S220>/KalmanGainM'
                                        */
  real_T C_Value[2];                   /* Expression: pInitialization.C
                                        * Referenced by: '<S11>/C'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T X0_Value[2];                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S11>/X0'
                                        */
  real_T KalmanGainM_Value_b;          /* Expression: pInitialization.M
                                        * Referenced by: '<S116>/KalmanGainM'
                                        */
  real_T C_Value_f;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S9>/C'
                                        */
  real_T X0_Value_g;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S9>/X0'
                                        */
  real_T KalmanGainM_Value_g;          /* Expression: pInitialization.M
                                        * Referenced by: '<S64>/KalmanGainM'
                                        */
  real_T C_Value_c;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S8>/C'
                                        */
  real_T Constant_Value;               /* Expression: 9.81
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T X0_Value_p;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S8>/X0'
                                        */
  real_T KalmanGainM_Value_d;          /* Expression: pInitialization.M
                                        * Referenced by: '<S168>/KalmanGainM'
                                        */
  real_T C_Value_i;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S10>/C'
                                        */
  real_T X0_Value_b;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S10>/X0'
                                        */
  real_T KalmanGainM_Value_c;          /* Expression: pInitialization.M
                                        * Referenced by: '<S12>/KalmanGainM'
                                        */
  real_T C_Value_p;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S7>/C'
                                        */
  real_T Constant1_Value;              /* Expression: -9.81
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T X0_Value_k;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S7>/X0'
                                        */
  real_T Constant6_Value;              /* Expression: -9.4351
                                        * Referenced by: '<S3>/Constant6'
                                        */
  real_T A_Value[4];                   /* Expression: pInitialization.A
                                        * Referenced by: '<S11>/A'
                                        */
  real_T B_Value[2];                   /* Expression: pInitialization.B
                                        * Referenced by: '<S11>/B'
                                        */
  real_T KalmanGainL_Value[2];         /* Expression: pInitialization.L
                                        * Referenced by: '<S220>/KalmanGainL'
                                        */
  real_T D_Value;                      /* Expression: pInitialization.D
                                        * Referenced by: '<S11>/D'
                                        */
  real_T A_Value_j;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S8>/A'
                                        */
  real_T B_Value_k;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S8>/B'
                                        */
  real_T KalmanGainL_Value_c;          /* Expression: pInitialization.L
                                        * Referenced by: '<S64>/KalmanGainL'
                                        */
  real_T D_Value_h;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S8>/D'
                                        */
  real_T A_Value_i;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S9>/A'
                                        */
  real_T B_Value_o;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S9>/B'
                                        */
  real_T KalmanGainL_Value_l;          /* Expression: pInitialization.L
                                        * Referenced by: '<S116>/KalmanGainL'
                                        */
  real_T D_Value_m;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S9>/D'
                                        */
  real_T A_Value_m;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S7>/A'
                                        */
  real_T B_Value_o0;                   /* Expression: pInitialization.B
                                        * Referenced by: '<S7>/B'
                                        */
  real_T KalmanGainL_Value_k;          /* Expression: pInitialization.L
                                        * Referenced by: '<S12>/KalmanGainL'
                                        */
  real_T D_Value_o;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S7>/D'
                                        */
  real_T A_Value_o;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S10>/A'
                                        */
  real_T B_Value_g;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S10>/B'
                                        */
  real_T KalmanGainL_Value_e;          /* Expression: pInitialization.L
                                        * Referenced by: '<S168>/KalmanGainL'
                                        */
  real_T D_Value_f;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S10>/D'
                                        */
  boolean_T Enable_Value;              /* Expression: true()
                                        * Referenced by: '<S11>/Enable'
                                        */
  boolean_T Enable_Value_k;            /* Expression: true()
                                        * Referenced by: '<S9>/Enable'
                                        */
  boolean_T Enable_Value_e;            /* Expression: true()
                                        * Referenced by: '<S8>/Enable'
                                        */
  boolean_T Enable_Value_l;            /* Expression: true()
                                        * Referenced by: '<S10>/Enable'
                                        */
  boolean_T Enable_Value_d;            /* Expression: true()
                                        * Referenced by: '<S7>/Enable'
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
  P_EnabledSubsystem_flythedron_T EnabledSubsystem_k;/* '<S195>/Enabled Subsystem' */
  P_MeasurementUpdate_flythedro_T MeasurementUpdate_ce;/* '<S188>/MeasurementUpdate' */
  P_EnabledSubsystem_flythedron_T EnabledSubsystem_i;/* '<S143>/Enabled Subsystem' */
  P_MeasurementUpdate_flythedro_T MeasurementUpdate_h;/* '<S136>/MeasurementUpdate' */
  P_EnabledSubsystem_flythedron_T EnabledSubsystem_g;/* '<S91>/Enabled Subsystem' */
  P_MeasurementUpdate_flythedro_T MeasurementUpdate_c;/* '<S84>/MeasurementUpdate' */
  P_EnabledSubsystem_flythedron_T EnabledSubsystem;/* '<S39>/Enabled Subsystem' */
  P_MeasurementUpdate_flythedro_T MeasurementUpdate;/* '<S32>/MeasurementUpdate' */
};

/* Real-time Model Data Structure */
struct tag_RTM_flythedrone_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_flythedrone_T flythedrone_P;

/* Block signals (default storage) */
extern B_flythedrone_T flythedrone_B;

/* Block states (default storage) */
extern DW_flythedrone_T flythedrone_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_flythedrone_T flythedrone_Y;

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
extern real32_T motors_outport[4];     /* '<S5>/Cast To Single' */
extern uint8_T flag_outport;           /* '<S1>/Manual Switch' */

/* Model entry point functions */
extern void flythedrone_initialize(void);
extern void flythedrone_step(void);
extern void flythedrone_terminate(void);

/* Real-time Model object */
extern RT_MODEL_flythedrone_T *const flythedrone_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
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
 * Block '<S7>/G' : Unused code path elimination
 * Block '<S7>/H' : Unused code path elimination
 * Block '<S7>/N' : Unused code path elimination
 * Block '<S7>/P0' : Unused code path elimination
 * Block '<S7>/Q' : Unused code path elimination
 * Block '<S7>/R' : Unused code path elimination
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
 * Block '<S8>/G' : Unused code path elimination
 * Block '<S8>/H' : Unused code path elimination
 * Block '<S8>/N' : Unused code path elimination
 * Block '<S8>/P0' : Unused code path elimination
 * Block '<S8>/Q' : Unused code path elimination
 * Block '<S8>/R' : Unused code path elimination
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
 * Block '<S9>/G' : Unused code path elimination
 * Block '<S9>/H' : Unused code path elimination
 * Block '<S9>/N' : Unused code path elimination
 * Block '<S9>/P0' : Unused code path elimination
 * Block '<S9>/Q' : Unused code path elimination
 * Block '<S9>/R' : Unused code path elimination
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
 * Block '<S10>/G' : Unused code path elimination
 * Block '<S10>/H' : Unused code path elimination
 * Block '<S10>/N' : Unused code path elimination
 * Block '<S10>/P0' : Unused code path elimination
 * Block '<S10>/Q' : Unused code path elimination
 * Block '<S10>/R' : Unused code path elimination
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
 * Block '<S11>/G' : Unused code path elimination
 * Block '<S11>/H' : Unused code path elimination
 * Block '<S11>/N' : Unused code path elimination
 * Block '<S11>/P0' : Unused code path elimination
 * Block '<S11>/Q' : Unused code path elimination
 * Block '<S11>/R' : Unused code path elimination
 * Block '<S261>/CheckSignalProperties' : Unused code path elimination
 * Block '<S262>/CheckSignalProperties' : Unused code path elimination
 * Block '<S1>/Data Type Conversion10' : Unused code path elimination
 * Block '<S1>/X' : Unused code path elimination
 * Block '<S1>/Y' : Unused code path elimination
 * Block '<S1>/psi' : Unused code path elimination
 * Block '<S3>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition10' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition11' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition12' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition13' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition5' : Eliminated since input and output rates are identical
 * Block '<S55>/Conversion' : Eliminate redundant data type conversion
 * Block '<S56>/Conversion' : Eliminate redundant data type conversion
 * Block '<S28>/Conversion' : Eliminate redundant data type conversion
 * Block '<S32>/Reshape' : Reshape block reduction
 * Block '<S7>/ReshapeX0' : Reshape block reduction
 * Block '<S7>/Reshapeu' : Reshape block reduction
 * Block '<S7>/Reshapexhat' : Reshape block reduction
 * Block '<S7>/Reshapey' : Reshape block reduction
 * Block '<S107>/Conversion' : Eliminate redundant data type conversion
 * Block '<S108>/Conversion' : Eliminate redundant data type conversion
 * Block '<S80>/Conversion' : Eliminate redundant data type conversion
 * Block '<S84>/Reshape' : Reshape block reduction
 * Block '<S8>/ReshapeX0' : Reshape block reduction
 * Block '<S8>/Reshapeu' : Reshape block reduction
 * Block '<S8>/Reshapexhat' : Reshape block reduction
 * Block '<S8>/Reshapey' : Reshape block reduction
 * Block '<S159>/Conversion' : Eliminate redundant data type conversion
 * Block '<S160>/Conversion' : Eliminate redundant data type conversion
 * Block '<S132>/Conversion' : Eliminate redundant data type conversion
 * Block '<S136>/Reshape' : Reshape block reduction
 * Block '<S9>/ReshapeX0' : Reshape block reduction
 * Block '<S9>/Reshapeu' : Reshape block reduction
 * Block '<S9>/Reshapexhat' : Reshape block reduction
 * Block '<S9>/Reshapey' : Reshape block reduction
 * Block '<S211>/Conversion' : Eliminate redundant data type conversion
 * Block '<S212>/Conversion' : Eliminate redundant data type conversion
 * Block '<S184>/Conversion' : Eliminate redundant data type conversion
 * Block '<S188>/Reshape' : Reshape block reduction
 * Block '<S10>/ReshapeX0' : Reshape block reduction
 * Block '<S10>/Reshapeu' : Reshape block reduction
 * Block '<S10>/Reshapexhat' : Reshape block reduction
 * Block '<S10>/Reshapey' : Reshape block reduction
 * Block '<S263>/Conversion' : Eliminate redundant data type conversion
 * Block '<S264>/Conversion' : Eliminate redundant data type conversion
 * Block '<S236>/Conversion' : Eliminate redundant data type conversion
 * Block '<S240>/Reshape' : Reshape block reduction
 * Block '<S11>/ReshapeX0' : Reshape block reduction
 * Block '<S11>/Reshapeu' : Reshape block reduction
 * Block '<S11>/Reshapexhat' : Reshape block reduction
 * Block '<S11>/Reshapey' : Reshape block reduction
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
 * '<Root>' : 'flythedrone'
 * '<S1>'   : 'flythedrone/Flight Control System'
 * '<S2>'   : 'flythedrone/Flight Control System/Clay's Controller'
 * '<S3>'   : 'flythedrone/Flight Control System/Clay's Kalman Filters'
 * '<S4>'   : 'flythedrone/Flight Control System/Corrects sudden jumps'
 * '<S5>'   : 'flythedrone/Flight Control System/Motor mixing  (TEAR to n1,...,n4)'
 * '<S6>'   : 'flythedrone/Flight Control System/Subsystem'
 * '<S7>'   : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1'
 * '<S8>'   : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1'
 * '<S9>'   : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter'
 * '<S10>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter'
 * '<S11>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter'
 * '<S12>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/CalculatePL'
 * '<S13>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/CalculateYhat'
 * '<S14>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/CovarianceOutputConfigurator'
 * '<S15>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionA'
 * '<S16>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionB'
 * '<S17>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionC'
 * '<S18>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionD'
 * '<S19>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionEnable'
 * '<S20>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionG'
 * '<S21>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionH'
 * '<S22>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionN'
 * '<S23>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionP'
 * '<S24>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionP0'
 * '<S25>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionQ'
 * '<S26>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionR'
 * '<S27>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionReset'
 * '<S28>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionX'
 * '<S29>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionX0'
 * '<S30>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/DataTypeConversionu'
 * '<S31>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/MemoryP'
 * '<S32>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/Observer'
 * '<S33>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/ReducedQRN'
 * '<S34>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/Reset'
 * '<S35>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/Reshapeyhat'
 * '<S36>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/ScalarExpansionP0'
 * '<S37>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/ScalarExpansionQ'
 * '<S38>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/ScalarExpansionR'
 * '<S39>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/UseCurrentEstimator'
 * '<S40>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/checkA'
 * '<S41>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/checkB'
 * '<S42>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/checkC'
 * '<S43>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/checkD'
 * '<S44>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/checkEnable'
 * '<S45>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/checkG'
 * '<S46>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/checkH'
 * '<S47>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/checkN'
 * '<S48>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/checkP0'
 * '<S49>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/checkQ'
 * '<S50>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/checkR'
 * '<S51>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/checkReset'
 * '<S52>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/checkX0'
 * '<S53>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/checku'
 * '<S54>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/checky'
 * '<S55>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/CalculatePL/DataTypeConversionL'
 * '<S56>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/CalculatePL/DataTypeConversionM'
 * '<S57>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/CalculatePL/DataTypeConversionP'
 * '<S58>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/CalculatePL/DataTypeConversionZ'
 * '<S59>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/CalculatePL/Ground'
 * '<S60>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/CalculateYhat/Ground'
 * '<S61>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/Observer/MeasurementUpdate'
 * '<S62>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/ReducedQRN/Ground'
 * '<S63>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/phi Kalman filter1/UseCurrentEstimator/Enabled Subsystem'
 * '<S64>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/CalculatePL'
 * '<S65>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/CalculateYhat'
 * '<S66>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/CovarianceOutputConfigurator'
 * '<S67>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionA'
 * '<S68>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionB'
 * '<S69>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionC'
 * '<S70>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionD'
 * '<S71>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionEnable'
 * '<S72>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionG'
 * '<S73>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionH'
 * '<S74>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionN'
 * '<S75>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionP'
 * '<S76>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionP0'
 * '<S77>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionQ'
 * '<S78>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionR'
 * '<S79>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionReset'
 * '<S80>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionX'
 * '<S81>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionX0'
 * '<S82>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/DataTypeConversionu'
 * '<S83>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/MemoryP'
 * '<S84>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/Observer'
 * '<S85>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/ReducedQRN'
 * '<S86>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/Reset'
 * '<S87>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/Reshapeyhat'
 * '<S88>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/ScalarExpansionP0'
 * '<S89>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/ScalarExpansionQ'
 * '<S90>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/ScalarExpansionR'
 * '<S91>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/UseCurrentEstimator'
 * '<S92>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/checkA'
 * '<S93>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/checkB'
 * '<S94>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/checkC'
 * '<S95>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/checkD'
 * '<S96>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/checkEnable'
 * '<S97>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/checkG'
 * '<S98>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/checkH'
 * '<S99>'  : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/checkN'
 * '<S100>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/checkP0'
 * '<S101>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/checkQ'
 * '<S102>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/checkR'
 * '<S103>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/checkReset'
 * '<S104>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/checkX0'
 * '<S105>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/checku'
 * '<S106>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/checky'
 * '<S107>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/CalculatePL/DataTypeConversionL'
 * '<S108>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/CalculatePL/DataTypeConversionM'
 * '<S109>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/CalculatePL/DataTypeConversionP'
 * '<S110>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/CalculatePL/DataTypeConversionZ'
 * '<S111>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/CalculatePL/Ground'
 * '<S112>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/CalculateYhat/Ground'
 * '<S113>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/Observer/MeasurementUpdate'
 * '<S114>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/ReducedQRN/Ground'
 * '<S115>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/theta Kalman filter1/UseCurrentEstimator/Enabled Subsystem'
 * '<S116>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/CalculatePL'
 * '<S117>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/CalculateYhat'
 * '<S118>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/CovarianceOutputConfigurator'
 * '<S119>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionA'
 * '<S120>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionB'
 * '<S121>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionC'
 * '<S122>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionD'
 * '<S123>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionEnable'
 * '<S124>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionG'
 * '<S125>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionH'
 * '<S126>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionN'
 * '<S127>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionP'
 * '<S128>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionP0'
 * '<S129>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionQ'
 * '<S130>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionR'
 * '<S131>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionReset'
 * '<S132>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionX'
 * '<S133>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionX0'
 * '<S134>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/DataTypeConversionu'
 * '<S135>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/MemoryP'
 * '<S136>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/Observer'
 * '<S137>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/ReducedQRN'
 * '<S138>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/Reset'
 * '<S139>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/Reshapeyhat'
 * '<S140>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/ScalarExpansionP0'
 * '<S141>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/ScalarExpansionQ'
 * '<S142>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/ScalarExpansionR'
 * '<S143>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/UseCurrentEstimator'
 * '<S144>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/checkA'
 * '<S145>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/checkB'
 * '<S146>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/checkC'
 * '<S147>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/checkD'
 * '<S148>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/checkEnable'
 * '<S149>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/checkG'
 * '<S150>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/checkH'
 * '<S151>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/checkN'
 * '<S152>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/checkP0'
 * '<S153>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/checkQ'
 * '<S154>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/checkR'
 * '<S155>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/checkReset'
 * '<S156>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/checkX0'
 * '<S157>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/checku'
 * '<S158>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/checky'
 * '<S159>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S160>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S161>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S162>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S163>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/CalculatePL/Ground'
 * '<S164>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/CalculateYhat/Ground'
 * '<S165>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/Observer/MeasurementUpdate'
 * '<S166>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/ReducedQRN/Ground'
 * '<S167>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/u Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S168>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/CalculatePL'
 * '<S169>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/CalculateYhat'
 * '<S170>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/CovarianceOutputConfigurator'
 * '<S171>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionA'
 * '<S172>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionB'
 * '<S173>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionC'
 * '<S174>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionD'
 * '<S175>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionEnable'
 * '<S176>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionG'
 * '<S177>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionH'
 * '<S178>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionN'
 * '<S179>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionP'
 * '<S180>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionP0'
 * '<S181>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionQ'
 * '<S182>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionR'
 * '<S183>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionReset'
 * '<S184>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionX'
 * '<S185>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionX0'
 * '<S186>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/DataTypeConversionu'
 * '<S187>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/MemoryP'
 * '<S188>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/Observer'
 * '<S189>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/ReducedQRN'
 * '<S190>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/Reset'
 * '<S191>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/Reshapeyhat'
 * '<S192>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/ScalarExpansionP0'
 * '<S193>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/ScalarExpansionQ'
 * '<S194>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/ScalarExpansionR'
 * '<S195>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/UseCurrentEstimator'
 * '<S196>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/checkA'
 * '<S197>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/checkB'
 * '<S198>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/checkC'
 * '<S199>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/checkD'
 * '<S200>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/checkEnable'
 * '<S201>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/checkG'
 * '<S202>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/checkH'
 * '<S203>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/checkN'
 * '<S204>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/checkP0'
 * '<S205>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/checkQ'
 * '<S206>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/checkR'
 * '<S207>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/checkReset'
 * '<S208>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/checkX0'
 * '<S209>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/checku'
 * '<S210>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/checky'
 * '<S211>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/CalculatePL/DataTypeConversionL'
 * '<S212>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/CalculatePL/DataTypeConversionM'
 * '<S213>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/CalculatePL/DataTypeConversionP'
 * '<S214>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/CalculatePL/DataTypeConversionZ'
 * '<S215>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/CalculatePL/Ground'
 * '<S216>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/CalculateYhat/Ground'
 * '<S217>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/Observer/MeasurementUpdate'
 * '<S218>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/ReducedQRN/Ground'
 * '<S219>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/v Kalman filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S220>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/CalculatePL'
 * '<S221>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/CalculateYhat'
 * '<S222>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/CovarianceOutputConfigurator'
 * '<S223>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionA'
 * '<S224>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionB'
 * '<S225>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionC'
 * '<S226>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionD'
 * '<S227>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionEnable'
 * '<S228>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionG'
 * '<S229>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionH'
 * '<S230>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionN'
 * '<S231>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionP'
 * '<S232>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionP0'
 * '<S233>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionQ'
 * '<S234>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionR'
 * '<S235>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionReset'
 * '<S236>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionX'
 * '<S237>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionX0'
 * '<S238>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/DataTypeConversionu'
 * '<S239>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/MemoryP'
 * '<S240>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/Observer'
 * '<S241>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/ReducedQRN'
 * '<S242>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/Reset'
 * '<S243>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/Reshapeyhat'
 * '<S244>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/ScalarExpansionP0'
 * '<S245>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/ScalarExpansionQ'
 * '<S246>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/ScalarExpansionR'
 * '<S247>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/UseCurrentEstimator'
 * '<S248>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/checkA'
 * '<S249>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/checkB'
 * '<S250>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/checkC'
 * '<S251>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/checkD'
 * '<S252>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/checkEnable'
 * '<S253>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/checkG'
 * '<S254>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/checkH'
 * '<S255>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/checkN'
 * '<S256>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/checkP0'
 * '<S257>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/checkQ'
 * '<S258>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/checkR'
 * '<S259>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/checkReset'
 * '<S260>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/checkX0'
 * '<S261>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/checku'
 * '<S262>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/checky'
 * '<S263>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S264>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S265>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S266>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S267>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/CalculatePL/Ground'
 * '<S268>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/CalculateYhat/Ground'
 * '<S269>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/Observer/MeasurementUpdate'
 * '<S270>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/ReducedQRN/Ground'
 * '<S271>' : 'flythedrone/Flight Control System/Clay's Kalman Filters/zw Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 */
#endif                                 /* RTW_HEADER_flythedrone_h_ */

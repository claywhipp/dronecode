/*
 * ClayDataLogging.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ClayDataLogging".
 *
 * Model version              : 1.11
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Thu Feb 27 12:29:23 2020
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ClayDataLogging.h"
#include "ClayDataLogging_private.h"

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S1>/Saturation1' */
uint8_T flag_outport;                  /* '<S1>/Manual Switch' */

/* Block signals (default storage) */
B_ClayDataLogging_T ClayDataLogging_B;

/* Continuous states */
X_ClayDataLogging_T ClayDataLogging_X;

/* Block states (default storage) */
DW_ClayDataLogging_T ClayDataLogging_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_ClayDataLogging_T ClayDataLogging_Y;

/* Real-time model */
RT_MODEL_ClayDataLogging_T ClayDataLogging_M_;
RT_MODEL_ClayDataLogging_T *const ClayDataLogging_M = &ClayDataLogging_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ClayDataLogging_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ClayDataLogging_step();
  ClayDataLogging_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ClayDataLogging_step();
  ClayDataLogging_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void ClayDataLogging_step(void)
{
  if (rtmIsMajorTimeStep(ClayDataLogging_M)) {
    /* set solver stop time */
    if (!(ClayDataLogging_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ClayDataLogging_M->solverInfo,
                            ((ClayDataLogging_M->Timing.clockTickH0 + 1) *
        ClayDataLogging_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ClayDataLogging_M->solverInfo,
                            ((ClayDataLogging_M->Timing.clockTick0 + 1) *
        ClayDataLogging_M->Timing.stepSize0 +
        ClayDataLogging_M->Timing.clockTickH0 *
        ClayDataLogging_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ClayDataLogging_M)) {
    ClayDataLogging_M->Timing.t[0] = rtsiGetT(&ClayDataLogging_M->solverInfo);
  }

  /* Integrator: '<S1>/Integrator1' */
  ClayDataLogging_B.Xned = ClayDataLogging_X.Integrator1_CSTATE;

  /* Integrator: '<S1>/Integrator3' */
  ClayDataLogging_B.Yned = ClayDataLogging_X.Integrator3_CSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion8' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  ClayDataLogging_B.DataTypeConversion8 =
    sensor_inport.HALSensors.HAL_ultrasound_SI.altitude;

  /* DataTypeConversion: '<S1>/Data Type Conversion3' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  ClayDataLogging_B.DataTypeConversion3 = sensor_inport.HALSensors.HAL_gyro_SI.x;

  /* DataTypeConversion: '<S1>/Data Type Conversion4' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  ClayDataLogging_B.DataTypeConversion4 = sensor_inport.HALSensors.HAL_gyro_SI.y;

  /* DataTypeConversion: '<S1>/Data Type Conversion5' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  ClayDataLogging_B.DataTypeConversion5 = sensor_inport.HALSensors.HAL_gyro_SI.z;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  ClayDataLogging_B.DataTypeConversion = sensor_inport.HALSensors.HAL_acc_SI.x;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  ClayDataLogging_B.DataTypeConversion1 = sensor_inport.HALSensors.HAL_acc_SI.y;

  /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  ClayDataLogging_B.DataTypeConversion2 = sensor_inport.HALSensors.HAL_acc_SI.z;

  /* Integrator: '<S1>/Integrator6' */
  ClayDataLogging_B.phi = ClayDataLogging_X.Integrator6_CSTATE;

  /* Integrator: '<S1>/Integrator7' */
  ClayDataLogging_B.theta = ClayDataLogging_X.Integrator7_CSTATE;

  /* Integrator: '<S1>/Integrator8' */
  ClayDataLogging_B.psi = ClayDataLogging_X.Integrator8_CSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion6' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  ClayDataLogging_B.DataTypeConversion6 =
    sensor_inport.VisionSensors.opticalFlow_data[0];

  /* DataTypeConversion: '<S1>/Data Type Conversion7' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  ClayDataLogging_B.DataTypeConversion7 =
    sensor_inport.VisionSensors.opticalFlow_data[1];

  /* Integrator: '<S1>/Integrator11' */
  ClayDataLogging_B.Integrator11 = ClayDataLogging_X.Integrator11_CSTATE;
  if (rtmIsMajorTimeStep(ClayDataLogging_M)) {
    /* Saturate: '<S1>/Saturation1' incorporates:
     *  Constant: '<S1>/Constant'
     */
    if (ClayDataLogging_P.Constant_Value >
        ClayDataLogging_P.Saturation1_UpperSat) {
      motors_outport[0] = ClayDataLogging_P.Saturation1_UpperSat;
    } else if (ClayDataLogging_P.Constant_Value <
               ClayDataLogging_P.Saturation1_LowerSat) {
      motors_outport[0] = ClayDataLogging_P.Saturation1_LowerSat;
    } else {
      motors_outport[0] = (real32_T)ClayDataLogging_P.Constant_Value;
    }

    /* Outport: '<Root>/Motors' */
    ClayDataLogging_Y.Motors[0] = motors_outport[0];

    /* Saturate: '<S1>/Saturation1' incorporates:
     *  Constant: '<S1>/Constant5'
     */
    if (ClayDataLogging_P.Constant5_Value >
        ClayDataLogging_P.Saturation1_UpperSat) {
      motors_outport[1] = ClayDataLogging_P.Saturation1_UpperSat;
    } else if (ClayDataLogging_P.Constant5_Value <
               ClayDataLogging_P.Saturation1_LowerSat) {
      motors_outport[1] = ClayDataLogging_P.Saturation1_LowerSat;
    } else {
      motors_outport[1] = (real32_T)ClayDataLogging_P.Constant5_Value;
    }

    /* Outport: '<Root>/Motors' */
    ClayDataLogging_Y.Motors[1] = motors_outport[1];

    /* Saturate: '<S1>/Saturation1' incorporates:
     *  Constant: '<S1>/Constant3'
     */
    if (ClayDataLogging_P.Constant3_Value >
        ClayDataLogging_P.Saturation1_UpperSat) {
      motors_outport[2] = ClayDataLogging_P.Saturation1_UpperSat;
    } else if (ClayDataLogging_P.Constant3_Value <
               ClayDataLogging_P.Saturation1_LowerSat) {
      motors_outport[2] = ClayDataLogging_P.Saturation1_LowerSat;
    } else {
      motors_outport[2] = (real32_T)ClayDataLogging_P.Constant3_Value;
    }

    /* Outport: '<Root>/Motors' */
    ClayDataLogging_Y.Motors[2] = motors_outport[2];

    /* Saturate: '<S1>/Saturation1' incorporates:
     *  Constant: '<S1>/Constant4'
     */
    if (ClayDataLogging_P.Constant4_Value >
        ClayDataLogging_P.Saturation1_UpperSat) {
      motors_outport[3] = ClayDataLogging_P.Saturation1_UpperSat;
    } else if (ClayDataLogging_P.Constant4_Value <
               ClayDataLogging_P.Saturation1_LowerSat) {
      motors_outport[3] = ClayDataLogging_P.Saturation1_LowerSat;
    } else {
      motors_outport[3] = (real32_T)ClayDataLogging_P.Constant4_Value;
    }

    /* Outport: '<Root>/Motors' */
    ClayDataLogging_Y.Motors[3] = motors_outport[3];

    /* ManualSwitch: '<S1>/Manual Switch' incorporates:
     *  Constant: '<S1>/Constant1'
     *  Constant: '<S1>/Constant2'
     */
    if (ClayDataLogging_P.ManualSwitch_CurrentSetting == 1) {
      flag_outport = ClayDataLogging_P.Constant2_Value;
    } else {
      flag_outport = ClayDataLogging_P.Constant1_Value;
    }

    /* End of ManualSwitch: '<S1>/Manual Switch' */

    /* Outport: '<Root>/Flag' */
    ClayDataLogging_Y.Flag = flag_outport;

    /* SignalConversion generated from: '<S1>/To Workspace' */
    ClayDataLogging_B.TmpSignalConversionAtToWork[0] = ClayDataLogging_B.Xned;
    ClayDataLogging_B.TmpSignalConversionAtToWork[1] = ClayDataLogging_B.Yned;
    ClayDataLogging_B.TmpSignalConversionAtToWork[2] =
      ClayDataLogging_B.DataTypeConversion8;
    ClayDataLogging_B.TmpSignalConversionAtToWork[3] =
      ClayDataLogging_B.DataTypeConversion3;
    ClayDataLogging_B.TmpSignalConversionAtToWork[4] =
      ClayDataLogging_B.DataTypeConversion4;
    ClayDataLogging_B.TmpSignalConversionAtToWork[5] =
      ClayDataLogging_B.DataTypeConversion5;
    ClayDataLogging_B.TmpSignalConversionAtToWork[6] =
      ClayDataLogging_B.DataTypeConversion;
    ClayDataLogging_B.TmpSignalConversionAtToWork[7] =
      ClayDataLogging_B.DataTypeConversion1;
    ClayDataLogging_B.TmpSignalConversionAtToWork[8] =
      ClayDataLogging_B.DataTypeConversion2;
    ClayDataLogging_B.TmpSignalConversionAtToWork[9] = ClayDataLogging_B.phi;
    ClayDataLogging_B.TmpSignalConversionAtToWork[10] = ClayDataLogging_B.theta;
    ClayDataLogging_B.TmpSignalConversionAtToWork[11] = ClayDataLogging_B.psi;
    ClayDataLogging_B.TmpSignalConversionAtToWork[12] =
      ClayDataLogging_B.DataTypeConversion6;
    ClayDataLogging_B.TmpSignalConversionAtToWork[13] =
      ClayDataLogging_B.DataTypeConversion7;
    ClayDataLogging_B.TmpSignalConversionAtToWork[14] =
      ClayDataLogging_B.Integrator11;

    /* ToWorkspace: '<S1>/To Workspace' */
    {
      double locTime = (((ClayDataLogging_M->Timing.clockTick1+
                          ClayDataLogging_M->Timing.clockTickH1* 4294967296.0)) *
                        0.005);
      ;
      if (rtmIsMajorTimeStep(ClayDataLogging_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              ClayDataLogging_DW.ToWorkspace_PWORK.LoggedData,
                              &locTime,
                              &ClayDataLogging_B.TmpSignalConversionAtToWork[0]);
      }
    }
  }

  /* Integrator: '<S1>/Integrator' */
  ClayDataLogging_B.Integrator = ClayDataLogging_X.Integrator_CSTATE;

  /* Integrator: '<S1>/Integrator2' */
  ClayDataLogging_B.Integrator2 = ClayDataLogging_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(ClayDataLogging_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(ClayDataLogging_M->rtwLogInfo,
                        (ClayDataLogging_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(ClayDataLogging_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(ClayDataLogging_M)!=-1) &&
          !((rtmGetTFinal(ClayDataLogging_M)-
             (((ClayDataLogging_M->Timing.clockTick1+
                ClayDataLogging_M->Timing.clockTickH1* 4294967296.0)) * 0.005)) >
            (((ClayDataLogging_M->Timing.clockTick1+
               ClayDataLogging_M->Timing.clockTickH1* 4294967296.0)) * 0.005) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(ClayDataLogging_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&ClayDataLogging_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ClayDataLogging_M->Timing.clockTick0)) {
      ++ClayDataLogging_M->Timing.clockTickH0;
    }

    ClayDataLogging_M->Timing.t[0] = rtsiGetSolverStopTime
      (&ClayDataLogging_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      ClayDataLogging_M->Timing.clockTick1++;
      if (!ClayDataLogging_M->Timing.clockTick1) {
        ClayDataLogging_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void ClayDataLogging_derivatives(void)
{
  XDot_ClayDataLogging_T *_rtXdot;
  _rtXdot = ((XDot_ClayDataLogging_T *) ClayDataLogging_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = ClayDataLogging_B.Integrator;

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = ClayDataLogging_B.Integrator2;

  /* Derivatives for Integrator: '<S1>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = ClayDataLogging_B.DataTypeConversion3;

  /* Derivatives for Integrator: '<S1>/Integrator7' */
  _rtXdot->Integrator7_CSTATE = ClayDataLogging_B.DataTypeConversion4;

  /* Derivatives for Integrator: '<S1>/Integrator8' */
  _rtXdot->Integrator8_CSTATE = ClayDataLogging_B.DataTypeConversion5;

  /* Derivatives for Integrator: '<S1>/Integrator11' */
  _rtXdot->Integrator11_CSTATE = ClayDataLogging_B.DataTypeConversion2;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = ClayDataLogging_B.DataTypeConversion;

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = ClayDataLogging_B.DataTypeConversion1;
}

/* Model initialize function */
void ClayDataLogging_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ClayDataLogging_M, 0,
                sizeof(RT_MODEL_ClayDataLogging_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ClayDataLogging_M->solverInfo,
                          &ClayDataLogging_M->Timing.simTimeStep);
    rtsiSetTPtr(&ClayDataLogging_M->solverInfo, &rtmGetTPtr(ClayDataLogging_M));
    rtsiSetStepSizePtr(&ClayDataLogging_M->solverInfo,
                       &ClayDataLogging_M->Timing.stepSize0);
    rtsiSetdXPtr(&ClayDataLogging_M->solverInfo, &ClayDataLogging_M->derivs);
    rtsiSetContStatesPtr(&ClayDataLogging_M->solverInfo, (real_T **)
                         &ClayDataLogging_M->contStates);
    rtsiSetNumContStatesPtr(&ClayDataLogging_M->solverInfo,
      &ClayDataLogging_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ClayDataLogging_M->solverInfo,
      &ClayDataLogging_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ClayDataLogging_M->solverInfo,
      &ClayDataLogging_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ClayDataLogging_M->solverInfo,
      &ClayDataLogging_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ClayDataLogging_M->solverInfo, (&rtmGetErrorStatus
      (ClayDataLogging_M)));
    rtsiSetRTModelPtr(&ClayDataLogging_M->solverInfo, ClayDataLogging_M);
  }

  rtsiSetSimTimeStep(&ClayDataLogging_M->solverInfo, MAJOR_TIME_STEP);
  ClayDataLogging_M->intgData.y = ClayDataLogging_M->odeY;
  ClayDataLogging_M->intgData.f[0] = ClayDataLogging_M->odeF[0];
  ClayDataLogging_M->intgData.f[1] = ClayDataLogging_M->odeF[1];
  ClayDataLogging_M->intgData.f[2] = ClayDataLogging_M->odeF[2];
  ClayDataLogging_M->contStates = ((X_ClayDataLogging_T *) &ClayDataLogging_X);
  rtsiSetSolverData(&ClayDataLogging_M->solverInfo, (void *)
                    &ClayDataLogging_M->intgData);
  rtsiSetSolverName(&ClayDataLogging_M->solverInfo,"ode3");
  rtmSetTPtr(ClayDataLogging_M, &ClayDataLogging_M->Timing.tArray[0]);
  rtmSetTFinal(ClayDataLogging_M, 10.0);
  ClayDataLogging_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    ClayDataLogging_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ClayDataLogging_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ClayDataLogging_M->rtwLogInfo, (NULL));
    rtliSetLogT(ClayDataLogging_M->rtwLogInfo, "tout");
    rtliSetLogX(ClayDataLogging_M->rtwLogInfo, "");
    rtliSetLogXFinal(ClayDataLogging_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ClayDataLogging_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ClayDataLogging_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(ClayDataLogging_M->rtwLogInfo, 0);
    rtliSetLogDecimation(ClayDataLogging_M->rtwLogInfo, 1);
    rtliSetLogY(ClayDataLogging_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ClayDataLogging_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ClayDataLogging_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &ClayDataLogging_B), 0,
                sizeof(B_ClayDataLogging_T));

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* states (continuous) */
  {
    (void) memset((void *)&ClayDataLogging_X, 0,
                  sizeof(X_ClayDataLogging_T));
  }

  /* states (dwork) */
  (void) memset((void *)&ClayDataLogging_DW, 0,
                sizeof(DW_ClayDataLogging_T));

  /* external inputs */
  (void)memset(&cmd_inport, 0, sizeof(CommandBus));
  (void)memset(&sensor_inport, 0, sizeof(SensorsBus));

  /* external outputs */
  (void) memset((void *)&ClayDataLogging_Y, 0,
                sizeof(ExtY_ClayDataLogging_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(ClayDataLogging_M->rtwLogInfo, 0.0,
    rtmGetTFinal(ClayDataLogging_M), ClayDataLogging_M->Timing.stepSize0,
    (&rtmGetErrorStatus(ClayDataLogging_M)));

  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 15 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 15 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "ClayDataLogging/Flight Control System/To Workspace";
    ClayDataLogging_DW.ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      ClayDataLogging_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(ClayDataLogging_M),
      ClayDataLogging_M->Timing.stepSize0,
      (&rtmGetErrorStatus(ClayDataLogging_M)),
      "states",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (ClayDataLogging_DW.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  ClayDataLogging_X.Integrator1_CSTATE = ClayDataLogging_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  ClayDataLogging_X.Integrator3_CSTATE = ClayDataLogging_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator6' */
  ClayDataLogging_X.Integrator6_CSTATE = ClayDataLogging_P.Integrator6_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator7' */
  ClayDataLogging_X.Integrator7_CSTATE = ClayDataLogging_P.Integrator7_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator8' */
  ClayDataLogging_X.Integrator8_CSTATE = ClayDataLogging_P.Integrator8_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator11' */
  ClayDataLogging_X.Integrator11_CSTATE = ClayDataLogging_P.Integrator11_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  ClayDataLogging_X.Integrator_CSTATE = ClayDataLogging_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  ClayDataLogging_X.Integrator2_CSTATE = ClayDataLogging_P.Integrator2_IC;
}

/* Model terminate function */
void ClayDataLogging_terminate(void)
{
  /* (no terminate code required) */
}

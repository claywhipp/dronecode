/*
 * HW5_Simulink.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "HW5_Simulink".
 *
 * Model version              : 1.25
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Mar  4 14:06:23 2020
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HW5_Simulink.h"
#include "HW5_Simulink_private.h"

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S1>/Saturation1' */
uint8_T flag_outport;                  /* '<S1>/Manual Switch' */

/* Block signals (default storage) */
B_HW5_Simulink_T HW5_Simulink_B;

/* Continuous states */
X_HW5_Simulink_T HW5_Simulink_X;

/* Block states (default storage) */
DW_HW5_Simulink_T HW5_Simulink_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_HW5_Simulink_T HW5_Simulink_Y;

/* Real-time model */
RT_MODEL_HW5_Simulink_T HW5_Simulink_M_;
RT_MODEL_HW5_Simulink_T *const HW5_Simulink_M = &HW5_Simulink_M_;

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
  HW5_Simulink_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  HW5_Simulink_step();
  HW5_Simulink_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  HW5_Simulink_step();
  HW5_Simulink_derivatives();

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
void HW5_Simulink_step(void)
{
  if (rtmIsMajorTimeStep(HW5_Simulink_M)) {
    /* set solver stop time */
    if (!(HW5_Simulink_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&HW5_Simulink_M->solverInfo,
                            ((HW5_Simulink_M->Timing.clockTickH0 + 1) *
        HW5_Simulink_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&HW5_Simulink_M->solverInfo,
                            ((HW5_Simulink_M->Timing.clockTick0 + 1) *
        HW5_Simulink_M->Timing.stepSize0 + HW5_Simulink_M->Timing.clockTickH0 *
        HW5_Simulink_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(HW5_Simulink_M)) {
    HW5_Simulink_M->Timing.t[0] = rtsiGetT(&HW5_Simulink_M->solverInfo);
  }

  /* Integrator: '<S1>/Integrator1' */
  HW5_Simulink_B.Xned = HW5_Simulink_X.Integrator1_CSTATE;

  /* Integrator: '<S1>/Integrator3' */
  HW5_Simulink_B.Yned = HW5_Simulink_X.Integrator3_CSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion8' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW5_Simulink_B.DataTypeConversion8 =
    sensor_inport.HALSensors.HAL_ultrasound_SI.altitude;

  /* DataTypeConversion: '<S1>/Data Type Conversion3' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW5_Simulink_B.DataTypeConversion3 = sensor_inport.HALSensors.HAL_gyro_SI.x;

  /* DataTypeConversion: '<S1>/Data Type Conversion4' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW5_Simulink_B.DataTypeConversion4 = sensor_inport.HALSensors.HAL_gyro_SI.y;

  /* DataTypeConversion: '<S1>/Data Type Conversion5' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW5_Simulink_B.DataTypeConversion5 = sensor_inport.HALSensors.HAL_gyro_SI.z;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW5_Simulink_B.DataTypeConversion = sensor_inport.HALSensors.HAL_acc_SI.x;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW5_Simulink_B.DataTypeConversion1 = sensor_inport.HALSensors.HAL_acc_SI.y;

  /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW5_Simulink_B.DataTypeConversion2 = sensor_inport.HALSensors.HAL_acc_SI.z;

  /* Integrator: '<S1>/Integrator6' */
  HW5_Simulink_B.phi = HW5_Simulink_X.Integrator6_CSTATE;

  /* Integrator: '<S1>/Integrator7' */
  HW5_Simulink_B.theta = HW5_Simulink_X.Integrator7_CSTATE;

  /* Integrator: '<S1>/Integrator8' */
  HW5_Simulink_B.psi = HW5_Simulink_X.Integrator8_CSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion6' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW5_Simulink_B.DataTypeConversion6 =
    sensor_inport.VisionSensors.opticalFlow_data[0];

  /* DataTypeConversion: '<S1>/Data Type Conversion7' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW5_Simulink_B.DataTypeConversion7 =
    sensor_inport.VisionSensors.opticalFlow_data[1];

  /* Integrator: '<S1>/Integrator11' */
  HW5_Simulink_B.Integrator11 = HW5_Simulink_X.Integrator11_CSTATE;
  if (rtmIsMajorTimeStep(HW5_Simulink_M)) {
    /* Saturate: '<S1>/Saturation1' incorporates:
     *  Constant: '<S1>/Constant'
     */
    if (HW5_Simulink_P.Constant_Value > HW5_Simulink_P.Saturation1_UpperSat) {
      motors_outport[0] = HW5_Simulink_P.Saturation1_UpperSat;
    } else if (HW5_Simulink_P.Constant_Value <
               HW5_Simulink_P.Saturation1_LowerSat) {
      motors_outport[0] = HW5_Simulink_P.Saturation1_LowerSat;
    } else {
      motors_outport[0] = (real32_T)HW5_Simulink_P.Constant_Value;
    }

    /* Outport: '<Root>/Motors' */
    HW5_Simulink_Y.Motors[0] = motors_outport[0];

    /* Saturate: '<S1>/Saturation1' incorporates:
     *  Constant: '<S1>/Constant5'
     */
    if (HW5_Simulink_P.Constant5_Value > HW5_Simulink_P.Saturation1_UpperSat) {
      motors_outport[1] = HW5_Simulink_P.Saturation1_UpperSat;
    } else if (HW5_Simulink_P.Constant5_Value <
               HW5_Simulink_P.Saturation1_LowerSat) {
      motors_outport[1] = HW5_Simulink_P.Saturation1_LowerSat;
    } else {
      motors_outport[1] = (real32_T)HW5_Simulink_P.Constant5_Value;
    }

    /* Outport: '<Root>/Motors' */
    HW5_Simulink_Y.Motors[1] = motors_outport[1];

    /* Saturate: '<S1>/Saturation1' incorporates:
     *  Constant: '<S1>/Constant3'
     */
    if (HW5_Simulink_P.Constant3_Value > HW5_Simulink_P.Saturation1_UpperSat) {
      motors_outport[2] = HW5_Simulink_P.Saturation1_UpperSat;
    } else if (HW5_Simulink_P.Constant3_Value <
               HW5_Simulink_P.Saturation1_LowerSat) {
      motors_outport[2] = HW5_Simulink_P.Saturation1_LowerSat;
    } else {
      motors_outport[2] = (real32_T)HW5_Simulink_P.Constant3_Value;
    }

    /* Outport: '<Root>/Motors' */
    HW5_Simulink_Y.Motors[2] = motors_outport[2];

    /* Saturate: '<S1>/Saturation1' incorporates:
     *  Constant: '<S1>/Constant4'
     */
    if (HW5_Simulink_P.Constant4_Value > HW5_Simulink_P.Saturation1_UpperSat) {
      motors_outport[3] = HW5_Simulink_P.Saturation1_UpperSat;
    } else if (HW5_Simulink_P.Constant4_Value <
               HW5_Simulink_P.Saturation1_LowerSat) {
      motors_outport[3] = HW5_Simulink_P.Saturation1_LowerSat;
    } else {
      motors_outport[3] = (real32_T)HW5_Simulink_P.Constant4_Value;
    }

    /* Outport: '<Root>/Motors' */
    HW5_Simulink_Y.Motors[3] = motors_outport[3];

    /* ManualSwitch: '<S1>/Manual Switch' incorporates:
     *  Constant: '<S1>/Constant1'
     *  Constant: '<S1>/Constant2'
     */
    if (HW5_Simulink_P.ManualSwitch_CurrentSetting == 1) {
      flag_outport = HW5_Simulink_P.Constant2_Value;
    } else {
      flag_outport = HW5_Simulink_P.Constant1_Value;
    }

    /* End of ManualSwitch: '<S1>/Manual Switch' */

    /* Outport: '<Root>/Flag' */
    HW5_Simulink_Y.Flag = flag_outport;

    /* SignalConversion generated from: '<S1>/To Workspace' */
    HW5_Simulink_B.TmpSignalConversionAtToWork[0] = HW5_Simulink_B.Xned;
    HW5_Simulink_B.TmpSignalConversionAtToWork[1] = HW5_Simulink_B.Yned;
    HW5_Simulink_B.TmpSignalConversionAtToWork[2] =
      HW5_Simulink_B.DataTypeConversion8;
    HW5_Simulink_B.TmpSignalConversionAtToWork[3] =
      HW5_Simulink_B.DataTypeConversion3;
    HW5_Simulink_B.TmpSignalConversionAtToWork[4] =
      HW5_Simulink_B.DataTypeConversion4;
    HW5_Simulink_B.TmpSignalConversionAtToWork[5] =
      HW5_Simulink_B.DataTypeConversion5;
    HW5_Simulink_B.TmpSignalConversionAtToWork[6] =
      HW5_Simulink_B.DataTypeConversion;
    HW5_Simulink_B.TmpSignalConversionAtToWork[7] =
      HW5_Simulink_B.DataTypeConversion1;
    HW5_Simulink_B.TmpSignalConversionAtToWork[8] =
      HW5_Simulink_B.DataTypeConversion2;
    HW5_Simulink_B.TmpSignalConversionAtToWork[9] = HW5_Simulink_B.phi;
    HW5_Simulink_B.TmpSignalConversionAtToWork[10] = HW5_Simulink_B.theta;
    HW5_Simulink_B.TmpSignalConversionAtToWork[11] = HW5_Simulink_B.psi;
    HW5_Simulink_B.TmpSignalConversionAtToWork[12] =
      HW5_Simulink_B.DataTypeConversion6;
    HW5_Simulink_B.TmpSignalConversionAtToWork[13] =
      HW5_Simulink_B.DataTypeConversion7;
    HW5_Simulink_B.TmpSignalConversionAtToWork[14] = HW5_Simulink_B.Integrator11;

    /* ToWorkspace: '<S1>/To Workspace' */
    {
      double locTime = (((HW5_Simulink_M->Timing.clockTick1+
                          HW5_Simulink_M->Timing.clockTickH1* 4294967296.0)) *
                        0.005);
      ;
      if (rtmIsMajorTimeStep(HW5_Simulink_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              HW5_Simulink_DW.ToWorkspace_PWORK.LoggedData,
                              &locTime,
                              &HW5_Simulink_B.TmpSignalConversionAtToWork[0]);
      }
    }
  }

  /* Integrator: '<S1>/Integrator' */
  HW5_Simulink_B.Integrator = HW5_Simulink_X.Integrator_CSTATE;

  /* Integrator: '<S1>/Integrator2' */
  HW5_Simulink_B.Integrator2 = HW5_Simulink_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(HW5_Simulink_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(HW5_Simulink_M->rtwLogInfo, (HW5_Simulink_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(HW5_Simulink_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(HW5_Simulink_M)!=-1) &&
          !((rtmGetTFinal(HW5_Simulink_M)-(((HW5_Simulink_M->Timing.clockTick1+
               HW5_Simulink_M->Timing.clockTickH1* 4294967296.0)) * 0.005)) >
            (((HW5_Simulink_M->Timing.clockTick1+
               HW5_Simulink_M->Timing.clockTickH1* 4294967296.0)) * 0.005) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(HW5_Simulink_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&HW5_Simulink_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++HW5_Simulink_M->Timing.clockTick0)) {
      ++HW5_Simulink_M->Timing.clockTickH0;
    }

    HW5_Simulink_M->Timing.t[0] = rtsiGetSolverStopTime
      (&HW5_Simulink_M->solverInfo);

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
      HW5_Simulink_M->Timing.clockTick1++;
      if (!HW5_Simulink_M->Timing.clockTick1) {
        HW5_Simulink_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void HW5_Simulink_derivatives(void)
{
  XDot_HW5_Simulink_T *_rtXdot;
  _rtXdot = ((XDot_HW5_Simulink_T *) HW5_Simulink_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = HW5_Simulink_B.Integrator;

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = HW5_Simulink_B.Integrator2;

  /* Derivatives for Integrator: '<S1>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = HW5_Simulink_B.DataTypeConversion3;

  /* Derivatives for Integrator: '<S1>/Integrator7' */
  _rtXdot->Integrator7_CSTATE = HW5_Simulink_B.DataTypeConversion4;

  /* Derivatives for Integrator: '<S1>/Integrator8' */
  _rtXdot->Integrator8_CSTATE = HW5_Simulink_B.DataTypeConversion5;

  /* Derivatives for Integrator: '<S1>/Integrator11' */
  _rtXdot->Integrator11_CSTATE = HW5_Simulink_B.DataTypeConversion2;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = HW5_Simulink_B.DataTypeConversion;

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = HW5_Simulink_B.DataTypeConversion1;
}

/* Model initialize function */
void HW5_Simulink_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)HW5_Simulink_M, 0,
                sizeof(RT_MODEL_HW5_Simulink_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&HW5_Simulink_M->solverInfo,
                          &HW5_Simulink_M->Timing.simTimeStep);
    rtsiSetTPtr(&HW5_Simulink_M->solverInfo, &rtmGetTPtr(HW5_Simulink_M));
    rtsiSetStepSizePtr(&HW5_Simulink_M->solverInfo,
                       &HW5_Simulink_M->Timing.stepSize0);
    rtsiSetdXPtr(&HW5_Simulink_M->solverInfo, &HW5_Simulink_M->derivs);
    rtsiSetContStatesPtr(&HW5_Simulink_M->solverInfo, (real_T **)
                         &HW5_Simulink_M->contStates);
    rtsiSetNumContStatesPtr(&HW5_Simulink_M->solverInfo,
      &HW5_Simulink_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&HW5_Simulink_M->solverInfo,
      &HW5_Simulink_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&HW5_Simulink_M->solverInfo,
      &HW5_Simulink_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&HW5_Simulink_M->solverInfo,
      &HW5_Simulink_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&HW5_Simulink_M->solverInfo, (&rtmGetErrorStatus
      (HW5_Simulink_M)));
    rtsiSetRTModelPtr(&HW5_Simulink_M->solverInfo, HW5_Simulink_M);
  }

  rtsiSetSimTimeStep(&HW5_Simulink_M->solverInfo, MAJOR_TIME_STEP);
  HW5_Simulink_M->intgData.y = HW5_Simulink_M->odeY;
  HW5_Simulink_M->intgData.f[0] = HW5_Simulink_M->odeF[0];
  HW5_Simulink_M->intgData.f[1] = HW5_Simulink_M->odeF[1];
  HW5_Simulink_M->intgData.f[2] = HW5_Simulink_M->odeF[2];
  HW5_Simulink_M->contStates = ((X_HW5_Simulink_T *) &HW5_Simulink_X);
  rtsiSetSolverData(&HW5_Simulink_M->solverInfo, (void *)
                    &HW5_Simulink_M->intgData);
  rtsiSetSolverName(&HW5_Simulink_M->solverInfo,"ode3");
  rtmSetTPtr(HW5_Simulink_M, &HW5_Simulink_M->Timing.tArray[0]);
  rtmSetTFinal(HW5_Simulink_M, 10.0);
  HW5_Simulink_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    HW5_Simulink_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(HW5_Simulink_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(HW5_Simulink_M->rtwLogInfo, (NULL));
    rtliSetLogT(HW5_Simulink_M->rtwLogInfo, "tout");
    rtliSetLogX(HW5_Simulink_M->rtwLogInfo, "");
    rtliSetLogXFinal(HW5_Simulink_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(HW5_Simulink_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(HW5_Simulink_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(HW5_Simulink_M->rtwLogInfo, 0);
    rtliSetLogDecimation(HW5_Simulink_M->rtwLogInfo, 1);
    rtliSetLogY(HW5_Simulink_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(HW5_Simulink_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(HW5_Simulink_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &HW5_Simulink_B), 0,
                sizeof(B_HW5_Simulink_T));

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* states (continuous) */
  {
    (void) memset((void *)&HW5_Simulink_X, 0,
                  sizeof(X_HW5_Simulink_T));
  }

  /* states (dwork) */
  (void) memset((void *)&HW5_Simulink_DW, 0,
                sizeof(DW_HW5_Simulink_T));

  /* external inputs */
  (void)memset(&cmd_inport, 0, sizeof(CommandBus));
  (void)memset(&sensor_inport, 0, sizeof(SensorsBus));

  /* external outputs */
  (void) memset((void *)&HW5_Simulink_Y, 0,
                sizeof(ExtY_HW5_Simulink_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(HW5_Simulink_M->rtwLogInfo, 0.0, rtmGetTFinal
    (HW5_Simulink_M), HW5_Simulink_M->Timing.stepSize0, (&rtmGetErrorStatus
    (HW5_Simulink_M)));

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
      "HW5_Simulink/Flight Control System/To Workspace";
    HW5_Simulink_DW.ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      HW5_Simulink_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(HW5_Simulink_M),
      HW5_Simulink_M->Timing.stepSize0,
      (&rtmGetErrorStatus(HW5_Simulink_M)),
      "states",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (HW5_Simulink_DW.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  HW5_Simulink_X.Integrator1_CSTATE = HW5_Simulink_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  HW5_Simulink_X.Integrator3_CSTATE = HW5_Simulink_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator6' */
  HW5_Simulink_X.Integrator6_CSTATE = HW5_Simulink_P.Integrator6_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator7' */
  HW5_Simulink_X.Integrator7_CSTATE = HW5_Simulink_P.Integrator7_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator8' */
  HW5_Simulink_X.Integrator8_CSTATE = HW5_Simulink_P.Integrator8_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator11' */
  HW5_Simulink_X.Integrator11_CSTATE = HW5_Simulink_P.Integrator11_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  HW5_Simulink_X.Integrator_CSTATE = HW5_Simulink_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  HW5_Simulink_X.Integrator2_CSTATE = HW5_Simulink_P.Integrator2_IC;
}

/* Model terminate function */
void HW5_Simulink_terminate(void)
{
  /* (no terminate code required) */
}

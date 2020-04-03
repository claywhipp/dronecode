/*
 * TestDataLogging.c
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

#include "TestDataLogging.h"
#include "TestDataLogging_private.h"

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S1>/Saturation1' */
uint8_T flag_outport;                  /* '<S1>/Manual Switch' */

/* Block signals (default storage) */
B_TestDataLogging_T TestDataLogging_B;

/* Continuous states */
X_TestDataLogging_T TestDataLogging_X;

/* Block states (default storage) */
DW_TestDataLogging_T TestDataLogging_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_TestDataLogging_T TestDataLogging_Y;

/* Real-time model */
RT_MODEL_TestDataLogging_T TestDataLogging_M_;
RT_MODEL_TestDataLogging_T *const TestDataLogging_M = &TestDataLogging_M_;

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
  TestDataLogging_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  TestDataLogging_step();
  TestDataLogging_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  TestDataLogging_step();
  TestDataLogging_derivatives();

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
void TestDataLogging_step(void)
{
  real_T rtb_VectorConcatenate1_idx_0;
  real_T rtb_VectorConcatenate1_idx_1;
  real_T rtb_VectorConcatenate1_idx_2;
  real_T rtb_VectorConcatenate1_idx_3;
  if (rtmIsMajorTimeStep(TestDataLogging_M)) {
    /* set solver stop time */
    if (!(TestDataLogging_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&TestDataLogging_M->solverInfo,
                            ((TestDataLogging_M->Timing.clockTickH0 + 1) *
        TestDataLogging_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&TestDataLogging_M->solverInfo,
                            ((TestDataLogging_M->Timing.clockTick0 + 1) *
        TestDataLogging_M->Timing.stepSize0 +
        TestDataLogging_M->Timing.clockTickH0 *
        TestDataLogging_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(TestDataLogging_M)) {
    TestDataLogging_M->Timing.t[0] = rtsiGetT(&TestDataLogging_M->solverInfo);
  }

  /* Integrator: '<S1>/Integrator1' */
  TestDataLogging_B.Integrator1 = TestDataLogging_X.Integrator1_CSTATE;

  /* Integrator: '<S1>/Integrator3' */
  TestDataLogging_B.Integrator3 = TestDataLogging_X.Integrator3_CSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion8' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.DataTypeConversion8 =
    sensor_inport.HALSensors.HAL_ultrasound_SI.altitude;

  /* DataTypeConversion: '<S1>/Data Type Conversion3' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.DataTypeConversion3 = sensor_inport.HALSensors.HAL_gyro_SI.x;

  /* DataTypeConversion: '<S1>/Data Type Conversion4' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.DataTypeConversion4 = sensor_inport.HALSensors.HAL_gyro_SI.y;

  /* DataTypeConversion: '<S1>/Data Type Conversion5' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.DataTypeConversion5 = sensor_inport.HALSensors.HAL_gyro_SI.z;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.DataTypeConversion = sensor_inport.HALSensors.HAL_acc_SI.x;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.DataTypeConversion1 = sensor_inport.HALSensors.HAL_acc_SI.y;

  /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.DataTypeConversion2 = sensor_inport.HALSensors.HAL_acc_SI.z;

  /* Integrator: '<S1>/Integrator6' */
  TestDataLogging_B.Integrator6 = TestDataLogging_X.Integrator6_CSTATE;

  /* Integrator: '<S1>/Integrator7' */
  TestDataLogging_B.Integrator7 = TestDataLogging_X.Integrator7_CSTATE;

  /* Integrator: '<S1>/Integrator8' */
  TestDataLogging_B.Integrator8 = TestDataLogging_X.Integrator8_CSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion6' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.DataTypeConversion6 =
    sensor_inport.VisionSensors.opticalFlow_data[0];

  /* DataTypeConversion: '<S1>/Data Type Conversion7' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.DataTypeConversion7 =
    sensor_inport.VisionSensors.opticalFlow_data[1];

  /* Integrator: '<S1>/Integrator11' */
  TestDataLogging_B.Integrator11 = TestDataLogging_X.Integrator11_CSTATE;
  if (rtmIsMajorTimeStep(TestDataLogging_M)) {
    /* DiscretePulseGenerator: '<S1>/Pulse Generator1' */
    rtb_VectorConcatenate1_idx_0 = (TestDataLogging_DW.clockTickCounter <
      TestDataLogging_P.PulseGenerator1_Duty) &&
      (TestDataLogging_DW.clockTickCounter >= 0) ?
      TestDataLogging_P.PulseGenerator1_Amp : 0.0;
    if (TestDataLogging_DW.clockTickCounter >=
        TestDataLogging_P.PulseGenerator1_Period - 1.0) {
      TestDataLogging_DW.clockTickCounter = 0;
    } else {
      TestDataLogging_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<S1>/Pulse Generator1' */

    /* DiscretePulseGenerator: '<S1>/Pulse Generator3' */
    rtb_VectorConcatenate1_idx_1 = (TestDataLogging_DW.clockTickCounter_h <
      TestDataLogging_P.PulseGenerator3_Duty) &&
      (TestDataLogging_DW.clockTickCounter_h >= 0) ?
      TestDataLogging_P.PulseGenerator3_Amp : 0.0;
    if (TestDataLogging_DW.clockTickCounter_h >=
        TestDataLogging_P.PulseGenerator3_Period - 1.0) {
      TestDataLogging_DW.clockTickCounter_h = 0;
    } else {
      TestDataLogging_DW.clockTickCounter_h++;
    }

    /* End of DiscretePulseGenerator: '<S1>/Pulse Generator3' */

    /* DiscretePulseGenerator: '<S1>/Pulse Generator4' */
    rtb_VectorConcatenate1_idx_2 = (TestDataLogging_DW.clockTickCounter_a <
      TestDataLogging_P.PulseGenerator4_Duty) &&
      (TestDataLogging_DW.clockTickCounter_a >= 0) ?
      TestDataLogging_P.PulseGenerator4_Amp : 0.0;
    if (TestDataLogging_DW.clockTickCounter_a >=
        TestDataLogging_P.PulseGenerator4_Period - 1.0) {
      TestDataLogging_DW.clockTickCounter_a = 0;
    } else {
      TestDataLogging_DW.clockTickCounter_a++;
    }

    /* End of DiscretePulseGenerator: '<S1>/Pulse Generator4' */

    /* DiscretePulseGenerator: '<S1>/Pulse Generator2' */
    rtb_VectorConcatenate1_idx_3 = (TestDataLogging_DW.clockTickCounter_n <
      TestDataLogging_P.PulseGenerator2_Duty) &&
      (TestDataLogging_DW.clockTickCounter_n >= 0) ?
      TestDataLogging_P.PulseGenerator2_Amp : 0.0;
    if (TestDataLogging_DW.clockTickCounter_n >=
        TestDataLogging_P.PulseGenerator2_Period - 1.0) {
      TestDataLogging_DW.clockTickCounter_n = 0;
    } else {
      TestDataLogging_DW.clockTickCounter_n++;
    }

    /* End of DiscretePulseGenerator: '<S1>/Pulse Generator2' */

    /* Saturate: '<S1>/Saturation1' */
    if (rtb_VectorConcatenate1_idx_0 > TestDataLogging_P.Saturation1_UpperSat) {
      motors_outport[0] = TestDataLogging_P.Saturation1_UpperSat;
    } else if (rtb_VectorConcatenate1_idx_0 <
               TestDataLogging_P.Saturation1_LowerSat) {
      motors_outport[0] = TestDataLogging_P.Saturation1_LowerSat;
    } else {
      motors_outport[0] = (real32_T)rtb_VectorConcatenate1_idx_0;
    }

    /* Outport: '<Root>/Motors' */
    TestDataLogging_Y.Motors[0] = motors_outport[0];

    /* Saturate: '<S1>/Saturation1' */
    if (rtb_VectorConcatenate1_idx_1 > TestDataLogging_P.Saturation1_UpperSat) {
      motors_outport[1] = TestDataLogging_P.Saturation1_UpperSat;
    } else if (rtb_VectorConcatenate1_idx_1 <
               TestDataLogging_P.Saturation1_LowerSat) {
      motors_outport[1] = TestDataLogging_P.Saturation1_LowerSat;
    } else {
      motors_outport[1] = (real32_T)rtb_VectorConcatenate1_idx_1;
    }

    /* Outport: '<Root>/Motors' */
    TestDataLogging_Y.Motors[1] = motors_outport[1];

    /* Saturate: '<S1>/Saturation1' */
    if (rtb_VectorConcatenate1_idx_2 > TestDataLogging_P.Saturation1_UpperSat) {
      motors_outport[2] = TestDataLogging_P.Saturation1_UpperSat;
    } else if (rtb_VectorConcatenate1_idx_2 <
               TestDataLogging_P.Saturation1_LowerSat) {
      motors_outport[2] = TestDataLogging_P.Saturation1_LowerSat;
    } else {
      motors_outport[2] = (real32_T)rtb_VectorConcatenate1_idx_2;
    }

    /* Outport: '<Root>/Motors' */
    TestDataLogging_Y.Motors[2] = motors_outport[2];

    /* Saturate: '<S1>/Saturation1' */
    if (rtb_VectorConcatenate1_idx_3 > TestDataLogging_P.Saturation1_UpperSat) {
      motors_outport[3] = TestDataLogging_P.Saturation1_UpperSat;
    } else if (rtb_VectorConcatenate1_idx_3 <
               TestDataLogging_P.Saturation1_LowerSat) {
      motors_outport[3] = TestDataLogging_P.Saturation1_LowerSat;
    } else {
      motors_outport[3] = (real32_T)rtb_VectorConcatenate1_idx_3;
    }

    /* Outport: '<Root>/Motors' */
    TestDataLogging_Y.Motors[3] = motors_outport[3];

    /* ManualSwitch: '<S1>/Manual Switch' incorporates:
     *  Constant: '<S1>/Constant1'
     *  Constant: '<S1>/Constant2'
     */
    if (TestDataLogging_P.ManualSwitch_CurrentSetting == 1) {
      flag_outport = TestDataLogging_P.Constant2_Value;
    } else {
      flag_outport = TestDataLogging_P.Constant1_Value;
    }

    /* End of ManualSwitch: '<S1>/Manual Switch' */

    /* Outport: '<Root>/Flag' */
    TestDataLogging_Y.Flag = flag_outport;

    /* SignalConversion generated from: '<S1>/To Workspace' */
    TestDataLogging_B.TmpSignalConversionAtToWork[0] =
      TestDataLogging_B.Integrator1;
    TestDataLogging_B.TmpSignalConversionAtToWork[1] =
      TestDataLogging_B.Integrator3;
    TestDataLogging_B.TmpSignalConversionAtToWork[2] =
      TestDataLogging_B.DataTypeConversion8;
    TestDataLogging_B.TmpSignalConversionAtToWork[3] =
      TestDataLogging_B.DataTypeConversion3;
    TestDataLogging_B.TmpSignalConversionAtToWork[4] =
      TestDataLogging_B.DataTypeConversion4;
    TestDataLogging_B.TmpSignalConversionAtToWork[5] =
      TestDataLogging_B.DataTypeConversion5;
    TestDataLogging_B.TmpSignalConversionAtToWork[6] =
      TestDataLogging_B.DataTypeConversion;
    TestDataLogging_B.TmpSignalConversionAtToWork[7] =
      TestDataLogging_B.DataTypeConversion1;
    TestDataLogging_B.TmpSignalConversionAtToWork[8] =
      TestDataLogging_B.DataTypeConversion2;
    TestDataLogging_B.TmpSignalConversionAtToWork[9] =
      TestDataLogging_B.Integrator6;
    TestDataLogging_B.TmpSignalConversionAtToWork[10] =
      TestDataLogging_B.Integrator7;
    TestDataLogging_B.TmpSignalConversionAtToWork[11] =
      TestDataLogging_B.Integrator8;
    TestDataLogging_B.TmpSignalConversionAtToWork[12] =
      TestDataLogging_B.DataTypeConversion6;
    TestDataLogging_B.TmpSignalConversionAtToWork[13] =
      TestDataLogging_B.DataTypeConversion7;
    TestDataLogging_B.TmpSignalConversionAtToWork[14] =
      TestDataLogging_B.Integrator11;

    /* ToWorkspace: '<S1>/To Workspace' */
    {
      double locTime = (((TestDataLogging_M->Timing.clockTick1+
                          TestDataLogging_M->Timing.clockTickH1* 4294967296.0)) *
                        0.005);
      ;
      if (rtmIsMajorTimeStep(TestDataLogging_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              TestDataLogging_DW.ToWorkspace_PWORK.LoggedData,
                              &locTime,
                              &TestDataLogging_B.TmpSignalConversionAtToWork[0]);
      }
    }
  }

  /* Integrator: '<S1>/Integrator' */
  TestDataLogging_B.Integrator = TestDataLogging_X.Integrator_CSTATE;

  /* Integrator: '<S1>/Integrator2' */
  TestDataLogging_B.Integrator2 = TestDataLogging_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(TestDataLogging_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(TestDataLogging_M->rtwLogInfo,
                        (TestDataLogging_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(TestDataLogging_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(TestDataLogging_M)!=-1) &&
          !((rtmGetTFinal(TestDataLogging_M)-
             (((TestDataLogging_M->Timing.clockTick1+
                TestDataLogging_M->Timing.clockTickH1* 4294967296.0)) * 0.005)) >
            (((TestDataLogging_M->Timing.clockTick1+
               TestDataLogging_M->Timing.clockTickH1* 4294967296.0)) * 0.005) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(TestDataLogging_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&TestDataLogging_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++TestDataLogging_M->Timing.clockTick0)) {
      ++TestDataLogging_M->Timing.clockTickH0;
    }

    TestDataLogging_M->Timing.t[0] = rtsiGetSolverStopTime
      (&TestDataLogging_M->solverInfo);

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
      TestDataLogging_M->Timing.clockTick1++;
      if (!TestDataLogging_M->Timing.clockTick1) {
        TestDataLogging_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void TestDataLogging_derivatives(void)
{
  XDot_TestDataLogging_T *_rtXdot;
  _rtXdot = ((XDot_TestDataLogging_T *) TestDataLogging_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = TestDataLogging_B.Integrator;

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = TestDataLogging_B.Integrator2;

  /* Derivatives for Integrator: '<S1>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = TestDataLogging_B.DataTypeConversion3;

  /* Derivatives for Integrator: '<S1>/Integrator7' */
  _rtXdot->Integrator7_CSTATE = TestDataLogging_B.DataTypeConversion4;

  /* Derivatives for Integrator: '<S1>/Integrator8' */
  _rtXdot->Integrator8_CSTATE = TestDataLogging_B.DataTypeConversion5;

  /* Derivatives for Integrator: '<S1>/Integrator11' */
  _rtXdot->Integrator11_CSTATE = TestDataLogging_B.DataTypeConversion2;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = TestDataLogging_B.DataTypeConversion;

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = TestDataLogging_B.DataTypeConversion1;
}

/* Model initialize function */
void TestDataLogging_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)TestDataLogging_M, 0,
                sizeof(RT_MODEL_TestDataLogging_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&TestDataLogging_M->solverInfo,
                          &TestDataLogging_M->Timing.simTimeStep);
    rtsiSetTPtr(&TestDataLogging_M->solverInfo, &rtmGetTPtr(TestDataLogging_M));
    rtsiSetStepSizePtr(&TestDataLogging_M->solverInfo,
                       &TestDataLogging_M->Timing.stepSize0);
    rtsiSetdXPtr(&TestDataLogging_M->solverInfo, &TestDataLogging_M->derivs);
    rtsiSetContStatesPtr(&TestDataLogging_M->solverInfo, (real_T **)
                         &TestDataLogging_M->contStates);
    rtsiSetNumContStatesPtr(&TestDataLogging_M->solverInfo,
      &TestDataLogging_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&TestDataLogging_M->solverInfo,
      &TestDataLogging_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&TestDataLogging_M->solverInfo,
      &TestDataLogging_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&TestDataLogging_M->solverInfo,
      &TestDataLogging_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&TestDataLogging_M->solverInfo, (&rtmGetErrorStatus
      (TestDataLogging_M)));
    rtsiSetRTModelPtr(&TestDataLogging_M->solverInfo, TestDataLogging_M);
  }

  rtsiSetSimTimeStep(&TestDataLogging_M->solverInfo, MAJOR_TIME_STEP);
  TestDataLogging_M->intgData.y = TestDataLogging_M->odeY;
  TestDataLogging_M->intgData.f[0] = TestDataLogging_M->odeF[0];
  TestDataLogging_M->intgData.f[1] = TestDataLogging_M->odeF[1];
  TestDataLogging_M->intgData.f[2] = TestDataLogging_M->odeF[2];
  TestDataLogging_M->contStates = ((X_TestDataLogging_T *) &TestDataLogging_X);
  rtsiSetSolverData(&TestDataLogging_M->solverInfo, (void *)
                    &TestDataLogging_M->intgData);
  rtsiSetSolverName(&TestDataLogging_M->solverInfo,"ode3");
  rtmSetTPtr(TestDataLogging_M, &TestDataLogging_M->Timing.tArray[0]);
  rtmSetTFinal(TestDataLogging_M, 100.0);
  TestDataLogging_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    TestDataLogging_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(TestDataLogging_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(TestDataLogging_M->rtwLogInfo, (NULL));
    rtliSetLogT(TestDataLogging_M->rtwLogInfo, "tout");
    rtliSetLogX(TestDataLogging_M->rtwLogInfo, "");
    rtliSetLogXFinal(TestDataLogging_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(TestDataLogging_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(TestDataLogging_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(TestDataLogging_M->rtwLogInfo, 0);
    rtliSetLogDecimation(TestDataLogging_M->rtwLogInfo, 1);
    rtliSetLogY(TestDataLogging_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(TestDataLogging_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(TestDataLogging_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &TestDataLogging_B), 0,
                sizeof(B_TestDataLogging_T));

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* states (continuous) */
  {
    (void) memset((void *)&TestDataLogging_X, 0,
                  sizeof(X_TestDataLogging_T));
  }

  /* states (dwork) */
  (void) memset((void *)&TestDataLogging_DW, 0,
                sizeof(DW_TestDataLogging_T));

  /* external inputs */
  (void)memset(&cmd_inport, 0, sizeof(CommandBus));
  (void)memset(&sensor_inport, 0, sizeof(SensorsBus));

  /* external outputs */
  (void) memset((void *)&TestDataLogging_Y, 0,
                sizeof(ExtY_TestDataLogging_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(TestDataLogging_M->rtwLogInfo, 0.0,
    rtmGetTFinal(TestDataLogging_M), TestDataLogging_M->Timing.stepSize0,
    (&rtmGetErrorStatus(TestDataLogging_M)));

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
      "TestDataLogging/Flight Control System/To Workspace";
    TestDataLogging_DW.ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      TestDataLogging_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(TestDataLogging_M),
      TestDataLogging_M->Timing.stepSize0,
      (&rtmGetErrorStatus(TestDataLogging_M)),
      "states",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (TestDataLogging_DW.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for DiscretePulseGenerator: '<S1>/Pulse Generator1' */
  TestDataLogging_DW.clockTickCounter = 0;

  /* InitializeConditions for DiscretePulseGenerator: '<S1>/Pulse Generator3' */
  TestDataLogging_DW.clockTickCounter_h = -400;

  /* InitializeConditions for DiscretePulseGenerator: '<S1>/Pulse Generator4' */
  TestDataLogging_DW.clockTickCounter_a = -800;

  /* InitializeConditions for DiscretePulseGenerator: '<S1>/Pulse Generator2' */
  TestDataLogging_DW.clockTickCounter_n = -1200;

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  TestDataLogging_X.Integrator1_CSTATE = TestDataLogging_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  TestDataLogging_X.Integrator3_CSTATE = TestDataLogging_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator6' */
  TestDataLogging_X.Integrator6_CSTATE = TestDataLogging_P.Integrator6_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator7' */
  TestDataLogging_X.Integrator7_CSTATE = TestDataLogging_P.Integrator7_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator8' */
  TestDataLogging_X.Integrator8_CSTATE = TestDataLogging_P.Integrator8_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator11' */
  TestDataLogging_X.Integrator11_CSTATE = TestDataLogging_P.Integrator11_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  TestDataLogging_X.Integrator_CSTATE = TestDataLogging_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  TestDataLogging_X.Integrator2_CSTATE = TestDataLogging_P.Integrator2_IC;
}

/* Model terminate function */
void TestDataLogging_terminate(void)
{
  /* (no terminate code required) */
}

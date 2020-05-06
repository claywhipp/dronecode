/*
 * HW6_v1.c
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

#include "HW6_v1.h"
#include "HW6_v1_private.h"

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S1>/Saturation1' */
uint8_T flag_outport;                  /* '<S1>/Manual Switch' */

/* Block signals (default storage) */
B_HW6_v1_T HW6_v1_B;

/* Continuous states */
X_HW6_v1_T HW6_v1_X;

/* Block states (default storage) */
DW_HW6_v1_T HW6_v1_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_HW6_v1_T HW6_v1_Y;

/* Real-time model */
RT_MODEL_HW6_v1_T HW6_v1_M_;
RT_MODEL_HW6_v1_T *const HW6_v1_M = &HW6_v1_M_;

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
  int_T nXc = 10;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  HW6_v1_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  HW6_v1_step();
  HW6_v1_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  HW6_v1_step();
  HW6_v1_derivatives();

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

/*
 * System initialize for enable system:
 *    '<S29>/MeasurementUpdate'
 *    '<S81>/MeasurementUpdate'
 *    '<S133>/MeasurementUpdate'
 *    '<S185>/MeasurementUpdate'
 */
void HW6_v1_MeasurementUpdate_Init(B_MeasurementUpdate_HW6_v1_T *localB,
  P_MeasurementUpdate_HW6_v1_T *localP)
{
  /* SystemInitialize for Outport: '<S58>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3 = localP->Lykyhatkk1_Y0;
}

/*
 * Disable for enable system:
 *    '<S29>/MeasurementUpdate'
 *    '<S81>/MeasurementUpdate'
 *    '<S133>/MeasurementUpdate'
 *    '<S185>/MeasurementUpdate'
 */
void HW6_v_MeasurementUpdate_Disable(B_MeasurementUpdate_HW6_v1_T *localB,
  DW_MeasurementUpdate_HW6_v1_T *localDW, P_MeasurementUpdate_HW6_v1_T *localP)
{
  /* Disable for Outport: '<S58>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3 = localP->Lykyhatkk1_Y0;
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S29>/MeasurementUpdate'
 *    '<S81>/MeasurementUpdate'
 *    '<S133>/MeasurementUpdate'
 *    '<S185>/MeasurementUpdate'
 */
void HW6_v1_MeasurementUpdate(RT_MODEL_HW6_v1_T * const HW6_v1_M, boolean_T
  rtu_Enable, real_T rtu_Lk, real_T rtu_yk, real_T rtu_Ck, real_T rtu_xhatkk1,
  real_T rtu_Dk, real_T rtu_uk, B_MeasurementUpdate_HW6_v1_T *localB,
  DW_MeasurementUpdate_HW6_v1_T *localDW, P_MeasurementUpdate_HW6_v1_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S29>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S58>/Enable'
   */
  if (rtmIsMajorTimeStep(HW6_v1_M)) {
    if (rtu_Enable) {
      localDW->MeasurementUpdate_MODE = true;
    } else {
      if (localDW->MeasurementUpdate_MODE) {
        HW6_v_MeasurementUpdate_Disable(localB, localDW, localP);
      }
    }
  }

  if (localDW->MeasurementUpdate_MODE) {
    /* Product: '<S58>/Product3' incorporates:
     *  Product: '<S58>/C[k]*xhat[k|k-1]'
     *  Product: '<S58>/D[k]*u[k]'
     *  Sum: '<S58>/Add1'
     *  Sum: '<S58>/Sum'
     */
    localB->Product3 = (rtu_yk - (rtu_Ck * rtu_xhatkk1 + rtu_Dk * rtu_uk)) *
      rtu_Lk;
  }

  /* End of Outputs for SubSystem: '<S29>/MeasurementUpdate' */
}

/*
 * System initialize for enable system:
 *    '<S36>/Enabled Subsystem'
 *    '<S88>/Enabled Subsystem'
 *    '<S140>/Enabled Subsystem'
 *    '<S192>/Enabled Subsystem'
 */
void HW6_v1_EnabledSubsystem_Init(B_EnabledSubsystem_HW6_v1_T *localB,
  P_EnabledSubsystem_HW6_v1_T *localP)
{
  /* SystemInitialize for Outport: '<S60>/deltax' */
  localB->Product2 = localP->deltax_Y0;
}

/*
 * Disable for enable system:
 *    '<S36>/Enabled Subsystem'
 *    '<S88>/Enabled Subsystem'
 *    '<S140>/Enabled Subsystem'
 *    '<S192>/Enabled Subsystem'
 */
void HW6_v1_EnabledSubsystem_Disable(B_EnabledSubsystem_HW6_v1_T *localB,
  DW_EnabledSubsystem_HW6_v1_T *localDW, P_EnabledSubsystem_HW6_v1_T *localP)
{
  /* Disable for Outport: '<S60>/deltax' */
  localB->Product2 = localP->deltax_Y0;
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S36>/Enabled Subsystem'
 *    '<S88>/Enabled Subsystem'
 *    '<S140>/Enabled Subsystem'
 *    '<S192>/Enabled Subsystem'
 */
void HW6_v1_EnabledSubsystem(RT_MODEL_HW6_v1_T * const HW6_v1_M, boolean_T
  rtu_Enable, real_T rtu_Mk, real_T rtu_Ck, real_T rtu_yk, real_T rtu_xhatkk1,
  B_EnabledSubsystem_HW6_v1_T *localB, DW_EnabledSubsystem_HW6_v1_T *localDW,
  P_EnabledSubsystem_HW6_v1_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S36>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S60>/Enable'
   */
  if (rtmIsMajorTimeStep(HW6_v1_M)) {
    if (rtu_Enable) {
      localDW->EnabledSubsystem_MODE = true;
    } else {
      if (localDW->EnabledSubsystem_MODE) {
        HW6_v1_EnabledSubsystem_Disable(localB, localDW, localP);
      }
    }
  }

  if (localDW->EnabledSubsystem_MODE) {
    /* Product: '<S60>/Product2' incorporates:
     *  Product: '<S60>/Product'
     *  Sum: '<S60>/Add1'
     */
    localB->Product2 = (rtu_yk - rtu_Ck * rtu_xhatkk1) * rtu_Mk;
  }

  /* End of Outputs for SubSystem: '<S36>/Enabled Subsystem' */
}

/* Model step function */
void HW6_v1_step(void)
{
  /* local block i/o variables */
  real_T rtb_Reshapey_p;
  real_T rtb_MemoryX_c;
  real_T rtb_Reshapey_c;
  real_T rtb_MemoryX_k;
  real_T rtb_Add_c;
  real_T rtb_Add_h;
  real_T rtb_Add_cc;
  real_T rtb_Add_ck;
  if (rtmIsMajorTimeStep(HW6_v1_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&HW6_v1_M->solverInfo,((HW6_v1_M->Timing.clockTick0+1)*
      HW6_v1_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(HW6_v1_M)) {
    HW6_v1_M->Timing.t[0] = rtsiGetT(&HW6_v1_M->solverInfo);
  }

  /* Gain: '<S1>/Gain1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion8'
   *  Inport: '<Root>/Sensors'
   */
  HW6_v1_B.Gain1 = HW6_v1_P.Gain1_Gain *
    sensor_inport.HALSensors.HAL_ultrasound_SI.altitude;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW6_v1_B.DataTypeConversion1 = sensor_inport.HALSensors.HAL_acc_SI.x;

  /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW6_v1_B.DataTypeConversion2 = sensor_inport.HALSensors.HAL_acc_SI.y;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S1>/Constant6'
   *  DataTypeConversion: '<S1>/Data Type Conversion9'
   *  Inport: '<Root>/Sensors'
   */
  HW6_v1_B.Sum1 = sensor_inport.HALSensors.HAL_acc_SI.z -
    HW6_v1_P.Constant6_Value;

  /* DataTypeConversion: '<S1>/Data Type Conversion3' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW6_v1_B.DataTypeConversion3 = sensor_inport.HALSensors.HAL_gyro_SI.x;

  /* DataTypeConversion: '<S1>/Data Type Conversion4' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW6_v1_B.DataTypeConversion4 = sensor_inport.HALSensors.HAL_gyro_SI.y;

  /* DataTypeConversion: '<S1>/Data Type Conversion5' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW6_v1_B.DataTypeConversion5 = sensor_inport.HALSensors.HAL_gyro_SI.z;
  if (rtmIsMajorTimeStep(HW6_v1_M)) {
    /* Saturate: '<S1>/Saturation1' incorporates:
     *  Constant: '<S1>/Constant'
     */
    if (HW6_v1_P.Constant_Value > HW6_v1_P.Saturation1_UpperSat) {
      motors_outport[0] = HW6_v1_P.Saturation1_UpperSat;
    } else if (HW6_v1_P.Constant_Value < HW6_v1_P.Saturation1_LowerSat) {
      motors_outport[0] = HW6_v1_P.Saturation1_LowerSat;
    } else {
      motors_outport[0] = (real32_T)HW6_v1_P.Constant_Value;
    }

    /* Outport: '<Root>/Motors' */
    HW6_v1_Y.Motors[0] = motors_outport[0];

    /* Saturate: '<S1>/Saturation1' incorporates:
     *  Constant: '<S1>/Constant'
     */
    if (HW6_v1_P.Constant_Value > HW6_v1_P.Saturation1_UpperSat) {
      motors_outport[1] = HW6_v1_P.Saturation1_UpperSat;
    } else if (HW6_v1_P.Constant_Value < HW6_v1_P.Saturation1_LowerSat) {
      motors_outport[1] = HW6_v1_P.Saturation1_LowerSat;
    } else {
      motors_outport[1] = (real32_T)HW6_v1_P.Constant_Value;
    }

    /* Outport: '<Root>/Motors' */
    HW6_v1_Y.Motors[1] = motors_outport[1];

    /* Saturate: '<S1>/Saturation1' incorporates:
     *  Constant: '<S1>/Constant'
     */
    if (HW6_v1_P.Constant_Value > HW6_v1_P.Saturation1_UpperSat) {
      motors_outport[2] = HW6_v1_P.Saturation1_UpperSat;
    } else if (HW6_v1_P.Constant_Value < HW6_v1_P.Saturation1_LowerSat) {
      motors_outport[2] = HW6_v1_P.Saturation1_LowerSat;
    } else {
      motors_outport[2] = (real32_T)HW6_v1_P.Constant_Value;
    }

    /* Outport: '<Root>/Motors' */
    HW6_v1_Y.Motors[2] = motors_outport[2];

    /* Saturate: '<S1>/Saturation1' incorporates:
     *  Constant: '<S1>/Constant'
     */
    if (HW6_v1_P.Constant_Value > HW6_v1_P.Saturation1_UpperSat) {
      motors_outport[3] = HW6_v1_P.Saturation1_UpperSat;
    } else if (HW6_v1_P.Constant_Value < HW6_v1_P.Saturation1_LowerSat) {
      motors_outport[3] = HW6_v1_P.Saturation1_LowerSat;
    } else {
      motors_outport[3] = (real32_T)HW6_v1_P.Constant_Value;
    }

    /* Outport: '<Root>/Motors' */
    HW6_v1_Y.Motors[3] = motors_outport[3];

    /* ManualSwitch: '<S1>/Manual Switch' incorporates:
     *  Constant: '<S1>/Constant1'
     *  Constant: '<S1>/Constant2'
     */
    if (HW6_v1_P.ManualSwitch_CurrentSetting == 1) {
      flag_outport = HW6_v1_P.Constant2_Value;
    } else {
      flag_outport = HW6_v1_P.Constant1_Value_d;
    }

    /* End of ManualSwitch: '<S1>/Manual Switch' */

    /* Outport: '<Root>/Flag' */
    HW6_v1_Y.Flag = flag_outport;

    /* SignalConversion generated from: '<S1>/To Workspace1' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion6'
     *  DataTypeConversion: '<S1>/Data Type Conversion7'
     *  DataTypeConversion: '<S1>/Data Type Conversion9'
     *  Inport: '<Root>/Sensors'
     *  Integrator: '<S1>/Integrator1'
     *  Integrator: '<S1>/Integrator11'
     *  Integrator: '<S1>/Integrator3'
     *  Integrator: '<S1>/Integrator5'
     *  Integrator: '<S1>/Integrator6'
     *  Integrator: '<S1>/Integrator7'
     *  Integrator: '<S1>/Integrator8'
     */
    HW6_v1_B.TmpSignalConversionAtToWork[0] = HW6_v1_B.Gain1;
    HW6_v1_B.TmpSignalConversionAtToWork[1] = HW6_v1_X.Integrator11_CSTATE;
    HW6_v1_B.TmpSignalConversionAtToWork[2] = HW6_v1_X.Integrator5_CSTATE;
    HW6_v1_B.TmpSignalConversionAtToWork[3] =
      sensor_inport.VisionSensors.opticalFlow_data[0];
    HW6_v1_B.TmpSignalConversionAtToWork[4] =
      sensor_inport.VisionSensors.opticalFlow_data[1];
    HW6_v1_B.TmpSignalConversionAtToWork[5] = HW6_v1_X.Integrator6_CSTATE;
    HW6_v1_B.TmpSignalConversionAtToWork[6] = HW6_v1_X.Integrator7_CSTATE;
    HW6_v1_B.TmpSignalConversionAtToWork[7] = HW6_v1_B.DataTypeConversion1;
    HW6_v1_B.TmpSignalConversionAtToWork[8] = HW6_v1_B.DataTypeConversion2;
    HW6_v1_B.TmpSignalConversionAtToWork[9] = HW6_v1_B.Sum1;
    HW6_v1_B.TmpSignalConversionAtToWork[10] =
      sensor_inport.HALSensors.HAL_acc_SI.z;
    HW6_v1_B.TmpSignalConversionAtToWork[11] = HW6_v1_X.Integrator8_CSTATE;
    HW6_v1_B.TmpSignalConversionAtToWork[12] = HW6_v1_B.DataTypeConversion3;
    HW6_v1_B.TmpSignalConversionAtToWork[13] = HW6_v1_B.DataTypeConversion4;
    HW6_v1_B.TmpSignalConversionAtToWork[14] = HW6_v1_B.DataTypeConversion5;
    HW6_v1_B.TmpSignalConversionAtToWork[15] = HW6_v1_X.Integrator1_CSTATE;
    HW6_v1_B.TmpSignalConversionAtToWork[16] = HW6_v1_X.Integrator3_CSTATE;

    /* ToWorkspace: '<S1>/To Workspace1' */
    {
      double locTime = ((HW6_v1_M->Timing.clockTick1) * 0.005);
      ;
      if (rtmIsMajorTimeStep(HW6_v1_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              HW6_v1_DW.ToWorkspace1_PWORK.LoggedData, &locTime,
                              &HW6_v1_B.TmpSignalConversionAtToWork[0]);
      }
    }

    /* Reshape: '<S8>/Reshapey' */
    HW6_v1_B.Reshapey = HW6_v1_B.Gain1;

    /* Delay: '<S8>/MemoryX' incorporates:
     *  Constant: '<S8>/X0'
     */
    if (HW6_v1_DW.icLoad != 0) {
      HW6_v1_DW.MemoryX_DSTATE[0] = HW6_v1_P.X0_Value[0];
      HW6_v1_DW.MemoryX_DSTATE[1] = HW6_v1_P.X0_Value[1];
    }

    HW6_v1_B.rtb_MemoryX_idx_0 = HW6_v1_DW.MemoryX_DSTATE[0];
    HW6_v1_B.rtb_MemoryX_idx_1 = HW6_v1_DW.MemoryX_DSTATE[1];

    /* Outputs for Enabled SubSystem: '<S244>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S268>/Enable'
     */
    if (rtmIsMajorTimeStep(HW6_v1_M)) {
      /* Constant: '<S8>/Enable' */
      if (HW6_v1_P.Enable_Value) {
        HW6_v1_DW.EnabledSubsystem_MODE = true;
      } else {
        if (HW6_v1_DW.EnabledSubsystem_MODE) {
          /* Disable for Outport: '<S268>/deltax' */
          HW6_v1_B.Product2[0] = HW6_v1_P.deltax_Y0;
          HW6_v1_B.Product2[1] = HW6_v1_P.deltax_Y0;
          HW6_v1_DW.EnabledSubsystem_MODE = false;
        }
      }
    }

    if (HW6_v1_DW.EnabledSubsystem_MODE) {
      /* Sum: '<S268>/Add1' incorporates:
       *  Constant: '<S8>/C'
       *  Delay: '<S8>/MemoryX'
       *  Product: '<S268>/Product'
       *  Reshape: '<S8>/Reshapey'
       */
      HW6_v1_B.Gain1 -= HW6_v1_P.C_Value[0] * HW6_v1_DW.MemoryX_DSTATE[0] +
        HW6_v1_P.C_Value[1] * HW6_v1_DW.MemoryX_DSTATE[1];

      /* Product: '<S268>/Product2' incorporates:
       *  Constant: '<S217>/KalmanGainM'
       */
      HW6_v1_B.Product2[0] = HW6_v1_P.KalmanGainM_Value[0] * HW6_v1_B.Gain1;
      HW6_v1_B.Product2[1] = HW6_v1_P.KalmanGainM_Value[1] * HW6_v1_B.Gain1;
    }

    /* End of Outputs for SubSystem: '<S244>/Enabled Subsystem' */

    /* Sum: '<S244>/Add' incorporates:
     *  Delay: '<S8>/MemoryX'
     */
    HW6_v1_B.Akxhatkk1[0] = HW6_v1_B.Product2[0] + HW6_v1_DW.MemoryX_DSTATE[0];
    HW6_v1_B.Akxhatkk1[1] = HW6_v1_B.Product2[1] + HW6_v1_DW.MemoryX_DSTATE[1];

    /* ToWorkspace: '<S1>/To Workspace2' */
    {
      double locTime = ((HW6_v1_M->Timing.clockTick1) * 0.005);
      ;
      if (rtmIsMajorTimeStep(HW6_v1_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              HW6_v1_DW.ToWorkspace2_PWORK.LoggedData, &locTime,
                              &HW6_v1_B.Akxhatkk1[0]);
      }
    }

    /* ToWorkspace: '<S1>/To Workspace3' */
    {
      double locTime = ((HW6_v1_M->Timing.clockTick1) * 0.005);
      ;
      if (rtmIsMajorTimeStep(HW6_v1_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              HW6_v1_DW.ToWorkspace3_PWORK.LoggedData, &locTime,
                              &HW6_v1_B.Akxhatkk1[1]);
      }
    }

    /* Reshape: '<S6>/Reshapey' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion6'
     *  Inport: '<Root>/Sensors'
     */
    HW6_v1_B.Reshapey_e = sensor_inport.VisionSensors.opticalFlow_data[0];

    /* Delay: '<S6>/MemoryX' incorporates:
     *  Constant: '<S6>/X0'
     */
    if (HW6_v1_DW.icLoad_m != 0) {
      HW6_v1_DW.MemoryX_DSTATE_l = HW6_v1_P.X0_Value_h;
    }

    HW6_v1_B.MemoryX_o = HW6_v1_DW.MemoryX_DSTATE_l;

    /* End of Delay: '<S6>/MemoryX' */

    /* Outputs for Enabled SubSystem: '<S140>/Enabled Subsystem' */
    /* Constant: '<S6>/Enable' incorporates:
     *  Constant: '<S113>/KalmanGainM'
     *  Constant: '<S6>/C'
     */
    HW6_v1_EnabledSubsystem(HW6_v1_M, HW6_v1_P.Enable_Value_g,
      HW6_v1_P.KalmanGainM_Value_c, HW6_v1_P.C_Value_a, HW6_v1_B.Reshapey_e,
      HW6_v1_B.MemoryX_o, &HW6_v1_B.EnabledSubsystem_d,
      &HW6_v1_DW.EnabledSubsystem_d, &HW6_v1_P.EnabledSubsystem_d);

    /* End of Outputs for SubSystem: '<S140>/Enabled Subsystem' */

    /* Sum: '<S140>/Add' */
    HW6_v1_B.Bkuk_e = HW6_v1_B.EnabledSubsystem_d.Product2 + HW6_v1_B.MemoryX_o;

    /* ToWorkspace: '<S1>/To Workspace4' */
    {
      double locTime = ((HW6_v1_M->Timing.clockTick1) * 0.005);
      ;
      if (rtmIsMajorTimeStep(HW6_v1_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              HW6_v1_DW.ToWorkspace4_PWORK.LoggedData, &locTime,
                              &HW6_v1_B.Bkuk_e);
      }
    }

    /* Reshape: '<S7>/Reshapey' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion7'
     *  Inport: '<Root>/Sensors'
     */
    HW6_v1_B.Reshapey_o = sensor_inport.VisionSensors.opticalFlow_data[1];

    /* Delay: '<S7>/MemoryX' incorporates:
     *  Constant: '<S7>/X0'
     */
    if (HW6_v1_DW.icLoad_l != 0) {
      HW6_v1_DW.MemoryX_DSTATE_f = HW6_v1_P.X0_Value_l;
    }

    HW6_v1_B.MemoryX_j = HW6_v1_DW.MemoryX_DSTATE_f;

    /* End of Delay: '<S7>/MemoryX' */

    /* Outputs for Enabled SubSystem: '<S192>/Enabled Subsystem' */
    /* Constant: '<S7>/Enable' incorporates:
     *  Constant: '<S165>/KalmanGainM'
     *  Constant: '<S7>/C'
     */
    HW6_v1_EnabledSubsystem(HW6_v1_M, HW6_v1_P.Enable_Value_m,
      HW6_v1_P.KalmanGainM_Value_i, HW6_v1_P.C_Value_d, HW6_v1_B.Reshapey_o,
      HW6_v1_B.MemoryX_j, &HW6_v1_B.EnabledSubsystem_f,
      &HW6_v1_DW.EnabledSubsystem_f, &HW6_v1_P.EnabledSubsystem_f);

    /* End of Outputs for SubSystem: '<S192>/Enabled Subsystem' */

    /* Sum: '<S192>/Add' */
    HW6_v1_B.Bkuk_e = HW6_v1_B.EnabledSubsystem_f.Product2 + HW6_v1_B.MemoryX_j;

    /* ToWorkspace: '<S1>/To Workspace5' */
    {
      double locTime = ((HW6_v1_M->Timing.clockTick1) * 0.005);
      ;
      if (rtmIsMajorTimeStep(HW6_v1_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              HW6_v1_DW.ToWorkspace5_PWORK.LoggedData, &locTime,
                              &HW6_v1_B.Bkuk_e);
      }
    }

    /* Reshape: '<S4>/Reshapey' incorporates:
     *  Constant: '<S2>/Constant1'
     *  Product: '<S2>/Divide3'
     */
    rtb_Reshapey_p = HW6_v1_B.DataTypeConversion2 / HW6_v1_P.Constant1_Value;

    /* Delay: '<S4>/MemoryX' incorporates:
     *  Constant: '<S4>/X0'
     */
    if (HW6_v1_DW.icLoad_h != 0) {
      HW6_v1_DW.MemoryX_DSTATE_j = HW6_v1_P.X0_Value_g;
    }

    rtb_MemoryX_c = HW6_v1_DW.MemoryX_DSTATE_j;

    /* End of Delay: '<S4>/MemoryX' */

    /* Outputs for Enabled SubSystem: '<S36>/Enabled Subsystem' */
    /* Constant: '<S4>/Enable' incorporates:
     *  Constant: '<S4>/C'
     *  Constant: '<S9>/KalmanGainM'
     */
    HW6_v1_EnabledSubsystem(HW6_v1_M, HW6_v1_P.Enable_Value_i,
      HW6_v1_P.KalmanGainM_Value_a, HW6_v1_P.C_Value_ag, rtb_Reshapey_p,
      rtb_MemoryX_c, &HW6_v1_B.EnabledSubsystem, &HW6_v1_DW.EnabledSubsystem,
      &HW6_v1_P.EnabledSubsystem);

    /* End of Outputs for SubSystem: '<S36>/Enabled Subsystem' */

    /* Sum: '<S36>/Add' */
    HW6_v1_B.Bkuk_e = HW6_v1_B.EnabledSubsystem.Product2 + rtb_MemoryX_c;

    /* ToWorkspace: '<S1>/To Workspace6' */
    {
      double locTime = ((HW6_v1_M->Timing.clockTick1) * 0.005);
      ;
      if (rtmIsMajorTimeStep(HW6_v1_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              HW6_v1_DW.ToWorkspace6_PWORK.LoggedData, &locTime,
                              &HW6_v1_B.Bkuk_e);
      }
    }

    /* Reshape: '<S5>/Reshapey' incorporates:
     *  Constant: '<S2>/Constant'
     *  Product: '<S2>/Divide2'
     */
    rtb_Reshapey_c = HW6_v1_B.DataTypeConversion1 / HW6_v1_P.Constant_Value_n;

    /* Delay: '<S5>/MemoryX' incorporates:
     *  Constant: '<S5>/X0'
     */
    if (HW6_v1_DW.icLoad_l4 != 0) {
      HW6_v1_DW.MemoryX_DSTATE_m = HW6_v1_P.X0_Value_p;
    }

    rtb_MemoryX_k = HW6_v1_DW.MemoryX_DSTATE_m;

    /* End of Delay: '<S5>/MemoryX' */

    /* Outputs for Enabled SubSystem: '<S88>/Enabled Subsystem' */
    /* Constant: '<S5>/Enable' incorporates:
     *  Constant: '<S5>/C'
     *  Constant: '<S61>/KalmanGainM'
     */
    HW6_v1_EnabledSubsystem(HW6_v1_M, HW6_v1_P.Enable_Value_ir,
      HW6_v1_P.KalmanGainM_Value_j, HW6_v1_P.C_Value_h, rtb_Reshapey_c,
      rtb_MemoryX_k, &HW6_v1_B.EnabledSubsystem_e, &HW6_v1_DW.EnabledSubsystem_e,
      &HW6_v1_P.EnabledSubsystem_e);

    /* End of Outputs for SubSystem: '<S88>/Enabled Subsystem' */

    /* Sum: '<S88>/Add' */
    HW6_v1_B.Bkuk_e = HW6_v1_B.EnabledSubsystem_e.Product2 + rtb_MemoryX_k;

    /* ToWorkspace: '<S1>/To Workspace7' */
    {
      double locTime = ((HW6_v1_M->Timing.clockTick1) * 0.005);
      ;
      if (rtmIsMajorTimeStep(HW6_v1_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              HW6_v1_DW.ToWorkspace7_PWORK.LoggedData, &locTime,
                              &HW6_v1_B.Bkuk_e);
      }
    }
  }

  /* Sum: '<S2>/Sum1' incorporates:
   *  Constant: '<S2>/Constant6'
   *  DataTypeConversion: '<S1>/Data Type Conversion9'
   *  Inport: '<Root>/Sensors'
   */
  HW6_v1_B.Sum1_m = sensor_inport.HALSensors.HAL_acc_SI.z -
    HW6_v1_P.Constant6_Value_e;
  if (rtmIsMajorTimeStep(HW6_v1_M)) {
    /* Product: '<S237>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S8>/A'
     */
    HW6_v1_B.Akxhatkk1[0] = 0.0;
    HW6_v1_B.Akxhatkk1[0] += HW6_v1_P.A_Value[0] * HW6_v1_B.rtb_MemoryX_idx_0;
    HW6_v1_B.Akxhatkk1[0] += HW6_v1_P.A_Value[2] * HW6_v1_B.rtb_MemoryX_idx_1;
    HW6_v1_B.Akxhatkk1[1] = 0.0;
    HW6_v1_B.Akxhatkk1[1] += HW6_v1_P.A_Value[1] * HW6_v1_B.rtb_MemoryX_idx_0;
    HW6_v1_B.Akxhatkk1[1] += HW6_v1_P.A_Value[3] * HW6_v1_B.rtb_MemoryX_idx_1;

    /* Outputs for Enabled SubSystem: '<S237>/MeasurementUpdate' incorporates:
     *  EnablePort: '<S266>/Enable'
     */
    if (rtmIsMajorTimeStep(HW6_v1_M)) {
      /* Constant: '<S8>/Enable' */
      if (HW6_v1_P.Enable_Value) {
        HW6_v1_DW.MeasurementUpdate_MODE = true;
      } else {
        if (HW6_v1_DW.MeasurementUpdate_MODE) {
          /* Disable for Outport: '<S266>/L*(y[k]-yhat[k|k-1])' */
          HW6_v1_B.Product3[0] = HW6_v1_P.Lykyhatkk1_Y0;
          HW6_v1_B.Product3[1] = HW6_v1_P.Lykyhatkk1_Y0;
          HW6_v1_DW.MeasurementUpdate_MODE = false;
        }
      }
    }

    if (HW6_v1_DW.MeasurementUpdate_MODE) {
      /* Product: '<S266>/D[k]*u[k]' incorporates:
       *  Constant: '<S8>/D'
       *  Reshape: '<S8>/Reshapeu'
       */
      HW6_v1_B.Bkuk_e = HW6_v1_P.D_Value * HW6_v1_B.Sum1_m;

      /* Sum: '<S266>/Sum' incorporates:
       *  Constant: '<S8>/C'
       *  Product: '<S266>/C[k]*xhat[k|k-1]'
       *  Sum: '<S266>/Add1'
       */
      HW6_v1_B.Gain1 = HW6_v1_B.Reshapey - ((HW6_v1_P.C_Value[0] *
        HW6_v1_B.rtb_MemoryX_idx_0 + HW6_v1_P.C_Value[1] *
        HW6_v1_B.rtb_MemoryX_idx_1) + HW6_v1_B.Bkuk_e);

      /* Product: '<S266>/Product3' incorporates:
       *  Constant: '<S217>/KalmanGainL'
       */
      HW6_v1_B.Product3[0] = HW6_v1_P.KalmanGainL_Value[0] * HW6_v1_B.Gain1;
      HW6_v1_B.Product3[1] = HW6_v1_P.KalmanGainL_Value[1] * HW6_v1_B.Gain1;
    }

    /* End of Outputs for SubSystem: '<S237>/MeasurementUpdate' */

    /* Sum: '<S237>/Add' incorporates:
     *  Constant: '<S8>/B'
     *  Product: '<S237>/B[k]*u[k]'
     *  Reshape: '<S8>/Reshapeu'
     */
    HW6_v1_B.Add[0] = (HW6_v1_P.B_Value[0] * HW6_v1_B.Sum1_m +
                       HW6_v1_B.Akxhatkk1[0]) + HW6_v1_B.Product3[0];
    HW6_v1_B.Add[1] = (HW6_v1_P.B_Value[1] * HW6_v1_B.Sum1_m +
                       HW6_v1_B.Akxhatkk1[1]) + HW6_v1_B.Product3[1];

    /* Product: '<S81>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S5>/A'
     */
    HW6_v1_B.Bkuk_e = HW6_v1_P.A_Value_k * rtb_MemoryX_k;

    /* Outputs for Enabled SubSystem: '<S81>/MeasurementUpdate' */
    /* Constant: '<S5>/Enable' incorporates:
     *  Constant: '<S5>/C'
     *  Constant: '<S5>/D'
     *  Constant: '<S61>/KalmanGainL'
     *  Reshape: '<S5>/Reshapeu'
     */
    HW6_v1_MeasurementUpdate(HW6_v1_M, HW6_v1_P.Enable_Value_ir,
      HW6_v1_P.KalmanGainL_Value_b, rtb_Reshapey_c, HW6_v1_P.C_Value_h,
      rtb_MemoryX_k, HW6_v1_P.D_Value_i, HW6_v1_B.DataTypeConversion4,
      &HW6_v1_B.MeasurementUpdate_o, &HW6_v1_DW.MeasurementUpdate_o,
      &HW6_v1_P.MeasurementUpdate_o);

    /* End of Outputs for SubSystem: '<S81>/MeasurementUpdate' */

    /* Sum: '<S81>/Add' incorporates:
     *  Constant: '<S5>/B'
     *  Product: '<S81>/B[k]*u[k]'
     *  Reshape: '<S5>/Reshapeu'
     */
    rtb_Add_c = (HW6_v1_P.B_Value_h * HW6_v1_B.DataTypeConversion4 +
                 HW6_v1_B.Bkuk_e) + HW6_v1_B.MeasurementUpdate_o.Product3;

    /* Product: '<S133>/B[k]*u[k]' incorporates:
     *  Constant: '<S6>/B'
     *  Reshape: '<S6>/Reshapeu'
     */
    HW6_v1_B.Bkuk_e = HW6_v1_P.B_Value_g * HW6_v1_B.DataTypeConversion1;

    /* Outputs for Enabled SubSystem: '<S133>/MeasurementUpdate' */
    /* Constant: '<S6>/Enable' incorporates:
     *  Constant: '<S113>/KalmanGainL'
     *  Constant: '<S6>/C'
     *  Constant: '<S6>/D'
     *  Reshape: '<S6>/Reshapeu'
     */
    HW6_v1_MeasurementUpdate(HW6_v1_M, HW6_v1_P.Enable_Value_g,
      HW6_v1_P.KalmanGainL_Value_j, HW6_v1_B.Reshapey_e, HW6_v1_P.C_Value_a,
      HW6_v1_B.MemoryX_o, HW6_v1_P.D_Value_h, HW6_v1_B.DataTypeConversion1,
      &HW6_v1_B.MeasurementUpdate_h, &HW6_v1_DW.MeasurementUpdate_h,
      &HW6_v1_P.MeasurementUpdate_h);

    /* End of Outputs for SubSystem: '<S133>/MeasurementUpdate' */

    /* Sum: '<S133>/Add' incorporates:
     *  Constant: '<S6>/A'
     *  Product: '<S133>/A[k]*xhat[k|k-1]'
     */
    rtb_Add_h = (HW6_v1_P.A_Value_m * HW6_v1_B.MemoryX_o + HW6_v1_B.Bkuk_e) +
      HW6_v1_B.MeasurementUpdate_h.Product3;

    /* Product: '<S29>/B[k]*u[k]' incorporates:
     *  Constant: '<S4>/B'
     *  Reshape: '<S4>/Reshapeu'
     */
    HW6_v1_B.Bkuk_e = HW6_v1_P.B_Value_o * HW6_v1_B.DataTypeConversion3;

    /* Outputs for Enabled SubSystem: '<S29>/MeasurementUpdate' */
    /* Constant: '<S4>/Enable' incorporates:
     *  Constant: '<S4>/C'
     *  Constant: '<S4>/D'
     *  Constant: '<S9>/KalmanGainL'
     *  Reshape: '<S4>/Reshapeu'
     */
    HW6_v1_MeasurementUpdate(HW6_v1_M, HW6_v1_P.Enable_Value_i,
      HW6_v1_P.KalmanGainL_Value_m, rtb_Reshapey_p, HW6_v1_P.C_Value_ag,
      rtb_MemoryX_c, HW6_v1_P.D_Value_a, HW6_v1_B.DataTypeConversion3,
      &HW6_v1_B.MeasurementUpdate, &HW6_v1_DW.MeasurementUpdate,
      &HW6_v1_P.MeasurementUpdate);

    /* End of Outputs for SubSystem: '<S29>/MeasurementUpdate' */

    /* Sum: '<S29>/Add' incorporates:
     *  Constant: '<S4>/A'
     *  Product: '<S29>/A[k]*xhat[k|k-1]'
     */
    rtb_Add_cc = (HW6_v1_P.A_Value_e * rtb_MemoryX_c + HW6_v1_B.Bkuk_e) +
      HW6_v1_B.MeasurementUpdate.Product3;

    /* Product: '<S185>/B[k]*u[k]' incorporates:
     *  Constant: '<S7>/B'
     *  Reshape: '<S7>/Reshapeu'
     */
    HW6_v1_B.Bkuk_e = HW6_v1_P.B_Value_p * HW6_v1_B.DataTypeConversion2;

    /* Outputs for Enabled SubSystem: '<S185>/MeasurementUpdate' */
    /* Constant: '<S7>/Enable' incorporates:
     *  Constant: '<S165>/KalmanGainL'
     *  Constant: '<S7>/C'
     *  Constant: '<S7>/D'
     *  Reshape: '<S7>/Reshapeu'
     */
    HW6_v1_MeasurementUpdate(HW6_v1_M, HW6_v1_P.Enable_Value_m,
      HW6_v1_P.KalmanGainL_Value_g, HW6_v1_B.Reshapey_o, HW6_v1_P.C_Value_d,
      HW6_v1_B.MemoryX_j, HW6_v1_P.D_Value_e, HW6_v1_B.DataTypeConversion2,
      &HW6_v1_B.MeasurementUpdate_f, &HW6_v1_DW.MeasurementUpdate_f,
      &HW6_v1_P.MeasurementUpdate_f);

    /* End of Outputs for SubSystem: '<S185>/MeasurementUpdate' */

    /* Sum: '<S185>/Add' incorporates:
     *  Constant: '<S7>/A'
     *  Product: '<S185>/A[k]*xhat[k|k-1]'
     */
    rtb_Add_ck = (HW6_v1_P.A_Value_mn * HW6_v1_B.MemoryX_j + HW6_v1_B.Bkuk_e) +
      HW6_v1_B.MeasurementUpdate_f.Product3;
  }

  /* Integrator: '<S1>/Integrator' */
  HW6_v1_B.Integrator = HW6_v1_X.Integrator_CSTATE;

  /* Integrator: '<S1>/Integrator2' */
  HW6_v1_B.Integrator2 = HW6_v1_X.Integrator2_CSTATE;

  /* Integrator: '<S1>/Integrator4' */
  HW6_v1_B.Integrator4 = HW6_v1_X.Integrator4_CSTATE;
  if (rtmIsMajorTimeStep(HW6_v1_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(HW6_v1_M->rtwLogInfo, (HW6_v1_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(HW6_v1_M)) {
    if (rtmIsMajorTimeStep(HW6_v1_M)) {
      /* Update for Delay: '<S8>/MemoryX' */
      HW6_v1_DW.icLoad = 0U;
      HW6_v1_DW.MemoryX_DSTATE[0] = HW6_v1_B.Add[0];
      HW6_v1_DW.MemoryX_DSTATE[1] = HW6_v1_B.Add[1];

      /* Update for Delay: '<S6>/MemoryX' */
      HW6_v1_DW.icLoad_m = 0U;
      HW6_v1_DW.MemoryX_DSTATE_l = rtb_Add_h;

      /* Update for Delay: '<S7>/MemoryX' */
      HW6_v1_DW.icLoad_l = 0U;
      HW6_v1_DW.MemoryX_DSTATE_f = rtb_Add_ck;

      /* Update for Delay: '<S4>/MemoryX' */
      HW6_v1_DW.icLoad_h = 0U;
      HW6_v1_DW.MemoryX_DSTATE_j = rtb_Add_cc;

      /* Update for Delay: '<S5>/MemoryX' */
      HW6_v1_DW.icLoad_l4 = 0U;
      HW6_v1_DW.MemoryX_DSTATE_m = rtb_Add_c;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(HW6_v1_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(HW6_v1_M)!=-1) &&
          !((rtmGetTFinal(HW6_v1_M)-((HW6_v1_M->Timing.clockTick1) * 0.005)) >
            ((HW6_v1_M->Timing.clockTick1) * 0.005) * (DBL_EPSILON))) {
        rtmSetErrorStatus(HW6_v1_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&HW6_v1_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++HW6_v1_M->Timing.clockTick0;
    HW6_v1_M->Timing.t[0] = rtsiGetSolverStopTime(&HW6_v1_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      HW6_v1_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void HW6_v1_derivatives(void)
{
  XDot_HW6_v1_T *_rtXdot;
  _rtXdot = ((XDot_HW6_v1_T *) HW6_v1_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator11' */
  _rtXdot->Integrator11_CSTATE = HW6_v1_B.Sum1;

  /* Derivatives for Integrator: '<S1>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = HW6_v1_B.Integrator4;

  /* Derivatives for Integrator: '<S1>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = HW6_v1_B.DataTypeConversion3;

  /* Derivatives for Integrator: '<S1>/Integrator7' */
  _rtXdot->Integrator7_CSTATE = HW6_v1_B.DataTypeConversion4;

  /* Derivatives for Integrator: '<S1>/Integrator8' */
  _rtXdot->Integrator8_CSTATE = HW6_v1_B.DataTypeConversion5;

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = HW6_v1_B.Integrator;

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = HW6_v1_B.Integrator2;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = HW6_v1_B.DataTypeConversion1;

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = HW6_v1_B.DataTypeConversion2;

  /* Derivatives for Integrator: '<S1>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = HW6_v1_B.Sum1;
}

/* Model initialize function */
void HW6_v1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)HW6_v1_M, 0,
                sizeof(RT_MODEL_HW6_v1_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&HW6_v1_M->solverInfo, &HW6_v1_M->Timing.simTimeStep);
    rtsiSetTPtr(&HW6_v1_M->solverInfo, &rtmGetTPtr(HW6_v1_M));
    rtsiSetStepSizePtr(&HW6_v1_M->solverInfo, &HW6_v1_M->Timing.stepSize0);
    rtsiSetdXPtr(&HW6_v1_M->solverInfo, &HW6_v1_M->derivs);
    rtsiSetContStatesPtr(&HW6_v1_M->solverInfo, (real_T **)
                         &HW6_v1_M->contStates);
    rtsiSetNumContStatesPtr(&HW6_v1_M->solverInfo,
      &HW6_v1_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&HW6_v1_M->solverInfo,
      &HW6_v1_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&HW6_v1_M->solverInfo,
      &HW6_v1_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&HW6_v1_M->solverInfo,
      &HW6_v1_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&HW6_v1_M->solverInfo, (&rtmGetErrorStatus(HW6_v1_M)));
    rtsiSetRTModelPtr(&HW6_v1_M->solverInfo, HW6_v1_M);
  }

  rtsiSetSimTimeStep(&HW6_v1_M->solverInfo, MAJOR_TIME_STEP);
  HW6_v1_M->intgData.y = HW6_v1_M->odeY;
  HW6_v1_M->intgData.f[0] = HW6_v1_M->odeF[0];
  HW6_v1_M->intgData.f[1] = HW6_v1_M->odeF[1];
  HW6_v1_M->intgData.f[2] = HW6_v1_M->odeF[2];
  HW6_v1_M->contStates = ((X_HW6_v1_T *) &HW6_v1_X);
  rtsiSetSolverData(&HW6_v1_M->solverInfo, (void *)&HW6_v1_M->intgData);
  rtsiSetSolverName(&HW6_v1_M->solverInfo,"ode3");
  rtmSetTPtr(HW6_v1_M, &HW6_v1_M->Timing.tArray[0]);
  rtmSetTFinal(HW6_v1_M, 20.0);
  HW6_v1_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    HW6_v1_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(HW6_v1_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(HW6_v1_M->rtwLogInfo, (NULL));
    rtliSetLogT(HW6_v1_M->rtwLogInfo, "tout");
    rtliSetLogX(HW6_v1_M->rtwLogInfo, "");
    rtliSetLogXFinal(HW6_v1_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(HW6_v1_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(HW6_v1_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(HW6_v1_M->rtwLogInfo, 0);
    rtliSetLogDecimation(HW6_v1_M->rtwLogInfo, 1);
    rtliSetLogY(HW6_v1_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(HW6_v1_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(HW6_v1_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &HW6_v1_B), 0,
                sizeof(B_HW6_v1_T));

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* states (continuous) */
  {
    (void) memset((void *)&HW6_v1_X, 0,
                  sizeof(X_HW6_v1_T));
  }

  /* states (dwork) */
  (void) memset((void *)&HW6_v1_DW, 0,
                sizeof(DW_HW6_v1_T));

  /* external inputs */
  (void)memset(&cmd_inport, 0, sizeof(CommandBus));
  (void)memset(&sensor_inport, 0, sizeof(SensorsBus));

  /* external outputs */
  (void) memset((void *)&HW6_v1_Y, 0,
                sizeof(ExtY_HW6_v1_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(HW6_v1_M->rtwLogInfo, 0.0, rtmGetTFinal
    (HW6_v1_M), HW6_v1_M->Timing.stepSize0, (&rtmGetErrorStatus(HW6_v1_M)));

  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace1' */
  {
    static int_T rt_ToWksWidths[] = { 17 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 17 };

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
      "HW6_v1/Flight_Control_System/To Workspace1";
    HW6_v1_DW.ToWorkspace1_PWORK.LoggedData = rt_CreateStructLogVar(
      HW6_v1_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(HW6_v1_M),
      HW6_v1_M->Timing.stepSize0,
      (&rtmGetErrorStatus(HW6_v1_M)),
      "states",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (HW6_v1_DW.ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace2' */
  {
    static int_T rt_ToWksWidths[] = { 1 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 1 };

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
      "HW6_v1/Flight_Control_System/To Workspace2";
    HW6_v1_DW.ToWorkspace2_PWORK.LoggedData = rt_CreateStructLogVar(
      HW6_v1_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(HW6_v1_M),
      HW6_v1_M->Timing.stepSize0,
      (&rtmGetErrorStatus(HW6_v1_M)),
      "zkalman",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (HW6_v1_DW.ToWorkspace2_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace3' */
  {
    static int_T rt_ToWksWidths[] = { 1 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 1 };

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
      "HW6_v1/Flight_Control_System/To Workspace3";
    HW6_v1_DW.ToWorkspace3_PWORK.LoggedData = rt_CreateStructLogVar(
      HW6_v1_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(HW6_v1_M),
      HW6_v1_M->Timing.stepSize0,
      (&rtmGetErrorStatus(HW6_v1_M)),
      "wkalman",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (HW6_v1_DW.ToWorkspace3_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace4' */
  {
    static int_T rt_ToWksWidths[] = { 1 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 1 };

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
      "HW6_v1/Flight_Control_System/To Workspace4";
    HW6_v1_DW.ToWorkspace4_PWORK.LoggedData = rt_CreateStructLogVar(
      HW6_v1_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(HW6_v1_M),
      HW6_v1_M->Timing.stepSize0,
      (&rtmGetErrorStatus(HW6_v1_M)),
      "ukalman",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (HW6_v1_DW.ToWorkspace4_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace5' */
  {
    static int_T rt_ToWksWidths[] = { 1 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 1 };

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
      "HW6_v1/Flight_Control_System/To Workspace5";
    HW6_v1_DW.ToWorkspace5_PWORK.LoggedData = rt_CreateStructLogVar(
      HW6_v1_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(HW6_v1_M),
      HW6_v1_M->Timing.stepSize0,
      (&rtmGetErrorStatus(HW6_v1_M)),
      "vkalman",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (HW6_v1_DW.ToWorkspace5_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace6' */
  {
    static int_T rt_ToWksWidths[] = { 1 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 1 };

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
      "HW6_v1/Flight_Control_System/To Workspace6";
    HW6_v1_DW.ToWorkspace6_PWORK.LoggedData = rt_CreateStructLogVar(
      HW6_v1_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(HW6_v1_M),
      HW6_v1_M->Timing.stepSize0,
      (&rtmGetErrorStatus(HW6_v1_M)),
      "phikalman",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (HW6_v1_DW.ToWorkspace6_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace7' */
  {
    static int_T rt_ToWksWidths[] = { 1 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 1 };

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
      "HW6_v1/Flight_Control_System/To Workspace7";
    HW6_v1_DW.ToWorkspace7_PWORK.LoggedData = rt_CreateStructLogVar(
      HW6_v1_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(HW6_v1_M),
      HW6_v1_M->Timing.stepSize0,
      (&rtmGetErrorStatus(HW6_v1_M)),
      "thetakalman",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (HW6_v1_DW.ToWorkspace7_PWORK.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for Integrator: '<S1>/Integrator11' */
  HW6_v1_X.Integrator11_CSTATE = HW6_v1_P.Integrator11_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator5' */
  HW6_v1_X.Integrator5_CSTATE = HW6_v1_P.Integrator5_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator6' */
  HW6_v1_X.Integrator6_CSTATE = HW6_v1_P.Integrator6_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator7' */
  HW6_v1_X.Integrator7_CSTATE = HW6_v1_P.Integrator7_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator8' */
  HW6_v1_X.Integrator8_CSTATE = HW6_v1_P.Integrator8_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  HW6_v1_X.Integrator1_CSTATE = HW6_v1_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  HW6_v1_X.Integrator3_CSTATE = HW6_v1_P.Integrator3_IC;

  /* InitializeConditions for Delay: '<S8>/MemoryX' */
  HW6_v1_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S6>/MemoryX' */
  HW6_v1_DW.icLoad_m = 1U;

  /* InitializeConditions for Delay: '<S7>/MemoryX' */
  HW6_v1_DW.icLoad_l = 1U;

  /* InitializeConditions for Delay: '<S4>/MemoryX' */
  HW6_v1_DW.icLoad_h = 1U;

  /* InitializeConditions for Delay: '<S5>/MemoryX' */
  HW6_v1_DW.icLoad_l4 = 1U;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  HW6_v1_X.Integrator_CSTATE = HW6_v1_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  HW6_v1_X.Integrator2_CSTATE = HW6_v1_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator4' */
  HW6_v1_X.Integrator4_CSTATE = HW6_v1_P.Integrator4_IC;

  /* SystemInitialize for Enabled SubSystem: '<S244>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S268>/deltax' */
  HW6_v1_B.Product2[0] = HW6_v1_P.deltax_Y0;
  HW6_v1_B.Product2[1] = HW6_v1_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S244>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S140>/Enabled Subsystem' */
  HW6_v1_EnabledSubsystem_Init(&HW6_v1_B.EnabledSubsystem_d,
    &HW6_v1_P.EnabledSubsystem_d);

  /* End of SystemInitialize for SubSystem: '<S140>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S192>/Enabled Subsystem' */
  HW6_v1_EnabledSubsystem_Init(&HW6_v1_B.EnabledSubsystem_f,
    &HW6_v1_P.EnabledSubsystem_f);

  /* End of SystemInitialize for SubSystem: '<S192>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S36>/Enabled Subsystem' */
  HW6_v1_EnabledSubsystem_Init(&HW6_v1_B.EnabledSubsystem,
    &HW6_v1_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S36>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S88>/Enabled Subsystem' */
  HW6_v1_EnabledSubsystem_Init(&HW6_v1_B.EnabledSubsystem_e,
    &HW6_v1_P.EnabledSubsystem_e);

  /* End of SystemInitialize for SubSystem: '<S88>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S237>/MeasurementUpdate' */
  /* SystemInitialize for Outport: '<S266>/L*(y[k]-yhat[k|k-1])' */
  HW6_v1_B.Product3[0] = HW6_v1_P.Lykyhatkk1_Y0;
  HW6_v1_B.Product3[1] = HW6_v1_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S237>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S81>/MeasurementUpdate' */
  HW6_v1_MeasurementUpdate_Init(&HW6_v1_B.MeasurementUpdate_o,
    &HW6_v1_P.MeasurementUpdate_o);

  /* End of SystemInitialize for SubSystem: '<S81>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S133>/MeasurementUpdate' */
  HW6_v1_MeasurementUpdate_Init(&HW6_v1_B.MeasurementUpdate_h,
    &HW6_v1_P.MeasurementUpdate_h);

  /* End of SystemInitialize for SubSystem: '<S133>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S29>/MeasurementUpdate' */
  HW6_v1_MeasurementUpdate_Init(&HW6_v1_B.MeasurementUpdate,
    &HW6_v1_P.MeasurementUpdate);

  /* End of SystemInitialize for SubSystem: '<S29>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S185>/MeasurementUpdate' */
  HW6_v1_MeasurementUpdate_Init(&HW6_v1_B.MeasurementUpdate_f,
    &HW6_v1_P.MeasurementUpdate_f);

  /* End of SystemInitialize for SubSystem: '<S185>/MeasurementUpdate' */
}

/* Model terminate function */
void HW6_v1_terminate(void)
{
  /* (no terminate code required) */
}

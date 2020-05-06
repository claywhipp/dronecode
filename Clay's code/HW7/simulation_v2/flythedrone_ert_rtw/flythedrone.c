/*
 * flythedrone.c
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

#include "flythedrone.h"
#include "flythedrone_private.h"

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S5>/Cast To Single' */
uint8_T flag_outport;                  /* '<S1>/Manual Switch' */

/* Block signals (default storage) */
B_flythedrone_T flythedrone_B;

/* Block states (default storage) */
DW_flythedrone_T flythedrone_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_flythedrone_T flythedrone_Y;

/* Real-time model */
RT_MODEL_flythedrone_T flythedrone_M_;
RT_MODEL_flythedrone_T *const flythedrone_M = &flythedrone_M_;

/*
 * System initialize for enable system:
 *    '<S32>/MeasurementUpdate'
 *    '<S84>/MeasurementUpdate'
 *    '<S136>/MeasurementUpdate'
 *    '<S188>/MeasurementUpdate'
 */
void flythedr_MeasurementUpdate_Init(B_MeasurementUpdate_flythedro_T *localB,
  P_MeasurementUpdate_flythedro_T *localP)
{
  /* SystemInitialize for Outport: '<S61>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3 = localP->Lykyhatkk1_Y0;
}

/*
 * Disable for enable system:
 *    '<S32>/MeasurementUpdate'
 *    '<S84>/MeasurementUpdate'
 *    '<S136>/MeasurementUpdate'
 *    '<S188>/MeasurementUpdate'
 */
void flyth_MeasurementUpdate_Disable(B_MeasurementUpdate_flythedro_T *localB,
  DW_MeasurementUpdate_flythedr_T *localDW, P_MeasurementUpdate_flythedro_T
  *localP)
{
  /* Disable for Outport: '<S61>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3 = localP->Lykyhatkk1_Y0;
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Start for enable system:
 *    '<S32>/MeasurementUpdate'
 *    '<S84>/MeasurementUpdate'
 *    '<S136>/MeasurementUpdate'
 *    '<S188>/MeasurementUpdate'
 */
void flythed_MeasurementUpdate_Start(DW_MeasurementUpdate_flythedr_T *localDW)
{
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S32>/MeasurementUpdate'
 *    '<S84>/MeasurementUpdate'
 *    '<S136>/MeasurementUpdate'
 *    '<S188>/MeasurementUpdate'
 */
void flythedrone_MeasurementUpdate(boolean_T rtu_Enable, real_T rtu_Lk, real_T
  rtu_yk, real_T rtu_Ck, real_T rtu_xhatkk1, real_T rtu_Dk, real_T rtu_uk,
  B_MeasurementUpdate_flythedro_T *localB, DW_MeasurementUpdate_flythedr_T
  *localDW, P_MeasurementUpdate_flythedro_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S32>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S61>/Enable'
   */
  if (rtu_Enable) {
    localDW->MeasurementUpdate_MODE = true;

    /* Product: '<S61>/Product3' incorporates:
     *  Product: '<S61>/C[k]*xhat[k|k-1]'
     *  Product: '<S61>/D[k]*u[k]'
     *  Sum: '<S61>/Add1'
     *  Sum: '<S61>/Sum'
     */
    localB->Product3 = (rtu_yk - (rtu_Ck * rtu_xhatkk1 + rtu_Dk * rtu_uk)) *
      rtu_Lk;
  } else {
    if (localDW->MeasurementUpdate_MODE) {
      flyth_MeasurementUpdate_Disable(localB, localDW, localP);
    }
  }

  /* End of Outputs for SubSystem: '<S32>/MeasurementUpdate' */
}

/*
 * System initialize for enable system:
 *    '<S39>/Enabled Subsystem'
 *    '<S91>/Enabled Subsystem'
 *    '<S143>/Enabled Subsystem'
 *    '<S195>/Enabled Subsystem'
 */
void flythedro_EnabledSubsystem_Init(B_EnabledSubsystem_flythedron_T *localB,
  P_EnabledSubsystem_flythedron_T *localP)
{
  /* SystemInitialize for Outport: '<S63>/deltax' */
  localB->Product2 = localP->deltax_Y0;
}

/*
 * Disable for enable system:
 *    '<S39>/Enabled Subsystem'
 *    '<S91>/Enabled Subsystem'
 *    '<S143>/Enabled Subsystem'
 *    '<S195>/Enabled Subsystem'
 */
void flythe_EnabledSubsystem_Disable(B_EnabledSubsystem_flythedron_T *localB,
  DW_EnabledSubsystem_flythedro_T *localDW, P_EnabledSubsystem_flythedron_T
  *localP)
{
  /* Disable for Outport: '<S63>/deltax' */
  localB->Product2 = localP->deltax_Y0;
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Start for enable system:
 *    '<S39>/Enabled Subsystem'
 *    '<S91>/Enabled Subsystem'
 *    '<S143>/Enabled Subsystem'
 *    '<S195>/Enabled Subsystem'
 */
void flythedr_EnabledSubsystem_Start(DW_EnabledSubsystem_flythedro_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S39>/Enabled Subsystem'
 *    '<S91>/Enabled Subsystem'
 *    '<S143>/Enabled Subsystem'
 *    '<S195>/Enabled Subsystem'
 */
void flythedrone_EnabledSubsystem(boolean_T rtu_Enable, real_T rtu_Mk, real_T
  rtu_Ck, real_T rtu_yk, real_T rtu_xhatkk1, B_EnabledSubsystem_flythedron_T
  *localB, DW_EnabledSubsystem_flythedro_T *localDW,
  P_EnabledSubsystem_flythedron_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S39>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S63>/Enable'
   */
  if (rtu_Enable) {
    localDW->EnabledSubsystem_MODE = true;

    /* Product: '<S63>/Product2' incorporates:
     *  Product: '<S63>/Product'
     *  Sum: '<S63>/Add1'
     */
    localB->Product2 = (rtu_yk - rtu_Ck * rtu_xhatkk1) * rtu_Mk;
  } else {
    if (localDW->EnabledSubsystem_MODE) {
      flythe_EnabledSubsystem_Disable(localB, localDW, localP);
    }
  }

  /* End of Outputs for SubSystem: '<S39>/Enabled Subsystem' */
}

/* Model step function */
void flythedrone_step(void)
{
  /* local block i/o variables */
  real_T rtb_Sum4;
  real_T rtb_Gain;
  real_T rtb_Akxhatkk1_p;
  real_T rtb_Sum1;
  real_T tmp;
  int32_T i;
  real_T tmp_0;
  real_T tmp_1;

  /* MATLAB Function: '<S1>/Corrects sudden jumps' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion4'
   *  Inport: '<Root>/Sensors'
   *  Memory: '<S1>/Memory'
   */
  /* MATLAB Function 'Flight Control System/Corrects sudden jumps': '<S4>:1' */
  /* '<S4>:1:3' */
  /* '<S4>:1:5' */
  if (fabs(sensor_inport.HALSensors.HAL_ultrasound_SI.altitude -
           flythedrone_DW.Memory_PreviousInput) > 1.0) {
    /* '<S4>:1:7' */
    /* '<S4>:1:8' */
    flythedrone_B.h_corrected = flythedrone_DW.Memory_PreviousInput;
  } else {
    /* '<S4>:1:10' */
    flythedrone_B.h_corrected =
      sensor_inport.HALSensors.HAL_ultrasound_SI.altitude;
  }

  /* End of MATLAB Function: '<S1>/Corrects sudden jumps' */

  /* Gain: '<S1>/Gain' */
  rtb_Gain = flythedrone_P.Gain_Gain * flythedrone_B.h_corrected;

  /* Delay: '<S11>/MemoryX' incorporates:
   *  Constant: '<S11>/X0'
   */
  if (flythedrone_DW.icLoad != 0) {
    flythedrone_DW.MemoryX_DSTATE[0] = flythedrone_P.X0_Value[0];
    flythedrone_DW.MemoryX_DSTATE[1] = flythedrone_P.X0_Value[1];
  }

  /* Outputs for Enabled SubSystem: '<S247>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S271>/Enable'
   */
  /* Constant: '<S11>/Enable' */
  if (flythedrone_P.Enable_Value) {
    flythedrone_DW.EnabledSubsystem_MODE = true;

    /* Sum: '<S271>/Add1' incorporates:
     *  Constant: '<S11>/C'
     *  Delay: '<S11>/MemoryX'
     *  Product: '<S271>/Product'
     */
    rtb_Akxhatkk1_p = rtb_Gain - (flythedrone_P.C_Value[0] *
      flythedrone_DW.MemoryX_DSTATE[0] + flythedrone_P.C_Value[1] *
      flythedrone_DW.MemoryX_DSTATE[1]);

    /* Product: '<S271>/Product2' incorporates:
     *  Constant: '<S220>/KalmanGainM'
     */
    flythedrone_B.Product2[0] = flythedrone_P.KalmanGainM_Value[0] *
      rtb_Akxhatkk1_p;
    flythedrone_B.Product2[1] = flythedrone_P.KalmanGainM_Value[1] *
      rtb_Akxhatkk1_p;
  } else {
    if (flythedrone_DW.EnabledSubsystem_MODE) {
      /* Disable for Outport: '<S271>/deltax' */
      flythedrone_B.Product2[0] = flythedrone_P.deltax_Y0;
      flythedrone_B.Product2[1] = flythedrone_P.deltax_Y0;
      flythedrone_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S247>/Enabled Subsystem' */

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S2>/desired T states'
   *  Delay: '<S11>/MemoryX'
   *  Sum: '<S247>/Add'
   */
  flythedrone_B.Akxhatkk1[0] = flythedrone_P.desiredTstates_Value[0] -
    (flythedrone_B.Product2[0] + flythedrone_DW.MemoryX_DSTATE[0]);
  flythedrone_B.Akxhatkk1[1] = flythedrone_P.desiredTstates_Value[1] -
    (flythedrone_B.Product2[1] + flythedrone_DW.MemoryX_DSTATE[1]);

  /* Delay: '<S9>/MemoryX' incorporates:
   *  Constant: '<S9>/X0'
   */
  if (flythedrone_DW.icLoad_e != 0) {
    flythedrone_DW.MemoryX_DSTATE_j = flythedrone_P.X0_Value_g;
  }

  /* Outputs for Enabled SubSystem: '<S143>/Enabled Subsystem' */
  /* Constant: '<S9>/Enable' incorporates:
   *  Constant: '<S116>/KalmanGainM'
   *  Constant: '<S9>/C'
   *  DataTypeConversion: '<S1>/Data Type Conversion6'
   *  Delay: '<S9>/MemoryX'
   *  Inport: '<Root>/Sensors'
   */
  flythedrone_EnabledSubsystem(flythedrone_P.Enable_Value_k,
    flythedrone_P.KalmanGainM_Value_b, flythedrone_P.C_Value_f, (real_T)
    sensor_inport.VisionSensors.opticalFlow_data[0],
    flythedrone_DW.MemoryX_DSTATE_j, &flythedrone_B.EnabledSubsystem_i,
    &flythedrone_DW.EnabledSubsystem_i, &flythedrone_P.EnabledSubsystem_i);

  /* End of Outputs for SubSystem: '<S143>/Enabled Subsystem' */

  /* Sum: '<S143>/Add' incorporates:
   *  Delay: '<S9>/MemoryX'
   */
  rtb_Sum4 = flythedrone_B.EnabledSubsystem_i.Product2 +
    flythedrone_DW.MemoryX_DSTATE_j;

  /* Product: '<S3>/Divide2' incorporates:
   *  Constant: '<S3>/Constant'
   *  DataTypeConversion: '<S1>/Data Type Conversion7'
   *  Inport: '<Root>/Sensors'
   */
  flythedrone_B.theta = sensor_inport.HALSensors.HAL_acc_SI.x /
    flythedrone_P.Constant_Value;

  /* Delay: '<S8>/MemoryX' incorporates:
   *  Constant: '<S8>/X0'
   */
  if (flythedrone_DW.icLoad_i != 0) {
    flythedrone_DW.MemoryX_DSTATE_g = flythedrone_P.X0_Value_p;
  }

  /* Outputs for Enabled SubSystem: '<S91>/Enabled Subsystem' */
  /* Constant: '<S8>/Enable' incorporates:
   *  Constant: '<S64>/KalmanGainM'
   *  Constant: '<S8>/C'
   *  Delay: '<S8>/MemoryX'
   */
  flythedrone_EnabledSubsystem(flythedrone_P.Enable_Value_e,
    flythedrone_P.KalmanGainM_Value_g, flythedrone_P.C_Value_c,
    flythedrone_B.theta, flythedrone_DW.MemoryX_DSTATE_g,
    &flythedrone_B.EnabledSubsystem_g, &flythedrone_DW.EnabledSubsystem_g,
    &flythedrone_P.EnabledSubsystem_g);

  /* End of Outputs for SubSystem: '<S91>/Enabled Subsystem' */

  /* Sum: '<S2>/Sum2' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   *  Delay: '<S8>/MemoryX'
   *  Inport: '<Root>/Sensors'
   *  Sum: '<S91>/Add'
   */
  flythedrone_B.Sum2[0] = 0.0 - rtb_Sum4;
  flythedrone_B.Sum2[1] = 0.0 - (flythedrone_B.EnabledSubsystem_g.Product2 +
    flythedrone_DW.MemoryX_DSTATE_g);
  flythedrone_B.Sum2[2] = 0.0 - sensor_inport.HALSensors.HAL_gyro_SI.y;

  /* Delay: '<S10>/MemoryX' incorporates:
   *  Constant: '<S10>/X0'
   */
  if (flythedrone_DW.icLoad_j != 0) {
    flythedrone_DW.MemoryX_DSTATE_c = flythedrone_P.X0_Value_b;
  }

  /* Outputs for Enabled SubSystem: '<S195>/Enabled Subsystem' */
  /* Constant: '<S10>/Enable' incorporates:
   *  Constant: '<S10>/C'
   *  Constant: '<S168>/KalmanGainM'
   *  DataTypeConversion: '<S1>/Data Type Conversion5'
   *  Delay: '<S10>/MemoryX'
   *  Inport: '<Root>/Sensors'
   */
  flythedrone_EnabledSubsystem(flythedrone_P.Enable_Value_l,
    flythedrone_P.KalmanGainM_Value_d, flythedrone_P.C_Value_i, (real_T)
    sensor_inport.VisionSensors.opticalFlow_data[1],
    flythedrone_DW.MemoryX_DSTATE_c, &flythedrone_B.EnabledSubsystem_k,
    &flythedrone_DW.EnabledSubsystem_k, &flythedrone_P.EnabledSubsystem_k);

  /* End of Outputs for SubSystem: '<S195>/Enabled Subsystem' */

  /* Sum: '<S195>/Add' incorporates:
   *  Delay: '<S10>/MemoryX'
   */
  rtb_Sum4 = flythedrone_B.EnabledSubsystem_k.Product2 +
    flythedrone_DW.MemoryX_DSTATE_c;

  /* Product: '<S3>/Divide3' incorporates:
   *  Constant: '<S3>/Constant1'
   *  DataTypeConversion: '<S1>/Data Type Conversion8'
   *  Inport: '<Root>/Sensors'
   */
  flythedrone_B.phi = sensor_inport.HALSensors.HAL_acc_SI.y /
    flythedrone_P.Constant1_Value;

  /* Delay: '<S7>/MemoryX' incorporates:
   *  Constant: '<S7>/X0'
   */
  if (flythedrone_DW.icLoad_k != 0) {
    flythedrone_DW.MemoryX_DSTATE_a = flythedrone_P.X0_Value_k;
  }

  /* Outputs for Enabled SubSystem: '<S39>/Enabled Subsystem' */
  /* Constant: '<S7>/Enable' incorporates:
   *  Constant: '<S12>/KalmanGainM'
   *  Constant: '<S7>/C'
   *  Delay: '<S7>/MemoryX'
   */
  flythedrone_EnabledSubsystem(flythedrone_P.Enable_Value_d,
    flythedrone_P.KalmanGainM_Value_c, flythedrone_P.C_Value_p,
    flythedrone_B.phi, flythedrone_DW.MemoryX_DSTATE_a,
    &flythedrone_B.EnabledSubsystem, &flythedrone_DW.EnabledSubsystem,
    &flythedrone_P.EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S39>/Enabled Subsystem' */

  /* Sum: '<S2>/Sum3' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  Delay: '<S7>/MemoryX'
   *  Inport: '<Root>/Sensors'
   *  Sum: '<S39>/Add'
   */
  flythedrone_B.Sum3[0] = 0.0 - rtb_Sum4;
  flythedrone_B.Sum3[1] = 0.0 - (flythedrone_B.EnabledSubsystem.Product2 +
    flythedrone_DW.MemoryX_DSTATE_a);
  flythedrone_B.Sum3[2] = 0.0 - sensor_inport.HALSensors.HAL_gyro_SI.x;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  rtb_Sum4 = sensor_inport.HALSensors.HAL_gyro_SI.z;

  /* Sum: '<S2>/Sum4' */
  rtb_Sum4 = 0.0 - rtb_Sum4;

  /* Gain: '<S2>/Gain' */
  rtb_Akxhatkk1_p = flythedrone_P.Kthrust[0] * flythedrone_B.Akxhatkk1[0] +
    flythedrone_P.Kthrust[1] * flythedrone_B.Akxhatkk1[1];

  /* Gain: '<S2>/controller gain' */
  rtb_Sum1 = (flythedrone_P.Kelevator[0] * flythedrone_B.Sum2[0] +
              flythedrone_P.Kelevator[1] * flythedrone_B.Sum2[1]) +
    flythedrone_P.Kelevator[2] * flythedrone_B.Sum2[2];

  /* Gain: '<S2>/controller gain1' */
  tmp = (flythedrone_P.Kaileron[0] * flythedrone_B.Sum3[0] +
         flythedrone_P.Kaileron[1] * flythedrone_B.Sum3[1]) +
    flythedrone_P.Kaileron[2] * flythedrone_B.Sum3[2];

  /* SignalConversion generated from: '<S5>/Convert fom TEAR to n1,..,n4' incorporates:
   *  Gain: '<S2>/controller gain2'
   */
  tmp_0 = flythedrone_P.Krudder * rtb_Sum4;
  for (i = 0; i < 4; i++) {
    /* Gain: '<S5>/Convert fom TEAR to n1,..,n4' incorporates:
     *  Gain: '<S2>/Gain'
     *  Gain: '<S2>/controller gain'
     *  Gain: '<S2>/controller gain1'
     */
    tmp_1 = flythedrone_P.M_motor[i + 12] * tmp_0 + (flythedrone_P.M_motor[i + 8]
      * tmp + (flythedrone_P.M_motor[i + 4] * rtb_Sum1 + flythedrone_P.M_motor[i]
               * rtb_Akxhatkk1_p));

    /* DataTypeConversion: '<S5>/Cast To Single' */
    motors_outport[i] = (real32_T)tmp_1;

    /* Outport: '<Root>/Motors' */
    flythedrone_Y.Motors[i] = motors_outport[i];
  }

  /* ManualSwitch: '<S1>/Manual Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   */
  if (flythedrone_P.ManualSwitch_CurrentSetting == 1) {
    flag_outport = flythedrone_P.Constant2_Value;
  } else {
    flag_outport = flythedrone_P.Constant1_Value_d;
  }

  /* End of ManualSwitch: '<S1>/Manual Switch' */

  /* Outport: '<Root>/Flag' */
  flythedrone_Y.Flag = flag_outport;

  /* ToWorkspace: '<S1>/To Workspace' */
  {
    double locTime = flythedrone_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)
                          flythedrone_DW.ToWorkspace_PWORK.LoggedData, &locTime,
                          &motors_outport[0]);
  }

  /* ToWorkspace: '<S2>/To Workspace1' */
  {
    double locTime = flythedrone_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)
                          flythedrone_DW.ToWorkspace1_PWORK.LoggedData, &locTime,
                          &flythedrone_B.Sum2[0]);
  }

  /* ToWorkspace: '<S2>/To Workspace2' */
  {
    double locTime = flythedrone_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)
                          flythedrone_DW.ToWorkspace2_PWORK.LoggedData, &locTime,
                          &flythedrone_B.Sum3[0]);
  }

  /* ToWorkspace: '<S2>/To Workspace3' */
  {
    double locTime = flythedrone_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)
                          flythedrone_DW.ToWorkspace3_PWORK.LoggedData, &locTime,
                          &rtb_Sum4);
  }

  /* ToWorkspace: '<S2>/To Workspace6' */
  {
    double locTime = flythedrone_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)
                          flythedrone_DW.ToWorkspace6_PWORK.LoggedData, &locTime,
                          &flythedrone_B.Akxhatkk1[0]);
  }

  /* Sum: '<S3>/Sum1' incorporates:
   *  Constant: '<S3>/Constant6'
   *  DataTypeConversion: '<S1>/Data Type Conversion9'
   *  Inport: '<Root>/Sensors'
   */
  rtb_Sum1 = sensor_inport.HALSensors.HAL_acc_SI.z -
    flythedrone_P.Constant6_Value;

  /* Product: '<S240>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S11>/A'
   *  Delay: '<S11>/MemoryX'
   */
  flythedrone_B.Akxhatkk1[0] = 0.0;
  flythedrone_B.Akxhatkk1[0] += flythedrone_P.A_Value[0] *
    flythedrone_DW.MemoryX_DSTATE[0];
  flythedrone_B.Akxhatkk1[0] += flythedrone_P.A_Value[2] *
    flythedrone_DW.MemoryX_DSTATE[1];
  flythedrone_B.Akxhatkk1[1] = 0.0;
  flythedrone_B.Akxhatkk1[1] += flythedrone_P.A_Value[1] *
    flythedrone_DW.MemoryX_DSTATE[0];
  flythedrone_B.Akxhatkk1[1] += flythedrone_P.A_Value[3] *
    flythedrone_DW.MemoryX_DSTATE[1];

  /* Outputs for Enabled SubSystem: '<S240>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S269>/Enable'
   */
  /* Constant: '<S11>/Enable' */
  if (flythedrone_P.Enable_Value) {
    flythedrone_DW.MeasurementUpdate_MODE = true;

    /* Sum: '<S269>/Sum' incorporates:
     *  Constant: '<S11>/C'
     *  Constant: '<S11>/D'
     *  Delay: '<S11>/MemoryX'
     *  Product: '<S269>/C[k]*xhat[k|k-1]'
     *  Product: '<S269>/D[k]*u[k]'
     *  Sum: '<S269>/Add1'
     */
    rtb_Akxhatkk1_p = rtb_Gain - ((flythedrone_P.C_Value[0] *
      flythedrone_DW.MemoryX_DSTATE[0] + flythedrone_P.C_Value[1] *
      flythedrone_DW.MemoryX_DSTATE[1]) + flythedrone_P.D_Value * rtb_Sum1);

    /* Product: '<S269>/Product3' incorporates:
     *  Constant: '<S220>/KalmanGainL'
     */
    flythedrone_B.Product3[0] = flythedrone_P.KalmanGainL_Value[0] *
      rtb_Akxhatkk1_p;
    flythedrone_B.Product3[1] = flythedrone_P.KalmanGainL_Value[1] *
      rtb_Akxhatkk1_p;
  } else {
    if (flythedrone_DW.MeasurementUpdate_MODE) {
      /* Disable for Outport: '<S269>/L*(y[k]-yhat[k|k-1])' */
      flythedrone_B.Product3[0] = flythedrone_P.Lykyhatkk1_Y0;
      flythedrone_B.Product3[1] = flythedrone_P.Lykyhatkk1_Y0;
      flythedrone_DW.MeasurementUpdate_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S240>/MeasurementUpdate' */

  /* Outputs for Enabled SubSystem: '<S84>/MeasurementUpdate' */
  /* Constant: '<S8>/Enable' incorporates:
   *  Constant: '<S64>/KalmanGainL'
   *  Constant: '<S8>/C'
   *  Constant: '<S8>/D'
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   *  Delay: '<S8>/MemoryX'
   *  Inport: '<Root>/Sensors'
   */
  flythedrone_MeasurementUpdate(flythedrone_P.Enable_Value_e,
    flythedrone_P.KalmanGainL_Value_c, flythedrone_B.theta,
    flythedrone_P.C_Value_c, flythedrone_DW.MemoryX_DSTATE_g,
    flythedrone_P.D_Value_h, (real_T)sensor_inport.HALSensors.HAL_gyro_SI.y,
    &flythedrone_B.MeasurementUpdate_c, &flythedrone_DW.MeasurementUpdate_c,
    &flythedrone_P.MeasurementUpdate_c);

  /* End of Outputs for SubSystem: '<S84>/MeasurementUpdate' */

  /* Outputs for Enabled SubSystem: '<S136>/MeasurementUpdate' */
  /* Constant: '<S9>/Enable' incorporates:
   *  Constant: '<S116>/KalmanGainL'
   *  Constant: '<S9>/C'
   *  Constant: '<S9>/D'
   *  DataTypeConversion: '<S1>/Data Type Conversion6'
   *  DataTypeConversion: '<S1>/Data Type Conversion7'
   *  Delay: '<S9>/MemoryX'
   *  Inport: '<Root>/Sensors'
   */
  flythedrone_MeasurementUpdate(flythedrone_P.Enable_Value_k,
    flythedrone_P.KalmanGainL_Value_l, (real_T)
    sensor_inport.VisionSensors.opticalFlow_data[0], flythedrone_P.C_Value_f,
    flythedrone_DW.MemoryX_DSTATE_j, flythedrone_P.D_Value_m, (real_T)
    sensor_inport.HALSensors.HAL_acc_SI.x, &flythedrone_B.MeasurementUpdate_h,
    &flythedrone_DW.MeasurementUpdate_h, &flythedrone_P.MeasurementUpdate_h);

  /* End of Outputs for SubSystem: '<S136>/MeasurementUpdate' */

  /* Outputs for Enabled SubSystem: '<S32>/MeasurementUpdate' */
  /* Constant: '<S7>/Enable' incorporates:
   *  Constant: '<S12>/KalmanGainL'
   *  Constant: '<S7>/C'
   *  Constant: '<S7>/D'
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  Delay: '<S7>/MemoryX'
   *  Inport: '<Root>/Sensors'
   */
  flythedrone_MeasurementUpdate(flythedrone_P.Enable_Value_d,
    flythedrone_P.KalmanGainL_Value_k, flythedrone_B.phi,
    flythedrone_P.C_Value_p, flythedrone_DW.MemoryX_DSTATE_a,
    flythedrone_P.D_Value_o, (real_T)sensor_inport.HALSensors.HAL_gyro_SI.x,
    &flythedrone_B.MeasurementUpdate, &flythedrone_DW.MeasurementUpdate,
    &flythedrone_P.MeasurementUpdate);

  /* End of Outputs for SubSystem: '<S32>/MeasurementUpdate' */

  /* Outputs for Enabled SubSystem: '<S188>/MeasurementUpdate' */
  /* Constant: '<S10>/Enable' incorporates:
   *  Constant: '<S10>/C'
   *  Constant: '<S10>/D'
   *  Constant: '<S168>/KalmanGainL'
   *  DataTypeConversion: '<S1>/Data Type Conversion5'
   *  DataTypeConversion: '<S1>/Data Type Conversion8'
   *  Delay: '<S10>/MemoryX'
   *  Inport: '<Root>/Sensors'
   */
  flythedrone_MeasurementUpdate(flythedrone_P.Enable_Value_l,
    flythedrone_P.KalmanGainL_Value_e, (real_T)
    sensor_inport.VisionSensors.opticalFlow_data[1], flythedrone_P.C_Value_i,
    flythedrone_DW.MemoryX_DSTATE_c, flythedrone_P.D_Value_f, (real_T)
    sensor_inport.HALSensors.HAL_acc_SI.y, &flythedrone_B.MeasurementUpdate_ce,
    &flythedrone_DW.MeasurementUpdate_ce, &flythedrone_P.MeasurementUpdate_ce);

  /* End of Outputs for SubSystem: '<S188>/MeasurementUpdate' */

  /* Update for Memory: '<S1>/Memory' */
  flythedrone_DW.Memory_PreviousInput = flythedrone_B.h_corrected;

  /* Update for Delay: '<S11>/MemoryX' incorporates:
   *  Constant: '<S11>/B'
   *  Product: '<S240>/B[k]*u[k]'
   *  Sum: '<S240>/Add'
   */
  flythedrone_DW.icLoad = 0U;
  flythedrone_DW.MemoryX_DSTATE[0] = (flythedrone_P.B_Value[0] * rtb_Sum1 +
    flythedrone_B.Akxhatkk1[0]) + flythedrone_B.Product3[0];
  flythedrone_DW.MemoryX_DSTATE[1] = (flythedrone_P.B_Value[1] * rtb_Sum1 +
    flythedrone_B.Akxhatkk1[1]) + flythedrone_B.Product3[1];

  /* Update for Delay: '<S9>/MemoryX' incorporates:
   *  Constant: '<S9>/A'
   *  Constant: '<S9>/B'
   *  DataTypeConversion: '<S1>/Data Type Conversion7'
   *  Inport: '<Root>/Sensors'
   *  Product: '<S136>/A[k]*xhat[k|k-1]'
   *  Product: '<S136>/B[k]*u[k]'
   *  Sum: '<S136>/Add'
   */
  flythedrone_DW.icLoad_e = 0U;
  flythedrone_DW.MemoryX_DSTATE_j = (flythedrone_P.B_Value_o *
    sensor_inport.HALSensors.HAL_acc_SI.x + flythedrone_P.A_Value_i *
    flythedrone_DW.MemoryX_DSTATE_j) +
    flythedrone_B.MeasurementUpdate_h.Product3;

  /* Update for Delay: '<S8>/MemoryX' incorporates:
   *  Constant: '<S8>/A'
   *  Constant: '<S8>/B'
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   *  Inport: '<Root>/Sensors'
   *  Product: '<S84>/A[k]*xhat[k|k-1]'
   *  Product: '<S84>/B[k]*u[k]'
   *  Sum: '<S84>/Add'
   */
  flythedrone_DW.icLoad_i = 0U;
  flythedrone_DW.MemoryX_DSTATE_g = (flythedrone_P.B_Value_k *
    sensor_inport.HALSensors.HAL_gyro_SI.y + flythedrone_P.A_Value_j *
    flythedrone_DW.MemoryX_DSTATE_g) +
    flythedrone_B.MeasurementUpdate_c.Product3;

  /* Update for Delay: '<S10>/MemoryX' incorporates:
   *  Constant: '<S10>/A'
   *  Constant: '<S10>/B'
   *  DataTypeConversion: '<S1>/Data Type Conversion8'
   *  Inport: '<Root>/Sensors'
   *  Product: '<S188>/A[k]*xhat[k|k-1]'
   *  Product: '<S188>/B[k]*u[k]'
   *  Sum: '<S188>/Add'
   */
  flythedrone_DW.icLoad_j = 0U;
  flythedrone_DW.MemoryX_DSTATE_c = (flythedrone_P.B_Value_g *
    sensor_inport.HALSensors.HAL_acc_SI.y + flythedrone_P.A_Value_o *
    flythedrone_DW.MemoryX_DSTATE_c) +
    flythedrone_B.MeasurementUpdate_ce.Product3;

  /* Update for Delay: '<S7>/MemoryX' incorporates:
   *  Constant: '<S7>/A'
   *  Constant: '<S7>/B'
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  Inport: '<Root>/Sensors'
   *  Product: '<S32>/A[k]*xhat[k|k-1]'
   *  Product: '<S32>/B[k]*u[k]'
   *  Sum: '<S32>/Add'
   */
  flythedrone_DW.icLoad_k = 0U;
  flythedrone_DW.MemoryX_DSTATE_a = (flythedrone_P.B_Value_o0 *
    sensor_inport.HALSensors.HAL_gyro_SI.x + flythedrone_P.A_Value_m *
    flythedrone_DW.MemoryX_DSTATE_a) + flythedrone_B.MeasurementUpdate.Product3;

  /* Matfile logging */
  rt_UpdateTXYLogVars(flythedrone_M->rtwLogInfo,
                      (&flythedrone_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(flythedrone_M)!=-1) &&
        !((rtmGetTFinal(flythedrone_M)-flythedrone_M->Timing.taskTime0) >
          flythedrone_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(flythedrone_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++flythedrone_M->Timing.clockTick0)) {
    ++flythedrone_M->Timing.clockTickH0;
  }

  flythedrone_M->Timing.taskTime0 = flythedrone_M->Timing.clockTick0 *
    flythedrone_M->Timing.stepSize0 + flythedrone_M->Timing.clockTickH0 *
    flythedrone_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void flythedrone_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)flythedrone_M, 0,
                sizeof(RT_MODEL_flythedrone_T));
  rtmSetTFinal(flythedrone_M, 100.0);
  flythedrone_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    flythedrone_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(flythedrone_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(flythedrone_M->rtwLogInfo, (NULL));
    rtliSetLogT(flythedrone_M->rtwLogInfo, "tout");
    rtliSetLogX(flythedrone_M->rtwLogInfo, "");
    rtliSetLogXFinal(flythedrone_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(flythedrone_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(flythedrone_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(flythedrone_M->rtwLogInfo, 0);
    rtliSetLogDecimation(flythedrone_M->rtwLogInfo, 1);
    rtliSetLogY(flythedrone_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(flythedrone_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(flythedrone_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &flythedrone_B), 0,
                sizeof(B_flythedrone_T));

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* states (dwork) */
  (void) memset((void *)&flythedrone_DW, 0,
                sizeof(DW_flythedrone_T));

  /* external inputs */
  (void)memset(&cmd_inport, 0, sizeof(CommandBus));
  (void)memset(&sensor_inport, 0, sizeof(SensorsBus));

  /* external outputs */
  (void) memset((void *)&flythedrone_Y, 0,
                sizeof(ExtY_flythedrone_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(flythedrone_M->rtwLogInfo, 0.0, rtmGetTFinal
    (flythedrone_M), flythedrone_M->Timing.stepSize0, (&rtmGetErrorStatus
    (flythedrone_M)));

  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 4 };

    static int_T rt_ToWksNumDimensions[] = { 2 };

    static int_T rt_ToWksDimensions[] = { 1, 4 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4, 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

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
      "flythedrone/Flight Control System/To Workspace";
    flythedrone_DW.ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      flythedrone_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flythedrone_M),
      flythedrone_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flythedrone_M)),
      "motorspeeds",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (flythedrone_DW.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S2>/To Workspace1' */
  {
    static int_T rt_ToWksWidths[] = { 3 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 3 };

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
      "flythedrone/Flight Control System/Clay's Controller/To Workspace1";
    flythedrone_DW.ToWorkspace1_PWORK.LoggedData = rt_CreateStructLogVar(
      flythedrone_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flythedrone_M),
      flythedrone_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flythedrone_M)),
      "error2",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (flythedrone_DW.ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S2>/To Workspace2' */
  {
    static int_T rt_ToWksWidths[] = { 3 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 3 };

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
      "flythedrone/Flight Control System/Clay's Controller/To Workspace2";
    flythedrone_DW.ToWorkspace2_PWORK.LoggedData = rt_CreateStructLogVar(
      flythedrone_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flythedrone_M),
      flythedrone_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flythedrone_M)),
      "error3",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (flythedrone_DW.ToWorkspace2_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S2>/To Workspace3' */
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
      "flythedrone/Flight Control System/Clay's Controller/To Workspace3";
    flythedrone_DW.ToWorkspace3_PWORK.LoggedData = rt_CreateStructLogVar(
      flythedrone_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flythedrone_M),
      flythedrone_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flythedrone_M)),
      "error4",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (flythedrone_DW.ToWorkspace3_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S2>/To Workspace6' */
  {
    static int_T rt_ToWksWidths[] = { 2 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 2 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "Z w error" };

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
      "flythedrone/Flight Control System/Clay's Controller/To Workspace6";
    flythedrone_DW.ToWorkspace6_PWORK.LoggedData = rt_CreateStructLogVar(
      flythedrone_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flythedrone_M),
      flythedrone_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flythedrone_M)),
      "error1",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (flythedrone_DW.ToWorkspace6_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Enabled SubSystem: '<S247>/Enabled Subsystem' */
  flythedrone_DW.EnabledSubsystem_MODE = false;

  /* End of Start for SubSystem: '<S247>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S143>/Enabled Subsystem' */
  flythedr_EnabledSubsystem_Start(&flythedrone_DW.EnabledSubsystem_i);

  /* End of Start for SubSystem: '<S143>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S91>/Enabled Subsystem' */
  flythedr_EnabledSubsystem_Start(&flythedrone_DW.EnabledSubsystem_g);

  /* End of Start for SubSystem: '<S91>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S195>/Enabled Subsystem' */
  flythedr_EnabledSubsystem_Start(&flythedrone_DW.EnabledSubsystem_k);

  /* End of Start for SubSystem: '<S195>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S39>/Enabled Subsystem' */
  flythedr_EnabledSubsystem_Start(&flythedrone_DW.EnabledSubsystem);

  /* End of Start for SubSystem: '<S39>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S240>/MeasurementUpdate' */
  flythedrone_DW.MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S240>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S84>/MeasurementUpdate' */
  flythed_MeasurementUpdate_Start(&flythedrone_DW.MeasurementUpdate_c);

  /* End of Start for SubSystem: '<S84>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S136>/MeasurementUpdate' */
  flythed_MeasurementUpdate_Start(&flythedrone_DW.MeasurementUpdate_h);

  /* End of Start for SubSystem: '<S136>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S32>/MeasurementUpdate' */
  flythed_MeasurementUpdate_Start(&flythedrone_DW.MeasurementUpdate);

  /* End of Start for SubSystem: '<S32>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S188>/MeasurementUpdate' */
  flythed_MeasurementUpdate_Start(&flythedrone_DW.MeasurementUpdate_ce);

  /* End of Start for SubSystem: '<S188>/MeasurementUpdate' */

  /* InitializeConditions for Memory: '<S1>/Memory' */
  flythedrone_DW.Memory_PreviousInput = flythedrone_P.Memory_InitialCondition;

  /* InitializeConditions for Delay: '<S11>/MemoryX' */
  flythedrone_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S9>/MemoryX' */
  flythedrone_DW.icLoad_e = 1U;

  /* InitializeConditions for Delay: '<S8>/MemoryX' */
  flythedrone_DW.icLoad_i = 1U;

  /* InitializeConditions for Delay: '<S10>/MemoryX' */
  flythedrone_DW.icLoad_j = 1U;

  /* InitializeConditions for Delay: '<S7>/MemoryX' */
  flythedrone_DW.icLoad_k = 1U;

  /* SystemInitialize for Enabled SubSystem: '<S247>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S271>/deltax' */
  flythedrone_B.Product2[0] = flythedrone_P.deltax_Y0;
  flythedrone_B.Product2[1] = flythedrone_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S247>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S143>/Enabled Subsystem' */
  flythedro_EnabledSubsystem_Init(&flythedrone_B.EnabledSubsystem_i,
    &flythedrone_P.EnabledSubsystem_i);

  /* End of SystemInitialize for SubSystem: '<S143>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S91>/Enabled Subsystem' */
  flythedro_EnabledSubsystem_Init(&flythedrone_B.EnabledSubsystem_g,
    &flythedrone_P.EnabledSubsystem_g);

  /* End of SystemInitialize for SubSystem: '<S91>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S195>/Enabled Subsystem' */
  flythedro_EnabledSubsystem_Init(&flythedrone_B.EnabledSubsystem_k,
    &flythedrone_P.EnabledSubsystem_k);

  /* End of SystemInitialize for SubSystem: '<S195>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S39>/Enabled Subsystem' */
  flythedro_EnabledSubsystem_Init(&flythedrone_B.EnabledSubsystem,
    &flythedrone_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S39>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S240>/MeasurementUpdate' */
  /* SystemInitialize for Outport: '<S269>/L*(y[k]-yhat[k|k-1])' */
  flythedrone_B.Product3[0] = flythedrone_P.Lykyhatkk1_Y0;
  flythedrone_B.Product3[1] = flythedrone_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S240>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S84>/MeasurementUpdate' */
  flythedr_MeasurementUpdate_Init(&flythedrone_B.MeasurementUpdate_c,
    &flythedrone_P.MeasurementUpdate_c);

  /* End of SystemInitialize for SubSystem: '<S84>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S136>/MeasurementUpdate' */
  flythedr_MeasurementUpdate_Init(&flythedrone_B.MeasurementUpdate_h,
    &flythedrone_P.MeasurementUpdate_h);

  /* End of SystemInitialize for SubSystem: '<S136>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S32>/MeasurementUpdate' */
  flythedr_MeasurementUpdate_Init(&flythedrone_B.MeasurementUpdate,
    &flythedrone_P.MeasurementUpdate);

  /* End of SystemInitialize for SubSystem: '<S32>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S188>/MeasurementUpdate' */
  flythedr_MeasurementUpdate_Init(&flythedrone_B.MeasurementUpdate_ce,
    &flythedrone_P.MeasurementUpdate_ce);

  /* End of SystemInitialize for SubSystem: '<S188>/MeasurementUpdate' */
}

/* Model terminate function */
void flythedrone_terminate(void)
{
  /* (no terminate code required) */
}

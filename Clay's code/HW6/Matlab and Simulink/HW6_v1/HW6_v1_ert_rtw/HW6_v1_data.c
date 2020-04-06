/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HW6_v1_data.c
 *
 * Code generated for Simulink model 'HW6_v1'.
 *
 * Model version                  : 1.134
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Apr  5 22:41:58 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HW6_v1.h"
#include "HW6_v1_private.h"

/* Block parameters (default storage) */
P_HW6_v1_T HW6_v1_P = {
  /* Mask Parameter: IntervalTest_lowlimit
   * Referenced by: '<S10>/Lower Limit'
   */
  -0.5,

  /* Mask Parameter: IntervalTest_lowlimit_n
   * Referenced by: '<S11>/Lower Limit'
   */
  -0.5,

  /* Mask Parameter: IntervalTest_uplimit
   * Referenced by: '<S10>/Upper Limit'
   */
  0.5,

  /* Mask Parameter: IntervalTest_uplimit_c
   * Referenced by: '<S11>/Upper Limit'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S3>/Check sign of input'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S269>/L*(y[k]-yhat[k|k-1])'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S271>/deltax'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator11'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator7'
   */
  0.0,

  /* Expression: -9.4351
   * Referenced by: '<S1>/Constant6'
   */
  -9.4351,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator8'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator3'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S220>/KalmanGainM'
   */
  { 0.084544184579942824, 0.74632044119690788 },

  /* Expression: pInitialization.C
   * Referenced by: '<S9>/C'
   */
  { 1.0, 0.0 },

  /* Expression: pInitialization.X0
   * Referenced by: '<S9>/X0'
   */
  { 0.0, 0.0 },

  /* Expression: pInitialization.M
   * Referenced by: '<S116>/KalmanGainM'
   */
  0.095124921972504051,

  /* Expression: pInitialization.C
   * Referenced by: '<S7>/C'
   */
  1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S7>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S168>/KalmanGainM'
   */
  0.095124921972504051,

  /* Expression: pInitialization.C
   * Referenced by: '<S8>/C'
   */
  1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S8>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S12>/KalmanGainM'
   */
  0.09512492197250369,

  /* Expression: pInitialization.C
   * Referenced by: '<S4>/C'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S2>/Constant3'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S2>/Constant4'
   */
  -0.5,

  /* Expression: 0
   * Referenced by: '<S2>/Check sign of input'
   */
  0.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S4>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S64>/KalmanGainM'
   */
  0.916079783099616,

  /* Expression: pInitialization.C
   * Referenced by: '<S5>/C'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain'
   */
  -1.0,

  /* Expression: 0.5
   * Referenced by: '<S3>/Constant3'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S3>/Constant4'
   */
  -0.5,

  /* Expression: pInitialization.X0
   * Referenced by: '<S5>/X0'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator4'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S4>/A'
   */
  1.0,

  /* Expression: pInitialization.B
   * Referenced by: '<S4>/B'
   */
  0.005,

  /* Expression: pInitialization.L
   * Referenced by: '<S12>/KalmanGainL'
   */
  0.095124921972503718,

  /* Expression: pInitialization.D
   * Referenced by: '<S4>/D'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S5>/A'
   */
  1.0,

  /* Expression: pInitialization.B
   * Referenced by: '<S5>/B'
   */
  0.005,

  /* Expression: pInitialization.L
   * Referenced by: '<S64>/KalmanGainL'
   */
  0.9160797830996158,

  /* Expression: pInitialization.D
   * Referenced by: '<S5>/D'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S7>/A'
   */
  1.0,

  /* Expression: pInitialization.B
   * Referenced by: '<S7>/B'
   */
  0.005,

  /* Expression: pInitialization.L
   * Referenced by: '<S116>/KalmanGainL'
   */
  0.095124921972504009,

  /* Expression: pInitialization.D
   * Referenced by: '<S7>/D'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S8>/A'
   */
  1.0,

  /* Expression: pInitialization.B
   * Referenced by: '<S8>/B'
   */
  0.005,

  /* Expression: pInitialization.L
   * Referenced by: '<S168>/KalmanGainL'
   */
  0.095124921972504009,

  /* Expression: pInitialization.D
   * Referenced by: '<S8>/D'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S9>/A'
   */
  { 1.0, 0.0, 0.005, 1.0 },

  /* Expression: pInitialization.B
   * Referenced by: '<S9>/B'
   */
  { 1.25E-5, 0.005 },

  /* Expression: pInitialization.L
   * Referenced by: '<S220>/KalmanGainL'
   */
  { 0.08827578678592736, 0.74632044119691054 },

  /* Expression: pInitialization.D
   * Referenced by: '<S9>/D'
   */
  0.0,

  /* Computed Parameter: Saturation1_UpperSat
   * Referenced by: '<S1>/Saturation1'
   */
  500.0F,

  /* Computed Parameter: Saturation1_LowerSat
   * Referenced by: '<S1>/Saturation1'
   */
  0.0F,

  /* Expression: true()
   * Referenced by: '<S9>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S7>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S8>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S4>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S5>/Enable'
   */
  1,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S1>/Constant1'
   */
  1U,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S1>/Constant2'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<S1>/Manual Switch'
   */
  1U,

  /* Start of '<S195>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S219>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S195>/Enabled Subsystem' */

  /* Start of '<S188>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S217>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S188>/MeasurementUpdate' */

  /* Start of '<S143>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S167>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S143>/Enabled Subsystem' */

  /* Start of '<S136>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S165>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S136>/MeasurementUpdate' */

  /* Start of '<S91>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S115>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S91>/Enabled Subsystem' */

  /* Start of '<S84>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S113>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S84>/MeasurementUpdate' */

  /* Start of '<S39>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S63>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S39>/Enabled Subsystem' */

  /* Start of '<S32>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S61>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  /* End of '<S32>/MeasurementUpdate' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

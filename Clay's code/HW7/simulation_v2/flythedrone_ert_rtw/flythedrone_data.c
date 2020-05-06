/*
 * flythedrone_data.c
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

/* Block parameters (default storage) */
P_flythedrone_T flythedrone_P = {
  /* Variable: Kaileron
   * Referenced by: '<S2>/controller gain1'
   */
  { 4.4721359549995912, 35.912492705491147, 14.470700608502495 },

  /* Variable: Kelevator
   * Referenced by: '<S2>/controller gain'
   */
  { -4.4721359549995832, 36.004607427205308, 14.546200653562581 },

  /* Variable: Krudder
   * Referenced by: '<S2>/controller gain2'
   */
  14.142135623730942,

  /* Variable: Kthrust
   * Referenced by: '<S2>/Gain'
   */
  { -4.4721359549995849, -18.006276648713037 },

  /* Variable: M_motor
   * Referenced by: '<S5>/Convert fom TEAR to n1,..,n4'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, 1.0, -1.0, -1.0, 1.0, -1.0, 1.0,
    -1.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S269>/L*(y[k]-yhat[k|k-1])'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S271>/deltax'
   */
  0.0,

  /* Expression: [-1.5; 0]
   * Referenced by: '<S2>/desired T states'
   */
  { -1.5, 0.0 },

  /* Expression: pInitialization.M
   * Referenced by: '<S220>/KalmanGainM'
   */
  { 0.031128643924278818, 0.098431263126902244 },

  /* Expression: pInitialization.C
   * Referenced by: '<S11>/C'
   */
  { 1.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S1>/Memory'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain'
   */
  -1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S11>/X0'
   */
  { 0.0, 0.0 },

  /* Expression: pInitialization.M
   * Referenced by: '<S116>/KalmanGainM'
   */
  0.095124921972504051,

  /* Expression: pInitialization.C
   * Referenced by: '<S9>/C'
   */
  1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S9>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S64>/KalmanGainM'
   */
  0.095124921972504051,

  /* Expression: pInitialization.C
   * Referenced by: '<S8>/C'
   */
  1.0,

  /* Expression: 9.81
   * Referenced by: '<S3>/Constant'
   */
  9.81,

  /* Expression: pInitialization.X0
   * Referenced by: '<S8>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S168>/KalmanGainM'
   */
  0.095124921972504051,

  /* Expression: pInitialization.C
   * Referenced by: '<S10>/C'
   */
  1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S10>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S12>/KalmanGainM'
   */
  0.095124921972504051,

  /* Expression: pInitialization.C
   * Referenced by: '<S7>/C'
   */
  1.0,

  /* Expression: -9.81
   * Referenced by: '<S3>/Constant1'
   */
  -9.81,

  /* Expression: pInitialization.X0
   * Referenced by: '<S7>/X0'
   */
  0.0,

  /* Expression: -9.4351
   * Referenced by: '<S3>/Constant6'
   */
  -9.4351,

  /* Expression: pInitialization.A
   * Referenced by: '<S11>/A'
   */
  { 1.0, 0.0, 0.005, 1.0 },

  /* Expression: pInitialization.B
   * Referenced by: '<S11>/B'
   */
  { 1.25E-5, 0.005 },

  /* Expression: pInitialization.L
   * Referenced by: '<S220>/KalmanGainL'
   */
  { 0.03162080023991333, 0.098431263126901078 },

  /* Expression: pInitialization.D
   * Referenced by: '<S11>/D'
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
   * Referenced by: '<S64>/KalmanGainL'
   */
  0.095124921972504009,

  /* Expression: pInitialization.D
   * Referenced by: '<S8>/D'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S9>/A'
   */
  1.0,

  /* Expression: pInitialization.B
   * Referenced by: '<S9>/B'
   */
  0.005,

  /* Expression: pInitialization.L
   * Referenced by: '<S116>/KalmanGainL'
   */
  0.095124921972504009,

  /* Expression: pInitialization.D
   * Referenced by: '<S9>/D'
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
   * Referenced by: '<S12>/KalmanGainL'
   */
  0.095124921972504009,

  /* Expression: pInitialization.D
   * Referenced by: '<S7>/D'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S10>/A'
   */
  1.0,

  /* Expression: pInitialization.B
   * Referenced by: '<S10>/B'
   */
  0.005,

  /* Expression: pInitialization.L
   * Referenced by: '<S168>/KalmanGainL'
   */
  0.095124921972504009,

  /* Expression: pInitialization.D
   * Referenced by: '<S10>/D'
   */
  0.0,

  /* Expression: true()
   * Referenced by: '<S11>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S9>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S8>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S10>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S7>/Enable'
   */
  1,

  /* Computed Parameter: Constant1_Value_d
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

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HW6_v1_data.c
 *
 * Code generated for Simulink model 'HW6_v1'.
 *
 * Model version                  : 1.140
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed May  6 14:58:41 2020
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
  /* Expression: 0
   * Referenced by: '<S266>/L*(y[k]-yhat[k|k-1])'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S268>/deltax'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain1'
   */
  -1.0,

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
   * Referenced by: '<S217>/KalmanGainM'
   */
  { 0.031128643924278818, 0.098431263126902244 },

  /* Expression: pInitialization.C
   * Referenced by: '<S8>/C'
   */
  { 1.0, 0.0 },

  /* Expression: pInitialization.X0
   * Referenced by: '<S8>/X0'
   */
  { 0.0, 0.0 },

  /* Expression: pInitialization.M
   * Referenced by: '<S113>/KalmanGainM'
   */
  0.095124921972504051,

  /* Expression: pInitialization.C
   * Referenced by: '<S6>/C'
   */
  1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S6>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S165>/KalmanGainM'
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
   * Referenced by: '<S9>/KalmanGainM'
   */
  0.095124921972504051,

  /* Expression: pInitialization.C
   * Referenced by: '<S4>/C'
   */
  1.0,

  /* Expression: -9.81
   * Referenced by: '<S2>/Constant1'
   */
  -9.81,

  /* Expression: pInitialization.X0
   * Referenced by: '<S4>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S61>/KalmanGainM'
   */
  0.095124921972504051,

  /* Expression: pInitialization.C
   * Referenced by: '<S5>/C'
   */
  1.0,

  /* Expression: 9.81
   * Referenced by: '<S2>/Constant'
   */
  9.81,

  /* Expression: pInitialization.X0
   * Referenced by: '<S5>/X0'
   */
  0.0,

  /* Expression: -9.4351
   * Referenced by: '<S2>/Constant6'
   */
  -9.4351,

  /* Expression: pInitialization.A
   * Referenced by: '<S8>/A'
   */
  { 1.0, 0.0, 0.005, 1.0 },

  /* Expression: pInitialization.B
   * Referenced by: '<S8>/B'
   */
  { 1.25E-5, 0.005 },

  /* Expression: pInitialization.L
   * Referenced by: '<S217>/KalmanGainL'
   */
  { 0.03162080023991333, 0.098431263126901078 },

  /* Expression: pInitialization.D
   * Referenced by: '<S8>/D'
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
   * Referenced by: '<S61>/KalmanGainL'
   */
  0.095124921972504009,

  /* Expression: pInitialization.D
   * Referenced by: '<S5>/D'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S6>/A'
   */
  1.0,

  /* Expression: pInitialization.B
   * Referenced by: '<S6>/B'
   */
  0.005,

  /* Expression: pInitialization.L
   * Referenced by: '<S113>/KalmanGainL'
   */
  0.095124921972504009,

  /* Expression: pInitialization.D
   * Referenced by: '<S6>/D'
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
   * Referenced by: '<S9>/KalmanGainL'
   */
  0.095124921972504009,

  /* Expression: pInitialization.D
   * Referenced by: '<S4>/D'
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
   * Referenced by: '<S165>/KalmanGainL'
   */
  0.095124921972504009,

  /* Expression: pInitialization.D
   * Referenced by: '<S7>/D'
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

  /* Computed Parameter: Saturation1_UpperSat
   * Referenced by: '<S1>/Saturation1'
   */
  500.0F,

  /* Computed Parameter: Saturation1_LowerSat
   * Referenced by: '<S1>/Saturation1'
   */
  0.0F,

  /* Expression: true()
   * Referenced by: '<S8>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S6>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S7>/Enable'
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

  /* Start of '<S192>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S216>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S192>/Enabled Subsystem' */

  /* Start of '<S185>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S214>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S185>/MeasurementUpdate' */

  /* Start of '<S140>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S164>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S140>/Enabled Subsystem' */

  /* Start of '<S133>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S162>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S133>/MeasurementUpdate' */

  /* Start of '<S88>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S112>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S88>/Enabled Subsystem' */

  /* Start of '<S81>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S110>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S81>/MeasurementUpdate' */

  /* Start of '<S36>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S60>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S36>/Enabled Subsystem' */

  /* Start of '<S29>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S58>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  /* End of '<S29>/MeasurementUpdate' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

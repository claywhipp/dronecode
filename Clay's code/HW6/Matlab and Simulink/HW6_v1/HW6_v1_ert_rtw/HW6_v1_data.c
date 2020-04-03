/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HW6_v1_data.c
 *
 * Code generated for Simulink model 'HW6_v1'.
 *
 * Model version                  : 1.126
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Fri Apr  3 12:59:16 2020
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
   * Referenced by: '<S265>/L*(y[k]-yhat[k|k-1])'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S267>/deltax'
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
   * Referenced by: '<S216>/KalmanGainM'
   */
  { 0.084544184579942824, 0.74632044119690788 },

  /* Expression: pInitialization.C
   * Referenced by: '<S7>/C'
   */
  { 1.0, 0.0 },

  /* Expression: pInitialization.X0
   * Referenced by: '<S7>/X0'
   */
  { 0.0, 0.0 },

  /* Expression: pInitialization.M
   * Referenced by: '<S112>/KalmanGainM'
   */
  0.70962096703595157,

  /* Expression: pInitialization.C
   * Referenced by: '<S5>/C'
   */
  1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S5>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S164>/KalmanGainM'
   */
  0.99019513592784836,

  /* Expression: pInitialization.C
   * Referenced by: '<S6>/C'
   */
  1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S6>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S8>/KalmanGainM'
   */
  0.09512492197250369,

  /* Expression: pInitialization.C
   * Referenced by: '<S2>/C'
   */
  1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S2>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S60>/KalmanGainM'
   */
  0.916079783099616,

  /* Expression: pInitialization.C
   * Referenced by: '<S3>/C'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain'
   */
  -1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S3>/X0'
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
   * Referenced by: '<S2>/A'
   */
  1.0,

  /* Expression: pInitialization.B
   * Referenced by: '<S2>/B'
   */
  0.005,

  /* Expression: pInitialization.L
   * Referenced by: '<S8>/KalmanGainL'
   */
  0.095124921972503718,

  /* Expression: pInitialization.D
   * Referenced by: '<S2>/D'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S3>/A'
   */
  1.0,

  /* Expression: pInitialization.B
   * Referenced by: '<S3>/B'
   */
  0.005,

  /* Expression: pInitialization.L
   * Referenced by: '<S60>/KalmanGainL'
   */
  0.9160797830996158,

  /* Expression: pInitialization.D
   * Referenced by: '<S3>/D'
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
   * Referenced by: '<S112>/KalmanGainL'
   */
  0.709620967035952,

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
   * Referenced by: '<S164>/KalmanGainL'
   */
  0.99019513592784891,

  /* Expression: pInitialization.D
   * Referenced by: '<S6>/D'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S7>/A'
   */
  { 1.0, 0.0, 0.005, 1.0 },

  /* Expression: pInitialization.B
   * Referenced by: '<S7>/B'
   */
  { 1.25E-5, 0.005 },

  /* Expression: pInitialization.L
   * Referenced by: '<S216>/KalmanGainL'
   */
  { 0.08827578678592736, 0.74632044119691054 },

  /* Expression: pInitialization.D
   * Referenced by: '<S7>/D'
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
   * Referenced by: '<S7>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S5>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S6>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S2>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S3>/Enable'
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

  /* Start of '<S191>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S215>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S191>/Enabled Subsystem' */

  /* Start of '<S184>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S213>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S184>/MeasurementUpdate' */

  /* Start of '<S139>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S163>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S139>/Enabled Subsystem' */

  /* Start of '<S132>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S161>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S132>/MeasurementUpdate' */

  /* Start of '<S87>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S111>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S87>/Enabled Subsystem' */

  /* Start of '<S80>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S109>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S80>/MeasurementUpdate' */

  /* Start of '<S35>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S59>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S35>/Enabled Subsystem' */

  /* Start of '<S28>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S57>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  /* End of '<S28>/MeasurementUpdate' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

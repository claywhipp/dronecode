/*
 * HW6_Simulink.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "HW6_Simulink".
 *
 * Model version              : 1.81
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Mon Mar 30 12:31:25 2020
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HW6_Simulink.h"
#include "HW6_Simulink_private.h"

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S1>/Saturation1' */
uint8_T flag_outport;                  /* '<S1>/Manual Switch' */

/* Block signals (default storage) */
B_HW6_Simulink_T HW6_Simulink_B;

/* Continuous states */
X_HW6_Simulink_T HW6_Simulink_X;

/* Block states (default storage) */
DW_HW6_Simulink_T HW6_Simulink_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_HW6_Simulink_T HW6_Simulink_Y;

/* Real-time model */
RT_MODEL_HW6_Simulink_T HW6_Simulink_M_;
RT_MODEL_HW6_Simulink_T *const HW6_Simulink_M = &HW6_Simulink_M_;

/* Simplified version of numjac.cpp, for use with RTW. */
void local_numjac( RTWSolverInfo *si, real_T *y, const real_T *Fty, real_T *fac,
                  real_T *dFdy )
{
  /* constants */
  real_T THRESH = 1e-6;
  real_T EPS = 2.2e-16;                /* utGetEps(); */
  real_T BL = pow(EPS, 0.75);
  real_T BU = pow(EPS, 0.25);
  real_T FACMIN = pow(EPS, 0.78);
  real_T FACMAX = 0.1;
  int_T nx = 10;
  real_T *x = rtsiGetContStates(si);
  real_T del;
  real_T difmax;
  real_T FdelRowmax;
  real_T temp;
  real_T Fdiff;
  real_T maybe;
  real_T xscale;
  real_T fscale;
  real_T *p;
  int_T rowmax;
  int_T i,j;
  if (x != y)
    (void) memcpy(x, y,
                  (uint_T)nx*sizeof(real_T));
  rtsiSetSolverComputingJacobian(si,true);
  for (p = dFdy, j = 0; j < nx; j++, p += nx) {
    /* Select an increment del for a difference approximation to
       column j of dFdy.  The vector fac accounts for experience
       gained in previous calls to numjac. */
    xscale = fabs(x[j]);
    if (xscale < THRESH)
      xscale = THRESH;
    temp = (x[j] + fac[j]*xscale);
    del = temp - y[j];
    while (del == 0.0) {
      if (fac[j] < FACMAX) {
        fac[j] *= 100.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
        temp = (x[j] + fac[j]*xscale);
        del = temp - x[j];
      } else {
        del = THRESH;                  /* thresh is nonzero */
        break;
      }
    }

    /* Keep del pointing into region. */
    if (Fty[j] >= 0.0)
      del = fabs(del);
    else
      del = -fabs(del);

    /* Form a difference approximation to column j of dFdy. */
    temp = x[j];
    x[j] += del;
    HW6_Simulink_step();
    rtsiSetdX(si,p);
    HW6_Simulink_derivatives();
    x[j] = temp;
    difmax = 0.0;
    rowmax = 0;
    FdelRowmax = p[0];
    temp = 1.0 / del;
    for (i = 0; i < nx; i++) {
      Fdiff = p[i] - Fty[i];
      maybe = fabs(Fdiff);
      if (maybe > difmax) {
        difmax = maybe;
        rowmax = i;
        FdelRowmax = p[i];
      }

      p[i] = temp * Fdiff;
    }

    /* Adjust fac for next call to numjac. */
    if (((FdelRowmax != 0.0) && (Fty[rowmax] != 0.0)) || (difmax == 0.0)) {
      fscale = fabs(FdelRowmax);
      if (fscale < fabs(Fty[rowmax]))
        fscale = fabs(Fty[rowmax]);
      if (difmax <= BL*fscale) {
        /* The difference is small, so increase the increment. */
        fac[j] *= 10.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
      } else if (difmax > BU*fscale) {
        /* The difference is large, so reduce the increment. */
        fac[j] *= 0.1;
        if (fac[j] < FACMIN)
          fac[j] = FACMIN;
      }
    }
  }

  rtsiSetSolverComputingJacobian(si,false);
}                                      /* end local_numjac */

/*
 * This function updates continuous states using the ODE14x fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static int_T rt_ODE14x_N[4] = { 12, 8, 6, 4 };

  time_T t0 = rtsiGetT(si);
  time_T t1 = t0;
  time_T h = rtsiGetStepSize(si);
  real_T *x1 = rtsiGetContStates(si);
  int_T order = rtsiGetSolverExtrapolationOrder(si);
  int_T numIter = rtsiGetSolverNumberNewtonIterations(si);
  ODE14X_IntgData *id = (ODE14X_IntgData *)rtsiGetSolverData(si);
  real_T *x0 = id->x0;
  real_T *f0 = id->f0;
  real_T *x1start = id->x1start;
  real_T *f1 = id->f1;
  real_T *Delta = id->Delta;
  real_T *E = id->E;
  real_T *fac = id->fac;
  real_T *dfdx = id->DFDX;
  real_T *W = id->W;
  int_T *pivots = id->pivots;
  real_T *xtmp = id->xtmp;
  real_T *ztmp = id->ztmp;
  int_T *N = &(rt_ODE14x_N[0]);
  int_T i,j,k,iter;
  int_T nx = 10;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(x0, x1,
                (uint_T)nx*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */

  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  HW6_Simulink_derivatives();
  local_numjac(si,x0,f0,fac,dfdx );
  for (j = 0; j < order; j++) {
    real_T *p;
    real_T hN = h/N[j];

    /* Get the iteration matrix and solution at t0 */

    /* [L,U] = lu(M - hN*J) */
    (void) memcpy(W, dfdx,
                  (uint_T)nx*nx*sizeof(real_T));
    for (p = W, i = 0; i < nx*nx; i++, p++) {
      *p *= (-hN);
    }

    for (p = W, i = 0; i < nx; i++, p += (nx+1)) {
      *p += 1.0;
    }

    rt_lu_real(W, nx,
               pivots);

    /* First Newton's iteration at t0. */
    /* rhs = hN*f0 */
    for (i = 0; i < nx; i++) {
      Delta[i] = hN*f0[i];
    }

    /* Delta = (U \ (L \ rhs)) */
    rt_ForwardSubstitutionRR_Dbl(W, Delta,
      f1, nx,
      1, pivots,
      1);
    rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
      Delta, nx,
      1, 0);

    /* ytmp = y0 + Delta
       ztmp = (ytmp-y0)/h
     */
    (void) memcpy(x1, x0,
                  (uint_T)nx*sizeof(real_T));
    for (i = 0; i < nx; i++) {
      x1[i] += Delta[i];
      ztmp[i] = Delta[i]/hN;
    }

    /* Additional Newton's iterations, if desired.
       for iter = 2:NewtIter
       rhs = hN*feval(odefun,tn,ytmp,extraArgs{:}) - M*(ytmp - yn);
       if statedepM   % only for state dep. Mdel ~= 0
       Mdel = M - feval(massfun,tn,ytmp);
       rhs = rhs + Mdel*ztmp*h;
       end
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       ztmp = (ytmp - yn)/h
       end
     */
    rtsiSetT(si, t0);
    rtsiSetdX(si, f1);
    for (iter = 1; iter < numIter; iter++) {
      HW6_Simulink_step();
      HW6_Simulink_derivatives();
      for (i = 0; i < nx; i++) {
        Delta[i] = hN*f1[i];
        xtmp[i] = x1[i] - x0[i];
      }

      /* rhs = hN*f(tn,ytmp) - (ytmp-yn) */
      for (i = 0; i < nx; i++) {
        Delta[i] -= xtmp[i];
      }

      rt_ForwardSubstitutionRR_Dbl(W, Delta,
        f1, nx,
        1, pivots,
        1);
      rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
        Delta, nx,
        1, 0);

      /* ytmp = ytmp + delta
         ztmp = (ytmp - yn)/h
       */
      for (i = 0; i < nx; i++) {
        x1[i] += Delta[i];
        ztmp[i] = (x1[i] - x0[i])/hN;
      }
    }

    /* Steps from t0+hN to t1 -- subintegration of N(j) steps for extrapolation
       ttmp = t0;
       for i = 2:N(j)
       ttmp = ttmp + hN
       ytmp0 = ytmp;
       for iter = 1:NewtIter
       rhs = (ytmp0 - ytmp) + hN*feval(odefun,ttmp,ytmp,extraArgs{:});
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       end
       end
     */
    for (k = 1; k < N[j]; k++) {
      t1 = t0 + k*hN;
      (void) memcpy(x1start, x1,
                    (uint_T)nx*sizeof(real_T));
      rtsiSetT(si, t1);
      rtsiSetdX(si, f1);
      for (iter = 0; iter < numIter; iter++) {
        HW6_Simulink_step();
        HW6_Simulink_derivatives();
        if (iter == 0) {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
          }
        } else {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
            xtmp[i] = (x1[i]-x1start[i]);
          }

          /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
          for (i = 0; i < nx; i++) {
            Delta[i] -= xtmp[i];
          }
        }

        rt_ForwardSubstitutionRR_Dbl(W, Delta,
          f1, nx,
          1, pivots,
          1);
        rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
          Delta, nx,
          1, 0);

        /* ytmp = ytmp + Delta
           ztmp = (ytmp - ytmp0)/h
         */
        for (i = 0; i < nx; i++) {
          x1[i] += Delta[i];
          ztmp[i] = (x1[i] - x1start[i])/hN;
        }
      }
    }

    /* Extrapolate to order j
       E(:,j) = ytmp
       for k = j:-1:2
       coef = N(k-1)/(N(j) - N(k-1))
       E(:,k-1) = E(:,k) + coef*( E(:,k) - E(:,k-1) )
       end
     */
    (void) memcpy(&(E[nx*j]), x1,
                  (uint_T)nx*sizeof(real_T));
    for (k = j; k > 0; k--) {
      real_T coef = (real_T)(N[k-1]) / (N[j]-N[k-1]);
      for (i = 0; i < nx; i++) {
        x1[i] = E[nx*k+i] + coef*(E[nx*k+i] - E[nx*(k-1)+i]);
      }

      (void) memcpy(&(E[nx*(k-1)]), x1,
                    (uint_T)nx*sizeof(real_T));
    }
  }

  /* x1 = E(:,1); */
  (void) memcpy(x1, E,
                (uint_T)nx*sizeof(real_T));

  /* t1 = t0 + h; */
  rtsiSetT(si,rtsiGetSolverStopTime(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for enable system:
 *    '<S28>/MeasurementUpdate'
 *    '<S80>/MeasurementUpdate'
 *    '<S132>/MeasurementUpdate'
 *    '<S184>/MeasurementUpdate'
 */
void HW6_Simu_MeasurementUpdate_Init(B_MeasurementUpdate_HW6_Simul_T *localB,
  P_MeasurementUpdate_HW6_Simul_T *localP)
{
  /* SystemInitialize for Outport: '<S57>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3 = localP->Lykyhatkk1_Y0;
}

/*
 * Disable for enable system:
 *    '<S28>/MeasurementUpdate'
 *    '<S80>/MeasurementUpdate'
 *    '<S132>/MeasurementUpdate'
 *    '<S184>/MeasurementUpdate'
 */
void HW6_S_MeasurementUpdate_Disable(B_MeasurementUpdate_HW6_Simul_T *localB,
  DW_MeasurementUpdate_HW6_Simu_T *localDW, P_MeasurementUpdate_HW6_Simul_T
  *localP)
{
  /* Disable for Outport: '<S57>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3 = localP->Lykyhatkk1_Y0;
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Start for enable system:
 *    '<S28>/MeasurementUpdate'
 *    '<S80>/MeasurementUpdate'
 *    '<S132>/MeasurementUpdate'
 *    '<S184>/MeasurementUpdate'
 */
void HW6_Sim_MeasurementUpdate_Start(DW_MeasurementUpdate_HW6_Simu_T *localDW)
{
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S28>/MeasurementUpdate'
 *    '<S80>/MeasurementUpdate'
 *    '<S132>/MeasurementUpdate'
 *    '<S184>/MeasurementUpdate'
 */
void HW6_Simulink_MeasurementUpdate(RT_MODEL_HW6_Simulink_T * const
  HW6_Simulink_M, boolean_T rtu_Enable, real_T rtu_Lk, real_T rtu_yk, real_T
  rtu_Ck, real_T rtu_xhatkk1, real_T rtu_Dk, real_T rtu_uk,
  B_MeasurementUpdate_HW6_Simul_T *localB, DW_MeasurementUpdate_HW6_Simu_T
  *localDW, P_MeasurementUpdate_HW6_Simul_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S28>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S57>/Enable'
   */
  if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
    if (rtu_Enable) {
      localDW->MeasurementUpdate_MODE = true;
    } else {
      if (localDW->MeasurementUpdate_MODE) {
        HW6_S_MeasurementUpdate_Disable(localB, localDW, localP);
      }
    }
  }

  if (localDW->MeasurementUpdate_MODE) {
    /* Product: '<S57>/Product3' incorporates:
     *  Product: '<S57>/C[k]*xhat[k|k-1]'
     *  Product: '<S57>/D[k]*u[k]'
     *  Sum: '<S57>/Add1'
     *  Sum: '<S57>/Sum'
     */
    localB->Product3 = (rtu_yk - (rtu_Ck * rtu_xhatkk1 + rtu_Dk * rtu_uk)) *
      rtu_Lk;
  }

  /* End of Outputs for SubSystem: '<S28>/MeasurementUpdate' */
}

/*
 * System initialize for enable system:
 *    '<S35>/Enabled Subsystem'
 *    '<S87>/Enabled Subsystem'
 *    '<S139>/Enabled Subsystem'
 *    '<S191>/Enabled Subsystem'
 */
void HW6_Simul_EnabledSubsystem_Init(B_EnabledSubsystem_HW6_Simuli_T *localB,
  P_EnabledSubsystem_HW6_Simuli_T *localP)
{
  /* SystemInitialize for Outport: '<S59>/deltax' */
  localB->Product2 = localP->deltax_Y0;
}

/*
 * Disable for enable system:
 *    '<S35>/Enabled Subsystem'
 *    '<S87>/Enabled Subsystem'
 *    '<S139>/Enabled Subsystem'
 *    '<S191>/Enabled Subsystem'
 */
void HW6_Si_EnabledSubsystem_Disable(B_EnabledSubsystem_HW6_Simuli_T *localB,
  DW_EnabledSubsystem_HW6_Simul_T *localDW, P_EnabledSubsystem_HW6_Simuli_T
  *localP)
{
  /* Disable for Outport: '<S59>/deltax' */
  localB->Product2 = localP->deltax_Y0;
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Start for enable system:
 *    '<S35>/Enabled Subsystem'
 *    '<S87>/Enabled Subsystem'
 *    '<S139>/Enabled Subsystem'
 *    '<S191>/Enabled Subsystem'
 */
void HW6_Simu_EnabledSubsystem_Start(DW_EnabledSubsystem_HW6_Simul_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S35>/Enabled Subsystem'
 *    '<S87>/Enabled Subsystem'
 *    '<S139>/Enabled Subsystem'
 *    '<S191>/Enabled Subsystem'
 */
void HW6_Simulink_EnabledSubsystem(RT_MODEL_HW6_Simulink_T * const
  HW6_Simulink_M, boolean_T rtu_Enable, real_T rtu_Mk, real_T rtu_Ck, real_T
  rtu_yk, real_T rtu_xhatkk1, B_EnabledSubsystem_HW6_Simuli_T *localB,
  DW_EnabledSubsystem_HW6_Simul_T *localDW, P_EnabledSubsystem_HW6_Simuli_T
  *localP)
{
  /* Outputs for Enabled SubSystem: '<S35>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S59>/Enable'
   */
  if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
    if (rtu_Enable) {
      localDW->EnabledSubsystem_MODE = true;
    } else {
      if (localDW->EnabledSubsystem_MODE) {
        HW6_Si_EnabledSubsystem_Disable(localB, localDW, localP);
      }
    }
  }

  if (localDW->EnabledSubsystem_MODE) {
    /* Product: '<S59>/Product2' incorporates:
     *  Product: '<S59>/Product'
     *  Sum: '<S59>/Add1'
     */
    localB->Product2 = (rtu_yk - rtu_Ck * rtu_xhatkk1) * rtu_Mk;
  }

  /* End of Outputs for SubSystem: '<S35>/Enabled Subsystem' */
}

/* Model step function */
void HW6_Simulink_step(void)
{
  /* local block i/o variables */
  real_T rtb_MemoryX_e;
  real_T rtb_MemoryX_i;
  real_T rtb_MemoryX_d;
  real_T rtb_Add;
  real_T rtb_Add_i;
  real_T rtb_Add_k;
  real_T rtb_Add_b;
  real_T rtb_Dkuk;
  if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
    /* set solver stop time */
    if (!(HW6_Simulink_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&HW6_Simulink_M->solverInfo,
                            ((HW6_Simulink_M->Timing.clockTickH0 + 1) *
        HW6_Simulink_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&HW6_Simulink_M->solverInfo,
                            ((HW6_Simulink_M->Timing.clockTick0 + 1) *
        HW6_Simulink_M->Timing.stepSize0 + HW6_Simulink_M->Timing.clockTickH0 *
        HW6_Simulink_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(HW6_Simulink_M)) {
    HW6_Simulink_M->Timing.t[0] = rtsiGetT(&HW6_Simulink_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
    /* Saturate: '<S1>/Saturation1' incorporates:
     *  Constant: '<S1>/Constant'
     */
    if (HW6_Simulink_P.Constant_Value > HW6_Simulink_P.Saturation1_UpperSat) {
      motors_outport[0] = HW6_Simulink_P.Saturation1_UpperSat;
    } else if (HW6_Simulink_P.Constant_Value <
               HW6_Simulink_P.Saturation1_LowerSat) {
      motors_outport[0] = HW6_Simulink_P.Saturation1_LowerSat;
    } else {
      motors_outport[0] = (real32_T)HW6_Simulink_P.Constant_Value;
    }

    /* Outport: '<Root>/Motors' */
    HW6_Simulink_Y.Motors[0] = motors_outport[0];

    /* Saturate: '<S1>/Saturation1' incorporates:
     *  Constant: '<S1>/Constant5'
     */
    if (HW6_Simulink_P.Constant5_Value > HW6_Simulink_P.Saturation1_UpperSat) {
      motors_outport[1] = HW6_Simulink_P.Saturation1_UpperSat;
    } else if (HW6_Simulink_P.Constant5_Value <
               HW6_Simulink_P.Saturation1_LowerSat) {
      motors_outport[1] = HW6_Simulink_P.Saturation1_LowerSat;
    } else {
      motors_outport[1] = (real32_T)HW6_Simulink_P.Constant5_Value;
    }

    /* Outport: '<Root>/Motors' */
    HW6_Simulink_Y.Motors[1] = motors_outport[1];

    /* Saturate: '<S1>/Saturation1' incorporates:
     *  Constant: '<S1>/Constant3'
     */
    if (HW6_Simulink_P.Constant3_Value > HW6_Simulink_P.Saturation1_UpperSat) {
      motors_outport[2] = HW6_Simulink_P.Saturation1_UpperSat;
    } else if (HW6_Simulink_P.Constant3_Value <
               HW6_Simulink_P.Saturation1_LowerSat) {
      motors_outport[2] = HW6_Simulink_P.Saturation1_LowerSat;
    } else {
      motors_outport[2] = (real32_T)HW6_Simulink_P.Constant3_Value;
    }

    /* Outport: '<Root>/Motors' */
    HW6_Simulink_Y.Motors[2] = motors_outport[2];

    /* Saturate: '<S1>/Saturation1' incorporates:
     *  Constant: '<S1>/Constant4'
     */
    if (HW6_Simulink_P.Constant4_Value > HW6_Simulink_P.Saturation1_UpperSat) {
      motors_outport[3] = HW6_Simulink_P.Saturation1_UpperSat;
    } else if (HW6_Simulink_P.Constant4_Value <
               HW6_Simulink_P.Saturation1_LowerSat) {
      motors_outport[3] = HW6_Simulink_P.Saturation1_LowerSat;
    } else {
      motors_outport[3] = (real32_T)HW6_Simulink_P.Constant4_Value;
    }

    /* Outport: '<Root>/Motors' */
    HW6_Simulink_Y.Motors[3] = motors_outport[3];

    /* ManualSwitch: '<S1>/Manual Switch' incorporates:
     *  Constant: '<S1>/Constant1'
     *  Constant: '<S1>/Constant2'
     */
    if (HW6_Simulink_P.ManualSwitch_CurrentSetting == 1) {
      flag_outport = HW6_Simulink_P.Constant2_Value;
    } else {
      flag_outport = HW6_Simulink_P.Constant1_Value;
    }

    /* End of ManualSwitch: '<S1>/Manual Switch' */

    /* Outport: '<Root>/Flag' */
    HW6_Simulink_Y.Flag = flag_outport;
  }

  /* Integrator: '<S1>/Integrator1' */
  HW6_Simulink_B.Xned = HW6_Simulink_X.Integrator1_CSTATE;

  /* Integrator: '<S1>/Integrator3' */
  HW6_Simulink_B.Yned = HW6_Simulink_X.Integrator3_CSTATE;

  /* RateLimiter: '<S1>/Rate Limiter' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion8'
   *  Inport: '<Root>/Sensors'
   */
  HW6_Simulink_B.Sum = HW6_Simulink_M->Timing.t[0];
  if ((HW6_Simulink_DW.LastMajorTimeA >= HW6_Simulink_B.Sum) &&
      (HW6_Simulink_DW.LastMajorTimeB >= HW6_Simulink_B.Sum)) {
    HW6_Simulink_B.RateLimiter =
      sensor_inport.HALSensors.HAL_ultrasound_SI.altitude;
  } else {
    if (((HW6_Simulink_DW.LastMajorTimeA < HW6_Simulink_DW.LastMajorTimeB) &&
         (HW6_Simulink_DW.LastMajorTimeB < HW6_Simulink_B.Sum)) ||
        ((HW6_Simulink_DW.LastMajorTimeA >= HW6_Simulink_DW.LastMajorTimeB) &&
         (HW6_Simulink_DW.LastMajorTimeA >= HW6_Simulink_B.Sum))) {
      HW6_Simulink_B.deltaT = HW6_Simulink_B.Sum -
        HW6_Simulink_DW.LastMajorTimeB;
      HW6_Simulink_B.Sum = HW6_Simulink_DW.PrevYB;
    } else {
      HW6_Simulink_B.deltaT = HW6_Simulink_B.Sum -
        HW6_Simulink_DW.LastMajorTimeA;
      HW6_Simulink_B.Sum = HW6_Simulink_DW.PrevYA;
    }

    HW6_Simulink_B.riseValLimit = HW6_Simulink_B.deltaT *
      HW6_Simulink_P.RateLimiter_RisingLim;
    HW6_Simulink_B.rateLimiterRate =
      sensor_inport.HALSensors.HAL_ultrasound_SI.altitude - HW6_Simulink_B.Sum;
    if (HW6_Simulink_B.rateLimiterRate > HW6_Simulink_B.riseValLimit) {
      HW6_Simulink_B.RateLimiter = HW6_Simulink_B.Sum +
        HW6_Simulink_B.riseValLimit;
    } else {
      HW6_Simulink_B.deltaT *= HW6_Simulink_P.RateLimiter_FallingLim;
      if (HW6_Simulink_B.rateLimiterRate < HW6_Simulink_B.deltaT) {
        HW6_Simulink_B.RateLimiter = HW6_Simulink_B.Sum + HW6_Simulink_B.deltaT;
      } else {
        HW6_Simulink_B.RateLimiter =
          sensor_inport.HALSensors.HAL_ultrasound_SI.altitude;
      }
    }
  }

  /* End of RateLimiter: '<S1>/Rate Limiter' */

  /* DataTypeConversion: '<S1>/Data Type Conversion3' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW6_Simulink_B.DataTypeConversion3 = sensor_inport.HALSensors.HAL_gyro_SI.x;

  /* DataTypeConversion: '<S1>/Data Type Conversion4' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW6_Simulink_B.DataTypeConversion4 = sensor_inport.HALSensors.HAL_gyro_SI.y;

  /* DataTypeConversion: '<S1>/Data Type Conversion5' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW6_Simulink_B.DataTypeConversion5 = sensor_inport.HALSensors.HAL_gyro_SI.z;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW6_Simulink_B.DataTypeConversion = sensor_inport.HALSensors.HAL_acc_SI.x;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW6_Simulink_B.DataTypeConversion1 = sensor_inport.HALSensors.HAL_acc_SI.y;

  /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW6_Simulink_B.DataTypeConversion2 = sensor_inport.HALSensors.HAL_acc_SI.z;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S1>/Constant6'
   */
  HW6_Simulink_B.Sum1 = HW6_Simulink_B.DataTypeConversion2 -
    HW6_Simulink_P.Constant6_Value;

  /* Integrator: '<S1>/Integrator6' */
  HW6_Simulink_B.phi = HW6_Simulink_X.Integrator6_CSTATE;

  /* Integrator: '<S1>/Integrator7' */
  HW6_Simulink_B.theta = HW6_Simulink_X.Integrator7_CSTATE;

  /* Integrator: '<S1>/Integrator8' */
  HW6_Simulink_B.psi = HW6_Simulink_X.Integrator8_CSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion6' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW6_Simulink_B.DataTypeConversion6 =
    sensor_inport.VisionSensors.opticalFlow_data[0];

  /* DataTypeConversion: '<S1>/Data Type Conversion7' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  HW6_Simulink_B.DataTypeConversion7 =
    sensor_inport.VisionSensors.opticalFlow_data[1];

  /* Integrator: '<S1>/Integrator11' */
  HW6_Simulink_B.Integrator11 = HW6_Simulink_X.Integrator11_CSTATE;

  /* Integrator: '<S1>/Integrator5' */
  HW6_Simulink_B.Yned_d = HW6_Simulink_X.Integrator5_CSTATE;
  if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
    /* SignalConversion generated from: '<S1>/To Workspace' */
    HW6_Simulink_B.TmpSignalConversionAtToWork[0] = HW6_Simulink_B.Xned;
    HW6_Simulink_B.TmpSignalConversionAtToWork[1] = HW6_Simulink_B.Yned;
    HW6_Simulink_B.TmpSignalConversionAtToWork[2] = HW6_Simulink_B.RateLimiter;
    HW6_Simulink_B.TmpSignalConversionAtToWork[3] =
      HW6_Simulink_B.DataTypeConversion3;
    HW6_Simulink_B.TmpSignalConversionAtToWork[4] =
      HW6_Simulink_B.DataTypeConversion4;
    HW6_Simulink_B.TmpSignalConversionAtToWork[5] =
      HW6_Simulink_B.DataTypeConversion5;
    HW6_Simulink_B.TmpSignalConversionAtToWork[6] =
      HW6_Simulink_B.DataTypeConversion;
    HW6_Simulink_B.TmpSignalConversionAtToWork[7] =
      HW6_Simulink_B.DataTypeConversion1;
    HW6_Simulink_B.TmpSignalConversionAtToWork[8] = HW6_Simulink_B.Sum1;
    HW6_Simulink_B.TmpSignalConversionAtToWork[9] = HW6_Simulink_B.phi;
    HW6_Simulink_B.TmpSignalConversionAtToWork[10] = HW6_Simulink_B.theta;
    HW6_Simulink_B.TmpSignalConversionAtToWork[11] = HW6_Simulink_B.psi;
    HW6_Simulink_B.TmpSignalConversionAtToWork[12] =
      HW6_Simulink_B.DataTypeConversion6;
    HW6_Simulink_B.TmpSignalConversionAtToWork[13] =
      HW6_Simulink_B.DataTypeConversion7;
    HW6_Simulink_B.TmpSignalConversionAtToWork[14] = HW6_Simulink_B.Integrator11;
    HW6_Simulink_B.TmpSignalConversionAtToWork[15] = HW6_Simulink_B.Yned_d;
    HW6_Simulink_B.TmpSignalConversionAtToWork[16] =
      HW6_Simulink_B.DataTypeConversion2;

    /* ToWorkspace: '<S1>/To Workspace' */
    {
      double locTime = (((HW6_Simulink_M->Timing.clockTick1+
                          HW6_Simulink_M->Timing.clockTickH1* 4294967296.0)) *
                        0.005);
      ;
      if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              HW6_Simulink_DW.ToWorkspace_PWORK.LoggedData,
                              &locTime,
                              &HW6_Simulink_B.TmpSignalConversionAtToWork[0]);
      }
    }

    /* Reshape: '<S7>/Reshapey' */
    HW6_Simulink_B.Reshapey = HW6_Simulink_B.RateLimiter;

    /* Delay: '<S7>/MemoryX' incorporates:
     *  Constant: '<S7>/X0'
     */
    if (HW6_Simulink_DW.icLoad != 0) {
      HW6_Simulink_DW.MemoryX_DSTATE[0] = HW6_Simulink_P.X0_Value[0];
      HW6_Simulink_DW.MemoryX_DSTATE[1] = HW6_Simulink_P.X0_Value[1];
    }

    HW6_Simulink_B.rtb_MemoryX_idx_0 = HW6_Simulink_DW.MemoryX_DSTATE[0];
    HW6_Simulink_B.rtb_MemoryX_idx_1 = HW6_Simulink_DW.MemoryX_DSTATE[1];

    /* Outputs for Enabled SubSystem: '<S243>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S267>/Enable'
     */
    if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
      /* Constant: '<S7>/Enable' */
      if (HW6_Simulink_P.Enable_Value) {
        HW6_Simulink_DW.EnabledSubsystem_MODE = true;
      } else {
        if (HW6_Simulink_DW.EnabledSubsystem_MODE) {
          /* Disable for Outport: '<S267>/deltax' */
          HW6_Simulink_B.Product2[0] = HW6_Simulink_P.deltax_Y0;
          HW6_Simulink_B.Product2[1] = HW6_Simulink_P.deltax_Y0;
          HW6_Simulink_DW.EnabledSubsystem_MODE = false;
        }
      }
    }

    if (HW6_Simulink_DW.EnabledSubsystem_MODE) {
      /* Sum: '<S267>/Add1' incorporates:
       *  Constant: '<S7>/C'
       *  Delay: '<S7>/MemoryX'
       *  Product: '<S267>/Product'
       *  Reshape: '<S7>/Reshapey'
       */
      HW6_Simulink_B.Sum = HW6_Simulink_B.RateLimiter - (HW6_Simulink_P.C_Value
        [0] * HW6_Simulink_DW.MemoryX_DSTATE[0] + HW6_Simulink_P.C_Value[1] *
        HW6_Simulink_DW.MemoryX_DSTATE[1]);

      /* Product: '<S267>/Product2' incorporates:
       *  Constant: '<S216>/KalmanGainM'
       */
      HW6_Simulink_B.Product2[0] = HW6_Simulink_P.KalmanGainM_Value[0] *
        HW6_Simulink_B.Sum;
      HW6_Simulink_B.Product2[1] = HW6_Simulink_P.KalmanGainM_Value[1] *
        HW6_Simulink_B.Sum;
    }

    /* End of Outputs for SubSystem: '<S243>/Enabled Subsystem' */

    /* Sum: '<S243>/Add' incorporates:
     *  Delay: '<S7>/MemoryX'
     */
    HW6_Simulink_B.Akxhatkk1[0] = HW6_Simulink_B.Product2[0] +
      HW6_Simulink_DW.MemoryX_DSTATE[0];
    HW6_Simulink_B.Akxhatkk1[1] = HW6_Simulink_B.Product2[1] +
      HW6_Simulink_DW.MemoryX_DSTATE[1];

    /* ToWorkspace: '<S1>/To Workspace1' */
    {
      double locTime = (((HW6_Simulink_M->Timing.clockTick1+
                          HW6_Simulink_M->Timing.clockTickH1* 4294967296.0)) *
                        0.005);
      ;
      if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              HW6_Simulink_DW.ToWorkspace1_PWORK.LoggedData,
                              &locTime, &HW6_Simulink_B.Akxhatkk1[0]);
      }
    }

    /* ToWorkspace: '<S1>/To Workspace2' */
    {
      double locTime = (((HW6_Simulink_M->Timing.clockTick1+
                          HW6_Simulink_M->Timing.clockTickH1* 4294967296.0)) *
                        0.005);
      ;
      if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              HW6_Simulink_DW.ToWorkspace2_PWORK.LoggedData,
                              &locTime, &HW6_Simulink_B.Akxhatkk1[1]);
      }
    }

    /* Delay: '<S2>/MemoryX' incorporates:
     *  Constant: '<S2>/X0'
     */
    if (HW6_Simulink_DW.icLoad_h != 0) {
      HW6_Simulink_DW.MemoryX_DSTATE_l = HW6_Simulink_P.X0_Value_d;
    }

    HW6_Simulink_B.MemoryX_b = HW6_Simulink_DW.MemoryX_DSTATE_l;

    /* End of Delay: '<S2>/MemoryX' */

    /* Outputs for Enabled SubSystem: '<S35>/Enabled Subsystem' */
    /* Constant: '<S2>/Enable' incorporates:
     *  Constant: '<S2>/C'
     *  Constant: '<S8>/KalmanGainM'
     */
    HW6_Simulink_EnabledSubsystem(HW6_Simulink_M, HW6_Simulink_P.Enable_Value_l,
      HW6_Simulink_P.KalmanGainM_Value_e, HW6_Simulink_P.C_Value_k,
      HW6_Simulink_B.DataTypeConversion6, HW6_Simulink_B.MemoryX_b,
      &HW6_Simulink_B.EnabledSubsystem, &HW6_Simulink_DW.EnabledSubsystem,
      &HW6_Simulink_P.EnabledSubsystem);

    /* End of Outputs for SubSystem: '<S35>/Enabled Subsystem' */

    /* Sum: '<S35>/Add' */
    rtb_Dkuk = HW6_Simulink_B.EnabledSubsystem.Product2 +
      HW6_Simulink_B.MemoryX_b;

    /* ToWorkspace: '<S1>/To Workspace3' */
    {
      double locTime = (((HW6_Simulink_M->Timing.clockTick1+
                          HW6_Simulink_M->Timing.clockTickH1* 4294967296.0)) *
                        0.005);
      ;
      if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              HW6_Simulink_DW.ToWorkspace3_PWORK.LoggedData,
                              &locTime, &rtb_Dkuk);
      }
    }

    /* Delay: '<S3>/MemoryX' incorporates:
     *  Constant: '<S3>/X0'
     */
    if (HW6_Simulink_DW.icLoad_p != 0) {
      HW6_Simulink_DW.MemoryX_DSTATE_f = HW6_Simulink_P.X0_Value_g;
    }

    rtb_MemoryX_e = HW6_Simulink_DW.MemoryX_DSTATE_f;

    /* End of Delay: '<S3>/MemoryX' */

    /* Outputs for Enabled SubSystem: '<S87>/Enabled Subsystem' */
    /* Constant: '<S3>/Enable' incorporates:
     *  Constant: '<S3>/C'
     *  Constant: '<S60>/KalmanGainM'
     */
    HW6_Simulink_EnabledSubsystem(HW6_Simulink_M, HW6_Simulink_P.Enable_Value_o,
      HW6_Simulink_P.KalmanGainM_Value_m, HW6_Simulink_P.C_Value_m,
      HW6_Simulink_B.DataTypeConversion7, rtb_MemoryX_e,
      &HW6_Simulink_B.EnabledSubsystem_j, &HW6_Simulink_DW.EnabledSubsystem_j,
      &HW6_Simulink_P.EnabledSubsystem_j);

    /* End of Outputs for SubSystem: '<S87>/Enabled Subsystem' */

    /* Sum: '<S87>/Add' */
    rtb_Dkuk = HW6_Simulink_B.EnabledSubsystem_j.Product2 + rtb_MemoryX_e;

    /* ToWorkspace: '<S1>/To Workspace4' */
    {
      double locTime = (((HW6_Simulink_M->Timing.clockTick1+
                          HW6_Simulink_M->Timing.clockTickH1* 4294967296.0)) *
                        0.005);
      ;
      if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              HW6_Simulink_DW.ToWorkspace4_PWORK.LoggedData,
                              &locTime, &rtb_Dkuk);
      }
    }
  }

  /* Product: '<S1>/Divide' incorporates:
   *  Constant: '<S1>/Constant7'
   */
  HW6_Simulink_B.phi_p = HW6_Simulink_B.DataTypeConversion1 /
    HW6_Simulink_P.Constant7_Value;
  if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
    /* Delay: '<S4>/MemoryX' incorporates:
     *  Constant: '<S4>/X0'
     */
    if (HW6_Simulink_DW.icLoad_f != 0) {
      HW6_Simulink_DW.MemoryX_DSTATE_k = HW6_Simulink_P.X0_Value_k;
    }

    rtb_MemoryX_i = HW6_Simulink_DW.MemoryX_DSTATE_k;

    /* End of Delay: '<S4>/MemoryX' */

    /* Outputs for Enabled SubSystem: '<S139>/Enabled Subsystem' */
    /* Constant: '<S4>/Enable' incorporates:
     *  Constant: '<S112>/KalmanGainM'
     *  Constant: '<S4>/C'
     */
    HW6_Simulink_EnabledSubsystem(HW6_Simulink_M, HW6_Simulink_P.Enable_Value_ln,
      HW6_Simulink_P.KalmanGainM_Value_n, HW6_Simulink_P.C_Value_g,
      HW6_Simulink_B.phi_p, rtb_MemoryX_i, &HW6_Simulink_B.EnabledSubsystem_a,
      &HW6_Simulink_DW.EnabledSubsystem_a, &HW6_Simulink_P.EnabledSubsystem_a);

    /* End of Outputs for SubSystem: '<S139>/Enabled Subsystem' */

    /* Sum: '<S139>/Add' */
    rtb_Dkuk = HW6_Simulink_B.EnabledSubsystem_a.Product2 + rtb_MemoryX_i;

    /* ToWorkspace: '<S1>/To Workspace5' */
    {
      double locTime = (((HW6_Simulink_M->Timing.clockTick1+
                          HW6_Simulink_M->Timing.clockTickH1* 4294967296.0)) *
                        0.005);
      ;
      if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              HW6_Simulink_DW.ToWorkspace5_PWORK.LoggedData,
                              &locTime, &rtb_Dkuk);
      }
    }
  }

  /* Product: '<S1>/Divide1' incorporates:
   *  Constant: '<S1>/Constant8'
   *  Gain: '<S1>/Gain'
   */
  HW6_Simulink_B.theta_o = HW6_Simulink_P.Gain_Gain *
    HW6_Simulink_B.DataTypeConversion / HW6_Simulink_P.Constant8_Value;
  if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
    /* Delay: '<S5>/MemoryX' incorporates:
     *  Constant: '<S5>/X0'
     */
    if (HW6_Simulink_DW.icLoad_d != 0) {
      HW6_Simulink_DW.MemoryX_DSTATE_j = HW6_Simulink_P.X0_Value_j;
    }

    rtb_MemoryX_d = HW6_Simulink_DW.MemoryX_DSTATE_j;

    /* End of Delay: '<S5>/MemoryX' */

    /* Outputs for Enabled SubSystem: '<S191>/Enabled Subsystem' */
    /* Constant: '<S5>/Enable' incorporates:
     *  Constant: '<S164>/KalmanGainM'
     *  Constant: '<S5>/C'
     */
    HW6_Simulink_EnabledSubsystem(HW6_Simulink_M, HW6_Simulink_P.Enable_Value_b,
      HW6_Simulink_P.KalmanGainM_Value_o, HW6_Simulink_P.C_Value_h,
      HW6_Simulink_B.theta_o, rtb_MemoryX_d, &HW6_Simulink_B.EnabledSubsystem_af,
      &HW6_Simulink_DW.EnabledSubsystem_af, &HW6_Simulink_P.EnabledSubsystem_af);

    /* End of Outputs for SubSystem: '<S191>/Enabled Subsystem' */

    /* Sum: '<S191>/Add' */
    rtb_Dkuk = HW6_Simulink_B.EnabledSubsystem_af.Product2 + rtb_MemoryX_d;

    /* ToWorkspace: '<S1>/To Workspace6' */
    {
      double locTime = (((HW6_Simulink_M->Timing.clockTick1+
                          HW6_Simulink_M->Timing.clockTickH1* 4294967296.0)) *
                        0.005);
      ;
      if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              HW6_Simulink_DW.ToWorkspace6_PWORK.LoggedData,
                              &locTime, &rtb_Dkuk);
      }
    }
  }

  /* Integrator: '<S1>/Integrator' */
  HW6_Simulink_B.Integrator = HW6_Simulink_X.Integrator_CSTATE;

  /* Integrator: '<S1>/Integrator2' */
  HW6_Simulink_B.Integrator2 = HW6_Simulink_X.Integrator2_CSTATE;

  /* Integrator: '<S1>/Integrator4' */
  HW6_Simulink_B.Integrator4 = HW6_Simulink_X.Integrator4_CSTATE;
  if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
    /* Product: '<S28>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S2>/A'
     */
    rtb_Dkuk = HW6_Simulink_P.A_Value * HW6_Simulink_B.MemoryX_b;

    /* Outputs for Enabled SubSystem: '<S28>/MeasurementUpdate' */
    /* Constant: '<S2>/Enable' incorporates:
     *  Constant: '<S2>/C'
     *  Constant: '<S2>/D'
     *  Constant: '<S8>/KalmanGainL'
     */
    HW6_Simulink_MeasurementUpdate(HW6_Simulink_M, HW6_Simulink_P.Enable_Value_l,
      HW6_Simulink_P.KalmanGainL_Value, HW6_Simulink_B.DataTypeConversion6,
      HW6_Simulink_P.C_Value_k, HW6_Simulink_B.MemoryX_b, HW6_Simulink_P.D_Value,
      HW6_Simulink_B.DataTypeConversion, &HW6_Simulink_B.MeasurementUpdate,
      &HW6_Simulink_DW.MeasurementUpdate, &HW6_Simulink_P.MeasurementUpdate);

    /* End of Outputs for SubSystem: '<S28>/MeasurementUpdate' */

    /* Sum: '<S28>/Add' incorporates:
     *  Constant: '<S2>/B'
     *  Product: '<S28>/B[k]*u[k]'
     */
    rtb_Add = (HW6_Simulink_P.B_Value * HW6_Simulink_B.DataTypeConversion +
               rtb_Dkuk) + HW6_Simulink_B.MeasurementUpdate.Product3;

    /* Product: '<S80>/B[k]*u[k]' incorporates:
     *  Constant: '<S3>/B'
     */
    rtb_Dkuk = HW6_Simulink_P.B_Value_e * HW6_Simulink_B.DataTypeConversion1;

    /* Outputs for Enabled SubSystem: '<S80>/MeasurementUpdate' */
    /* Constant: '<S3>/Enable' incorporates:
     *  Constant: '<S3>/C'
     *  Constant: '<S3>/D'
     *  Constant: '<S60>/KalmanGainL'
     */
    HW6_Simulink_MeasurementUpdate(HW6_Simulink_M, HW6_Simulink_P.Enable_Value_o,
      HW6_Simulink_P.KalmanGainL_Value_g, HW6_Simulink_B.DataTypeConversion7,
      HW6_Simulink_P.C_Value_m, rtb_MemoryX_e, HW6_Simulink_P.D_Value_h,
      HW6_Simulink_B.DataTypeConversion1, &HW6_Simulink_B.MeasurementUpdate_j,
      &HW6_Simulink_DW.MeasurementUpdate_j, &HW6_Simulink_P.MeasurementUpdate_j);

    /* End of Outputs for SubSystem: '<S80>/MeasurementUpdate' */

    /* Sum: '<S80>/Add' incorporates:
     *  Constant: '<S3>/A'
     *  Product: '<S80>/A[k]*xhat[k|k-1]'
     */
    rtb_Add_i = (HW6_Simulink_P.A_Value_a * rtb_MemoryX_e + rtb_Dkuk) +
      HW6_Simulink_B.MeasurementUpdate_j.Product3;

    /* Product: '<S132>/B[k]*u[k]' incorporates:
     *  Constant: '<S4>/B'
     */
    rtb_Dkuk = HW6_Simulink_P.B_Value_g * HW6_Simulink_B.DataTypeConversion3;

    /* Outputs for Enabled SubSystem: '<S132>/MeasurementUpdate' */
    /* Constant: '<S4>/Enable' incorporates:
     *  Constant: '<S112>/KalmanGainL'
     *  Constant: '<S4>/C'
     *  Constant: '<S4>/D'
     */
    HW6_Simulink_MeasurementUpdate(HW6_Simulink_M,
      HW6_Simulink_P.Enable_Value_ln, HW6_Simulink_P.KalmanGainL_Value_o,
      HW6_Simulink_B.phi_p, HW6_Simulink_P.C_Value_g, rtb_MemoryX_i,
      HW6_Simulink_P.D_Value_i, HW6_Simulink_B.DataTypeConversion3,
      &HW6_Simulink_B.MeasurementUpdate_p, &HW6_Simulink_DW.MeasurementUpdate_p,
      &HW6_Simulink_P.MeasurementUpdate_p);

    /* End of Outputs for SubSystem: '<S132>/MeasurementUpdate' */

    /* Sum: '<S132>/Add' incorporates:
     *  Constant: '<S4>/A'
     *  Product: '<S132>/A[k]*xhat[k|k-1]'
     */
    rtb_Add_k = (HW6_Simulink_P.A_Value_g * rtb_MemoryX_i + rtb_Dkuk) +
      HW6_Simulink_B.MeasurementUpdate_p.Product3;

    /* Product: '<S184>/B[k]*u[k]' incorporates:
     *  Constant: '<S5>/B'
     */
    rtb_Dkuk = HW6_Simulink_P.B_Value_j * HW6_Simulink_B.DataTypeConversion4;

    /* Outputs for Enabled SubSystem: '<S184>/MeasurementUpdate' */
    /* Constant: '<S5>/Enable' incorporates:
     *  Constant: '<S164>/KalmanGainL'
     *  Constant: '<S5>/C'
     *  Constant: '<S5>/D'
     */
    HW6_Simulink_MeasurementUpdate(HW6_Simulink_M, HW6_Simulink_P.Enable_Value_b,
      HW6_Simulink_P.KalmanGainL_Value_l, HW6_Simulink_B.theta_o,
      HW6_Simulink_P.C_Value_h, rtb_MemoryX_d, HW6_Simulink_P.D_Value_b,
      HW6_Simulink_B.DataTypeConversion4, &HW6_Simulink_B.MeasurementUpdate_j0,
      &HW6_Simulink_DW.MeasurementUpdate_j0,
      &HW6_Simulink_P.MeasurementUpdate_j0);

    /* End of Outputs for SubSystem: '<S184>/MeasurementUpdate' */

    /* Sum: '<S184>/Add' incorporates:
     *  Constant: '<S5>/A'
     *  Product: '<S184>/A[k]*xhat[k|k-1]'
     */
    rtb_Add_b = (HW6_Simulink_P.A_Value_o * rtb_MemoryX_d + rtb_Dkuk) +
      HW6_Simulink_B.MeasurementUpdate_j0.Product3;

    /* Product: '<S236>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S7>/A'
     */
    HW6_Simulink_B.Akxhatkk1[0] = 0.0;
    HW6_Simulink_B.Akxhatkk1[0] += HW6_Simulink_P.A_Value_i[0] *
      HW6_Simulink_B.rtb_MemoryX_idx_0;
    HW6_Simulink_B.Akxhatkk1[0] += HW6_Simulink_P.A_Value_i[2] *
      HW6_Simulink_B.rtb_MemoryX_idx_1;
    HW6_Simulink_B.Akxhatkk1[1] = 0.0;
    HW6_Simulink_B.Akxhatkk1[1] += HW6_Simulink_P.A_Value_i[1] *
      HW6_Simulink_B.rtb_MemoryX_idx_0;
    HW6_Simulink_B.Akxhatkk1[1] += HW6_Simulink_P.A_Value_i[3] *
      HW6_Simulink_B.rtb_MemoryX_idx_1;

    /* Outputs for Enabled SubSystem: '<S236>/MeasurementUpdate' incorporates:
     *  EnablePort: '<S265>/Enable'
     */
    if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
      /* Constant: '<S7>/Enable' */
      if (HW6_Simulink_P.Enable_Value) {
        HW6_Simulink_DW.MeasurementUpdate_MODE = true;
      } else {
        if (HW6_Simulink_DW.MeasurementUpdate_MODE) {
          /* Disable for Outport: '<S265>/L*(y[k]-yhat[k|k-1])' */
          HW6_Simulink_B.Product3[0] = HW6_Simulink_P.Lykyhatkk1_Y0;
          HW6_Simulink_B.Product3[1] = HW6_Simulink_P.Lykyhatkk1_Y0;
          HW6_Simulink_DW.MeasurementUpdate_MODE = false;
        }
      }
    }

    if (HW6_Simulink_DW.MeasurementUpdate_MODE) {
      /* Product: '<S265>/D[k]*u[k]' incorporates:
       *  Constant: '<S7>/D'
       *  Reshape: '<S7>/Reshapeu'
       */
      rtb_Dkuk = HW6_Simulink_P.D_Value_a * HW6_Simulink_B.Sum1;

      /* Sum: '<S265>/Sum' incorporates:
       *  Constant: '<S7>/C'
       *  Product: '<S265>/C[k]*xhat[k|k-1]'
       *  Sum: '<S265>/Add1'
       */
      HW6_Simulink_B.Sum = HW6_Simulink_B.Reshapey - ((HW6_Simulink_P.C_Value[0]
        * HW6_Simulink_B.rtb_MemoryX_idx_0 + HW6_Simulink_P.C_Value[1] *
        HW6_Simulink_B.rtb_MemoryX_idx_1) + rtb_Dkuk);

      /* Product: '<S265>/Product3' incorporates:
       *  Constant: '<S216>/KalmanGainL'
       */
      HW6_Simulink_B.Product3[0] = HW6_Simulink_P.KalmanGainL_Value_j[0] *
        HW6_Simulink_B.Sum;
      HW6_Simulink_B.Product3[1] = HW6_Simulink_P.KalmanGainL_Value_j[1] *
        HW6_Simulink_B.Sum;
    }

    /* End of Outputs for SubSystem: '<S236>/MeasurementUpdate' */

    /* Sum: '<S236>/Add' incorporates:
     *  Constant: '<S7>/B'
     *  Product: '<S236>/B[k]*u[k]'
     *  Reshape: '<S7>/Reshapeu'
     */
    HW6_Simulink_B.Add_f[0] = (HW6_Simulink_P.B_Value_m[0] * HW6_Simulink_B.Sum1
      + HW6_Simulink_B.Akxhatkk1[0]) + HW6_Simulink_B.Product3[0];
    HW6_Simulink_B.Add_f[1] = (HW6_Simulink_P.B_Value_m[1] * HW6_Simulink_B.Sum1
      + HW6_Simulink_B.Akxhatkk1[1]) + HW6_Simulink_B.Product3[1];
  }

  if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(HW6_Simulink_M->rtwLogInfo, (HW6_Simulink_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
    /* Update for RateLimiter: '<S1>/Rate Limiter' */
    if (HW6_Simulink_DW.LastMajorTimeA == (rtInf)) {
      HW6_Simulink_DW.LastMajorTimeA = HW6_Simulink_M->Timing.t[0];
      HW6_Simulink_DW.PrevYA = HW6_Simulink_B.RateLimiter;
    } else if (HW6_Simulink_DW.LastMajorTimeB == (rtInf)) {
      HW6_Simulink_DW.LastMajorTimeB = HW6_Simulink_M->Timing.t[0];
      HW6_Simulink_DW.PrevYB = HW6_Simulink_B.RateLimiter;
    } else if (HW6_Simulink_DW.LastMajorTimeA < HW6_Simulink_DW.LastMajorTimeB)
    {
      HW6_Simulink_DW.LastMajorTimeA = HW6_Simulink_M->Timing.t[0];
      HW6_Simulink_DW.PrevYA = HW6_Simulink_B.RateLimiter;
    } else {
      HW6_Simulink_DW.LastMajorTimeB = HW6_Simulink_M->Timing.t[0];
      HW6_Simulink_DW.PrevYB = HW6_Simulink_B.RateLimiter;
    }

    /* End of Update for RateLimiter: '<S1>/Rate Limiter' */
    if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
      /* Update for Delay: '<S7>/MemoryX' */
      HW6_Simulink_DW.icLoad = 0U;
      HW6_Simulink_DW.MemoryX_DSTATE[0] = HW6_Simulink_B.Add_f[0];
      HW6_Simulink_DW.MemoryX_DSTATE[1] = HW6_Simulink_B.Add_f[1];

      /* Update for Delay: '<S2>/MemoryX' */
      HW6_Simulink_DW.icLoad_h = 0U;
      HW6_Simulink_DW.MemoryX_DSTATE_l = rtb_Add;

      /* Update for Delay: '<S3>/MemoryX' */
      HW6_Simulink_DW.icLoad_p = 0U;
      HW6_Simulink_DW.MemoryX_DSTATE_f = rtb_Add_i;

      /* Update for Delay: '<S4>/MemoryX' */
      HW6_Simulink_DW.icLoad_f = 0U;
      HW6_Simulink_DW.MemoryX_DSTATE_k = rtb_Add_k;

      /* Update for Delay: '<S5>/MemoryX' */
      HW6_Simulink_DW.icLoad_d = 0U;
      HW6_Simulink_DW.MemoryX_DSTATE_j = rtb_Add_b;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(HW6_Simulink_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(HW6_Simulink_M)!=-1) &&
          !((rtmGetTFinal(HW6_Simulink_M)-(((HW6_Simulink_M->Timing.clockTick1+
               HW6_Simulink_M->Timing.clockTickH1* 4294967296.0)) * 0.005)) >
            (((HW6_Simulink_M->Timing.clockTick1+
               HW6_Simulink_M->Timing.clockTickH1* 4294967296.0)) * 0.005) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(HW6_Simulink_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&HW6_Simulink_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++HW6_Simulink_M->Timing.clockTick0)) {
      ++HW6_Simulink_M->Timing.clockTickH0;
    }

    HW6_Simulink_M->Timing.t[0] = rtsiGetSolverStopTime
      (&HW6_Simulink_M->solverInfo);

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
      HW6_Simulink_M->Timing.clockTick1++;
      if (!HW6_Simulink_M->Timing.clockTick1) {
        HW6_Simulink_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void HW6_Simulink_derivatives(void)
{
  XDot_HW6_Simulink_T *_rtXdot;
  _rtXdot = ((XDot_HW6_Simulink_T *) HW6_Simulink_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = HW6_Simulink_B.Integrator;

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = HW6_Simulink_B.Integrator2;

  /* Derivatives for Integrator: '<S1>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = HW6_Simulink_B.DataTypeConversion3;

  /* Derivatives for Integrator: '<S1>/Integrator7' */
  _rtXdot->Integrator7_CSTATE = HW6_Simulink_B.DataTypeConversion4;

  /* Derivatives for Integrator: '<S1>/Integrator8' */
  _rtXdot->Integrator8_CSTATE = HW6_Simulink_B.DataTypeConversion5;

  /* Derivatives for Integrator: '<S1>/Integrator11' */
  _rtXdot->Integrator11_CSTATE = HW6_Simulink_B.Sum1;

  /* Derivatives for Integrator: '<S1>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = HW6_Simulink_B.Integrator4;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = HW6_Simulink_B.DataTypeConversion;

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = HW6_Simulink_B.DataTypeConversion1;

  /* Derivatives for Integrator: '<S1>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = HW6_Simulink_B.Sum1;
}

/* Model initialize function */
void HW6_Simulink_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)HW6_Simulink_M, 0,
                sizeof(RT_MODEL_HW6_Simulink_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&HW6_Simulink_M->solverInfo,
                          &HW6_Simulink_M->Timing.simTimeStep);
    rtsiSetTPtr(&HW6_Simulink_M->solverInfo, &rtmGetTPtr(HW6_Simulink_M));
    rtsiSetStepSizePtr(&HW6_Simulink_M->solverInfo,
                       &HW6_Simulink_M->Timing.stepSize0);
    rtsiSetdXPtr(&HW6_Simulink_M->solverInfo, &HW6_Simulink_M->derivs);
    rtsiSetContStatesPtr(&HW6_Simulink_M->solverInfo, (real_T **)
                         &HW6_Simulink_M->contStates);
    rtsiSetNumContStatesPtr(&HW6_Simulink_M->solverInfo,
      &HW6_Simulink_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&HW6_Simulink_M->solverInfo,
      &HW6_Simulink_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&HW6_Simulink_M->solverInfo,
      &HW6_Simulink_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&HW6_Simulink_M->solverInfo,
      &HW6_Simulink_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&HW6_Simulink_M->solverInfo, (&rtmGetErrorStatus
      (HW6_Simulink_M)));
    rtsiSetRTModelPtr(&HW6_Simulink_M->solverInfo, HW6_Simulink_M);
  }

  rtsiSetSimTimeStep(&HW6_Simulink_M->solverInfo, MAJOR_TIME_STEP);
  HW6_Simulink_M->intgData.x0 = HW6_Simulink_M->odeX0;
  HW6_Simulink_M->intgData.f0 = HW6_Simulink_M->odeF0;
  HW6_Simulink_M->intgData.x1start = HW6_Simulink_M->odeX1START;
  HW6_Simulink_M->intgData.f1 = HW6_Simulink_M->odeF1;
  HW6_Simulink_M->intgData.Delta = HW6_Simulink_M->odeDELTA;
  HW6_Simulink_M->intgData.E = HW6_Simulink_M->odeE;
  HW6_Simulink_M->intgData.fac = HW6_Simulink_M->odeFAC;

  /* initialize */
  {
    int_T i;
    real_T *f = HW6_Simulink_M->intgData.fac;
    for (i = 0; i < (int_T)(sizeof(HW6_Simulink_M->odeFAC)/sizeof(real_T)); i++)
    {
      f[i] = 1.5e-8;
    }
  }

  HW6_Simulink_M->intgData.DFDX = HW6_Simulink_M->odeDFDX;
  HW6_Simulink_M->intgData.W = HW6_Simulink_M->odeW;
  HW6_Simulink_M->intgData.pivots = HW6_Simulink_M->odePIVOTS;
  HW6_Simulink_M->intgData.xtmp = HW6_Simulink_M->odeXTMP;
  HW6_Simulink_M->intgData.ztmp = HW6_Simulink_M->odeZTMP;
  HW6_Simulink_M->intgData.isFirstStep = true;
  rtsiSetSolverExtrapolationOrder(&HW6_Simulink_M->solverInfo, 4);
  rtsiSetSolverNumberNewtonIterations(&HW6_Simulink_M->solverInfo, 1);
  HW6_Simulink_M->contStates = ((X_HW6_Simulink_T *) &HW6_Simulink_X);
  rtsiSetSolverData(&HW6_Simulink_M->solverInfo, (void *)
                    &HW6_Simulink_M->intgData);
  rtsiSetSolverName(&HW6_Simulink_M->solverInfo,"ode14x");
  rtmSetTPtr(HW6_Simulink_M, &HW6_Simulink_M->Timing.tArray[0]);
  rtmSetTFinal(HW6_Simulink_M, 20.0);
  HW6_Simulink_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    HW6_Simulink_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(HW6_Simulink_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(HW6_Simulink_M->rtwLogInfo, (NULL));
    rtliSetLogT(HW6_Simulink_M->rtwLogInfo, "tout");
    rtliSetLogX(HW6_Simulink_M->rtwLogInfo, "");
    rtliSetLogXFinal(HW6_Simulink_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(HW6_Simulink_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(HW6_Simulink_M->rtwLogInfo, 1);
    rtliSetLogMaxRows(HW6_Simulink_M->rtwLogInfo, 0);
    rtliSetLogDecimation(HW6_Simulink_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &HW6_Simulink_Y.Motors[0],
        &HW6_Simulink_Y.Flag
      };

      rtliSetLogYSignalPtrs(HW6_Simulink_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        4,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        2,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1, 4,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL), (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4, 4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_SINGLE,
        SS_UINT8
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL),
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "Motor",
        "flag" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "HW6_Simulink/Motors",
        "HW6_Simulink/Flag" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_SINGLE, SS_SINGLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_UINT8, SS_UINT8, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          2,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(HW6_Simulink_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(HW6_Simulink_M->rtwLogInfo, "yout");
  }

  /* block I/O */
  (void) memset(((void *) &HW6_Simulink_B), 0,
                sizeof(B_HW6_Simulink_T));

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* states (continuous) */
  {
    (void) memset((void *)&HW6_Simulink_X, 0,
                  sizeof(X_HW6_Simulink_T));
  }

  /* states (dwork) */
  (void) memset((void *)&HW6_Simulink_DW, 0,
                sizeof(DW_HW6_Simulink_T));

  /* external inputs */
  (void)memset(&cmd_inport, 0, sizeof(CommandBus));
  (void)memset(&sensor_inport, 0, sizeof(SensorsBus));

  /* external outputs */
  (void) memset((void *)&HW6_Simulink_Y, 0,
                sizeof(ExtY_HW6_Simulink_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(HW6_Simulink_M->rtwLogInfo, 0.0, rtmGetTFinal
    (HW6_Simulink_M), HW6_Simulink_M->Timing.stepSize0, (&rtmGetErrorStatus
    (HW6_Simulink_M)));

  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace' */
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
      "HW6_Simulink/Flight Control System/To Workspace";
    HW6_Simulink_DW.ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      HW6_Simulink_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(HW6_Simulink_M),
      HW6_Simulink_M->Timing.stepSize0,
      (&rtmGetErrorStatus(HW6_Simulink_M)),
      "states",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (HW6_Simulink_DW.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace1' */
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

    static const char_T *rt_ToWksLabels[] = { "z" };

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
      "HW6_Simulink/Flight Control System/To Workspace1";
    HW6_Simulink_DW.ToWorkspace1_PWORK.LoggedData = rt_CreateStructLogVar(
      HW6_Simulink_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(HW6_Simulink_M),
      HW6_Simulink_M->Timing.stepSize0,
      (&rtmGetErrorStatus(HW6_Simulink_M)),
      "zkalman",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (HW6_Simulink_DW.ToWorkspace1_PWORK.LoggedData == (NULL))
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

    static const char_T *rt_ToWksLabels[] = { "w" };

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
      "HW6_Simulink/Flight Control System/To Workspace2";
    HW6_Simulink_DW.ToWorkspace2_PWORK.LoggedData = rt_CreateStructLogVar(
      HW6_Simulink_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(HW6_Simulink_M),
      HW6_Simulink_M->Timing.stepSize0,
      (&rtmGetErrorStatus(HW6_Simulink_M)),
      "wkalman",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (HW6_Simulink_DW.ToWorkspace2_PWORK.LoggedData == (NULL))
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

    static const char_T *rt_ToWksLabels[] = { "z" };

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
      "HW6_Simulink/Flight Control System/To Workspace3";
    HW6_Simulink_DW.ToWorkspace3_PWORK.LoggedData = rt_CreateStructLogVar(
      HW6_Simulink_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(HW6_Simulink_M),
      HW6_Simulink_M->Timing.stepSize0,
      (&rtmGetErrorStatus(HW6_Simulink_M)),
      "ukalman",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (HW6_Simulink_DW.ToWorkspace3_PWORK.LoggedData == (NULL))
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

    static const char_T *rt_ToWksLabels[] = { "z" };

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
      "HW6_Simulink/Flight Control System/To Workspace4";
    HW6_Simulink_DW.ToWorkspace4_PWORK.LoggedData = rt_CreateStructLogVar(
      HW6_Simulink_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(HW6_Simulink_M),
      HW6_Simulink_M->Timing.stepSize0,
      (&rtmGetErrorStatus(HW6_Simulink_M)),
      "vkalman",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (HW6_Simulink_DW.ToWorkspace4_PWORK.LoggedData == (NULL))
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

    static const char_T *rt_ToWksLabels[] = { "z" };

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
      "HW6_Simulink/Flight Control System/To Workspace5";
    HW6_Simulink_DW.ToWorkspace5_PWORK.LoggedData = rt_CreateStructLogVar(
      HW6_Simulink_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(HW6_Simulink_M),
      HW6_Simulink_M->Timing.stepSize0,
      (&rtmGetErrorStatus(HW6_Simulink_M)),
      "phikalman",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (HW6_Simulink_DW.ToWorkspace5_PWORK.LoggedData == (NULL))
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

    static const char_T *rt_ToWksLabels[] = { "z" };

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
      "HW6_Simulink/Flight Control System/To Workspace6";
    HW6_Simulink_DW.ToWorkspace6_PWORK.LoggedData = rt_CreateStructLogVar(
      HW6_Simulink_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(HW6_Simulink_M),
      HW6_Simulink_M->Timing.stepSize0,
      (&rtmGetErrorStatus(HW6_Simulink_M)),
      "thetakalman",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (HW6_Simulink_DW.ToWorkspace6_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Enabled SubSystem: '<S243>/Enabled Subsystem' */
  HW6_Simulink_DW.EnabledSubsystem_MODE = false;

  /* End of Start for SubSystem: '<S243>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S35>/Enabled Subsystem' */
  HW6_Simu_EnabledSubsystem_Start(&HW6_Simulink_DW.EnabledSubsystem);

  /* End of Start for SubSystem: '<S35>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S87>/Enabled Subsystem' */
  HW6_Simu_EnabledSubsystem_Start(&HW6_Simulink_DW.EnabledSubsystem_j);

  /* End of Start for SubSystem: '<S87>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S139>/Enabled Subsystem' */
  HW6_Simu_EnabledSubsystem_Start(&HW6_Simulink_DW.EnabledSubsystem_a);

  /* End of Start for SubSystem: '<S139>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S191>/Enabled Subsystem' */
  HW6_Simu_EnabledSubsystem_Start(&HW6_Simulink_DW.EnabledSubsystem_af);

  /* End of Start for SubSystem: '<S191>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S28>/MeasurementUpdate' */
  HW6_Sim_MeasurementUpdate_Start(&HW6_Simulink_DW.MeasurementUpdate);

  /* End of Start for SubSystem: '<S28>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S80>/MeasurementUpdate' */
  HW6_Sim_MeasurementUpdate_Start(&HW6_Simulink_DW.MeasurementUpdate_j);

  /* End of Start for SubSystem: '<S80>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S132>/MeasurementUpdate' */
  HW6_Sim_MeasurementUpdate_Start(&HW6_Simulink_DW.MeasurementUpdate_p);

  /* End of Start for SubSystem: '<S132>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S184>/MeasurementUpdate' */
  HW6_Sim_MeasurementUpdate_Start(&HW6_Simulink_DW.MeasurementUpdate_j0);

  /* End of Start for SubSystem: '<S184>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S236>/MeasurementUpdate' */
  HW6_Simulink_DW.MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S236>/MeasurementUpdate' */

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  HW6_Simulink_X.Integrator1_CSTATE = HW6_Simulink_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  HW6_Simulink_X.Integrator3_CSTATE = HW6_Simulink_P.Integrator3_IC;

  /* InitializeConditions for RateLimiter: '<S1>/Rate Limiter' */
  HW6_Simulink_DW.LastMajorTimeA = (rtInf);
  HW6_Simulink_DW.LastMajorTimeB = (rtInf);

  /* InitializeConditions for Integrator: '<S1>/Integrator6' */
  HW6_Simulink_X.Integrator6_CSTATE = HW6_Simulink_P.Integrator6_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator7' */
  HW6_Simulink_X.Integrator7_CSTATE = HW6_Simulink_P.Integrator7_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator8' */
  HW6_Simulink_X.Integrator8_CSTATE = HW6_Simulink_P.Integrator8_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator11' */
  HW6_Simulink_X.Integrator11_CSTATE = HW6_Simulink_P.Integrator11_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator5' */
  HW6_Simulink_X.Integrator5_CSTATE = HW6_Simulink_P.Integrator5_IC;

  /* InitializeConditions for Delay: '<S7>/MemoryX' */
  HW6_Simulink_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S2>/MemoryX' */
  HW6_Simulink_DW.icLoad_h = 1U;

  /* InitializeConditions for Delay: '<S3>/MemoryX' */
  HW6_Simulink_DW.icLoad_p = 1U;

  /* InitializeConditions for Delay: '<S4>/MemoryX' */
  HW6_Simulink_DW.icLoad_f = 1U;

  /* InitializeConditions for Delay: '<S5>/MemoryX' */
  HW6_Simulink_DW.icLoad_d = 1U;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  HW6_Simulink_X.Integrator_CSTATE = HW6_Simulink_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  HW6_Simulink_X.Integrator2_CSTATE = HW6_Simulink_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator4' */
  HW6_Simulink_X.Integrator4_CSTATE = HW6_Simulink_P.Integrator4_IC;

  /* SystemInitialize for Enabled SubSystem: '<S243>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S267>/deltax' */
  HW6_Simulink_B.Product2[0] = HW6_Simulink_P.deltax_Y0;
  HW6_Simulink_B.Product2[1] = HW6_Simulink_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S243>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S35>/Enabled Subsystem' */
  HW6_Simul_EnabledSubsystem_Init(&HW6_Simulink_B.EnabledSubsystem,
    &HW6_Simulink_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S35>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S87>/Enabled Subsystem' */
  HW6_Simul_EnabledSubsystem_Init(&HW6_Simulink_B.EnabledSubsystem_j,
    &HW6_Simulink_P.EnabledSubsystem_j);

  /* End of SystemInitialize for SubSystem: '<S87>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S139>/Enabled Subsystem' */
  HW6_Simul_EnabledSubsystem_Init(&HW6_Simulink_B.EnabledSubsystem_a,
    &HW6_Simulink_P.EnabledSubsystem_a);

  /* End of SystemInitialize for SubSystem: '<S139>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S191>/Enabled Subsystem' */
  HW6_Simul_EnabledSubsystem_Init(&HW6_Simulink_B.EnabledSubsystem_af,
    &HW6_Simulink_P.EnabledSubsystem_af);

  /* End of SystemInitialize for SubSystem: '<S191>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S28>/MeasurementUpdate' */
  HW6_Simu_MeasurementUpdate_Init(&HW6_Simulink_B.MeasurementUpdate,
    &HW6_Simulink_P.MeasurementUpdate);

  /* End of SystemInitialize for SubSystem: '<S28>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S80>/MeasurementUpdate' */
  HW6_Simu_MeasurementUpdate_Init(&HW6_Simulink_B.MeasurementUpdate_j,
    &HW6_Simulink_P.MeasurementUpdate_j);

  /* End of SystemInitialize for SubSystem: '<S80>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S132>/MeasurementUpdate' */
  HW6_Simu_MeasurementUpdate_Init(&HW6_Simulink_B.MeasurementUpdate_p,
    &HW6_Simulink_P.MeasurementUpdate_p);

  /* End of SystemInitialize for SubSystem: '<S132>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S184>/MeasurementUpdate' */
  HW6_Simu_MeasurementUpdate_Init(&HW6_Simulink_B.MeasurementUpdate_j0,
    &HW6_Simulink_P.MeasurementUpdate_j0);

  /* End of SystemInitialize for SubSystem: '<S184>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S236>/MeasurementUpdate' */
  /* SystemInitialize for Outport: '<S265>/L*(y[k]-yhat[k|k-1])' */
  HW6_Simulink_B.Product3[0] = HW6_Simulink_P.Lykyhatkk1_Y0;
  HW6_Simulink_B.Product3[1] = HW6_Simulink_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S236>/MeasurementUpdate' */
}

/* Model terminate function */
void HW6_Simulink_terminate(void)
{
  /* (no terminate code required) */
}

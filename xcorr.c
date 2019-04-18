/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xcorr.c
 *
 * Code generation for function 'xcorr'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "gccGetPosition.h"
#include "xcorr.h"
#include "ifft.h"
#include "fft.h"

/* Function Declarations */
static void crosscorr(const double x[8000], const double y[8000], double c[15999]);

/* Function Definitions */
static void crosscorr(const double x[8000], const double y[8000], double c[15999])
{
  static creal_T dcv0[16384];
  static creal_T dcv1[16384];
  int i;
  static creal_T dcv2[16384];
  static double c1[16384];
  fft(x, dcv0);
  fft(y, dcv1);
  for (i = 0; i < 16384; i++) {
    dcv2[i].re = dcv0[i].re * dcv1[i].re - dcv0[i].im * -dcv1[i].im;
    dcv2[i].im = dcv0[i].re * -dcv1[i].im + dcv0[i].im * dcv1[i].re;
  }

  ifft(dcv2, dcv0);
  for (i = 0; i < 16384; i++) {
    c1[i] = dcv0[i].re;
  }

  memcpy(&c[0], &c1[8385], 7999U * sizeof(double));
  memcpy(&c[7999], &c1[0], 8000U * sizeof(double));
}

void xcorr(const double x[8000], const double varargin_1[8000], double c[15999],
           double lags[15999])
{
  int i1;
  crosscorr(x, varargin_1, c);
  for (i1 = 0; i1 < 15999; i1++) {
    lags[i1] = -7999.0 + (double)i1;
  }
}

/* End of code generation (xcorr.c) */

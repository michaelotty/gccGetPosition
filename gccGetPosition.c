/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * gccGetPosition.c
 *
 * Code generation for function 'gccGetPosition'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "gccGetPosition.h"
#include "sqrt.h"
#include "sind.h"
#include "asind.h"
#include "xcorr.h"
#include "mean.h"
#include <stdio.h>

/* Type Definitions */

/* Function Definitions */
void gccGetPosition(const double allsig[32000], double *x, double *y)
{
  int i0;
  int allsig_tmp;
  double d0;
  static double b_allsig[32000];
  double d1;
  double b_gamma;
  double a;
  static double c_allsig[32000];
  static double corr1[15999];
  static double unusedU0[15999];
  static double lags[15999];
  int k;
  bool exitg1;
  int idx;
  double angle_est[2];

  /*  validateattributes(allsig, {'double'},{'nonempty'},mfilename,'Signals',1) */
  for (i0 = 0; i0 < 8000; i0++) {
    allsig_tmp = i0 << 2;
    b_allsig[i0] = allsig[allsig_tmp];
    b_allsig[8000 + i0] = allsig[2 + allsig_tmp];
    b_allsig[16000 + i0] = allsig[3 + allsig_tmp];
    b_allsig[24000 + i0] = allsig[1 + allsig_tmp];
  }

  /*  Remove DC offset */
  d0 = mean(*(double (*)[8000])&b_allsig[0]);
  d1 = mean(*(double (*)[8000])&b_allsig[8000]);
  b_gamma = mean(*(double (*)[8000])&b_allsig[16000]);
  a = mean(*(double (*)[8000])&b_allsig[24000]);
  for (i0 = 0; i0 < 8000; i0++) {
    c_allsig[i0] = b_allsig[i0] - d0;
    c_allsig[8000 + i0] = b_allsig[8000 + i0] - d1;
    c_allsig[16000 + i0] = b_allsig[16000 + i0] - b_gamma;
    c_allsig[24000 + i0] = b_allsig[24000 + i0] - a;
  }

  memcpy(&b_allsig[0], &c_allsig[0], 32000U * sizeof(double));
  xcorr(*(double (*)[8000])&b_allsig[0], *(double (*)[8000])&b_allsig[8000],
        corr1, unusedU0);
  xcorr(*(double (*)[8000])&b_allsig[16000], *(double (*)[8000])&b_allsig[24000],
        unusedU0, lags);
  if (!rtIsNaN(corr1[7909])) {
    allsig_tmp = 1;
  } else {
    allsig_tmp = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 182)) {
      if (!rtIsNaN(corr1[k + 7908])) {
        allsig_tmp = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (allsig_tmp == 0) {
    allsig_tmp = 1;
  } else {
    b_gamma = corr1[allsig_tmp + 7908];
    i0 = allsig_tmp + 1;
    for (k = i0; k < 182; k++) {
      d0 = corr1[k + 7908];
      if (b_gamma < d0) {
        b_gamma = d0;
        allsig_tmp = k;
      }
    }
  }

  if (!rtIsNaN(unusedU0[7909])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 182)) {
      if (!rtIsNaN(unusedU0[k + 7908])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    idx = 1;
  } else {
    b_gamma = unusedU0[idx + 7908];
    i0 = idx + 1;
    for (k = i0; k < 182; k++) {
      d0 = unusedU0[k + 7908];
      if (b_gamma < d0) {
        b_gamma = d0;
        idx = k;
      }
    }
  }

  angle_est[0] = lags[allsig_tmp + 7909] / 102000.0 * 340.0 / 0.3;
  angle_est[1] = lags[idx + 7909] / 102000.0 * 340.0 / 0.3;
  b_asind(angle_est);
  printf("Angle 1: %f\t\tAngle 2: %f\t", angle_est[0], angle_est[1]);
  fflush(stdout);
  b_gamma = (180.0 - (90.0 + angle_est[0])) - (90.0 - angle_est[1]);
  d0 = 90.0 + angle_est[0];
  b_sind(&d0);
  d1 = b_gamma;
  b_sind(&d1);
  a = d0 / d1;
  d0 = 90.0 - angle_est[1];
  b_sind(&d0);
  b_sind(&b_gamma);
  b_gamma = d0 / b_gamma;
  b_gamma *= b_gamma;
  *x = ((1.0 + b_gamma) - a * a) / 2.0;
  *y = b_gamma - *x * *x;
  b_sqrt(y);
}

/* End of code generation (gccGetPosition.c) */

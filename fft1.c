/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft1.c
 *
 * Code generation for function 'fft1'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "gccGetPosition.h"
#include "fft1.h"

/* Function Definitions */
void b_generate_twiddle_tables(double costab[8193], double sintab[8193])
{
  double costab1q[4097];
  int k;
  double sintab_tmp;
  costab1q[0] = 1.0;
  for (k = 0; k < 2048; k++) {
    costab1q[1 + k] = cos(0.00038349519697141029 * (1.0 + (double)k));
  }

  for (k = 0; k < 2047; k++) {
    costab1q[k + 2049] = sin(0.00038349519697141029 * (4096.0 - ((double)k +
      2049.0)));
  }

  costab1q[4096] = 0.0;
  costab[0] = 1.0;
  sintab[0] = 0.0;
  for (k = 0; k < 4096; k++) {
    costab[1 + k] = costab1q[1 + k];
    sintab_tmp = costab1q[4095 - k];
    sintab[1 + k] = sintab_tmp;
    costab[k + 4097] = -sintab_tmp;
    sintab[k + 4097] = costab1q[k + 1];
  }
}

void generate_twiddle_tables(double costab[8193], double sintab[8193])
{
  double costab1q[4097];
  int k;
  double sintab_tmp;
  costab1q[0] = 1.0;
  for (k = 0; k < 2048; k++) {
    costab1q[1 + k] = cos(0.00038349519697141029 * (1.0 + (double)k));
  }

  for (k = 0; k < 2047; k++) {
    costab1q[k + 2049] = sin(0.00038349519697141029 * (4096.0 - ((double)k +
      2049.0)));
  }

  costab1q[4096] = 0.0;
  costab[0] = 1.0;
  sintab[0] = 0.0;
  for (k = 0; k < 4096; k++) {
    costab[1 + k] = costab1q[1 + k];
    sintab_tmp = -costab1q[4095 - k];
    sintab[1 + k] = sintab_tmp;
    costab[k + 4097] = sintab_tmp;
    sintab[k + 4097] = -costab1q[k + 1];
  }
}

/* End of code generation (fft1.c) */

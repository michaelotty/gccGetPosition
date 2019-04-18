/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * asind.c
 *
 * Code generation for function 'asind'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "gccGetPosition.h"
#include "asind.h"

/* Function Definitions */
void b_asind(double x[2])
{
  x[0] = 57.295779513082323 * asin(x[0]);
  x[1] = 57.295779513082323 * asin(x[1]);
}

/* End of code generation (asind.c) */

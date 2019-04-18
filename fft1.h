/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft1.h
 *
 * Code generation for function 'fft1'
 *
 */

#ifndef FFT1_H
#define FFT1_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "gccGetPosition_types.h"

/* Function Declarations */
extern void b_generate_twiddle_tables(double costab[8193], double sintab[8193]);
extern void generate_twiddle_tables(double costab[8193], double sintab[8193]);

#endif

/* End of code generation (fft1.h) */

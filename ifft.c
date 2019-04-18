/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ifft.c
 *
 * Code generation for function 'ifft'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "gccGetPosition.h"
#include "ifft.h"
#include "fft1.h"

/* Function Definitions */
void ifft(const creal_T x[16384], creal_T y[16384])
{
  double costab[8193];
  double sintab[8193];
  int ix;
  int ju;
  int iy;
  int i;
  bool tst;
  double temp_re;
  double temp_im;
  double twid_re;
  int iheight;
  double twid_im;
  int istart;
  int temp_re_tmp;
  int j;
  int ihi;
  b_generate_twiddle_tables(costab, sintab);
  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i < 16383; i++) {
    y[iy] = x[ix];
    iy = 16384;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y[iy] = x[ix];
  for (i = 0; i <= 16382; i += 2) {
    temp_re = y[i + 1].re;
    temp_im = y[i + 1].im;
    twid_re = y[i].re;
    twid_im = y[i].im;
    y[i + 1].re = y[i].re - y[i + 1].re;
    y[i + 1].im = y[i].im - y[i + 1].im;
    twid_re += temp_re;
    twid_im += temp_im;
    y[i].re = twid_re;
    y[i].im = twid_im;
  }

  iy = 2;
  ix = 4;
  ju = 4096;
  iheight = 16381;
  while (ju > 0) {
    for (i = 0; i < iheight; i += ix) {
      temp_re_tmp = i + iy;
      temp_re = y[temp_re_tmp].re;
      temp_im = y[i + iy].im;
      y[temp_re_tmp].re = y[i].re - y[temp_re_tmp].re;
      y[temp_re_tmp].im = y[i].im - temp_im;
      y[i].re += temp_re;
      y[i].im += temp_im;
    }

    istart = 1;
    for (j = ju; j < 8192; j += ju) {
      twid_re = costab[j];
      twid_im = sintab[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = twid_re * y[temp_re_tmp].re - twid_im * y[i + iy].im;
        temp_im = twid_re * y[i + iy].im + twid_im * y[i + iy].re;
        y[temp_re_tmp].re = y[i].re - temp_re;
        y[temp_re_tmp].im = y[i].im - temp_im;
        y[i].re += temp_re;
        y[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    ju /= 2;
    iy = ix;
    ix += ix;
    iheight -= iy;
  }

  for (iy = 0; iy < 16384; iy++) {
    y[iy].re *= 6.103515625E-5;
    y[iy].im *= 6.103515625E-5;
  }
}

/* End of code generation (ifft.c) */

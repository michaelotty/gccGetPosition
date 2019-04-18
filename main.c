
#define D0 0
#define D1 1
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define D8 8
#define D9 9
#define D10 10
#define D11 11
#define CONV 12
#define BUSY 13
#define RD 14
#define CS_A 15
#define CS_B 16

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>
/*
* Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include files */
#include "rt_nonfinite.h"
#include "gccGetPosition.h"
#include "main.h"
#include "gccGetPosition_terminate.h"
#include "gccGetPosition_initialize.h"

/* Function Declarations */
static void getWaveform(double data[32000]);
static void main_gccGetPosition(void);
int getSample();

/* Function Definitions */
static void getWaveform(double data[32000])
{
	int loops = 8000;

	for(int i = 0; i < loops; i++) {
		digitalWrite(CONV, LOW);
		digitalWrite(CONV, HIGH);

		while(digitalRead(BUSY)){
//			printf("ADC is busy...\n");
		}// Wait until BUSY is 0
    

		digitalWrite(RD, LOW);
		digitalWrite(CS_A, LOW);

		data[4*i] = (double) getSample();

		digitalWrite(CS_A, HIGH);

		digitalWrite(CS_B, LOW);

		data[4*i+1] = (double) getSample();

		digitalWrite(RD, HIGH);
		digitalWrite(CS_B, HIGH);

		digitalWrite(RD, LOW);
		digitalWrite(CS_A, LOW);

		data[4*i+2] = (double) getSample();

		digitalWrite(CS_A, HIGH);

		digitalWrite(CS_B, LOW);

		data[4*i+3] = (double) getSample();

		digitalWrite(CS_B, HIGH);
		digitalWrite(RD, HIGH);
	}
}


static void main_gccGetPosition(void)
{
  static double dv0[32000];
  double x;
  double y;

	wiringPiSetup();
	pinMode(D0, INPUT);
	pinMode(D1, INPUT);
	pinMode(D2, INPUT);
	pinMode(D3, INPUT);
	pinMode(D4, INPUT);
	pinMode(D5, INPUT);
	pinMode(D6, INPUT);
	pinMode(D7, INPUT);
	pinMode(D8, INPUT);
	pinMode(D9, INPUT);
	pinMode(D10, INPUT);
	pinMode(D11, INPUT);
	pinMode(CONV, OUTPUT);
	pinMode(BUSY, INPUT);
	pinMode(RD, OUTPUT);
	pinMode(CS_A, OUTPUT);
	pinMode(CS_B, OUTPUT);

	digitalWrite(CS_A, HIGH);
	digitalWrite(CS_B, HIGH);
	digitalWrite(RD, HIGH);
  /* Initialize function 'gccGetPosition' input arguments. */
  /* Initialize function input argument 'allsig'. */
  /* Call the entry-point 'gccGetPosition'. */
  while(1){
    getWaveform(dv0);
    gccGetPosition(dv0, &x, &y);
    printf("%f\t%f\n", x, y);
    delay(500);
  }
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  gccGetPosition_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_gccGetPosition();

  /* Terminate the application.
     You do not need to do this more than one time. */
  gccGetPosition_terminate();
  return 0;
}

/* End of code generation (main.c) */
int getSample() {
	int a, b, c, d, e, f, g, h, i, j, k, l;
	a = digitalRead(D11);
	a = a << 11;
	b = digitalRead(D10);
	b = b << 10;
	c = digitalRead(D9);
	c = c << 9;
	d = digitalRead(D8);
	d = d << 8;
	e = digitalRead(D7);
	e = e << 7;
	f = digitalRead(D6);
	f = f << 6;
	g = digitalRead(D5);
	g = g << 5;
	h = digitalRead(D4);
	h = h << 4;
	i = digitalRead(D3);
	i = i << 3;
	j = digitalRead(D2);
	j = j << 2;
 	k = digitalRead(D1);
	k = k << 1;
 	l = digitalRead(D0);
	
	int sample = 0x000 | a | b | c | d | e | f | g | h | i | j | k | l;

	sample = (sample >> 11) == 0 ? sample : (-1 ^ 0xFFF) | sample;
  	/*if (a) {
		printf("negated\t");
    		sample = sample ^ 0x7FF;
		sample++;
	}*/

  	//printf("%d\t", sample);
	//  printf("%d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j, k, l); 

	return sample;
}


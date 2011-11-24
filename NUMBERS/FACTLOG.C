/* -------------------------------------------------------- */
/* FUNCTION factorial :                                     */
/*    This is an O(logN) function for calculating n!.  It   */
/* combines the O(logN) power concept and divide-and-conquer*/
/* technique.  NOTE that the improvement is that all        */
/* C(n,n/2) needed are computed along with the (2^n+1)^2.   */
/* Thus if we can save these C(n,n/2)'s it is not necessary */
/* to call cnr(*,*) each time when C(n,n/2) is computed.    */
/* NOTE also this function works fine for n <= 7 only on a  */
/* 32 bit unsigned long computer and for these small numbers*/
/* this function is slower than the others.  But remember   */
/* that the meaning of O(logN) is for large N's, this means */
/* we will have bigger speed gain when n is getting larger. */
/*                                                          */
/* Copyright Ching-Kuang SHENE                  Feb/25/1989 */
/* -------------------------------------------------------- */

unsigned long  mask;          /* mask for shifting bits     */
unsigned cnrs[100];           /* storage for C(n,n/2)'s     */
int      number;              /* index for cnrs[]           */
int      p_size;              /* partition size in C(n,n/2) */

unsigned long  factor(unsigned long);
unsigned long  power(unsigned long, unsigned long);


/* -------------------------------------------------------- */
/* FUNCTION factorial :                                     */
/*    Control routine of n! calculation.                    */
/* -------------------------------------------------------- */

unsigned long  factorial(unsigned long n)
{
     unsigned long  x = (1 << n) + 1;

     number = 0;              /* set index to init. pos.    */
     mask   = (1 << n) - 1;   /* set up mask for shifting   */
     p_size = n;              /* set up partition size      */
     (void) power(x, n);      /* now computing (2^n+1)^n    */
     number = 0;              /* reset index to the start   */
     return factor(n);        /* then compute n!            */
}


/* -------------------------------------------------------- */
/* FUNCTION factor :                                        */
/*    This is the working routine for n!.  The idea is      */
/*                                                          */
/*          +-  1                  if n = 1                 */
/*          |                                               */
/*    n! =  +   n * (n-1)!         if n is odd              */
/*          |                                               */
/*          +-  C(n,n/2)*[(n/2)]!  if n is even             */
/*                                                          */
/* Before factor() is called n_power() is used to compute   */
/* (2^n+1)^n and during the course of this computation, it  */
/* stores all relevant C(n,n/2) into array cnrs[].  Thus    */
/* C(n,n/2)'s are available from array C(n,n/2) here.       */
/* -------------------------------------------------------- */

unsigned long  factor(unsigned long n)
{
     unsigned long  temp;

     if (n == 1)
          return 1;
     else if (n & 0x01UL == 1)
          return n * factor(n - 1);
     else {
          temp = factor(n >> 1);
          return cnrs[number++] * temp * temp;
     }
}


/* -------------------------------------------------------- */
/* FUNCTION power :                                         */
/*    The modified power function to compute (2^n+1)^n in   */
/* recursive mode.  During its computation, n_power() will  */
/* save C(n,n/2) into array cnrs[].                         */
/* -------------------------------------------------------- */

unsigned long  power(unsigned long n, unsigned long m)
{
     unsigned long  temp;

     if (m == 1)
          temp = n;
     else if (m & 0x01UL != 0)
          temp = n * power(n, m-1);
     else {
          temp = power(n, m >> 1);
          temp *= temp;
          cnrs[number++] = (temp >> ((m >> 1)*p_size)) & mask;
     }
     return temp;
}


/* -------------------------------------------------------- */

#include  <stdio.h>
#include  <stdlib.h>          /* for strtoul() function     */

void main(void)
{
     char  line[100], *dummy_ptr;
     unsigned long m, n;

     printf("\nThe Fast N! Computation :");
     printf("\n\nN for N! please --> ");
     gets(line);
     n = strtoul(line, &dummy_ptr, 10);
     printf("\n%lu! = %lu", n, factorial(n));
}

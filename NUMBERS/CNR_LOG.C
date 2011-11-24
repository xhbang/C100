/* --------------------------------------------------------- */
/* FUNCTION cnr :                                            */
/*    A special function to calculate all C(n,r)'s given n.  */
/* It employs a very special trick on bit operations.  NOTE  */
/* that depend on the number of bits for unsigned long type  */
/* this function might returns wrong answer.  The rule of    */
/* thumb is that if unsigned long has k bits then the max.   */
/* of n, the input, should be no more than following :       */
/*                                                           */
/*          -1 + sqrt(1 + 4*k)                               */
/*         --------------------                              */
/*                   2                                       */
/*                                                           */
/* Thus for k=32 as many microprocessor has, then the max.   */
/* of n is 5.  But this should not be viewd as a restriction */
/* because the same algorithm can be used in more advanced   */
/* non-numeric applications.                                 */
/*                                                           */
/* Copyright Ching-Kuang SHENE                   Feb/24/1989 */
/* --------------------------------------------------------- */

unsigned long  power(unsigned long, unsigned long);

void  cnr(int n, int answer[])
{
     unsigned long  x    = (1 << n) + 1;  /* 2^n + 1         */
     unsigned long  mask = (1 << n) - 1;  /* 2^n - 1, n 1's  */
     unsigned long  result;
     int      i;

     result = power(x, (unsigned long) n); /* (2^n+1)^n      */

     for (i = 0; i <= n; i++, result >>= n) /* retrieve data */
          answer[i] = result & mask;
}


/* ------------------------------------------------------ */
/* FUNCTION power :                                       */
/*    This is the function called 'iterative_power' in    */
/* file I_POWER.C of this book.                           */
/* ------------------------------------------------------ */

unsigned long power(unsigned long m, unsigned long n)
{
     unsigned long  temp = 1;

     while (n > 0) {          /* if there exists 1 bits.. */
          if (n & 0x01UL == 1)/* the right most one ?     */
               temp *= m;     /* YES, the result get a 'm'*/
          m *= m;             /* anyway, compute m^k      */
          n >>= 1;            /* throw away this bit      */
     }
     return temp;
}


/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE  10

void main(void)
{
     int  answer[MAXSIZE];
     int  n, r;
     char line[100];

     printf("\nFast Combinatorial Coefficient Computation");
     printf("\n==========================================");
     printf("\n\nN ---> ");
     gets(line);
     n = atoi(line);

     cnr(n, answer);
     printf("\nAll Combinatorial Coefficients :\n");
     for (r = 0; r <= n; r++)
          printf("\nC(%d,%d) = %d", n, r, answer[r]);
}

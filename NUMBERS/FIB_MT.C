/* ------------------------------------------------------ */
/* FUNCTION fib_mt :                                      */
/*    Probably, this is the most natural way to speed up  */
/* to speedup Fibonacci number generation.  Almost all    */
/* books on algorithm design and analysis mention this    */
/* technique in some details.  This method converts the   */
/* computation of Fibonacci number to a sequence of       */
/* matrix multiplication as discussed in my article.      */
/*                                                        */
/* Copyright Ching-Kuang Shene               June/14/1989 */
/* ------------------------------------------------------ */


void matrix_power(unsigned long, unsigned long, 
                  unsigned long, unsigned long, int,
                  unsigned long *, unsigned long *, 
                  unsigned long *, unsigned long *);


unsigned long  fibonacci(int  n)
{
     unsigned long  a, b, c, d;

     if (n <= 2)
          return 1;
     else {                   /* A^(n-2) of a matrix A    */
          matrix_power(1UL, 1UL, 1UL, 0UL, n-2, &a, &b, &c, &d);
          return a + b;
     }
}


/* ------------------------------------------------------ */
/* FUNCTION matrix_power :                                */
/*    This function accepts a matrix X and computes       */
/* X^(n-2) for n >= 3 using the power computation method, */
/* where X is defined as follows                          */
/*                                                        */
/*     +-       -+   +-      -+(n-2)                      */
/*     | aa   bb |   | a    b |                           */
/*     |         | = |        |                           */
/*     | cc   dd |   | c    d |                           */
/*     +-       -+   +-      -+                           */
/* ------------------------------------------------------ */

void matrix_power(unsigned long a,   unsigned long b, 
                  unsigned long c,   unsigned long d, int n,
                  unsigned long *aa, unsigned long *bb,
                  unsigned long *cc, unsigned long *dd)
{
     unsigned long  xa, xb, xc, xd;

     if (n == 1)
          *aa = a, *bb = b, *cc = c, *dd = d;
     else if (n & 0x01 == 1) { /* n odd: X^(2k+1)=X*X^(2k)*/
          matrix_power(a, b, c, d, n-1, &xa, &xb, &xc, &xd);
          *aa = a*xa + b*xc;
          *bb = a*xb + b*xd;
          *cc = c*xa + d*xc;
          *dd = c*xb + d*xd;
     }
     else {                   /* n even: X^(2k)=(X^(2k))^2*/
          matrix_power(a, b, c, d, n>>1, &xa, &xb, &xc, &xd);
          *aa = xa*xa + xb*xc;
          *bb = xa*xb + xb*xd;
          *cc = xc*xa + xd*xc;
          *dd = xc*xb + xd*xd;
     }
}


/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>             /* for function atoi()   */

void main(void)
{
     char  line[100];
     int   n;

     printf("\nO(log(n)) Fibonacci Number Computation\n");
     printf("\nn please ---> ");
     gets(line);
     n = atoi(line);
     printf("\nfib(%d) = %lu", n, fibonacci(n));
}

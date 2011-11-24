/* ------------------------------------------------------ */
/* FUNCTION fibonacci :                                   */
/*    This program uses two aux. variables to hold two    */
/* intermideate results and thus achieves linear time.    */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/02/1989 */
/* ------------------------------------------------------ */

unsigned long  fibonacci(int n)
{
     unsigned long  f0, f1, temp;
     int  i;

     if (n <= 2)
          return 1;
     else {
          for (f0 = f1 = 1, i = 3; i <= n; i++) {
               temp = f0 + f1; /* temp = f(n-2)+f(n-1)    */
               f0   = f1;      /* f0   = f(n-2)           */
               f1   = temp;    /* f1   = f(n-1)           */
          }
          return f1;
     }
}


/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>             /* for function atoi()   */

void main(void)
{
     char  line[100];
     int   n;

     printf("\nIterative Linear Fibonacci Number Computation\n");
     printf("\nn please ---> ");
     gets(line);
     n = atoi(line);
     printf("\nfib(%d) = %lu", n, fibonacci(n));
}

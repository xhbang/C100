/* ------------------------------------------------------ */
/* FUNCTION ext_fibonacci :                               */
/*    This program extends the Fibonacci number a little  */
/* bit (see the accompanied text please.  This is a       */
/* modification of the iterative version of Fibonacci     */
/* Number computation.  But you can also use the more     */
/* efficient matrix version.                              */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/02/1989 */
/* ------------------------------------------------------ */

unsigned long ext_fibonacci(int n, int x, int y)
{
     unsigned long  f0, f1;
     unsigned long  a0, a1;
     unsigned long  temp1, temp2;
     int  i;

     if (n == 0)
          return 1;
     else if (n == 1)
          return 2;
     else {
          for (f0 = f1 = 1, a0 = 1, a1 = 2, i = 2; i <= n; i++) {
               temp1 = x*f1 + y*f0;
               f0    = f1;
               f1    = temp1;
               temp2 = x*a0 + y*(a1 - f0) + f0 + f1;
               a0    = a1;
               a1    = temp2;
          }
          return a1;
     }
}


/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

void main(void)
{
     char line[100];
     int  n, x, y;

     printf("\nExtended Fibonacci Number Computation\n");
     printf("\nGiven x and y, define the Extended Fibonacci"
            " Number as follows\n");
     printf("\nXfib(0) = 1; Xfib(1) = 1;"
            " Xfib(n) = x*Xfib(n-1) + y*Xfib(n-2)\n");
     printf("\nNow given another integer n, compute the sum of");
     printf("\nXfib(0)*Xfib(n) + Xfib(1)*Xfib(n-1) + ... +"
            " Xfib(i)*Xfib(n-i) + ... ");
     printf("\n                + Xfib(n-1)*Xfib(1) + Xfib(n)*Xfib(0)\n");

     printf("\nx ---> ");
     gets(line);
     x = atoi(line);
     printf("\ny ---> ");
     gets(line);
     y = atoi(line);
     printf("\nn ---> ");
     gets(line);
     n = atoi(line);
     printf("\n\nAnswer is %lu", ext_fibonacci(n, x, y));
}

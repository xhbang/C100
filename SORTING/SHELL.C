/* ------------------------------------------------------ */
/* FUNCTION  shell :                                      */
/*    This is the Shell Sort program.  But the gap        */
/* sequence used will affect the performance of the Shell */
/* sort.  As proved by D.Knuth in his famous book, the    */
/* commonly used sequence, n/2, n/2^2, n/2^3, ..., 4. 2, 1*/
/* can achieve the order of O(n^1.5).  But Sedgewick found*/
/* a new gap sequence recently which can achieve the order*/
/* of O(n^(4/3)).  Thus it is a little bit faster than    */
/* the original version of D.L.Shell.                     */
/*    The sequence used here is suggested by Sedgewick and*/
/* is defined as 4^(j+1) + 3*2^j + 1 = 1, 8, 23, 77, 281, */
/* 1073, ....                                             */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/30/1989 */
/* ------------------------------------------------------ */

#include  <math.h>            /* for sqrt()               */

#define   EQN(x)              ((4*x+3)*x+1)

void  sort(int x[], int n)
{
     int  gap;                /* the gap sequence variable*/
     int  power2;             /* represents 2^j           */
     int  i, j, temp;         /* working variables        */
     
     power2 = log((-3.0 + sqrt(16.0*n-7.0))/8.0)/log(2.0);
     power2 = 1 << (power2 + 1);
     do {
          power2 >>= 1;
          gap    = EQN(power2);
          for (i = gap; i < n; i++)
               for (j=i-gap; j>=0 && x[j] > x[j+gap]; j -= gap) {
                    temp = x[j];
                    x[j] = x[j+gap];
                    x[j+gap] = temp;
               }
     } while (gap > 1);
}

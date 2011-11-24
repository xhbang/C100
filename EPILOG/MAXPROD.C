/* ------------------------------------------------------ */
/* FUNCTION max_prod :                                    */
/*    This function accepts an integer array and computes */
/* the maximum consecutive product.  If the maximum is    */
/* negative, this programs returns one.                   */
/*                                                        */
/* Copyright Ching-Kuang Shene               Sept/01/1989 */
/* ------------------------------------------------------ */

#define  MIN(x, y)  ((x) <= (y) ? (x) : (y))
#define  MAX(x, y)  ((x) >= (y) ? (x) : (y))

int  max_prod(int  x[], int n)
{
     int  max_ending_here = 1;/* max. computed ended here */
     int  min_ending_here = 1;/* min. computed ended here */
     int  max_so_far      = 1;/* global maximum so far    */
     int  temp, i;

     for (i = 0; i < n; i++) {/* scan each element in turn*/
          if (x[i] > 0) {     /* if x[i] is positive ...  */
               max_ending_here *= x[i]; /* max will incr. */
               min_ending_here = MIN(min_ending_here*x[i],1);
          } 
          else if (x[i] == 0) { /* if zero, reset         */
               max_ending_here = 1;
               min_ending_here = 0;
          }
          else {              /* x[i] < 0                 */
               temp            = max_ending_here;
               max_ending_here = MAX(min_ending_here*x[i],1);
               min_ending_here = temp * x[i];
          }
          max_so_far = MAX(max_so_far, max_ending_here);
     }
     return max_so_far;
}


/* ------------------------------------------------------ */

#include  <stdio.h>

void main(void)
{
     int  x[] = { 2, -3, 0, -4, 3, -2, -3, 3};
     int  n   = sizeof(x)/sizeof(int);
     int  i;

     printf("\nMaximum Consecutive Elements Producr Program");
     printf("\n============================================");
     printf("\n\nGiven Array :");

     for (i = 0; i < n; i++)
          printf("%4d", x[i]);

     printf("\n\nMaximum Product is %d", max_prod(x, n));
}

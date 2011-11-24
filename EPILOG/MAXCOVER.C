/* ------------------------------------------------------ */
/* FUNCTION  maxcover :                                   */
/*    Given an integer, this function computes the max.   */
/* cover interval length of the array.  A cover interval  */
/* of an element of the array, say x[i], is an interval   */
/* [j,i], j <= i, such that for all k, j<=k<=i, we have   */
/* x[k] <= abs(x[i]).  A maximal cover interval is an     */
/* interval with maximum length.                          */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/11/1989 */
/* ------------------------------------------------------ */

#include  <math.h>            /* for abs()                */

#define   MAX(x, y)  ((x) >= (y) ? (x) : (y))

int  maxcover(int x[], int n)
{
     int  length;             /* max. interval length     */
     int  bound;              /* last element searched    */
     int  i;

     length = 1;              /* min. length is one       */
     bound  = n - 1;          /* start from n-1 th item   */
     for (i = n - 2; i >= 0; i--) { /* for each item...   */
          for ( ; x[i] > abs(x[bound]); bound--) /* bound?*/
               ;              /* now x[i] <= x[bound] ... */
          length = MAX(length, bound-i+1); /* update len. */
     }
     return length;
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     int  x[] = { 1, 6, 2, 1, -2, 3, 5, 2, -4, 3};
     int  n   = sizeof(x)/sizeof(int);
     int  i;

     printf("\nMaximum Cover Interval of an Array");
     printf("\n==================================");
     printf("\n\nGiven Array :\n");
     for (i = 0; i < n; i++)
          printf("%d ", x[i]);
     printf("\n\nMaximum Interval Length = %d", maxcover(x, n));
}

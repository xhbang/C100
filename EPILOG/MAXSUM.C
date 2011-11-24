/* ------------------------------------------------------ */
/* FUNCTION max_sum :                                     */
/*    This function accepts an integer array and computes */
/* the maximum consecutive sum.  If the maximum sum is    */
/* negative, this programs returns zero.                  */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/01/1989 */
/* ------------------------------------------------------ */

int  max_sum(int  x[], int n)
{
     int  max_ending_here = 0;/* max. computed ended here */
     int  max_so_far      = 0;/* global maximum so far    */
     int  i;

     for (i = 0; i < n; i++) {/* scan each element in turn*/
          if (max_ending_here + x[i] < 0) /* sum positive?*/
               max_ending_here = 0;  /* NO, set it to 0   */
          else                /* else update the max. sum */
               max_ending_here += x[i]; /* ended here and */
          if (max_ending_here > max_so_far) /* sum inc?   */
               max_so_far = max_ending_here;/* YES, update*/
     }
     return max_so_far;
}


/* ------------------------------------------------------ */

#include  <stdio.h>

void main(void)
{
     int  x[] = { 2, -3, 1, -1, 3, -2, -3, 3};
     int  n   = sizeof(x)/sizeof(int);
     int  i;

     printf("\nMaximum Consecutive Elements Sum Program");
     printf("\n========================================");
     printf("\n\nGiven Array :");

     for (i = 0; i < n; i++)
          printf("%4d", x[i]);

     printf("\n\nMaximum Sum is %d", max_sum(x, n));
}

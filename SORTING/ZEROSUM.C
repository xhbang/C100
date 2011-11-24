/* ------------------------------------------------------ */
/* FUNCTION  zero_sum :                                   */
/*    Given an integer array, this function checks to see */
/* if there is a subarray summing up to zero.  NOTE that  */
/* sorting is still the most efficient way to solve this  */
/* problem.                                               */
/* ------------------------------------------------------ */

#define    YES    1
#define    NO     0

void  sort(int [], int);

int  zero_sum(int x[], int n)
{
     int  i;

     for (i = 1; i < n; i++)  /* compute prefix sum       */
          x[i] += x[i-1];
     sort(x, n);              /* then sort these sums     */
     for (i = 1; i < n && x[i] != x[i-1]; i++) /* unique? */ 
          ;
     return (i == n) ? NO : YES; /* if not unique, YES.   */
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void main(void)
{
     int  x[] = { 4, -1, 2, 1, -2, -1, 5};
     int  n   = sizeof(x)/sizeof(int);
     int  i;

     printf("\nZero Sum Sunarray Check Program");
     printf("\n===============================");
     printf("\n\nGiven Array :");
     for (i = 0; i < n; i++)
          printf("%4d", x[i]);
     if (zero_sum(x, n) == YES)
          printf("\n\nYES, there is some range summing up to 0");
     else
          printf("\n\nNO! no such subarray found");
}

/* ------------------------------------------------------ */
/* FUNCTION min_distance :                                */
/*    Given two sorted (increasing) arrays, this function */
/* computes the minimum distance between these two arrays */
/* by using the techniques employed in the previous       */
/* examples.                                              */
/*                                                        */
/* Copyright Ching-Kuang Shene               June/30/1989 */
/* ------------------------------------------------------ */

#include <limits.h>

#define  min(x, y)     ((x) < (y) ? (x) : (y))

int  min_distance(int x[], int y[], int m, int n)
{
     int  minimum = INT_MAX;  /* INT_MAX is from limits.h */
     int  index_x = 0, index_y = 0;

     while (index_x < m && index_y < n)
          if (x[index_x] >= y[index_y]) {
               minimum = min(minimum, x[index_x]-y[index_y]);
               index_y++;
          }
          else {
               minimum = min(minimum, y[index_y]-x[index_x]);
               index_x++;
          }
     return minimum;
}


/* ------------------------------------------------------ */
 
#include  <stdio.h>

void main(void)
{
     int  x[] = { 1, 3, 7, 11, 18};
     int  m   = sizeof(x)/sizeof(int);

     int  y[] = { 4, 5, 8, 13, 22};
     int  n   = sizeof(y)/sizeof(int);

     int  i, min_distance(int [], int [], int, int);

     printf("\nCompute Minimum Distance Between Two Sorted Arrays");
     printf("\n==================================================");
     printf("\n\nGiven Array #1 :");
     for (i = 0; i < m; i++)
          printf("%5d", x[i]);
     printf("\n\nGiven Array #2 :");
     for (i = 0; i < n; i++)
          printf("%5d", y[i]);
     printf("\n\nMinimum Distance = %d", min_distance(x, y, m, n));
}

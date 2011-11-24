/* ------------------------------------------------------ */
/* FUNCTION  coincidence_count :                          */
/*    Given two sorted (increasing) arrays, this function */
/* determines how many equal pairs there are.  Note that  */
/* 'sorted' is a very strong requirement.                 */
/*                                                        */
/* Copyright Ching-Kuang Shene               June/30/1989 */
/* ------------------------------------------------------ */

int coincidence_count(int f[], int g[], int m, int n)
{
     int  index_f, index_g;   /* subscripts for f and g   */
     int  count;              /* equal pair counter       */

     count = index_f = index_g = 0;
     while (index_f < m && index_g < n) 
          if (f[index_f] < g[index_g]) /* if f[] is less  */
               index_f++;              /* then move f     */
          else if (f[index_f] > g[index_g]) /* if f[] >   */
               index_g++;              /* then move g     */
          else
               count++, index_f++, index_g++; /* EQUAL    */
     return count;
}

/* ------------------------------------------------------ */

#include <stdio.h>

void main(void)
{
     int  x[] = {  1,  2,  4,  7,  9, 12, 13, 15, 16, 20};
     int  nx  = sizeof(x)/sizeof(int);

     int  y[] = {  4,  5,  7,  8,  9, 10, 11, 13, 16, 19};
     int  ny  = sizeof(y)/sizeof(int);

     int  coincidence_count(int [], int [], int, int), i;

     printf("\nCoincidence Count of two Increasing Arrays\n");
     printf("\n  #   Array 1   Array 2");
     printf("\n --   -------   -------");

     for (i = 0; i < nx; i++)
          printf("\n%3d%10d%10d", i, x[i], y[i]);
     printf("\n\nThere are %d equal numbers.", 
            coincidence_count(x, y, nx, ny));
}

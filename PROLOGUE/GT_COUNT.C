/* ------------------------------------------------------ */
/* FUNCTION dominance_count :                             */
/*    Given two sorted (increasing) arrays, this function */
/* computes the number of pairs that satisfies f[i]>g[j]. */
/* This function is similar to coincidence_count().       */
/*                                                        */
/* Copyright Ching-Kuang Shene               June/30/1989 */
/* ------------------------------------------------------ */

int  dominance_count(int f[], int g[], int m, int n)
{
     int  index_f, index_g;
     int  count;

     count = index_f = index_g = 0;
     while (index_f < m && index_g < n)
          if (f[index_f] <= g[index_g])
               index_f++;
          else
               index_g++, count += m - index_f;
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

     int  dominance_count(int [], int [], int, int), i;

     printf("\nDominance Count of two Increasing Arrays\n");
     printf("\n  #   Array 1   Array 2");
     printf("\n --   -------   -------");

     for (i = 0; i < nx; i++)
          printf("\n%3d%10d%10d", i, x[i], y[i]);
     printf("\n\nThere are %d Dominance Pairs.", 
            dominance_count(x, y, nx, ny));
}

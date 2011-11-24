/* ------------------------------------------------------ */
/* FUNCTION  cyclic_min :                                 */
/*    Given a sorted array stored in a cyclic fashion,    */
/* this function locates the minimum with a modified      */
/* binary search.                                         */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/26/1989 */
/* ------------------------------------------------------ */

int  cyclic_min(int  x[], int n)
{
     int  left  = 0;
     int  right = n - 1;
     int  mid;

     while (left < right) {        /* if there is a gap : */
          mid = (left + right)/2;  /* get the middle item */
          if (x[mid] < x[right])   /* if < the right most */
               right = mid;        /* then chop right part*/
          else                     /* if >= the left part */
               left  = mid + 1;    /* then chop right part*/
     }
     return left;                  /* answer is the item  */
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     int  x[] = { 20, 23, 28, 35, 39, 40, 42, 8, 10, 15, 17, 19};
     int  n   = sizeof(x)/sizeof(int);
     int  loc, i;

     printf("\nFind Cyclic Minimum");
     printf("\n===================");
     printf("\n\nGiven Array Sorted in Cyclic Fashion :\n");
     for (i = 0; i < n; i++)
          printf("%3d", x[i]);
     
     loc = cyclic_min(x, n);
     printf("\n\nMinimum is located at x[%d] = %d", loc, x[loc]);
}

/* ------------------------------------------------------ */
/* FUNCTION  bolzano_search :                             */
/*    This is the discretized Bolzano algorithm for       */
/* continue equation solving.  It is simply a bineary     */
/* search, but the key to be searched must be in between  */
/* the range of two end points.                           */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/28/1989 */
/* ------------------------------------------------------ */

#define   ERROR    -1

int  bolzano_search(int x[], int n, int key)
{
     int  low  = 0;
     int  high = n-1;
     int  mid;

     if (key > x[n-1] || key < x[0]) /* reject illegal in */
          return ERROR;

     while (low <= high) {    /* simply a binary search   */
          mid = (low + high)/2;
          if (key > x[mid])
               low  = mid + 1;
          else if (key < x[mid])
               high = mid - 1;
          else
               return mid;    /* search succeeds always   */
     }
}

/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

void  main(void)
{
     int  x[] = { 1, 2, 3, 2, 3, 4, 3, 2, 1, 0, 
                  1, 2, 3, 4, 5, 6, 5, 6, 7, 8 };
     int  n   = sizeof(x)/sizeof(int);
     int  key, answer, i;
     char line[100];

     printf("\nBolzano Type Binary Search");
     printf("\n==========================");
     printf("\n\nThe Given Array :\n\n");
     for (i = 0; i < n; i++)
          printf("%3d", x[i]);
     printf("\n\nWhat is the key to be searched --> ");
     gets(line);
     key = atoi(line);
     if ((answer = bolzano_search(x, n, key)) >= 0)
          printf("\nKey found at location %d", answer);
     else
          printf("\n*** Input error ***\n Should be in the range"
                 " of %d and %d (the first and the last element)",
                 x[0], x[n-1]);
}

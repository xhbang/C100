/* ------------------------------------------------------ */
/* FUNCTION  pos_neg_balance :                            */
/*    Given an integer array x[], this function computes  */
/* the largest section of the array with equal number of  */
/* positive and negative numbers.                         */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/10/1989 */
/* ------------------------------------------------------ */

#include  <stdlib.h>          /* for malloc()             */

#define   MAX(x, y)   ((x) >= (y) ? (x) : (y))

int  pos_neg_balance(int x[], int n)
{
     int  length;             /* maximum length so far    */
     int  neg_over;           /* #of neg - #of pos        */
     int  min_over;           /* min of neg_over so far   */
     int  max_over;           /* max of neg_over so far   */
     int  mid;                /* the middle item of work  */
     int  i;
     int  *loc;               /* addr. of working array   */

     length   = neg_over = min_over = max_over = 0;
     loc      = (int *) malloc(sizeof(int)*(n+n));
     mid      = n;
     loc[mid] = 0;            /* #of neg=#of pos at start */
     for (i = 0; i < n; i++) {/* for each element in x[]..*/
          if (x[i] < 0)       /* if negative              */
               neg_over++;    /* #of neg increased        */
          else if (x[i] > 0)  /* or if positive           */
               neg_over--;    /* #of neg. decreased       */
          if (neg_over < min_over) {  /* update min.      */
               min_over = neg_over;
               loc[mid+min_over] = i + 1; /* and store it */
          }
          else if (neg_over > max_over) { /* update max.  */
               max_over = neg_over;
               loc[mid+max_over] = i + 1;
          }
          length = MAX(length, i+1-loc[mid+neg_over]);
     }
     free(loc);
     return length;
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     int  x[] = { 1, 1, -1, -2, 0, 1, 3, -1, 2, -1};
     int  n   = sizeof(x)/sizeof(int);
     int  i;

     printf("\nMaximum Interval of Balanced Positive/Negative Numbers");
     printf("\n======================================================");
     printf("\n\nGiven Array :\n");
     for (i = 0; i < n; i++)
          printf("%d ", x[i]);
     printf("\n\nInterval Length = %d", pos_neg_balance(x, n));
}

/* ------------------------------------------------------ */
/* FUNCTION  diameter :                                   */
/*    Given the length of each side of a polygon, this    */
/* function determines its diameter.  The diameter of a   */
/* polygon is the line segment joining from i to j, i < j,*/
/* such that absolute difference of d[i]+d[i+1]+...+d[j]  */
/* and d[j]+...+d[n-1]+d[0]+...+d[i-1] is minimal.        */
/*                                                        */
/* Copyright Ching-Kuang Shene               Sept/01/1989 */
/* ------------------------------------------------------ */

#include  <stdlib.h>

void  diameter(int len[], int n, int *first, int *last)
{
     int  start, end;         /* [end,start] is the min   */
     int  lead, follow;       /* [follow,lead]-running min*/
     int  diff, abs_diff;     /* diff and absolute diff   */
     int  current_min;        /* current min - [end,start]*/
     int  i;

     for (i = diff = 0; i < n; diff -= len[i], i++)
          ;                    /* compute max. diff       */

     abs_diff = current_min = -diff; 
     for (lead = follow = start = end = 0; lead < n; ) {
          if (current_min >= abs_diff) {  /* update min   */
               current_min = abs_diff;
               start       = lead;
               end         = follow;
          }
          if (diff >= 0)      /* if diff > 0 ...          */
               diff -= 2*len[follow++]; /* too big, dec.  */
          else                /* if diff < 0 ...          */
               diff += 2*len[lead++];   /* too small, inc */
          abs_diff = abs(diff);  /* update absolute diff  */
     }
     *first = end;            /* return point number, NOT */
     *last  = start;          /* side number.             */
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     int  len[] = { 1, 2, 2, 1, 3, 2, 4, 1, 1, 2, 2, 3};
     int  n = sizeof(len)/sizeof(int);
     int  start, end, i;

     printf("\nPolygon Diameter Computation");
     printf("\n============================");
     printf("\n\nSide #     Length");
     printf(  "\n-----------------");
     for (i = 0; i < n; i++)
          printf("\n%5d%11d", i, len[i]);

     diameter(len, n, &start, &end);
     printf("\n\nDiameter is generated from point %d to %d", start, end);
}

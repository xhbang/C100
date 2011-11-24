/* ------------------------------------------------------ */
/* FUNCTION  find_rectangle :                             */
/*    Given a consecutive length of arcs of a circle, this*/
/* function determines if there exists a rectangle formed */
/* by these end points of arcs.                           */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/25/1989 */
/* ------------------------------------------------------ */

int  find_rectangle(int len[], int n)
{
     int  total;              /* total arc length         */
     int  half;               /* half = total/2           */
     int  sum;                /* running sum              */
     int  start;              /* running index #1         */
     int  end;                /* running index #2         */
     int  count;              /* counter of diametrical pt*/
     int  i;

     for (total = i = 0; i < n; i++)  /* compute total len*/
          total += len[i];
     half = total/2;           /* and its half            */

     count = start = end = 0;  /* initialization          */
     sum   = len[start];       /* running sum = 1st arc   */
     while (start < n - 1)         
          if (sum < half)      /* if shorter -> increase  */
               sum += len[++start];
          else if (sum > half) /* if longer -> decrease   */
               sum -= len[end++];
          else                 /* got one and inc.        */
               sum += len[++start], count++;
     return count;
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void main(void)
{
     int  x[] = { 1, 3, 1, 1, 4, 1, 2, 1, 2, 2, 2};
     int  n   = sizeof(x)/sizeof(int);
     int  y[] = { 2, 2, 2, 3, 3};
     int  m   = sizeof(y)/sizeof(int);
     int  z[] = { 10, 2, 2, 2, 2 };
     int  mn  = sizeof(z)/sizeof(int);
     int  i;

     printf("\nRectangle Finding Program");
     printf("\n=========================");
     printf("\n\nFirst Arc Length Set  :");
     for (i = 0; i < n; i++)
          printf("%3d", x[i]);
     printf("\nThere are %d pairs diametrical points.",
             find_rectangle(x, n));

     printf("\n\nSecond Arc Length Set :");
     for (i = 0; i < m; i++)
          printf("%3d", y[i]);
     printf("\nThere are %d pairs diametrical points.",
             find_rectangle(y, m));

     printf("\n\nThird  Arc Length Set :");
     for (i = 0; i < mn; i++)
          printf("%3d", z[i]);
     printf("\nThere are %d pairs diametrical points.",
             find_rectangle(z, mn));
}

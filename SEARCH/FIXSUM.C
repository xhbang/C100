/* ------------------------------------------------------ */
/* FUNCTION fix_sum :                                     */
/*    Given two int arrays x[] and y[], and an integer    */
/* given, this function checks to see if there is a pair  */
/* x[i] and y[j] such that x[i] + y[j] = given.           */
/*    Solution is extremly simple.  Sort one of the given */
/* array and do a sequence of binary searches.            */
/*    NOTE that this function needs quicksort() routines. */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/02/1989 */
/* ------------------------------------------------------ */

#define  YES   1
#define  NO    0

void  sort(int [], int);

int fix_sum(int x[], int y[], int m, int n, int given)
{
     int  first;
     int  last;
     int  middle;
     int  i;

     sort(x, m);              /* sort array x[]           */

     for (i = 0; i < n; i++)  /* for each y[j], do a bin. */
          for (first=0, last=m-1; first <= last; ) {
               middle = (first + last)/2;
               if (x[middle] + y[i] == given)
                    return YES;
               else if (x[middle] + y[i] > given)
                    last  = middle - 1;
               else
                    first = middle + 1;
          }
     return NO;
}


/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

void main(void)
{
     int  x[] = { 3, 7, 1, 2, 9, 4, 5};
     int  y[] = { 4, 2, 0, 3, 2, 7, 1, 9, 8};
     int  m   = sizeof(x)/sizeof(int);
     int  n   = sizeof(y)/sizeof(int);
     int  data, i;
     char line[100];

     printf("\nFixed Sum Search Program");
     printf("\n\nGiven Array #1 :");
     for (i = 0; i < m; i++)
          printf("%4d", x[i]);
     printf("\n\nGiven Array #2 :");
     for (i = 0; i < n; i++)
          printf("%4d", y[i]);

     printf("\n\nFixed Sum to be searched --> ");
     gets(line);
     data = atoi(line);

     if (fix_sum(x, y, m, n, data) == YES)
          printf("\nYES!, there is a pair summing up to %d", data);
     else
          printf("\nNO! no such sum exits");
}

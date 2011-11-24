/* ------------------------------------------------------ */
/* FUNCTION index_search :                                */
/*    Given a sorted (increasing) array, this function    */
/* determines if there exists an index i such that x[i]=i.*/
/* It could be solved by a linear scan, but a modified    */
/* binary search would be much more efficient.            */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/01/1989 */
/* ------------------------------------------------------ */

int  index_search(int x[], int n)
{
     int  first = 0;
     int  last  = n-1;
     int  middle, index;

     index = -1;
     while (first <= last) {  /* a modified binary search*/
          middle = (first + last) / 2;
          if (x[middle] == middle) {
               index = middle;
               break;
          }
          else if (x[middle] > middle)
               last = middle - 1;
          else 
               first = middle + 1;
     }
     return index;
}


/* ------------------------------------------------------ */

#include  <stdio.h>

void main(void)
{
     int  x[] = { -1, 0, 1, 3, 5, 7, 9, 10};
     int  n   = sizeof(x)/sizeof(int);
     int  answer, i;

     printf("\nIndex Search Program");
     printf("\n====================");
     printf("\n\nGiven Array :");
     for (i = 0; i < n; i++)
          printf("%5d", x[i]);

     answer = index_search(x, n);
     if (answer >= 0)
          printf("\n\nYES, x[%d] = %d has been found.", answer, answer);
     else
          printf("\n\nNO, there is no element with x[i] = i");
}

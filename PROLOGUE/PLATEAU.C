/* ------------------------------------------------------ */
/* FUNCTION longest_plateau :                             */
/*    Given a sorted (increasing) array, this function    */
/* computes the length of the longest plateau.  A plateau */
/* is a consective segment of an array with equal elements*/
/* For example, if x[] contains 1, 2, 3, 3, 4, 4, 5, 5, 5 */
/* and 6, then we have six plateaus, namely 1, 2, 3-3, 4-4*/
/* 5-5-5 and 6.  Therefore the length of the longest one  */
/* is 3.                                                  */
/*    This is the simplest program which I have ever seen.*/
/*                                                        */
/* Copyright Ching-Kuang Shene               June/30/1989 */
/* ------------------------------------------------------ */

int longest_plateau(int x[], int n)
{
     int  length = 1;         /* plateau length >= 1.     */
     int  i;

     for (i = 1; i < n; i++)
          if (x[i] == x[i-length])
               length++;
     return length;
}


/* ------------------------------------------------------ */

#include  <stdio.h>

void main(void)
{
     int  x[] = { 3, 4, 4, 7, 8, 9, 9, 9, 9, 10};
     int  n   = sizeof(x)/sizeof(int);
     int  i, longest_plateau(int [], int);

     printf("\nLongest Plateau Computation Program");
     printf("\n===================================");
     printf("\n\nThe Given Array :");
     for (i = 0; i < n; i++)
          printf("%5d", x[i]);
     printf("\n\nLength of the Longest Plateau is %d",
             longest_plateau(x, n));
}

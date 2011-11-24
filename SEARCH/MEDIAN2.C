/* ------------------------------------------------------ */
/* FUNCTION  median :                                     */
/*    Given two sorted arrays x[] and y[] with n items,   */
/* this function picks up the median of the merged array  */
/* by using a binary search in log(n) comparisons.        */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/14/1989 */
/* ------------------------------------------------------ */

void  sort(int [], int);

int  median(int x[], int y[], int n)
{
     int  first_X = 0;        /* lower element of x[]     */
     int  first_Y = 0;        /* lower element of y[]     */
     int  last_X  = n-1;      /* higher element of x[]    */
     int  last_Y  = n-1;      /* higher element of y[]    */
     int  count   = 0;        /* # of smaller items elim. */
     int  mid_X, mid_Y;       /* middle element pointers  */
     int  number;             /* # of elements left       */
     int  z[4];               /* working array            */

     while ((last_X - first_X > 1) || (last_Y - first_Y > 1)) {
          mid_X = (first_X + last_X)/2;  /* get mid ptrs  */
          mid_Y = (first_Y + last_Y)/2;
          if (x[mid_X] <= y[mid_Y]) {   
               count   += (mid_X - first_X); /* inc. count*/
               first_X =  mid_X; /* elim. lower half x[]  */
               last_Y  =  mid_Y; /* elim. higher half x[] */
          }
          else {
               count   += (mid_Y - first_Y);
               first_Y =  mid_Y; /* elim. lower half y[]  */
               last_X  =  mid_X; /* elim. higher half x[] */
          }
     }

     for (number = 0; first_X <= last_X; first_X++)
          z[number++] = x[first_X];  /* collect remainder */
     for ( ; first_Y <= last_Y; first_Y++)
          z[number++] = y[first_Y];

     sort(z, number);         /* sort them                */
     return z[n-count-1];     /* pick up appropriate item */
}

/* ------------------------------------------------------ */
/* FUNCTION  sort :                                       */
/*    Special routine to sort small arrays with 2, 3 and  */
/* 4 elements.                                            */
/* ------------------------------------------------------ */

#define  SWAP(x, y)  { temp = x; x = y; y = temp; }

void  sort(int z[], int n)
{
     int  temp;

     switch (n) {
          case 4 : if (z[0] >= z[3])  SWAP(z[0], z[3]);
                   if (z[1] >= z[3])  SWAP(z[1], z[3]);
                   if (z[2] >= z[3])  SWAP(z[2], z[3]);
          case 3 : if (z[0] >= z[2])  SWAP(z[0], z[2]);
                   if (z[1] >= z[2])  SWAP(z[1], z[2]);
          case 2 : if (z[0] >= z[1])  SWAP(z[0], z[1]);
     }
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     int  x[] = { 1, 3, 6,  7,  8,  9, 10};
     int  y[] = { 2, 4, 5, 11, 12, 13, 14};
     int  n   = sizeof(x)/sizeof(int);
     int  i;

     printf("\nMedian of Two Sorted Arrays");
     printf("\n===========================");
     printf("\n\nArray #1     Array #2");
     printf(  "\n--------     --------");
     for (i = 0; i < n; i++)
          printf("\n%6d%13d", x[i], y[i]);
     printf("\n\nMedian is %d", median(x, y, n));
}

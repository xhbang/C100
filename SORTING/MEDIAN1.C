/* ------------------------------------------------------ */
/* FUNCTION  median :                                     */
/*    Given an integer array, this function computes the  */
/* median of this array without sorting.  Note that the   */
/* median of an array of odd number of elements is the    */
/* middle element in sorted order.  But for an array with */
/* even number of elements, the median is the average of  */
/* the two elements in the middle of the array.  For      */
/* example, the median of {1,3,5,7,9} is 5, while the     */
/* median of {1, 3, 5, 7, 9, 11} is (5+7)/2=6.            */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/22/1989 */
/* ------------------------------------------------------ */

#define  ALWAYS   1

void  split(int [], int, int, int *);

int  median(int x[], int n)
{
     int  left  = 0;
     int  right = n - 1;
     int  mid   = (left + right)/2;
     int  split_point;

     while (ALWAYS) {         /* loop until we hit the mid*/
          split(x, left, right, &split_point); /* split   */
          if (split_point == mid)  /* is the spli pt. mid?*/
               break;         /* YES, found               */
          else if (split_point > mid) /* NO, larger than  */
               right = split_point - 1; /* use left part  */
          else                /* NO, smaller than         */
               left  = split_point + 1; /* use right part */
     }
     return (n & 0x01 != 0) ? x[mid] : (x[mid]+x[mid+1])/2;
}


/* ------------------------------------------------------ */
/* FUNCTION split :                                       */
/*    Given a section of an array, this function splits   */
/* this array in to two parts such that the all elements  */
/* of left part are less than some element while all      */
/* elements of the right part are greater than or equal to*/
/* the same element.  See quick sort for more detailed    */
/* information.                                           */
/* ------------------------------------------------------ */

#define  SWAP(x, y)  { int  t;  t = x; x = y; y = t; }

void  split(int x[], int left, int right, int *split_point)
{
     int  split_data = x[left];
     int  i;

     for (*split_point=left, i=left+1; i <= right; i++)
          if (x[i] < split_data) {
               (*split_point)++;
               SWAP(x[*split_point], x[i]);
          }
     SWAP(x[left], x[*split_point]);
}

/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE  20

void  main(void)
{
     int  x[MAXSIZE];
     int  n;
     int  i;
     char line[100];

     printf("\nMedian Finder Program");
     printf("\n=====================");
     printf("\n\nHow many data do you want to generate --> ");
     gets(line);
     n = atoi(line);

     srand((unsigned) clock());
     printf("\nData Array : ");
     for (i = 0; i < n; i++) {
          if (i % 10 == 0) printf("\n");
          x[i] = rand();
          printf("%6d", x[i]);
     }
     printf("\n\nThe median is %d", median(x, n));
}

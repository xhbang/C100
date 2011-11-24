/* ------------------------------------------------------ */
/* FUNCTION  longest increasing subsequence :             */
/*    Given an integer sequence of length n, this function*/
/* determines the longest increasing subsequence in nlogn */
/* stpes with a dynamic programming technique.            */
/* ------------------------------------------------------ */

#include  <stdlib.h>          /* for malloc() and free()  */

int longest_inc_sequence(int x[], int n)
{
     int  *last;              /* the last of a n-seubseq. */
     int  length;             /* current max inc. subseq. */
     int  left;               /* left bound for bin search*/
     int  right;              /* right bound              */
     int  mid;                /* the middle point.        */
     int  i;

     last = (int *) malloc(sizeof(int)*n); /* get work mem*/
     
     last[0] = x[0];          /* start from the beginning */
     length  = 0;             /* len=1 and x[0] in subseq */
     for (i = 1; i < n; i++)  /* scan all other items     */
          if (x[i] >= last[length]) /* higher than max?   */
               last[++length] = x[i]; /* YES, record it.  */
          else if (x[i] < last[0]) /* NO, less then 1st   */
               last[0] = x[i]; /* it would be the new head*/
          else {              /* now insert it with bin.sr*/
               for (left = 0, right = length; left != right-1; ) {
                    mid = (left + right) / 2;
                    (last[mid] <= x[i]) ? (left = mid) : (right = mid);
               }
               last[right] = x[i];
          }
     free(last);              /* finally release memory   */
     return length + 1;       /* return the true length   */
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void main(void)
{
     int  x[] = { 1, 3, 2, 1, 5, 7, 8, 6, 5, 9, 4, 10, 6 };
     int  n = sizeof(x)/sizeof(int);
     int  i;

     printf("\nLongest Increasing Sequence Program");
     printf("\n===================================\n");
     printf("\nGiven Array : ");
     for (i = 0; i < n; i++)
          printf("%4d", x[i]);
     printf("\n\nLength of L.I.S. is %d", longest_inc_sequence(x, n));
}

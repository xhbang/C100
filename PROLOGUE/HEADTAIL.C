/* ------------------------------------------------------ */
/* FUNCTION head_tail :                                   */
/*    Given an array with positive elements, this routine */
/* counts how many equal prefix and suffix sums there are */
/* Techniques employed here are all the same as the two   */
/* previous examples.                                     */
/*                                                        */
/* Copyright Ching-Kuang Shene               June/30/1989 */
/* ------------------------------------------------------ */

int  head_tail(int  x[], int n)
{
     int  prefix     = 0, suffix     = 0;
     int  prefix_idx = 0, suffix_idx = n-1;
     int  count = 0;

     while (suffix_idx >= 0 && prefix_idx <= n-1)
          if (prefix < suffix)      /* prefix too small   */
               prefix += x[prefix_idx++];
          else if (prefix > suffix) /* suffix too small   */
               suffix += x[suffix_idx--];
          else {                    /* get an equal pair: */
               count++;             /* increase count and */
               prefix += x[prefix_idx++]; /* advance pref.*/
               suffix += x[suffix_idx--]; /* and suffix   */
          }
     return count;
}


/* ------------------------------------------------------ */

#include  <stdio.h>

void main(void)
{
     int  x[] = { 3, 6, 2, 1, 4, 5, 2};
     int  n   = sizeof(x)/sizeof(int);
     int  i;

     printf("\nHead Sum == Tail Sum Counting Program");
     printf("\n=====================================\n");
     printf("\nGiven Array :");
     for (i = 0; i < n; i++)
          printf("%5d", x[i]);
     printf("\n\nThere are %d equal Prefix-Suffix sum pairs.",
                 head_tail(x, n));
}

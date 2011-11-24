/* ------------------------------------------------------ */
/* FUNCTION  sort :                                       */
/*    An improvement of the insertion sort algorithm by   */
/* using binary search and memmove() function. This is the*/
/* fastest version that we can do without further any data*/
/* structure technique. Note that it attands order  of    */
/* O(n log n) in the comparison based model.  But this    */
/* model is not powerful enough so that this sorting      */
/* algorithm is still very slow although IT IS OF O(nlogn)*/
/*                                                        */
/* Copyright Ching-Kuang Shene               June/27/1989 */
/* ------------------------------------------------------ */

#include  <string.h>

#define   YES    1
#define   NO     0

#define   SIZE   sizeof(int)/sizeof(char)

void  sort(int input[], int n)
{
     int  current, pos;
     int  low, high, mid;
     int  x;

     for (current = 1; current < n; current++) {
          x   = input[current];
          pos = -1;           /* pos=-1 means DON'T move  */
          if (x < input[0])   /* insert before head ?     */
               pos = 0;       /* YES, set pos to 0.       */
          else if (x <= input[current-1]) { /* bin search */
               low  = 0;      /* low index.               */
               high = current - 1;  /* high index         */
               while (high - low > 1) { /* stop?          */
                    mid = (low + high) / 2; /* the mid pt */
                    if (x >= input[mid]) 
                         low = mid;  /* try right         */
                    else
                         high = mid; /* try left          */
               }
               pos = low + 1;
          }
          if (pos >= 0) {     /* move a block             */
               memmove((void *) &input[pos+1], (void *) &input[pos], 
                       SIZE*(current-pos));
               input[pos] = x;
          }
     }
}

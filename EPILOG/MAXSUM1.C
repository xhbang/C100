/* ------------------------------------------------------ */
/* FUNCTION max_sum :                                     */
/*    Another slower solution of the max_sum problem with */
/* order O(n log(n)).  Not only it is slower, but also its*/
/* program is much longer.                                */
/*    Note the difference in the function head.  This one */
/* requires 'left', the left boundary pointer, and 'right'*/
/* the right boundary pointer.                            */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/01/1989 */
/* ------------------------------------------------------ */

#define  max(x, y)   ((x) >= (y) ? (x) : (y))

int  max_sum(int x[], int left, int right)
{
     int middle;              /* the middle element       */
     int max_to_left;         /* max found in [left,mid]  */
     int max_to_right;        /* max found in [mid+1,rig] */
     int max_crossing;        /* max found cross middle   */
     int sum;                 /* working variable         */
     int left_max;            /* left max from recursion  */
     int right_max;           /* right max from recursion */
     int result, i;

     if (left > right)        /* no element remains?      */
          result = 0;         /* result must be zero      */
     else if (left == right)  /* exactly one element?     */
          result = (x[left] > 0) ? x[left] : 0; /* ret max*/
     else {                   /* now we have many element */
          middle    = (left + right) / 2; /* get the mid. */
          left_max  = max_sum(x, left, middle); /* left   */
          right_max = max_sum(x, middle+1, right); /* rig.*/

          sum = 0;            /* compute max from mid down*/
          max_to_left = 0;
          for (i = middle; i >= left; i--) {
               sum += x[i];
               if (max_to_left < sum)
                    max_to_left = sum;
          }

          sum = 0;            /* compute max from mid+1 up*/
          max_to_right = 0;
          for (i = middle+1; i <= right; i++) {
               sum += x[i];
               if (max_to_right < sum)
                    max_to_right = sum;
          }

          max_crossing = max_to_left+max_to_right; /*cross*/
          if (max_crossing >= max_to_left) /* get the max */
               result = max(max_crossing, max_to_right);
          else
               result = max(max_to_left, max_to_right);
     }
     return result;
}


/* ------------------------------------------------------ */

#include  <stdio.h>

void main(void)
{
     int  x[] = { 2, -3, 1, -1, 3, -2, -3, 3};
     int  n   = sizeof(x)/sizeof(int);
     int  i;

     printf("\nMaximum Consecutive Elements Sum Program");
     printf("\n========================================");
     printf("\n\nGiven Array :");

     for (i = 0; i < n; i++)
          printf("%4d", x[i]);

     printf("\n\nMaximum Sum is %d", max_sum(x, 0, n-1));
}

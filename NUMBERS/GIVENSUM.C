/* ------------------------------------------------------ */
/* PROGRAM consecutive sum :                              */
/*    Given a positive integer, find all a's and b's such */
/* that the sum from a to b equals the given number.      */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/03/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

void main(void)
{
     long  left, right;       /* left and right bound     */
     long  sum;               /* computed sum             */
     long  GIVEN;             /* the given number         */
     int   count = 0;         /* solution counter         */
     char  line[100];         /* input buffer             */

     printf("\nConsecutive sum to a fixed given number");
     printf("\n=======================================\n");
     printf("\nYour number (> 0) please ---> ");
     gets(line);
     GIVEN = atol(line);

     for (sum = 0, right = 1; sum < GIVEN; sum += right, right++)
          ;

     for (left = 1, right--; left <= GIVEN/2; )
          if (sum > GIVEN)         /* if sum too large    */
               sum -= (left++);    /* reduce from left    */
          else {
               if (sum == GIVEN) { /* if equal, print it  */
                    printf("\n%ld = sum from %ld to %ld", 
                           GIVEN, left, right);
                    count++;       /* and increase count  */
               }                   /* if sum too small    */
               sum += (++right);   /* increase from right */
          }

     if (count > 0)
          printf("\n\nThere are %d solutions in total.", count);
     else
          printf("\n\nSorry, there is NO solution at all.");
}

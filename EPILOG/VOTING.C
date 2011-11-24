/* ------------------------------------------------------ */
/* FUNCTION majority :                                    */
/*    Given vote[] containing a voting record, say x[i]=j */
/* meaning that person i votes person j, this function    */
/* determine if there is any one is a majority.  There is */
/* no limit to the value of j.  In other words, anybody   */
/* can vote someone else and there is no fixed candidate. */
/* Thus value in x[] could be very large, or even larger  */
/* than the size of x[].  'Majority' means that there is  */
/* a guy such that more than n/2 persons votes for him.   */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/01/1989 */
/* ------------------------------------------------------ */

int majority(int vote[], int n)
{
     int  candidate;          /* current candidate        */
     int  vote_count;         /* vote count for the cand. */
     int  count;              /* final count              */
     int  answer;             /* final answer             */
     int  i;

     candidate  = vote[0];    /* assume the guy voted by  */
     vote_count = 1;          /* #1 is the candidate      */
     for (i = 1; i < n; i++)  /* for all other people ... */
          if (vote_count == 0) {  /* if current no count  */
               candidate  = vote[i]; /* pick up a new can.*/
               vote_count = 1; /* give him count 1        */
          }
          else if (candidate == vote[i]) /* is he a candi?*/
               vote_count++;  /* increase his count       */
          else
               vote_count--;  /* NO, decrease his count   */

     if (vote_count == 0)     /* finally check if the cand*/
          answer = 0;       /* is the guy with majority */
     else {
          for (i = 0, count = 0; i < n; i++)
               if (vote[i] == candidate)
                    count++;
          answer = (count > (int)(n / 2.0 + 0.5)) ? candidate : 0;
     }
     return answer;
}


/* ------------------------------------------------------ */

#include  <stdio.h>

void main(void)
{
     int  x[] = { 2, 2, 4, 2, 1, 2, 5, 2, 2, 8 };
     int  n = sizeof(x)/sizeof(int);
     int  answer, i;

     printf("\nMajority Counting Program");
     printf("\n=========================");
     printf("\n\n  No   Vote");
     printf(  "\n  --   ----");
     for (i = 0; i < n; i++)
          printf("\n%4d%6d", i, x[i]);

     answer = majority(x, n);

     printf("\n");
     if (answer > 0)
          printf("\nMajority is %d", answer);
     else
          printf("\nThere is no majority");
}

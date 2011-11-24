/* ------------------------------------------------------ */
/* FUNCTION  sink :                                       */
/*    Given a matrix containing who-knows-who information */
/* this function check the matrix to see if there exists  */
/* the sink, or the celebrity.                            */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/27/1989 */
/* ------------------------------------------------------ */

#define     YES          1
#define     NO           0
#define     NO_SINK     -1
#define     MAXSIZE    100

int sink(char know[MAXSIZE][MAXSIZE], int n)
{
     int  candidate;          /* possible candidate       */
     int  next;               /* working; points to next  */
     int  wrong;              /* a loop control variable  */
     int  the_sink;
     int  i, j, k;

     the_sink = NO_SINK;      /* suppose there is no sink */
     candidate = 0;           /* ask question from the 0th*/
     for (i = 1; i < n; i++)
          if (know[candidate][i]) candidate = i;

     for (wrong = NO, k = 0; (k < n) && !wrong; k++) {
          if (know[candidate][k]) /* cand. knows nobody   */
               wrong = YES;   /* so the cand. is wrong    */
          if (!know[k][candidate] && candidate != k)
               wrong = YES;   /* also wring if no one know*/
     }
     if (!wrong)
        the_sink = candidate;
     return the_sink;
}

/* ------------------------------------------------------ */

#include    <stdio.h>

void main(void)
{
     char  know[MAXSIZE][MAXSIZE] 
                      = { { NO,  NO, YES, YES, YES},
                          {YES,  NO, YES, YES, YES},
                          { NO, YES,  NO, YES,  NO},
                          { NO,  NO,  NO,  NO,  NO},
                          {YES,  NO, YES, YES, YES}};
     int   n = 5;
     int   answer, i, j;

     printf("\nSink Finding Program");
     printf("\n====================");
     printf("\n\nGiven know[*,*] Matrix:\n");
     for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
           printf(" %s", know[i][j] ? " Y" : " N");
        printf("\n");
     }
     answer = sink(know, n);
     if (answer >=0)
          printf("\n\nThe sink is %d", answer + 1);
     else
          printf("\n\nNO!, there is no sink");
}

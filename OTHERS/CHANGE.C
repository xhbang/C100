/* ------------------------------------------------------ */
/* PROGRAM change :                                       */
/*    Given a set of based value base[0],...,base[k] and  */
/* and input number, this program finds a representation  */
/* of the input number with base values such that the     */
/* number of base values used are at minimum.             */
/*    This program employs the dynamic programming tech.  */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/08/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE   100
#define   min(a,b)  ((a) <= (b) ? (a) : (b))

void  main(void)
{
     int  money[MAXSIZE+1];
     int  base[] = { 1, 3, 4 };
     int  k      = sizeof(base)/sizeof(int);
     int  n;
     int  i, j, MIN;
     char line[100];

     printf("\nMinimum Money Change Program");
     printf("\n============================");
     printf("\n\nBase Values : ");
     for (i = 0; i < k; i++)
          printf("%d ", base[i]);
     printf("\n\nYour input please --> ");
     gets(line);
     n = atoi(line);

     money[0] = 0;            /* money[0] can not be used*/
     money[1] = 1;            /* money[1] is the basic   */
     for (i = 2; i <= n; i++) { /* for 2 dollars to n... */
          MIN = n;            /* find the minimum # by   */
          for (j = 0; j < k; j++) /* looking back.       */
               if (i >= base[j])
                    MIN = min(money[i-base[j]]+1, MIN);
          money[i] = MIN;      /* min. computed for i    */
     }
     printf("\n\nMinimum = %d", money[n]);
}

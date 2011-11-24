/* ------------------------------------------------------ */
/* FUNCTION cnr :                                         */
/*    Given unsigned integers n and r, this function      */
/* computes C(n,r), the Binomial Coefficient of n and r   */
/* by using addition operation only.  The method used     */
/* calculates C(n,r) with exactly (n-1)*(r-1) additions   */
/* and this is fewer than many known techniques.          */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/13/1989 */
/* ------------------------------------------------------ */

#define  MAXSIZE  100

unsigned long cnr(int n, int r)
{
     unsigned long c[MAXSIZE];
     int           i, j;

     for (i = 0; i <= r; i++) /* initial c[] to all 1's   */
          c[i] = 1UL;

     for (i = 1; i <= n-r; i++) /* compute C(n,r) by add. */
          for (j = 1; j <= r; j++) /* but compute only    */
               c[j] += c[j-1];  /* those needed.          */
     return c[r];
}


/* ------------------------------------------------------ */

#include  <stdio.h>

unsigned long  cnr(int, int);

void main(void)
{
     int      n, r;
     char     line[100];

     printf("\nCombinatorial Coefficient by Addition");
     printf("\n=====================================");
     printf("\n\nN ---> ");
     gets(line);
     n = atoi(line);
     printf(    "R ---> ");
     gets(line);
     r = atoi(line);

     printf("\nC(%d,%d) = %lu", n, r, cnr(n,r));
}

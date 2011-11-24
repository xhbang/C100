/* ------------------------------------------------------ */
/* PROGRAM factorization of positive integers :           */
/*    Given un unsigned long integer, this program finds  */
/* all prime factor by using traditional division method. */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/10/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE  100
#define   SAVE_FACTOR(fact, exp) { if (exp > 0)                \
                                        factors[count] = fact, \
                                        exps[count++]  = i;    \
                                 }

void main(void)
{
     unsigned long  factors[MAXSIZE]; /* stores factors   */
     unsigned long  exps[MAXSIZE];    /* stores exps      */
     unsigned long  n, work;
     int            count = 0;        /* factor counter   */
     int            i, k;
     char           line[100], *dummy;

     printf("\nFactorization by Division Program");
     printf("\n=================================");
     printf("\n\nInput a positive integer --> ");
     gets(line);
     n = strtoul(line, &dummy, 10);

     for (i=0,work=n; (work & 0x01UL)==0 && work>1; work>>=1,i++)
          ;                   /* extract divisor 2        */
     SAVE_FACTOR(2, i);       /* save it and its exp.     */

     for (k = 3; k <= work; k += 2) { /* for k=3,5,7,9,.. */
          for (i = 0; work % k == 0 && work > 1; work /= k, i++)
               ;              /* extract divisor k        */
          SAVE_FACTOR(k, i);  /* save it and its exp.     */
     }

     printf("\n%ld = ", n);   /* display result.          */
     for (i = 0; i < count; i++)
          printf("%ld(%ld)", factors[i], exps[i]);
}

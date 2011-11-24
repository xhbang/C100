/* ------------------------------------------------------ */
/* FUNCTION sieve :                                       */
/*    This program uses Eratosthenes Sieve method to      */
/* generate all primes between 2 and MAXSIZE*2+3.  This   */
/* is a very simple yet elegant method to generate primes */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/01/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>

#define   MAXSIZE   200
#define   DELETED     1
#define   KEPT        0

void main(void)
{
     int  sieve[MAXSIZE+1];   /* the sieve array          */
     int  count = 1;          /* no. of primes counter    */
     int  prime;              /* a generated prime        */
     int  i, k;               /* working variable         */

     printf("\nEratosthenes Sieve Method");
     printf("\n=========================");
     printf("\n\nPrime Numbers between 2 and %d\n", MAXSIZE*2+3);

     for (i = 0; i <= MAXSIZE; i++) /* set all items to be*/
          sieve[i] = KEPT;    /* kept in the sieve        */

     for (i = 0; i <= MAXSIZE; i++) /* for each i, it     */
          if (sieve[i] == KEPT) {   /* corresponds to 2i+3*/
               prime = i + i + 3;   /* if it is not sieved*/
               count++;             /* prime=2i+3.        */
               for (k = prime + i; k <= MAXSIZE; k += prime)
                    sieve[k] = DELETED; /* screen multiple*/
          }

     printf("\n%6d", 2);      /* output part.             */
     for (i = 0, k = 2; i <= MAXSIZE; i++)
          if (sieve[i] == KEPT) {
               if (k > 10) {
                    printf("\n");
                    k = 1;
               }
               printf("%6d", 2*i+3);
               k++;
          }
     printf("\n\nThere are %d primes in total.", count);
}

/* ------------------------------------------------------ */
/* PROGRAM prime number generator :                       */
/*    This program generates first MAXSIZE-1 primes by    */
/* using the conventional division method, but multiples  */
/* of 2 and 3 are not tested.  Therefore it is faster.    */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/02/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>

#define   MAXSIZE    100
#define   YES          1
#define   NO           0

void main(void)
{
     int  prime[MAXSIZE];     /* array to contains primes */
     int  gap = 2;            /* increasing gap = 2 and 4 */
     int  count = 3;          /* no. of primes            */
     int  may_be_prime = 5;   /* working  variable        */
     int  i, is_prime;

     prime[0] = 2;            /* Note that 2, 3 and 5 are */
     prime[1] = 3;            /* primes.                  */
     prime[2] = 5;
     while (count < MAXSIZE)  { /* loop until prime[] full*/
          may_be_prime += gap;  /* get next number        */
          gap           = 6 - gap; /* switch to next gap  */
          is_prime      = YES;  /* suppose it were a prime*/
          for (i = 2; prime[i]*prime[i] <= may_be_prime && is_prime; i++)
               if (may_be_prime % prime[i] == 0) /* NO    */
                    is_prime = NO; /* exit                */
          if (is_prime)       /* if it IS a prime...      */
               prime[count++] = may_be_prime;  /* save it */
     }

     printf("\nPrime Number Generation Program");
     printf("\n===============================\n");
     printf("\nFirst %d Prime Numbers are :\n", count);
     for (i = 0; i < count; i++) {
          if (i % 10 == 0) printf("\n");
          printf("%5d", prime[i]);
     }
}

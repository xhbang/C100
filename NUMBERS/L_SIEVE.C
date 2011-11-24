/* ------------------------------------------------------ */
/* PROGRAM linear sieve program of Gries and Misra :      */
/*    This program finds all prime numbers between 2 and  */
/* n, the input, by using Gries and Misra linear sieve    */
/* method.  This method does not use division, instead    */
/* multiplications are used.                              */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/10/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE    1000
#define   NEXT(x)    x = next[x]
#define   REMOVE(x)  { next[previous[x]] = next[x];          \
                       previous[next[x]] = previous[x];      \
                     }
#define   INITIAL(n) { unsigned long i;                      \
                       for (i = 2; i <= n; i++)              \
                            previous[i] = i-1, next[i] = i+1;\
                       previous[2] = next[n] = NULL;         \
                     }

void main(void)
{
     unsigned long  previous[MAXSIZE+1]; /* prev. pointer */
     unsigned long  next[MAXSIZE+1];     /* next pointer  */
     unsigned long  prime, fact, i, mult;
     unsigned long  n;
     unsigned long  count = 0;
     char           line[100], dummy;

     printf("\nLinear Sieve Program");
     printf("\n====================");
     printf("\n\nPrime Numbers between 2 to --> ");
     gets(line);
     n = strtoul(line, &dummy, 10);
  
     INITIAL(n);              /* initial the set          */
     for (prime = 2; prime*prime <= n; NEXT(prime))
          for (fact = prime; prime*fact <= n; NEXT(fact))
               for (mult = prime*fact; mult <= n; mult *= prime)
                    REMOVE(mult); /* remove multiples     */

     for (i = 2; i != NULL; NEXT(i)) { /* display result  */
          if (count % 8 == 0)  printf("\n");
          printf("%6ld", i);
          count++;
     }
     printf("\n\nThere are %ld Prime Numbers in Total", count);
}

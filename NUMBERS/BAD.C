#include  <stdio.h>
#include  <math.h>            /* for sqrt() */

#define   MAXSIZE    100
#define   YES          1
#define   NO           0

void main(void)
{
     int    prime[MAXSIZE];
     int    count = 1;     
     int    i, j, is_prime;
     double sqrt_i;

     prime[0] = 2;
     for (i = 3; i < MAXSIZE; i++) {
          is_prime = YES;
          sqrt_i   = sqrt((double) i);
          for (j = 0; prime[j] <= sqrt_i && is_prime; j++)
               if (i % prime[j] == 0)
                    is_prime = NO;
          if (is_prime)
               prime[count++] = i;
     }

     printf("\nPrime Numbers between 1 and %d are\n", MAXSIZE);
     for (i = 0; i < count; i++) {
          if (i % 10 == 0) printf("\n");
          printf("%5d", prime[i]);
     }
     printf("\n\nThere are %d Prime Numbers in total", count);
}

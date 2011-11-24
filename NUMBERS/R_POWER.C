/* ------------------------------------------------------ */
/* FUNCTION recursive_power :                             */
/*    Given two unsigned long data, m and n, this routine */
/* computes m^n with recursive technique so that number   */
/* of multiplications can be reduced to O(log(n)) instead */
/* of O(n).  Here we require m and n be positive integers */
/* but it is a easy matter to extend it to all integers.  */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/01/1989 */
/* ------------------------------------------------------ */

unsigned long  recursive_power(unsigned long m, unsigned long n)
{
     unsigned long temp;

     if (n == 0)              /* m^0 = 1                  */
          return 1;
     else if (n & 0x01UL == 0) { /* if power is even then */
          temp = recursive_power(m, n >> 1); 
          return temp * temp; /* m^(2k) = (m^k)^2         */
     }
     else                     /* otherwise, m^n=m*m^(n-1) */
          return m * recursive_power(m, n-1);
}


/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>          /* for strtoul() function   */

void main(void)
{
     char  line[100], *dummy_ptr;
     unsigned long m, n;

     printf("\nM^N Computation (M > 0 and N > 0)\n");
     printf("\nM   = ");
     gets(line);
     m = strtoul(line, &dummy_ptr, 10);
     printf("\nN   = ");
     gets(line);
     n = strtoul(line, &dummy_ptr, 10);
     printf("\n\nM^N = %lu", recursive_power(m, n));
}

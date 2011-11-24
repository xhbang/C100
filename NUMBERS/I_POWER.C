/* ------------------------------------------------------ */
/* FUNCTION iterative_power :                             */
/*    Given two unsigned long data, m and n, this routine */
/* computes m^n with iterative technique and the number   */
/* of multiplications is still of order O(log(n)) but     */
/* recursion is no more required.                         */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/02/1989 */
/* ------------------------------------------------------ */

unsigned long iterative_power(unsigned long m, unsigned long n)
{
     unsigned long  temp = 1;

     while (n > 0) {          /* if there exists 1 bits.. */
          if (n & 0x01UL == 1)/* the right most one ?     */
               temp *= m;     /* YES, the result get a 'm'*/
          m *= m;             /* anyway, compute m^k      */
          n >>= 1;            /* throw away this bit      */
     }
     return temp;
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
     printf("\n\nM^N = %lu", iterative_power(m, n));
}

/* -------------------------------------------------------- */
/* FUNCTION  factorial :                                    */
/*    This function uses a divide-and-conquer method to     */
/* compute n!, but employs the bit manipulation technique   */
/* calculate C(n,n/2).  Thus this still maintain O(logN)    */
/* feature, but because there are O(logN) steps in          */
/* decomposing n! the actual complexity is therefore        */
/* O((logN)^2).                                             */
/*                                                          */
/* Copyright Ching-Kuang SHENE                  Feb/25/1989 */
/* -------------------------------------------------------- */

unsigned long  cn2(unsigned long);

unsigned long  factorial(unsigned long n)
{
     unsigned long  temp;

     if (n == 1)                   /* if n = 1, n! = 1      */
          return 1;
     else if (n & 0x01UL == 1)     /* if n odd, n!=n*(n-1)! */
          return n * factorial(n - 1);
     else {
          temp = factorial(n >> 1);/* if n even, use C(*,*) */
          return cn2(n) * temp * temp;  /* blend up.        */
     }
}


/* --------------------------------------------------------- */
/* FUNCTION cn2 :                                            */
/*    This function is adopted from a special routine using  */
/* bit manipulation technique to compute C(n,r).  See notes  */
/* therein please.                                           */
/* --------------------------------------------------------- */

unsigned long  power(unsigned long, unsigned long);

unsigned long  cn2(unsigned long n)
{
     unsigned long  x    = (1 << n) + 1;  /* 2^n + 1         */
     unsigned long  mask = (1 << n) - 1;  /* 2^n - 1, n 1's  */

     return (power(x, n) >> ((n >> 1)*n)) & mask;
}

/* ------------------------------------------------------ */
/* FUNCTION power :                                       */
/*    Given two unsigned long data, m and n, this routine */
/* computes m^n with iterative technique and the number   */
/* of multiplications is still of order O(log(n)) but     */
/* recursion is no more required.                         */
/* ------------------------------------------------------ */

unsigned long power(unsigned long m, unsigned long n)
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

     printf("\nFast (but NOT THE FASTEST) N! Computation :");
     printf("\n\nN for N! please --> ");
     gets(line);
     n = strtoul(line, &dummy_ptr, 10);
     printf("\n%lu! = %lu", n, factorial(n));
}

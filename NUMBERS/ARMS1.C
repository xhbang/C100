/* ------------------------------------------------------ */
/* PROGRAM Armstrong Number Search :                      */
/*    This program searches all 3-digit Armstrong Numbers */
/* and thus numbers in the range of 0-99 are not counted. */
/*                                                        */
/* Copyright Ching-Kuang Shene               June/29/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <time.h>

void main(void)
{
     int  p, q, r;            /* three digits             */
     int  number;
     int  count = 0;

     printf("\nArmstrong Number Search");
     printf("\n=======================");
     printf("\n\nCount  Number");
     printf(  "\n-----  ------");

     for (number = 100; number <= 999; number++) {
          p = number/100;      /* extract left most digit  */
          q = (number%100)/10; /* the middle digit         */
          r = number%10;       /* the right most one       */
          if (p*p*p+q*q*q+r*r*r == number) /* Armstrong # ?*/
               printf("\n%3d%9d", ++count, number);
     }
     printf("\n\nThere are %d 3-digit Armstrong Numbers.", count);
}

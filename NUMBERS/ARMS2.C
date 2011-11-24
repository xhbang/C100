/* ------------------------------------------------------ */
/* PROGRAM Armstrong Number Search :                      */
/*    This program searches all 3-digit Armstrong Numbers */
/* and thus numbers in the range of 0-99 are not counted. */
/*                                                        */
/* Copyright Ching-Kuang Shene               June/29/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>

void main(void)
{
     int  p, q, r;            /* three digits             */
     int  p_cube, q_cube, r_cube; /* their cubes          */
     int  p100, q10;          /* their position values    */
     int  number;             /* the computed number      */
     int  cube_sum;           /* the sum of the cubes     */
     int  count = 0;          /* counter                  */

     printf("\nArmstrong Number Search");
     printf("\n=======================");
     printf("\n\nCount  Number");
     printf(  "\n-----  ------");

     for (p = 1, p100 = 100; p <= 9; p++, p100+=100) {
          p_cube = p*p*p;
          for (q = q10 = 0; q <= 9; q++, q10+=10) {
               q_cube = q*q*q;
               for (r = 0; r <= 9; r++) {
                    r_cube   = r*r*r;
                    number   = p100 + q10 + r;
                    cube_sum = p_cube + q_cube + r_cube;
                    if (number == cube_sum) 
                         printf("\n%3d%9d", ++count, number);
               }
          }
     }
     printf("\n\nThere are %d 3-digit Armstrong Numbers.", count);
}

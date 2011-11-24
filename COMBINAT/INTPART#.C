/* ------------------------------------------------------ */
/* FUNCTION  int_part_no :                                */
/*    Given an integer n, this function computes the      */
/* number of partitions of the input integer.  NOTE that  */
/* this function computes the number only and does not    */
/* generate the corresponding partition.  For the second  */
/* purpose, see program INTPART.C please.                 */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/23/1989 */
/* ------------------------------------------------------ */

unsigned long  compute(int, int);
unsigned long  int_part_no(int);

unsigned long  int_part_no(int n)
{
     return compute(n, n);    /* convert to another form */
}

/* ----------------------------------------------------- */
/* FUNCTION  compute :                                   */
/*    The computation routine.  It accepts number-the    */
/* number to be partitioned, and maximum-the maximum     */
/* value in any partition of number, then returns the    */
/* number of partitions subject to number and maximum.   */
/* ----------------------------------------------------- */

unsigned long  compute(int number, int maximum)
{
     if (number == 1 || maximum == 1)
          return 1;
     else if (number < maximum)
          return compute(number, number);
     else if (number == maximum)
          return 1 + compute(number, maximum-1);
     else
          return compute(number,maximum-1) + 
                 compute(number-maximum,maximum);
}

/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

void  main(void)
{
     int  n;
     char line[100];

     printf("\nNumber of partitions of an Integer");
     printf("\n==================================");
     printf("\n\nN --> ");
     gets(line);
     n = atoi(line);
     printf("\nThere are %lu partitions.", int_part_no(n));
}

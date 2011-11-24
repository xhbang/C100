/* ------------------------------------------------------ */
/* PROGRAM Buffon Needle Problem :                        */
/*    This is the simulation program for Buffon Needle    */
/* problem.  It generates pairs of (x,theta), where x is  */
/* is distance from a point to the lower parallel line    */
/* while theta is the angle between the lower parallel    */
/* line and the needle.  From this we can determine if the*/
/* needle crosses any parallel line.  Suppose we repeat   */
/* this procedure enough time, (# of crossing/# of points)*/
/* is an approximate of the true probability, namely 2/pi */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/10/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>            /* for sin()                */
#include  <time.h>            /* for clock()              */

void main(void)
{
     unsigned seed = (unsigned) clock(); /* the seed      */
     int      i, count = 0;
     int      n;
     double   pi = acos(-1.0);/* the number pi = 3.414..  */
     double   x, theta, dist; /* the needle's length      */
     double   length = 1.0;
     char     line[100];

     printf("\nBuffon Needle Program by Simulation");
     printf("\n===================================");
     printf("\n\nNumber of Simulation Points --> ");
     gets(line);
     n = atoi(line);

     srand(seed);
     for (i = 1; i <= n; i++) {
          x     = (double) rand() / RAND_MAX;
          theta = ((double) rand() / RAND_MAX) * 2.0 * pi;
          dist  = x + length * sin(theta);
          if (0. < dist && dist < length)
               count++;
     }
     printf("\n\nCrossing Probability --> %.2f", 
                 1.0 - (double) count/n);
     printf(  "\nTrue Probability ------> %.2f", 2.0/pi);
}

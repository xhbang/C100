/* ------------------------------------------------------ */
/* FUNCTION  turns :                                      */
/*    Given a sequence of points on the plane and a robot */
/* at the first point facing the X-axi direction, this    */
/* function determines the number of counter-clock turns  */
/* along the tour of all points.  The tour starts from the*/
/* first point.  At any point, the robot makes a counter- */
/* clock-wise turn in order to face the next point.  After*/
/* a turn, it proceeds to next point.  The final position */
/* is the first point facing the X-axi.                   */
/*                                                        */
/* Copyright Ching-Kuang Shene               Sept/01/1989 */
/* ------------------------------------------------------ */

int  turns(int x[], int y[], int n)
{
     int  X     = 1;          /* robot's previous direct X*/
     int  Y     = 0;          /* robot's previous direct Y*/
     int  TURNS = 0;          /* # of 90 turns to 1st Q.  */
     int  count;              /* # of complete 360 turns  */
     int  new_x;              /* ronot's next direct. X   */
     int  new_y;              /* robot's next direct. Y   */
     int  new_turns;          /* # of 90 turns to 1st Q.  */
     int  i, temp;            /* working                  */

     for (count = i = 0; i <= n; i++) { /* scan all points*/
          new_x     = x[(i+1) % n] - x[i % n]; /* new dir.*/
          new_y     = y[(i+1) % n] - y[i % n];
          new_turns = 0;      /* assume no 90 turn.       */
          while (new_x <= 0 || new_y < 0) { /* turn it to */
               temp  = new_x; /* first quartant           */
               new_x = new_y;
               new_y = -temp;
               new_turns++;
          }
          if (TURNS > new_turns || (TURNS == new_turns && Y*new_x > new_y*X))
               count++;       /* crossing X-axi, inc ocunt*/
          X     = new_x;      /* proceed to next point    */
          Y     = new_y;
          TURNS = new_turns;
     }
     return count;            /* return # of 360 turns    */
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     int  x[] = { 0, 5, 7, 5, 8, 1, 4, 6, 2, 0 };
     int  y[] = { 0, 1, 5, 6, 7, 7, 5, 2, 4, 3 };
     int  n = sizeof(x)/sizeof(int);
     int  i;

     printf("\nNumber of 360 turns along a route");
     printf("\n=================================");
     printf("\n\nPoint#    x      y");
     printf(  "\n------------------");
     for (i = 0; i < n; i++)
          printf("\n%5d%6d%7d", i+1, x[i], y[i]);

     printf("\n\nThere are %d complete 360 turns", turns(x, y, n));
}

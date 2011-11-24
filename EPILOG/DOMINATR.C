/* ------------------------------------------------------ */
/* FUNCTION nearest_dominator :                           */
/*    Given an array, this function computes the right    */
/* nearest dominator of each element in the array.  A     */
/* right dominator of x[i] is any element x[j] with j > i */
/* and x[i] <= x[j].  The right nearest dominator is the  */
/* right dominator with smallest index.  You can define   */
/* the left nearest dominator in a similar way.           */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/01/1989 */
/* ------------------------------------------------------ */

#define   STACK_SIZE    100
#define   YES             1
#define   NO              0


void nearest_dominator(int x[], int dom[], int n)
{
     int  stack[STACK_SIZE];  /* the working stack        */
     int  top;                /* the stack pointer        */
     int  i;                  /* working variables        */

     for (i = 0; i < n; i++)  /* clear dominator array    */
          dom[i] = -1;        /* -1 means no dominator    */
     
     top        = 0;          /* stack initialization     */
     stack[top] = 0;
     for (i = 1; i < n; i++) { /* for each element :      */
          while (top >= 0 && x[stack[top]] <= x[i])
               dom[stack[top--]] = i;
          stack[++top] = i;   /* push i into stack        */
     }
}


/* ------------------------------------------------------ */

#include  <stdio.h>

void main(void)
{
     int  x[] = { 6, 1, 4, 3, 6, 2, 4, 7, 3, 5};
     int  n   = sizeof(x)/sizeof(int);
     int  dom[sizeof(x)/sizeof(int)];
     int  i;

     printf("\nRight Nearest Dominator Program");
     printf("\n===============================\n");
     printf("\n             Dominator   Dominator");
     printf("\n  #   Data      Loc        Value  ");
     printf("\n --   ----   ---------   ---------");

     nearest_dominator(x, dom, n);

     for (i = 0; i < n; i++) {
          printf("\n%3d%6d", i, x[i]);
          if (dom[i] >= 0)
               printf("%10d%12d", dom[i], x[dom[i]]);
          else
               printf("        --          --");
     }
}

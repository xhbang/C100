/* ------------------------------------------------------ */
/* PROGRAM All Possible Subset by Lexical Order :         */
/*    This program generates all subsets by lexical order.*/
/*                                                        */
/* Copyright Ching-Kuang Shene               July/05/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE      20
#define   LOOP          1

void main(void)
{
     int  set[MAXSIZE];
     int  n, i;
     int  position;
     char line[100];

     printf("\nAll Possible Subsets Generation by Lexical Order");
     printf("\n================================================");
     printf("\n\nNumber of Elements in the Set --> ");
     gets(line);
     n = atoi(line);

     printf("\n{}");          /* the empty set            */
     position      = 0;       /* start from the 1st pos.  */
     set[position] = 1;       /* it gets a '1'            */
     while (LOOP) {           /* loop until done...       */
          printf("\n{%d", set[0]);  /* print one result   */
          for (i = 1; i <= position; i++)
               printf(",%d", set[i]);
          printf("}");

          if (set[position] < n) { /* this pos. can be inc*/
               set[position+1] = set[position] + 1; /* YES*/
               position++;    /* inc. next pos.           */
          }
          else if (position != 0)  /* NO, the 1st pos?    */
               set[--position]++;  /* backup and increase */
          else                /* NO, the 1st pos and can  */
               break;         /* not be inc. JOB DONE!    */
     }
}

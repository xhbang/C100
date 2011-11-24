/* ------------------------------------------------------ */
/* FUNCTION  h-sequence :                                 */
/*    The recursive h-sequence recognition function. It   */
/* employs a recursive decent technique.                  */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/12/1989 */
/* ------------------------------------------------------ */

#include  <string.h>          /* for strlen()             */

#define   YES     1
#define   NO      0
int  h_seq(char []);          /* function prototype       */
int  cursor;                  /* the working cursor       */

/* ------------------------------------------------------ */
/* FUNCTION  h_sequence :                                 */
/*    The control routine.                                */
/* ------------------------------------------------------ */

int  h_sequence(char x[])
{
     int  length = strlen(x);

     cursor = 0;              /* set working cursor to 0  */
     if (h_seq(x) == YES)     /* does it recognize prefix?*/
          if (cursor == length - 1) /* YES, length exhaust*/
               return YES;    /* YES, a h-sequence.....   */
     return NO;               /* NO.                      */
}

/* ------------------------------------------------------ */
/* FUNCTION  h_seq :                                      */
/*    The working routine by using recursive decent       */
/* parsing technique.                                     */
/* ------------------------------------------------------ */

int  h_seq(char x[])
{
     switch (x[cursor]) {     /* for the current char.    */
          case '0' : return YES;  /* a '0' is a h-seq.    */
          case '1' : cursor++;    /* a '1' has to be      */
                     if (h_seq(x) == YES) { /* followed by*/
                          cursor++;         /* two h-seq's*/
                          if (h_seq(x) == YES)
                               return YES;
                     }
                     return NO;
          default  : return NO;
     }
}


/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     char  line[100];
     int   done;

     printf("\nH-Sequence Testing Program (Recursive Version)");
     printf("\n==============================================");
     
     for (done = NO; !done; ) {
          printf("\n\nInput a string of 0 and 1 --> ");
          if (gets(line) != NULL)
               if (h_sequence(line) == YES)
                    printf("\n*** Input is a H sequence ***");
               else
                    printf("\n*** Input is NOT a H sequence ***");
          else
               done = YES;
     }
}

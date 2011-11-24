/* ------------------------------------------------------ */
/* FUNCTION  h_sequence :                                 */
/*    A h-sequence is defined as follows :                */
/*       <h-seq> -> 0                                     */
/*       <h-seq> -> 1 <h-seq> <h-seq>                     */
/* This function accepts a sequence consisting of 0's and */
/* 1's, then check to see if it is a h-sequence of not    */
/* by using iterative technique.                          */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/12/1989 */
/* ------------------------------------------------------ */

#include  <string.h>          /* for strlen()             */

#define   YES     1
#define   NO      0

int  h_sequence(char x[])
{
     int  length = strlen(x);
     int  count;              /* counting for # of h-seq  */
     int  i;

     for (count = 1, i = 0; count != 0 && i < length; i++)
          switch (x[i]) {
               case '0' : count--; /* a '0' means one less*/
                          break;
               case '1' : count++; /* a '1' starts a new  */
                          break;
               default  : return NO;
          }
     return count == 0 && i >= length;
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     char  line[100];
     int   done;

     printf("\nH-Sequence Testing Program (Iterative Version)");
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
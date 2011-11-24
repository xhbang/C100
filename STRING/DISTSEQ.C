/* ------------------------------------------------------ */
/* FUNCTION  seq_gen :                                    */
/*    Given an input 'n', this function generates all 3   */
/* letter sequence of length n with no repeating neighbor */
/* substring.  This function is programed with backtrack  */
/* technique and the check() function is NOT the fastest. */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/12/1989 */
/* ------------------------------------------------------ */

#define   OK      1
#define   NO      0

/* ------------------------------------------------------ */
/*                  function prototypes                   */
/* ------------------------------------------------------ */

void  change(int [], int *);
void  extend(int [], int *);
int   check(int [], int);
void  output(int [], int);

/* ------------------------------------------------------ */
/* FUNCTION  seq_gen :                                    */
/*    The given input is 'n' and seq[] array is the array */
/* to store generated sequence.                           */
/* ------------------------------------------------------ */

void  seq_gen(int seq[], int n)
{
     int  no;
     int  i;

     seq[0] = 1;              /* two initial digits       */
     seq[1] = 2;
     no     = 1;              /* last index in seq[]      */
     while (no >= 0)          /* if still have chance.... */
          if (check(seq, no) == OK)   /* is this seq OK ? */
               if (no == n-1) {       /* Full ?           */
                    output(seq, n);   /* YES, show it     */
                    change(seq, &no); /* backtrack...     */
               }
               else
                    extend(seq, &no); /* OR, extend it    */
          else
               change(seq, &no);      /* NOT OK, backtrack*/
}

/* ------------------------------------------------------ */
/* FUNCTION  change :                                     */
/*    Given a sequence seq[] and the last index of it, no,*/
/* this function finds the last digit such that has a     */
/* chance that could be increased.                        */
/* ------------------------------------------------------ */

void  change(int seq[], int *no)
{
     for ( ; seq[*no] == 3; (*no)--)
          ;
     seq[*no]++;
}

/* ------------------------------------------------------ */
/* FUNCTION  extend :                                     */
/*    Put a '1' into the position next to the last.       */
/* ------------------------------------------------------ */

void  extend(int seq[], int *no)
{
     seq[++(*no)] = 1;
}

/* ------------------------------------------------------ */
/* FUNCTION  check :                                      */
/*    This function checks to see if the sequence has a   */
/* consecutive duplicated substring.                      */
/* ------------------------------------------------------ */

int  check(int seq[], int no)
{
     int  length;
     int  half = (no + 1)/2;
     int  i;

     for (length = 1; length <= half; length++) {
          for (i = 0; i<length && seq[no-i]==seq[no-length-i]; i++)
               ;
          if (i >= length)
               return NO;
     }
     return OK;
}

/* ------------------------------------------------------ */
/* FUNCTION  output :                                     */
/*    Function to display the generated sequence.         */
/* ------------------------------------------------------ */

void  output(int seq[], int n)
{
     int  i;

     printf("\n");
     for (i = 0; i < n; i++)
          printf("%d", seq[i]);
}

/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

void  main(void)
{
     int  seq[10];
     int  n;
     int  i;
     char line[100];

     printf("\nNon-Repeated Sequence of Three Chars. Generator");
     printf("\n===============================================");
     printf("\n\nSequence Length Please --> ");
     gets(line);
     n = atoi(line);
     printf("\nGenerated Sequence is shown below :\n");
     seq_gen(seq, n);
}

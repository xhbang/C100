/* ------------------------------------------------------ */
/* FUNCTION BM :                                          */
/*    The Boyer-Moore String Searching Program.  Given a  */
/* text string text[] and a pattern string pat[], this    */
/* function will find the first occurrence of pat[] in    */
/* test[] by using the naive Boyer-Moore algorithm.       */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/18/1989 */
/* ------------------------------------------------------ */

#include  <string.h>          /* for strlen()             */

#define   NOT_FOUND      -1

void  get_jump(unsigned char [], int []);
int   BM(unsigned char [], unsigned char []);

int  BM(unsigned char text[], unsigned char pat[])
{
     int  jump_tab[256];
     int  t_len = strlen(text);
     int  p_len = strlen(pat);
     int  i, j, k;

     get_jump(pat, jump_tab); /* compute the jump table   */
     for (i = p_len - 1; i < t_len; ) { /* comp. downward */
          for (j=p_len-1, k=i; j >= 0 && text[k] == pat[j]; k--,j--)
               ;
          if (j < 0)          /* if pat[] exhausted ?     */
               return k + 1;  /* YES, pattern found.      */
          else                /* NO, update using jump_tab*/
               i += jump_tab[text[i]];
     }
     return NOT_FOUND;        /* text[] exhausted.        */
}


/* ------------------------------------------------------ */
/* FUNCTION get_jump :                                    */
/*    Given the pattern string pat[], this function       */
/* computes a jump table, jump_tab[], by look at each char*/
/* in the pattern string.                                 */
/* ------------------------------------------------------ */

void  get_jump(unsigned char pat[], int jump_tab[])
{
     int  length = strlen(pat);
     int  i;

     for (i = 1; i < 256; i++) /* assume length is the gap*/
          jump_tab[i] = length;
     for (i = 0; i < length - 1; i++) /* now adjust them. */
          jump_tab[(int)pat[i]] = length - i - 1;
}


/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE       100

void main(void)
{
     unsigned char  text[MAXSIZE];
     unsigned char  pat[MAXSIZE];
     int            answer, i;
     
     printf("\nBoyer-Moore String Searching Program");
     printf("\n====================================");
     printf("\n\nText String    --> ");
     gets(text);
     printf(  "\nPattern String --> ");
     gets(pat);

     if ((answer = BM(text, pat)) >= 0) {
          printf("\n ");
          for (i = 1; i <= 6; i++)
               printf("         %1d", i);
          printf("\n");
          for (i = 1; i <= 6; i++)
               printf("0....5....");
          printf("0");
          printf("\n%s\n", text);
          for (i = 0; i < answer; i++)
               printf(" ");
          printf("%s", pat);
          printf("\n\nPattern Found at location %d", answer);
     }
     else
          printf("\nPattern NOT FOUND.");
}

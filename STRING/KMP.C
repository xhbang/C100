/* ------------------------------------------------------ */
/* FUNCTION Knuth-Morris-Pratt string search program :    */
/*    Given text string and pattern string in text[] and  */
/* pat[] respectively, these two routines will find if    */
/* the pat[] string is somewhere in the text[] by using   */
/* the linear Knuth-Morris-Pratt algorithm.               */
/*                                                        */
/* Copyright Ching-Kunag Shene               July/12/1989 */
/* ------------------------------------------------------ */

#include  <string.h>          /* for strlen()             */

/* ------------------------------------------------------ */
/* FUNCTION  setup :                                      */
/*    Given the pattern pat[], setup builds up the failure*/
/* function table fail[].                                 */
/* ------------------------------------------------------ */

void setup(char pat[], int fail[])
{
     int  length = strlen(pat);
     int  i, j;

     fail[0] = -1;
     for (i = 1; i < length; i++) {
          for (j=fail[i-1]; j>=0 && pat[j+1]!=pat[i]; j=fail[j])
               ;
          fail[i] = (j < 0 && pat[j+1] != pat[i]) ? -1 : j+1;
     }
}

/* ------------------------------------------------------ */
/* FUNCTION  KMP :                                        */
/*    The KMP pattern search routine.                     */
/* ------------------------------------------------------ */

int KMP(char text[], char pat[], int fail[])
{
     int  t_length = strlen(text);
     int  p_length = strlen(pat);
     int  t, p;

     setup(pat, fail);        /* build up the fail func.  */
     for (t = p = 0; t < t_length && p < p_length; )
          if (text[t] != pat[p]) /* if not match ...      */
               if (p > 0)     /* is it the 1st location?  */
                    p = fail[p-1] + 1; /* no, shift right */
               else
                    t++;      /* or match next in text[]  */
          else
               t++, p++;      /* matched, advance both    */
     return (p >= p_length) ? t - p_length : -1;
}


/* ------------------------------------------------------ */

#include  <stdio.h>

#define   MAXSIZE  100

void main(void)
{
     char  text[MAXSIZE];
     char  pat[MAXSIZE];
     int   fail[MAXSIZE];
     int   answer, i;

     printf("\nKnuth-Morris-Pratt String Search Program");
     printf("\n========================================");
     printf("\n\nText String ------> ");
     gets(text);
     printf(  "\nPattern String ---> ");
     gets(pat);

     if ((answer = KMP(text, pat, fail)) >= 0) {
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
          printf("\nPattern NOT found");
}

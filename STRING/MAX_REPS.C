/* ------------------------------------------------------ */
/* FUNCTION  max_repetition :                             */
/*    Given a text string text[] and a pattern pat[], this*/
/* fucntion computes the maximum repetition number of the */
/* pattern such that the expanded pattern is the longest  */
/* subsequence of the text.  NOTE the 'repetition' means  */
/* repeating individual characters, but the usual meaning */
/* of concatenation.                                      */
/* Copyright Ching-Kuang Shene               July/27/1989 */
/* ------------------------------------------------------ */

#define   FOUND      1
#define   NOT_FOUND  0

int  subsequence(char [], char [], int, int []);

int  max_repetition(char text[], char pat[], int loc[])
{
     int  t_len = strlen(text);
     int  p_len = strlen(pat);
     int  low   = 1;
     int  high  = t_len/p_len;
     int  mid;

     if (subsequence(text, pat, low, loc) == NOT_FOUND)
          return NOT_FOUND;

     while (low + 1 < high) { /* there must a solution in */
          mid = (low + high)/2;  /* the [low,high]        */
          if (subsequence(text, pat, mid, loc) == FOUND)
               low  = mid;
          else
               high = mid;
     }

     /* ------- do it again to recover loc[] array ------ */

     if (subsequence(text, pat, high, loc) == FOUND)
          return high;
     (void) subsequence(text, pat, low, loc);
     return low;
}

     
/* ------------------------------------------------------ */
/* FUNCTION  subsequence :                                */
/*    This is a modified version of the function appeared */
/* earlier.  subsequence() accepts a text string text[],  */
/* a pattern string pat[] and repeated number 'number',   */
/* than determines if there exists a subsequence in text  */
/* of form pat[0]pat[0]...pat[0]pat[1]pat[1]...pat[1]...  */
/* That is each character in pat[] repeats 'number' times.*/
/* ------------------------------------------------------ */

int  subsequence(char text[], char pat[], int number, int loc[])
{
     int  t_len = strlen(text);
     int  p_len = strlen(pat);
     int  count, index = 0;
     int  i, j;

     if (p_len > t_len)       /* is pattern too long ?    */
          return NOT_FOUND;   /* YES, return.             */

     for (i = j = 0; i < t_len && j < p_len; j++) {
          count = 0;
          do {
               for (; i < t_len && text[i] != pat[j]; i++)
                    ;         /* can we find pat[j] ?     */
               if (i >= t_len)     /* text[] exhausted ?  */
                    return NOT_FOUND;  /* YES, not found. */
               else {
                    loc[index++] = i++;
                    count++;
               }
          } while (count < number);
     }
     return FOUND;
}

/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE   100

void  main(void)
{
     char  t[MAXSIZE], p[MAXSIZE];
     int   loc[MAXSIZE];
     int   n, i, j;
     char  line[100];

     printf("\nMaximum Repetition of Subsequence");
     printf("\n=================================");
     printf("\n");
     printf("\nText String    : ");  
     gets(t);
     printf("\nPattern String : ");
     gets(p);
     if ((n = max_repetition(t, p, loc)) > 0) {
          printf("\nThe Maximum Repetition Factor is %d", n);
          printf("\nPattern's Locations are shown Bellow :\n");
          printf("\n%s\n", t);
          for (i = j = 0; i < strlen(p)*n; i++, j++) {
               for ( ; j < loc[i]; j++)
                    printf(" ");
               printf("%c", t[j]);
          }
     }
     else
          printf("\n*** Pattern NOT FOUND *****");
}

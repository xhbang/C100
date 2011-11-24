/* ------------------------------------------------------ */
/* FUNCTION  subsequence :                                */
/*    Given a text string text[] and a pattern string     */
/* pat[], this function picks up a subsequence of text[]  */
/* which matches pat[] and stores the corresponding       */
/* locations into array loc[].                            */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/26/1989 */
/* ------------------------------------------------------ */

#define   FOUND      1
#define   NOT_FOUND  0

int  subsequence(char text[], char pat[], int loc[])
{
     int  t_len = strlen(text);
     int  p_len = strlen(pat);
     int  i, j;

     if (p_len > t_len)       /* is pattern too long ?    */
          return NOT_FOUND;   /* YES, return.             */

     for (i = j = 0; i < t_len && j < p_len; j++) {
          for ( ; i < t_len && text[i] != pat[j]; i++)
               ;              /* can we find pat[j] ?     */
          if (i >= t_len)     /* text[] exhausted ?       */
               return NOT_FOUND;  /* YES, not found.      */
          else                /* NO, pat[j] is located at */
               loc[j] = i;    /* i-th pos. of text[]      */
     }
     return FOUND;
}

/* ------------------------------------------------------ */

#include  <stdio.h>

#define   MAXSIZE   100

void  main(void)
{
     char  t[MAXSIZE], p[MAXSIZE];
     int   loc[MAXSIZE];
     int   i, j;

     printf("\nSubsequence Search Program");
     printf("\n==========================");
     printf("\n");
     printf("\nText String    : ");  
     gets(t);
     printf("\nPattern String : ");
     gets(p);
     if (subsequence(t, p, loc) == FOUND) {
          printf("\n\nPattern's Locations are shown Bellow :\n");
          printf("\n%s\n", t);
          for (i = j = 0; i < strlen(p); i++, j++) {
               for ( ; j < loc[i]; j++)
                    printf(" ");
               printf("%c", t[j]);
          }
     }
     else
          printf("\n*** Pattern NOT FOUND *****");
}

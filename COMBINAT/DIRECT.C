/* ------------------------------------------------------ */
/* PROGRAM Subset Listing :                               */
/*    This program lists all subsets, including empty set,*/
/* of a given set with elements {1,2,...,n} by using a    */
/* direct generation method.                              */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/04/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE   20
#define   LOOP       1

void main(void)
{
     char digit[MAXSIZE];
     int  i, j;
     int  n;
     char line[100];

     printf("\nDirect Generation of All Subsets of a Set");
     printf("\n=========================================");
     printf("\n\nNumber of Elements in the Given Set --> ");
     gets(line);
     n = atoi(line);

     /* ---You'd better check to see if n is too large--- */

     for (i = 0; i < n; i++)  /* clear all digits to 0    */
          digit[i] = '0';

     printf("\n{}");          /* outpout empty set {}     */
     while (LOOP) {
          for (i = 0; i < n && digit[i] == '1'; digit[i] = '0', i++)
               ;              /* find first 0 position    */
          if (i == n)         /* if none, all pos. are 1  */
               break;         /* thus all elem. are in set*/
          else
               digit[i] = '1';/* now add one to this pos  */

          for (i = 0; i < n && digit[i] == '0'; i++)
               ;              /* find first 1 position    */
          printf("\n{%d", i+1);  /* show its numner and   */
          for (j = i + 1; j < n; j++) /* others           */
               if (digit[j] == '1')
                    printf(",%d", j + 1);
          printf("}");
     }
}

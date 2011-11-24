/* ------------------------------------------------------ */
/* PROGRAM Subset Generation by Gray Code :               */
/*    This program generates all possible subsets of a n  */
/* elements set with Gray Code.  Simply speaking, the Gray*/
/* code of n bits is a sequence of n-bit strings such that*/
/* any two consecutive two bit strings have exactly one   */
/* position in difference.  For example, for n = 3, the   */
/* gray code generated is the sequence 000,001,010,011,   */
/* 010,110,111,101 and 100.  Therefore each item of this  */
/* sequence corresponds one subset as in the direct method*/
/*                                                        */
/* Copyright Ching-Kuang Shene               July/05/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE         20
#define   YES             1
#define   LOOP            1

#define   FLIP_DIGIT(x)   x = ((x) == '0' ? '1' : '0')
#define   FLIP(x)         x = (1 - (x))

void main(void)
{
     char  digit[MAXSIZE];
     int   position[MAXSIZE];
     int   even;
     int   n;
     int   i, count = 0;
     char  line[100];

     printf("\nAll Subset Listing by Gray Code");
     printf("\n===============================");
     printf("\n\nNumber of Elements in Set Please --> ");
     gets(line);
     n = atoi(line);

     printf("\n");            /* initialization           */
     for (i = 0; i < n; i++) {
          digit[i] = '0';
          printf("0");
     }
     printf(" : {}\n");       /* the empty set            */

     even = YES;
     while (LOOP)  {
          if (even)           /* for even positions:0,2,..*/
               FLIP_DIGIT(digit[0]);  /* flip the 1st bit */
          else {              /* for odd positions...     */
               for (i = 0; i < n && digit[i] == '0'; i++)
                    ;         /* find the first 1 bit     */
               if (i == n-1) break; /* if it is the last..*/
               FLIP_DIGIT(digit[i+1]); /* NO, flip its nbr*/
          }
          for (count = 0, i = n - 1; i >= 0; i--) {
               printf("%c", digit[i]); /* print the bits  */
               if (digit[i] == '1')    /* and collect pos */
                    position[count++] = i + 1;
          }
          printf(" : {%d", position[count-1]);
          for (i = count - 2; i >= 0; i--) /* print pos   */
               printf(",%d", position[i]);
          printf("}\n");
          FLIP(even);         /* next will be odd(or even)*/
     }
}

/* ------------------------------------------------------ */
/* FUNCTION  parentheses_gen :                            */
/*    Given an even representing the length of a string,  */
/* this function generates all strings of well-formed     */
/* parentheses in a 'lexicagraphically' order, namely     */
/* '(' > ')'.  This is a recursive program, but it is a   */
/* matter to convert it to the iterative  version.        */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/28/1989 */
/* ------------------------------------------------------ */

#include  <stdlib.h>          /* for malloc()             */

void  gen(char [], int, int, int);

int  count;                   /* # of string counter      */

int  parentheses_gen(int n)
{
     char *x;
     int  i;

     x = (char *) malloc(sizeof(char)*n);  /* get memory  */
     for (i = 0; i < n; i++)  /* initialize it to blank   */
          x[i] = ' ';
     x[i] = '\0';
     count = 0;               /* set counter to zero.     */
     gen(x, n/2, n/2, 0);     /* and GO! gen n/2 ('s & )'s*/
     free(x);                 /* release memory           */
     return count;            /* return counter           */
}

/* ------------------------------------------------------ */
/* FUNCTION  gen :                                        */
/*    This function receives # of ('s and # of )'s, then  */
/* generates corresponding # of ('s and )'s.              */
/* ------------------------------------------------------ */

void  gen(char x[], int n, int left_no, int right_no)
{
     int  i;

     if (left_no == 0 && right_no == 0)  /* balanced ?    */
          printf("\n%5d   %s", ++count, x); /* YES, show  */
     else {                   /* not yet balanced...      */
          i = 2*(n - left_no) - right_no;  /* get next loc*/
          if (right_no != 0) { /* if too many )'s left    */
               x[i] = ')';    /* gen. a ) and keep trying */
               gen(x, n, left_no, right_no - 1);
          }                   
          if (left_no != 0) { /* now ('s=)'s, still have (*/
               x[i] = '(';    /* gen. a ( and add one )   */
               gen(x, n, left_no - 1, right_no + 1);
          }
     }
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     int  n, answer;
     char line[100];

     printf("\nWell-Formed Parenthesis Generation");
     printf("\n==================================");
     printf("\n\nString Length --> ");
     gets(line);
     n = atoi(line);
     if (n % 2 != 0)
          printf("\n*** ERROR ***  String Length must be even.");
     else {
          printf("\n   No   Generated String");
          printf("\n  ---   ----------------");
          answer = parentheses_gen(n);
          printf("\n\nThere are %d Parentheses Strings Generated.", 
                 answer);
     }
}

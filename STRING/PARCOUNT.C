/* ------------------------------------------------------ */
/* FUNCTION par_count :                                   */
/*    Given an input string containing ( and ), this      */
/* function counts the # of ('s and )'s and indicates the */
/* positions of those incorrect placed ('s and )'s.  The  */
/* input string is stored in line[].  error[], which      */
/* stores a set of error position indicators, is returned */
/* and thus can be printed below the input line so that   */
/* all error positions are macthed with the input.  'sw'  */
/* is an indicator variable, =0 means no error.           */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/08/1989 */
/* ------------------------------------------------------ */

#define  MAXLENGTH  100
#define  YES          1
#define  NO           0

void par_count(char line[], char error[], int *sw)
{
     int  location[MAXLENGTH]; 
     int  left    =  0;
     int  right   =  0;
     int  loc_ptr = -1;
     int  i;

     *sw = NO;                /* assume there is no error */
     for (i = 0; line[i] != '\0'; i++) { /* scan the input*/
          error[i] = ' ';     /* initial to no error mark */
          if (line[i] == '(') { /* is it a '(' ?          */
               location[++loc_ptr] = i; /* YES, save pos  */
               left++;        /* and increase '(' count   */
          } 
          else if (line[i] == ')') /* or if it is a ')'   */
               if (left <= right) {/* too many )'s ?      */
                    error[i] = '?';/* YES, record a mark  */
                    *sw      = YES;/* and set error switch*/
               }
               else {         
                    right++;  /* no error, inc. # of )'s  */
                    loc_ptr--;/* remove the matched (     */
               }
     }
     error[i] = '\0';         /* append a '\0'            */
     if (loc_ptr >= 0) {      /* are there more ('s ?     */
          *sw = YES;          /* YES, all of them are err.*/
          for (i = 0; i <= loc_ptr; i++) /* therefore set */
               error[location[i]] = '$'; /* error marks.  */
     }
}


/* ------------------------------------------------------ */

#include <stdio.h>

void main(void)
{
     char  line[MAXLENGTH];
     char  error[MAXLENGTH];
     int   error_sw;

     printf("\nParenthesis Counting Program");
     printf("\n============================\n");
     printf("\nInput a line please\n");
     gets(line);
     par_count(line, error, &error_sw);
     if (error_sw == NO)
          printf("\nCorrect Input.");
     else
          printf("%s", error);
}

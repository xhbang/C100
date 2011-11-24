/* ------------------------------------------------------ */
/* FUNCTION  x_atoi :                                     */
/*    An extended atoi() function with OVERFLOW detection.*/
/* You are expected to fill the missing UNDERFLOW part.   */
/* Given a string containing a sequence of digits, this   */
/* function converts this string to integer if no OVERFLOW*/
/* condition is detected, or returns OVERFLOW.  The result*/
/* is returned with a parameter.                          */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/26/1989 */
/* ------------------------------------------------------ */

#include  <limits.h>          /* for INT_MAX and INT_MIN  */
#include  <ctype.h>           /* for isdigit()            */

#define   OVERFLOW      1
#define   UNDERFLOW    -1
#define   NO_ERROR      0

int  x_atoi(char s[], int *result)
{
     int  digit_value;        /* value of the scaned dig  */
     int  i;

     *result = 0;
     for (i = 0; isdigit(s[i]); i++) /* overflow test     */
          if (*result <= (INT_MAX - (digit_value=s[i]-'0'))/10)
               *result = 10 * *result + digit_value;
          else
               return  OVERFLOW;  /* returns OVERFLOW     */
     return NO_ERROR;         /* normal ended             */
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void main(void)
{
     int  result;
     char s1[] = "12345";
     char s2[] = "45678";
     char s3[] = "32768";

     printf("\natoi() Function with Overflow Detection");
     printf("\n=======================================");
     printf("\n\nString #1 = \"%s\"", s1);
     if (x_atoi(s1, &result) == NO_ERROR)
          printf("\nResult    = %d", result);
     else
          printf("\nResult    = OVERFLOW");

     printf("\n\nString #2 = \"%s\"", s2);
     if (x_atoi(s2, &result) == NO_ERROR)
          printf("\nResult    = %d", result);
     else
          printf("\nResult    = OVERFLOW");

     printf("\n\nString #3 = \"%s\"", s3);
     if (x_atoi(s3, &result) == NO_ERROR)
          printf("\nResult    = %d", result);
     else
          printf("\nResult    = OVERFLOW");
}

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>

void main(void)
{
     int    number;           /* the input number         */
     int    pos, ten_pow;     /* # of digits and 10^x     */
     int    arm_no;           /* computed Armstrong Number*/
     int    temp, i;          /* working variables        */
     float  expon;            /* computed exponent        */
     char   line[100];        /* input buffer             */

     printf("\nPlease key in number : ");  /* get a number*/
     gets(line);
     number = atoi(line);

     pos = 0;                 /* count # of digits        */
     ten_pow = 1;             /* power of 10, 10^0=1      */
     do {                     /* start counting           */
          ten_pow *= 10;      /* one more digit...        */
          pos++;
     } while (ten_pow < number);

     if (ten_pow == number)   /* all 10^x are not Arm #   */
          printf("\n%d is not an Armstrong Number.", number);
     else {                   /* not 10^x                 */
          ten_pow = number;   /* now ten_pow is a temp var*/
          arm_no  = 0;        /* initial value for Arm. # */
          for (i = pos-1; i >= 1; i--) { /* scan from R->L*/
               expon = exp(i*log(10.0)); /* the ugly part */
               temp  = ten_pow / expon;  /* you do it...  */
               ten_pow %= (int)(expon + 0.5);
               arm_no  += exp(pos*log(temp)) + 0.5;
          }
          arm_no += exp(pos*log(ten_pow)) + 0.5;
          if (arm_no == number)
               printf("\n%d is an Armstrong Number.", number);
          else
               printf("\n%d is not an Armstrong Number.", number);
     }
}

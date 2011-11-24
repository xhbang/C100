#include  <stdio.h>
#include  <stdlib.h>

void main(void)
{
     long  left, right;
     long  sum;
     long  GIVEN;
     char  line[100];

     gets(line);
     GIVEN = atol(line);

     for (sum = 0, left = right = 1; left < GIVEN/2+1; right++) {
          sum += right;
          while (sum > GIVEN) {
               sum -= left;
               left++;
          }
          if (sum == GIVEN)
               printf("\n%ld - %ld", left, right);
     }
}

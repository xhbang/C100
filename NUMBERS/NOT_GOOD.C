#include <stdio.h>
#include <stdlib.h>

void main(void)
{
     char  line[100];
     long  sum, i, j, n;

     gets(line);
     n = atol(line);

     for (i = 1; i <= n/2; i++)
          for (sum = i, j = i + 1; j <= n/2+1; j++) {
               sum += j;
               if (sum == n)
                    printf("\n%ld - %ld", i, j);
          }
}

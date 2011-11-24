/* ------------------------------------------------------ */
/* FUNCTION  infinite precision addition & multiplication */
/*    Given two infinite precision numbers, functions in  */
/* this program can add and multiply them in infinite     */
/* precision.  This package contains four basic functions,*/
/* namely, make_number(), add(), multiply() and           */
/* display_number().                                      */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/15/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>           /* for display_number()     */
#include  <stdlib.h>          /* for malloc() and free()  */
#include  <string.h>          /* for memmove()            */

#define   BASE         10     /* radix used in this system*/

#define   MAX(x, y)    ((x) >= (y) ? (x) : (y))
#define   MIN(x, y)    ((x) <= (y) ? (x) : (y))

typedef struct number  NUMBER; /* type of a number        */

struct  number  {             /* data struct. of NUMBER   */
     int   length;            /* it consists of a length  */
     char  *data;             /* and a ptr to data        */
};

/* ------------------------------------------------------ */
/* FUNCTION  make_number :                                */
/*    This function accepts a positive long integer and   */
/* converts it to the infinite precision form.            */
/* ------------------------------------------------------ */

NUMBER  *make_number(long n)
{
     char  buffer[16];        /* assume long has 16 digits*/
     int   len, i;
     NUMBER *u;

     len = sprintf(buffer, "%d", (n >= 0) ? n : -n);
     for (i = 0; buffer[i] != '\0'; i++) /* convert to bin*/
          buffer[i] = buffer[i] - '0';

     u   = (NUMBER *) malloc(sizeof(NUMBER));
     u->length = len;
     u->data   = (char *) malloc(sizeof(char)*(len+1));
     memmove(u->data, buffer, len+1);
     return u;
}

/* ------------------------------------------------------ */
/* FUNCTION  add :                                        */
/*    Given two numbers, this function computes their sum */
/* and returns a new pointer to the sum.                  */
/* ------------------------------------------------------ */

NUMBER  *add(NUMBER *opn1, NUMBER *opn2)
{
     int  m  = opn1->length;
     char *u = opn1->data;
     int  n  = opn2->length;
     char *v = opn2->data;
     char *w, *p;
     int  mn = MAX(m,n)+1;
     int  carry = 0, temp;
     int  i, j, k, t;
     NUMBER *result;

     w = (char *) malloc(sizeof(char)*(mn+1)); 
     w[mn] = '\0';
    
     for (i=m-1, j=n-1, k=mn-1; i>=0 && j>=0; i--,j--,k--) {
          temp  = u[i] + v[j] + carry;
          w[k]  = (char) (temp % BASE);
          carry = (char) (temp / BASE);
     }

     if (i >= 0)              /* NOTE that last part gets */
          p = u, t = i;       /* the second half of the   */
     else                     /* result.  Now computes the*/
          p = v, t = j;       /* the first half.          */

     for ( ; t >= 0; t--, k--) {
          temp  = p[t] + carry;
          w[k]  = (char) (temp % BASE);
          carry = (char) (temp / BASE);
     }
     w[0] = carry;

     result = (NUMBER *) malloc(sizeof(NUMBER));
     if (w[0] == '\0') {      /* adjust array such that   */
          mn--;               /* the first digit != 0     */
          result->data = (char *) malloc(sizeof(char)*(mn+1));
          memmove(result->data, &w[1], mn+1);
          free(w);
     }
     else
          result->data = w;
     result->length = mn;
     return result;
}

/* ------------------------------------------------------ */
/* FUNCTION  multiply :                                   */
/*    Given two infinite precision number, this function  */
/* computes their product.                                */
/* ------------------------------------------------------ */

NUMBER  *multiply(NUMBER *opn1, NUMBER *opn2)
{
     int  n  = opn1->length;
     char *u = opn1->data;
     int  m  = opn2->length;
     char *v = opn2->data;
     char *w;
     int  mn = m + n;
     int  carry, temp;
     int  i, j;
     NUMBER *result;

     w = (char *) malloc(sizeof(char)*(mn+1));
     memset(&w[m], 0, n+1);

     for (j = m - 1; j >= 0; j--)  /* for each digit ...  */
          if (v[j] != '\0') {      /* computes product    */
               for (carry = 0, i = n - 1; i >= 0; i--) {
                    temp     = u[i]*v[j] + w[i+j+1] + carry;
                    w[i+j+1] = (char) (temp % BASE);
                    carry    = (char) (temp / BASE);
               }
               w[j] = (char) carry;
          }
          else
               w[j] = '\0';

     for (i = 0; w[i] == '\0'; i++) /* remove leading 0's */
          ;
     result = (NUMBER *) malloc(sizeof(NUMBER));
     result->length = mn - i;
     result->data   = (char *) malloc(sizeof(char)*(mn-i+1));
     memmove(result->data, &w[i], mn-i+1);
     free(w);
     return result;
}

/* ------------------------------------------------------ */
/* FUNCTION  display_number :                             */
/*    Display an infinite precision number.  NOTE that a  */
/* zero is represented with a null string.                */
/* ------------------------------------------------------ */

void  display_number(NUMBER *no)
{
     int  i;

     if (no->data == 0)
          printf("0");
     else
          for (i = 0; i < no->length; i++)
               printf("%c", (no->data)[i] + '0');
}

/* ------------------------------------------------------ */

void  main(void)
{
     NUMBER  *prod, *opn1, *opn2;
     NUMBER  *sum,  *temp;
     int     N;
     char    line[100];
     int     i;

     printf("\nInfinite Precision Addition and Multiplication");
     printf("\n==============================================");
     printf("\n\nFactorial of N --> ");
     gets(line);
     N = atoi(line);
     prod = make_number(1L);
     sum  = make_number(0L);
     for (i = 1; i <= N; i++) {
          opn1 = make_number((long) i);
          opn2 = multiply(prod, opn1);
          printf("\n%2d! = ", i);
          display_number(opn2);
          free(prod->data);  free(prod);
          free(opn1->data);  free(opn1);
          prod = opn2;

          temp = add(sum, prod);
          free(sum->data);   free(sum);
          sum  = temp;
     }
     printf("\n\n1! + 2! + ..... + %d! = ", N);
     display_number(sum);
}

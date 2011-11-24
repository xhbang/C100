/* ------------------------------------------------------ */
/* PROGRAM  prefix polish form evaluator :                */
/*    Given an input string of Prefix Polish Form with    */
/* integer constants and +, -, * and operator, this       */
/* program will calculate the result of the Prefix form.  */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/29/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <ctype.h>           /* for isdigit()            */

#define   LINE_SIZE      100  /* line buffer length       */
 
#define   STACK_BOTTOM     0  /* stack bottom indicator   */
#define   OPERAND          1  /* operand symbol indicator */
#define   OPERATOR         2  /* operator symbol indicator*/

/* ------------------------------------------------------ */
/*                 function prototypes                    */
/* ------------------------------------------------------ */

int       is_opr(char);       /* test for operator        */
double    compute(char, double, double);  /* evaluator    */
void      initial(void);      /* stack initialization     */
void      push_opn(double);   /* push an operand          */
void      push_opr(char);     /* push an operator         */
double    pop_opn(void);      /* pop an operand           */
char      pop_opr(void);      /* pop an operator          */
int       stack_top(void);    /* return type of top item  */

void  main(void)
{
     double opn1, opn2;       /* working operands         */
     char   s[LINE_SIZE];     /* input line buffer        */
     char   opr;              /* working operator         */
     char   *p;               /* buffer cursor            */

     printf("\nPrefix Form Evaluator");
     printf("\n=====================");
     printf("\n\nInput --> ");
     gets(s);

     initial();               /* initial stack            */
     for (p = s; *p != '\0'; p++)  /* for each character  */
          if (is_opr(*p))     /* is is an operator ?      */
               push_opr(*p);  /* YES, push.               */
          else if (isdigit(*p)) {  /* is it an operand ?  */
               opn2 = *p - '0'; /* YES, convert to double */
               while (stack_top() == OPERAND) { 
                    opn1 = pop_opn();  /* for all of its  */
                    opr  = pop_opr();  /* buddy, compute  */
                    opn2 = compute(opr, opn1, opn2);
               }
               push_opn(opn2);  /* then push the result   */
          }
     printf("\nResult = %lf", pop_opn());
}

/* ------------------------------------------------------ */
/* FUNCTION  is_opr :                                     */
/*    Tests to see if 'opr' contains an operator.         */
/* ------------------------------------------------------ */

int  is_opr(char opr)
{
     return opr == '+' || opr == '-' || opr == '*' || opr == '/';
}

/* ------------------------------------------------------ */
/* FUNCTION  compute :                                    */
/*    Given two operands and an operator, this function   */
/* computes the result.                                   */
/* ------------------------------------------------------ */

double  compute(char opr, double opn1, double opn2)
{
     double  result;

     switch (opr) {
          case '+' : result = opn1 + opn2;
                     break;
          case '-' : result = opn1 - opn2;
                     break;
          case '*' : result = opn1 * opn2;
                     break;
          case '/' : result = opn1 / opn2;
                     break;
     }
     return result;
}

/* ------------------------------------------------------ */
/*               stack management package                 */
/* ------------------------------------------------------ */

#define  STACK_SIZE    100    /* stack size               */

struct item {                 /* stack record  :          */
     union {                  /*    shared memory for     */
          double  value;      /*       operand value, or  */
          char    operator;   /*       operator symbol    */
     } store;
     int   type;              /*    type of stored item   */
};

static struct item  stack[STACK_SIZE];  /* actual stack   */
static int          top;                /* stack pointer  */

/* ------------------------------------------------------ */
/* FUNCTION  initial :                                    */
/*    Initializes the stack with STACK_BOTTOM symbol.     */
/* ------------------------------------------------------ */

void  initial(void)
{
     top = 0;
     stack[top].type = STACK_BOTTOM;
}

/* ------------------------------------------------------ */
/* FUNCTION  push_opn :                                   */
/*    Pushes an operand (a value) into the stack.         */
/* ------------------------------------------------------ */

void  push_opn(double data)
{
     stack[++top].type      = OPERAND;
     stack[top].store.value = data;
}

/* ------------------------------------------------------ */
/* FUNCTION  push_opr :                                   */
/*    Pushes an operator into the stack.                  */
/* ------------------------------------------------------ */

void  push_opr(char opr)
{
     stack[++top].type         = OPERATOR;
     stack[top].store.operator = opr;
}

/* ------------------------------------------------------ */
/* FUNCTION  pop_opn :                                    */
/*    Pops up and returns the top-most operand.           */
/* ------------------------------------------------------ */

double  pop_opn(void)
{
     return  stack[top--].store.value;
}

/* ------------------------------------------------------ */
/* FUNCTION  pop_opr :                                    */
/*    Pops up and returns the top-most operator.          */
/* ------------------------------------------------------ */

char  pop_opr(void)
{
     return  stack[top--].store.operator;
}

/* ------------------------------------------------------ */
/* FUNCTION  stack_top :                                  */
/*    Returns the type of the top-most item in stack.     */
/* ------------------------------------------------------ */

int  stack_top(void)
{
     return  stack[top].type;
}

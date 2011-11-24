/* ------------------------------------------------------ */
/* FUNCTION one solution for n queens' problem :          */
/*    Given a board size n > 3, this program computes one */
/* solution on the N Queens' Problem by using a formula   */
/* of legal positions.  This method is interesting because*/
/* there actuall are some regularities in the N Queens'   */
/* problem which confused C.F.Gauss once upon a time.     */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/17/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE    30
#define   MARK       'Q'

void  initial(void);
void  display(void);
void  class_1(void);
void  class_2(void);
void  class_3(void);
void  class_4(void);

int  n;                       /* input board size         */
char board[MAXSIZE+1][MAXSIZE+1]; /* the chess board      */

void main(void)
{
     void (*funct[])() = { class_1, class_2, /* functions */
                           class_4, class_3, /* of four   */
                           class_1, class_2  /* classes   */
                         };
     char line[100];

     printf("\nOne Solution for N Queens' Problem");
     printf("\n==================================");
     printf("\n\nBoard Size Please (N > 3) --> ");
     gets(line);
     n = atoi(line);

     if (n > 3) {
          initial();          /* initial the chess board  */
          (*funct[n % 6])();  /* call appropriate funct.  */
          display();          /* print result             */
     }
     else
          printf("\nIllegal Board Size.");
}


/* ------------------------------------------------------ */
/* FUNCTION initial :                                     */
/*    Initialize the chess board to blank.                */
/* ------------------------------------------------------ */

void initial(void)
{
     int  i, j;

     for (i = 1; i <= n; i++)
          for (j = 1; j <= n; j++)
               board[i][j] = ' ';
}


/* ------------------------------------------------------ */
/* FUNCTION display :                                     */
/*    Function to display the chess board.                */
/* ------------------------------------------------------ */

#define  DRAWGRID(N)     { int i;                          \
                           printf("\n+");                  \
                           for (i = 1; i <= N; i++)        \
                                printf("-+");              \
                         }


#define  DRAWLINE(N, r)  { int i;                          \
                           printf("\n|");                  \
                           for (i = 1; i <= N; i++)        \
                                printf("%c|", board[r][i]);\
                         }

void display(void)
{
     int  r;

     DRAWGRID(n);
     for (r = 1; r <= n; r++) {
          DRAWLINE(n, r);
          DRAWGRID(n);
     }
}


/* ------------------------------------------------------ */
/* FUNCTION class_1 :                                     */
/*    Solution for n mod 6 == 0 or 4.                     */
/* ------------------------------------------------------ */

void  class_1(void)
{
     int  i;

     for (i = 1; i <= n/2; i++)
          board[2*i][i] = board[2*i-1][n/2+i] = MARK;
}


/* ------------------------------------------------------ */
/* FUNCTION class_2 :                                     */
/*    Solution for n mod 6 == 1 or 5.                     */
/* ------------------------------------------------------ */

void  class_2(void)
{
     int  i;

     for (i = 1; i <= (n-1)/2; i++)
          board[2*i][i] = MARK;
     for (i = 1; i <= (n+1)/2; i++)
          board[2*i-1][(n-1)/2+i] = MARK;
}


/* ------------------------------------------------------ */
/* FUNCTION class_3 :                                     */
/*    Solution for n mod 6 == 3.                          */
/* ------------------------------------------------------ */

void  class_3(void)
{
     int  i;

     for (i = 1; i <= (n-3)/2; i++)
          board[2*i+2][i] = board[2*i+3][(n-1)/2+i] = MARK;
     board[1][n-1] = board[2][(n-2)/2] = board[3][n] = MARK;
}


/* ------------------------------------------------------ */
/* FUNCTION class_4 :                                     */
/*    Solution for n mod 6 = 2.                           */
/* ------------------------------------------------------ */

void  class_4(void)
{
     int  i;

     if (n > 8) {
          for (i = 1; i <= 3; i++)
               board[2*i-1][n/2-2+i] = MARK;
          board[2][n] = board[4][1] = board[6][n-1] = MARK;
          for (i = 1; i <= n/2 - 3; i++)
               board[2*i+5][i+1] = board[2*i+6][n/2+1+i] = MARK;
     }
     else {
          for (i = 1; i <= 4; i++)
               board[2*i][i] = MARK;
          board[1][6] = board[3][5] = MARK;
          board[5][8] = board[7][7] = MARK;
     }
}

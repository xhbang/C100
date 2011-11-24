/* ------------------------------------------------------ */
/* PROGRAM all possible solutions of n queens' problem :  */
/*    Given an input n, this program computes all possible*/
/* solutions of the N Queens' Problem by using recursive  */
/* method.                                                */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/17/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE     20      /* max. board size          */
#define   DIAG_SIZE   39      /* max. # of diagonals      */
#define   OCCUPIED     0      
#define   EMPTY        1

void initial(void);
void display(void);
void try(int);

int       pos[MAXSIZE+1];     /* pos[j]=i means Q is (i,j)*/
int       in_row[MAXSIZE+1];  /* in_row[i] true->row occ. */
int       diag[DIAG_SIZE+1];  /* diag[i] or back_diag[i]  */
int       back_diag[DIAG_SIZE+1]; /* = true -> occupied.  */
int       n;                  /* input board size         */
int       count = 0;          /* # of solutions counter   */

void main(void)
{
     int  i, j;
     char line[100];

     printf("\nAll Possible Solutions of N Queens' Problem");
     printf("\n===========================================");
     printf("\n\nBoard Size (N > 3) --> ");
     gets(line);
     n = atoi(line);

     initial();
     try(1);                  /* starting from column 1   */
     printf("\n\nThere are %d solutions in total.", count);
}


/* ------------------------------------------------------ */
/* FUNCTION initial :                                     */
/*    Function to initial the chess board.                */
/* ------------------------------------------------------ */

void  initial(void)
{
     int  i;

     for (i = 1; i <= n; i++)
          in_row[i] = EMPTY;
     for (i = 1; i <= 2*n - 1; i++)
          diag[i] = back_diag[i] = EMPTY;

     printf("\nSolutions are represented the row # in a column");
     printf("\n\n  #");
     for (i = 1; i <= n; i++)
          printf("%3d", i);
     printf("\n---");
     for (i = 1; i <= n; i++)
          printf(" --");
}


/* ------------------------------------------------------ */
/* FUNCTION display :                                     */
/*    Function to display a single solution.              */
/* ------------------------------------------------------ */

void  display(void)
{
     int  i;

     printf("\n%3d", count);
     for (i = 1; i <= n; i++)
          printf("%3d", pos[i]);
}


/* ------------------------------------------------------ */
/* FUNCTION try :                                         */
/*    Given a column number, this function tries to put   */
/* a queen on some row of that column until all possible  */
/* rows are attampted.                                    */
/* ------------------------------------------------------ */

#define  SAVE(r,c)  (in_row[r] && back_diag[r+c-1] && diag[n-(c-r)])
#define  SET(r,c)   { pos[c]             = r;         \
                      in_row[r]          = OCCUPIED;  \
                      back_diag[r+c-1]   = OCCUPIED;  \
                      diag[n-(c-r)]      = OCCUPIED;  \
                    }
#define  RESET(r,c) { in_row[r]          = EMPTY;     \
                      back_diag[r+c-1]   = EMPTY;     \
                      diag[n-(c-r)]      = EMPTY;     \
                    }
 
void  try(int column)
{
     int  row;

     for (row = 1; row <= n; row++)  /* for each row      */
          if (SAVE(row, column)) {   /* is it save ?      */
               SET(row, column);     /* YES, make a record*/
               if (column < n)       /* all columns tried?*/
                    try(column+1);   /* NO, try next col. */
               else {
                    count++;         /* OR, we found a sol*/
                    display();       /* display it.       */
               }
               RESET(row, column);   /* restore and back. */
          }
}

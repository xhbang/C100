/* ------------------------------------------------------ */
/* PROGRAM  game of life :                                */
/*    This is a finite implementation of John H. Conway's */
/* Game of Life.  Refere to my book for detail please.    */
/*                                                        */
/* Copyright Ching-Kuang Shene               July/25/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>

#define   MAXSIZE      50     /* board size               */
#define   OCCUPIED      1     /* occupied flag            */
#define   UNOCCUPIED    0
#define   YES           1
#define   NO            0

char  cell[MAXSIZE][MAXSIZE];      /* the board           */
char  workcopy[MAXSIZE][MAXSIZE];  /* a working copy      */
int   row;                    /* No. of rows you want     */
int   column;                 /* no. of columns you want  */
int   generations;            /* maximum no. of generation*/

/* ------------------------------------------------------ */
/* FUNCTION  read_in :                                    */
/*    This function reads in the number of generations,   */
/* the number of rows, the number of columns and finally  */
/* the initial configuration (the generation 0).  Then put*/
/* your configuration to the center of the board.         */
/* ------------------------------------------------------ */

void  read_in(void)
{
     int  max_row, max_col;   /* max # of row and col.    */
     int  col_gap, row_gap;   /* incremnet of row and col */
     int  i, j;
     char line[100];

     gets(line);              /* read in gens, row and col*/
     sscanf(line, "%d%d%d", &generations, &row, &column);
     for (i = 0; i < row; i++)/* clear the board          */
          for (j = 0; j < column; j++)
               cell[i][j] = UNOCCUPIED;
     max_col = 0;             /* read in the config.      */
     for (max_row = 0; gets(line) != NULL; max_row++) {
          for (i = 0; line[i] != '\0'; i++)
               if (line[i] != ' ')
                    cell[max_row][i] = OCCUPIED;
          max_col = (max_col < i) ? i : max_col;
     }
     row_gap = (row - max_row)/2;    /* the moving gap    */
     col_gap = (column - max_col)/2;
     for (i = max_row + row_gap - 1; i >= row_gap; i--) {
          for (j = max_col + col_gap - 1; j >= col_gap; j--)
               cell[i][j] = cell[i-row_gap][j-col_gap];
          for ( ; j >= 0; j--)
               cell[i][j] = UNOCCUPIED;
     }
     for ( ; i >= 0; i--)
          for (j = 0; j < column; j++)
               cell[i][j] = UNOCCUPIED;
}

/* ------------------------------------------------------ */
/* FUNCTION  display :                                    */
/*    Display the board.                                  */
/* ------------------------------------------------------ */

#define   DRAW_BOARDER(n) { int i;                    \
                            printf("\n+");            \
                            for (i = 0; i < n; i++)   \
                                 printf("-");         \
                            printf("+");              \
                          }
void  display(int gen_no)
{
     int  i, j;

     if (gen_no == 0)
          printf("\n\nInitial Generation :\n");
     else
          printf("\n\nGeneration %d :\n", gen_no);

     DRAW_BOARDER(column);
     for (i = 0; i < row; i++) {
          printf("\n|");
          for (j = 0; j < column; j++)
               printf("%c", (cell[i][j] == OCCUPIED) ? '*' : ' ');
          printf("|");
     }
     DRAW_BOARDER(column);
}

/* ------------------------------------------------------ */
/* FUNCTION  game_of_life :                               */
/*    This is the main function of Game of Life.          */
/* ------------------------------------------------------ */

void  game_of_life(void)
{
     int  stable;             /* stable flag              */
     int  iter;               /* iteration count          */
     int  top, bottom, left, right; /* neighborhood bound */
     int  neighbors;          /* # of neighbors           */
     int  cell_count;         /* # of cells count         */
     int  done;
     int  i, j, p, q;

     display(0);              /* display initial config.  */
     done = NO;
     for (iter = 1; iter <= generations && !done; iter++) {
          memmove(workcopy, cell, MAXSIZE*MAXSIZE); /*copy*/
          stable     = YES;   /* assume it is in stable   */
          cell_count = 0;     /* # of survived cells = 0  */
          for (i = 0; i < row; i++) { /* scan each cell...*/
               top    = (i == 0) ? 0 : i - 1;
               bottom = (i == row - 1) ? row-1 : i + 1;
               for (j = 0; j < column; j++) {
                    left  = (j == 0) ? 0 : j - 1;
                    right = (j == column - 1) ? column-1 : j + 1;

                    /* compute number of neighbors        */

                    neighbors = 0;
                    for (p = top; p <= bottom; p++)
                         for (q = left; q <= right; q++)
                              neighbors += workcopy[p][q];
                    neighbors -= workcopy[i][j];

                    /* determine life or dead             */

                    if (workcopy[i][j] == OCCUPIED) 
                         if (neighbors == 2 || neighbors == 3) {
                              cell[i][j] = OCCUPIED;
                              cell_count++;
                         }
                         else
                              cell[i][j] = UNOCCUPIED;
                    else if (neighbors == 3) {
                         cell[i][j] = OCCUPIED;
                         cell_count++;
                    }
                    else
                         cell[i][j] = UNOCCUPIED;
                    stable = stable && (workcopy[i][j] == cell[i][j]);
               }
          }
          if (cell_count == 0) {
               printf("\n\nAll cells die out.");
               done = YES;
          }
          else if (stable) {
               printf("\n\nSystem enters a stable state.");
               done = YES;
          }
          else
               display(iter);
     }
}

/* ------------------------------------------------------ */

void  main(void)
{
     read_in();
     game_of_life();
}

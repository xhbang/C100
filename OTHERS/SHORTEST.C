/* ------------------------------------------------------ */
/* FUNCTION  floyd shortest path :                        */
/*    Given a matrix of path distance of a street map,    */
/* this function determines the minimum distances between */
/* all pairs of vertices and its route.  In the distance  */
/* matrix, i->i is filled with zero, while those i-j pairs*/
/* without an edge will be put in an infinity.  On return */
/* path[][] is the path matrix which could be printed out */
/* with display_path() function.                          */
/*                                                        */
/* Copyright Ching-Kuang Shene               Sept/03/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>           /* for gets() and sscanf()  */
#include  <stdlib.h>          /* for malloc() and free()  */
#include  <limits.h>          /* for INT_MAX              */

#define   MAXSIZE   20        /* max. size of matrices    */

/* ------------------------------------------------------ */
/*                  function prototypes                   */
/* ------------------------------------------------------ */

void  floyd(int [][MAXSIZE], int [][MAXSIZE], int);
void  display_path(int [][MAXSIZE], int [][MAXSIZE], int);
void  reverse(int [], int);
void  readin(int [][MAXSIZE], int *);

/* ------------------------------------------------------ */
/* FUNCTION  floyd :                                      */
/*    Floyd's All-Shortest Path Algorithm.                */
/* ------------------------------------------------------ */

#define   MAXSUM(a, b)   (((a) != INT_MAX && (b) != INT_MAX) ? \
                          ((a) + (b)) : INT_MAX)

void  floyd(int dist[][MAXSIZE], int path[][MAXSIZE], int n)
{
     int  i, j, k;

     for (i = 0; i < n; i++)  /* initialize path matrix   */
          for (j = 0; j < n; j++)
               path[i][j] = i;

     for (k = 0; k < n; k++)  /* for vertex k ...         */
          for (i = 0; i < n; i++) /* update dist. with    */
               for (j = 0; j < n; j++)  /* vertex k.      */
                    if (dist[i][j] > MAXSUM(dist[i][k], dist[k][j])) {
                         path[i][j] = path[k][j]; 
                         dist[i][j] = MAXSUM(dist[i][k], dist[k][j]);
                    }
}

/* ------------------------------------------------------ */
/* FUNCTION  display_path :                               */
/*    This function receives the dist. and path matrices, */
/* then prints shortest paths of all i-j pairs.           */
/* ------------------------------------------------------ */

void  display_path(int dist[][MAXSIZE], int path[][MAXSIZE], int n)
{
     int  *chain;
     int  count;
     int  i, j, k;

     printf("\n\nOrigin->Dest    Dist    Path");
     printf(  "\n------------    ----    ----");

     chain = (int *) malloc(sizeof(int)*n);
     for (i = 0; i < n; i++)  /* scan all i-j pairs       */
          for (j = 0; j < n; j++) {
               if (i != j) {  /* discard diagonal pairs   */
                    printf("\n%6d->%4d    ", i+1, j+1);
                    if (dist[i][j] == INT_MAX) /* discard */
                         printf("  NA    "); /* un-reachbl*/
                    else {
                         printf("%4d    ", dist[i][j]);
                         count = 0;   /* extract path     */
                         k     = j;
                         do {
                              k = chain[count++] = path[i][k];
                         } while (i != k);
                         reverse(chain, count); /* reverse*/
                         printf("%d", chain[0]+1); /* prt.*/
                         for (k = 1; k < count; k++)
                              printf("->%d", chain[k]+1);
                         printf("->%d", j+1);
                    }
               }
          }
     free(chain);             /* release memory           */
}

/* ------------------------------------------------------ */
/* FUNCTION  reverse :                                    */
/*    This function reverses the input array.             */
/* ------------------------------------------------------ */

#define  SWAP(a, b)    { temp = a; a = b; b = temp; }

void  reverse(int x[], int n)
{
     int  i, j, temp;

     for (i = 0, j = n-1; i < j; i++, j--)
          SWAP(x[i], x[j]);
}

/* ------------------------------------------------------ */
/* FUNCTION  readin :                                     */
/*    Function to read in the distance matrix.            */
/* ------------------------------------------------------ */

void  readin(int dist[][MAXSIZE], int *number)
{
     int  origin, dest, length, n;
     int  i, j;
     char line[100];
     
     gets(line);              /* read in # of vertices    */
     sscanf(line, "%d", &n);
     *number = n;
     for (i = 0; i < n; i++) {/* initial dist. matrix     */
          for (j = 0; j < n; j++)
               dist[i][j] = INT_MAX;
          dist[i][i] = 0;     /* disgonal must be zero.   */
     }

     gets(line);              /* get first data line      */
     sscanf(line, "%d%d%d", &origin, &dest, &length);
     while (origin != 0 && dest != 0 && length != 0) {
          dist[origin-1][dest-1] = length;
          gets(line);         /* get other data lines     */
          sscanf(line, "%d%d%d", &origin, &dest, &length);
     }
}

/* ------------------------------------------------------ */

void  main(void)
{
     int  dist[MAXSIZE][MAXSIZE];
     int  path[MAXSIZE][MAXSIZE];
     int  n;

     printf("\nAll-Shortest Program");
     printf("\n====================");

     readin(dist, &n);
     floyd(dist, path, n);
     display_path(dist, path, n);
}

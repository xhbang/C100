/* ------------------------------------------------------ */
/* FUNCTION  edit :                                       */
/*    Given two strings and costs of inserting, deleting  */
/* and exchanging a character, this function computes a   */
/* longest common subsequence and puts those common       */
/* positions in array s[] and t[].  Then another function */
/* can print all editing operations by looking at these   */
/* positions.                                             */
/*                                                        */
/* Copyright Ching-Kuang Shene                Aug/15/1989 */
/* ------------------------------------------------------ */

#include  <stdio.h>           /* for printf()             */
#include  <stdlib.h>          /* for malloc() and free()  */
#include  <string.h>          /* for strlen(), memncpy()  */

void  edit(char [], char [], int [], int [], int *);
void  edit_op(char [], char [], int [], int [], int);
void  reverse(int [], int);

#define   INSERT_COST       1 /* cost for inserting a char*/
#define   DELETE_COST       1 /* cost for deleting a char */
#define   EXCHANGE_COST     2 /* cost for exchanging chars*/

#define   MIN(x, y, z)      ((x) <= (y) ?                   \
                                 ((x) <= (z) ? (x) : (z)) : \
                                 ((y) <= (z) ? (y) : (z))   \
                            )

void  edit(char source[], char target[], int s[], int t[], int *count)
{
     int  s_len = strlen(source);
     int  t_len = strlen(target);
     int  insert_t, delete_s, exchange;
     int  i, j, no;
     int  **cost;

     /* -------------- get working memory --------------- */

     cost    = (int **) malloc(sizeof(int)*(s_len+1));
     cost[0] = (int *) malloc(sizeof(int)*(s_len+1)*(t_len+1));
     for (i = 1; i <= s_len; i++)
          cost[i] = cost[i-1] + t_len + 1;

     /* ---------------- initialization ----------------- */

     cost[0][0] = 0;
     for (i = 1; i <= s_len; i++)
          cost[i][0] = cost[i-1][0] + 1;
     for (j = 1; j <= t_len; j++)
          cost[0][j] = cost[0][j-1] + 1;

     /* ----- compute minimum cost for each i and j ----- */

     for (i = 0; i < s_len; i++)
          for (j = 0; j < t_len; j++)
               if (source[i] == target[j])
                    cost[i+1][j+1] = cost[i][j];
               else {         /* computes the min. cost   */
                    insert_t = cost[i+1][j] + INSERT_COST;
                    delete_s = cost[i][j+1] + DELETE_COST;
                    exchange = cost[i][j] + EXCHANGE_COST;
                    cost[i+1][j+1] = MIN(insert_t, delete_s, exchange);
               }

     /* ---------- get the locations of L.C.S. ---------- */

     for (i = s_len, j = t_len, no = 0; i != 0 && j != 0; )
          if (cost[i][j] == cost[i-1][j] + INSERT_COST)
               i--;
          else if (cost[i][j] == cost[i][j-1] + DELETE_COST)
               j--;
          else {
               s[no] = i - 1;
               t[no] = j - 1;
               no++, i--, j--;
          }
     reverse(s, no);
     reverse(t, no);
     *count = no;
     free(cost[0]);
     free(cost);
}

/* ------------------------------------------------------ */
/* FUNCTION  edit_op :                                    */
/*    This routine is used to output editing operations.  */
/* ------------------------------------------------------ */

#define    MAX(x, y)   ((x) >= (y) ? (x) : (y))

void  edit_op(char source[], char target[], int s[], int t[], int n)
{
     int  length = MAX(strlen(source), strlen(target)) + 1;
     int  i, j, k;
     char *work;

     printf("\n\nEditing Operations are listed as Follows\n");
     work = (char *) malloc(sizeof(char)*length);
     for (i = j = k = 0; i < n; j=s[i]+1, k=t[i]+1, i++) {
          if (s[i] - j > 0) {
               (void) strncpy(work, &source[j], s[i] - j);
               work[s[i]-j] = '\0';
               printf("\nDelete \"%s\" from source string.", work);
          }
          if (t[i] - k > 0) {
               (void) strncpy(work, &target[k], t[i] - k);
               work[t[i]-k] = '\0';
               printf("\nInsert \"%s\" to source string.", work);
          }
          printf("\nKeep \'%c\' from source string.", source[s[i]]);
     }
     if (strlen(source) - j > 0)
          printf("\nDelete \"%s\" from source string.", &source[j]);
     if (strlen(target) - k > 0)
          printf("\nInsert \"%s\" to source string.", &target[k]);

     printf("\n\nDONE! Target string generated.");
     free(work);
}

/* ------------------------------------------------------ */
/* FUNCTION  reverse :                                    */
/*    This function reverse the given array in place.     */
/* ------------------------------------------------------ */

#define   SWAP(a, b)   { t = a; a = b; b = t; }

void  reverse(int x[], int n)
{
     int  i, j, t;

     for (i = 0, j = n-1; i <= j; i++, j--)
          SWAP(x[i], x[j]);
}

/* ------------------------------------------------------ */

#include  <stdio.h>

void  main(void)
{
     char  source[100];
     char  target[100];
     int   on_source[100];
     int   on_target[100];
     int   equal_count;

     printf("\nString Editing Problem");
     printf("\n======================");
     printf("\n\nSource String --> ");
     gets(source);
     printf(  "\nTarget String --> ");
     gets(target);
     edit(source, target, on_source, on_target, &equal_count);
     edit_op(source, target, on_source, on_target, equal_count);
}

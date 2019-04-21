

#include "grid.h"
#include "stdio.h"
#define TRUE 1
#define FALSE 0

/*checks if i,j is out of bounds */
int check(int i,int j){
    if(i<0 || i>8 || j<0 || j>8){
          printf("I ,J is out of bounds \n");
          return TRUE;
    }
    return FALSE;
}

/* updates value of element(i,j) to n */
void grid_update_value(Grid_T *g, int i, int j, int n)
{
	assert(g);
	if (check(i,j)){
              return;
        }
	g->elts[i][j].val = n;
}


/* returns value of elemtn( i,j) */
int grid_read_value(Grid_T g, int i, int j)
{
	if (check(i,j));
	return g.elts[i][j].val;
}

/*sets choice of element(i,j) to 1*/
void grid_set_choice(Grid_T *g, int i, int j, int n)
{
	assert(g);
	if (check(i,j));
	g->elts[i][j].choices.num[n] = 1;
}

/*sets choice of element(i,j) to 0 */
void grid_clear_choice(Grid_T *g, int i, int j, int n)
{
	assert(g);
	if (check(i,j));
	g->elts[i][j].choices.num[n] = 0;
}

/* true if choice n for element i,j is valid */

int grid_choice_is_valid(Grid_T g, int i, int j, int n)
{
	if (check(i,j)){
              return 0;
        }else{

	       return (g.elts[i][j].choices.num[n]==1);
        }
}


void grid_remove_choice(Grid_T *g, int i, int j, int n)
{
	assert(g);
	if (check(i,j)) return;
	if (grid_choice_is_valid(*g, i, j, n)) {
             (g->elts[i][j].choices.count)--; 
        }
        grid_clear_choice(g, i, j, n);
}

void grid_add_choice(Grid_T *g, int i, int j, int n)
{
	assert(g);
	if (check (i,j)) return;
	if (!grid_choice_is_valid(*g, i, j, n)) {
              (g->elts[i][j].choices.count)++;
         }
	grid_set_choice(g, i, j, n);
}

/* returns choices count */
int grid_read_count(Grid_T g, int i, int j)
{
	if (check(i,j)){
              return -1;
       }else{
	      return g.elts[i][j].choices.count;
       }
}

/*sets choices count to 9 */
void grid_set_count(Grid_T *g, int i, int j)
{
	assert(g);
	if (check(i,j)) return;
	g->elts[i][j].choices.count = 9;
}
/* sets choices count to 0 */
void grid_clear_count(Grid_T *g, int i, int j)
{
	assert(g);
	if (check(i,j)) return;
	g->elts[i][j].choices.count = 0;
}

/* returns  grid.value */
int grid_read_unique(Grid_T g)
{
	return g.unique;
}

/*sets grid.unique value to 1 */
void grid_set_unique(Grid_T *g)
{
	assert(g);
	g->unique = 1;
}

/*sets grid.unique value to 0 */
void grid_clear_unique(Grid_T *g)
{
	assert(g);
	g->unique = 0;
}

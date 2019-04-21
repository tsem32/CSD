


#include "sudoku.h"
#include "time.h"

#define GRID_NUM(i,j) ((int)(i / 3)*3 + (int)(j / 3))


Grid_T sudoku_read(void)
{
	int count;
	int i=0, j=0;
	Grid_T g;
	char c;
	while ((c=fgetc(stdin)) != EOF){

                         if(c=='\n'){
                              j=0;
                              i++;
                              continue;
                          }
                         if(c==32){
                               continue;
                          }
                          if(i>=9){
                              printf("Columns out of bounds\n");
                          return g;
                           }
                          if(j>=9){
                              printf("rows out of bounds\n");
                          }
                            grid_update_value(&g,i,j,(int)c-48);
                            j=j+1;




         }
	return g;
}


void sudoku_print(FILE *s, Grid_T g)
{
	int i=0;
	int j=0;
	for (i; i < 9; i++){
		for (j; j < 9; j++){
			fputc( (char)(grid_read_value(g,i,j)+48), s);
			fputc(' ',s);
		}
		fputc('\n',s);
	}
}

/* checks and returns 1 if n value exists on a subgrid of grid g */
static int exists_on_grid(Grid_T g, int i, int j, int n)
{
	int grid_num = GRID_NUM(i, j);
	for (i = (int)(grid_num / 3) * 3; i <= (int)(grid_num / 3) * 3 + 2; i++){
		for (j = (grid_num % 3) * 3; j <= (grid_num % 3) * 3 + 2; j++){
			if (grid_read_value(g, i, j) == n){
                                            return 1;
                          }
                 }
	}
	return 0;
}


/* This functions initialises the choices of 
 * grid g ,the unique flag and the choices count
 */
static void sudoku_init_choices(Grid_T *g)
{
	int i;
	int j;
	int k;
	assert(g);
	grid_set_unique(g);
	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			int value;
			grid_clear_count(g, i, j);
			grid_clear_choice(g, i, j, 0);
			value = grid_read_value(*g, i, j);
			for (k = 1; k < 10; k++){
                                int exists;/*Existence flag*/
                                int l;
				grid_clear_choice(g, i, j, k);
				if (value != 0) continue;

				exists = 0;
				for (l = 0; l < 9; l++){
					/* checks for columns and rows to see
					    if value k exists on them */
					if (grid_read_value(*g, i, l) == k) {
						exists = 1;
						break;
					}
					if (grid_read_value(*g, l, j) == k){
						exists = 1;
						break;
					}
				}
				if (exists_on_grid(*g, i, j, k)) exists = 1;

				/* If value k doesnt exist in the  column ,row
				   and sub grid of  (i,j) add as a choice to 
				   (i,j) */
				if (exists == 0) grid_add_choice(g, i, j, k);
			}
		}
	}
}


/* Sets the row and col and returns the value of the choice 
   to try next from g */
static int sudoku_try_next(Grid_T g, int *row, int *col)
{
	int i;
	int j;
	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			/*Checks first for choices with count==1 */
			if (grid_read_value(g, i, j) != 0) continue;
			if (grid_read_count(g, i, j)==1){
				int k;
				*row = i; *col = j;
				for (k = 1; k <= 9; k++){
					if (grid_choice_is_valid(g, i, j, k)) return k;
				}
			}
		}
	}

	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			/* If there are arent any choices with 
			   count==1, find another choice to try */
			if (grid_read_value(g, i, j) != 0) continue;
			if (grid_read_count(g, i, j) != 0){
				int k;
				*row = i; *col = j;
				for (k = 1; k < 10; k++){
					if (grid_choice_is_valid(g, i, j, k)) return k;
				}
			}
		}
	}
	return 0;
}


/* Remove choice n from choices of cell i,j of grid g*/
static int sudoku_update_choice(Grid_T *g, int i, int j, int n)
{
        int nchoices;
	assert(g);
	nchoices = grid_read_count(*g, i, j);
	grid_remove_choice(g, i, j, n);
	return nchoices;
}

/* Elimintate the choice n from the sub_grid,row and column
   of cell (r,c) of grid g*/
static void sudoku_eliminate_choice(Grid_T *g, int r, int c, int n)
{
	int i; int grid_num; int j;
	for (i = 0; i < 9; i++){
		grid_remove_choice(g, r, i, n);
		grid_remove_choice(g, i, c, n);
	}
	grid_num = GRID_NUM(r, c);
	/* The following formulas are functions of grid_num */
	for (i = (int)(grid_num / 3) * 3; i <= (int)(grid_num / 3) * 3 + 2; i++){
		for (j = (grid_num % 3) * 3; j <= (grid_num % 3) * 3 + 2; j++){
			grid_remove_choice(g, i, j, n);
		}
	}

}


/* Solve puzzle g and return the solved puzzle; if the puzzle has
multiple solutions, return one of the possible solutions. */
Grid_T sudoku_solve(Grid_T g)
{
	Grid_T return_g;
	int r;
	int c;
	int value;
	sudoku_init_choices(&g);
	while (value = sudoku_try_next(g, &r, &c)){
		int number_of_choices;
		
		number_of_choices = sudoku_update_choice(&g, r, c, value);
		if (number_of_choices == 1){
			grid_update_value(&g, r, c, value);
			sudoku_eliminate_choice(&g, r, c, value);
		}
		else{
			/* If the number of choices were more than 1 backtrack*/
			Grid_T new_g = g;
			grid_clear_unique(&g);
			grid_update_value(&new_g, r, c, value);
			sudoku_eliminate_choice(&new_g, r, c, value);
			return_g = sudoku_solve(new_g);
			if (sudoku_is_correct(return_g)){
				return return_g;
			}
		}
	}
	return g;

}


/* Return true iff puzzle g is correct. */
int sudoku_is_correct(Grid_T g)
{
	int i, j, ex;
	/* ex is used to see the number of times a value 
	   occures at a row , column or sub grid */
	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			if (grid_read_value(g, i, j) == 0) return 0;
		}
	}
	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			int l;
			int value;
			int grid_num;
			value = grid_read_value(g, i, j);

			ex = 0;
			for (l = 0; l < 9; l++){
				if (grid_read_value(g, i, l) == value) ex++;
			}
			if (ex != 1) return 0;

			ex = 0;
			for (l = 0; l < 9; l++){
				if (grid_read_value(g, l, j) == value) ex++;
			}
			if (ex != 1) return 0;

			ex = 0;
			grid_num = GRID_NUM(i, j);
			/* The following formulas are functions of grid_num */
			for (i = (int)(grid_num / 3) * 3; i <= (int)(grid_num / 3) * 3 + 2; i++){
				for (j = (grid_num % 3) * 3; j <= (grid_num % 3) * 3 + 2; j++){
					if (grid_read_value(g, i, j) == value) ex++;
				}
			}
			if (ex != 1) return 0;

		}
	}
	return 1;

}


/* Returns true if solution g, as returned by sudoku_solve, has a
unique choice for each step (no backtracking required). (Note, g
must have been computed with the use of sudoku_solve.) */
int sudoku_solution_is_unique(Grid_T g)
{
	return g.unique;
}


/* Print all row, col, sub-grid errors/conflicts found in puzzle g;
some errors may be reported more than once. */
void sudoku_print_errors(Grid_T g)
{
	int i, j, ex;
	/* ex is used to see the number of times a value
	occures at a row , column or sub grid */

	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			if (grid_read_value(g, i, j) == 0) {
				fprintf(stderr, "Cell (%d , %d) is Empty \n",
					i + 1, j + 1);
			}
		}
	}

	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			int l;
			int value;
			int grid_num;
			value = grid_read_value(g, i, j);

			ex = 0;
			for (l = 0; l < 9; l++){
				if (grid_read_value(g, i, l) == value) ex++;
			}
			if (ex != 1) fprintf(stderr, "More than one instance of number %d in line %d \n",
				value, i + 1);

			ex = 0;
			for (l = 0; l < 9; l++){
				if (grid_read_value(g, l, j) == value) ex++;
			}
			if (ex != 1) fprintf(stderr, "More than one instance of number %d in column %d \n",
				value, l + 1);

			ex = 0;
			grid_num = GRID_NUM(i, j);
			for (i = (int)(grid_num / 3) * 3; i <= (int)(grid_num / 3) * 3 + 2; i++){
				for (j = (grid_num % 3) * 3; j <= (grid_num % 3) * 3 + 2; j++){
					if (grid_read_value(g, i, j) == value) ex++;
				}
			}
			if (ex != 1) fprintf(stderr, "More than one instance of number %d in grid %d \n",
				value, grid_num + 1);
		}
	}
}






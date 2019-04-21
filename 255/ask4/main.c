
#include "sudoku.h"
#include <string.h>

int main(int argc,char** argv)
{

        Grid_T sudoku,solved_sudoku;
        int unique;
        if(argc==1){

            sudoku=sudoku_read();
            sudoku_print(stderr,sudoku);
            sudoku_solve(sudoku);
            unique=sudoku_solution_is_unique(sudoku);
            fprintf(stderr,"\n\n");
            sudoku_print(stderr,solved_sudoku);
            sudoku_print_errors(solved_sudoku);
         }else if(argc==2){
                   if(argv[1]=="-c"){
                       sudoku=sudoku_read();
                       sudoku_print(stderr,sudoku);

                               if(sudoku_is_correct(sudoku)){
                                         fprintf(stderr,"\nsudoku is correct \n");
                                }else{
                                         fprintf(stderr,"sudoku is incorrect \n");
                                }
                        sudoku_print_errors(sudoku);
                     }else{
                        fprintf(stderr,"\nwrong parameter\n");
                     }
         }else{
         fprintf(stderr,"\nwrong paramater\n");
         }
}

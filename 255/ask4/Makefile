sudoku: grid.o sudoku.o main.o
	gcc -o sudoku grid.o sudoku.o main.o
grid.o: 
	gcc -ansi -pedantic -Werror -c grid.c
sudoku.o:
	gcc -ansi -pedantic -Werror -c sudoku.c
main.o:
	gcc -ansi -pedantic -Werror -c main.c 
clean: 
	rm -rf *.o
	rm sudoku


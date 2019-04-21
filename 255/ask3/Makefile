list: symtablelist.o testsymtab.o
	gcc -o list testsymtab.o symtablelist.o

hash: symtablehash.o testsymtab.o
	gcc -o hash testsymtab.o symtablehash.o

symtablelist.o: symtablelist.c symtable.h
	gcc -Wall -ansi -pedantic -c  symtablelist.c

symtablehash.o: symtablehash.c symtable.h
	gcc -c -Wall -ansi -pedantic symtablehash.c

testsymtab.o: testsymtab.c symtable.h
	gcc -Wall -ansi -pedantic -c testsymtab.c

clean:
	rm -rf *o 

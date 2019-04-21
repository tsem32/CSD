data3: createdata3.o
	gcc -ansi -Wall -pedantic -o createdata3.out createdata3.o
	./createdata3.out
	rm *.o
data6: createdata6.o
	gcc -ansi -Wall -pedantic -o createdata6.out createdata6.o
	./createdata6.out
	rm *.o
all: createdata3.o createdata6.o
	gcc -ansi -Wall -pedantic -o createdata3.out createdata3.o
	gcc -ansi -Wall -pedantic -o createdata6.out createdata6.o
	./createdata3.out
	./createdata6.out
	rm *.o
clean:
	rm *.out
	rm *.txt

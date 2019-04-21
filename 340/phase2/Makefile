all: phase1.l parser.y hashtable.c
	clear
	flex phase1.l 
	yacc -d parser.y
	gcc lex.yy.c y.tab.c hashtable.c


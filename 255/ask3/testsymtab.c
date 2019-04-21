


#include "symtable.h"
#define HASH_MULTIPLIER 65599


int main()
{
        size_t size;
        int x,i,removed,contains;
	SymTable_T table;
        table = SymTable_new();
	x = 1;
	for (i = 0; i < 1000; i++)
	{
		char *key = (char*)malloc(10);
		sprintf(key,"size%d", i);
		SymTable_put(table, key, &x);
	}
        size = SymTable_getLength(table);
	printf("\nSize is :%d \n", size);
	contains=SymTable_contains(table, "size40");

	if (contains == 1) printf("Contains key:size40\n");
	else printf("Doesnt contain key:size40\n");

        removed=SymTable_remove(table, "size40");

	if (removed == 1) printf("Sucessfuly Removed key:size40\n");
	else printf("Failed at removing size40\n");

	contains = SymTable_contains(table, "size40");

	if (contains == 1) printf("Contains key:size40\n");
	else printf("Doesnt contain key:size40\n");

        size=SymTable_getLength(table);
        printf("Size is :%d \n",size);

	SymTable_free(table);
	return 0;
}



#include "symtable.h"

#define HASH_MULTIPLIER 65599
#define TRUE 1
#define FALSE 0

#define TABLE_SIZE(table) size_val[table->size_index]

/* size values*/
size_t size_val[8] = { 509, 1021, 2053, 4093, 8191, 16381, 32771, 65521 };

int expand(SymTable_T oSymTable);
typedef struct node{
	/* Binding */
	void* value;
	const char*key;
	struct node* next;
} node;

struct SymTable{
	unsigned char size_index;/* Index of size_val (current size)*/
	size_t num_of_nodes;
	node** table;
};

/* Random-esque hash function that returns a size_t number*/
static unsigned int SymTable_hash(const char *pcKey)
{
	size_t ui;
	unsigned int uiHash = 0U;
	for (ui = 0U; pcKey[ui] != '\0'; ui++)
		uiHash = uiHash * HASH_MULTIPLIER + pcKey[ui];
	return uiHash;
}

/* Returns a new Empty SymTable_T(or SymTable*) */
SymTable_T SymTable_new(void)
{
        int i;
	SymTable_T newSymTable;
        newSymTable = (SymTable_T)malloc(sizeof(struct SymTable));
	if (newSymTable == NULL) { printf("Error at alocation"); exit(-1); }
	newSymTable->size_index = 0;
	newSymTable->num_of_nodes = 0;
	newSymTable->table = (node**)malloc(TABLE_SIZE(newSymTable) * sizeof(node*));
	/* initializes all table elements with NULL */
	for (i = 0; i < TABLE_SIZE(newSymTable); i++) newSymTable->table[i] = NULL;
	return newSymTable;
}

/* Deallocates  oSymTable ,if
oSymTable is NULL do nothing */
void SymTable_free(SymTable_T oSymTable)
{
        size_t i;
	if (oSymTable == NULL) return;
	for (i = 0; i<TABLE_SIZE(oSymTable); i++){
		node* iter;
                iter = oSymTable->table[i];
		while (iter != NULL){
			oSymTable->table[i] = iter->next;
			free(iter);
			iter = oSymTable->table[i];
		}
	}
	free(oSymTable->table);
	free(oSymTable);
}


/* Returns length of oSymTable.It is a checked runtime
error if oSymTable is NULL */
unsigned int SymTable_getLength(SymTable_T oSymTable)
{
	assert(oSymTable);
	return (oSymTable->num_of_nodes);
}


/* Puts the binding (pckey,pvValue) at oSymTable.Returns true if
succesfull else false.It is a checked runtime error if oSymTable
or pcKey is NULL */
int SymTable_put(SymTable_T oSymTable, const char *pcKey,
	const void *pvValue)
{
        node*temp;
        node*iter;
        size_t index;
	assert(pcKey&&oSymTable);
	index = SymTable_hash(pcKey) % TABLE_SIZE(oSymTable);

	temp = (node*)malloc(sizeof(node));
	if (temp == NULL) { return FALSE; }
	temp->key = pcKey;
	temp->value = (void*)pvValue;

	iter = oSymTable->table[index];/* table[index]
	is a 'head' pointer to a list */

	if (iter == NULL){
		oSymTable->table[index] = temp;
		temp->next = NULL;
		oSymTable->num_of_nodes++;
		if (oSymTable->num_of_nodes > TABLE_SIZE(oSymTable) &&
			oSymTable->size_index < 7){
			/*if size_index==7 size of table shouldnt change*/
			expand(oSymTable);
		}
		return TRUE;
	}
	if (strcmp(pcKey, iter->key) == 0) return FALSE;/*Checks lists' 'head' */
	while (iter->next != NULL){
		/* Moves to the last node and returns false 
		   if pcKey exists */
		if (strcmp(pcKey, iter->next->key) == 0) return FALSE;
		iter = iter->next;
	}
	/* Add to the end of list*/
	iter->next = temp;
	temp->next = NULL;
	oSymTable->num_of_nodes++;
	if (oSymTable->num_of_nodes > TABLE_SIZE(oSymTable) &&
		oSymTable->size_index < 7){
		expand(oSymTable);
	}
	return TRUE;
}


/*Removes the binding with key , pckey from oSymTable .Returns
true if sucessful else false.It is a checked runtime error if
oSymTable or pcKey is NULL */
int SymTable_remove(SymTable_T oSymTable, const char *pcKey)
{
        node*iter;
        size_t index;
	assert(oSymTable&& pcKey);
	index = SymTable_hash(pcKey) % TABLE_SIZE(oSymTable);
	if (oSymTable->table[index] == NULL) return FALSE;
	iter = oSymTable->table[index];
	if (strcmp(iter->key, pcKey) == 0){
		/*if pcKey is the first node of the 
		table[index list */
		oSymTable->table[index] = iter->next;
		oSymTable->num_of_nodes--;
		free(iter);
		return TRUE;
	}
	while (iter->next != NULL){
		if (strcmp(iter->next->key, pcKey) == 0){
			node* temp = iter->next;
			iter->next = iter->next->next;
			free(temp);
			oSymTable->num_of_nodes--;
			return TRUE;
		}
		iter = iter->next;
	}
	return FALSE;
}


/* Returns true if oSymTable contains the binding with key : pcKey
or else false.It is a checked runtime error if oSymTable or pcKey is
NULL */
int SymTable_contains(SymTable_T oSymTable, const char *pcKey)
{       
        size_t index;
        node*iter;
	assert(oSymTable&& pcKey);
	index = SymTable_hash(pcKey) % TABLE_SIZE(oSymTable);
	iter = oSymTable->table[index];
	while (iter != NULL){
		if (strcmp(iter->key, pcKey) == 0) return TRUE;
		iter = iter->next;
	}
	return FALSE;
}


/* Returns a void pointer to the value of the binding with key : pcKey
It is a checked runtime error if oSymTable or pcKey is NULL */
void *SymTable_get(SymTable_T oSymTable, const char *pcKey)
{
        size_t index;
        node*iter;
	assert(oSymTable&& pcKey);
	index = SymTable_hash(pcKey) % TABLE_SIZE(oSymTable);
	iter = oSymTable->table[index];
	while (iter != NULL){
		if (strcmp(iter->key, pcKey) == 0) return (void*)iter->value;
		iter = iter->next;
	}
	return NULL;
}


/* Applies function *pfApply to every binding in oSymTable
It is a checked runtime error if oSymTable or pfApply is NULL */
void SymTable_map(SymTable_T oSymTable,
	void(*pfApply)(const char *pcKey, void *pvValue, void *pvExtra),
	const void *pvExtra)
{
        size_t i;
	assert(oSymTable&&pfApply);
	for (i = 0; i < TABLE_SIZE(oSymTable); i++){
		node*iter;
                iter = oSymTable->table[i];
		while (iter != NULL){
			pfApply(iter->key, iter->value, (void*)pvExtra);
			iter = iter->next;
		}
	}
}


/* Reallocates oSymTable and compies the old contents 
   to the new table.Returns true if sucessfule else
   false.*/
int expand(SymTable_T oSymTable)
{
	int i;
	node** newTable;
        newTable = (node**)malloc(sizeof(node*)*TABLE_SIZE(oSymTable));
	if (oSymTable->size_index == 0||newTable==NULL) return FALSE;
	for (i = 0; i <size_val[oSymTable->size_index - 1]; i++){
		/* Copies old table to newTable */
		newTable[i] = oSymTable->table[i];
	}
	for (i = size_val[oSymTable->size_index - 1];
		i < TABLE_SIZE(oSymTable); i++)
	{
		/*Everything else is initialized with NULL */
		newTable[i] == NULL;
	}
	oSymTable->table = newTable;
	return TRUE;
}


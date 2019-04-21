


#include "symtable.h"
#define TRUE 1
#define FALSE 0

typedef struct node{
	/* Binding */
	void* value;
	const char*key;
	struct node* next;
} node;

struct SymTable{
	node* head;
	int length;
};



/* Returns a new Empty SymTable_T(or SymTable*) */
SymTable_T SymTable_new(void)
{
	SymTable_T newSymTable=(SymTable_T)malloc(sizeof(struct SymTable));
	if (newSymTable == NULL) { printf("Error at alocation"); exit(-1); }
	if(newSymTable!=NULL) newSymTable->head=NULL;
	newSymTable->length = 0;
	return newSymTable;
}

/* Deallocates  oSymTable ,if
 oSymTable is NULL do nothing */
void SymTable_free(SymTable_T oSymTable)
{
    node* iter;
    if(oSymTable==NULL) return;
    iter=oSymTable->head;
	while(iter!=NULL){
		node* temp=iter;
		iter=iter->next;
		free(temp);
	}
	free(oSymTable);
}

/* Returns length of oSymTable.It is a checked runtime
 error if oSymTable is NULL */
unsigned int SymTable_getLength(SymTable_T oSymTable)
{
	assert(oSymTable);
	return oSymTable->length;
}


/* Puts the binding (pckey,pvValue) at oSymTable.Returns true if
succesfull else false.It is a checked runtime error if oSymTable
or pcKey is NULL */
int SymTable_put(SymTable_T oSymTable, const char *pcKey,
                 const void *pvValue)
{
        node*temp;
        node*iter;
	assert(pcKey&&oSymTable);
	/* Allocates and initializes */
        temp=(node*)malloc(sizeof(node));
	if(temp==NULL) { return FALSE;}
	temp->key=pcKey;
	temp->value=(void*)pvValue;
	iter = oSymTable->head;
	if(oSymTable->head==NULL){
		oSymTable->head=temp;
		temp->next=NULL;
		oSymTable->length++;
		return TRUE;
	}

	if (strcmp(pcKey, iter->key) == 0) return FALSE; 
	while(iter->next!=NULL){
		/* Go to the last node */
		if(strcmp(pcKey,iter->next->key)==0) return FALSE;
		iter=iter->next;
	}
	iter->next=temp;
	temp->next=NULL;
	oSymTable->length++;
	return TRUE;
}


/*Removes the binding with key , pckey from oSymTable .Returns
true if sucessful else false.It is a checked runtime error if
oSymTable or pcKey is NULL */
int SymTable_remove(SymTable_T oSymTable, const char *pcKey)
{
        node*iter;
	assert(oSymTable&& pcKey);
	if(oSymTable->head==NULL) return FALSE;
        iter=oSymTable->head;
	/*Checks for the list's head first and then in a loop for 
	  every other node(binding)*/
	if(strcmp(iter->key,pcKey)==0){
		oSymTable->head = iter->next;
		oSymTable->length--;
		free(iter);
		return TRUE;
	}
	while(iter->next!=NULL){
		if(strcmp(iter->next->key,pcKey)==0){
			node* temp;
                        temp=iter->next;
			iter->next=iter->next->next;
			free(temp);
			oSymTable->length--;
			return TRUE;
		}
		iter=iter->next;
	}
	return FALSE;
}

/* Returns true if oSymTable contains the binding with key : pcKey
or else false.It is a checked runtime error if oSymTable or pcKey is
NULL */
int SymTable_contains(SymTable_T oSymTable, const char *pcKey)
{
        node*iter;
	assert(oSymTable&& pcKey);
        iter=oSymTable->head;
	while(iter!=NULL){
		if(strcmp(iter->key,pcKey)==0) return TRUE;
		iter=iter->next;
	}
	return FALSE;
}

/* Returns a void pointer to the value of the binding with key : pcKey
It is a checked runtime error if oSymTable or pcKey is NULL */
void *SymTable_get(SymTable_T oSymTable, const char *pcKey)
{
        node* iter;
	assert(oSymTable&& pcKey);
	iter = oSymTable->head;
	while (iter != NULL){
		if (strcmp(iter->key, pcKey) == 0) return (void*)iter->value;
		iter = iter->next;
	}
	return NULL;
}

/* Applies function *pfApply to every binding in oSymTable
It is a checked runtime error if oSymTable or pfApply is NULL */
void SymTable_map(SymTable_T oSymTable,
                  void (*pfApply)(const char *pcKey, void *pvValue, void *pvExtra),
                  const void *pvExtra)
{
        node*iter;
	assert(oSymTable&&pfApply);
        iter=oSymTable->head;
	while(iter!=NULL){
		pfApply(iter->key,iter->value,(void*)pvExtra);
		iter=iter->next;
	}
}

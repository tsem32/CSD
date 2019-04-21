
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#ifndef HEADER
typedef struct SymTable* SymTable_T;

/* Returns a new Empty SymTable_T(or SymTable*) */
SymTable_T SymTable_new(void);

/* Deallocates oSymTable ,if 
   oSymTable is NULL do nothing */
void SymTable_free(SymTable_T oSymTable);

/* Returns length of oSymTable.It is a checked runtime
   error if oSymTable is NULL */
unsigned int SymTable_getLength(SymTable_T oSymTable);


/* Puts the binding (pckey,pvValue) at oSymTable.Returns true if 
   succesfull else false.It is a checked runtime error if oSymTable
   or pcKey is NULL */
int SymTable_put(SymTable_T oSymTable, const char *pcKey,
                 const void *pvValue);


/*Removes the binding with key , pckey from oSymTable .Returns 
  true if sucessful else false.It is a checked runtime error if
  oSymTable or pcKey is NULL */
int SymTable_remove(SymTable_T oSymTable, const char *pcKey);


/* Returns true if oSymTable contains the binding with key : pcKey
   or else false.It is a checked runtime error if oSymTable or pcKey is 
   NULL */
int SymTable_contains(SymTable_T oSymTable, const char *pcKey);


/* Returns a void pointer to the value of the binding with key : pcKey 
  It is a checked runtime error if oSymTable or pcKey is NULL */
void *SymTable_get(SymTable_T oSymTable, const char *pcKey);


/* Applies function *pfApply to every binding in oSymTable
   It is a checked runtime error if oSymTable or pfApply is NULL */
void SymTable_map(SymTable_T oSymTable,
                  void (*pfApply)(const char *pcKey, void *pvValue, void *pvExtra),
                  const void *pvExtra);

#define HEADER
#endif

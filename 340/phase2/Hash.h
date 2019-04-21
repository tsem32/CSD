#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum  {
GLOBAL=0, LCAL=1, FORMAL=2,
USERFUNC=3, LIBFUNC=4
}SymbolTableType;

static char* enumStrings[] = { "GLOBAL", "LOCAL","FORMAL", "USERFUNC", "LIBFUNC"};

typedef struct ScopeList ScopeList;
typedef struct Hash_T Hash_T;
int HashFunc(char *Name);
void Hash_Put(char *var,int line_no,int scope,SymbolTableType type,int is_function);
void Hash_Print();
void has_init();
int check_lib(char * id);
SymbolTableType  set_type( int scope);
void print_lists();
int ez_active(char *Name,int exists);

#include "symtable.h"
#define EXPAND_SIZE 1024
#define CURR_SIZE (total*sizeof(quad))
#define NEW_SIZE (EXPAND_SIZE*sizeof(quad)+CURR_SIZE)

unsigned total;
unsigned int currQuad;


typedef enum expr_t {
	      var_e,
	      tableitem_e,
	      
	      programmfunc_e,
	      libraryfunc_e,
	      
	      arithexpr_e,
	      boolexpr_e,
	      assgnexpr_e,
	      newtable_e,
	      
	      constint_e,
	      constdouble_e,
	      constbool_e,
	      conststring_e,
	      
	      nil_e
}expr_t;

typedef enum iopcode{ 	
			assign, add, sub,
			mul, divv, mod,
			uminus, and, or, 
			not, if_eq, if_noteq,
			if_lesseq, if_geatereq, if_less, if__eq,
			if_greater, jump, call,
			param, ret, getretval,
			funcstart, funcend, tablecreate,
			tablegetelem, tablesetelem
 }iopcode;

 typedef struct intList{
	int currentquad;
	char *str;
	struct intList *next;
}intlist;
 
 typedef struct expr{ 
	     expr_t type;
	     SymbolNode* sym;
	     struct expr* index;
	     union{
	      int intConst;		//Nums
	      double doubleConst;	
	      char* strConst;	//Strings and ids
	      unsigned int boolConst; 	//0 if false,1 if true
	     }uni;
	     struct expr* next;
		 
		intlist *FalseHead;
		intlist *TrueHead;
} expr;
 
typedef struct quad{ 
		 iopcode op;
	     expr* result;
	     expr* arg1;
	     expr* arg2;
	     unsigned int label;	//JUMPTARGET
	     unsigned int line;
} quad;

 quad* quads;

typedef struct stmt{
	intlist *breaklist;
	intlist *continuelist;
	intlist *falselist;
	intlist *truelist;
}Stmt;



/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
int functionoffsets[100] = {0}, offset = 0, Argoffset=0;
char *functionNames[100], *ScopeSpace;
intlist *BreakHead = NULL, *ContinueHead = NULL;
intlist *Falsehead = NULL, *Truehead = NULL,*tmp = NULL;
int i=0, normCall = 0, paramCounter=0,ErrorFlag=0, memberFlag=0;
int loopstart[100],loopindex[100] = {0}, Qindex=0, forstart=0;
expr *temp=NULL,*tmpCall=NULL;
quad *tmpquad[100], *fortmpquad=NULL;
SymbolNode  *TmpNode;
int tcounter;

/*

char* newtempname();
void resettemp();
expr* newexpr(expr_t t);
expr* lvalue_expr(SymbolNode* sym);
expr* ConstDouble_exp(double Num);
expr* ConstInt_exp(int Num);
expr* ConstString_exp(char *str);
expr* ConstBool_exp(int Bool);
expr* ConstNil_exp();
void expand();
quad *insertQuad(iopcode op, expr *Result,expr *Arg1,expr *Arg2, unsigned int label, unsigned int line);
expr *insertExpr(iopcode op, expr *Arg1,expr *Arg2, unsigned int line, expr_t type);
expr *insert_tableelist(expr* elist,int line);
intlist *CreateIntList(int quad,intlist *head);
void CreateList(char * x, expr **head);
intlist *DeleteIntList(int DelQuad, intlist *head);
intlist *MergeIntList(intlist *head1, intlist *head2);
void backpatch(intlist *head, int target);
void printExpr(expr *e);
void PrintQuads();
expr *emit_iftableitem(expr *e,int line);
expr *table_emit(expr *arg1,expr *arg2,int line);
expr* reverse_list(expr *head);
*/

char* newtempname()
{
    char tmp[20], str[20];
    strcpy (tmp,"_t");
    snprintf( str,20,"%d",tcounter++ );
    strcat (tmp, str);
    return strdup(tmp);

}

void resettemp()
{
  tcounter = 0;
}

expr* newexpr(expr_t t)
{
	expr* e=(expr*)malloc(sizeof(expr));
	memset(e,0,sizeof(expr));
	e->type =t;
	
	return e;
}

SymbolNode *newtemp(char *name)
{

  SymbolNode *search = Scope_NameLookup(ScopeArray,scope, name);
  SymbolNode *res=NULL;

  if(search)
  {

	    return search;
}
  else
  {


	    SymbolNode *Sym = InsertToSymTable(oSymTable, ScopeArray, name, LOKAL, scope,
					      -666,functionoffsets[FunctionFlag],ScopeSpace,-1);

	   res = Scope_NameLookup(ScopeArray,scope, name);



	    return res;
  }


}


expr* lvalue_expr(SymbolNode* sym){
	struct expr* newexpr=malloc(sizeof(struct expr));
	newexpr->sym=sym;
	newexpr->uni.strConst=strdup(sym->name);
	
	if(sym->type== USERFUNC)
	    newexpr->type=programmfunc_e;
	else if(sym->type== LIBFUNC)
	    newexpr->type=libraryfunc_e;
	else
	    newexpr->type=var_e;
		
	newexpr->next=NULL;
	newexpr->index=NULL;
	newexpr->FalseHead = NULL;
	newexpr->TrueHead = NULL;
	
	return newexpr;
}

expr* ConstDouble_exp(double Num)
{
	expr* newexpr = malloc (sizeof(expr) );
	newexpr->type = constdouble_e;
	newexpr->uni.doubleConst = Num;

	return newexpr;
}


expr* ConstInt_exp(int Num)
{
	expr* newexpr = malloc (sizeof(expr) );
	newexpr->type = constint_e;
	newexpr->uni.intConst = Num;

	return newexpr;
}


expr* ConstString_exp(char *str)
{
	expr* newexpr = malloc (sizeof(expr) );
	newexpr->type = conststring_e;
	newexpr->uni.strConst = strdup(str);

	return newexpr;
}


expr* ConstBool_exp(int Bool)
{
	expr* newexpr = malloc (sizeof(expr) );
	newexpr->type = constbool_e;
	newexpr->uni.boolConst = Bool;

	return newexpr;
}
expr* ConstNil_exp()
{
	expr *newexpr = malloc (sizeof(expr));
	newexpr->type = nil_e;

	return newexpr;
}

void expand(){
	quad *newquads=malloc(NEW_SIZE);

	memcpy(newquads,quads,CURR_SIZE);
	free(quads);

	quads= newquads;
	total=total+EXPAND_SIZE;
}


/*Inserts a new quad*/
quad *insertQuad(iopcode op, expr *Result,expr *Arg1,expr *Arg2, unsigned int label, unsigned int line)
{
	if(currQuad==total)
	      expand();

	quad *newquad=quads+currQuad++;
	newquad->op=op;
	newquad->result=Result;
	newquad->arg1=Arg1;
	newquad->arg2=Arg2;
	newquad->line=currQuad;
	newquad->label=label;

	return newquad;
}

/*Inserts a quad with a hidden variable as a result*/
expr *insertExpr(iopcode op, expr *Arg1,expr *Arg2, unsigned int line, expr_t type)
{
	expr *result = NULL;
	result=(expr *)malloc(sizeof(expr));
	char *name = newtempname();

	result=newexpr(type);
	result->uni.strConst=strdup(name);
   	result->sym=newtemp(name); //prepei na to eisagoume sto symtable

	insertQuad(op,result,Arg1,Arg2,-1,line);

	return result;
}


expr *insert_tableelist(expr* elist,int line)
{
	expr* t=(expr*)malloc(sizeof(expr));
	t->type =newtable_e;
	expr* tmp;
	int j=0;
	char* tmpname=strdup(newtempname());
	t->sym=InsertToSymTable(oSymTable,ScopeArray,tmpname,
				LOKAL,scope,line,offset, "Programm Variables",-1);
	t->uni.strConst=tmpname;
	insertQuad(tablecreate,t,NULL,NULL,-1,line);
   	tmp = elist;
   	while(tmp!=NULL){
      	insertQuad(tablesetelem,t,ConstInt_exp(j),tmp,-1,line);
      	tmp=tmp->next;
      	j++;
   	}
   	return t;
}

/*Creates a new struct IntList*/
intlist *CreateIntList(int quad,intlist *head)
{

	intlist *tmp=(intlist *)malloc(sizeof(intlist));

	tmp->currentquad=quad;
	tmp->next=head;

	return tmp;
}

expr* reverse_list(expr *head)
{
  expr *temp;
  if(head==NULL)
    return NULL;
  if (head->next == NULL) 
    temp = head;
  else {
    temp = reverse_list(head->next);
    head->next->next = head;
    head->next = NULL;
  }
 
  return temp;
}

intlist *DeleteIntList(int DelQuad, intlist *head)
{

	intlist *tmp = head, *prev = NULL;
	while(tmp){
		//if the delete node is found
		if (tmp->currentquad == DelQuad){
			if (tmp == head){
				return head->next;
			}
			else{
				prev->next = tmp->next;
				//free(tmp);
				return head;
			}
		}
		prev = tmp;
		tmp=tmp->next;
	}
	return head;
}

intlist *MergeIntList(intlist *head1, intlist *head2)
{

	assert(head1);

	intlist *NewList = head1;

	if (!head1) return head2;
	else if (!head2) return head1;

	while(head1->next){
		head1 = head1->next;
	}
	head1->next = head2;

	return NewList;
}

void backpatch(intlist *head, int target)
{
	intlist *tmp=head;
	int thesh;

	while( (tmp) && (tmp->currentquad != -666) ){
	      	thesh=tmp->currentquad;
	      	(quads+thesh)->label=target;

		head = tmp->next;//pseudo delete of head (pop)
		free(tmp);//delete top of stack
	    tmp=head; // next node pls
	}

	if (tmp){
		head = tmp->next;
		free(tmp);
	}


}



void printExpr(expr *e)
{
	switch(e->type){
	  case var_e:
		printf("%s\t", e->uni.strConst);
		break;
	  case tableitem_e:
		printf("%s\t", e->uni.strConst);
		break;
	  case programmfunc_e:
		printf("%s\t", e->uni.strConst);
		break;
	  case libraryfunc_e:
		printf("%s\t", e->uni.strConst);
		break;
	  case arithexpr_e:
		printf("%s\t", e->uni.strConst);
		break;
	  case boolexpr_e:
		printf("%s\t", e->uni.strConst);
		break;
	  case assgnexpr_e:
		printf("%s\t", e->uni.strConst);
		break;
	  case newtable_e:
		printf("%s\t", e->uni.strConst);
		break;
	  case constint_e:
		printf("%d\t",e->uni.intConst);
		break;
	  case constdouble_e:
		printf("%.2lf\t",e->uni.doubleConst);
		break;
	  case constbool_e:
		if(e->uni.boolConst)
		      printf("TRUE\t");
		else
		      printf("FALSE\t");
		break;
	  case conststring_e:
		printf("%s\t",e->uni.strConst);
		break;
	  case nil_e:
		printf("null\t");
		break;
	  default:
		printf("***\t");
	}
}
void PrintQuads()
{


	int j=0;
	quad *tmp = quads;

	while(j < currQuad){

		printf("%d:  ",j);
		tmp= quads+j++;
		switch(tmp->op)
		{
			case assign:
				printf("ASSIGN\t");
				break;
			case add:
				printf("ADD\t");
				break;
			case sub:
				printf("SUB\t");
				break;
			case mul:
				printf("MUL\t");
				break;
			case divv:
				printf("DIV\t");
				break;
			case mod:
				printf("MOD\t");
				break;
			case and:
				printf("AND\t");
				break;
			case or:
				printf("OR\t");
				break;
			case not:
				printf("NOT\t");
				break;
			case jump:
				printf("JUMP\t");
				break;
			case if_eq:
				printf("IF_EQ\t");
				break;
			case if_noteq:
				printf("IF_NOTEQ\t");
				break;
			case if_greater:
				printf("IF_GREATER\t");
				break;
			case if_lesseq:
				printf("IF_LESSEQ\t");
				break;
			case if_geatereq:
				printf("IF_GREATEREQ\t");
				break;
			case if_less:
				printf("IF_LESS\t");
				break;
			case if__eq:
				printf("IF_EQ\t");
				break;
			case call:
				printf("CALL\t");
				break;
			case getretval:
				printf("GETRETVAL\t");
				break;
			case funcstart:
				printf("FUNCSTART\t");
				break;
			case funcend:
				printf("FUNCEND\t");
				break;
			case tablecreate:
				printf("TABLECREATE\t");
				break;
			case tablegetelem:
				printf("TABLEGETELEM\t");
				break;
			case tablesetelem:
				printf("TABLESETELEM\t");
				break;
			case ret:
				printf("RETURN\t");
				break;
			case uminus:
				printf("UMINUS\t");
				break;
			case param:
				printf("PARAM\t");
				break;
			default:
				printf("***\t");
		}
		if(tmp->result)
		      printExpr(tmp->result);
		if(tmp->arg1)
		      printExpr(tmp->arg1);
		if(tmp->arg2)
		      printExpr(tmp->arg2);

		if(tmp->label != -1)
		      printf("%d",tmp->label);
		printf("\n");
	}
}


expr *emit_iftableitem(expr *e,int line)
{
   expr *result;

   if(e->type != tableitem_e){

      return(e);
   }
   else{
      char *name=newtempname();
      result = newexpr(e->type);
      result->sym = newtemp(name);
      result->uni.strConst=strdup(result->sym->name);
      
      insertQuad(tablegetelem,result,e,e->index,-1,line);
      return(result);
   }

   return NULL;
}
expr *table_emit(expr *arg1,expr *arg2,int line)
{
      expr *new = NULL;
      expr *tmp = NULL;
      
     tmp = emit_iftableitem(arg1,line);

      new = newexpr(tableitem_e);
      new->sym = tmp->sym;
      new->uni.strConst=strdup(tmp->sym->name);
      new->index = arg2;
      return new;
}


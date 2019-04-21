%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Hash.h"
extern int yylex(void);
extern int yylineno;
extern char *yytext;
int scope=0;
int counter=0;
int funcdefflag=0;
int funcall=0;
int tempexists=0;
int loop=0;
%}

%error-verbose
%start program
%union
{
	int intval;
	char* strval;
	float realval;
}
%token <intval> INTEGER;
%token <strval> STRING;
%token <strval> WHILE FOR IF ELSE FUNCTION RETURN BREAK CONTINUE AND OR NOT LOCAL TRUE FALSE NIL PLUS MINUS MUL MOD DIV EQUALS N_EQL PLUSPLUS MINUSMINUS 
%token <strval> ID;
%token <strval> ASSIGN;
%token <realval> REALNUMBER;
%token <strval> GRTR_EQL LESS_EQL GRTR LESS L_BRACKET R_BRACKET L_BRACE R_BRACE L_PAR R_PAR COMMA SEMCOL COLON DOT DBL_DOT WRONG_DEFINITION GLOB

%type <strval> stmt 
%type <intval> expr
%type <strval> ifstmt whilestmt forstmt returnstmt block funcdef
%type <strval> assignexpr term
%type <strval> lvalue primary call objectdef const member
%type <strval> elist callsuffix normcall methodcall indexed indexedelem

%left ASSIGN
%left OR
%left AND
%nonassoc EQUALS N_EQL
%nonassoc GRTR GRTR_EQL LESS LESS_EQL
%left PLUS MINUS
%left  MUL DIV MOD
%left NOT PLUSPLUS MINUSMINUS
%left DOT DBL_DOT
%left L_BRACKET R_BRACKET
%left L_PAR R_PAR



%%
program: stmt program 
	|	{
			printf("Program\n");
		}
        ;
stmt:	 expr SEMCOL {printf("Expression \n");}
	| ifstmt {printf("ifstatement\n");}
	| whilestmt {printf("whilestatement\n");}
	| forstmt {printf("forstatement\n");}
	| returnstmt {printf("retstatement\n");}
	| BREAK  SEMCOL {if(loop==0)printf("Break is not contained in active loop . line: %d\n",yylineno); printf("break\n");}
	| CONTINUE SEMCOL {if(loop==0)printf("Continue is not contained in active loop . line: %d\n",yylineno); printf("continue\n");}
	| block {printf("block\n");}
	| funcdef {printf("funcdef\n");funcdefflag=0;}
	|SEMCOL
;
expr: assignexpr {if(funcall==1){
				printf("Syntax Error: In line %d .Trying to make an lvalue action to function[invalid action : rvalue ASSIGN].\n",yylineno);
				funcall=0;
			} printf("assign expression\n");funcall=0;}
        | expr PLUS expr {printf("expression  + expression \n");}
	| expr MINUS expr {printf("expression - expression \n");}
	| expr MUL expr { printf("expression * expression  \n");}
	| expr DIV expr {printf("expression / expression  \n");}
	| expr MOD expr {printf("expression % expression \n");}
	| expr GRTR expr {printf("expression > expression %d>%d \n");}
	| expr GRTR_EQL expr	{printf("expression >= expression  \n");}
	| expr LESS expr	{printf("expression  < expression  \n");}
	| expr LESS_EQL expr	{printf("expression <= expression  \n");}
	| expr EQUALS expr		{printf("expression == expression \n");}
	| expr N_EQL expr	{printf("expression != expression  \n");}
	| expr AND expr		{printf("expression && expression  \n");}
	| expr OR expr		{printf("expression || expression \n");}

	| term {printf("term\n");}
	;
term: L_PAR expr R_PAR {printf("(expr)\n");}
	| MINUS expr {if(funcall==1){
                                printf("Syntax Error: In line %d .Trying to make an lvalue action to function[invalid action : rvalue ASSIGN].\n",yylineno);
                                funcall=0;
                        } printf("-expr\n");}
	| NOT expr {if(funcall==1){
                                printf("Syntax Error: In line %d .Trying to make an lvalue action to function[invalid action : rvalue ASSIGN].\n",yylineno);
                                funcall=0;
                        } printf("oxiexpr\n");}
	| PLUSPLUS lvalue { if(funcall==1){
                                printf("Syntax Error: In line %d .Trying to make an lvalue action to function[invalid action : rvalue ASSIGN].\n",yylineno);
                                funcall=0;
                        }printf("++lvalue\n");}
	| lvalue PLUSPLUS {if(funcall==1){
                                printf("Syntax Error: In line %d .Trying to make an lvalue action to function[invalid action : rvalue ASSIGN].\n",yylineno);
                                funcall=0;
                        } printf("lvalue++\n");}
	| MINUSMINUS lvalue {if(funcall==1){
                                printf("Syntax Error: In line %d .Trying to make an lvalue action to function[invalid action : rvalue ASSIGN].\n",yylineno);
                                funcall=0;
                        } printf("--lvalue\n");}
	| lvalue MINUSMINUS {if(funcall==1){
                                printf("Syntax Error: In line %d .Trying to make an lvalue action to function[invalid action : rvalue ASSIGN].\n",yylineno);
                                funcall=0;
                        } printf("lvalue--\n");}
	| primary { printf("termprimary\n");}
	;
assignexpr: lvalue ASSIGN expr {printf("lvalue=expr\n");};
primary: lvalue {printf("lvalue\n");}
	| call {printf("call\n");}
	| objectdef {printf("objectdef\n");}
	| L_PAR funcdef R_PAR {printf("(funcdef)\n");}
	| const {printf("const\n");}
	;
lvalue: ID {printf("identifier\n"); 
             int i =0;
             i= Exists(yytext,scope,set_type(scope));
	     funcall=0;
             if(i==-1){  //An den uparxei to id dhlwmeno sto hashtable,valto
                Hash_Put(yytext,yylineno,scope,set_type(scope),0);
             }

              
            else if(is_func(yytext)!=-1 ){ //An uparxei sto hashtable,kai einai sunarthsh
                if(ez_active(yytext,scope)==0){ //Kai an den einai uparxei san energh metavlhth
                 funcall=1; }
             }
               else  if((i!=scope && i!=0)  && funcdefflag!=0 ){ 
//An auto pou koitaw den einai sto idio scope me auto pou vrhka sto symbol table 
//KAI h kataxwrhsh tou symbol tble DEN einai global
//KAI den paw na kanw dhlwsh sunarthshs 
                                           if(is_func(yytext)!=i){                    
                 		 printf("Variable %s not accessible in line %d\n",yytext,yylineno);
		     }
                }

              
             else if(i==scope && is_func(yytext)==1 && funcdefflag==1)
	  	{printf("Trying to redeclare variable that is function in same scope in line %d \n",yylineno);funcdefflag=0;
	          
             } 
             
        }
	|GLOB ID {
		funcall=0;
		if(is_func(yytext)>=0){
			funcall=1;
		}
		if(Global_Exists(yytext)==-1){
			printf("Variable %s not globally declared in line : %d \n",yytext,yylineno);
		}
	}
	|LOCAL ID{tempexists=Exists(yytext,scope,set_type(scope));funcall=0;
		if(check_lib(yytext)==1){   //Des an einai sunarthsh bibliothikis

			printf("Error in line: %d . Shadowing not permitted \n");
		
		}else if(Local_Exists(yytext,scope)==-1 || ez_active(yytext,tempexists)==0){ //An den uparxei local metvlhth me to idio onoma H den uparxei active metavlhth me to idio onoma	
                      if(scope==0){
			   Hash_Put(yytext,yylineno,scope,GLOBAL,0);
			}else{  
                           Hash_Put(yytext,yylineno,scope,LCAL,0);
			}		
			
		}
                else if(Local_Exists(yytext,scope)==1 && ez_active(yytext,tempexists)!=0){ //An uparxei hdh h metavlhth sto idio scope pou vriskomai,kai einai energh
                    printf("Local variable %s redefinition in line %d: \n",yytext,yylineno);
                  }
	
	printf("|LOCAL ID\n");
	}

		
	| member {printf("member\n");}
	;
member: lvalue DOT ID {printf("lvalue.identifier\n");}
	| lvalue L_BRACKET expr R_BRACKET {printf("lvalue expr\n");}
	| call DOT ID {printf("call.identifier\n");}
	| call L_BRACKET expr R_BRACKET {printf("call expr\n");}
	;
call: call L_PAR elist R_PAR {printf("(elist)\n");}
	|lvalue callsuffix {printf("lvaluecallsuffix\n");}
	|L_PAR funcdef R_PAR L_PAR elist R_PAR {printf("(funcdef)(elist)\n");}
	;
callsuffix: normcall {printf("normcall\n");funcall=1;}
	| methodcall {printf("methodcall\n");}
	;
normcall: L_PAR elist R_PAR {printf("(elist)\n");};
methodcall: DBL_DOT ID L_PAR elist R_PAR {printf("method call\n");};
elist:	expr			{printf("Expr\n");}
	| elist COMMA expr	{printf("Expr,..,Expr\n");} 
	|			{printf("Empty Elist\n");}
	;
objectdef:	L_BRACKET elist R_BRACKET	{printf(" [ Elist ] \n");}
	| L_BRACKET indexed R_BRACKET		{printf(" [ Indexed ] \n");}
	;
indexed:	indexedelem		{printf("Idexedelem\n");}
	|indexed COMMA indexedelem	{printf("indexedelem , indexedelem\n");}
	;

indexedelem:	L_BRACE expr COLON expr R_BRACE	{printf("{ Expr : Expr }\n");};
temp_id: ID{}
	|{printf("empty\n");}
;
temp_st: temp_st stmt {}
	|{}
;
block: L_BRACE {scope++; }temp_st R_BRACE{Hide(scope);scope--; } {printf("block\n");};
funcdef: FUNCTION temp_id{funcdefflag=1;funcall=1;
                 if(check_lib(yytext)==1){
			printf("Shadowing of library function %s in line: %d \n",yytext,yylineno);
		 }else if(Exists(yytext,scope,set_type(scope))==scope){
			printf("Variable %s redefinition in line: %d \n",yytext,yylineno);
		 }else{
			Hash_Put(yytext,yylineno,scope,USERFUNC,1);
		}	
		} L_PAR idlist R_PAR block {printf("function def \n");};
const:	INTEGER			{printf("|NUMBER %s\n",yytext);} 
	| REALNUMBER		{printf("|REALNUMBER %s\n",yytext);}
	| STRING		{printf("|STRING\n");}
	| NIL			{printf("|NIL\n");}
	| TRUE			{printf("|TRUE\n");}
	| FALSE			{printf("|FALSE\n");}
	;
idlist:ID {if(check_formal(yytext,scope)==1){
		printf("Error: Formal argument redefinition in line : %d \n",yylineno);
	   }else{
		Hash_Put(yytext,yylineno,scope+1,FORMAL,0);
           }	
	printf("idlist ID\n");}
	|idlist COMMA ID {
	if(check_formal(yytext,scope)==1){
                printf("Error: Formal argument redefinition in line : %d \n",yylineno);
           }else{
                Hash_Put(yytext,yylineno,scope+1,FORMAL,0);
           }

	printf("idlist comma \n");}
	|{;}
;
ifstmt: IF L_PAR expr R_PAR stmt{printf("if()\n");}
	| ELSE stmt {printf("ifelse stmt \n");}
	;
whilestmt: WHILE L_PAR{loop++;} expr R_PAR stmt {loop--;printf("while()stmt\n");};
forstmt: FOR L_PAR{loop++;} elist SEMCOL expr SEMCOL elist R_PAR stmt {loop--;printf("|FOR (ELIST;EXPR;ELIST)STMT\n");};
returnstmt: RETURN SEMCOL {if(funcdefflag==0)printf("Error in line:%d .Return statement not inside func declaration \n",yylineno);printf("return;\n");}
	|RETURN expr SEMCOL {if(funcdefflag==0)printf("Error in line:%d .Return statement not inside func declaration \n",yylineno); printf("RETURN EXPR;\n");};


%%
int yyerror (const char * YaccProvidedMessage)
{	
	if ((strstr(YaccProvidedMessage,"$end")))
		printf("Unexpected reach of the EOF.\n");
	else
		printf("%s -- in line %d , token %s \n ",YaccProvidedMessage,yylineno,yytext);
	return 0;
}


int main(int argc,char **argv)
{
	hash_init();
	yyparse();
	Hash_Print();
	return 0;
}

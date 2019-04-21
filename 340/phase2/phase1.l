
%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
extern YYSTYPE yylval;
int i=0;
int tokens=0;
char *str=NULL;
char *com="MULTILINE COMMENT";
typedef struct node {
    int line;   //keeps the line of the token found
    int token_no; //keeps the token number
    char *c_value; //keeps the value of the token(yytext)
    char *type;  //keeps the type of the token(id,operator,keyword,etc)
    int is_keyword; //keeps TRUE if type is keyword and FALSE if not
    struct node * next; //pointer to the next node of the list
} alpha_token_t;

//declarations//
void insert(int line,int token_no,char *c_value,char *type,int is_keyword,alpha_token_t *next);
void print(alpha_token_t *head);
int check_if_keyword(char *); //returns TRUE if parameter is type of keyword and FALSE if not

%}
%option noyywrap
%option yylineno
ID [a-zA-Z_][a-zA-Z_0-9]* 

intconst (0[xX][0-9a-fA-F]+)|[0-9]+

realconst ([0-9]+)\.([0-9](e|E)?[0-9]*)

whitespace [\r\n \t\v]

commentline "//".*

wrong_identifier [0-9][a-zA-Z_0-9]*



%x comment1 string plus
%%
"for"		{return FOR;}
"return"	{return RETURN;}
"continue"	{return CONTINUE;}
"break"		{return BREAK;}
"while"		{return WHILE;} 
"function" 	{return FUNCTION;}
"="             {return ASSIGN;}
"+"             {return PLUS;}
"-"             {return MINUS;}
"*"             {return MUL;}
"/"             {return DIV;}
"%"             {return MOD;}
"=="            {return EQUALS;}
"!="            {return N_EQL;}
"++"            {return PLUSPLUS;}
"--"            {return MINUSMINUS;}
">"             {return GRTR;}
"<"             {return LESS;}
">="            {return GRTR_EQL;}
"<="            {return LESS_EQL;}
"if"		{return IF;}
"local"		{return LOCAL;}
"else"		{return ELSE;}
"{"             {return L_BRACE;}
"}"             {return R_BRACE;}
"["             {return L_BRACKET;}
"]"             {return R_BRACKET;}
"("             {return L_PAR;}
")"             {return R_PAR;}
";"             {return SEMCOL;}
","             {return COMMA;}
":"             {return COLON;}
"."             {return DOT;}
".."            {return DBL_DOT;}
"::"		{return GLOB;}
{ID} {yylval.strval=strdup(yytext);return ID;}
{intconst} {yylval.intval = atoi(yytext);return INTEGER; }
{whitespace} {;}
{realconst} {yylval.realval=atof(yytext);return REALNUMBER;}
{commentline} {;}
{wrong_identifier} {;}
<INITIAL><<EOF>> {return EOF;}
"/*" { BEGIN(comment1);}
<comment1>{
"/*"           { ; }
"*"+"/"        { if (i) --i;
                   else BEGIN(INITIAL); }
"*"+           ;
  [^/*\n]+       ; 
  [/]            ; 
  \n             ; 

}
<comment1><<EOF>> {printf("unclosed comment \n"); exit(0);}
\"  { BEGIN(string);}

<string>\" {yylval.strval=strdup(str);BEGIN(INITIAL);return STRING;}
<string>\\n  {if(str!=NULL){
                str=(char *)realloc(str,strlen(str)+2*sizeof(char));
		str[strlen(str)]='\n';
		str[strlen(str)+1]='\0';
	      }else{
		str=(char *)malloc(strlen(yytext)+2);
		str[(strlen(str))]='\n';
		str[strlen(str)+1]='\0';
		}
}
<string>\\t    {if(str!=NULL){
                str=(char *)realloc(str,strlen(str)+2*sizeof(char ));
                str[(strlen(str))]='\t';
		str[strlen(str)+1]='\0';
                
              }else{
                str=(char *)malloc(strlen(yytext)+2);
                str[(strlen(str))]='\t';
                str[strlen(str)+1]='\0';
                }
}

<string>\\\" { if(str!=NULL){
                str=(char *)realloc(str,strlen(str)+2*sizeof(char));
                str[(strlen(str))]='\"';
		 str[strlen(str)+1]='\0';
                
              }else{
                str=(char *)malloc(strlen(yytext)+2);
                str[(strlen(str))]='\"';
                str[strlen(str)+1]='\0';
                }

}               
<string>\\\\ {if(str!=NULL){
                str=(char *)realloc(str,strlen(str)+2*sizeof(char));
                str[(strlen(str))]='\\';
		 str[strlen(str)+1]='\0';
                
              }else{
                str=(char *)malloc(strlen(yytext)+2);
                str[(strlen(str))]='\\';
                str[strlen(str)+1]='\0';
                }


}

<string>[^\"\\\t\\\n]+ { if(str==NULL){
                                str=(char *) malloc(strlen(yytext)+sizeof(char));
                        strcpy(str,yytext);
			str[strlen(str)+1]='\0';
                   }else{
                        str=(char *)realloc(str,strlen(str)+strlen(yytext)+sizeof(char));
                        strcat(str,yytext);
			 str[strlen(str)+1]='\0';


        }
}


<string><<EOF>> {printf("unclosed string \n"); return EOF;}
.	{ printf("undefined char \n"); exit(0);}
%%


void insert(int line,int token_no,char *c_value,char *type,int is_keyword,alpha_token_t *head){
  alpha_token_t *temp = head;
  alpha_token_t *temp2 =(alpha_token_t *)malloc(sizeof(alpha_token_t));
  while(temp->next !=NULL) temp = temp->next;
  temp2->line = line;
  temp2->token_no = token_no;
  temp2->c_value=(char *)malloc(strlen(c_value)*sizeof(char )+1);
  if(strcmp(c_value,"")==0){
	temp2->c_value="";
  }else{
  strcpy(temp2->c_value,c_value);
   temp2->c_value[strlen(c_value)+1]='\0';  
  }
  if(is_keyword==1){
	temp2->type=(char *)malloc(sizeof(type));
	strcpy(temp2->type,type);
  }else{
  temp2->type = type;
	}
  temp2->is_keyword=is_keyword;
  temp->next = temp2;
  temp2->next = NULL;

}

void print(alpha_token_t *head){
  alpha_token_t *temp = head;
  while(temp->next != NULL){
    temp = temp->next;
     printf("\n TOKEN #:%d \n Type:%s \n Token_Value: %s \n Line: %d \n",temp->token_no,temp->type,temp->c_value,temp->line);
     printf("======================================================== \n");
  }
}

int  check_if_keyword(char *text){
	if(strcmp(text,"if")==0){
		return 1;
	}else if(strcmp(text,"function")==0){
		 return 1;
	}else if(strcmp(text,"while")==0){
		 return 1;
	}else if(strcmp(text,"for")==0){
                 return 1;
	}else if(strcmp(text,"else")==0){
                 return 1;
	}else if(strcmp(text,"return")==0){
                 return 1;
	}else if(strcmp(text,"break")==0){
                 return 1;
	}else if(strcmp(text,"while")==0){
                 return 1;
	}else if(strcmp(text,"and")==0){
                 return 1;
	}else if(strcmp(text,"not")==0){
                 return 1;
	}else if(strcmp(text,"or")==0){
                 return 1;
	}else if(strcmp(text,"continue")==0){
		return 1;
	}else if(strcmp(text,"local")==0){
		return 1;
	}else if(strcmp(text,"true")==0){
		return 1;
	}else if(strcmp(text,"false")==0){
		return 1;
	}else if(strcmp(text,"nil")==0){
		return 1;
	}

		
return -1;
}

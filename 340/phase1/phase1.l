
%{
#define YY_DECL int alpha_yylex(void* yyval)
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE -1
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

punctuation (\{)|(\})|(\()|(\))|(\[)|(\])|(\:)|(\,)|(\:\:)|(\.)|(\.\.)|(\;)

operator (\-)|(\*)|(\/)|(\=)|(\%)|(\+\+)|(\-\-)|(\>)|(\<)|(\>\=)|(\<\=)|(\=\=)|(\!\=)

whitespace [\r\n \t\v]

commentline "//".*

wrong_identifier [0-9][a-zA-Z_0-9]*



%x comment1 string plus
%% 
{ID} {	tokens++; 
        if(check_if_keyword(yytext)==TRUE){ 
		insert( yylineno,tokens,yytext,yytext,TRUE,yyval);}
	else{
		insert( yylineno,tokens,yytext,"IDENTIFIER",FALSE,yyval);}
}
{intconst} {tokens++; insert(yylineno,tokens,yytext,"CONSTANT INTEGER",FALSE,yyval); }
{punctuation} {tokens++; insert(yylineno,tokens,yytext,"PUNCTUATION",FALSE,yyval);}
{whitespace} {;}
{realconst} {tokens++; insert(yylineno,tokens,yytext,"REAL CONSTANT",FALSE,yyval);}
{commentline} {tokens++; insert(yylineno,tokens,"LINE COMMENT","LINE COMMENT",FALSE,yyval);}
{wrong_identifier} {tokens++; insert(yylineno,tokens,yytext,"WRONG IDENTIFIER",FALSE,yyval);}
"/*" { tokens++; insert(yylineno,tokens,com,"MULTILINE_COMMENT",FALSE,yyval); BEGIN(comment1);}
<comment1>{
"/*"           { ++i;tokens++; insert(yylineno,tokens,com,"NESTED_COMMENT",FALSE,yyval); }
"*"+"/"        { if (i) --i;
                   else BEGIN(INITIAL); }
"*"+           ;
  [^/*\n]+       ; 
  [/]            ; 
  \n             ; 

}
<comment1><<EOF>> {printf("unclosed comment \n"); exit(0);}
\"  { BEGIN(string);}

<string>\" {tokens++;  if(str==NULL){ insert(yylineno,tokens,"","STRING",FALSE,yyval); BEGIN(INITIAL); str=NULL;}
			 else { str[strlen(str)+1]='\0'; insert(yylineno,tokens,str,"STRING",FALSE,yyval); BEGIN(INITIAL); str=NULL;}}
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


<string><<EOF>> {printf("unclosed string \n"); exit(0);}
"+" { printf("kalala"); }
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
  if(is_keyword==TRUE){
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
int main(int argc, char* argv[]){
   alpha_token_t *head;
   head=(alpha_token_t *)malloc(sizeof(alpha_token_t));
   head->next=NULL;
   if(argc>1){
		if(!(yyin = fopen(argv[1],"r"))){
			fprintf(stderr, "Cannot read file %s\n",argv[1]);
			return -1;
		}
	}
	else{
		yyin = stdin;
	}
   alpha_yylex(head);
   print(head);
   return 0;
}

int  check_if_keyword(char *text){
	if(strcmp(text,"if")==0){
		return TRUE;
	}else if(strcmp(text,"function")==0){
		 return TRUE;
	}else if(strcmp(text,"while")==0){
		 return TRUE;
	}else if(strcmp(text,"for")==0){
                 return TRUE;
	}else if(strcmp(text,"else")==0){
                 return TRUE;
	}else if(strcmp(text,"return")==0){
                 return TRUE;
	}else if(strcmp(text,"break")==0){
                 return TRUE;
	}else if(strcmp(text,"while")==0){
                 return TRUE;
	}else if(strcmp(text,"and")==0){
                 return TRUE;
	}else if(strcmp(text,"not")==0){
                 return TRUE;
	}else if(strcmp(text,"or")==0){
                 return TRUE;
	}else if(strcmp(text,"continue")==0){
		return TRUE;
	}else if(strcmp(text,"local")==0){
		return TRUE;
	}else if(strcmp(text,"true")==0){
		return TRUE;
	}else if(strcmp(text,"false")==0){
		return TRUE;
	}else if(strcmp(text,"nil")==0){
		return TRUE;
	}

		
return FALSE;
}

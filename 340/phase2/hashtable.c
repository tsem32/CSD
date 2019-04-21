#include "Hash.h"
#include <string.h>


struct Hash_T {
    char *Name;
    int line_no;
    int scope;
    SymbolTableType type;
    int is_function; //1 for function
    struct Hash_T *next;
    struct Hash_T *previous;
    struct Hash_T *last;
    struct Hash_T *sidenext;
    struct Hash_T *downnext;
    int is_active;
};
Hash_T *HashTable[10000];
Hash_T *Scopes;
int HashSize = 1000;
int HashFunc(char * Name){
  int Strasc = 0;
  int i=0;
  while(Name[i] != '\0'){
    Strasc = Name[i] + Strasc;
    i++;
  }
  Strasc = Strasc/7;
  return Strasc;
}

void Hash_Put(char *var,int line_no,int scope,SymbolTableType type,int is_function){
  int key = HashFunc(var);
    int i = scope;
    Hash_T *temp3;
    temp3 = Scopes;
    if(HashTable[key] == NULL){
      HashTable[key] =(Hash_T *) malloc(sizeof(Hash_T));
      HashTable[key]->Name=(char *)malloc(strlen(var)+1);
      strcpy(HashTable[key]->Name,var);
      HashTable[key]->line_no = line_no;
      HashTable[key]->scope = scope;
      HashTable[key]->type = type;
      HashTable[key]->is_function = is_function;
      HashTable[key]->is_active = 1;
      if(type == LIBFUNC) return;
      if(Scopes == NULL){
        Scopes = HashTable[key];
        return;
      }
      while(temp3->downnext != NULL){
        temp3 = temp3->downnext;
      }
          temp3->downnext = HashTable[key];
    }else{
      Hash_T *temp = HashTable[key]->next;
      Hash_T *temp2 = (Hash_T*)malloc(sizeof(Hash_T));
      temp2->Name = (char *)malloc(strlen(var)+1);
      strcpy(temp2->Name,var);
      temp2->line_no = line_no;
      temp2->scope = scope;
      temp2->type = type;
      temp2->is_function = is_function;
      temp2->next = NULL;
      temp2->is_active = 1;
      if(type == LIBFUNC) return;
        if(Scopes == NULL){
          Scopes = temp2;
          return;
        }
      if(Scopes == NULL){
        Scopes = HashTable[key];
        return;
      }
      while(temp3->downnext != NULL){
        temp3 = temp3->downnext;
      }
          temp3->downnext = temp2;
      if(HashTable[key]->last == NULL){
        HashTable[key]->next = temp2;
        HashTable[key]->last = HashTable[key]->next;
        HashTable[key]->last->previous = HashTable[key];
      }else{
        temp2->previous = HashTable[key]->last;
        HashTable[key]->last->next = temp2;
        HashTable[key]->last = temp2;
      }
   }
}

void hash_init(){
Hash_Put("print",0,0,LIBFUNC,1);
Hash_Put("input",0,0,LIBFUNC,1);
Hash_Put("objectmemberkeys",0,0,LIBFUNC,1);
Hash_Put("objecttotalmembers",0,0,LIBFUNC,1);
Hash_Put("objectcopy",0,0,LIBFUNC,1);
Hash_Put("totalarguments",0,0,LIBFUNC,1);
Hash_Put("arguments",0,0,LIBFUNC,1);
Hash_Put("typeof",0,0,LIBFUNC,1);
Hash_Put("strtonum",0,0,LIBFUNC,1);
Hash_Put("sqrt",0,0,LIBFUNC,1);
Hash_Put("cos",0,0,LIBFUNC,1);
Hash_Put("sin",0,0,LIBFUNC,1);
}

void Hash_Print(void){
   int i=0;
   Hash_T *temp;

  for(i=0; i < 1000; i++){
     temp=HashTable[i];
    while(HashTable[i] != NULL){
      printf("Name:%s Line:%d scope:%d isF:%d type:%s\n",temp->Name,temp->line_no,temp->scope,temp->is_function,enumStrings[temp->type]);
      temp = temp->next;
      if(temp == NULL) break;
    }
  }

}


int  check_lib(char *id){//checks if id is a LIBFUNC 0 =false 1 =true
	int i=0;
	Hash_T *temp;
	for(i;i<1000;i++){
		temp=HashTable[i];
		while(HashTable[i]!=NULL){ 
			if(strcmp(temp->Name,id)==0 && temp->type==LIBFUNC){
				return 1;
			}
			temp=temp->next;
			if(temp==NULL)break;
		}
	}
return 0;
}

int check_formal(char* Name ,int scope){
       int i=0;
        Hash_T *temp;
        for(i;i<1000;i++){
                temp=HashTable[i];
                while(HashTable[i]!=NULL){
                        if(strcmp(temp->Name,Name)==0 && temp->scope==scope+1 && temp->type==FORMAL ){
                                return 1;
                        }
                        temp=temp->next;
                        if(temp==NULL)break;
                }
        }
return 0;

}
int Exists(char* Name ,int Scope,SymbolTableType type){
       int i=0,j=Scope,ret=-1;
       int flag=0;
        Hash_T *temp;
        for(i;i<1000;i++){
                temp=HashTable[i];
                while(HashTable[i]!=NULL){
                        if(strcmp(temp->Name,Name)==0 ){
                            ret=temp->scope;
 
                        }
                        temp=temp->next;
                        if(temp==NULL)break;
                }
           }
      
return ret;

}
int Local_Exists(char* Name ,int Scope){
       int i=0;
        Hash_T *temp;
        for(i;i<1000;i++){
                temp=HashTable[i];
                while(HashTable[i]!=NULL){
                        if(strcmp(temp->Name,Name)==0 && Scope==temp->scope && temp->type==LCAL){
                                return 1;
                        }
                        temp=temp->next;
                        if(temp==NULL)break;
                }
        }
return -1;

}

int Global_Exists(char* Name){
       int i=0;
        Hash_T *temp;
        for(i;i<1000;i++){
                temp=HashTable[i];
                while(HashTable[i]!=NULL){
                        if(strcmp(temp->Name,Name)==0 && temp->scope==0 && temp->type==GLOBAL){
                                return 1;
                        }
                        temp=temp->next;
                        if(temp==NULL)break;
                }
        }
return -1;

}


int ez_active(char *Name,int exists){
	int i=0;
	Hash_T *temp;
	if(exists>=0){
		for(i;i<1000;i++){
			temp=HashTable[i];
			while(HashTable[i]!=NULL){
				if(strcmp(temp->Name,Name)==0){
					return temp->is_active;
				}
				temp=temp->next;
				if(temp==NULL)break;
			}
		}
	}
return -1;
}

int is_func(char *Name){
        int i=0;
        Hash_T *temp;
        
                for(i;i<1000;i++){
                        temp=HashTable[i];
                        while(HashTable[i]!=NULL){
                                if(strcmp(temp->Name,Name)==0 && temp->is_function==1){
                                        return temp->scope;
                                }
                                temp=temp->next;
                                if(temp==NULL)break;
                        }
                }
        
return -1;
}

/*int main(void){
  Hash_Put("a",1,0,LCAL,0);
  Hash_Put("b",1,1,LCAL,0);
  Hash_Put("c",1,1,LCAL,0);
  Hash_Put("z",1,0,LCAL,0);
  Hash_T *temp = Scopes;
  Hash_T *tempside = temp;
  while(temp != NULL){
    while(tempside != NULL){
    printf("%s ,%d\n",tempside->Name,tempside->scope);
    tempside = tempside->sidenext;
    }
    temp = temp->downnext;
    tempside = temp;
  }
}
*/
void print_lists(){
 Hash_T *temp = Scopes;
  Hash_T *tempside = temp;
  while(temp != NULL){
    while(tempside != NULL){
    printf("%s ,%d %d\n",tempside->Name,tempside->scope,tempside->is_active);
    tempside = tempside->sidenext;
    }
    temp = temp->downnext;
    tempside = temp;
  }

}

void Hide(int scope){
  Hash_T *temp = Scopes;
  Hash_T *tempside = temp;
    while(temp != NULL){
      if(temp->scope == scope){
      while(tempside != NULL){
        tempside->is_active = 0;
        tempside = tempside->sidenext;
      }	
      }
      temp = temp->downnext;
      tempside = temp;
    }


}


SymbolTableType  set_type( int scope){
	if(scope==0){
		return GLOBAL;
	}else if(scope>0){
		return LCAL;
	}
}

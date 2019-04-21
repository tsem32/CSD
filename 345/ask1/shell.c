/*Anastasios Gialamoudis 2910 (gialamoud) */
#include <stdlib.h>
#include "shell.h"
#define wspace " $=\t\r\n\a"
#include <string.h>
#include "list.h"
int shell_exit(char *args){
 int i=0;
 char *test="exit";
if(args!=NULL){
	if(strcmp(args,test)==0){
		return 0;
	}
}

}

int check_test(char *line){
	int i=0;
	for(i;i<strlen(line);i++){
		if(line[i]=='|'){

			return 0;
		}
	}
return -1;
}

void shell_run(char *line){
		int x=check_test(line);
		if(x==0){ 
			char *line3=left_pipe_ret(line);
                	char **args3=line_parser(line3);

                         char *line4=right_pipe_ret(line);
			char **args2=line_parser(line4);
			pipe_run(args3,args2);
		}else{
		char **args=line_parser(line);
			if(strcmp(args[0],"echo")==0 || strcmp(args[0],"set")==0 || strcmp(args[0],"unset")==0 || strcmp(args[0],"printvars")==0||line[0]=='$'){
		set_var(args);
		print_var(args);
		unset_var(args);
		echo_var(args);
		x_var(line);
		}else{
		change_dir(args);
		shell_exec(args);
		}
		}


}


char *read_line(void){
	int bufsize= 64;
	int position=0;
	char *buffer=malloc(sizeof(char)*bufsize);
	int c,i;
	if(!buffer){
		fprintf(stderr,"error allocation \n");
	exit(EXIT_FAILURE);
	}
	while(1){
		c=getchar();
		if (c == EOF || c == '\n') {
      			buffer[position] = '\0';
      			return buffer;
    		} else {
      			buffer[position] = c;
    		}
    		position++;
		if (position >= bufsize) {
      				bufsize += 64;
      				buffer = realloc(buffer, bufsize);
      				if (!buffer) {
        				fprintf(stderr, "lsh: allocation error\n");
        				exit(EXIT_FAILURE);
      				}
		}	
	}
}


int arg_len(char **args){
	int i=0;
	while(args[i]!=NULL){
		i++;
	}
return i;
}

char *left_pipe_ret(char *line){
	int i=0;
	int x=0;
	for(i;i<strlen(line);i++){
		if(line[i]=='|'){
			x=1;

		}
		if(x>0&& i>0){
		 x++;

		}
	}
char *line2=(char *)malloc(sizeof(char *)*(strlen(line)-x+1));
memcpy(line2,line,strlen(line)-x);
line2[strlen(line)-x+1]='\0';
return line2;
}

char *right_pipe_ret(char *line){
	int i=strlen(line);
	int x=0;
	int a=0;
	for(i;i>0;i--){
		if(line[i]!='|'){
			x++;
		}else{
		     break;
		}
		
	}



	char *line2=(char *)malloc(sizeof(char *) *(strlen(line)-x+1));
	strncpy(line2,line+strlen(line)-x+1,strlen(line));
	
	return line2;
}

char **line_parser(char *line){
	int bfsize=128;
	int position=0;
	char **tokens=(char **)malloc(bfsize *sizeof(char*));
	char *token;

	if(!tokens){
	fprintf(stderr,"Error in allocation \n");
	exit(EXIT_FAILURE);
 	}
	token=strtok(line,wspace);
	while(token!=NULL){
		tokens[position]=token;
		position++;
		token=strtok(NULL,wspace);
	}
	tokens[position]=NULL;
	return tokens;
}

int shell_exec(char **args){
	pid_t pid,wpid;
	int status;
	pid=fork();
	if(pid==0){
		execvp(args[0],args);
	}else if(pid<0){
		perror("lsh");
	}else{
		while(wait(&status)!=pid);
	}
}

void pipe_run(char **args1,char **args2){
	int pfds[2];
	pipe(pfds);
	if(!fork()){
		close(1);
		dup(pfds[1]);
		close(pfds[0]);
		execvp(args1[0],args1);
	}else{
		close(0);
		dup(pfds[0]);
		close(pfds[1]);
		execvp(args2[0],args2);
	}


}


void change_dir(char ** line){
int i=0;
	if(line[0]!=NULL){
		if(strcmp(line[i],"cd")==0){
	       		chdir(line[1]);	

		}
	}
}

void set_var(char **args){
	int i=0;
	char *data=(char*)malloc(1000*sizeof(char));;
	if(args[i]!=NULL && strcmp(args[0],"set")==0){
		while(args[2+i]!=NULL){
			strcat(data,args[2+i]);
			strcat(data," ");
			i++;
		}
		insertFirst(args[1],data);
		
	}
}

void print_var(char **args){
	if(args[0]!=NULL && strcmp(args[0],"printvars")==0){
		printList();
	}
}
void  unset_var(char **args){
	if(args[0]!=NULL && strcmp(args[0],"unset")==0){
			struct node *temp=delete(args[1]);
			
	}
}

void echo_var(char **args){
	if(args[0]!=NULL && strcmp(args[0],"echo")==0){
		if(find(args[1])!=NULL){
			printf("%s \n",find(args[1]));
		}
	}
}


void x_var(char *line){
	int i=1;
	char *var=(char *)malloc(strlen(line-1)*sizeof(char));
	if(line!=NULL){
		if(line[0]=='$'){
			while(line[i]!='\0'){
				var[i-1]=line[i];
				i++;
			}
			var[i-1]='\0';
			char **args=line_parser(find(var));
			shell_exec(args);
			
		}
	}
}

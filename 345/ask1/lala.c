/*Anastasios Gialamoudis 2910 (gialamoud */
#include "shell.h"
#include <stdio.h>

int main(void){
		while(1){
		char *name=getlogin();
                char buf[255+1];
                char *dir=getcwd(buf,255+1);

                strcat(name,"@csd345sh");
                strcat(name,dir);
                strcat(name,"$");
                printf("%s",name); 
                char *line=read_line();
		if(strcmp(line,"exit")==0){
			break;
		}
		shell_run(line);

}
return 0;
}

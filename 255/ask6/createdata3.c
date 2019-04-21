#include <stdio.h>
int main(void){
    FILE *f;
  f=fopen("data3.txt","w");
 
   const char *text44="12345678901234567890123456789012345678901234567890";
   fprintf(f,"%s\n",text44);
   fclose(f);
}

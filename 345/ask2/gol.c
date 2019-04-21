#include <stdio.h>
#include <stdlib.h>

void main() 
{
    int  i=0,j=0;
    
    char numbers[4][4];
    FILE *fp;  /*  FILE pointer  */
    fp = fopen("test1.txt", "r");  /* open a text file for reading */
  	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			fscanf(fp,"%d",&numbers[i][j]);
		}
	}
 for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                        printf("%d ", numbers[i][j]);
                }
	printf("\n");
        }

    fclose(fp);

}

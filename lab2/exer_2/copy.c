#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	FILE *readFile = fopen(argv[1],"r");
	FILE *writeFile = fopen(argv[2],"a");
	char temp[100],c;
	if (readFile == NULL || writeFile == NULL){
		printf("Error.");
		exit(1);
	}//printf("agjsahj");
	while(fscanf(readFile,"%s",temp)!=EOF){
		fprintf(writeFile,"%s ",temp);
		printf("%s is printed.\n",temp);
	}
	fclose(readFile);
	fclose(writeFile);
}

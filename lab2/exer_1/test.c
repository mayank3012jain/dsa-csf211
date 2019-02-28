/*File: test.c */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	for (int i=1; i<argc; i++){
		if (argv[i][0]>='0'&&argv[i][0]<='9'){
			int a=atoi(argv[i]) +1;
			printf("%d",a);
		}else{
			printf("%s",argv[i]);
		}
	}
}

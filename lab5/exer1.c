#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
	char c_number[17];
	char b_code[5];
	char expiry[7];
	char name[5];
	char lastName[5];
}record;

int MAX=0;
	

record* readFile(FILE* inputFile, int n){
	if (inputFile ==NULL){
		printf("ERROR");
		return NULL;
	}
	//char *buff;
	record *arr;
	arr = (record*)malloc(sizeof(record)*5);
	MAX = 5;
	for (int i =0; i<n; i++){
		if(i == MAX-1){
			arr = (record*)realloc(arr, MAX*2);
			MAX = MAX*2;
		}
		fscanf(inputFile,"\"%s,%s,%s,%s,%s\"", arr[i].c_number, arr[i].b_code, arr[i].expiry, arr[i].name, arr[i].lastName);
	}
	return arr;
}

int main(){
	int n;
	scanf("%d", &n);
	FILE *inputFile = fopen("10","r");
	clock_t start, end;
	start=clock();
	record *arr = readFile(inputFile, n);
	end = clock();
	double runTime = (double)(end- start);
	printf("Run time is : %f",  runTime);
	return 0;
	}

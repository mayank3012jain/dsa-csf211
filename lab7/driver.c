#include<stdio.h>
#include<stdlib.h>
#include"sort.h"

#define MAX 10
Element* readFile(char* fileName){
	FILE* inFile = fopen(fileName, "r");
	//FILE* inFile = fopen("test.txt", "r");
	Element* A = (Element*)malloc(sizeof(Element) * MAX);
	for (int i =0; i<MAX; i++){
		fscanf(inFile,"%s %d",A[i].name, &A[i].empID);
	}
	return A;
}

void print(Element a){
	printf("\nName: %s, Id: %d", a.name, a.empID); 
}

int main(){
	Element* array = readFile("test.txt");
	for(int i =0; i<MAX; i++){
		print(array[i]);
	}
	printf("\nSorted");
	Element* sorted = quickSortIterative(array,0, MAX-1,0);
	for(int i =0; i<MAX; i++){
		print(array[i]);
	}
}


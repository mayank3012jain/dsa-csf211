#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sort.h"
#include "insertionSort.h"


#define MAX 1000
Element* readFile(char* fileName){
	FILE* inFile = fopen(fileName, "r");
	//FILE* inFile = fopen("test.txt", "r");
	Element* A = (Element*)malloc(sizeof(Element) * MAX);
	for (int i =0; i<MAX; i++){
		fscanf(inFile,"%s %d",A[i].name, &A[i].empID);
	}
	return A;
}

//void print(Element a){
//	printf("\nName: %s, Id: %d", a.name, a.empID); 
//}

int main(int argc, char* argv[]){
	Element* array = readFile(argv[1]);
	// for(int i =0; i<MAX; i++){
	// 	print(array[i]);
	// }
	printf("\nSorted with array size = %d", MAX);
	double start = clock();
	Element* sorted = quickSortIterative(array,0, MAX-1,0);
	double end = clock();
	//Element* sorted = insertionSort(array, MAX);
	// for(int i =0; i<MAX; i++){
	// 	print(sorted[i]);
	// }
	printf("\nTime taken to complete quickSort: %lf", end-start);
	array = readFile(argv[1]);
	start = clock();
	sorted = insertionSort(array,0, MAX-1);
	end = clock();
	printf("\nTime taken to complete insertionSort: %lf", end-start);
	array = readFile(argv[1]);
	start = clock();
	sorted = mixSort(array,0, MAX-1,20);
	end = clock();
	printf("\nTime taken to complete mixSort: %lf", end-start);

}

#include "merge.h"
#include<stdio.h>
int main(){
	FILE *input = fopen("1024.txt", "r");
	int size1= 1024, size2= 15;
	student Ls1[size1], Ls2[size2], merged[size1 + size2];
	for (int i = 0; i < size1; i++){
		fscanf(input,"%[^,],%f\n", Ls1[i].name, &Ls1[i].cgpa);
		//if(i<50)
		printf("\nInput %d: %s,.. %f", i, Ls1[i].name, Ls1[i].cgpa);; 
	}
	//printf("\nList 2");
	/*for (int i = size1; i < size1+size2; i++){
		fscanf(input,"%[^,],%f\n", Ls2[i-size1].name, &Ls2[i-size1].cgpa);
		printf("\nInput %d: %s,.. %f", i, Ls2[i-size1].name, Ls2[i-size1].cgpa);
	}*/
	//merge(Ls1, size1, Ls2, size2, merged);
	mergeSort(Ls1, size1);
	for (int i = 0; i < size1; i++){
		print(Ls1[i]);
	}	
	
	
}

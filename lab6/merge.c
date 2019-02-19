#include<stdio.h>
#include "merge.h"
#include<string.h>

void copy(Element *a, Element *b);
void print(Element a){
	printf("\nElement: %.10s, %f", a.name, a.cgpa);
}

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]){
	int i=0, j=0, k=0;
	for (i=0; i< sz1+ sz2; i++){
		//print(Ls1[j]);
		//print(Ls2[k]);
		if(j>=sz1){
			//Ls[i] = Ls2[k];
			copy(&Ls[i], &Ls2[k]);
			k++;
			//printf("1");
		}else if(k>=sz2){
			//Ls[i] = Ls1[j];
			copy(&Ls[i], &Ls1[j]);
			j++;
			//printf("2");
		}else if(Ls1[j].key <= Ls2[k].key){
			//Ls[i] = Ls1[j];
			copy(&Ls[i], &Ls1[j]);
			j++;
			//printf("3");
		}else{
			//Ls[i] = Ls2[k];
			copy(&Ls[i], &Ls2[k]);
			k++;
			//printf("4");
		}
	}
}

void copy(Element *a, Element *b){
	strcpy(a->name, b->name);
	a->key= b->key;
}

void mergeSort(Element input[], int size){
	if (size >1){
		Element sorted[size];
		int mid= size/2;
		mergeSort(input, mid);
		mergeSort(input+mid, size-mid);
		merge(input, mid, input+mid, size-mid, sorted);
		for(int i = 0; i < size; i++){
			copy(&input[i], &sorted[i]);
		}
	}
}

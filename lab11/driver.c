#include "nary.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
	FILE* input = fopen(argv[1], "r");
	int inChoice;
	NODE tree = (NODE)malloc(sizeof(struct node));
	tree->child=NULL;
	tree->sibling = NULL;
	while(!feof(input)){
		fscanf(input, "%d", &inChoice);
		if( inChoice == 1){
			int n;
			fscanf(input, "%d", &n);
			readData(input, tree, n);
		}else if(inChoice == -1){
			break;
		}
	}
}

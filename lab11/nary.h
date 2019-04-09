#include<stdio.h>
#include<stdlib.h>

struct node{
	char key[100];
	struct node* child;
	struct node* sibling;
};

#define NODE struct node*

NODE readData(FILE* input, NODE root, int n);
void lookup(char* name, NODE root);



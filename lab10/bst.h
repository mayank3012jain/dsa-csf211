#ifndef _BST_H
#define _BST_H

#include<stdio.h>
#include<stdlib.h>

#define node* NODE

typedef struct{
	int value;
	NODE left, right, parent;
	int hleft,hright;
}node;

//unbalanced add
NODE addUB(NODE root, int value);

NODE find(NODE root, int value);

NODE deleteNode(NODE root, NODE toDelete);

#endif

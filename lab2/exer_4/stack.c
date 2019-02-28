#include "stack.h"

void push(STACK* head, int ele){
	insertFirst(head, ele);
}

int pop(STACK* head){
	struct node* top= deleteFirst(head);
	return top->element;
}

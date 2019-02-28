/* linkedlist.c*/
#include "linkedlist.h"
#include<stdlib.h>

void insertFirst( struct linkedList* head, int ele){
	struct node* link= (struct node*)malloc(sizeof(struct node));
	link->element = ele;

	link->next = head->first;

	head->first = link;
	head->count++;
}

struct node* deleteFirst(struct linkedList* head){
	struct node* temp = head->first;
	head->first = temp->next;
	head->count--;
	printf("deleted ele is %d", temp->element);
	return temp;
}

//display the list
void printList(struct linkedList* head){
	struct node* ptr = head->first;
	printf("\n[ ");
	//start from the beginning
	while(ptr != NULL){        
		printf("%d,",ptr->element);
		ptr = ptr->next;
	}
	printf(" ]");
}

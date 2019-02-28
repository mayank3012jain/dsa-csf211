#include<stdio.h>


typedef struct node{
	int tid;
	int p;
	struct node *next;
}node;

typedef node* Element;

typedef struct{
	int length;
	node *front;
	node* tail;
}queue;

typedef queue* Queue;

typedef enum{False,True} Boolean;

Queue newQ();

Boolean isEmptyQ(Queue q);

Queue delQ(Queue q);

Element front(Queue q);

Queue addQ(Queue q, Element element);

int lengthQ(Queue q);

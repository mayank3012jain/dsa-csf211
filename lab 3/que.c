#include "queue.h"
#include<stdlib.h>

Queue newQ(){
	Queue q;
	q->length=0;
	q->front=NULL;
	q->tail =NULL;
	return q;
}

Boolean isEmptyQ(Queue q){
	if (q->length == 0){
		return False;
	}
	else return True;
}

Queue delQ(Queue q){
	node* temp;
	if(isEmptyQ(q)){
		printf("EmptyQ");
		return NULL;
	}else {
		temp = q->front;
		q->front = temp->next;
		free(temp);
		temp=NULL;
		return q;
	}
}

Element front(Queue q){
	if(isEmptyQ(q)){
		printf("empty");
		return NULL;

	}	
	return q->front;
}

Queue addQ(Queue q, Element e){
	//node* temp = (node*)malloc(sizeof(node));
	//temp->ele = e;
	//temp->next = NULL;
	Element temp = e;
	q->length++;
	if(isEmptyQ(q)){
		q->front=temp;
		q->tail=temp;
	}else{
		q->tail->next=temp;
		q->tail=temp;	
	}
	return q;
}

int lengthQ(Queue q){
	return q->length;
}

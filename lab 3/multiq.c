#include "multiq.h"


MultiQ createMQ(int num){
	MultiQ mq = (MultiQ)malloc(num*sizeof(queue));
	for(int i=0; i<num; i++){
		mq[i] = newQ();
	}
}

MultiQ addMQ(MultiQ mq, Task t){
	mq[t->p] = addQ(mq[t->p],t);
}

Task nextMQ(MultiQ mq){
	for (int i=0; i<sizeMQ(mq); i++){
		if(!isEmptyQ(mq[i]){
			return front(mq[i]);
		}	
	}
	printf("all empty");
	return NULL;
}

int sizeMQ(MUltiQ mq){
	int size= sizeof(mq



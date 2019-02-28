#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

//typedef int TaskID;
typedef int Priority;
/*typedef struct{
	int tid;
	Priority p;
}Task;*/
typedef Element Task;

typedef Queue* MultiQ;

MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Task t);
Task nextMQ(MultiQ mq);
Task delNextMQ(MultiQ mq);
Boolean isEmptyMQ(MultiQ mq);
int sizeMq(MultiQ mq);
int sizeMQbyPriority(MultiQ mq, Priority p);
Queue getQueueFromMQ(MultiQ mq, Priority p);

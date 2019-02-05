#include<stdio.h>
#include<stdlib.h>


void* myAlloc(int size){
	
	allocatedMemory += size;
	printf("\nTotal mem = %d",  allocatedMemory);
	void* ptr = malloc(size+4);
	int* pad;
	pad = (int*)ptr;
	*pad = size;	
	return ptr+4;
}
void myFree(void* ptr){
	//printf("Total mem = %d",  allocatedMemory);
	allocatedMemory -= (*((int*)(ptr-4)));
	free(ptr-4);
	printf("\nTotal mem = %d",  allocatedMemory);
}


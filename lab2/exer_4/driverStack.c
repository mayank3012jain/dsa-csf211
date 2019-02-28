/* driverStack.c */
#include <stdio.h>
#include "stack.h"
#include<stdlib.h>
int main(int argc, char *argv[])
{
	// Create a file pointer and open the file read as command line argument.
	FILE * fileptr = fopen(argv[1], "r");
	// Declare a pointer to a linked list (head) and allocate memory to it.
	STACK* top = (STACK*)malloc(sizeof(STACK));
	// In a loop read the file and insert elements into the linkedList.
	while (!feof(fileptr)){
		// read the next element and store into the temp variable.
		
		int temp;
		fscanf(fileptr, "%d", &temp);
		// insert temp into the linked list.
		push(top,temp);
	}
	printList(top);
	//printf("popped ele is %d", pop(top));
}

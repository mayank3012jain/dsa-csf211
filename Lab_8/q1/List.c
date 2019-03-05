#include "List.h"
List createList(Student studArray, int arraySize){
	List ls = (List)myalloc(sizeof(struct list));
	//ls->first = temp;
	//ls->count=1;
	for( int i=0; i<arraySize; i++){
		Node temp = (Node)myalloc(sizeof(struct node));
		temp->record = (Student)myalloc(sizeof(struct student));
		temp->record->name = (char *)myalloc(sizeof(char)*50);
		strcpy(temp->record->name,studArray[i].name);
		temp->record->marks = studArray[i].marks;
		temp->next = NULL;
		ls->count++;
		if (0 == i){
			ls->first = temp;
			ls->last = temp;
		}else{
			ls->last->next = temp;
			ls->last = ls->last->next;
		}
	}
	return ls;
}

void insertInOrder(List list, Node newN){
	Node newNode = (Node)myalloc(sizeof(struct node));
	newNode->record = (Student)myalloc(sizeof(struct student));
	newNode->record->name = (char *)myalloc(sizeof(char)*50);
	strcpy(newNode->record->name,newN->record->name);
	newNode->record->marks = newN->record->marks;
	newNode->next = NULL;
	list->count++;
	if (1 == list->count){
		list->first = newNode;
		list->last = newNode;
		return;
	}else{
		Node temp = list->first;
		if (temp->record->marks > newNode->record->marks){
			newNode->next = list->first;
			list->first = newNode;
		}else{
			while (temp != list->last){
				if (temp->next->record->marks > newNode->record->marks){
					newNode->next = temp->next;
					temp->next = newNode;
					return;
				}
				temp = temp->next;
			}
			list->last->next = newNode;
			newNode->next = NULL;
			list->last = newNode;
			return;
		}
	}
}

List insertionSort(List list){
	List sorted = (List)myalloc(sizeof(struct list));
	sorted->count = 0;
	sorted->first= NULL;
	sorted->last = NULL;
	Node temp = list->first;
	while(temp != NULL){
		insertInOrder(sorted, temp);
		temp = temp->next;		
	}
	return sorted;
}


double measureSortingTime(List list){
	double start = clock();
	List sorted = insertionSort(list);
	double end = clock();
	double timeTaken = ((end -start)/CLOCKS_PER_SEC)*100;
	return timeTaken;
}

void* myalloc(int size){
	
	globalCounter += size;
	//printf("\nTotal mem = %d",  globalCounter);
	void* ptr = malloc(size+4);
	int* pad;
	pad = (int*)ptr;
	*pad = size;	
	return ptr+4;
}
void myfree(void* ptr){
	//printf("Total mem = %d",  allocatedMemory);
	globalCounter -= (*((int*)(ptr-4)));
	free(ptr-4);
	//printf("\nTotal mem = %d",  allocatedMemory);
}

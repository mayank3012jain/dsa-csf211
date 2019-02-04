#include<stdio.h>
#include<stdlib.h>

typedef int index;
#define MAX 30
#define NEXT 2
#define KEY 1
#define Null -1
#define PREV 0
int memory[MAX];
//will use it in form prev, key, next

typedef struct{
    int head;
    int length;
}listHead;

listHead freeList;

void initFreeList();
void pushFreeList(index i);
index popFreeList();
void displayFreeList();

void print();

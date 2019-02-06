//__________freeList.h________
#include<stdio.h>
#include<stdlib.h>

typedef int index;
#define MAX 150
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

void initFreeList();//fills the complete memory with freeList
void pushFreeList(index i);//pushes the index i into the freeList
index popFreeList();//pops the top element of the freeList
void displayFreeList();//displays the freeList

//print is used for debugging. It prints the complete array.
void print();

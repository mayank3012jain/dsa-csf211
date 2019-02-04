//____freeList.c_____
#include "freeList.h"

void initFreeList(){
    freeList.head = 0;
    freeList.length = 1;
    memory[freeList.head]=Null;
    memory[freeList.head + 2] = freeList.head + 3;
    for(index i = freeList.head + 3; i<MAX; i += 3){
        memory[i]= i-1;
        memory[i+2]= i+3;
        freeList.length++;
    }
    memory[MAX-1] = Null;
}

void pushFreeList(index i){
    if (freeList.length == 0){
        freeList.head = i;
        freeList.length = 1;
        memory[i + PREV] = Null;
        memory[i + NEXT] = Null;
    }else{
        memory[i + NEXT] = freeList.head;
        memory[freeList.head + PREV] = i;
        memory[i + PREV] = Null;
        freeList.head = i;
        freeList.length++;
    }
}

index popFreeList(){
    if (freeList.length == 0){
        printf("\nMemory full.");
        return Null;
    }else if(freeList.length == 1){
        index temp = freeList.head;
        freeList.head = Null;
        freeList.length = 0;
        return temp;
    }else{
        index temp = freeList.head;
        freeList.head = memory[freeList.head + NEXT];
        memory[freeList.head + PREV] = Null;
        freeList.length--;
        return temp;
    }
}

void displayFreeList(){
    if (freeList.length == 0){
        printf("Free list is empty.");
    }
    index i = freeList.head;
    printf("\nIndexes of elements of free list in order are:\n");
    while(i != Null){
        printf("%d  ",i);
        i = memory[i + NEXT];
    }
}

void print(){
    printf("\n");
    for(int i=0; i<MAX; i++){
        printf("%d ", memory[i]);
    }
}
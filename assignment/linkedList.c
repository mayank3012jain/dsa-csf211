//______linkedList.c__________
#include "linkedList.h"

void newList(){
    if (listCount < 4){
        listCount++;
        LinkedLists[listCount].head = Null;
        LinkedLists[listCount].length = 0;
        printf("SUCCESS: New list added with list number %d", listCount);
    }else{
        printf("ERROR: Max number of lists reached.");
    }
}

void insertIntoList(int listNumber, int key){
    if (listNumber>listCount || listNumber<0){
        printf("ERROR: enter a number between 0 and %d(both inclusive)",listCount);
        return;
    }
    index temp = popFreeList();
    if (temp == -1){
        return;
    }
    printf("\nSUCCESS: Given value has been inserted.");
    //inserting in ascending order
    if(LinkedLists[listNumber].length == 0){
        LinkedLists[listNumber].head = temp;
        LinkedLists[listNumber].length++;
        memory[temp + PREV] = Null;
        memory[temp + KEY] = key;
        memory[temp + NEXT] = Null;
        return;
    }
    if (key < memory[LinkedLists[listNumber].head + KEY]){
        memory[LinkedLists[listNumber].head + PREV] = temp;
        memory[temp + NEXT] = LinkedLists[listNumber].head;
        memory[temp + PREV] = Null;
        memory[temp + KEY] = key;
        LinkedLists[listNumber].head = temp;
        LinkedLists[listNumber].length++;
        return;
    }
    index i = LinkedLists[listNumber].head;
    while(memory[i + NEXT] != Null){
        if(memory[memory[i + NEXT] + KEY] < key){
            i = memory[i + NEXT];
        }else{
            break;
        }
    }
    memory[temp + NEXT] = memory[i + NEXT];
    memory[temp +PREV] = i;
    memory[temp + KEY] = key;
    memory[memory[i+NEXT] + PREV] = temp;
    memory[i + NEXT] = temp;
    LinkedLists[listNumber].length++;
    return;
}

void deleteFromList(int listNumber, int key){
    if (!(listNumber>=0 && listNumber <= listCount)){
        printf("ERROR: Enter list number between 0 and %d(both inclusive).", listCount);
        return;
    }
    index i = LinkedLists[listNumber].head;
    while(i != Null){
        if (memory[i + KEY] == key){
            break;
        }else if(memory[i + KEY] > key){
            printf("ERROR: No such element exists in the given list.");
            return;
        }else {
            i = memory[i+NEXT];
        }
    }
    
    LinkedLists[listNumber].length--;
    if (LinkedLists[listNumber].length == 0){
        LinkedLists[listNumber].head = Null;
    }
    if (memory[i + PREV] == Null){
        memory[memory[i + NEXT] + PREV] = Null;
        LinkedLists[listNumber].head = memory[i + NEXT];
    }else if (memory[i + NEXT] == Null){
        memory[memory[i+PREV] + NEXT] = Null;
    }else {
        memory[memory[i+PREV] + NEXT] = memory[i + NEXT];
        memory[memory[i + NEXT] + PREV] = memory[i + PREV];
    }
    
    pushFreeList(i);
    printf("SUCCESS.");
}

int countElementsAll(){
    int sum=0;
    for (int i = 0; i<listCount; i++){
        sum += LinkedLists[i].length;
    }
    return sum;
}

int countElementsList(int listNumber){
    return LinkedLists[listNumber].length;
}

void displayList(int listNumber){
    index i = LinkedLists[listNumber].head;
    if (i == Null){
        printf("\nList %d is empty.", listNumber);
        return;
    }
    printf("\nList number %d: \nFormat:  [Previous, Key, Next]", listNumber);
    while(i != Null){
        printf("\nAt index %d: [%d, %d, %d]", i,memory[i+PREV],memory[i + KEY], memory[i + NEXT]);
        i = memory[i + NEXT];
    }
}
void displayAll(){
    for (int i = 0; i<= listCount; i++){
        displayList(i);
    }
}
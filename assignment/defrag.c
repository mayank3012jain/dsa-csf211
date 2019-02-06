//__________defrag.c_________
#include "defrag.h"

void insert(index temp, int key, int listNumber);
//used to insert the value into the given linked list at memory index which is passed.

void defrag(){
    index minFree, maxUsed;
    do{
        //print();
        int maxUsedList = -1, maxUsedKey=0;
        index i = freeList.head;
        minFree = i;
        //find the minimum index of any node in free list
        while(i != Null){
            if (i < minFree){
                minFree = i;
            }
            i = memory[i + NEXT];
        }
        if(minFree >= MAX-(freeList.length*3)){break;}

        //find the maximum index of a node in any of the linked lists
        maxUsed = -1;
        for (int listNumber = 0; i<listCount; i++){
            i = LinkedLists[listNumber].head;
            while(i != Null){
                if (maxUsed < i){
                    maxUsed = i;
                    maxUsedList = listNumber;
                    maxUsedKey = memory[i + KEY];
                }
                i = memory[i + NEXT];
            }
        }

        //swap the above found both
        freeList.length--;
        if (freeList.length == 0){
            freeList.head = Null;
        }
        if (memory[minFree + PREV] == Null){
            memory[memory[minFree + NEXT] + PREV] = Null;
            freeList.head = memory[minFree + NEXT];
        }else if (memory[minFree + NEXT] == Null){
            memory[memory[minFree+PREV] + NEXT] = Null;
        }else {
            memory[memory[minFree+PREV] + NEXT] = memory[minFree + NEXT];
            memory[memory[minFree + NEXT] + PREV] = memory[minFree + PREV];
        }
        //print();
        int listNumber = maxUsedList;
        i = maxUsed;
        LinkedLists[listNumber].length--;
        if (LinkedLists[listNumber].length == 0){
            LinkedLists[listNumber].head = Null;
        }else if (memory[i + PREV] == Null){
            memory[memory[i + NEXT] + PREV] = Null;
            LinkedLists[listNumber].head = memory[i + NEXT];
        }else if (memory[i + NEXT] == Null){
            memory[memory[i+PREV] + NEXT] = Null;
        }else {
            memory[memory[i+PREV] + NEXT] = memory[i + NEXT];
            memory[memory[i + NEXT] + PREV] = memory[i + PREV];
        }

        pushFreeList(maxUsed);
        insert(minFree, maxUsedKey, maxUsedList);
        printf("\n minfree = %d", minFree);
        getchar();
    }while(minFree < MAX-(freeList.length*3));
    printf("SUCCESS.");
}

void insert(index temp, int key, int listNumber){
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
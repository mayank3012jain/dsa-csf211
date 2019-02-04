#include "freeList.h"

int listCount;

listHead LinkedLists[5];

void newList();
void insertIntoList(int listNumber, int key);
void deleteFromList(int listNumber, int key);
int countElementsAll();
int countElementsList(int listNumber);
void displayAll();
void displayList(int listnumber);

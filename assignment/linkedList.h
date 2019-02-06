//__________linkedList.h___________
#include "freeList.h"

int listCount;

listHead LinkedLists[5];//These will point to the head of all the linked lists implemented

void newList();//used to create new list
void insertIntoList(int listNumber, int key);
/* Inserts the given key into the linked list in a sorted manner(ascending)
    params:
    int listNumber: number of the list in which you want to add the element
    int key: value that you want to add
*/
void deleteFromList(int listNumber, int key);
/* Deletes the given key from the linked list. Gives error if the given list or given value doesn't exist
    params:
    int listNumber: number of the list from which you want to delete the element
    int key: value that you want to remove
*/
int countElementsAll();//returns total number of elements in all the lists
int countElementsList(int listNumber);
/*returns total number of elements in the given list
    params:
    int listNumber: number of the list whose number of elements you want to know
*/
void displayAll();//displays all the linked lists
void displayList(int listnumber);
/* displays the linked list whose number is given
    params:
    int listNumber: number of the list which you want to dislpay
*/

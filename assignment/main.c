//__________main.c____________
#include "defrag.h"

int main(){
    initFreeList();
    listCount=-1;
    int input, count;
    do{
        printf("\n****************\nSelect an option:"
            "\n1. Create a new list"
            "\n2. Insert a new element in a given list in sorted order"
            "\n3. Delete an element from a given list"
            "\n4. Count total elements excluding free list"
            "\n5. Count total elements of a list"
            "\n6. Display all lists"
            "\n7. Display free list"
            "\n8. Perform defragmentation"
            "\n9. Press 0 to exit \n");
        scanf("%d", &input);
        int listNumber, value;

        switch (input)
        {
            case 1:
                newList();
                break;
            case 2:
                printf("\nEnter the list number:");
                scanf("%d",&listNumber);
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insertIntoList(listNumber, value);
                break;
            case 3:
                printf("\nEnter the list number:");
                scanf("%d",&listNumber);
                printf("Enter the value to be deleted: ");
                scanf("%d", &value);
                deleteFromList(listNumber, value);
                break;
            case 4:
                count = countElementsAll();
                printf("\n Total elements are %d.", count);
                break;
            case 5:
                printf("\nEnter the list number:");
                scanf("%d",&listNumber);
                count = countElementsList(listNumber);
                printf("\n Total elements in list %d are %d.", listNumber, count);
                break;
            case 6:
                displayAll();
                break;
            case 7:
                displayFreeList();
                break;
            case 8:
                defrag();
                break;
            case 0:
                break;
            default:
                printf("\nWrong input. Please try again.");
                break;
        }
    }while(input != 0);
}

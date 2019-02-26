#include "stack.h"
typedef struct{
	char name[10];
	int empID;
}employee;

#define index int
#define Element employee
Element* readFile(char fileName[]);
Element* quickSortIterative(Element* ls, int lo, int hi, int min);
index pivot(Element* array, index lo, index high);
index partition(Element* array, index lo, index hi, index pivot);
int compEmp(Element a, Element b);

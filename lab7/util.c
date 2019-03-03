#include "util.h"
#include<stdio.h>
int compEmp(Element a, Element b){
	if (a.empID < b.empID)	return -1;
	else if(a.empID == b.empID) return 0;
	else return 1;
}

void print(Element a){
	printf("\nName: %s, Id: %d", a.name, a.empID); 
}
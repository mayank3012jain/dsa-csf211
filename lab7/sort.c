#include<stdio.h>
#include"sort.h"

index pivot(Element* array, index lo, index hi){
	return hi;
}
void swap(Element* a, Element* b){
	Element temp;
	strcpy(temp.name,b->name);
	temp.empID = b->empID;
	strcpy(b->name,a->name);
	b->empID = a->empID;
	strcpy(a->name,temp.name);
	a->empID = temp.empID;
}


//wont have pivot at correct pos
//will work only with pivot in upper half
// change the else part to correct
index partition(Element* array, index lo, index hi, index pivot){
	Element pi = array[pivot];
	index i= lo-1;
	index j = hi+1;
	while(1){
		do{
			j--;
		}while(compEmp(array[j],pi) == -1);
		do{
			i++;
		}while(compEmp(array[i],pi) == 1||compEmp(array[i],pi) == 0);
		if ( i<j){
			swap(&array[i], &array[j]);
			/*Element temp = array[i];
			array[i] = array[j];
			array[j] = temp;*/
		}else{
			/*Element temp = array[i];
			array[i] = array[pivot];
			array[pivot] = temp;*/
			return j;
		}
	}
}

Element* quickSortIterative(Element* ls, int lo, int hi, int min){
	Stack st = push(newStack(100), newStEle(lo,hi));
	while(st.top != -1){
		stEle y = top(st); st = pop(st);
		lo = y.lo; hi = y.hi;
		while(lo + min<hi){
			index p = pivot(ls, lo, hi);
			p = partition(ls, lo,hi, p);
			st = push(st, newStEle(lo,p-1));
			lo = p;
		}
	}
}

int compEmp(Element a, Element b){
	if (a.empID < b.empID)	return -1;
	else if(a.empID == b.empID) return 0;
	else return 1;
}



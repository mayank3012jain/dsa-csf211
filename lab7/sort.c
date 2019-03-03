#include<stdio.h>
#include"sort.h"
#include"util.h"
#include"stack.h"
#include"insertionSort.h"
#include<string.h>

Index pivot(Element* array, Index lo, Index hi){
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
Index partition(Element* array, Index lo, Index hi, Index pivot){
	//printf("sadbhkd");
	Element pi = array[pivot];
	Index i= lo-1;
	Index j = hi;
	while(1){
		do{
			j--;
		}while(compEmp(array[j],pi) == 1|| compEmp(array[j],pi) == 0);//array[j]>=pi
		do{
			i++;
		}while(compEmp(array[i],pi) == -1);//array[i]<pi
		if ( i<j){
			swap(&array[i], &array[j]);
			j--;
			i++;
			/*Element temp = array[i];
			array[i] = array[j];
			array[j] = temp;*/
		}else{
			/*Element temp = array[i];
			array[i] = array[pivot];
			array[pivot] = temp;*/
			if (i==j){
				pivot= j;
			}else{
				pivot = j+1;
			}
			swap(&array[pivot], &array[hi]);
			// printf("\n%d %d %d", lo, hi, j);
			// for (int i=lo; i<hi; i++){
			// 	print(array[i]);
			// }
			return pivot;
		}
	}
	
}

Element* quickSortIterative(Element* ls, int lo, int hi, int min){
	int max =0;
	Stack st = push(newStack(100), newStEle(lo,hi));
	while(st.top != -1){
		stEle y = top(st); st = pop(st);
		lo = y.lo; hi = y.hi;
		while(lo + min<hi){
			Index p = pivot(ls, lo, hi);
			p = partition(ls, lo,hi, p);
			st = push(st, newStEle(lo,p-1));
			if (st.top > max)
			// {max = st.top; 
			// 	printf("\n%d %d %d", max, lo, hi);
			// 	//if (hi - lo < 2)	printf("\n %d %d", ls[lo].empID, ls[hi].empID);
			// }
			// lo = p;
		}
		//ls = insertionSort(ls, lo, hi);
	}
	printf("\nStack: %d", max);
	return ls;
}

Element* mixSort(Element* ls, int lo, int hi, int min){
	Stack st = push(newStack(100), newStEle(lo,hi));
	while(st.top != -1){
		stEle y = top(st); st = pop(st);
		lo = y.lo; hi = y.hi;
		while(lo + min<hi){
			Index p = pivot(ls, lo, hi);
			p = partition(ls, lo,hi, p);
			st = push(st, newStEle(lo,p-1));
			lo = p;
		}
		ls = insertionSort(ls, lo, hi);
	}
	return ls;
}




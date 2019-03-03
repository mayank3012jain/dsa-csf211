#include <stdio.h>
#include<stdlib.h>
#include "stack.h"


Stack newStack(int size){
	Stack st;
	st.top = -1;
	st.size = size;
	st.array = (stEle*)malloc(sizeof(stEle)*size);
	return st;
}

Stack push(Stack st, stEle x){
	if (st.top == st.size-1){
		printf("Stack full");
		exit(1);
		return st;
	}
	st.top++;
	st.array[st.top] = x;
	//if (st.top>_max) _max = st.top;
	return st;
}

stEle top(Stack st){
	stEle x;
	x.lo = 0;
	x.hi = 0;
	if (st.top == -1){
		printf("Stack empty!!");
		return x;
	}
	x = st.array[st.top];
	st.top--;
	return x;
}

Stack pop(Stack st){
	if (st.top == -1){
		printf("Stack empty!!");
		return st;
	}
	st.top--;
	return st;
}

stEle newStEle(int lo, int hi){
	stEle x;
	x.lo = lo;
	x.hi = hi;
	return x;
}

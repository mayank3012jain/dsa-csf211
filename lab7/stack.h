typedef struct{
	int lo,hi;
}stEle;

//extern int _max =0;

typedef struct{
	int top, size;
	stEle* array;
}Stack;

Stack newStack(int size);
Stack push(Stack st, stEle x);
Stack pop(Stack st);
stEle top(Stack st);
stEle newStEle(int low, int hi);

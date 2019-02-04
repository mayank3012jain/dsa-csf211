test: main.o freeList.o linkedList.o
	gcc main.o freeList.o linkedList.o -o test

freeList.o: freeList.c freeList.h
	gcc -c freeList.c

main.o: main.c freeList.h
	gcc -c main.c

linkedList.o: linkedList.c freeList.h
	gcc -c linkedList.c


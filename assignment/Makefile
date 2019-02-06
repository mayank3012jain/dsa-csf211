run:main
	./main

main: main.o freeList.o linkedList.o defrag.o
	gcc main.o freeList.o linkedList.o defrag.o -o main

freeList.o: freeList.c freeList.h
	gcc -c freeList.c

main.o: main.c freeList.h
	gcc -c main.c

linkedList.o: linkedList.c freeList.h
	gcc -c linkedList.c

defrag.o : defrag.c defrag.h
	gcc -c defrag.c

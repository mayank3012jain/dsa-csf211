execute: run
	./run
	
run: List.c List.h main.c
	gcc List.c main.c -o run
	
debug: debug.out
	gdb debug.out

debug.out: List.c List.h main.c
	gcc -g List.c main.c -o debug.out

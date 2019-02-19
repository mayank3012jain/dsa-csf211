run: a.out
	./a.out

a.out: main.c merge.c merge.h
	gcc main.c merge.c
	
merge.o: merge.c merge.h
	gcc -c merge.c
	
gdb: debug
	gdb debug
debug: main.c merge.c merge.h
	gcc -g main.c merge.c -o debug

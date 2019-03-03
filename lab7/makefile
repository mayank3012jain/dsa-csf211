run: out
	./out 100000

out: driver.c sort.c stack.c sort.h stack.h util.c util.h insertionSort.c insertionSort.h
	gcc driver.c stack.c sort.c util.c insertionSort.c -o out
	
debug: driver.c sort.c stack.c sort.h stack.h util.c util.h insertionSort.c insertionSort.h
	gcc -g driver.c stack.c sort.c util.c insertionSort.c -o debug

runInsert: insert.out
	./insert.out

insert.out: driver.c insertionSort.h insertionSort.c util.h util.c
	gcc driver.c insertionSort.c util.c -o insert.out
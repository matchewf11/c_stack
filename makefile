all: main.c stack.c
	gcc -O3 main.c stack.c -o stack
mem: all
	valgrind ./stack

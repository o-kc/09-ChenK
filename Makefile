.PHONY: run compile clean
all: run
main.o: main.c list.h node.h
	@gcc -Wall -c main.c
library.o: library.c node.h
	@gcc -Wall -c list.c
node.o: node.c node.h
	@gcc -Wall -c node.c
run: program
	@./program
program: main.o list.o node.o
	@gcc -o program main.o list.o node.o
clean:
		@rm -f program

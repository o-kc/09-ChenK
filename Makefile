.PHONY: run compile clean
all: run
main.o: main.c list.h
	@gcc -Wall -c main.c
list.o: list.c node.h
	@gcc -Wall -c list.c
run: program
	@./program
program: main.o list.o
	@gcc -o program main.o list.o
clean:
		@rm -f program

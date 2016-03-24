all: npaths

npaths: main.o path.o queue_stack.o matrix.o
	gcc -o npaths main.o path.o queue_stack.o matrix.o

main.o: main.c
	gcc -c main.c

path.o: path.c
	gcc -c path.c

queue_stack.o: queue_stack.c
	gcc -c queue_stack.c

matrix.o: matrix.c
	gcc -c matrix.c

clean:
	rm -rf *o hello

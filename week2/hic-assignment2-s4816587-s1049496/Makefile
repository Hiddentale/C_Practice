CC = gcc
CFLAGS = -Wall -Wextra -pedantic
OBJ = exercise1.c

all: exercise1 exercise2 exercise3 exercise4

exercise1: $(OBJ)
	$(CC) $(CFLAGS) -o exercise1 $(OBJ)

exercise2: exercise2.c
	$(CC) $(CFLAGS) -o exercise2 exercise2.c

exercise3: exercise3.c
	$(CC) -Wall -O3 -o exercise3 exercise3.c

exercise4: exercise4.c
	$(CC) -Wall -O3 -o exercise4 exercise4.c

run: exercise3
	./exercise3 > exercise3.out 2>&1

clean:
	rm -f exercise1 exercise2 exercise3
CC = gcc
CFLAGS = -Wall -Wextra -fno-stack-protector

all: exercise1 exercise2

exercise1: exercise1.c otherfuncs.o
	$(CC) $(CFLAGS) -o exercise1 exercise1.c otherfuncs.o

otherfuncs.o: otherfuncs.c
	$(CC) $(CFLAGS) -c otherfuncs.c

exercise2: exercise2.c
	$(CC) $(CFLAGS) -o exercise2 exercise2.c

clean:
	rm -f exercise1.o otherfuncs.o
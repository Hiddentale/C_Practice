CC = gcc
CFLAGS = -Wall -Wextra

all: parsegenome

parsegenome: parsegenome.o
	$(CC) -o parsegenome parsegenome.o

parsegenome.o: parsegenome.c
	$(CC) -c parsegenome.c

clean:
	rm -f parsegnome parsegenome.o

CC = gcc
CFLAGS = -Wall -Wextra

all: parsegenome

parsegenome: parsegenome.o
	$(CC) $(CFLAGS) -o parsegenome parsegenome.o

parsegenome.o: parsegenome.c
	$(CC) $(CFLAGS) -c parsegenome.c

clean:
	rm -f parsegnome parsegenome.o

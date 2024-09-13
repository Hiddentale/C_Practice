CC = gcc
CFLAGS = -Wall -Wextra -I..

all: parsegenome

parsegenome: parsegenome.o execute_bash_script.o
	$(CC) $(CFLAGS) -o parsegenome parsegenome.o execute_bash_script.o

parsegenome.o: parsegenome.c ../execute_bash_script.h
	$(CC) $(CFLAGS) -c parsegenome.c

execute_bash_script.o: ../execute_bash_script.c ../execute_bash_script.h
	$(CC) $(CFLAGS) -c ../execute_bash_script.c

clean:
	rm -f parsegenome parsegenome.o

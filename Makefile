CC = gcc
CFLAGS = -Wall -Wextra
OBJS = main.o utils.o

hello: $(OBJS)
	$(CC) $(CFLAGS) -o hello $(OBJS)

main.o: main.c utils.h
	$(CC) $(CFLAGS) -c main.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f hello $(OBJS)
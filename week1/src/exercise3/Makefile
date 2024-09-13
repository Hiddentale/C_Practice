CC = gcc
CFLAGS = -Wall -Wextra -I..
FIRST_OUTPUT_FILE = urandom_byte_output.txt
SECOND_OUTPUT_FILE = urandom_uint16_output.txt
SECOND_TEMP_OUTPUT_FILE = urandom_uint16_temp_output.txt

all: urandom_loop_bytes urandom_loop_uint16

urandom_loop_bytes: urandom_loop_bytes.o urandom_reading.o ../execute_bash_script.o
	$(CC) $(CFLAGS) -o urandom_loop_bytes urandom_loop_bytes.o urandom_reading.o ../execute_bash_script.o
 
urandom_loop_uint16: urandom_loop_uint16.o urandom_reading.o ../execute_bash_script.o
	$(CC) $(CFLAGS) -o urandom_loop_uint16 urandom_loop_uint16.o urandom_reading.o ../execute_bash_script.o

urandom_loop_bytes.o: urandom_loop_bytes.c urandom_reading.h
	$(CC) $(CFLAGS) -c urandom_loop_bytes.c 

urandom_loop_uint16.o: urandom_loop_uint16.c urandom_reading.h
	$(CC) $(CFLAGS) -c urandom_loop_uint16.c 

urandom_reading.o: urandom_reading.c urandom_reading.h ../execute_bash_script.h
	$(CC) $(CFLAGS) -c urandom_reading.c

execute_bash_script.o: ../execute_bash_script.c ../execute_bash_script.h
	$(CC) $(CFLAGS) -c ../execute_bash_script.c

run: urandom_loop_bytes
	./urandom_loop_bytes > $(FIRST_OUTPUT_FILE)
	./make_file_helper.sh

clean:
	rm -f urandom_loop_bytes urandom_loop_bytes.o $(OUTPUT_FILE) urandom_loop_uint16 urandom_loop_uint16.o

.PHONY: run clean	
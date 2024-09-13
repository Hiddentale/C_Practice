#!/bin/bash

rm -f ./urandom_uint16_output.txt

for i in {1..10}; do 
		./urandom_loop_uint16 > urandom_uint16_temp_output.txt
		wc -l < urandom_uint16_temp_output.txt >> ./urandom_uint16_output.txt
	done
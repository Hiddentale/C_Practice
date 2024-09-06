#!/bin/bash

output_file="output.txt"
characters=('A' 'C' 'G' 'T')

> "$output_file"

generate_character() {
    character=${characters[$RANDOM % 4]}
    echo -n $character
}
for ((line = 0; line < 500; line++)); do
    for ((char = 0; char < 100; char++)); do
        generate_character 
    done >> "$output_file"
    echo >> "$output_file"
done

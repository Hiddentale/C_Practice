#!/bin/sh

filename="$1"
string="$2"

echo "Searching for '$string' in file '$filename'"

count=$(tr  -d '\n' < $filename | grep -o $string | wc -l)

echo "The sequence appears $count times."
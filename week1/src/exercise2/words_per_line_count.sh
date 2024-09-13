#!/bin/bash

filename="$1"
line_number="$2"

sed -n "${line_number}p" $filename | tr -d "\n" | wc -c
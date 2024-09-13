#!/bin/sh

filename="$1"
string="$2"

tr  -d '\n' < $filename | grep -o $string | wc -l
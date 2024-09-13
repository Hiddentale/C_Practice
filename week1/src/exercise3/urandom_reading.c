#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <execute_bash_script.h>
#include "urandom_reading.h"

uint16_t read_uint16() {
    char* pointer_to_value = execute_bash_script("od -An -N2 -t u2 < /dev/urandom");
    uint16_t value = (uint16_t) strtoul(pointer_to_value, NULL, 10);
    return value;   
}

int read_bytes() {
    char* pointer_to_value = execute_bash_script("od -An -N1 -t d1 < /dev/urandom");
    int value = atoi(pointer_to_value);
    return value;
}
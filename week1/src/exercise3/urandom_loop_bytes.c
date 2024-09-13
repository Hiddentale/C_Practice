#include <stdio.h>
#include <stdlib.h>
#include <execute_bash_script.h>
#include "urandom_reading.h"

int main() {
    while (1) {
        int value = read_bytes();
        printf("%d %u %x\n", value, value, value);
        if (value == 42) {
            return 0;
        }
    }
}
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <execute_bash_script.h>
#include "urandom_reading.h"

int main() {
    while (1) {
        uint16_t value = read_uint16();
        printf("%04" PRIx16 "\n", value);
        if (value == 42) {
            return 0;
        }
    }
}
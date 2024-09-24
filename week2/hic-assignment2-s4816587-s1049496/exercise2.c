#include<stdbool.h>
#include<stdio.h>

int main() {
    bool x = true;
    bool y = false;
    bool z = 4;

    printf("A bool uses %zu byte.\n", sizeof(x));
    printf("The hexadecimal representation of true is 0x%08x.\n", x);
    printf("The hexadecimal representation of false is 0x%08x.\n", y);
    printf("The hexadecimal representation of a positive value is 0x%08x.\n", z);
    return 0;
}

//https://www.w3schools.com/c/c_booleans.php
//The boolean type is defined as: false if 0, true for any other value.
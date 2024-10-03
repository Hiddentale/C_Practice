#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define MAX_VALUE 4194304
extern int unknown_function();
int main(void)
{   
    int bytes = 0;
    char c;
    char *p = &c;
    for (int i = 0; i < MAX_VALUE; i++) {
        *p = 'x';
        p--;
    }
    p++;

    unknown_function();

    while (*p == 'x') {
        p++;
        bytes++;
    }

    printf("The stack usage of this function was approximately %d bytes.\n", MAX_VALUE-bytes);
    return 0;
}
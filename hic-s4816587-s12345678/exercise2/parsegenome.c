#include <stdio.h>

int main(int argument_count, char *cli_arguments[]) {
    if (argument_count == 1) {
    printf("Hello %s\n", cli_arguments[1]);
    }
    else {
        printf("No argument or too many arguments provided, please only give one text file as input.");
    }
}
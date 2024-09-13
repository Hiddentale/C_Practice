#include <stdio.h>
#include <stdlib.h>
#include <execute_bash_script.h>

char* execute_bash_script(const char* path) { //https://man7.org/linux/man-pages/man3/popen.3.html, https://c-for-dummies.com/blog/?p=1418
    static char output[100000];
    FILE* connection = popen(path, "r");
    fgets(output, sizeof(output), connection);  //https://www.educative.io/answers/how-to-use-the-fgets-function-in-c
    pclose(connection);
    return output;
}
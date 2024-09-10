#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* execute_bash_script(const char* path) { //https://man7.org/linux/man-pages/man3/popen.3.html, https://c-for-dummies.com/blog/?p=1418
    static char output[100000];
    FILE* connection = popen(path, "r");
    fgets(output, sizeof(output), connection);  //https://www.educative.io/answers/how-to-use-the-fgets-function-in-c
    pclose(connection);
    return output;
}

bool format_is_correct(const char* current_text_file) {
    char input[128];
    snprintf(input, sizeof(input), "./total_line_count.sh %s", current_text_file); //https://cplusplus.com/reference/cstdio/snprintf/
    char* line_count_string = execute_bash_script(input);
    int line_count = atoi(line_count_string); //https://www.oreilly.com/library/view/c-in-a/0596006977/re15.html
    if (line_count == 500) {
        for (int i = 0; i < line_count; i++) {
            char input[128];
            snprintf(input, sizeof(input), "./words_per_line_count %s %d", current_text_file, i);
            char* word_count_string = execute_bash_script(input);
            int word_count = atoi(word_count_string);
            if (word_count != 100) {
                return false; 
            }
        }
        char input[128];
        snprintf(input, sizeof(input), "./give_all_characters %s", current_text_file);
        char* letter_array = execute_bash_script(input);
        unsigned int array_length = strlen(letter_array);
        for (int i = 0; i < (int) array_length; i++)
        {
            char current_character = letter_array[i];
            if (current_character != 'A' && current_character != 'C' && current_character != 'G' && current_character != 'T') {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main(int argument_count, char *cli_arguments[]) {
    if (argument_count > 1) {
        const char* current_text_file = cli_arguments[0];
        if (format_is_correct(current_text_file) == true) {
            const char* letter_array[] = {"A", "C", "T", "G"};
            for (int i = 0; i < 4; i++) {
                char input[128];
                snprintf(input, sizeof(input), "./genome.sh %s %s", current_text_file, letter_array[i]);
                char* number_of_repeats_string = execute_bash_script(input);
                int number_of_repeats = atoi(number_of_repeats_string);
                printf("%d", number_of_repeats);
            }
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        printf("No argument or too many arguments provided, please only give one text file as input.");
    }
}
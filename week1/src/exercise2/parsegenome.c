#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "execute_bash_script.h"

#define NO_VALUE -1

char* retrieve_data_from_bash_script(const char* string, const char* current_text_file, int optional_i, const char* optional_array) {
    char input[128];
    if (optional_i != NO_VALUE) {
        snprintf(input, sizeof(input), string, current_text_file, optional_i); //https://cplusplus.com/reference/cstdio/snprintf/
        char* word_count_string = execute_bash_script(input);
        return word_count_string;
    }
    else if (optional_array != (void*) NO_VALUE)
    {
        snprintf(input, sizeof(input), string, current_text_file, optional_array);
        char* word_count_string = execute_bash_script(input);
        return word_count_string;
    }
    else {
        snprintf(input, sizeof(input), string, current_text_file);
        char* word_count_string = execute_bash_script(input);
        return word_count_string;
    }
    
    snprintf(input, sizeof(input), string, current_text_file);
    char* word_count_string = execute_bash_script(input);
    return word_count_string;
}

bool format_is_correct(const char* current_text_file) {
    int line_count = atoi(retrieve_data_from_bash_script("./total_line_count.sh %s", current_text_file, NO_VALUE, (void*) NO_VALUE));
    if (line_count == 500) {
        for (int i = 1; i <= line_count; i++) {
            int word_count = atoi(retrieve_data_from_bash_script("./words_per_line_count.sh %s %d", current_text_file, i, (void*) NO_VALUE));
            if (word_count != 100) {
                return false; 
            }
        }
        char* letter_array = retrieve_data_from_bash_script("./give_all_characters.sh %s", current_text_file, NO_VALUE, (void*) NO_VALUE);
        int array_length = strlen(letter_array);
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
        const char* current_text_file = cli_arguments[1];
        if (format_is_correct(current_text_file) == true) {
            const char* letter_array[] = {"A", "C", "T", "G"};
            for (int i = 0; i < 4; i++) {
                int number_of_repeats = atoi(retrieve_data_from_bash_script("./genome.sh %s %s", current_text_file, NO_VALUE, letter_array[i]));
                printf("%s: %d\n", letter_array[i],number_of_repeats);
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
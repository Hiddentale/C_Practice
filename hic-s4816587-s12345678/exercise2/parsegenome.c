#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool format_is_correct(const char* current_text_file) {
    int line_count = execute_bash_script(("./total_line_count.sh %s", current_text_file));
    if (line_count == 500) {
        for (int i = 0; i < line_count; i++) {
            int word_count = execute_bash_script(("./words_per_line_count %s %s", current_text_file, i));
            if (word_count != 100) {
                return false;
            }
        }
        const char* letter_array = execute_bash_script(("./give_all_characters %s", current_text_file));
        unsigned int array_length = strlen(letter_array);
        for (int i = 0; i < array_length; i++)
        {
            char current_character = letter_array[i];
            if (current_character != "A" && current_character != "C" && current_character != "G" && current_character != "T") {
                return false;
            }
        }
        return true;
    }
}

const char* execute_bash_script(const char* path) { //https://man7.org/linux/man-pages/man3/popen.3.html, https://c-for-dummies.com/blog/?p=1418, https://www.educative.io/answers/how-to-use-the-fgets-function-in-c
    static char* output[10000000];
    FILE *connection = popen(path, "r");
    fgets(output, sizeof(output), connection);
    pclose(connection);
    return output;
}

int main(int argument_count, char *cli_arguments[]) {
    if (argument_count > 1) {
        const char* current_text_file = cli_arguments[0];
        if (format_is_correct(current_text_file) == true) {
            const char* letter_array[] = {"A", "C", "T", "G"};
            for (int i = 0; i < 4; i++) {
                int number_of_repeats = execute_bash_script(("./genome.sh %s %s", current_text_file, letter_array[i]));
                printf(number_of_repeats);
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
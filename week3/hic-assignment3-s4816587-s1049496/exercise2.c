#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
 void binary_search_malloc() {
    size_t lower_number = 0;
    size_t higher_number = (size_t) - 1;
    size_t median;
    void* allocated_memory;

    while (lower_number <= higher_number) {
        median = lower_number + (higher_number - lower_number) / 2;

        allocated_memory = malloc(median);
        if (allocated_memory != NULL) {
            free(allocated_memory);
            lower_number = median + 1;
        } else {
            higher_number = median - 1;
        }
    }
    printf("One malloc can allocate at most %zu bytes.\n", higher_number);
 }

  void binary_search_calloc() {
    size_t lower_number = 0;
    size_t higher_number = (size_t) - 1;
    size_t median;
    void* allocated_memory;

    while (lower_number <= higher_number) {
        median = lower_number + (higher_number - lower_number) / 2;

        allocated_memory = calloc(median, 1);
        if (allocated_memory != NULL) {
            free(allocated_memory);
            lower_number = median + 1;
        } else {
            higher_number = median - 1;
        }
    }
    printf("One calloc can allocate at most %zu bytes.\n", higher_number);
 }

 int main() {
    binary_search_malloc();
    binary_search_calloc();
 }
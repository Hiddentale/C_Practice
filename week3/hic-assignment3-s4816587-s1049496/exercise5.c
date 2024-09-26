// vim: shiftwidth=4 tabstop=4 softtabstop=4 noexpandtab
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void heap_attack(void) {
	// ...
}

int main(void) {
	char *s1 = malloc(9);
	if (s1 == NULL) { return 1; }
	char *s2 = malloc(9);
	if (s2 == NULL) { return 1; }

	strcpy(s1, "s0123456");
	strcpy(s2, "s3456789");

	heap_attack();

	printf("student 1: %s\n", s1);
	printf("student 2: %s\n", s2);
	return 0;
}

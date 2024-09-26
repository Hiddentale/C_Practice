// vim: shiftwidth=4 tabstop=4 softtabstop=4 noexpandtab
#include <stdlib.h>
#include <stdio.h>
int main(void) {
	int i,j;
	unsigned long long **m, **mt;
	while (1) {
		// allocate matrix m
		m = malloc(1000 * sizeof(unsigned long long*));
		if (m == NULL) { return -1; }
		for (i = 0; i < 1000; i++) {
			m[i] = malloc(1000 * sizeof(unsigned long long));
			if (m[i] == NULL) { return -1; }
		}

		// allocate matrix mt
		mt = malloc(1000 * sizeof(unsigned long long*));
		if (mt == NULL) { return -1; }
		for (i = 0; i < 1000; i++) {
			mt[i] = malloc(1000 * sizeof(unsigned long long));
			if (mt[i] == NULL) { return -1; }
		}

		// fill matrix m with values
		for (i = 0; i < 1000; i++) {
			for (j = 0; j < 1000; j++) {
				m[i][j] = 1000 * i + j;
			}
		}

		// transpose matrix m, write to mt
		for (i = 0; i < 1000; i++) {
			for (j = 0; j < 1000; j++) {
				mt[i][j] = m[j][i];
			}
		}

		// free matrices m and mt
		free(m);
		free(mt);
	}
	return 0;
}

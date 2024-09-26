// vim: shiftwidth=4 tabstop=4 softtabstop=4 noexpandtab
#include <inttypes.h>
#include <stdio.h>

int main(void) {
	int32_t x[4];
	x[0] = 23;
	x[1] = 42;
	x[2] = 5;
	x[3] = (1<<7);

	printf("%p\n", (void*) x);           // prints 0x7ffc0ffeef20
	printf("%p\n", (void*) &x);          // (a)
	printf("%p\n", (void*) (x+1));       // (b)
	printf("%p\n", (void*) (&x+1));      // (c)
	printf("%" PRId32 "\n", *x);         // (d)
	printf("%" PRId32 "\n", *x+x[2]);    // (e)
	printf("%" PRId32 "\n", *x+*(x+3));  // (f)
	return 0;
}


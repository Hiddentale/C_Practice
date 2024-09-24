#include <stddef.h>
#include <stdio.h>
#include <string.h>

void addvector(int* z, int* x, int* y, unsigned int len) {
	for (unsigned int i = 0; i < len; i++) {
		*(z + i) = *(x + i) + *(y + i);
	}
}

int my_memcmp(const void* object1, const void* object2, size_t number_of_bytes_to_compare) {

	const unsigned char* obj1 = (const char*) object1; //I had a ton of problems getting this code to work similarly to memcmp,
													   //I randomly changed the pointer type to an unsigned char, and it fixed the problem
													   //this might be because a char object can only go up to 127? and will then overflow into negative numbers?
	const unsigned char* obj2 = (const char*) object2;

	for (unsigned int i = 0; i < number_of_bytes_to_compare; i++) { 			
		if (*(obj1 + i) != *(obj2 + i)) {
			return *(obj2 + i) - *(obj1 + i);
		}
	}
	return 0;
}

int my_memcmp_backwards(const void* object1, const void* object2, size_t number_of_bytes_to_compare) {
	const unsigned char* obj1 = (const char*) object1;
	const unsigned char* obj2 = (const char*) object2;

	for (int i = number_of_bytes_to_compare - 1; i >= 0; i--) { 			
		if (*(obj1 + i) != *(obj2 + i)) {
			return *(obj2 + i) - *(obj1 + i);
		}
	}
	return 0;
}

int main(void) {
	int len = 10;
	int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	long int a = 12930128093;
	long int b = 123;
	int y[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int z[len];

	addvector((int *) &z, (int *) &x, (int *) &y, len);

	
	for (unsigned int i = 0; i < len; i++) {
		printf("%d: %d ", i, z[i]);
	}
	printf("\n");

	printf("%d\n", memcmp(&a, &b, 8)); //I don't get why the implementation is different compared to mine
									   //I must say that the documentation is very unclear (like most)
	printf("%d\n", my_memcmp(&a, &b, 8));
	printf("%d\n", my_memcmp_backwards(&a, &b, 8));
}
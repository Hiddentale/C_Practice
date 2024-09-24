#include <stdio.h>

int main(void) {
	short i = 0x1234;
	char x = -127;
	long sn1 = 4816587;
	long sn2 = 1049496;
	int y[2] = {0x11223344,0x44332211};

	//https://www.cyberciti.biz/faq/how-to-redirect-standard-error-in-bash/

	fprintf(stderr, "address\t\tcontent (hex)\tcontent (dec)\n");
	printf("%p\t%x\t\t%d\n", (char*) &i, *((char*) &i), *((char*) &i));
	printf("%p\t%x\t\t%d\n", (char*) &i + 1, *(((char*) &i) + 1), *(((char*) &i) + 1));
	printf("%p\t%x\t\t%d\n",  &x, x, x);
	for (int j = 0; j < sizeof(sn1); j++) {
		printf("%p\t%x\t\t%d\n", (char*) &sn1 + j, *(((unsigned char*) &sn1) + j), *(((unsigned char*) &sn1) + j));
	}
	for (int j = 0; j < sizeof(sn2); j++) {
		printf("%p\t%x\t\t%d\n", (char*) &sn2 + j, *(((unsigned char*) &sn2) + j), *(((unsigned char*) &sn2) + j));
	}
	for (int j = 0; j < 8; j++) {
		printf("%p\t%x\t\t%d\n", (char*) &y + j, *(((char*) &y) + j), *(((char*) &y) + j));
	}
	return 0;
} 

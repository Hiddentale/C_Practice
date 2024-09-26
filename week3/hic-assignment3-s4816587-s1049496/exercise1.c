#include <stdio.h>

extern int unknown_function();

int main(void)
{
	long stack_adress_before_function = 0xB00BAB00BAB00BA;
	unknown_function();
	long top_of_stack;
	long* tos = &top_of_stack;

	int i = 0;
	int approximate_bytes = 0;
	while (i < 524290) {
		printf("%p: %p\n", (void*) tos, *tos);	
		if (*tos == stack_adress_before_function) {
			break;
		}
		approximate_bytes += sizeof(*tos);
		i++;
		tos++;
	}
	printf("\napproximate_number_of_bytes: %d\n", approximate_bytes);
	return 0;
}
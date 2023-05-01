#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

int fahr_to_cel(int f);

int main() {
	int i;

	for (i = 0; i <= UPPER; i = i + STEP) 
		printf("%d\t %d\n", i, fahr_to_cel(i));

	return 0;
}

int fahr_to_cel(int f) {
	int c;

	c = (5.0/9) * (f - 32); 

	return c;
}

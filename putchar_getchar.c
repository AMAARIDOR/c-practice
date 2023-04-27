#include <stdio.h>

/* count characters input; 1st version */

main() {
	char x = "String";
	int y = 129389; 
	long z = "A very long string with 1234"; 
	
	printf("%lu\n", sizeof(x));
	printf("%lu\n", sizeof(y));
	printf("%lu\n", sizeof(z));

	return 0;
}

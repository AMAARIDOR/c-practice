#include <stdio.h>

#define TAB_WIDTH 4

void main(void) {
	int tc = 1;
	while (1) {
		switch (getchar()) {
			case EOF:
				goto histogram_print;
			case '\t':
				tc += TAB_WIDTH;
				break;
			case '\n':
				break;
			default:
				++tc;
				break;
		}
	}
histogram_print:
	while (--tc) {
		putchar('-');
	}
	putchar('\n');

	return 0;
}

#include <stdio.h>

static inline
void histogram(void) {
	int space = 1;
	int tab = 1;
	int newline = 1;
	int other = 1;
	while (1) {
		switch (getchar()) {
			case EOF:
				goto histogram_print;
			case '\t': ++tab; break;
			case '\n': ++newline; break;
			case ' ': ++space; break;
			default: ++other; break;
		}
	}
histogram_print:
	puts("characters:");
	while (--other) putchar('-');
	puts("\nspaces:");
	while (--space) putchar('-');
	puts("\ntabs:");
	while (--tab) putchar('-');
	puts("\nnewlines:");
	while (--newline) putchar('-');
	putchar('\n');
}

int main(void) {
	histogram();
	return 0;
}

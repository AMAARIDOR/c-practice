#include <stdio.h>

int main() {
	int c, tc, tb, tt, tn;

	c = 0; 
	tc = 0;
	tb = 0;
	tt = 0;
	tn = 0;

	while ((c = getchar()) != EOF) {
		if (c != ' ' || c != '\n' || c != '\t')
			tc++;
		else if (c == ' ')
			tb++;
		else if (c == '\t')
			tt++;
		else if (c == '\n')
			tn++;
	}

	putchar('\n');

	for (int i = 0; i < tc; i++) {
		printf("%s", "-");
	}

	putchar('\n');

	for (int i = 0; i < tb; i++) {
		printf("%s", "-");
	}
	
	putchar('\n');

	for (int i = 0; i < tt; i++) {
		printf("%s", "-");
	}

	putchar('\n');

	for (int i = 0; i < tn; i++) {
		printf("%s", "-");
	}
	
	putchar('\n');

	return 0;
}

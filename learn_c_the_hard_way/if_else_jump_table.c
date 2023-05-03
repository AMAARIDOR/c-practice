#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("ERROR: You need one argument.\n");
		return 1;
	}

	int i = 0;
	for (i = 0; argv[1][i] != '\0'; i++) {
		char letter = argv[1][i];

		if (letter == 'A' || letter == 'a') {
			printf("%d,'A'\n", i);
		} else if (letter == 'E' || letter == 'e') {
			printf("%d,'E'\n", i);
		} else if (letter == 'I' || letter == 'i') {
			printf("%d,'I'\n", i);
		} else if (letter == 'O' || letter == 'o') {
			printf("%d,'O'\n", i);
		} else if (letter == 'U' || letter == 'u') {
			printf("%d,'U'\n", i);
		} else if (letter == 'Y' || letter == 'y') {
			printf("%d,'Y'\n", i);
		} else {
			printf("%d: %c is not a vowel\n", i, letter);
		}
	}
	return 0;
}

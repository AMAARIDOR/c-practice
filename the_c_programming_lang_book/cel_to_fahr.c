#include <stdio.h>

/* print Fahrenheit-Celsius table
 	for fahr = 0, 20, ..., 300 */

main() {
	float cel, fahr;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	cel = lower;
	printf("%3s %6s\n", "Celsius", "Fahrenheit");

	while (cel <= upper) {
		fahr = cel * 1.8 + 32;
		printf("%3.0f %6.1f\n", cel, fahr);
		cel = cel + step;
	}
}

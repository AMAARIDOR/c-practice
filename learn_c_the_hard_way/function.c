#include <stdio.h>

int main() {
    int testInteger;

    printf("Enter a integer: ");

    scanf("%d", &testInteger);

    printf("Number = %d\n", testInteger);

    return 0;
}

// function definition
int sum(int num1, int num2) {
    return (num1 + num2); 
}
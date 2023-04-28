#include <stdio.h>

int main() {
    int a = 0;
    int b = 100909213;

    do {
        printf("%d\n", a++);
    } while (a < b);

    return 0;
}
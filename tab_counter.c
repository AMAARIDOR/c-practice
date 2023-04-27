#include <stdio.h>

int main() {
    int c, tb;

    tb = 0;

    while ((c = getchar()) != '\n')
        if (c == ' ')
            ++tb;
    printf("%d\n", tb);
}
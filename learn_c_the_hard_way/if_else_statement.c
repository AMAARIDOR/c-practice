#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    start = clock();

    int num = 0;

    while (num < 1000) {
        printf("%d\n", num);
        num++;
    }

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;

    printf("Time taken to execute in seconds : %f\n", duration);

    return 0;
}
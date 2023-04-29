#include <stdio.h>
#include <stdbool.h>

int main() {
    bool yes = false;

    if (yes == true) {
		printf("Something");
        goto fail;
    }
    
    fail:
        printf("fail condition");

    return 0;
}

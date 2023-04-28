#include <stdio.h>
#include <stdbool.h>

enum Level {
    LOW = 25,
    MEDIUM = 50,
    HIGH = 75 
};

enum Bread {
    SOUR = 4,
    NORMAL = 2,
    CROISSANT = 5
};

int main() {
    bool yes = false;
    enum Level myVar = MEDIUM;
    enum Bread leastFavoriteBread = NORMAL; 

    if (yes == true) {
        printf("something");
    }

    printf("%d\n", myVar);
    printf("%d\n", leastFavoriteBread);

    return 0;
}
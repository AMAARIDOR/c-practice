#include <stdio.h> // Provides basic C functions
#include <assert.h> // Provides assert macro
#include <stdlib.h> // Provides free and malloc
#include <string.h> // Provides some stuff idk

// Define a structure with char pointer and integer
struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

// Make a pointer for the Person structure and define a Person_create function 
struct Person *Person_create(char *name, int age, int height, int weight) {
    // Make a *who pointer for allocation of memory for the Person structure
    struct Person *who = malloc(sizeof(struct Person));
    // Check if the memory isn't NULL
    assert(who != NULL);

    // Assign the values to the arguments of the structure
    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight; 

    return who;
}

// Make Person_destroy function to destroy the instances of the Person structure
void Person_destroy(struct Person *who) {
    assert(who != NULL);

    // Free memory because C doesn't have built-in garbage collector 
    free(who->name);
    free(who);
}

// Make a Person_print function for the Person structure which prints the name, age, height and weight of the instance
void Person_print(struct Person *who) {
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

// Main function 
int main(int argc, char *argv[]) {
    // Make two people structure
    struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
    struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

    // Print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);

    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);

    // Make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->height += 20;
    Person_print(frank);

    // Destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}
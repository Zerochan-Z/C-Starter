#include <stdio.h>
#include <string.h>

int main() {
    char name[10] = "Hello";

    printf("The word is: %s\n", name);
    printf("Array size: %d\n", 10);
    printf("String length: %zu\n", strlen(name)); // %zu -> the length of name

    return 0;
}
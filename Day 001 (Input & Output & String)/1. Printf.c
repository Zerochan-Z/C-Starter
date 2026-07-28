#include <stdio.h>

int main() {
    int age = 25;
    float height = 5.9;
    char grade = 'A';

    // variables is implement into %_
    printf("Age: %d\n", age); // %d is required for printing int
    printf("Height: %.1f\n", height); // %.1f = 1 dec
    printf("Grade: %c\n", grade); // %c = char
    printf("Name: %s\n", "Alex"); // %s = string

    return 0;
}
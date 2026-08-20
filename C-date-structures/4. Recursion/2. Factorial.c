#include <stdio.h>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }

    return n * factorial(n - 1);
    // Function runs in function == recursion
}

int main() {
    printf("Factorial of 5: %d\n", factorial(5));
    printf("Factorial of 0: %d\n", factorial(0));
    printf("Factorial of -1: %d\n", factorial(-1));

    return 0;
}
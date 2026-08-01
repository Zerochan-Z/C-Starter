#include <stdio.h>

int main() {
    int matrix[3][3];

    printf("Enter 9 integers: ");
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            scanf("%d", &matrix[i][k]); 
            
            // RULE: Always use & with scanf for integers (and most data types).
            // The only exception is strings (char arrays) where the array name 
            // already acts as an address.
            
            // %d tells scanf: "The user will type an integer."
            
            // With &, you give scanf the actual address of your box.
            // scanf writes the user's input safely into your box.
            
            // If you forget &, scanf receives the current value inside 
            // matrix[i][k] (which is garbage). 
            // It hands that garbage number to scanf.
            // scanf thinks that garbage number is a REAL memory ADDRESS.
            // It tries to write the user's input to that fake address.
            // The operating system says "That's not yours!" and crashes your program.
        }
    }

    int rowSum[3] = {0, 0, 0};
    int total = 0;
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            rowSum[i] += matrix[i][k];
            total += matrix[i][k];
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("\nSum of row %d : %d\n", i+1 , rowSum[i]);
    }
    printf("Average: %.1f\n", (double)total / 9);

    return 0;
}
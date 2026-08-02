#include <stdio.h>

void swap(int* a, int* b) { 
    // POINTERS (int*): These parameters hold memory addresses.
    // When we call swap(&a, &b), we pass the addresses of a and b.
    
    // *a means: "Go to the address stored in 'a' and look at the value there."
    // *b means: "Go to the address stored in 'b' and look at the value there."
    
    int temp = *a;   // Save the value at address a
    *a = *b;         // Put the value at address b into address a
    *b = temp;       // Put the saved value into address b
    
    // WITHOUT pointers (int a, int b):
    // The function receives COPIES of the values.
    // Changes inside the function only affect the copies.
    // The original variables remain unchanged after the function ends.
}

int main() {
    int a, b;
    printf("Enter 2 integers: ");
    scanf("%d %d",&a, &b);

    printf("a before swapping: %d\n", a);
    printf("b before swapping: %d\n", b);
    
    // Pass the ADDRESSES of a and b using &
    swap(&a, &b);
    
    printf("After swapping, a = %d, b = %d", a, b);

    return 0;
}
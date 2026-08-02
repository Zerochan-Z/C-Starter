/*
#include <stdio.h>

void printArray1(int arr[], int size) { 
    // int arr[] is automatically translated to int *arr.
    // The compiler treats them as identical.
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
    }
}

void printArray2(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", *(arr + i));   // arr + i moves to the i-th element
    }
}

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    printf("%d", arr[0]);    
    printf("%d", *arr);      
    // *arr goes to the address arr and reads the value there

    printf("%d", arr[2]);      
    printf("%d", *(arr + 2));    
    // arr + 2 moves 2 steps forward, * reads the value

    printArray1(arr, 5);   // arr is the address of the first element
    printArray2(arr, 5);   // Same as above

    // Both functions print the same values using different syntax.
}
*/

#include <stdio.h>

void doubleArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        // *(arr + i) goes to the i-th element and doubles it
        *(arr + i) = *(arr + i) * 2;
        // -> arr[i] = arr[i] * 2;
    }
}

int main() {
    int arr[5];

    printf("Enter 5 numbers: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);   // & gives the address of arr[i]
    }

    printf("Before doubling: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);   // Access using array syntax
    }

    printf("\nAfter doubling: ");
    doubleArray(arr, 5);         
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(arr + i));  
    }

    // arr = address of arr[0]
    // &arr[i] = address of arr[i]
    // &arr = whole arr adress (rare)

    printf("\n");

    return 0;
}
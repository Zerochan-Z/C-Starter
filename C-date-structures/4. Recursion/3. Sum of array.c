#include <stdio.h>

int sum_array(int arr[], int n) {
    if (n == 0) {
        return 0;
    }

    return arr[0] + sum_array(arr + 1, n -1);
    // arr[0] + {arr[0 + 1] && (size of array - 1)}
    // Add first element to the sum of the remaining (n-1) elements
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    printf("Sum of 5 array: %d\n", sum_array(arr1, 5));

    int arr2[] = {42};
    printf("Sum of one array: %d\n", sum_array(arr2, 1));

    int arr3[] = {};
    // These 3 are basically same
    printf("Sum of empty array: %d\n", sum_array(arr3, 0));
    // Minor issue exist because
    // You declared an empty array (int arr3[] = {};) with size 0, 
    // but sum_array tries to access arr[0] when n > 0. 
    // If someone accidentally calls sum_array(arr3, 5)
    // it would read memory that doesn't belong to the array, causing a buffer overflow.

    printf("Sum of empty array: %d\n", sum_array(NULL, 0));
    printf("Sum of empty array: %d\n", sum_array((int[]){0}, 0));

    return 0;
}
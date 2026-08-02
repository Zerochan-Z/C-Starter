#include <stdio.h>

void reverseArray(int* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main() {
    int arr[5];

    printf("Enter 5 integers: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before reversed: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    reverseArray(arr, 5);
    printf("\nAfter reversed: ");
    for (int i  = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
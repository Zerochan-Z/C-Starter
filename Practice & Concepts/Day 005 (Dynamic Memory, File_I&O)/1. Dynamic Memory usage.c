#include <stdio.h>
#include <stdlib.h>

/*
malloc(size) -> Allocates `size` bytes of memory. Returns a pointer to it. 
free(ptr) -> Frees the memory so it can be reused. 
calloc(count, size) -> Allocates memory for an array, sets it to zero. 
realloc(ptr, newSize) -> Resizes an existing block of memory. 
*/

void ReverseArray(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main() {
    int total;
    int *arr;

    printf("Enter total of numbers you want to enter: ");
    scanf("%d", &total);

    // Vector logic behind :
    arr = (int*)malloc(total * sizeof(int));
    // same as new in C++
    // (int*) = type cast 
    // tells compiler "Treat this as a pointer to int"
    // Often kept for clarity or compatibility with C++

    if (arr == NULL) { 
        // if total == 0 then immediately return
        return 1;
    }

    printf("Enter %d number: ", total);
    for (int i = 0; i < total; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Reverse order: ");
    ReverseArray(arr, total);
    for (int i = 0; i < total; i++) {
        printf("%d ", arr[i]);
    }

    int newSize;
    printf("\nEnter new total size: ");
    scanf("%d", &newSize);

    int *temp = realloc(arr, newSize * sizeof(int));
    if (temp == NULL) {
        printf("Memory reallocation failed.\n");
        free (arr);
        return 1;
    } 
    arr = temp;

    // Realloc function: change the size of arr
    printf("Enter %d more numbers: ", newSize - total);
    for (int i = total; i < newSize; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nAfter adding numbers: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    
    int *zeroArr = calloc(newSize, sizeof(zeroArr));

    if (zeroArr == NULL) {
        printf("\nCalloc failed.\n");
        free(zeroArr);
        return 1;
    }

    printf("\nCalloc array (all zeros): ");
    // Calloc function: return everything into zero
    for (int i = 0; i < newSize; i++) {
        printf("%d ", zeroArr[i]);
    }

    free(arr);
    free(zeroArr);

    return 0;
}
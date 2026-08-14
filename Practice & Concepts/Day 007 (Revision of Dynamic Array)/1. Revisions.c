#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* create(int initial) {
    DynamicArray* arr = malloc(sizeof(DynamicArray));
    arr->data = malloc(sizeof(int) * initial);
    arr->size = 0;
    arr->capacity = initial;
    return arr;
}

void append(DynamicArray* arr, int value) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->data = realloc(arr->data, sizeof(int) * arr->capacity);
    }    
    arr->data[arr->size] = value;
    arr->size++;
}

void print(DynamicArray* arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void destroy(DynamicArray* arr) {
    free(arr->data);
    free(arr);
}

int main() {
    DynamicArray* arr = create(2);

    append(arr, 10);
    append(arr, 20);
    append(arr, 30);
    append(arr, 40);

    print(arr);
    destroy(arr);

    return 0;
}
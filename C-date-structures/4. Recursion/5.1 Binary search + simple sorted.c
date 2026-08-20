#include <stdio.h>
#include <string.h>

// Sorted version

void sorted_arr(int arr[], int size) {
    for (int i = 0; i < size - 1;i++) {
        for (int k = 0; k < size - 1 - i; k++) {
            if (arr[k] > arr[k+1]) {
                int temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }
}

int binary_search(int arr[], int left, int right, int target) {
    int mid = (left + right) / 2;

    if (left > right) {
        printf("Target not in array.\n");
        return -1;
    }

    if (arr[mid] < target) {
        return binary_search(arr, mid + 1, right, target);
    } else if (arr[mid] > target) {
        return binary_search(arr, left, mid - 1, target);
    } else {
        return mid;
    }
}

int main() {
    int arr[] = {7, 3, 13, 1, 9, 5 ,11};
    sorted_arr(arr, 7);

    int result = binary_search(arr, 0, 6, 7);
    printf("Index (target 7): %d\n", result);

    result = binary_search(arr, 0, 6, 2);
    printf("Index (target 2): %d\n", result);

    result = binary_search(arr, 0, 6, 13);
    printf("Index (target 13): %d\n", result);

    return 0;
}
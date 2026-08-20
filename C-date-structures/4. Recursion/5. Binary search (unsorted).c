#include <stdio.h>

// Note that this is just basic exercise
// ONLY work on sorted array !
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
    int arr[] = {1, 3, 5, 7, 9, 11, 13};

    int result = binary_search(arr, 0, 6, 7);
    printf("Index (target 7): %d\n", result);

    result = binary_search(arr, 0, 6, 2);
    printf("Index (target 2): %d\n", result);

    result = binary_search(arr, 0, 6, 13);
    printf("Index (target 13): %d\n", result);

    return 0;
}
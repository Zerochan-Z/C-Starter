#include <stdio.h>

int main() {
    int arr[5];

    printf("Enter 5 integers: \n");
    for (int i = 0; i < 5; i++) {
        printf("Number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Reverse order: ");
    for (int i = 4; i > -1;  i--) {
        printf("%d ", arr[i]);
        if (i == 0) {
            printf("\n");
        }
    }
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        sum += arr[i];
    }
    printf("Sum: %d\n", sum);

    double avg = (double) sum / 5;
    printf("Average: %.1f\n", avg);

    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < 5; i++) {
        if (min > arr[i]) {
            min = arr[i];
        } else if (max < arr[i]) {
            max = arr[i];
        }
    }

    printf("Minimum number: %d\n", min);
    printf("Maximum number: %d\n", max);

    return 0;
}
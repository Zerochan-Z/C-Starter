#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[30];

    printf("Enter a filename: ");
    scanf("%s", filename);

    file = fopen(filename, "w");
    int num = 1;
    if (file == NULL) {
        printf("No file opened.\n");
        return 1;
    }

    while (num) {
        printf("Enter a number: ");
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        fprintf(file, "%d ", num);
    }

    fclose(file);
    file = fopen(filename, "r");
    int data;
    if (file == NULL) {
        printf("No file saved for reading.\n");
        return 1;
    }

    while (fscanf(file, "%d", &data) != EOF) {
        printf("%d ", data);
    }

    fclose(file);
}
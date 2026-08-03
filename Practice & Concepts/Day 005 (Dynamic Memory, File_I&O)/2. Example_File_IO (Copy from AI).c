#include <stdio.h>

int main() {
    FILE *file;

    file = fopen("example.txt", "w");

    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    fprintf(file, "Hello, this is a test.\n");
    fprintf(file, "Second line.\n");

    fclose(file);

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Failed to open file for reading.\n");
        return 1;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}
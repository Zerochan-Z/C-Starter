#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char sentence[30];

    file = fopen("test.txt", "w");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    fprintf(file, "%s", sentence);

    fclose(file);

    file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("Failed to open file for reading.\n");
        return 1;
    }

    char test[200];
    while (fgets(test, sizeof(test), file) != NULL) {
        printf("%s", test);
    }

    fclose(file);
    
    return 0;
}
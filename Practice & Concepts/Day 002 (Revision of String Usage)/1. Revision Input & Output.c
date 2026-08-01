#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    printf("Enter your name: ");
    char name[30];
    fgets(name, sizeof(name), stdin);

    size_t len = strlen(name);

    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
        len = strlen(name);
    }
    
    int total = 0;
    for (size_t i = 0; i < len; i++) {
        char upper = toupper(name[i]);
        if (upper == 'A' || upper == 'E' || upper == 'I' || upper == 'O' || upper == 'U') {
            total++;
        }
    }

    if (len == 0) {
        printf("No name entered");
        return 0;
    }

    printf("Name: %s\n", name);
    printf("Length of name: %zu\n", len);
    printf("First character: %c\n", name[0]);
    printf("Last character: %c\n", name[len - 1]);
    printf("Total number of vowels: %d\n", total);

    return 0;
}
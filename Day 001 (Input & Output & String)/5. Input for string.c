#include <stdio.h>
#include <string.h>

int main() {
    char name[20];

    // Bad way 
    printf("Enter your first name: ");
    scanf("%s", name); 
    // Reads until space/ \n then others remains unread (buffer)
    printf("scanf read: %s\n", name);

    // Clear the unread data
    // Includes '\n' and any extra letters
    // This does NOT touch "name" variable !!!! Only cleans unread (buffer)
    while (getchar() != '\n'); 


    // safe way
    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin); 
    // safer because it reads whole line, including spaces
    // but it keeps '\n' (ENTER) inside string

    // How to discard '\n' : 
    size_t len = strlen(name); 
    // strlen = length of name before it hits \0

    // length > 0 & the last char is '\n'
    if (len > 0 && name[len - 1 ] == '\n') {
        name[len - 1] = '\0'; // replace
    }

    printf("Full name: %s\n", name);

    return 0;
}
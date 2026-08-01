#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    printf("Enter a sentence: ");
    char sentence[30];
    fgets(sentence, sizeof(sentence), stdin);

    size_t len = strlen(sentence);
    if (len > 0 && sentence[len -1] == '\n') {
        sentence[len - 1] = '\0';
        len = strlen(sentence);
    } else if (len == 0) {
        printf("No sentence input.\n");
        return 0;
    }

    int words = 0;
    bool inWord = false;
    for (size_t i = 0; i < len; i++) {
        if (isalpha(sentence[i]) && inWord == false) {
            inWord = true;
            words += 1;
        } else if (isspace(sentence[i]) || ispunct(sentence[i])) {
            inWord = false;
        }
    }

    printf("Total words: %d\n", words);
    
    return 0;
}
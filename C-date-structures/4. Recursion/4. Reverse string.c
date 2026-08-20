#include <stdio.h>
#include <string.h>

void reverse_string(char *str, int left, int right) {
    if (left >= right) {
        return;
    } else {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        reverse_string(str, left + 1, right - 1);
    }
}

int main() {
    char str1[] = "hello";
    char str2[] = "a";
    char str3[] = "";
    char str4[] = "racecar";

    reverse_string(str1, 0, strlen(str1) - 1);
    reverse_string(str2, 0, strlen(str2) - 1);
    reverse_string(str3, 0, strlen(str3) - 1);
    reverse_string(str4, 0, strlen(str4) - 1);

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);
    printf("str4: %s\n", str4);

    return 0;
}
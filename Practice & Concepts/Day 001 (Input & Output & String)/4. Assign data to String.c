#include <stdio.h>
#include <string.h>

int main() {
    char name1[10] = "Alex";
    char name2[10];
    
    // name2 = name1;   // ERROR: Cannot assign arrays with '=' in C
    
    // strcpy(name2, name1);  
    // Copies the ENTIRE string from name1 into name2.
    // DANGER: Doesn't check if name2 has enough space.
    // If name1 is larger than name2, it will overflow name2.
    
    // SAFER: strncpy limits how many characters are copied.
    // Copies at most 9 characters from name1 into name2.
    // Stops early if it hits '\0' in the source.
    strncpy(name2, name1, 9); 
    
    // SAFETY: Manually set the last box to '\0'.
    // This guarantees the string ends properly even if
    // strncpy didn't add a null terminator.
    name2[9] = '\0';

    printf("%s", name2); 

    return 0;
}
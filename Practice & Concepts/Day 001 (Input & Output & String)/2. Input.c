#include <stdio.h>

int main() {
    int age; 
    char grade;

    // scanf is strict about the format (%d expects digits), but it is greedy. 
    // It reads as many digits as it can and stops at the first non-digit, 
    // leaving the rest of the input (including letters or '\n') in the buffer.

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter grade: ");
    
    // BAD: scanf("%c", &grade); 
    // This would grab the leftover '\n' (or leftover letter) immediately.

    // FIX 1: Space before %c skips ANY whitespace (spaces, tabs, newlines) 
    // before reading the character. This is the safest fix.
    scanf(" %c", &grade); 
    
    // OR 

    printf("Enter new grade: ");
    // FIX 2: getchar() discards exactly ONE character from the buffer.
    // This only works if exactly one '\n' is left behind. 
    getchar(); 
    scanf("%c", &grade); 

    /* SPECIAL CASE (Important!):
       If the user types "25abc" and presses Enter:
       - scanf("%d") reads '2' and '5', stops at 'a', and leaves "abc\n" in the buffer.
       - getchar() discards ONLY the 'a'. 
       - The "bc\n" is STILL in the buffer. 
       - Your next scanf or getchar will read 'b' next, which may cause a logical bug. 
       - The program will NOT crash, it will just read the wrong data.
    */

    return 0;
}
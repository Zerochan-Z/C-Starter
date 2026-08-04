#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int age;
    float grade;
};

int main() {
    struct Student arr[3];
    int total = 3;
    

    printf("Enter information for 3 students: \n");
    for (int i = 0; i < total; i++) {
        printf("Enter name for the student: ");
        fgets(arr[i].name, sizeof(arr[i].name), stdin);
        int len = strlen(arr[i].name);
        if (len > 0 && arr[i].name[len - 1] == '\n') {
            arr[i].name[len - 1] = '\0';
            len = strlen(arr[i].name);
        }
        printf("Enter the age for the student: ");
        scanf("%d", &arr[i].age);
        printf("Enter grade of the student: ");
        scanf("%f", &arr[i].grade); 

        while(getchar() != '\n'); 
        // Buffer clearning
        // Clears \n to ensure next data input works!
    }

    for (int i = 0; i < total; i++) {
        printf("\nStudent %d: \n", i+1);
        printf("Name : %s\n", arr[i].name);
        printf("Age: %d\n", arr[i].age);
        printf("Grade: %.2f\n", arr[i].grade);
    }
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum {
    PENDING,
    COMPLETED
} Status;

typedef enum {
    LOW,
    MEDIUM,
    HIGH
} Priority;

typedef struct {
    char due_date[11];
    char title[100];
    char description[200];
    Status status;
    Priority priority;
} Task;


int count = 0;
int capacity = 10;
Task *list;

void add_task() {
    if (count == capacity) {
        Task *temp = realloc(list, (capacity + 10) * sizeof(Task));
        if (temp == NULL) {
            printf("Array size added failed.\n");
            return;
        }
        capacity += 10;

        list = temp;
    }
    
    Task t;

    printf("Enter task's title: ");
    fgets(t.title, sizeof(t.title), stdin);
    int len = strlen(t.title);
    if (len > 0 && t.title[len - 1] == '\n') {
        t.title[len - 1] = '\0';
    }

    printf("Enter task's description: ");
    fgets(t.description, sizeof(t.description), stdin);
    len = strlen(t.description);
    if (len > 0 && t.description[len - 1] == '\n') {
        t.description[len - 1] = '\0';
    }

    printf("Enter task's due date: ");
    fgets(t.due_date, sizeof(t.due_date), stdin);
    len = strlen(t.due_date);
    if (len > 0 && t.due_date[len - 1] == '\n') {
        t.due_date[len - 1] = '\0';
    }
    
    printf("Enter priority (2 = HIGH, 1 = MEDIUM, 0 = LOW): ");
    int p;
    scanf("%d", &p);
    getchar();
    t.priority = (Priority)p; // Cast the int to enum type
    t.status = PENDING;
    
    list[count] = t;
    count++;
}

void view_tasks() {

}

int main() {
    list = malloc(capacity * sizeof(Task));
    
    return 0;
}
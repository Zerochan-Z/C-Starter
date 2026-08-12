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

const char* priority_str(Priority p) {
    switch (p) {
        case LOW: return "LOW";
        case MEDIUM: return "MEDIUM"; 
        case HIGH: return "HIGH"; 
        default: return "ERROR"; 
    }
}

const char* status_str(Status s) {
    switch (s) {
        case PENDING: return "PENDING"; 
        case COMPLETED: return "COMPLETED";
        default: return "ERROR";
    }
}

int count = 0;
int capacity = 10;
Task *list;

void save_tasks() {
    FILE *path;

    path = fopen("tasks.txt", "w");
    if (path == NULL) {
        printf("No task file saved.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(path, "%s|%s|%s|%d|%d\n", 
                list[i].title, list[i].description,
                list[i].due_date, list[i].status, list[i].priority);
    }
    fclose(path);
}

void load_tasks() {
    FILE *path;
    path = fopen("tasks.txt", "r");
    if (path == NULL) {
        printf("No task file loaded.\n");
        return;
    }
    
    char line[350];
    while(fgets(line, sizeof(line), path) != NULL) {
        if (count == capacity) {
            Task *temp = realloc(list, (capacity + 10) * sizeof(Task));
            if (temp == NULL) {
                printf("Array size renew failed.\n");
                return;
            }
            capacity += 10;
            list = temp;
        }

        char *token = strtok(line, "|");
        strcpy(list[count].title, token);
        token = strtok(NULL, "|");
        strcpy(list[count].description, token);
        token = strtok(NULL, "|");
        strcpy(list[count].due_date, token);
        token = strtok(NULL, "|");
        list[count].status = (Status)atoi(token);
        token = strtok(NULL, "|");
        list[count].priority = (Priority)atoi(token);

        count++;
    }
}

void add_task() {
    if (count == capacity) {
        Task *temp = realloc(list, (capacity + 10) * sizeof(Task));
        if (temp == NULL) {
            printf("Array size renew failed.\n");
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
    
    printf("Enter priority (0 = LOW, 1 = MEDIUM, 2 = HIGH): ");
    int p;
    scanf("%d", &p);
    getchar();
    t.priority = (Priority)p; // Cast the int to enum type
    t.status = PENDING;
    
    printf("{%s} task saved.\n", t.title);
    list[count] = t;
    count++;

}

void view_tasks() {
    if (count == 0) {
        printf("No task to view.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", i + 1);
        printf("Task title: %s\n", list[i].title);
        printf("Task description: %s\n", list[i].description);
        printf("Due date: %s\n", list[i].due_date);
        printf("Priority: %s\n", priority_str(list[i].priority));
        printf("Status: %s\n\n", status_str(list[i].status));
    }
}

void mark_completed() {
    if (count == 0) {
        printf("No task to mark.\n");
        return;
    }

    int ID;
    printf("Enter the task ID you want to mark as completed.\n");
    printf("ID: ");
    scanf("%d", &ID);
    getchar();
    int index = ID - 1;

    if (index < 0 || index >= count) {
        printf("Invalid ID input.\n");
    } else if (list[index].status == COMPLETED) {
        printf("%d ID is already completed.\n", ID);
    } else {
        list[index].status = COMPLETED;
        printf("%d ID is marked as completed successfully.\n", ID);
    }
}

int main() {
    list = malloc(capacity * sizeof(Task));
    load_tasks();
    int choice;

    do {
        printf("\n1. Add task.\n");
        printf("2. View tasks.\n");
        printf("3. Mark as completed.\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        getchar();

        switch (choice) {
            case 1: add_task(); break;
            case 2: view_tasks(); break;
            case 3: mark_completed(); break;
            case 4: {
                printf("Thanks for using this system!!!.\n");
                save_tasks(); 
                break;   
            }
            default: {
                printf("Enter choice 1-4.\n");
                continue;
            }
        }
    } while (choice != 4);

    free(list);
    return 0;
}
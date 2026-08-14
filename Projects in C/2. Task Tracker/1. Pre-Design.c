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
    int ID;
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

void pad_date(char *date) { 
    // ensure the month, day and year is 2-2-4 digit
    // while sorting, it's a must to set these conditions
    // or else 08 is earlier than 8 although they're the same
    int year, month, day;
    sscanf(date, "%d-%d-%d", &year, &month, &day);
    sprintf(date, "%04d-%02d-%02d", year, month, day);
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
        fprintf(path, "%d|%s|%s|%s|%d|%d\n", 
                list[i].ID, list[i].title, list[i].description,
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
        list[count].ID = atoi(token);
        token = strtok(NULL, "|");
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

    t.ID = count + 1;
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

    printf("Enter task's due date (Y-M-D): ");
    fgets(t.due_date, sizeof(t.due_date), stdin);
    len = strlen(t.due_date);
    if (len > 0 && t.due_date[len - 1] == '\n') {
        t.due_date[len - 1] = '\0';
    }
    pad_date(t.due_date);
    
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
    
    Task **temp = malloc(count * sizeof(Task*)); 
    // temp is array of pointers (Task *)
    //not array of struct (Task)
    // it should be size of pointers not struct
    
    for (int i = 0; i < count; i++) {
        temp[i] = &list[i];
        // temp[i] is one pointer (Task*)
    }
    
    for (int i = 0; i < count - 1; i++) {
        for (int k = 0; k < count - 1 - i; k++) {
            // temp[k]->due_date is dereference the pointer
            // to get the struct then access to title
            if (strcmp(temp[k]->due_date, temp[k + 1]->due_date) > 0) {
                // if [k]->due_date is bigger than [k+1]->due_date
                // swap so earlier date comes first                 
                Task *swap = temp[k];
                temp[k] = temp[k + 1];
                temp[k + 1] = swap;
            } else if (strcmp(temp[k]->due_date, temp[k + 1]->due_date) == 0 && temp[k]->priority < temp[k + 1]->priority) {
                // if temp[k]->due_date and temp[k + 1]->due_date is the same
                // AND [k] priority is lower than [k+1], swap for descending priority                
                Task *swap = temp[k];
                temp[k] = temp[k + 1];
                temp[k + 1] = swap;
            } 
        }
    }

    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", temp[i]->ID);
        printf("Task title: %s\n", temp[i]->title); // same as (*(temp + i)) -> title
        printf("Task description: %s\n", temp[i]->description);
        printf("Due date: %s\n", temp[i]->due_date);
        printf("Priority: %s\n", priority_str(temp[i]->priority));
        printf("Status: %s\n\n", status_str(temp[i]->status));
    }
    free(temp);
}

void mark_completed() {
    if (count == 0) {
        printf("No task to mark.\n");
        return;
    }

    int target_id;
    printf("Enter the task ID you want to mark as completed.\n");
    printf("ID: ");
    scanf("%d", &target_id);
    getchar();

    int found = -1;
    for (int i = 0; i < count; i++) {
        if (list[i].ID == target_id) {
            found = i;
            break;
        } 
    }

    if (found == -1) {
        printf("Target ID %d not found.\n", target_id);
    } else if (list[found].status == COMPLETED) {
        printf("Already completed.\n");
    } else {
        list[found].status = COMPLETED;
        printf("%s marked complete.\n", list[found].title);
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
                printf("Thanks for using this system !\n");
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
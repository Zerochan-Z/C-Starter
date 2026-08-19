#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    Node *tail;
} List;

Node *create_node(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_head(List *list, int data) {
    Node *new_node = create_node(data);

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head = new_node;
    }
}

void insert_tail(List *list, int data) {
    Node *new_node = create_node(data);

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void print_list (List *list) {
    if (list->head == NULL) {
        printf("Nothing to print.\n");
        return;
    }
    
    Node *current = list->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void find_cycle(List *list) {
    if (list->head == NULL) {
        printf("No cycle");
        return;
    }

    Node *slow = list->head;
    Node *fast = list->head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            printf("Cycle detected.\n");
            return;
        }
    }
    printf("No cycle.\n");
}

void free_list(List *list) {
    if (list->head == NULL) {
        printf("Nothing to clear.\n");
        return;
    }

    while (list->head != NULL) {
        Node *next = list->head->next;
        free (list->head);
        list->head = next;
    }
}

int main() {
    List list = {NULL, NULL};

    insert_head(&list, 30);
    insert_head(&list, 20);
    insert_head(&list, 10);

    insert_tail(&list, 40);
    insert_tail(&list, 50);

    printf("List: ");
    print_list(&list);

    find_cycle(&list);
    list.tail->next = list.head; // Runs from last to front
    // slow will meet fast since slow is slower 1 address ran by fast
    // Cycle detected if we put these codes
    // Must happen all the time except the list is empty
    find_cycle(&list);

    free_list(&list);
    return 0;
}
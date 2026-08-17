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

void print_list(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void delete_by_index(List *list, int target_index) {
    if (list->head == NULL) {
        printf("Nothing to delete.\n");
        return;
    }

    Node *prev = NULL;
    Node *current = list->head;
    int i = 0;

    while(current != NULL && i < target_index) { // when target_index is 1
        prev = current; // prev = [0] element
        current = current->next; // current = [1] element
        i++; 
    } // so will be deleting the [1] element  (i < target_index is true)

    if (current == NULL) {
        printf("Index %d out of bounds.\n", target_index);
        return;
    }

    if (prev == NULL) {
        // when deleting [0] (first element)
        list->head = current->next;
    } else {
        // while deleting middle or tail
        prev->next = current->next;
    }

    if (current == list->tail) {
        list->tail = prev;
    }

    free(current);
}

void delete_by_value(List *list, int target_value) {
    if (list->head == NULL) {
        printf("Nothing to delete.\n");
        return;
    }

    Node *prev = NULL;
    Node *current = list->head;

    while (current != NULL) { 
        if (current->data == target_value) {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }

            if (current == list->tail) {
                list->tail = prev;
            }

            // Scenario 1: Deleting the head:
            // prev == NULL -> list->head = current->next

            // Scenario 2: Deleting the middle
            // prev != NULL -> prev->next = current->next

            // Scenario 3: Deleting the tail
            // prev != NULL -> prev->next = current->next (NULL)
            // list->tail = prev (Tail moves to the new last node)
            // if prev == NULL (only one node), tail becomes NULL
                
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

void free_list(List *list) {
    if (list->head == NULL) {
        printf("Nothing to free.\n");
        return;
    }

    while (list->head != NULL) {
        Node *next = list->head->next;
        free(list->head);
        list->head = next;
    }

    // Optional: Double check 
    list->head = NULL;
    list->tail = NULL;
}

int main() {
    List list = {NULL, NULL};

    insert_tail(&list, 10);
    insert_tail(&list, 20);
    insert_tail(&list, 30);

    delete_by_value(&list, 20);
    print_list(&list); // output: [10] [30]

    delete_by_index(&list, 0); 
    print_list(&list); // output: [30]

    free_list(&list);

    return 0;
}


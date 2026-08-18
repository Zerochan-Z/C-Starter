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

void print_list(List *list) {
    Node *current = list->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void middle_node(List *list) {
    if (list->head == NULL) {
        printf("No middle node.\n");
        return;
    }

    Node *slow = list->head;
    Node *fast = list->head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle node: %d \n", slow->data);
}

void free_list(List *list) {
    if (list->head == NULL) {
        printf("Nothing to return.\n");
        return;
    }

    while (list->head != NULL) {
        Node *next = list->head->next;
        free(list->head);
        list->head = next;
    }

    list->head = NULL;
    list->tail = NULL;
}

int main() {
    List list = {NULL, NULL};

    insert_head(&list, 30);
    insert_head(&list, 20);
    insert_head(&list, 10);

    print_list(&list);
    middle_node(&list);

    free_list(&list);

    return 0;
}
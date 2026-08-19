#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *head;
} Stack;

void init_stack(Stack *s) { // Reason why function existed
    // Check main function
    s->head = NULL;
}

int is_empty(Stack *s) {
    return s->head == NULL;
}

void push(Stack *s, int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = s->head; // New node points to old head
    s->head = new_node; // Head moves to new node
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow.\n");
        return -1;
    }

    Node *old = s->head;
    int value = s->head->data;
    s->head = s->head->next;
    free(old);
    return value;
}

int peek(Stack *s) {
    if (is_empty(s)) {
        printf("Nothing to peek.\n");
        return -1;
    }

    return s->head->data;
}

void print_stack(Stack *s) {
    if (is_empty(s)) {
        printf("Nothing to print.\n");
        return;
    }

    printf("From top to bottom: ");
    Node *current = s->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void free_stack(Stack *s) {
    while (s->head != NULL) {
        Node *next = s->head->next;
        free(s->head);
        s->head = next;
    }
}

int main() {
    Stack s;
    
    // Can also use 
    // s.head = NULL but init_stack(&s) is more organised
    // We might add more later...

    init_stack(&s);
    
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    push(&s, 60);

    print_stack(&s);

    printf("\nTop element: %d\n", peek(&s));

    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));

    print_stack(&s);

    free_stack(&s);
    return 0;
}
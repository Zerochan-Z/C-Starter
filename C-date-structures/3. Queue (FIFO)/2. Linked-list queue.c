#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;

void init_queue(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

int is_empty(Queue *q) {
    return q->head == NULL;
}

void enqueue(Queue *q, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data  = data;
    new_node->next = NULL;
    // Rule: Every time you allocate a new node, 
    // ALWAYS set new_node->next = NULL immediately.

    if (is_empty(q)) {
        new_node->next = q->head;
        q->head = new_node;
        q->tail = new_node;
    } else {
        // Wrong: (Inserting the new node before the tail)
        // new_node->next = q->tail;
        // q->tail = new_node;
        // Nothing point to old tail

        // Correct: (Inserting the new node after the tail)
        q->tail->next = new_node;
        // Old tail tied to the new node
        q->tail = new_node;
        // Telling old tail new_node is the new tail
    }
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Nothing to dequeue.\n");
        return -1;
    }

    Node *old = q->head;
    int value = old->data;
    q->head =q->head->next;
    free(old);

    // Check again because first if only runs at the first time
    // *Last check
    if (q->head == NULL) {
        q->tail = NULL;
    }

    return value;
}

int peek(Queue *q) {
    if (is_empty(q)) {
        printf("Nothing to peek.\n");
        return -1;
    }

    return q->head->data;
}

void print_queue(Queue *q) {
    if (is_empty(q)) {
        printf("Nothing to print.\n");
        return;
    }

    printf("From first to last: ");
    Node *current = q->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void free_queue(Queue *q) {
    if (is_empty(q)) {
        printf("Nothing is stored.\n");
        return;
    }

    while (q->head != NULL) {
        Node *next = q->head->next;
        free(q->head);
        q->head = next;
    }   
}

int main() {
    Queue q;

    init_queue(&q);

    enqueue(&q, 30);
    enqueue(&q, 20);
    enqueue(&q, 10);
    enqueue(&q, 40);
    enqueue(&q, 50);

    print_queue(&q);

    printf("\nTop element: %d\n", peek(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    print_queue(&q);

    free_queue(&q);

    return 0;
}
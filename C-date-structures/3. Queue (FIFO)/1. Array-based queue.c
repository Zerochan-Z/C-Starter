#include <stdio.h>
#include <stdlib.h>

#define MAX 5
// MAX = 5 means the array has indices 0-4
// One slot is always left empty to distinguish empty from full
// The queue can store at most 4 items

typedef struct {
    int arr[MAX];
    int front; // first index
    int rear; // last index
} Queue;

void init_queue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int is_empty(Queue *q) {
    return q->front == q->rear;
    // Empty when front and rear point to same index
}

int is_full(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
    // Full when the next position after rear is front (one slot empty)
    // Example [index 4 + 1] % 5 = 0 --> == front (indicate FULL!)
    // return
}

void enqueue(Queue *q, int value) {
    if (is_full(q)) {
        printf("Array is overflow.\n");
        return;
    }
    // if condition [if (is_full(q))] condition fulfileld return

    q->arr[q->rear] = value;
    q->rear = (q->rear + 1) % MAX;
    // Output = remainder after dividing MAX
    // Move rear foward, wrapping to 0 when it reaches MAX
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Array is underflow.\n");
        return -1;
    }
    // if condition [if (is_full(q))] condition fulfileld return

    int value = q->arr[q->front];
    q->front = (q->front + 1) % MAX;
    // Output = remainder after dividing MAX
    // Move front foward, wrapping to 0 when it reaches MAX
    return value;
}

int peek(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    return q->arr[q->front];
}

void print_queue(Queue *q) {
    if (is_empty(q)) {
        printf("Nothing to print in queue.\n");
        return;
    }

    printf("Whole queue: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX;
        // Same as the concept mentioned just now
    }
    printf("\n");
}

int main() {
    Queue q;

    init_queue(&q);

    enqueue(&q, 30);
    enqueue(&q, 20);
    enqueue(&q, 10);
    enqueue(&q, 40);

    print_queue(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Peek: %d\n", peek(&q));
    print_queue(&q);

    return 0;
}
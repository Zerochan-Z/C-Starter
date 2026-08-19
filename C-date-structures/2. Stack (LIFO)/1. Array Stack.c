#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void init_stack(Stack *s) {
    s->top = -1; // initial top = -1
}

int is_empty(Stack *s) {
    return s->top == -1; 
    // if top == -1 return true (empty)
    // never filled in before
}

int is_full(Stack *s) {
    return s->top == MAX - 1;
    // return 1 if top index (s->top) == MAX - 1 (size of array)
}

void push(Stack *s, int value) {
    if (is_full(s)) {
        printf("Stack overflow! cannot push %d.\n", value);
        return;
    }

    s->top++;
    s->arr[s->top] = value;
    printf("Pushed: %d\n", value);
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow! Cannot pop.\n");
        return -1;
    }

    int value = s->arr[s->top];
    s->top--;
    return value;
}

int peek(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty.\n");
        return -1;
    }

    return s->arr[s->top];
}

void print_stack(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack (top to bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;

    init_stack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    push(&s, 60);

    print_stack(&s);

    printf("Top element: %d\n", peek(&s));

    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));

    print_stack(&s);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { // stores data and pointer
    int data;
    struct Node *next; // pointer to "next" struct
    // just a direction to find it 
} Node;

Node *create_node (int data) { 
    // Node * -> returns pointer to a Node
    Node *new_node = malloc(sizeof(Node)); 
    // build one train car in heap
    new_node->data = data;
    new_node->next = NULL;
    return new_node; 
    // return the car's address
}

void insert_head(Node **head, int data) {
    // Node **head -> takes a pointer to a pointer
    Node *new_node = create_node(data);
    new_node->next = *head;
    // Old thought: set next as the dereferences of head
    // Correct: new_node->next points to whatever head was pointing at
    // (Whether it's old list or NULL)
    *head = new_node;
    // Old thought: and now head is the new_node (data & next)
    // correct: Update head to point to new node
    // (new node is now first)
}
    /*
    Before: 
    head --> [data: 20 | next: NULL]
    After insert_head:
    head --> [data: 10 | next: 0x200] --> [data: 20 | next: NULL]
    */

void print_list(Node *head) {
    while (head != NULL) { // print until head is empty
        printf("%d ", head->data); 
        head = head->next; // point to next 
    }  
}

void free_list(Node *head) {
    if (head == NULL) {
        printf("No memory to free.\n");
        return;
    }

    Node *current = head; 
    // set current as head (but Idk why not just head)
    // AI explaination: (not neccessary to set current but suggested for large programs)
    // current preserves head for debugging or if I need it later
    // It prints I freed the list that started at 0x1234
    while (current != NULL) {
        Node *after_next = current->next; 
        // after_next -> current->next * how many times run
        // save address of next node before we free current
        free(current); // free current node
        current = after_next; // move to saved next
    }
}

int main() {
    // Node *head = create_node(10);
    // head->next = create_node(20);
    // printf("%d %d\n", head->data, head->next->data);
    
    Node *head = NULL;
    insert_head(&head, 30);
    insert_head(&head, 20);
    insert_head(&head, 10);
    print_list(head);

    free_list(head);
    return 0;
}
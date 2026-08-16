#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head; // bookmark: ADDRESS of first node
    Node *tail; // bookmark: ADDRESS of last node
} List;


Node *create_node(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_tail(List *list, int data) {
    Node *new_node = create_node(data);
    // address of node
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
        // assign new_node (data's address) into both head and tail
        // since both are NULL now
    } else { // fill to tail if there's another data
        // why not ->head? 
        // Ans: To find last node from head, need to walk ->next repeatedly
        // That's why we use tail (a shortcut, not walking [O(n)])
        // to shorten the code: we use adding data from tail
        list->tail->next = new_node; // MUST be first 
        // OLD ->next ADDRESS is NULL
        // new data >> we fill in the new address into ->next
        list->tail = new_node; 
        // The last house (->tail) is now this new address
        
        // Summary:
        // Step 1: Old last node now points to new node (link them)
        // Step 2: Tail bookmark now points to new node (update shortcut)    
    }
}

void print_list(List *list) {
    Node *current = list->head; // grab bookmark, go to first room
    // Walking rooms (nodes) not bookmark box (list)
    while (current != NULL) { // while room exists
        printf("%d ", current->data); // read number in room
        current = current->next; // follow room's index card to next room
    }
}

void free_list(List *list) {
    if (list->head == NULL) {
        printf("Nothing to free.\n");
        return;
    } 

    // My code 
    while (list->head != NULL) {        
    // head points to [10], not NULL, enter loop
        Node *next = list->head->next; 
        // stored first before clear head
         // next = moves to -> [20]
        free(list->head);               
        // [10] freed. head still points to dead [10]
        // Wrong: 
        // list->head->next = next;  
        // Still pointing to the dead [10]
        // CRASH: writing to dead memory [10]->next
        // Correct: 
        list->head = next; 
        // list->head is now [20] (storing as next)     
    }

    // AI (modified) version:
    // Node *current = list->head;         // current = [10]
    // while (current != NULL) {           // [10] not NULL, enter loop
    //  Node *next = current->next;     // next = [20]
    //   free(current);                   // [10] freed
    //  current = next;                  // current = [20]
    // }
    // current = [20], not NULL, enter loop again
    // next = NULL, free [20], current = NULL
    // current is NULL, loop ends

    list->head = NULL;
    list->tail = NULL;
}

int main() {
    List list = {NULL, NULL};

    insert_tail(&list, 10);
    insert_tail(&list, 20);
    insert_tail(&list, 30);

    print_list(&list);
    free_list(&list);
    return 0;
}
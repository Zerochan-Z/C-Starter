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

void free_list(List *list) {
    if (list->head == NULL) {
        printf("Nothing to clear.\n");
        return;
    } 

    while (list->head != NULL) {
        Node *next = list->head->next;
        free(list->head);
        list->head = next;
    }
}

Node *merge_sorted_lists(Node *head1, Node *head2) {
    if (head1 == NULL) {
        printf("List 1 is empty. Returning one list.\n");
        return head2;
    } else if (head2 == NULL) {
        printf("Second list is empty. Returning other list.\n");
        return head1;
    }

    Node *dummy = create_node(0);
    Node *tail = dummy;
    
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            tail->next = create_node(head1->data);
            tail = tail->next;
            head1 = head1->next;
        } else {
            tail->next = create_node(head2->data); // next is new data
            tail = tail->next; // set new tail as the (next) tail
            head2 = head2->next;
        }
    }

    /* Simpler way: 
    if (head1 != NULL) {
        tail->next = head1;
    } else if (head2 != NULL) {
        tail->next = head2;
    }
    */

    // Consistant way:
    while (head1 != NULL) {
        tail->next = create_node(head1->data);
        tail = tail->next;
        head1 = head1->next;
    } 
    while (head2 != NULL) {
        tail->next = create_node(head2->data);
        tail = tail->next;
        head2 = head2->next;
    }
    Node *result = dummy->next;
    free(dummy);
    return result;
}

int main() {
    List list1 = {NULL, NULL};
    List list2 = {NULL, NULL};

    insert_head(&list1, 50);
    insert_head(&list1, 30);
    insert_head(&list1, 10);

    insert_head(&list2, 40);
    insert_head(&list2, 20);
    insert_head(&list2, 0);

    printf("List 1: ");
    print_list(&list1);

    printf("List 2: ");
    print_list(&list2);

    Node *merge_head = merge_sorted_lists(list1.head, list2.head);
    // merge_sorted_lists do the whole job
    // Node is created (name = merge_head)

    printf("Merged list: ");
    Node *current = merge_head;
    // Just like print_list concept
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Free_list concept
    while (merge_head != NULL) {
        Node *next = merge_head->next;
        free(merge_head);
        merge_head = next;
    }

    free_list(&list1);
    free_list(&list2);

    return 0;
}
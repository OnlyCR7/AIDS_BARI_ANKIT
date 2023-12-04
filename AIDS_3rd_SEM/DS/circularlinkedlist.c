#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Circular Linked List structure
typedef struct {
    Node *head;
} CircularLinkedList;

// Function to create a new node with the given data
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty circular linked list
void initialize(CircularLinkedList *clist) {
    clist->head = NULL;
}

// Function to check if the circular linked list is empty
int isEmpty(CircularLinkedList *clist) {
    return clist->head == NULL;
}

// Function to insert a new node at the beginning of the circular linked list
void insertAtBeginning(CircularLinkedList *clist, int data) {
    Node *newNode = createNode(data);

    if (isEmpty(clist)) {
        newNode->next = newNode;  // Point to itself in a circular list
    } else {
        newNode->next = clist->head->next;
        clist->head->next = newNode;
    }

    clist->head = newNode;
}

// Function to insert a new node at the end of the circular linked list
void insertAtEnd(CircularLinkedList *clist, int data) {
    Node *newNode = createNode(data);

    if (isEmpty(clist)) {
        newNode->next = newNode;  // Point to itself in a circular list
        clist->head = newNode;
    } else {
        newNode->next = clist->head->next;
        clist->head->next = newNode;
        clist->head = newNode;
    }
}

// Function to delete a node with the given data from the circular linked list
void deleteNode(CircularLinkedList *clist, int data) {
    if (isEmpty(clist)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node *current = clist->head;
    Node *prev = NULL;

    do {
        prev = current;
        current = current->next;

        if (current->data == data) {
            prev->next = current->next;

            if (current == clist->head) {
                clist->head = prev;
            }

            free(current);
            return;
        }
    } while (current != clist->head);
}

// Function to display the circular linked list
void display(CircularLinkedList *clist) {
    if (isEmpty(clist)) {
        printf("Circular Linked List is empty.\n");
        return;
    }

    Node *current = clist->head->next;

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != clist->head);

    printf("(Head)\n");
}

// Function to free the memory occupied by the circular linked list
void freeList(CircularLinkedList *clist) {
    if (isEmpty(clist)) {
        return;
    }

    Node *current = clist->head->next;
    Node *next;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != clist->head);

    clist->head = NULL;
}

int main() {
    CircularLinkedList clist;
    initialize(&clist);

    insertAtBeginning(&clist, 10);
    insertAtEnd(&clist, 20);
    insertAtBeginning(&clist, 5);

    display(&clist);

    deleteNode(&clist, 20);
    display(&clist);

    freeList(&clist);

    return 0;
}

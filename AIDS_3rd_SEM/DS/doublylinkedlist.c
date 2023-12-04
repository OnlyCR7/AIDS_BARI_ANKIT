#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Doubly Linked List structure
typedef struct {
    Node *head;
    Node *tail;
} DoublyLinkedList;

// Function to create a new node with the given data
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty doubly linked list
void initialize(DoublyLinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
}

// Function to check if the doubly linked list is empty
int isEmpty(DoublyLinkedList *list) {
    return list->head == NULL;
}

// Function to insert a new node at the beginning of the doubly linked list
void insertAtBeginning(DoublyLinkedList *list, int data) {
    Node *newNode = createNode(data);

    if (isEmpty(list)) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

// Function to insert a new node at the end of the doubly linked list
void insertAtEnd(DoublyLinkedList *list, int data) {
    Node *newNode = createNode(data);

    if (isEmpty(list)) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Function to delete a node with the given data from the doubly linked list
void deleteNode(DoublyLinkedList *list, int data) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node *current = list->head;

    while (current != NULL && current->data != data) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found. Cannot delete.\n", data);
        return;
    }

    if (current->prev == NULL) {
        // Deleting the head node
        list->head = current->next;
        if (list->head != NULL) {
            list->head->prev = NULL;
        }
    } else if (current->next == NULL) {
        // Deleting the tail node
        list->tail = current->prev;
        list->tail->next = NULL;
    } else {
        // Deleting a node in the middle
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    free(current);
}

// Function to display the doubly linked list forward
void displayForward(DoublyLinkedList *list) {
    if (isEmpty(list)) {
        printf("Doubly Linked List is empty.\n");
        return;
    }

    Node *current = list->head;

    printf("Doubly Linked List (Forward): ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to display the doubly linked list backward
void displayBackward(DoublyLinkedList *list) {
    if (isEmpty(list)) {
        printf("Doubly Linked List is empty.\n");
        return;
    }

    Node *current = list->tail;

    printf("Doubly Linked List (Backward): NULL ");
    while (current != NULL) {
        printf("<-> %d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// Function to free the memory occupied by the doubly linked list
void freeList(DoublyLinkedList *list) {
    Node *current = list->head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
}

int main() {
    DoublyLinkedList list;
    initialize(&list);

    insertAtBeginning(&list, 10);
    insertAtEnd(&list, 20);
    insertAtBeginning(&list, 5);

    displayForward(&list);
    displayBackward(&list);

    deleteNode(&list, 20);
    displayForward(&list);

    freeList(&list);

    return 0;
}

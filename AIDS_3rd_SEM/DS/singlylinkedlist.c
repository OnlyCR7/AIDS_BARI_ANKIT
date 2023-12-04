#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Linked List structure
typedef struct {
    Node *head;
} LinkedList;

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

// Function to initialize an empty linked list
void initialize(LinkedList *list) {
    list->head = NULL;
}

// Function to check if the linked list is empty
int isEmpty(LinkedList *list) {
    return list->head == NULL;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(LinkedList *list, int data) {
    Node *newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(LinkedList *list, int data) {
    Node *newNode = createNode(data);

    if (isEmpty(list)) {
        list->head = newNode;
        return;
    }

    Node *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Function to delete a node with the given data from the linked list
void deleteNode(LinkedList *list, int data) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node *current = list->head;
    Node *prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found. Cannot delete.\n", data);
        return;
    }

    if (prev == NULL) {
        // Deleting the head node
        list->head = current->next;
    } else {
        // Deleting a node in the middle or at the end
        prev->next = current->next;
    }

    free(current);
}

// Function to display the linked list
void display(LinkedList *list) {
    Node *current = list->head;

    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory occupied by the linked list
void freeList(LinkedList *list) {
    Node *current = list->head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
}

int main() {
    LinkedList list;
    initialize(&list);

    insertAtBeginning(&list, 10);
    insertAtEnd(&list, 20);
    insertAtBeginning(&list, 5);

    display(&list);

    deleteNode(&list, 20);
    display(&list);

    freeList(&list);

    return 0;
}

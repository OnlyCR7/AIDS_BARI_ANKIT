#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Stack structure
typedef struct {
    Node *top;
} Stack;

// Linear Queue structure
typedef struct {
    Node *front;
    Node *rear;
} LinearQueue;

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

// Function to initialize an empty stack
void initializeStack(Stack *stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isStackEmpty(Stack *stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack *stack, int data) {
    Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }

    Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to display the stack
void displayStack(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    Node *current = stack->top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to initialize an empty linear queue
void initializeQueue(LinearQueue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the linear queue is empty
int isQueueEmpty(LinearQueue *queue) {
    return queue->front == NULL;
}

// Function to enqueue (insert) an element into the linear queue
void enqueue(LinearQueue *queue, int data) {
    Node *newNode = createNode(data);

    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue (remove) an element from the linear queue
int dequeue(LinearQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue underflow\n");
        exit(EXIT_FAILURE);
    }

    Node *temp = queue->front;
    int data = temp->data;
    
    queue->front = temp->next;
    
    if (queue->front == NULL) {
        // If the queue becomes empty after dequeue
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// Function to display the linear queue
void displayQueue(LinearQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    Node *current = queue->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Stack stack;
    LinearQueue queue;

    initializeStack(&stack);
    initializeQueue(&queue);

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Display the stack
    displayStack(&stack);

    // Dequeue elements from the queue
    enqueue(&queue, 5);
    enqueue(&queue, 15);
    enqueue(&queue, 25);

    // Display the queue
    displayQueue(&queue);

    // Pop elements from the stack
    printf("Popped element from the stack: %d\n", pop(&stack));
    printf("Popped element from the stack: %d\n", pop(&stack));

    // Display the updated stack
    displayStack(&stack);

    // Dequeue elements from the queue
    printf("Dequeued element from the queue: %d\n", dequeue(&queue));
    printf("Dequeued element from the queue: %d\n", dequeue(&queue));

    // Display the updated queue
    displayQueue(&queue);

    return 0;
}

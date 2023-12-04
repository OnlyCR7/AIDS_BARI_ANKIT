#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Circular Queue structure
typedef struct {
    int arr[MAX_SIZE];
    int front, rear;
    int count;  // To keep track of the number of elements in the queue
} CircularQueue;

// Function to initialize an empty circular queue
void initialize(CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->count = 0;
}

// Function to check if the circular queue is empty
int isEmpty(CircularQueue *queue) {
    return queue->count == 0;
}

// Function to check if the circular queue is full
int isFull(CircularQueue *queue) {
    return queue->count == MAX_SIZE;
}

// Function to enqueue (insert) an element into the circular queue
void enqueue(CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue)) {
        // If the queue is empty, set both front and rear to 0
        queue->front = 0;
        queue->rear = 0;
    } else {
        // Increment rear circularly
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    // Enqueue the element
    queue->arr[queue->rear] = value;
    queue->count++;
}

// Function to dequeue (remove) an element from the circular queue
int dequeue(CircularQueue *queue) {
    int value;

    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(EXIT_FAILURE);
    }

    // Dequeue the element
    value = queue->arr[queue->front];

    if (queue->front == queue->rear) {
        // If there was only one element in the queue, reset front and rear to -1
        queue->front = -1;
        queue->rear = -1;
    } else {
        // Increment front circularly
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    queue->count--;

    return value;
}

// Function to get the front element of the circular queue without dequeuing
int front(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    return queue->arr[queue->front];
}

int main() {
    CircularQueue queue;
    initialize(&queue);

    // Enqueue elements
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    // Display front element
    printf("Front element: %d\n", front(&queue));

    // Dequeue elements
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    // Display front element after dequeues
    printf("Front element: %d\n", front(&queue));

    return 0;
}

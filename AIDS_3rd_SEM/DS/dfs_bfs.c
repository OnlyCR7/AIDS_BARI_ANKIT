#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent the adjacency list for each vertex
typedef struct {
    Node* head;
} AdjList;

// Structure to represent a graph
typedef struct {
    int vertices;
    AdjList* array;
} Graph;

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    graph->vertices = vertices;

    // Create an array of adjacency lists
    graph->array = (AdjList*)malloc(vertices * sizeof(AdjList));
    if (graph->array == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize each adjacency list as empty by setting the head to NULL
    for (int i = 0; i < vertices; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to perform Depth-First Search (DFS) on the graph
void DFS(Graph* graph, int vertex, bool* visited) {
    // Mark the current vertex as visited
    visited[vertex] = true;
    printf("%d ", vertex);

    // Recur for all adjacent vertices
    Node* current = graph->array[vertex].head;
    while (current != NULL) {
        int adjacentVertex = current->vertex;
        if (!visited[adjacentVertex]) {
            DFS(graph, adjacentVertex, visited);
        }
        current = current->next;
    }
}

// Function to perform Breadth-First Search (BFS) on the graph
void BFS(Graph* graph, int startVertex, bool* visited) {
    // Create a queue for BFS
    int* queue = (int*)malloc(graph->vertices * sizeof(int));
    int front = 0, rear = 0;

    // Enqueue the starting vertex
    queue[rear++] = startVertex;
    visited[startVertex] = true;

    // Continue until the queue is empty
    while (front < rear) {
        // Dequeue a vertex and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Enqueue all adjacent vertices of the dequeued vertex that have not been visited
        Node* current = graph->array[currentVertex].head;
        while (current != NULL) {
            int adjacentVertex = current->vertex;
            if (!visited[adjacentVertex]) {
                queue[rear++] = adjacentVertex;
                visited[adjacentVertex] = true;
            }
            current = current->next;
        }
    }

    free(queue);
}

// Function to perform DFS on all vertices of the graph
void DFSTraversal(Graph* graph) {
    // Create an array to keep track of visited vertices
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = false;
    }

    // Perform DFS for each unvisited vertex
    for (int i = 0; i < graph->vertices; ++i) {
        if (!visited[i]) {
            DFS(graph, i, visited);
        }
    }

    free(visited);
}

int main() {
    // Create a graph with 5 vertices
    Graph* graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);

    // Display the graph using DFS and BFS
    printf("DFS Traversal: ");
    DFSTraversal(graph);
    printf("\n");

    // Reset visited array for BFS
    bool* visitedBFS = (bool*)malloc(graph->vertices * sizeof(bool));
    for (int i = 0; i < graph->vertices; ++i) {
        visitedBFS[i] = false;
    }

    printf("BFS Traversal: ");
    // Perform BFS starting from each unvisited vertex
    for (int i = 0; i < graph->vertices; ++i) {
        if (!visitedBFS[i]) {
            BFS(graph, i, visitedBFS);
        }
    }
    printf("\n");

    // Free memory allocated for the graph
    for (int i = 0; i < graph->vertices; ++i) {
        Node* current = graph->array[i].head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
    free(visitedBFS);

    return 0;
}

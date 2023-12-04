#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_POINTS 100
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
#define FILL_CHAR '*'
#define BOUNDARY_CHAR ' '

// Structure to represent a point
struct Point {
    int x, y;
};

// Structure to represent an edge
struct Edge {
    int x1, y1, x2, y2;
};

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort edges based on their x-coordinate
void sortEdges(struct Edge edges[], int numEdges) {
    for (int i = 0; i < numEdges - 1; i++) {
        for (int j = 0; j < numEdges - i - 1; j++) {
            if (edges[j].x1 > edges[j + 1].x1) {
                // Swap the edges
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Function to fill the polygon using the Scan-Line Polygon Filling algorithm
void scanLineFill(struct Point polygon[], int numPoints) {
    int minY = SCREEN_HEIGHT;
    int maxY = 0;

    // Find the minimum and maximum Y-coordinates
    for (int i = 0; i < numPoints; i++) {
        if (polygon[i].y < minY) {
            minY = polygon[i].y;
        }
        if (polygon[i].y > maxY) {
            maxY = polygon[i].y;
        }
    }

    // Create an array to store the edges of the polygon
    struct Edge edges[MAX_POINTS];
    int numEdges = 0;

    // Find the edges of the polygon
    for (int i = 0; i < numPoints; i++) {
        int next = (i + 1) % numPoints;
        int x1 = polygon[i].x;
        int y1 = polygon[i].y;
        int x2 = polygon[next].x;
        int y2 = polygon[next].y;

        if (y1 < y2) {
            edges[numEdges].x1 = x1;
            edges[numEdges].y1 = y1;
            edges[numEdges].x2 = x2;
            edges[numEdges].y2 = y2;
            numEdges++;
        } else if (y1 > y2) {
            edges[numEdges].x1 = x2;
            edges[numEdges].y1 = y2;
            edges[numEdges].x2 = x1;
            edges[numEdges].y2 = y1;
            numEdges++;
        }
    }

    // Sort the edges based on their x-coordinate
    sortEdges(edges, numEdges);

    // Initialize the active edge table
    int AET[MAX_POINTS];
    for (int i = 0; i < MAX_POINTS; i++) {
        AET[i] = -1;
    }

    // Fill the polygon
    for (int y = minY; y <= maxY; y++) {
        // Update the active edge table
        for (int i = 0; i < numEdges; i++) {
            if (edges[i].y1 == y) {
                AET[i] = edges[i].x1;
            }
        }

        // Process the active edge table
        for (int i = 0; i < MAX_POINTS; i += 2) {
            if (AET[i] != -1 && AET[i + 1] != -1) {
                for (int x = AET[i]; x <= AET[i + 1]; x++) {
                    putchar(FILL_CHAR);
                }
            }
        }

        // Update the active edge table
        for (int i = 0; i < MAX_POINTS; i += 2) {
            if (AET[i] != -1) {
                AET[i] += 1;
            }
        }
    }
}

int main() {
    int numPoints;
    struct Point polygon[MAX_POINTS];

    printf("Enter the number of vertices of the polygon: ");
    scanf("%d", &numPoints);

    if (numPoints < 3 || numPoints > MAX_POINTS) {
        printf("Invalid number of vertices. Must be between 3 and %d.\n", MAX_POINTS);
        return 1;
    }

    printf("Enter the vertices (x y): \n");
    for (int i = 0; i < numPoints; i++) {
        scanf("%d %d", &polygon[i].x, &polygon[i].y);
    }

    // Fill the polygon
    scanLineFill(polygon, numPoints);

    // Print the filled polygon
    putchar('\n');

    return 0;
}

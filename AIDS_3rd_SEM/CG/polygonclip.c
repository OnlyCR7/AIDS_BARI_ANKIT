#include <stdio.h>
#include <stdbool.h>

// Define the maximum number of vertices for the input polygon and clipping window
#define MAX_VERTICES 100

// Structure to represent a 2D point (x, y)
struct Point {
    float x, y;
};

// Function to check if a point is inside a clipping window defined by its vertices
bool isInside(struct Point point, struct Point window[], int numVertices) {
    // Initialize a flag to keep track of the winding number
    int windingNumber = 0;

    // Iterate over each edge of the window
    for (int i = 0; i < numVertices; i++) {
        struct Point p1 = window[i];
        struct Point p2 = window[(i + 1) % numVertices];

        if (p1.y <= point.y) {
            if (p2.y > point.y && ((point.x - p1.x) * (p2.y - p1.y) - (point.y - p1.y) * (p2.x - p1.x) > 0)) {
                windingNumber++;
            }
        } else if (p2.y <= point.y && ((point.x - p1.x) * (p2.y - p1.y) - (point.y - p1.y) * (p2.x - p1.x) < 0)) {
            windingNumber--;
        }
    }

    // If the winding number is not zero, the point is inside the window
    return windingNumber != 0;
}

// Function to clip a polygon against a convex window
void sutherlandHodgmanClip(struct Point polygon[], int numVertices, struct Point window[], int numWindowVertices) {
    struct Point output[MAX_VERTICES]; // Initialize an array for the clipped polygon
    int numOutputVertices = 0; // Initialize the number of vertices in the clipped polygon

    // Iterate over each edge of the clipping window
    for (int i = 0; i < numWindowVertices; i++) {
        struct Point p1 = window[i];
        struct Point p2 = window[(i + 1) % numWindowVertices];

        // Initialize an array for the new vertices resulting from clipping
        struct Point input[MAX_VERTICES];
        int numInputVertices = numVertices;

        // Copy the vertices of the polygon to the input array
        for (int j = 0; j < numVertices; j++) {
            input[j] = polygon[j];
        }

        // Clip the polygon against the current edge of the window
        for (int j = 0; j < numInputVertices; j++) {
            struct Point currentPoint = input[j];
            struct Point nextPoint = input[(j + 1) % numInputVertices];

            bool currentInside = isInside(currentPoint, window, numWindowVertices);
            bool nextInside = isInside(nextPoint, window, numWindowVertices);

            if (currentInside && nextInside) {
                // Both points are inside, add the next point to the output
                output[numOutputVertices++] = nextPoint;
            } else if (currentInside && !nextInside) {
                // Current point is inside, but next point is outside
                // Add the intersection point to the output
                float x_intersect = p1.x + (p2.x - p1.x) * (p1.y - currentPoint.y) / (nextPoint.y - currentPoint.y);
                output[numOutputVertices].x = x_intersect;
                output[numOutputVertices++].y = p1.y;
            } else if (!currentInside && nextInside) {
                // Current point is outside, but next point is inside
                // Add the intersection point and next point to the output
                float x_intersect = p1.x + (p2.x - p1.x) * (p1.y - currentPoint.y) / (nextPoint.y - currentPoint.y);
                output[numOutputVertices].x = x_intersect;
                output[numOutputVertices++].y = p1.y;
                output[numOutputVertices++] = nextPoint;
            }
            // If both points are outside, skip this edge
        }

        // Copy the clipped polygon back to the input for the next iteration
        for (int j = 0; j < numOutputVertices; j++) {
            input[j] = output[j];
        }
        numInputVertices = numOutputVertices;
        numOutputVertices = 0; // Reset the output vertex count
    }

    // Output the clipped polygon vertices
    printf("Clipped Polygon:\n");
    for (int i = 0; i < numOutputVertices; i++) {
        printf("(%.2f, %.2f)\n", output[i].x, output[i].y);
    }
}

int main() {
    // Define the vertices of the polygon to be clipped
    struct Point polygon[MAX_VERTICES] = {
        {100, 50},
        {200, 150},
        {150, 250},
        {50, 200}
    };
    int numVertices = 4;

    // Define the vertices of the clipping window (convex polygon)
    struct Point window[] = {
        {75, 75},
        {175, 75},
        {175, 175},
        {75, 175}
    };
    int numWindowVertices = 4;

    // Perform polygon clipping using the Sutherland-Hodgman algorithm
    sutherlandHodgmanClip(polygon, numVertices, window, numWindowVertices);

    return 0;
}

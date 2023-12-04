#include <stdio.h>
#include <stdbool.h>

// Define the window coordinates (xmin, ymin, xmax, ymax)
#define X_MIN 50
#define Y_MIN 50
#define X_MAX 250
#define Y_MAX 250

// Structure to represent a point (x, y)
struct Point {
    float x, y;
};

// Function to clip a line segment using the Liang-Barsky algorithm
bool liangBarskyClip(struct Point p1, struct Point p2) {
    float t1 = 0.0, t2 = 1.0;
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;

    float p[4] = {-dx, dx, -dy, dy};
    float q[4] = {p1.x - X_MIN, X_MAX - p1.x, p1.y - Y_MIN, Y_MAX - p1.y};

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0) {
                return false; // Line is parallel to the clipping boundary and outside
            }
        } else {
            float r = q[i] / p[i];
            if (p[i] < 0 && r > t1) {
                t1 = r;
            } else if (p[i] > 0 && r < t2) {
                t2 = r;
            }
        }
    }
}

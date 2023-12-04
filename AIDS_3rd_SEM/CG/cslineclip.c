#include <stdio.h>
#include <stdbool.h>

// Define region codes for the Cohen-Sutherland algorithm
#define INSIDE 0  // 0000
#define LEFT 1    // 0001
#define RIGHT 2   // 0010
#define BOTTOM 4  // 0100
#define TOP 8     // 1000

// Define the window coordinates (xmin, ymin, xmax, ymax)
#define X_MIN 50
#define Y_MIN 50
#define X_MAX 250
#define Y_MAX 250

// Structure to represent a point (x, y)
struct Point {
    int x, y;
};

// Function to compute the region code for a point
int computeRegionCode(struct Point p) {
    int code = INSIDE;

    if (p.x < X_MIN)
        code |= LEFT;
    else if (p.x > X_MAX)
        code |= RIGHT;

    if (p.y < Y_MIN)
        code |= BOTTOM;
    else if (p.y > Y_MAX)
        code |= TOP;

    return code;
}

// Function to clip a line segment using the Cohen-Sutherland algorithm
bool cohenSutherlandClip(struct Point *p1, struct Point *p2) {
    int code1 = computeRegionCode(*p1);
    int code2 = computeRegionCode(*p2);

    while (1) {
        if (!(code1 | code2)) {
            // Both endpoints are inside the window
            return true;
        } else if (code1 & code2) {
            // Both endpoints are outside the same region, so the line is entirely outside
            return false;
        } else {
            // Calculate the intersection point
            struct Point intersect;
            int code = code1 ? code1 : code2;

            if (code & TOP) {
                intersect.x = p1->x + (p2->x - p1->x) * (Y_MAX - p1->y) / (p2->y - p1->y);
                intersect.y = Y_MAX;
            } else if (code & BOTTOM) {
                intersect.x = p1->x + (p2->x - p1->x) * (Y_MIN - p1->y) / (p2->y - p1->y);
                intersect.y = Y_MIN;
            } else if (code & RIGHT) {
                intersect.y = p1->y + (p2->y - p1->y) * (X_MAX - p1->x) / (p2->x - p1->x);
                intersect.x = X_MAX;
            } else if (code & LEFT) {
                intersect.y = p1->y + (p2->y - p1->y) * (X_MIN - p1->x) / (p2->x - p1->x);
                intersect.x = X_MIN;
            }

            if (code == code1) {
                p1->x = intersect.x;
                p1->y = intersect.y;
                code1 = computeRegionCode(*p1);
            } else {
                p2->x = intersect.x;
                p2->y = intersect.y;
                code2 = computeRegionCode(*p2);
            }
        }
    }
}

int main() {
    struct Point p1 = {60, 60}; // Line segment endpoints
    struct Point p2 = {220, 200};

    printf("Original Line: (%d, %d) to (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);

    if (cohenSutherlandClip(&p1, &p2)) {
        printf("Clipped Line: (%d, %d) to (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
    } else {
        printf("Line is entirely outside the window.\n");
    }

    return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265359

// Structure to represent a 2D point (x, y)
struct Point {
    double x, y;
};

// Function to calculate the midpoint between two points
struct Point midpoint(struct Point p1, struct Point p2) {
    struct Point mid;
    mid.x = (p1.x + p2.x) / 2.0;
    mid.y = (p1.y + p2.y) / 2.0;
    return mid;
}

// Function to draw the Koch Snowflake fractal
void drawKochSnowflake(struct Point p1, struct Point p2, int depth) {
    if (depth == 0) {
        // Base case: draw a line segment
        printf("%.2lf %.2lf %.2lf %.2lf\n", p1.x, p1.y, p2.x, p2.y);
    } else {
        // Calculate points for the Koch Snowflake pattern
        struct Point one_third = midpoint(p1, p2);
        struct Point two_thirds = midpoint(p2, p1);
        struct Point tip;

        // Calculate tip point (equidistant from one_third and two_thirds)
        double angle = PI / 3.0;
        tip.x = one_third.x + (two_thirds.x - one_third.x) * cos(angle) - (two_thirds.y - one_third.y) * sin(angle);
        tip.y = one_third.y + (two_thirds.x - one_third.x) * sin(angle) + (two_thirds.y - one_third.y) * cos(angle);

        // Recursively draw the four segments of the Koch Snowflake
        drawKochSnowflake(p1, one_third, depth - 1);
        drawKochSnowflake(one_third, tip, depth - 1);
        drawKochSnowflake(tip, two_thirds, depth - 1);
        drawKochSnowflake(two_thirds, p2, depth - 1);
    }
}

int main() {
    int depth;

    printf("Enter the depth for the Koch Snowflake: ");
    scanf("%d", &depth);

    if (depth < 0) {
        printf("Depth should be a non-negative integer.\n");
        return 1;
    }

    // Define the vertices of an equilateral triangle
    struct Point p1 = {0.0, 0.0};
    struct Point p2 = {100.0, 0.0};
    struct Point p3 = {50.0, 100.0};

    // Draw the three sides of the equilateral triangle
    drawKochSnowflake(p1, p2, depth);
    drawKochSnowflake(p2, p3, depth);
    drawKochSnowflake(p3, p1, depth);

    return 0;
}

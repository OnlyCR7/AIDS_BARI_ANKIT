#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void drawCircleMidpoint(int radius) {
    int x = 0;
    int y = radius;
    int p = 1 - radius; // Initial decision parameter

    while (x <= y) {
        // Draw the eight octants of the circle
        putchar(' ');
        for (int i = 0; i < x; i++) putchar(' ');
        putchar('*');
        for (int i = 0; i < 2 * (y - x) - 1; i++) putchar(' ');
        if (x != y) putchar('*');
        putchar('\n');

        if (p < 0) {
            p += 2 * x + 3;
        } else {
            p += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

int main() {
    int radius;

    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);

    if (radius <= 0) {
        printf("Radius should be a positive integer.\n");
        return 1;
    }

    drawCircleMidpoint(radius);

    return 0;
}

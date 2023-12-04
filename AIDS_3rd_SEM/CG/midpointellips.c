#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void drawEllipseMidpoint(int a, int b) {
    int x = 0;
    int y = b;
    double d1 = b * b - a * a * b + 0.25 * a * a;
    double dx = 2 * b * b * x;
    double dy = 2 * a * a * y;

    while (dx < dy) {
        // Plot points in the first region (region 1)
        putchar('*');
        for (int i = 0; i < 2 * x; i++) putchar(' ');
        putchar('*');
        putchar('\n');

        if (d1 < 0) {
            x++;
            dx += 2 * b * b;
            d1 += b * b * (2 * x + 3);
        } else {
            x++;
            y--;
            dx += 2 * b * b;
            dy -= 2 * a * a;
            d1 += b * b * (2 * x + 3) + a * a * (-2 * y + 2);
        }
    }

    double d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;
    while (y >= 0) {
        // Plot points in the second region (region 2)
        putchar('*');
        for (int i = 0; i < 2 * x; i++) putchar(' ');
        putchar('*');
        putchar('\n');

        if (d2 > 0) {
            y--;
            dy -= 2 * a * a;
            d2 += a * a * (-2 * y + 3);
        } else {
            x++;
            y--;
            dx += 2 * b * b;
            dy -= 2 * a * a;
            d2 += b * b * (2 * x + 2) + a * a * (-2 * y + 3);
        }
    }
}

int main() {
    int a, b;

    printf("Enter the semi-major axis (a) and semi-minor axis (b) of the ellipse: ");
    scanf("%d %d", &a, &b);

    if (a <= 0 || b <= 0) {
        printf("Both axes should be positive integers.\n");
        return 1;
    }

    drawEllipseMidpoint(a, b);

    return 0;
}

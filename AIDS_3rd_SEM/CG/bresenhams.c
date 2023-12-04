#include <stdio.h>
#include <math.h>

void drawLineBresenham(int x1, int y1, int x2, int y2, char pixel, int dotted, int dashed, int thickness) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;

    int p = 2 * dy - dx;

    // Determine the direction of travel
    int xIncrement = (x1 < x2) ? 1 : -1;
    int yIncrement = (y1 < y2) ? 1 : -1;

    // Initialize counters for dotted and dashed lines
    int dotCounter = 0;
    int dashCounter = 0;

    if (dx > dy) {
        // Slope is less than 45 degrees
        for (x = x1, y = y1; x != x2; x += xIncrement) {
            if (dotCounter < dotted) {
                putchar(' ');
                dotCounter++;
            } else if (dashCounter < dashed) {
                putchar(pixel);
                dashCounter++;
            } else {
                putchar(pixel);
                dashCounter = 0;
            }

            if (p >= 0) {
                y += yIncrement;
                p -= 2 * dx;
            }
            p += 2 * dy;
        }
    } else {
        // Slope is greater than 45 degrees
        for (x = x1, y = y1; y != y2; y += yIncrement) {
            if (dotCounter < dotted) {
                putchar(' ');
                dotCounter++;
            } else if (dashCounter < dashed) {
                putchar(pixel);
                dashCounter++;
            } else {
                putchar(pixel);
                dashCounter = 0;
            }

            if (p >= 0) {
                x += xIncrement;
                p -= 2 * dy;
            }
            p += 2 * dx;
        }
    }

    putchar('\n');
}

int main() {
    int x1, y1, x2, y2;
    char pixel;
    int dotted, dashed, thickness;

    printf("Enter the coordinates (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    printf("Enter the character to use for the line: ");
    scanf(" %c", &pixel);

    printf("Enter the number of spaces between pixels for dotted line: ");
    scanf("%d", &dotted);

    printf("Enter the number of pixels between dashes for dashed line: ");
    scanf("%d", &dashed);

    printf("Enter the thickness of the line: ");
    scanf("%d", &thickness);

    drawLineBresenham(x1, y1, x2, y2, pixel, dotted, dashed, thickness);

    return 0;
}

#include <stdio.h>
#include <math.h>

void drawLineDDA(int x1, int y1, int x2, int y2, char pixel, int dotted, int dashed, int thickness) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    int x = x1;
    int y = y1;

    int dotCounter = 0;
    int dashCounter = 0;

    for (int i = 0; i <= steps; i++) {
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

        x += xIncrement;
        y += yIncrement;

        if (i % thickness == 0) {
            dotCounter = 0;
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

    drawLineDDA(x1, y1, x2, y2, pixel, dotted, dashed, thickness);

    return 0;
}

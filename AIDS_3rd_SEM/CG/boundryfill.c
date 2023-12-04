#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For getch()

void boundaryFill(int x, int y, char fill, char boundary, char image[20][50]) {
    if (x < 0 || x >= 20 || y < 0 || y >= 50 || image[x][y] == fill || image[x][y] == boundary)
        return;

    // Fill the current pixel
    image[x][y] = fill;

    // Recursively fill in the surrounding pixels
    boundaryFill(x + 1, y, fill, boundary, image);
    boundaryFill(x - 1, y, fill, boundary, image);
    boundaryFill(x, y + 1, fill, boundary, image);
    boundaryFill(x, y - 1, fill, boundary, image);
}

int main() {
    char image[20][50]; // Assuming a 20x50 image

    // Initialize the image with boundary and background colors
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 50; j++) {
            if (i == 0 || i == 19 || j == 0 || j == 49)
                image[i][j] = '*'; // Boundary color
            else
                image[i][j] = ' '; // Background color
        }
    }

    // Set a starting point for the fill
    int startX = 10;
    int startY = 25;

    // Call Boundary Fill algorithm
    boundaryFill(startX, startY, '+', '*', image);

    // Display the filled image
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 50; j++) {
            putchar(image[i][j]);
        }
        putchar('\n');
    }

    getch(); // Wait for a key press before exiting

    return 0;
}

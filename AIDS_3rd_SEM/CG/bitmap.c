#include <stdio.h>

// Define a bitmap character 'A'
const char bitmap_A[] = {
    0b00011000,
    0b00100100,
    0b01000010,
    0b01111110,
    0b01000010,
    0b01000010,
    0b01000010
};

// Function to display a bitmap character
void displayBitmapCharacter(const char bitmap[]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            if (bitmap[i] & (1 << j)) {
                putchar('*');  // Print '*' for '1' bits
            } else {
                putchar(' ');  // Print ' ' for '0' bits
            }
        }
        putchar('\n');
    }
}

int main() {
    printf("Bit Map Character 'A':\n");
    displayBitmapCharacter(bitmap_A);

    return 0;
}

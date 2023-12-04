#include <stdio.h>

// Define the character 'A' as a series of strokes
const char* strokes_A = "M10 10 L20 30 L30 10 M15 20 L25 20";

// Function to display a character defined by strokes
void displayStrokeCharacter(const char* strokes) {
    printf("Character:\n%s\n", strokes);
}

int main() {
    printf("Stroke Character 'A':\n");
    displayStrokeCharacter(strokes_A);

    return 0;
}

#include <stdio.h>
#include <math.h>

// Structure to represent a 3D point (x, y, z)
struct Point3D {
    float x, y, z;
};

// Function to perform 3D translation
void translate3D(struct Point3D *point, float tx, float ty, float tz) {
    point->x += tx;
    point->y += ty;
    point->z += tz;
}

// Function to perform 3D rotation around the X-axis
void rotateX3D(struct Point3D *point, float angle) {
    float tempY = point->y;
    point->y = cos(angle) * point->y - sin(angle) * point->z;
    point->z = sin(angle) * tempY + cos(angle) * point->z;
}

// Function to perform 3D rotation around the Y-axis
void rotateY3D(struct Point3D *point, float angle) {
    float tempX = point->x;
    point->x = cos(angle) * point->x + sin(angle) * point->z;
    point->z = -sin(angle) * tempX + cos(angle) * point->z;
}

// Function to perform 3D rotation around the Z-axis
void rotateZ3D(struct Point3D *point, float angle) {
    float tempX = point->x;
    point->x = cos(angle) * point->x - sin(angle) * point->y;
    point->y = sin(angle) * tempX + cos(angle) * point->y;
}

// Function to perform 3D scaling
void scale3D(struct Point3D *point, float sx, float sy, float sz) {
    point->x *= sx;
    point->y *= sy;
    point->z *= sz;
}

int main() {
    struct Point3D point = {1.0, 2.0, 3.0};
    
    printf("Original Point: (%.2f, %.2f, %.2f)\n", point.x, point.y, point.z);

    // Perform 3D transformations
    translate3D(&point, 2.0, 3.0, 1.0);
    rotateX3D(&point, 3.142 / 4.0); // Rotate 45 degrees around X-axis
    rotateY3D(&point, 3.142 / 3.0); // Rotate 60 degrees around Y-axis
    scale3D(&point, 1.5, 0.8, 1.2);

    printf("Transformed Point: (%.2f, %.2f, %.2f)\n", point.x, point.y, point.z);

    return 0;
}

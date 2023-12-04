#include <stdio.h>

// Structure to represent a 3D point (x, y, z)
struct Point3D {
    float x, y, z;
};

// Function to perform perspective projection
void perspectiveProjection(struct Point3D point3D, float *x2D, float *y2D) {
    float focalLength = 5.0; // Adjust the focal length as needed
    *x2D = (point3D.x * focalLength) / point3D.z;
    *y2D = (point3D.y * focalLength) / point3D.z;
}

int main() {
    struct Point3D point3D = {2.0, 3.0, 4.0};
    float x2D, y2D;

    perspectiveProjection(point3D, &x2D, &y2D);

    printf("3D Point: (%.2f, %.2f, %.2f)\n", point3D.x, point3D.y, point3D.z);
    printf("2D Projection (Perspective): (%.2f, %.2f)\n", x2D, y2D);

    return 0;
}

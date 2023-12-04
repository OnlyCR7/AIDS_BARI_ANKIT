#include <stdio.h>

// Structure to represent a 3D point (x, y, z)
struct Point3D {
    float x, y, z;
};

// Function to perform parallel projection
void parallelProjection(struct Point3D point3D, float *x2D, float *y2D) {
    *x2D = point3D.x;
    *y2D = point3D.y;
}

int main() {
    struct Point3D point3D = {2.0, 3.0, 4.0};
    float x2D, y2D;

    parallelProjection(point3D, &x2D, &y2D);

    printf("3D Point: (%.2f, %.2f, %.2f)\n", point3D.x, point3D.y, point3D.z);
    printf("2D Projection (Parallel): (%.2f, %.2f)\n", x2D, y2D);

    return 0;
}

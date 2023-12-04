#include <stdio.h>

struct Point {
    float x, y;
};


struct Point translate(struct Point p, float tx, float ty) {
    p.x += tx;
    p.y += ty;
    return p;
}

int main() {
    struct Point p = {2.0, 3.0};
    float tx = 4.0;
    float ty = 5.0;
    
    struct Point translated = translate(p, tx, ty);
    
    printf("Original Point: (%.2f, %.2f)\n", p.x, p.y);
    printf("Translated Point: (%.2f, %.2f)\n", translated.x, translated.y);
    
    return 0;
}


struct Point scale(struct Point p, float sx, float sy) {
    p.x *= sx;
    p.y *= sy;
    return p;
}

int main() {
    struct Point p = {2.0, 3.0};
    float sx = 1.5; // Scale factor in the x-direction
    float sy = 0.5; // Scale factor in the y-direction
    
    struct Point scaled = scale(p, sx, sy);
    
    printf("Original Point: (%.2f, %.2f)\n", p.x, p.y);
    printf("Scaled Point: (%.2f, %.2f)\n", scaled.x, scaled.y);
    
    return 0;
}


#include <math.h>

struct Point rotate(struct Point p, float angle) {
    float x = p.x * cos(angle) - p.y * sin(angle);
    float y = p.x * sin(angle) + p.y * cos(angle);
    p.x = x;
    p.y = y;
    return p;
}

int main() {
    struct Point p = {2.0, 3.0};
    float angle = 3.142 / 4.0; // Rotate by 45 degrees (pi/4 radians)
    
    struct Point rotated = rotate(p, angle);
    
    printf("Original Point: (%.2f, %.2f)\n", p.x, p.y);
    printf("Rotated Point: (%.2f, %.2f)\n", rotated.x, rotated.y);
    
    return 0;
}


struct Point reflectX(struct Point p) {
    p.y = -p.y;
    return p;
}

int main() {
    struct Point p = {2.0, 3.0};
    
    struct Point reflected = reflectX(p);
    
    printf("Original Point: (%.2f, %.2f)\n", p.x, p.y);
    printf("Reflected Point (X-axis): (%.2f, %.2f)\n", reflected.x, reflected.y);
    
    return 0;
}


struct Point shearX(struct Point p, float shx) {
    p.x += shx * p.y;
    return p;
}

int main() {
    struct Point p = {2.0, 3.0};
    float shx = 1.5; // Shear factor in the x-direction
    
    struct Point sheared = shearX(p, shx);
    
    printf("Original Point: (%.2f, %.2f)\n", p.x, p.y);
    printf("Sheared Point (X-direction): (%.2f, %.2f)\n", sheared.x, sheared.y);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point (x, y)
struct Point {
    double x, y;
};

// Calculate binomial coefficient C(n, k)
double binomialCoefficient(int n, int k) {
    if (k == 0 || k == n) {
        return 1.0;
    } else {
        double result = 1.0;
        for (int i = 1; i <= k; i++) {
            result *= (double)(n - i + 1) / (double)i;
        }
        return result;
    }
}

// Calculate the Bezier curve point for a given t and control points
struct Point bezierCurvePoint(struct Point controlPoints[], int n, double t) {
    struct Point result = {0.0, 0.0};

    for (int i = 0; i <= n; i++) {
        double coefficient = binomialCoefficient(n, i) * pow(1 - t, n - i) * pow(t, i);
        result.x += controlPoints[i].x * coefficient;
        result.y += controlPoints[i].y * coefficient;
    }

    return result;
}

// Calculate the B-Spline basis function value for a given i and degree k
double bSplineBasis(int i, int k, double t, double knots[]) {
    if (k == 0) {
        if (knots[i] <= t && t < knots[i + 1]) {
            return 1.0;
        } else {
            return 0.0;
        }
    } else {
        double numerator1 = t - knots[i];
        double denominator1 = knots[i + k] - knots[i];
        double term1 = (numerator1 / denominator1) * bSplineBasis(i, k - 1, t, knots);

        double numerator2 = knots[i + k + 1] - t;
        double denominator2 = knots[i + k + 1] - knots[i + 1];
        double term2 = (numerator2 / denominator2) * bSplineBasis(i + 1, k - 1, t, knots);

        return term1 + term2;
    }
}

// Calculate the B-Spline curve point for a given t, control points, and knots
struct Point bSplineCurvePoint(struct Point controlPoints[], int n, int degree, double t, double knots[]) {
    struct Point result = {0.0, 0.0};

    for (int i = 0; i <= n; i++) {
        double basis = bSplineBasis(i, degree, t, knots);
        result.x += controlPoints[i].x * basis;
        result.y += controlPoints[i].y * basis;
    }

    return result;
}

int main() {
    int n;
    printf("Enter the number of control points: ");
    scanf("%d", &n);

    struct Point controlPoints[n];
    printf("Enter the control points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &controlPoints[i].x, &controlPoints[i].y);
    }

    double t;
    printf("Enter the parameter t (0 <= t <= 1): ");
    scanf("%lf", &t);

    // Bezier Curve
    struct Point bezierResult = bezierCurvePoint(controlPoints, n - 1, t);
    printf("Bezier Curve Point: (%lf, %lf)\n", bezierResult.x, bezierResult.y);

    // B-Spline Curve (Uniform B-Spline with one knot)
    int degree = 2; // Degree of the B-Spline
    double knots[n + degree + 1];
    for (int i = 0; i <= n + degree; i++) {
        knots[i] = (double)i / (n + degree);
    }

    struct Point bSplineResult = bSplineCurvePoint(controlPoints, n - 1, degree, t, knots);
    printf("B-Spline Curve Point: (%lf, %lf)\n", bSplineResult.x, bSplineResult.y);

    return 0;
}

#include <stdio.h>
#include <math.h>

void calculateQuadraticRoots(double coefficientA, double coefficientB, double coefficientC) {
  // Check if A and B are both zero
  if (coefficientA == 0 && coefficientB == 0) {
    printf("There is no solution.\n");
    return;
  }

  // Check if A is zero
  if (coefficientA == 0) {
    double root = -coefficientC / coefficientB;
    printf("There is one root: %.2lf\n", root);
    return;
  }

  // Calculate the discriminant
  double discriminant = coefficientB * coefficientB - 4 * coefficientA * coefficientC;

  // Check if the discriminant is negative
  if (discriminant < 0) {
    printf("There are no real roots.\n");
    return;
  } else if (discriminant == 0) {
    // One real root
    double root = -coefficientB / (2 * coefficientA);
    printf("There is one real root: %.2lf\n", root);
  } else {
    // Two real roots
    double root1 = (-coefficientB + sqrt(discriminant)) / (2 * coefficientA);
    double root2 = (-coefficientB - sqrt(discriminant)) / (2 * coefficientA);
    // Print the roots
    printf("The roots are: %.2lf, %.2lf\n", root1, root2);
  }
}

int main() {
  double coefficientA, coefficientB, coefficientC;

  printf("Enter the coefficients A, B, and C: ");
  scanf("%lf %lf %lf", &coefficientA, &coefficientB, &coefficientC);

  calculateQuadraticRoots(coefficientA, coefficientB, coefficientC);

  return 0;
}

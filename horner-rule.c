// NOTE : We are using %lf or long double to increase the precision of our answer. You can modify it accoringly.

#include <stdio.h>

#define MAX_DEGREE 100 // Maximum degree of the polynomial

double evaluate_polynomial(double coeffs[], int degree, double x)
{
    // Base case: if the degree is 0, return the constant coefficient
    if (degree == 0)
    {
        return coeffs[0];
    }
    // Recursive case: evaluate the polynomial of degree n-1 and multiply by x, then add the constant coefficient
    return x * evaluate_polynomial(coeffs, degree - 1, x) + coeffs[degree];
}

int main()
{
    double coeffs[MAX_DEGREE + 1], x, result;
    int degree;

    // Read the degree of the polynomial from the user
    printf("Enter the degree of the polynomial (maximum %d): ", MAX_DEGREE);
    scanf("%d", &degree);

    // Read the coefficients of the polynomial from the user
    printf("Enter the coefficients of the polynomial (in descending order of degree): \n");
    for (int i = degree; i >= 0; i--)
    {
        scanf("%lf", &coeffs[i]);
    }

    // Read the value of x from the user
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    // Evaluate the polynomial using Horner's Rule
    result = evaluate_polynomial(coeffs, degree, x);

    // Display the result to the user
    printf("The value of the polynomial at x = %lf is %lf\n", x, result);

    return 0;
}
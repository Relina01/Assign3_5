#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 100

typedef struct {
    int degree;
    float coeffs[MAX_DEGREE];
} polynomial;

void input_poly(polynomial* p) {
    int i;
    printf("Enter the degree of the polynomial: ");
    scanf_s("%d", &p->degree);
    printf("Enter the coefficients of the polynomial, starting with the constant term: ");
    for (i = 0; i <= p->degree; i++) {
        scanf_s("%f", &p->coeffs[i]);
    }
}

void print_poly(polynomial p) {
    int i;
    for (i = 0; i <= p.degree; i++) {
        if (i == p.degree) {
            printf("%3.1f", p.coeffs[i]);
        }
        else if (i == p.degree - 1) {
            printf("%3.1fx + ", p.coeffs[i]);
        }
        else {
            printf("%3.1fx^%d + ", p.coeffs[i], p.degree - i);
        }
    }
    printf("\n");
}

void multiply_poly(polynomial p1, polynomial p2, polynomial* result) {
    int i, j, degree_sum;
    for (i = 0; i <= p1.degree + p2.degree; i++) {
        result->coeffs[i] = 0;
    }
    result->degree = p1.degree + p2.degree;
    for (i = 0; i <= p1.degree; i++) {
        for (j = 0; j <= p2.degree; j++) {
            degree_sum = p1.degree - i + p2.degree - j;
            result->coeffs[degree_sum] += p1.coeffs[i] * p2.coeffs[j];
        }
    }
}

int main() {
    polynomial p1, p2, result;
    printf("Enter the first polynomial\n");
    input_poly(&p1);
    printf("Enter the second polynomial\n");
    input_poly(&p2);
    multiply_poly(p1, p2, &result);
    printf("The product of the polynomials is\n");
    print_poly(result);
    return 0;
}

#include <stdio.h>
#pragma warning(disable:4996)

typedef struct
{
    double real;
    double imag;
} Complex;

Complex multiply(Complex a, Complex b)
{
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

int main()
{
    Complex num1, num2, product;
    scanf("%lf%lfi %lf%lfi", &num1.real, &num1.imag, &num2.real, &num2.imag);
    product = multiply(num1, num2);
    if (product.imag < 0)
        printf("%.3lf%.3lfi\n", product.real, product.imag);
    else
        printf("%.3lf+%.3lfi\n", product.real, product.imag);
    return 0;
}
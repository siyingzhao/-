#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996)

float f(float x, float a, float b, float c, float d, float e)
{
	return (pow(x, 5) + a * pow(x, 4) + b * pow(x, 3) + c * pow(x, 2) + d * x + e);
}


float xpoint(float x1, float x2, float a, float b, float c, float d, float e)
{
	float A, B;
	A = f(x1, a, b, c, d, e) * x2 - f(x2, a, b, c, d, e) * x1;
	B = f(x1, a, b, c, d, e) - f(x2, a, b, c, d, e);
	return (A / B);
}

float root(float x1, float x2, float a, float b, float c, float d, float e)
{
	float x3, fx1, fx2, fx3;

	do {
		x3 = xpoint(x1,x2,a,b,c,d,e);
		fx1 = f(x1, a, b, c, d, e);
		fx2 = f(x2, a, b, c, d, e);
		fx3 = f(x3, a, b, c, d, e);

		x1 = x2;
		x2 = x3;
	} while (fabsf(fx3) > 1e-6);

	return x3;
}


int main()
{
	float a, b, c, d, e;
	float x1, x2;
	scanf("%f,%f,%f,%f,%f", &a, &b, &c, &d, &e);
	scanf("%f,%f", &x1, &x2);
	printf("%.3f", root(x1, x2, a, b, c, d, e));
	return 0;
}
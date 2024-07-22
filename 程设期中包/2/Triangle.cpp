#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	double C, S, p;
	if (a + b > c && a + c > b && b + c > a)
	{
		C = a + b + c;
		p = C / 2;
		S = sqrt(p * (p - a) * (p - b) * (p - c));
		printf("%.2lf %.2lf", C, S);
	}
	else
		printf("Error");
	return 0;
}
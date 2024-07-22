#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

int main()
{
	double money;
	int way;
	scanf("%lf %d", &money, &way);
	switch (way)
	{
	case 1: 
		money = money * (1 + 5 * 0.0550);
		break;
	case 2:
		money = money * (1 + 2 * 0.0440);
		money = money * (1 + 3 * 0.0500);
		break;
	case 3:
		money = money * (1 + 3 * 0.0500);
		money = money * (1 + 2 * 0.0440);
		break;
	case 4:
		money = money * pow(1 + 0.0350, 5);
		break;
	case 5:
		money = money * pow(1 + 0.0050 / 4, 20);
		break;
	}
	printf("%.2lf", money);
	return 0;
}
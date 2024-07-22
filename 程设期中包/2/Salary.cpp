#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	double mount, salary;
	scanf("%lf", &mount);
	if (mount <= 8)
		salary = mount * 62.5;
	else if (mount > 8)
		salary = 8 * 62.5 + (mount - 8) * (62.5 * 1.5);
	printf("%.2lf", salary);
	return 0;
}
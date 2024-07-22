#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	int n, count;
	scanf("%d", &n);
	count = 0;
	for (; n != 0;)
	{
		if (n % 2 == 1)
			count++;
		n = n - n % 2;
		n /= 2;
	}
	printf("%d", count);
	return 0;
}